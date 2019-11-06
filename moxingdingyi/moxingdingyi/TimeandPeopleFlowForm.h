#pragma once
#include"Singleaxis.h"
namespace moxingdingyi {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//新增
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using namespace System::Web;
	using namespace System::Xml;
	using namespace System::Data::SqlClient;
	using namespace System::Security::Permissions;
	[System::Runtime::InteropServices::ComVisibleAttribute(true)]
	/// <summary>
	/// TimeandPeopleFlowForm 摘要
	/// </summary>
	public ref class TimeandPeopleFlowForm : public System::Windows::Forms::Form
	{
	public:
		TimeandPeopleFlowForm(void)
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
		~TimeandPeopleFlowForm()
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
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::WebBrowser^  webBrowser2;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
	private: System::Windows::Forms::Label^  label3;
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
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->webBrowser2 = (gcnew System::Windows::Forms::WebBrowser());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Controls->Add(this->webBrowser1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(618, 662);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"散点图显示各时间段人流量大小";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->dateTimePicker1);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Location = System::Drawing::Point(6, 20);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(605, 49);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"显示调整";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(279, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 12);
			this->label2->TabIndex = 2;
			this->label2->Text = L"最多同时显示7天";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(125, 20);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(120, 21);
			this->dateTimePicker1->TabIndex = 1;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &TimeandPeopleFlowForm::dateTimePicker1_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"选择需要显示的日期";
			// 
			// webBrowser1
			// 
			this->webBrowser1->Location = System::Drawing::Point(6, 75);
			this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->ScrollBarsEnabled = false;
			this->webBrowser1->Size = System::Drawing::Size(606, 581);
			this->webBrowser1->TabIndex = 0;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->webBrowser2);
			this->groupBox3->Controls->Add(this->groupBox4);
			this->groupBox3->Location = System::Drawing::Point(638, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(634, 662);
			this->groupBox3->TabIndex = 1;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"时间人流量雷达图";
			// 
			// webBrowser2
			// 
			this->webBrowser2->Location = System::Drawing::Point(6, 75);
			this->webBrowser2->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser2->Name = L"webBrowser2";
			this->webBrowser2->ScrollBarsEnabled = false;
			this->webBrowser2->Size = System::Drawing::Size(622, 581);
			this->webBrowser2->TabIndex = 1;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->dateTimePicker2);
			this->groupBox4->Controls->Add(this->label3);
			this->groupBox4->Location = System::Drawing::Point(6, 28);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(622, 41);
			this->groupBox4->TabIndex = 0;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"显示调整";
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(101, 17);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(121, 21);
			this->dateTimePicker2->TabIndex = 1;
			this->dateTimePicker2->ValueChanged += gcnew System::EventHandler(this, &TimeandPeopleFlowForm::dateTimePicker2_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(18, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 12);
			this->label3->TabIndex = 0;
			this->label3->Text = L"选择显示日期";
			// 
			// TimeandPeopleFlowForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1284, 686);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox1);
			this->Name = L"TimeandPeopleFlowForm";
			this->Text = L"TimeandPeopleFlowForm";
			this->Load += gcnew System::EventHandler(this, &TimeandPeopleFlowForm::TimeandPeopleFlowForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:SqlConnection^con = gcnew SqlConnection();
	private:Hashtable^timepeopleflowht = gcnew Hashtable();
	private:DataTable^GetDataTable(SqlConnection^con1, String^selectsql1)
	{
		con1->Open();
		SqlDataAdapter^da1 = gcnew SqlDataAdapter(selectsql1, con1);
		DataTable^result_dt = gcnew DataTable();
		da1->Fill(result_dt);
		con1->Close();
		return result_dt;
	}
			//窗体加载函数

	private: System::Void TimeandPeopleFlowForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//初始化必要参数
		con->ConnectionString = "Data Source=localhost;Initial Catalog=RunDB2;Integrated Security=True";

		this->webBrowser1->AllowWebBrowserDrop = false;
		this->webBrowser1->IsWebBrowserContextMenuEnabled = false;
		this->webBrowser1->WebBrowserShortcutsEnabled = false;
		this->webBrowser1->ObjectForScripting = this;
		String^path_current = System::Windows::Forms::Application::StartupPath;
		String^path1 = path_current + "\\时间段人流量散点图.html";
		this->webBrowser1->Navigate(path1);

		this->webBrowser2->AllowWebBrowserDrop = false;
		this->webBrowser2->IsWebBrowserContextMenuEnabled = false;
		this->webBrowser2->WebBrowserShortcutsEnabled = false;
		this->webBrowser2->ObjectForScripting = this;
		String^path2 = path_current + "\\时段人流雷达图.html";
		this->webBrowser2->Navigate(path2);
	}
	private:System::Void PaintChart()
	{
		this->webBrowser1->Document->InvokeScript("ClearAll");
		for each(String^key in timepeopleflowht->Keys)
		{
			array<System::Object^>^senddate = gcnew array<System::Object^>(1);
			senddate[0] = key;
			this->webBrowser1->Document->InvokeScript("CreateDay", senddate);
			array<Singleaxis^>^arrlist = safe_cast<array<Singleaxis^>^>(timepeopleflowht[key]);
			for (int i = 0; i < arrlist->Length; i++)
			{
				array<System::Object^>^senddata = gcnew array<System::Object^>(3);
				try
				{
					senddata[0] = arrlist[i]->axis;
					senddata[1] = arrlist[i]->position;
					senddata[2] = arrlist[i]->radius;
					//MessageBox::Show("axis:" + arrlist[i]->axis.ToString()+
					//	" position:" + arrlist[i]->position.ToString()+" radius:"+
					//	arrlist[i]->radius.ToString());
					this->webBrowser1->Document->InvokeScript("CreateData", senddata);
				}
				catch (NullReferenceException^e)
				{
					continue;
				}
			}
		}
		this->webBrowser1->Document->InvokeScript("InitChart");
	}
	private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		/*con->Open();
		String^updatesql = String::Format("UPDATE 线路人流量数据表 SET 时间='{0}' WHERE 方案编号='F002';",
		DateTime::Now);
		SqlCommand^cmd = gcnew SqlCommand(updatesql,con);
		int back=cmd->ExecuteNonQuery();
		MessageBox::Show(back.ToString());
		con->Close();*/
		this->timepeopleflowht->Clear();
		for (int k = 0; k < 7; k++)
		{

			String^selectsql = String::Format("SELECT DATEPART(hour,时间) AS 时间,SUM(上车人数) AS 上车人数和," +
				"SUM(下车人数) AS 下车人数和 FROM PeopleFlowDataTable WHERE 时间 BETWEEN '{0}' AND " +
				"dateadd(second,-1,dateadd(day,1,'{1}')) GROUP BY DATEPART(hour,时间) ORDER BY DATEPART(hour,时间);",
				this->dateTimePicker1->Value.AddDays(-k).ToShortDateString(),
				this->dateTimePicker1->Value.AddDays(-k).ToShortDateString());
			array<Singleaxis^>^peopleflows = gcnew array<Singleaxis^>(24);
			DataTable^resultdt = GetDataTable(con, selectsql);
			for (int i = 0; i < resultdt->Rows->Count; i++)
			{
				DataRow^dr = resultdt->Rows[i];
				int peopleflow_temp = int::Parse(dr["上车人数和"]->ToString()) + int::Parse(dr["下车人数和"]->ToString());
				Singleaxis^ss = gcnew Singleaxis();
				ss->axis = k;
				ss->position = int::Parse(dr["时间"]->ToString());
				//MessageBox::Show(ss->position.ToString());
				ss->radius = peopleflow_temp;
				peopleflows[ss->position] = ss;
			}
			timepeopleflowht->Add(this->dateTimePicker1->Value.AddDays(-k).ToShortDateString(), peopleflows);

		}
		if (timepeopleflowht->Keys->Count > 0)
		{
			PaintChart();
		}

	}
	private: System::Void dateTimePicker2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		String^selectsql = String::Format("SELECT DATEPART(hour,时间) AS 时间,SUM(上车人数) AS 上车人数和," +
			"SUM(下车人数) AS 下车人数和 FROM PeopleFlowDataTable WHERE 时间 BETWEEN '{0}' AND " +
			"dateadd(second,-1,dateadd(day,1,'{1}')) GROUP BY DATEPART(hour,时间) ORDER BY DATEPART(hour,时间);",
			this->dateTimePicker2->Value.ToShortDateString(),
			this->dateTimePicker2->Value.ToShortDateString());
		DataTable^resultdt = GetDataTable(con, selectsql);
		array<int>^y_data = gcnew array<int>(12);
		for (int i = 0; i < resultdt->Rows->Count; i++)
		{
			DataRow^dr = resultdt->Rows[i];
			y_data[int::Parse(dr["时间"]->ToString()) - 6] = int::Parse(dr["上车人数和"]->ToString()) + int::Parse(dr["下车人数和"]->ToString());
			//MessageBox::Show(y_data[int::Parse(dr["时间"]->ToString()) - 6].ToString());
		}
		array<System::Object^>^senddata = gcnew array<System::Object^>(12);
		for (int i = 0; i < y_data->Length; i++)
		{

			senddata[i] = y_data[i];
			//MessageBox::Show(senddata[i]->ToString());
		}
		this->webBrowser2->Document->InvokeScript("ClearAll");
		this->webBrowser2->Document->InvokeScript("GetData", senddata);
		this->webBrowser2->Document->InvokeScript("InitChart");

	}
	};
}
