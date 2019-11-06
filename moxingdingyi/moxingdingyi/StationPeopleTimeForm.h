#pragma once
#include"StationTimePeopleflow.h"
namespace moxingdingyi {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//新增
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using namespace System::Data::SqlClient;
	using namespace System::Security::Permissions;
	[System::Runtime::InteropServices::ComVisibleAttribute(true)]
	/// <summary>
	/// StationPeopleTimeForm 摘要
	/// </summary>
	public ref class StationPeopleTimeForm : public System::Windows::Forms::Form
	{
	public:
		StationPeopleTimeForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
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
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
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
			this->groupBox1->Text = L"分布图";
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
			this->groupBox2->Text = L"显示调整";
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
			this->label1->Text = L"选择日期";
			// 
			// StationPeopleTimeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1284, 686);
			this->Controls->Add(this->groupBox1);
			this->Name = L"StationPeopleTimeForm";
			this->Text = L"单天时段站点人流分布图";
			this->Load += gcnew System::EventHandler(this, &StationPeopleTimeForm::StationPeopleTimeForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		//主窗体加载函数
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
				 //初始化必要参数
				 con->ConnectionString = "Data Source=localhost;Initial Catalog=RunDB2;Integrated Security=True";

				 this->webBrowser1->AllowWebBrowserDrop = false;
				 this->webBrowser1->IsWebBrowserContextMenuEnabled = false;
				 this->webBrowser1->WebBrowserShortcutsEnabled = false;
				 this->webBrowser1->ObjectForScripting = this;
				 String^path_current = System::Windows::Forms::Application::StartupPath;
				 String^path1 = path_current + "\\时段站点人流分布图.html";
				 this->webBrowser1->Navigate(path1);
	}
private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 String^selectsql = String::Format("SELECT DISTINCT 站点名称 AS 站点名称,站点编号 AS 站点编号 FROM PeopleFlowDataTable " +
				 "WHERE 时间 BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}')) ORDER BY 站点编号;",
				 this->dateTimePicker1->Value.ToShortDateString(), this->dateTimePicker1->Value.ToShortDateString());
			 DataTable^stationsdt = GetDataTable(con, selectsql);
			 //MessageBox::Show(stationsdt->Rows->Count.ToString());
			 array<StationTimePeopleflow^>^stpf_arr = gcnew array<StationTimePeopleflow^>(stationsdt->Rows->Count);
			 //站点
			 array<String^>^stationsname = gcnew array<String^>(stationsdt->Rows->Count);
			 for (int i = 0; i < stationsdt->Rows->Count; i++)
			 {
				 StationTimePeopleflow^stpf = gcnew StationTimePeopleflow();

				 DataRow^dr = stationsdt->Rows[i];
				 stationsname[int::Parse(dr["站点编号"]->ToString()) - 1] = dr["站点名称"]->ToString();
				 stpf->stationname = dr["站点名称"]->ToString();
				 stpf->station_x = i;
				 selectsql = String::Format("SELECT DATEPART(hour,时间) AS 时间,SUM(上车人数) AS 上车人数和," +
					 "SUM(下车人数) AS 下车人数和 FROM PeopleFlowDataTable WHERE " +
					 "站点名称='{0}' AND (时间 BETWEEN '{1}' AND dateadd(second,-1,dateadd(day,1,'{2}'))) " +
					 "GROUP BY DATEPART(hour,时间) ORDER BY DATEPART(hour,时间);",
					 dr["站点名称"]->ToString(), this->dateTimePicker1->Value.ToShortDateString(),
					 this->dateTimePicker1->Value.ToShortDateString());
				 DataTable^stationtimespeopleflowdt = GetDataTable(con, selectsql);
				 //MessageBox::Show(stationtimespeopleflowdt->Rows->Count.ToString());
				 for (int j = 0; j < stationtimespeopleflowdt->Rows->Count; j++)
				 {
					 DataRow^dr1 = stationtimespeopleflowdt->Rows[j];
					 stpf->y_data[int::Parse(dr1["时间"]->ToString()) - 6] = int::Parse(dr1["上车人数和"]->ToString()) + int::Parse(dr1["下车人数和"]->ToString());
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
