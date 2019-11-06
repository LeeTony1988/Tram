#pragma once
using namespace System;
using namespace System::Collections::Generic;//List所在的命名空间
//与数据库相关的命名空间
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Data::Common;
using namespace System::Data::OleDb;

namespace PowerDissipationAndRunningTimeChart {
	
	
	ref class PowerDissipation
	{
	public:
		PowerDissipation() {}

	public:
		String^ carnum;
		String^ proposalnum;
		String^ regionnum;//区间编号
		String^ powerdissipation;
		String^ runtime;
	};

	ref class RegionData {
	public:
		String^ regionNum;//区间编号
		float^ powerDissipation;//区间能耗
		float^ runningTime;//区间运行时间

		//构造函数
		RegionData(){}
		RegionData(String^ _regionNum, float^ _powerDissipation, float^ _runningTime) {
			regionNum = _regionNum;
			powerDissipation = _powerDissipation;
			runningTime = _runningTime;
		}
	};

	ref class ProposalData {
	public:
		//属性
		String^ carNum;
		String^ proposalNum;
		List<RegionData^>^ regions = gcnew List<RegionData^>();

		//构造函数
		ProposalData() {}
		//这里只是创建一天之内的一个方案数据
		ProposalData(String^ _proposalNum,String^_dateTime) {
			//获取列车编号
			String^ selectsql = String::Format("SELECT DISTINCT 列车编号 FROM ProjectPowerDissipationTable WHERE 方案编号='{0}';",_proposalNum);
			carNum = GetDataTable(selectsql)->Rows[0]->ItemArray[0]->ToString();
			//获取各个区间数据
			selectsql = String::Format("SELECT cast(区间编号 as int),功耗,运行时间 FROM ProjectPowerDissipationTable " +
				"WHERE 时间 BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}')) AND 方案编号='{2}' ORDER BY cast(区间编号 as int);",
				_dateTime, _dateTime, _proposalNum);
			DataTable^ dataTable = GetDataTable(selectsql);
			for (int i = 0; i < dataTable->Rows->Count; i++) {
				//创建各个区间数据
				RegionData^ region = gcnew RegionData(dataTable->Rows[i]->ItemArray[0]->ToString(),
					float::Parse(dataTable->Rows[i]->ItemArray[1]->ToString()),float::Parse(dataTable->Rows[i]->ItemArray[2]->ToString()));
				regions->Add(region);
			}
		}

	private:
		DataTable^ GetDataTable(String^ selectsql) {
			SqlConnection^ con = gcnew SqlConnection();
			con->ConnectionString = "Data Source=localhost;Initial Catalog=RunDB2;Integrated Security=True";
			SqlDataAdapter^ da = gcnew SqlDataAdapter(selectsql, con);
			DataTable^ table1 = gcnew DataTable();
			con->Open();
			da->Fill(table1);
			con->Close();
			return table1;
		}

	};


}

