#pragma once
#include"StationTimePeopleflow.h"
namespace moxingdingyi {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//����
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using namespace System::Data::SqlClient;
	using namespace System::Security::Permissions;
	[System::Runtime::InteropServices::ComVisibleAttribute(true)]
	/// <summary>
	/// StationPeopleTimeForm ժҪ
	/// </summary>
	public ref class StationPeopleTimeForm : public System::Windows::Forms::Form
	{
	public:
		StationPeopleTimeForm(void)
		{
			InitializeComponent();
			//
			//TODO:  �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~StationPeopleTimeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	private: System::Windows::Forms::WebBrowser^  webBrowser1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::Label^  label1;
	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->webBrowser1);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(915, 610);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"�ֲ�ͼ";
			// 
			// webBrowser1
			// 
			this->webBrowser1->Location = System::Drawing::Point(6, 68);
			this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->ScrollBarsEnabled = false;
			this->webBrowser1->Size = System::Drawing::Size(903, 536);
			this->webBrowser1->TabIndex = 1;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dateTimePicker1);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Location = System::Drawing::Point(6, 20);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(903, 42);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"��ʾ����";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(65, 15);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(131, 21);
			this->dateTimePicker1->TabIndex = 1;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &StationPeopleTimeForm::dateTimePicker1_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ѡ������";
			// 
			// StationPeopleTimeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1284, 686);
			this->Controls->Add(this->groupBox1);
			this->Name = L"StationPeopleTimeForm";
			this->Text = L"����ʱ��վ�������ֲ�ͼ";
			this->Load += gcnew System::EventHandler(this, &StationPeopleTimeForm::StationPeopleTimeForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		//��������غ���
	private:SqlConnection^con = gcnew SqlConnection();
	private:DataTable^GetDataTable(SqlConnection^con1, String^selectsql1)
	{
				con1->Open();
				SqlDataAdapter^da1 = gcnew SqlDataAdapter(selectsql1, con1);
				DataTable^result_dt = gcnew DataTable();
				da1->Fill(result_dt);
				con1->Close();
				return result_dt;
	}
	private: System::Void StationPeopleTimeForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 //��ʼ����Ҫ����
				 con->ConnectionString = "Data Source=localhost;Initial Catalog=RunDB2;Integrated Security=True";

				 this->webBrowser1->AllowWebBrowserDrop = false;
				 this->webBrowser1->IsWebBrowserContextMenuEnabled = false;
				 this->webBrowser1->WebBrowserShortcutsEnabled = false;
				 this->webBrowser1->ObjectForScripting = this;
				 String^path_current = System::Windows::Forms::Application::StartupPath;
				 String^path1 = path_current + "\\ʱ��վ�������ֲ�ͼ.html";
				 this->webBrowser1->Navigate(path1);
	}
private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 String^selectsql = String::Format("SELECT DISTINCT վ������ AS վ������,վ���� AS վ���� FROM PeopleFlowDataTable " +
				 "WHERE ʱ�� BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}')) ORDER BY վ����;",
				 this->dateTimePicker1->Value.ToShortDateString(), this->dateTimePicker1->Value.ToShortDateString());
			 DataTable^stationsdt = GetDataTable(con, selectsql);
			 //MessageBox::Show(stationsdt->Rows->Count.ToString());
			 array<StationTimePeopleflow^>^stpf_arr = gcnew array<StationTimePeopleflow^>(stationsdt->Rows->Count);
			 //վ��
			 array<String^>^stationsname = gcnew array<String^>(stationsdt->Rows->Count);
			 for (int i = 0; i < stationsdt->Rows->Count; i++)
			 {
				 StationTimePeopleflow^stpf = gcnew StationTimePeopleflow();

				 DataRow^dr = stationsdt->Rows[i];
				 stationsname[int::Parse(dr["վ����"]->ToString()) - 1] = dr["վ������"]->ToString();
				 stpf->stationname = dr["վ������"]->ToString();
				 stpf->station_x = i;
				 selectsql = String::Format("SELECT DATEPART(hour,ʱ��) AS ʱ��,SUM(�ϳ�����) AS �ϳ�������," +
					 "SUM(�³�����) AS �³������� FROM PeopleFlowDataTable WHERE " +
					 "վ������='{0}' AND (ʱ�� BETWEEN '{1}' AND dateadd(second,-1,dateadd(day,1,'{2}'))) " +
					 "GROUP BY DATEPART(hour,ʱ��) ORDER BY DATEPART(hour,ʱ��);",
					 dr["վ������"]->ToString(), this->dateTimePicker1->Value.ToShortDateString(),
					 this->dateTimePicker1->Value.ToShortDateString());
				 DataTable^stationtimespeopleflowdt = GetDataTable(con, selectsql);
				 //MessageBox::Show(stationtimespeopleflowdt->Rows->Count.ToString());
				 for (int j = 0; j < stationtimespeopleflowdt->Rows->Count; j++)
				 {
					 DataRow^dr1 = stationtimespeopleflowdt->Rows[j];
					 stpf->y_data[int::Parse(dr1["ʱ��"]->ToString()) - 6] = int::Parse(dr1["�ϳ�������"]->ToString()) + int::Parse(dr1["�³�������"]->ToString());
				 }
				 stpf_arr[i] = stpf;
			 }
			 this->webBrowser1->Document->InvokeScript("ClearAll");
			 for (int i = 0; i < stationsname->Length; i++)
			 {
				 array<System::Object^>^sendstationname = gcnew array<System::Object^>(1);
				 sendstationname[0] = stationsname[i];
				 this->webBrowser1->Document->InvokeScript("GetStations", sendstationname);
			 }
			 for (int i = 0; i < stpf_arr->Length; i++)
			 {
				 for (int j = 0; j < 15; j++)
				 {
					 array<System::Object^>^senddata = gcnew array<System::Object^>(3);
					 senddata[0] = j;
					 senddata[1] = stpf_arr[i]->station_x;
					 senddata[2] = stpf_arr[i]->y_data[j];
					 this->webBrowser1->Document->InvokeScript("GetDatas", senddata);
				 }

			 }
			 this->webBrowser1->Document->InvokeScript("InitChart");
}
	};
}
