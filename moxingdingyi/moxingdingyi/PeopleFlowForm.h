#pragma once

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
	/// PeopleFlowForm ժҪ
	/// </summary>
	public ref class PeopleFlowForm : public System::Windows::Forms::Form
	{
	public:
		PeopleFlowForm(void)
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
		~PeopleFlowForm()
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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ��ѡ����ToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::WebBrowser^  webBrowser2;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker3;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	protected:

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->��ѡ����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->webBrowser2 = (gcnew System::Windows::Forms::WebBrowser());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->dateTimePicker3 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->webBrowser1);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(731, 447);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"�����վ��������";
			// 
			// webBrowser1
			// 
			this->webBrowser1->Location = System::Drawing::Point(6, 88);
			this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->ScrollBarsEnabled = false;
			this->webBrowser1->Size = System::Drawing::Size(715, 352);
			this->webBrowser1->TabIndex = 1;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->dateTimePicker1);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->menuStrip1);
			this->groupBox2->Location = System::Drawing::Point(6, 22);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(715, 52);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"��ʾ������";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(221, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 12);
			this->label2->TabIndex = 2;
			this->label2->Text = L"ѡ��Ҫ��ʾ����";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(77, 21);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(121, 21);
			this->dateTimePicker1->TabIndex = 1;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &PeopleFlowForm::dateTimePicker1_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ѡ������";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->��ѡ����ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(313, 21);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(76, 25);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ��ѡ����ToolStripMenuItem
			// 
			this->��ѡ����ToolStripMenuItem->Name = L"��ѡ����ToolStripMenuItem";
			this->��ѡ����ToolStripMenuItem->Size = System::Drawing::Size(68, 21);
			this->��ѡ����ToolStripMenuItem->Text = L"��ѡ����";
			this->��ѡ����ToolStripMenuItem->CheckedChanged += gcnew System::EventHandler(this, &PeopleFlowForm::��ѡ����ToolStripMenuItem_CheckedChanged);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->webBrowser2);
			this->groupBox3->Controls->Add(this->groupBox4);
			this->groupBox3->Location = System::Drawing::Point(749, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(532, 447);
			this->groupBox3->TabIndex = 1;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"������������";
			// 
			// webBrowser2
			// 
			this->webBrowser2->Location = System::Drawing::Point(6, 88);
			this->webBrowser2->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser2->Name = L"webBrowser2";
			this->webBrowser2->ScrollBarsEnabled = false;
			this->webBrowser2->Size = System::Drawing::Size(520, 352);
			this->webBrowser2->TabIndex = 1;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->dateTimePicker3);
			this->groupBox4->Controls->Add(this->dateTimePicker2);
			this->groupBox4->Controls->Add(this->comboBox1);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Controls->Add(this->label4);
			this->groupBox4->Controls->Add(this->label3);
			this->groupBox4->Location = System::Drawing::Point(6, 22);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(520, 52);
			this->groupBox4->TabIndex = 0;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"��ʾ����";
			// 
			// dateTimePicker3
			// 
			this->dateTimePicker3->Location = System::Drawing::Point(384, 24);
			this->dateTimePicker3->Name = L"dateTimePicker3";
			this->dateTimePicker3->Size = System::Drawing::Size(121, 21);
			this->dateTimePicker3->TabIndex = 2;
			this->dateTimePicker3->ValueChanged += gcnew System::EventHandler(this, &PeopleFlowForm::dateTimePicker3_ValueChanged);
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(240, 24);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(121, 21);
			this->dateTimePicker2->TabIndex = 2;
			this->dateTimePicker2->ValueChanged += gcnew System::EventHandler(this, &PeopleFlowForm::dateTimePicker2_ValueChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"7��", L"30��", L"3����", L"����", L"һ��" });
			this->comboBox1->Location = System::Drawing::Point(65, 24);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(97, 20);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &PeopleFlowForm::comboBox1_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(367, 27);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(11, 12);
			this->label5->TabIndex = 0;
			this->label5->Text = L"-";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(181, 27);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 12);
			this->label4->TabIndex = 0;
			this->label4->Text = L"��ȷʱ��";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 27);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 12);
			this->label3->TabIndex = 0;
			this->label3->Text = L"���ʱ��";
			// 
			// PeopleFlowForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1284, 686);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"PeopleFlowForm";
			this->Text = L"����������ͳ��";
			this->Load += gcnew System::EventHandler(this, &PeopleFlowForm::PeopleFlowForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		//����������¼�
	private:SqlConnection^con = gcnew SqlConnection();
	private:int maxstationsnum = 0;
	private:array<String^>^x_result;
	private:Hashtable^y_arrht = gcnew Hashtable();
	private:DataTable^GetDataTable(SqlConnection^con1, String^selectsql1)
	{
				con1->Open();
				SqlDataAdapter^da1 = gcnew SqlDataAdapter(selectsql1, con1);
				DataTable^result_dt = gcnew DataTable();
				da1->Fill(result_dt);
				con1->Close();
				return result_dt;
	}
	private:System::Void PaintChart1()
	{
				this->webBrowser1->Document->InvokeScript("ClearAll");
				for (int i = 0; i < x_result->Length; i++)
				{
					array<System::Object^>^send_x_result = gcnew array<System::Object^>(1);
					send_x_result[0] = x_result[i];
					this->webBrowser1->Document->InvokeScript("GetXData", send_x_result);
				}
				for each(String^key in y_arrht->Keys)
				{
					array<float>^y_result = safe_cast<array<float>^>(y_arrht[key]);
					for (int i = 0; i < y_result->Length; i++)
					{
						array<System::Object^>^send_y_result = gcnew array<System::Object^>(1);
						send_y_result[0] = y_result[i];
						this->webBrowser1->Document->InvokeScript("GetYData", send_y_result);
					}
					array<System::Object^>^sendproposalnum = gcnew array<System::Object^>(1);
					sendproposalnum[0] = key;
					this->webBrowser1->Document->InvokeScript("CreateSerie", sendproposalnum);
				}
				array<System::Object^>^senddate = gcnew array<System::Object^>(1);
				senddate[0] = this->dateTimePicker1->Value.ToShortDateString();
				this->webBrowser1->Document->InvokeScript("InitChart", senddate);
	}
	private: System::Void PeopleFlowForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 //��ʼ����Ҫ����
				 this->webBrowser1->AllowWebBrowserDrop = false;
				 this->webBrowser1->IsWebBrowserContextMenuEnabled = false;
				 this->webBrowser1->WebBrowserShortcutsEnabled = false;
				 this->webBrowser1->ObjectForScripting = this;
				 String^path_current = System::Windows::Forms::Application::StartupPath;

				 String^path1 = path_current + "\\�����������վ��������ͼ.html";
				 this->webBrowser1->Navigate(path1);

				 this->webBrowser2->AllowWebBrowserDrop = false;
				 this->webBrowser2->IsWebBrowserContextMenuEnabled = false;
				 this->webBrowser2->WebBrowserShortcutsEnabled = false;
				 this->webBrowser2->ObjectForScripting = this;
				 String^path2 = path_current + "\\����������ͼ.html";
				 this->webBrowser2->Navigate(path2);

				 con->ConnectionString = "Data Source=localhost;Initial Catalog=RunDB2;Integrated Security=True";

				 String^selectsql = String::Format("SELECT �������,MAX(վ����) FROM " +
					 "(SELECT �������,COUNT(DISTINCT վ������) AS վ���� FROM PeopleFlowDataTable GROUP BY �������) " +
					 "AS T1 GROUP BY �������;");
				 DataTable^stationsnumdt = GetDataTable(con, selectsql);
				 maxstationsnum = int::Parse(stationsnumdt->Rows[0]->ItemArray[1]->ToString());//��·���վ����=14
				 selectsql = String::Format("SELECT DISTINCT վ������,վ���� FROM PeopleFlowDataTable " +
					 "WHERE �������='{0}' ORDER BY վ����;", stationsnumdt->Rows[0]->ItemArray[0]->ToString());
				 DataTable^stationsdt = GetDataTable(con, selectsql);//�����ȡ����������27��
				 x_result = gcnew array<String^>(maxstationsnum);//վ����������
				 for (int i = 0; i < maxstationsnum; i++)
				 {
					 x_result[i] = stationsdt->Rows[i]->ItemArray[0]->ToString();//��ʼ��վ���������飬��Ϊͼ���X��
				 }
	}
			 //ѡ�����ڸı�-����װ�ظ������µķ���
