#pragma once
using namespace System;
using namespace System::Collections::Generic;//List���ڵ������ռ�
//�����ݿ���ص������ռ�
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
		String^ regionnum;//������
		String^ powerdissipation;
		String^ runtime;
	};

	ref class RegionData {
	public:
		String^ regionNum;//������
		float^ powerDissipation;//�����ܺ�
		float^ runningTime;//��������ʱ��

		//���캯��
		RegionData(){}
		RegionData(String^ _regionNum, float^ _powerDissipation, float^ _runningTime) {
			regionNum = _regionNum;
			powerDissipation = _powerDissipation;
			runningTime = _runningTime;
		}
	};

	ref class ProposalData {
	public:
		//����
		String^ carNum;
		String^ proposalNum;
		List<RegionData^>^ regions = gcnew List<RegionData^>();

		//���캯��
		ProposalData() {}
		//����ֻ�Ǵ���һ��֮�ڵ�һ����������
		ProposalData(String^ _proposalNum,String^_dateTime) {
			//��ȡ�г����
			String^ selectsql = String::Format("SELECT DISTINCT �г���� FROM ProjectPowerDissipationTable WHERE �������='{0}';",_proposalNum);
			carNum = GetDataTable(selectsql)->Rows[0]->ItemArray[0]->ToString();
			//��ȡ������������
			selectsql = String::Format("SELECT cast(������ as int),����,����ʱ�� FROM ProjectPowerDissipationTable " +
				"WHERE ʱ�� BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}')) AND �������='{2}' ORDER BY cast(������ as int);",
				_dateTime, _dateTime, _proposalNum);
			DataTable^ dataTable = GetDataTable(selectsql);
			for (int i = 0; i < dataTable->Rows->Count; i++) {
				//����������������
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

