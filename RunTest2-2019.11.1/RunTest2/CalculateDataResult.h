#pragma once
using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Collections::Generic;

namespace RunTest2 {

	ref class Region {
	public:
		int regionnum;
		float tramrunningtime;
		float powerdissipation;

		Region() {}
		Region(int _regionnum,float _tramrunningtime,float _powerdissipation) {
			regionnum = _regionnum;
			tramrunningtime = _tramrunningtime;
			powerdissipation = _powerdissipation;
		}
	};

	ref class Proposal {
	public:
		String^ proposal_strnum;//字符型方案编号
		String^ tram_strnum;//字符型电车编号
		String^ line_strnum;//字符型线路编号
		float line_len = 0;
		array<Region^>^ pos_regions;//正向区间情况
		array<Region^>^ inv_regions;//正向区间情况

		//构造函数
		Proposal() {}
		Proposal(String^_proposal_strnum,String^ _tram_strnum,String^ _line_strnum,array<Region^>^ _pos_regions, array<Region^>^ _inv_regions) {
			proposal_strnum = _proposal_strnum;
			tram_strnum = _tram_strnum;
			line_strnum = _line_strnum;
			pos_regions = _pos_regions;
			inv_regions = _inv_regions;
		}
	};

	//自定义数据库查询
	DataTable^ GetData(String^ sqlstr)
	{
		SqlConnection^ con = gcnew SqlConnection();
		con->ConnectionString = "Data Source=localhost;Initial Catalog=列车数据库;Integrated Security=True";
		SqlDataAdapter^ da = gcnew SqlDataAdapter(sqlstr, con);
		con->Open();
		DataTable^ table1 = gcnew DataTable();
		da->Fill(table1);
		con->Close();
		return table1;
	}
	DataTable^ GetData1(String^ sqlstr)
	{
		SqlConnection^ con = gcnew SqlConnection();
		con->ConnectionString = "Data Source=localhost;Initial Catalog=RunDB2;Integrated Security=True";
		SqlDataAdapter^ da = gcnew SqlDataAdapter(sqlstr, con);
		con->Open();
		DataTable^ table1 = gcnew DataTable();
		da->Fill(table1);
		con->Close();
		return table1;
	}

	System::Void CalculatePowerDissipation(String^proposalnum) {
		//创建一个方案
		Proposal^ pp = gcnew Proposal();
		//从方案信息表获取电车编号、线路编号
		String^ selectsql = "SELECT 线路编号 AS 线路编号,列车编号 AS 列车编号 FROM 方案信息 WHERE 方案编号='" + proposalnum + "';";
		DataTable^ table = gcnew DataTable();
		table = GetData(selectsql);
		pp->tram_strnum = table->Rows[0]->ItemArray[1]->ToString();
		pp->line_strnum = table->Rows[0]->ItemArray[0]->ToString();
		
		//从站点信息表中获取各个站间距离，并按照站点编号排序
		selectsql = "SELECT 站点编号,站间距离 FROM 站点信息 WHERE 线路编号='" + pp->line_strnum + "' ORDER BY 站点编号;";
		table = GetData(selectsql);

		array<float>^ stationdistances = gcnew array<float>(table->Rows->Count);
		//线路总长
		float linelength = 0;
		for (int i = 0; i < table->Rows->Count; i++) {
			stationdistances[i] = float::Parse(table->Rows[i]->ItemArray[1]->ToString());
			linelength = linelength + stationdistances[i];
		}
		pp->line_len = linelength;
		//还原各个站点距离第一个站点(左边为第一个)的距离
		for (int i = 1; i < stationdistances->Length; i++) {
				stationdistances[i] = stationdistances[i] + stationdistances[i - 1];
		}
		//计算各个站间功耗
		SqlConnection^ Conn = gcnew SqlConnection("Data Source=localhost;Initial Catalog=RunDB2;Integrated Security=True");
		array<Region^>^ powerdissipationofregion = gcnew array<Region^>(stationdistances->Length - 1);
		//正向
		for (int i = 1; i < stationdistances->Length; i++) {
			//计算区间功耗：正向
			selectsql = "SELECT 数据序号,电流,电压,cast(位置 as float),时间间隔 FROM trainTable WHERE cast(位置 as float) >= '" + stationdistances[i-1] + "' AND " +
				"cast(位置 as float) <= '" + stationdistances[i] + "' AND 方案编号='" + proposalnum +  "' AND 行驶方向='正向' ORDER BY 数据序号;";
			table = GetData1(selectsql);
			float powerdissipation = 0; 
			for (int j = 0; j < table->Rows->Count; j++) {
				powerdissipation = powerdissipation + float::Parse(table->Rows[j]->ItemArray[1]->ToString()) * float::Parse(table->Rows[j]->ItemArray[2]->ToString()) * \
					float::Parse(table->Rows[j]->ItemArray[4]->ToString());
			}
			//计算区间运行时间：正向
			selectsql = "SELECT MIN(cast(时间 as datetime)),MAX(cast(时间 as datetime)) FROM trainTable WHERE cast(位置 as float) >= '" + stationdistances[i - 1] + "' AND " +
				"cast(位置 as float) < '" + stationdistances[i] + "' AND 方案编号='" + proposalnum + "' AND 行驶方向= '正向';";
			table = GetData1(selectsql);
			DateTime time1 = Convert::ToDateTime(table->Rows[0]->ItemArray[0]->ToString()->Trim());
			DateTime time2 = Convert::ToDateTime(table->Rows[0]->ItemArray[1]->ToString()->Trim());
			int runningtime = (time2 - time1).Seconds;
			Region^ region = gcnew Region(i, runningtime, powerdissipation);
			powerdissipationofregion[i - 1] = region;

			//将计算出的当前区间数据存入数据库
			String^ strcmd = String::Format("INSERT INTO ProjectPowerDissipationTable (列车编号,方案编号,区间编号,运行时间,功耗,时间,行驶方向) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}','{6}');", \
				pp->tram_strnum, proposalnum, region->regionnum, region->tramrunningtime,region->powerdissipation, DateTime::Now.ToString(),"正向");
			Data::SqlClient::SqlCommand^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);
			Conn->Open();
			cmd->ExecuteNonQuery();
			Conn->Close();
		}
		pp->pos_regions = powerdissipationofregion;

