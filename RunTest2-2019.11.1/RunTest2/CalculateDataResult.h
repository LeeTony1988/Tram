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
		String^ proposal_strnum;//�ַ��ͷ������
		String^ tram_strnum;//�ַ��͵糵���
		String^ line_strnum;//�ַ�����·���
		float line_len = 0;
		array<Region^>^ pos_regions;//�����������
		array<Region^>^ inv_regions;//�����������

		//���캯��
		Proposal() {}
		Proposal(String^_proposal_strnum,String^ _tram_strnum,String^ _line_strnum,array<Region^>^ _pos_regions, array<Region^>^ _inv_regions) {
			proposal_strnum = _proposal_strnum;
			tram_strnum = _tram_strnum;
			line_strnum = _line_strnum;
			pos_regions = _pos_regions;
			inv_regions = _inv_regions;
		}
	};

	//�Զ������ݿ��ѯ
	DataTable^ GetData(String^ sqlstr)
	{
		SqlConnection^ con = gcnew SqlConnection();
		con->ConnectionString = "Data Source=localhost;Initial Catalog=�г����ݿ�;Integrated Security=True";
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
		//����һ������
		Proposal^ pp = gcnew Proposal();
		//�ӷ�����Ϣ���ȡ�糵��š���·���
		String^ selectsql = "SELECT ��·��� AS ��·���,�г���� AS �г���� FROM ������Ϣ WHERE �������='" + proposalnum + "';";
		DataTable^ table = gcnew DataTable();
		table = GetData(selectsql);
		pp->tram_strnum = table->Rows[0]->ItemArray[1]->ToString();
		pp->line_strnum = table->Rows[0]->ItemArray[0]->ToString();
		
		//��վ����Ϣ���л�ȡ����վ����룬������վ��������
		selectsql = "SELECT վ����,վ����� FROM վ����Ϣ WHERE ��·���='" + pp->line_strnum + "' ORDER BY վ����;";
		table = GetData(selectsql);

		array<float>^ stationdistances = gcnew array<float>(table->Rows->Count);
		//��·�ܳ�
		float linelength = 0;
		for (int i = 0; i < table->Rows->Count; i++) {
			stationdistances[i] = float::Parse(table->Rows[i]->ItemArray[1]->ToString());
			linelength = linelength + stationdistances[i];
		}
		pp->line_len = linelength;
		//��ԭ����վ������һ��վ��(���Ϊ��һ��)�ľ���
		for (int i = 1; i < stationdistances->Length; i++) {
				stationdistances[i] = stationdistances[i] + stationdistances[i - 1];
		}
		//�������վ�书��
		SqlConnection^ Conn = gcnew SqlConnection("Data Source=localhost;Initial Catalog=RunDB2;Integrated Security=True");
		array<Region^>^ powerdissipationofregion = gcnew array<Region^>(stationdistances->Length - 1);
		//����
		for (int i = 1; i < stationdistances->Length; i++) {
			//�������书�ģ�����
			selectsql = "SELECT �������,����,��ѹ,cast(λ�� as float),ʱ���� FROM trainTable WHERE cast(λ�� as float) >= '" + stationdistances[i-1] + "' AND " +
				"cast(λ�� as float) <= '" + stationdistances[i] + "' AND �������='" + proposalnum +  "' AND ��ʻ����='����' ORDER BY �������;";
			table = GetData1(selectsql);
			float powerdissipation = 0; 
			for (int j = 0; j < table->Rows->Count; j++) {
				powerdissipation = powerdissipation + float::Parse(table->Rows[j]->ItemArray[1]->ToString()) * float::Parse(table->Rows[j]->ItemArray[2]->ToString()) * \
					float::Parse(table->Rows[j]->ItemArray[4]->ToString());
			}
			//������������ʱ�䣺����
			selectsql = "SELECT MIN(cast(ʱ�� as datetime)),MAX(cast(ʱ�� as datetime)) FROM trainTable WHERE cast(λ�� as float) >= '" + stationdistances[i - 1] + "' AND " +
				"cast(λ�� as float) < '" + stationdistances[i] + "' AND �������='" + proposalnum + "' AND ��ʻ����= '����';";
			table = GetData1(selectsql);
			DateTime time1 = Convert::ToDateTime(table->Rows[0]->ItemArray[0]->ToString()->Trim());
			DateTime time2 = Convert::ToDateTime(table->Rows[0]->ItemArray[1]->ToString()->Trim());
			int runningtime = (time2 - time1).Seconds;
			Region^ region = gcnew Region(i, runningtime, powerdissipation);
			powerdissipationofregion[i - 1] = region;

			//��������ĵ�ǰ�������ݴ������ݿ�
			String^ strcmd = String::Format("INSERT INTO ProjectPowerDissipationTable (�г����,�������,������,����ʱ��,����,ʱ��,��ʻ����) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}','{6}');", \
				pp->tram_strnum, proposalnum, region->regionnum, region->tramrunningtime,region->powerdissipation, DateTime::Now.ToString(),"����");
			Data::SqlClient::SqlCommand^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);
			Conn->Open();
			cmd->ExecuteNonQuery();
			Conn->Close();
		}
		pp->pos_regions = powerdissipationofregion;

		//����
		for (int i = 1; i < stationdistances->Length; i++) {
			//�������书�ģ�����
			selectsql = "SELECT �������,����,��ѹ,cast(λ�� as float),ʱ���� FROM trainTable WHERE cast(λ�� as float) <= '" + (2*pp->line_len-stationdistances[i - 1]) + "' AND " +
				"cast(λ�� as float) > '" + (2*pp->line_len-stationdistances[i]) + "' AND �������='" + proposalnum + "' AND ��ʻ����='����' ORDER BY �������;";
			table = GetData1(selectsql);
			float powerdissipation = 0;
			for (int j = 0; j < table->Rows->Count; j++) {
				powerdissipation = powerdissipation + float::Parse(table->Rows[j]->ItemArray[1]->ToString()) * float::Parse(table->Rows[j]->ItemArray[2]->ToString()) * \
					float::Parse(table->Rows[j]->ItemArray[4]->ToString());
			}
			//������������ʱ�䣺����
			selectsql = "SELECT MIN(cast(ʱ�� as datetime)),MAX(cast(ʱ�� as datetime)) FROM trainTable WHERE cast(λ�� as float) <= '" + (2*pp->line_len-stationdistances[i - 1]) + "' AND " +
				"cast(λ�� as float) > '" + (2*pp->line_len-stationdistances[i]) + "' AND �������='" + proposalnum + "' AND ��ʻ����= '����';";
			table = GetData1(selectsql);
			DateTime time1 = Convert::ToDateTime(table->Rows[0]->ItemArray[0]->ToString()->Trim());
			DateTime time2 = Convert::ToDateTime(table->Rows[0]->ItemArray[1]->ToString()->Trim());
			int runningtime = (time2 - time1).Seconds;
			Region^ region = gcnew Region(i, runningtime, powerdissipation);
			powerdissipationofregion[i - 1] = region;

			//��������ĵ�ǰ�������ݴ������ݿ�
			String^ strcmd = String::Format("INSERT INTO ProjectPowerDissipationTable (�г����,�������,������,����ʱ��,����,ʱ��,��ʻ����) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}','{6}');", \
				pp->tram_strnum, proposalnum, region->regionnum, region->tramrunningtime, region->powerdissipation, DateTime::Now.ToString(), "����");
			Data::SqlClient::SqlCommand^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);
			Conn->Open();
			cmd->ExecuteNonQuery();
			Conn->Close();
		}
		pp->inv_regions = powerdissipationofregion;
	}

	System::Void CalculatePeopleFlow(String^ proposalnum,int stationNum) {
		//�ӷ�����Ϣ���ȡ�糵��š���·���
		String^ selectsql = "SELECT ��·��� AS ��·���,�г���� AS �г���� FROM ������Ϣ WHERE �������='" + proposalnum + "';";
		DataTable^ table = gcnew DataTable();
		table = GetData(selectsql);
		String^ tramnum = table->Rows[0]->ItemArray[1]->ToString();
		String^ linenum = table->Rows[0]->ItemArray[0]->ToString();

		selectsql = "SELECT DISTINCT cast(վ���� as int),վ����,�ϳ�����,�³�����,��������,cast(��վʱ�� as datetime),cast(��վʱ�� as datetime),ʱ���� " + 
			"FROM peopleTable WHERE �������='" + proposalnum + "' ORDER BY cast(վ���� as int);";
		table = GetData1(selectsql);

		//�����ݴ�����һ���������������ν������Ϊ�˲��ı����������Դ�һ��
		SqlConnection^ Conn = gcnew SqlConnection("Data Source=localhost;Initial Catalog=RunDB2;Integrated Security=True");
		for (int i = 0; i < table->Rows->Count; i++) {
			//ȡ��վʱ����Ϊ��¼ʱ���
			DateTime time = Convert::ToDateTime(table->Rows[i]->ItemArray[5]->ToString()->Trim());
			String^ direction;
			if (i < stationNum)
				direction = "����";
			else if (i >= stationNum)
				direction = "����";
			String^ strcmd = String::Format("INSERT INTO PeopleFlowDataTable (�г����,�������,վ������,�ϳ�����,�³�����,��������,ʱ��,վ����,����ʱ��,��ʻ����) "+
				"VALUES ('{0}','{1}','{2}','{3}','{4}','{5}','{6}','{7}','{8}','{9}');", \
				tramnum,
				proposalnum,
				table->Rows[i]->ItemArray[1]->ToString(),//վ����
				table->Rows[i]->ItemArray[2]->ToString(),//�ϳ�����
				table->Rows[i]->ItemArray[3]->ToString(),//�³�����
				table->Rows[i]->ItemArray[4]->ToString(),//��������
				time.ToString(),
				(i+1),//վ����
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