private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 String^selectsql = String::Format("SELECT DISTINCT �г���� AS �г����,������� AS ������� FROM PeopleFlowDataTable " +
				 "WHERE ʱ�� BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}'));",
				 this->dateTimePicker1->Value.ToShortDateString(), this->dateTimePicker1->Value.ToShortDateString());
			 DataTable^proposalsofdaydt = GetDataTable(con, selectsql);
			 //MessageBox::Show(proposalsofdaydt->Rows->Count.ToString());
			 this->��ѡ����ToolStripMenuItem->DropDownItems->Clear();
			 for (int i = 0; i < proposalsofdaydt->Rows->Count; i++)
			 {
				 DataRow^dr = proposalsofdaydt->Rows[i];
				 System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
				 toolstripmenuitem->Name = L"toolStripMenuTtem" + dr["�������"]->ToString();
				 toolstripmenuitem->Size = System::Drawing::Size(152, 22);
				 toolstripmenuitem->Text = dr["�������"]->ToString();
				 toolstripmenuitem->CheckOnClick = true;
				 toolstripmenuitem->Checked = false;//Ĭ�ϱ�ѡ��
				 this->��ѡ����ToolStripMenuItem->DropDownItems->Add(toolstripmenuitem);
				 toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &PeopleFlowForm::��ѡ����ToolStripMenuItem_CheckedChanged);
			 }

}
private: System::Void ��ѡ����ToolStripMenuItem_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 y_arrht->Clear();
			 /*ÿһ�ι�ѡ���������仯�������y_arrht���ڱ����жϵ�ǰ��ѡ����Щ����*/
			 for (int i = 0; i < this->��ѡ����ToolStripMenuItem->DropDownItems->Count; i++)
			 {
				 System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = safe_cast<System::Windows::Forms::ToolStripMenuItem^>(this->��ѡ����ToolStripMenuItem->DropDownItems[i]);
				 if (toolstripmenuitem->Checked == true)
				 {
					 array<float>^y_result = gcnew array<float>(maxstationsnum);
					 String^selectsql = String::Format("SELECT �ϳ�����,�³�����,վ������,վ���� " +
						 "FROM PeopleFlowDataTable WHERE �������='{0}' AND ʱ�� BETWEEN '{1}' AND dateadd(second,-1,dateadd(day,1,'{2}')) ORDER BY վ����;",
						 toolstripmenuitem->Text,
						 this->dateTimePicker1->Value.ToShortDateString(), this->dateTimePicker1->Value.ToShortDateString());
					 DataTable^y_datadt = GetDataTable(con, selectsql);
					 for (int j = 0; j < y_datadt->Rows->Count; j++)
					 {
						 DataRow^dr = y_datadt->Rows[j];

						 y_result[int::Parse(dr["վ����"]->ToString()) - 1] = float::Parse(dr["�ϳ�����"]->ToString()) + float::Parse(dr["�³�����"]->ToString());
						 //MessageBox::Show(y_result[j].ToString());
					 }
					 y_arrht->Add(toolstripmenuitem->Text, y_result);
				 }
			 }
			 PaintChart1();
}
private:System::Void ShowPeopleFlow(int days)
{
			this->webBrowser2->Document->InvokeScript("ClearAll");
			array<String^>^x_arr = gcnew array<String^>(days);
			array<float>^y_arr = gcnew array<float>(days);
			con->Open();
			for (int i = 0; i < days; i++)
			{
				String^selectsql = String::Format("SELECT SUM(�ϳ�����) AS �ϳ�������,SUM(�³�����) AS �³������� FROM PeopleFlowDataTable WHERE ʱ�� BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}'));",
					DateTime::Now.AddDays(-i).ToShortDateString(), DateTime::Now.AddDays(-i).ToShortDateString());
				//String^selectsql = String::Format("SELECT SUM(����) FROM �����������ݱ� WHERE ʱ�� BETWEEN '{0}' AND dateadd(day,-"+i+",GETDATE());",
				//	DateTime::Now.ToShortDateString());
				SqlDataAdapter^da = gcnew SqlDataAdapter(selectsql, con);
				DataTable^peopleflowdt = gcnew DataTable("����������");
				da->Fill(peopleflowdt);
				DataRow^dr = peopleflowdt->Rows[0];
				//MessageBox::Show(dr["���칦�ĺ�"]->ToString());
				x_arr[days - i - 1] = DateTime::Now.AddDays(-i).ToShortDateString();
				try
				{
					y_arr[days - i - 1] = float::Parse(dr["�ϳ�������"]->ToString()) + float::Parse(dr["�³�������"]->ToString());
				}
				catch (FormatException^e)
				{
					y_arr[days - i - 1] = 0;
				}
			}
			con->Close();

			for (int i = 0; i < days; i++)
			{
				array<System::Object^>^senddata = gcnew array<System::Object^>(2);
				senddata[0] = x_arr[i];
				senddata[1] = y_arr[i];
				this->webBrowser2->Document->InvokeScript("GetData", senddata);
			}
			this->webBrowser2->Document->InvokeScript("InitChart");
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->comboBox1->SelectedIndex == 0)
			 {
				 ShowPeopleFlow(7);
			 }
			 if (this->comboBox1->SelectedIndex == 1)
			 {
				 ShowPeopleFlow(30);
			 }
			 if (this->comboBox1->SelectedIndex == 2)
			 {
				 ShowPeopleFlow(90);
			 }
			 if (this->comboBox1->SelectedIndex == 3)
			 {
				 ShowPeopleFlow(180);
			 }
			 if (this->comboBox1->SelectedIndex == 4)
			 {
				 ShowPeopleFlow(365);
			 }
}
private: System::Void dateTimePicker2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 int days = this->dateTimePicker3->Value.DayOfYear - this->dateTimePicker2->Value.DayOfYear;
			 ShowPeopleFlow(days);
}
private: System::Void dateTimePicker3_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 int days = this->dateTimePicker3->Value.DayOfYear - this->dateTimePicker2->Value.DayOfYear;
			 ShowPeopleFlow(days);
}
	};
}