		//反向
		for (int i = 1; i < stationdistances->Length; i++) {
			//计算区间功耗：反向
			selectsql = "SELECT 数据序号,电流,电压,cast(位置 as float),时间间隔 FROM trainTable WHERE cast(位置 as float) <= '" + (2*pp->line_len-stationdistances[i - 1]) + "' AND " +
				"cast(位置 as float) > '" + (2*pp->line_len-stationdistances[i]) + "' AND 方案编号='" + proposalnum + "' AND 行驶方向='反向' ORDER BY 数据序号;";
			table = GetData1(selectsql);
			float powerdissipation = 0;
			for (int j = 0; j < table->Rows->Count; j++) {
				powerdissipation = powerdissipation + float::Parse(table->Rows[j]->ItemArray[1]->ToString()) * float::Parse(table->Rows[j]->ItemArray[2]->ToString()) * \
					float::Parse(table->Rows[j]->ItemArray[4]->ToString());
			}
			//计算区间运行时间：反向
			selectsql = "SELECT MIN(cast(时间 as datetime)),MAX(cast(时间 as datetime)) FROM trainTable WHERE cast(位置 as float) <= '" + (2*pp->line_len-stationdistances[i - 1]) + "' AND " +
				"cast(位置 as float) > '" + (2*pp->line_len-stationdistances[i]) + "' AND 方案编号='" + proposalnum + "' AND 行驶方向= '反向';";
			table = GetData1(selectsql);
			DateTime time1 = Convert::ToDateTime(table->Rows[0]->ItemArray[0]->ToString()->Trim());
			DateTime time2 = Convert::ToDateTime(table->Rows[0]->ItemArray[1]->ToString()->Trim());
			int runningtime = (time2 - time1).Seconds;
			Region^ region = gcnew Region(i, runningtime, powerdissipation);
			powerdissipationofregion[i - 1] = region;

			//将计算出的当前区间数据存入数据库
			String^ strcmd = String::Format("INSERT INTO ProjectPowerDissipationTable (列车编号,方案编号,区间编号,运行时间,功耗,时间,行驶方向) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}','{6}');", \
				pp->tram_strnum, proposalnum, region->regionnum, region->tramrunningtime, region->powerdissipation, DateTime::Now.ToString(), "反向");
			Data::SqlClient::SqlCommand^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);
			Conn->Open();
			cmd->ExecuteNonQuery();
			Conn->Close();
		}
		pp->inv_regions = powerdissipationofregion;
	}

	System::Void CalculatePeopleFlow(String^ proposalnum,int stationNum) {
		//从方案信息表获取电车编号、线路编号
		String^ selectsql = "SELECT 线路编号 AS 线路编号,列车编号 AS 列车编号 FROM 方案信息 WHERE 方案编号='" + proposalnum + "';";
		DataTable^ table = gcnew DataTable();
		table = GetData(selectsql);
		String^ tramnum = table->Rows[0]->ItemArray[1]->ToString();
		String^ linenum = table->Rows[0]->ItemArray[0]->ToString();

		selectsql = "SELECT DISTINCT cast(站点编号 as int),站点名,上车人数,下车人数,车内人数,cast(到站时间 as datetime),cast(出站时间 as datetime),时间间隔 " + 
			"FROM peopleTable WHERE 方案编号='" + proposalnum + "' ORDER BY cast(站点编号 as int);";
		table = GetData1(selectsql);

		//将数据存入另一个表。。好像存无所谓，这里为了不改变后面程序所以存一下
		SqlConnection^ Conn = gcnew SqlConnection("Data Source=localhost;Initial Catalog=RunDB2;Integrated Security=True");
		for (int i = 0; i < table->Rows->Count; i++) {
			//取到站时间作为记录时间戳
			DateTime time = Convert::ToDateTime(table->Rows[i]->ItemArray[5]->ToString()->Trim());
			String^ direction;
			if (i < stationNum)
				direction = "正向";
			else if (i >= stationNum)
				direction = "反向";
			String^ strcmd = String::Format("INSERT INTO PeopleFlowDataTable (列车编号,方案编号,站点名称,上车人数,下车人数,车内人数,时间,站点编号,运行时间,行驶方向) "+
				"VALUES ('{0}','{1}','{2}','{3}','{4}','{5}','{6}','{7}','{8}','{9}');", \
				tramnum,
				proposalnum,
				table->Rows[i]->ItemArray[1]->ToString(),//站点名
				table->Rows[i]->ItemArray[2]->ToString(),//上车人数
				table->Rows[i]->ItemArray[3]->ToString(),//下车人数
				table->Rows[i]->ItemArray[4]->ToString(),//车内人数
				time.ToString(),
				(i+1),//站点编号
				table->Rows[i]->ItemArray[7]->ToString(),
				direction
			);
			Data::SqlClient::SqlCommand^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);
			Conn->Open();
			cmd->ExecuteNonQuery();
			Conn->Close();
		}


	}
}
