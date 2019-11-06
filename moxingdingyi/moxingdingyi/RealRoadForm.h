#pragma once
#include"ProjectPropertyForm.h"
#include"RealRoadInfo.h"
namespace moxingdingyi {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	//����
	using namespace System::Data::SqlClient;
	using namespace System::Threading;
	using namespace System::Collections::Generic;
	//���������ռ�
	using namespace RealRoad;
	using namespace System::Security::Permissions;
	[System::Runtime::InteropServices::ComVisibleAttribute(true)]

	/// <summary>
	/// RealRoadForm ժҪ
	/// </summary>
	public ref class RealRoadForm : public System::Windows::Forms::Form
	{
	public:
		RealRoadForm(void)
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
		~RealRoadForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:


	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  RepeatradioButton2;
	private: System::Windows::Forms::RadioButton^  CurrentradioButton1;


	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::ComboBox^  AdjustRunIntervalcomboBox1;


	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::ToolStripComboBox^  CityNametoolStripComboBox2;
	private: System::Windows::Forms::ToolStripComboBox^  RoadNametoolStripComboBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::ToolStripMenuItem^  ѡ�����еķ���ToolStripMenuItem;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::RadioButton^  MakeprojectradioButton1;


	private: System::Windows::Forms::WebBrowser^  webBrowser1;

	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// ����������������
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ�޸�
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->CityNametoolStripComboBox2 = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->RoadNametoolStripComboBox1 = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->ѡ�����еķ���ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->RepeatradioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->MakeprojectradioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->CurrentradioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->AdjustRunIntervalcomboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Transparent;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->CityNametoolStripComboBox2,
					this->RoadNametoolStripComboBox1, this->ѡ�����еķ���ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1292, 29);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// CityNametoolStripComboBox2
			// 
			this->CityNametoolStripComboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"�麣" });
			this->CityNametoolStripComboBox2->Name = L"CityNametoolStripComboBox2";
			this->CityNametoolStripComboBox2->Size = System::Drawing::Size(145, 25);
			this->CityNametoolStripComboBox2->Text = L"ѡ��������������";
			this->CityNametoolStripComboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &RealRoadForm::ChooseCityChanged);
			this->CityNametoolStripComboBox2->TextUpdate += gcnew System::EventHandler(this, &RealRoadForm::CityNametoolStripComboBox2_TextUpdate);
			// 
			// RoadNametoolStripComboBox1
			// 
			this->RoadNametoolStripComboBox1->Name = L"RoadNametoolStripComboBox1";
			this->RoadNametoolStripComboBox1->Size = System::Drawing::Size(145, 25);
			this->RoadNametoolStripComboBox1->Text = L"�����ѡ��������·";
			this->RoadNametoolStripComboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &RealRoadForm::ChooseRoadChanged);
			// 
			// ѡ�����еķ���ToolStripMenuItem
			// 
			this->ѡ�����еķ���ToolStripMenuItem->Name = L"ѡ�����еķ���ToolStripMenuItem";
			this->ѡ�����еķ���ToolStripMenuItem->Size = System::Drawing::Size(104, 25);
			this->ѡ�����еķ���ToolStripMenuItem->Text = L"ѡ�����еķ���";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->RepeatradioButton2);
			this->groupBox1->Controls->Add(this->MakeprojectradioButton1);
			this->groupBox1->Controls->Add(this->CurrentradioButton1);
			this->groupBox1->Location = System::Drawing::Point(12, 28);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(278, 49);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"ģʽѡ��";
			// 
			// RepeatradioButton2
			// 
			this->RepeatradioButton2->AutoSize = true;
			this->RepeatradioButton2->Checked = true;
			this->RepeatradioButton2->Location = System::Drawing::Point(192, 21);
			this->RepeatradioButton2->Name = L"RepeatradioButton2";
			this->RepeatradioButton2->Size = System::Drawing::Size(71, 16);
			this->RepeatradioButton2->TabIndex = 0;
			this->RepeatradioButton2->TabStop = true;
			this->RepeatradioButton2->Text = L"�켣����";
			this->RepeatradioButton2->UseVisualStyleBackColor = true;
			this->RepeatradioButton2->CheckedChanged += gcnew System::EventHandler(this, &RealRoadForm::ModeChosenChanged);
			// 
			// MakeprojectradioButton1
			// 
			this->MakeprojectradioButton1->AutoSize = true;
			this->MakeprojectradioButton1->Location = System::Drawing::Point(16, 21);
			this->MakeprojectradioButton1->Name = L"MakeprojectradioButton1";
			this->MakeprojectradioButton1->Size = System::Drawing::Size(71, 16);
			this->MakeprojectradioButton1->TabIndex = 0;
			this->MakeprojectradioButton1->TabStop = true;
			this->MakeprojectradioButton1->Text = L"���ɷ���";
			this->MakeprojectradioButton1->UseVisualStyleBackColor = true;
			this->MakeprojectradioButton1->CheckedChanged += gcnew System::EventHandler(this, &RealRoadForm::ModeChosenChanged);
			// 
			// CurrentradioButton1
			// 
			this->CurrentradioButton1->AutoSize = true;
			this->CurrentradioButton1->Location = System::Drawing::Point(102, 21);
			this->CurrentradioButton1->Name = L"CurrentradioButton1";
			this->CurrentradioButton1->Size = System::Drawing::Size(71, 16);
			this->CurrentradioButton1->TabIndex = 0;
			this->CurrentradioButton1->TabStop = true;
			this->CurrentradioButton1->Text = L"ʵʱ��ʾ";
			this->CurrentradioButton1->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->AdjustRunIntervalcomboBox1);
			this->groupBox2->Controls->Add(this->dateTimePicker1);
			this->groupBox2->Controls->Add(this->numericUpDown1);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Location = System::Drawing::Point(296, 32);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(676, 45);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"����������";
			// 
			// AdjustRunIntervalcomboBox1
			// 
			this->AdjustRunIntervalcomboBox1->FormattingEnabled = true;
			this->AdjustRunIntervalcomboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"ԭ��", L"�ӿ�2����", L"�ӿ�5����", L"�ӿ�8����",
					L"�ӿ�10����", L"����1.5����", L"����2����"
			});
			this->AdjustRunIntervalcomboBox1->Location = System::Drawing::Point(522, 17);
			this->AdjustRunIntervalcomboBox1->Name = L"AdjustRunIntervalcomboBox1";
			this->AdjustRunIntervalcomboBox1->Size = System::Drawing::Size(125, 20);
			this->AdjustRunIntervalcomboBox1->TabIndex = 3;
			this->AdjustRunIntervalcomboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &RealRoadForm::AdjustRunInterval);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(278, 17);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(134, 21);
			this->dateTimePicker1->TabIndex = 2;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(81, 17);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(98, 21);
			this->numericUpDown1->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(439, 21);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 12);
			this->label3->TabIndex = 0;
			this->label3->Text = L"���������ٶ�";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(243, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 12);
			this->label2->TabIndex = 0;
			this->label2->Text = L"����";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(185, 21);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 12);
			this->label4->TabIndex = 0;
			this->label4->Text = L"������";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ͬʱ��ʾ";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(978, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 45);
			this->button1->TabIndex = 4;
			this->button1->Text = L"��ʼ����";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &RealRoadForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &RealRoadForm::timer1_Tick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1135, 32);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 45);
			this->button2->TabIndex = 4;
			this->button2->Text = L"ֹͣ����";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &RealRoadForm::button2_Click);
			// 
			// webBrowser1
			// 
			this->webBrowser1->Location = System::Drawing::Point(12, 85);
			this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->Size = System::Drawing::Size(1268, 644);
			this->webBrowser1->TabIndex = 6;
			// 
			// RealRoadForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1292, 741);
			this->Controls->Add(this->webBrowser1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"RealRoadForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ʵ����·ͼ";
			this->Load += gcnew System::EventHandler(this, &RealRoadForm::RealRoadForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:List<DateTime>^starttime_arr;
	private:SqlConnection^con = gcnew SqlConnection();
			SqlConnection^con1 = gcnew SqlConnection();
	private:String^sqlstr;
	private:Operate_System^op;
	

			//��ѯ����
	private:DataTable^GetTable(SqlConnection^sqlcon, String^sqlstr)
	{
		sqlcon->Open();
		SqlDataAdapter^da = gcnew SqlDataAdapter(sqlstr, sqlcon);
		DataTable^result_dt = gcnew DataTable();
		da->Fill(result_dt);
		sqlcon->Close();
		return result_dt;
	}
	//����
	/*
	��ʼ��html�ű�
	��ʼ�����ݿ����ӷ�
	���ִ����ݿ���·����ѡ������Ϊ����ѡ�¿�ѡ��
	*/
	private: System::Void RealRoadForm_Load(System::Object^  sender, System::EventArgs^  e) {

		//this->richTextBox1->AppendText("\t���\t����ʱ��\t����\n\n");

		this->webBrowser1->AllowWebBrowserDrop = false;
		this->webBrowser1->IsWebBrowserContextMenuEnabled = false;
		this->webBrowser1->WebBrowserShortcutsEnabled = false;
		this->webBrowser1->ObjectForScripting = this;
		String^path_current = System::Windows::Forms::Application::StartupPath;
		String^path1 = path_current + "\\testmap7.html";
		this->webBrowser1->Navigate(path1);
		//this->webBrowser1->Navigate("C:\\Users\\Lixingye\\Desktop\\testmap7.html");

		this->RepeatradioButton2->Checked = false;
		this->MakeprojectradioButton1->Checked = false;

		con1->ConnectionString = "Data Source=localhost;Initial Catalog=RunDB2;Integrated Security=True";
		//�������ݿ��ж���õ���·����
		con->ConnectionString = "Data Source=localhost;Initial Catalog=�г����ݿ�;Integrated Security=True";

		String^selectsql = "SELECT ��·��� AS ��·���,��·���� AS ��·���� FROM ��·��Ϣ;";
		DataTable^roadinfodt = GetTable(con, selectsql);

		for (int i = 0; i < roadinfodt->Rows->Count; i++)
		{
			DataRow^dr = roadinfodt->Rows[i];
			this->RoadNametoolStripComboBox1->Items->Add(dr["��·���"]->ToString());
		}
	}
	//ѡ�����
	/*
	�������г������ƽ���ѡ��
	*/
	private: System::Void ChooseCityChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->CityNametoolStripComboBox2->SelectedIndex >= 0)
		{
			String^cityname = this->CityNametoolStripComboBox2->Items[this->CityNametoolStripComboBox2->SelectedIndex]->ToString();
			array<System::Object^>^sendcityname = gcnew array<System::Object^>(1);
			sendcityname[0] = cityname;
			this->webBrowser1->Document->InvokeScript("GetCityName", sendcityname);
		}
	}
	//�����������ʾ��ͬ��ͼ
	private: System::Void CityNametoolStripComboBox2_TextUpdate(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			String^cityname = this->CityNametoolStripComboBox2->Text;
			array<System::Object^>^sendcityname = gcnew array<System::Object^>(1);
			sendcityname[0] = cityname;
			this->webBrowser1->Document->InvokeScript("GetCityName", sendcityname);
		}
		catch (FormatException^e)
		{

		}
	}
	//ѡ����·
	private: System::Void ChooseRoadChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->RoadNametoolStripComboBox1->SelectedIndex >= 0)
		{
			//���ûѡ�����ʹ��ͼ��ʾ��������·������سɹ�
			if ((this->CityNametoolStripComboBox2->SelectedIndex < 0) || (String::IsNullOrEmpty(this->CityNametoolStripComboBox2->Text)))
				return;
			//��ȡ��·����
			op = gcnew Operate_System(this->RoadNametoolStripComboBox1->Text);
			op->InitPath(this->RoadNametoolStripComboBox1->Text);

			//��ʼ����·״��
			this->webBrowser1->Document->InvokeScript("ClearStationsorigin");
			op->InitSites();
			for (int i = 0; i < op->sites->Count; i++)
			{
				String^sitename = op->sites[i]->name->Trim();
				array<System::Object^>^sendstationname = gcnew array<System::Object^>(1);
				sendstationname[0] = sitename;
				this->webBrowser1->Document->InvokeScript("GetStationStatus", sendstationname);
			}
			//����·���ƴ���html��ʾ��ͼ
			String^linename = op->roadname;
			array<System::Object^>^sendlinename = gcnew array<System::Object^>(1);
			sendlinename[0] = linename;
			this->webBrowser1->Document->InvokeScript("InitLine", sendlinename);
			//��ȡ����·������������з�����Ϣ�����û�ѡ��
			sqlstr = String::Format("SELECT DISTINCT ������� AS ������� FROM ������Ϣ WHERE ��·���='{0}';", op->roadstrnum);
			DataTable^proposalsdt = GetTable(con, sqlstr);
			//�����������Ϊ����ѡ�ѡ��û�ѡ��
			if (this->RepeatradioButton2->Checked == true)
			{
				//�ṩ����ѡ��
				this->ѡ�����еķ���ToolStripMenuItem->DropDownItems->Clear();//****************************//ȫ�ֱ�����Ҫ���

				for (int i = 0; i < proposalsdt->Rows->Count; i++)
				{
					DataRow^proposaldr = proposalsdt->Rows[i];
					System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
					toolstripmenuitem->Name = L"toolStripMenuTtem" + (i + 1).ToString();
					toolstripmenuitem->Size = System::Drawing::Size(152, 22);
					toolstripmenuitem->Text = proposaldr["�������"]->ToString();
					toolstripmenuitem->CheckOnClick = true;
					this->ѡ�����еķ���ToolStripMenuItem->DropDownItems->Add(toolstripmenuitem);
					toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &RealRoadForm::toolStripMenuItem_CheckedChanged);
				}
			}
			else if (this->MakeprojectradioButton1->Checked == true)
			{
				//�ṩ����ѡ��
				this->ѡ�����еķ���ToolStripMenuItem->DropDownItems->Clear();//****************************//ȫ�ֱ�����Ҫ���

				for (int i = 0; i < proposalsdt->Rows->Count; i++)
				{
					DataRow^proposaldr = proposalsdt->Rows[i];
					System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
					toolstripmenuitem->Name = L"toolStripMenuTtem" + (i + 1).ToString();
					toolstripmenuitem->Size = System::Drawing::Size(152, 22);
					toolstripmenuitem->Text = proposaldr["�������"]->ToString();
					toolstripmenuitem->CheckOnClick = true;
					this->ѡ�����еķ���ToolStripMenuItem->DropDownItems->Add(toolstripmenuitem);
					toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &RealRoadForm::SetStartTime);
				}
				starttime_arr = gcnew List<DateTime>();
			}
			else if (this->CurrentradioButton1->Checked == true)
			{
				//�ṩ����ѡ��
				this->ѡ�����еķ���ToolStripMenuItem->DropDownItems->Clear();//****************************//ȫ�ֱ�����Ҫ���
				for (int i = 0; i < proposalsdt->Rows->Count; i++)
				{
					DataRow^proposaldr = proposalsdt->Rows[i];
					System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
					toolstripmenuitem->Name = L"toolStripMenuTtem" + (i + 1).ToString();
					toolstripmenuitem->Size = System::Drawing::Size(152, 22);
					toolstripmenuitem->Text = proposaldr["�������"]->ToString();
					toolstripmenuitem->CheckOnClick = true;
					this->ѡ�����еķ���ToolStripMenuItem->DropDownItems->Add(toolstripmenuitem);
					toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &RealRoadForm::SysMode);
				}
			}
		}
	}
	//ѡ����·�󽫸���·�������з���������proposht��
			   /*
			   ��ʼ����
			   �����ظ���ʼ����������·��š�������š��г���š�������ݺš����λ��
			   ���ظ���ʼ����������ʼʱ��㡢����ʱ��㡢������š���ǰλ�á���������ʶ������Ԥ��ʶ����ʻ����
			   �仯�������ٶȡ����ٶȡ�����������
			   */
	//ѡ��ͬ�ķ��������ʾ���ظ�ģʽ�µİ��¼���
	private: System::Void toolStripMenuItem_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->RepeatradioButton2->Checked == true)
		{
			System::Windows::Forms::ToolStripMenuItem^item = safe_cast<System::Windows::Forms::ToolStripMenuItem^>(sender);
			if (item->Checked == true)
			{
				op->InitTram(item->Text);
			}
			else
			{
				op->RemoveTram(item->Text);
			}
		}
	}
	//������ʼʱ�䣨���Ʒ���ģʽ�µİ��¼���
	private:System::Void SetStartTime(System::Object^  sender, System::EventArgs^  e)
	{
		System::Windows::Forms::ToolStripMenuItem^item = safe_cast<System::Windows::Forms::ToolStripMenuItem^>(sender);
		//MessageBox::Show(sender->ToString());
		if (item->Checked == true)
		{
			ProjectPropertyForm^ppform = gcnew ProjectPropertyForm();
			if (ppform->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				if (!(String::IsNullOrEmpty(ppform->maskedTextBox1->Text)))
				{
					op->InitTram(item->Text, ppform->maskedTextBox1->Text);//�����˹�������ʼʱ���
					DateTime temp_time = Convert::ToDateTime(ppform->maskedTextBox1->Text);//����û���й�***********
					if (!(starttime_arr->Contains(temp_time)))
					{
						starttime_arr->Add(temp_time);
					}
				}
			}
			starttime_arr->Sort();//������˳������ʱ����ʼ���������
		}
		else if (item->Checked == false)//����ѽڵ�ɾ��
		{
			op->RemoveTram(item->Text);
		}
	}
	//ʵʱ��ʾģʽ
	private:System::Void SysMode(System::Object^  sender, System::EventArgs^  e)
	{
		System::Windows::Forms::ToolStripMenuItem^item = safe_cast<System::Windows::Forms::ToolStripMenuItem^>(sender);
		if (item->Checked == true)
		{
			for each (System::Windows::Forms::ToolStripMenuItem^item1 in this->ѡ�����еķ���ToolStripMenuItem->DropDownItems)
			{
				if (!String::Equals(item1->Text, sender->ToString()))
				{
					item1->Checked = false;//���������в��ǵ�ǰѡ�з���ȥ��
				}
			}

			//MessageBox::Show(sender->ToString());
			if (item->Checked == true)
			{
				op->InitTram(item->Text, "ʵʱ", "���ʲô");//������������Ϊ�����غ������ã��е����
			}
			else if (item->Checked == false)//����ѽڵ�ɾ��
			{
				op->RemoveTram(item->Text, "ʵʱ");
			}
		}
	}
			//��ʼ��ť
	private:array<int>^map_starttimetotrams;//ӳ������ҵ���Ӧ��������
	private:DateTime timemanager;//����ʱ����
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->MakeprojectradioButton1->Checked == true)
		{
			map_starttimetotrams = gcnew array<int>(starttime_arr->Count);
			timemanager = starttime_arr[0];//��������ʱ���ߵ���ʼ��
			//this->richTextBox1->Clear();
			//this->richTextBox1->AppendText("���\t����ʱ��\t����\n\n");
			//����ʱ���齫����������ʱ��˳�����������ӳ�䣩
			for (int i = 0; i < op->trams->Count; i++)
			{
				if (!String::IsNullOrEmpty(op->trams[i]->settime))
				{
					DateTime temp_time = Convert::ToDateTime(op->trams[i]->settime);
					int index_1 = starttime_arr->IndexOf(temp_time);//�ҳ�������ʱ������Ӧ������
					map_starttimetotrams[i] = index_1;
				}
			}
		}
		this->webBrowser1->Document->InvokeScript("RunStart");
	}
			 //ֹͣ��ť
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->timer1->Stop();
	}
			 //��ʱ����ʼ
	public:void Run()
	{

		if (MessageBox::Show("������ɣ�", "��ʾ", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::Yes)
		{
			this->timer1->Start();
		}

	}

		   //��ʱ�����䳵����Ϣ���ű���ʾ
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		//ģ��೵��������
		if (this->MakeprojectradioButton1->Checked == true)
		{
			for (int i = 0; i < op->trams->Count; i++)
			{
				System::TimeSpan tram_settime = Convert::ToDateTime(op->trams[i]->settime).TimeOfDay;//��ȡ��ʼʱ��
				if (timemanager.TimeOfDay < tram_settime)//���ʱ�������û���糵���˹����ÿ�ʼʱ�䣬�����ж���һ�糵
				{
					timemanager = timemanager.AddSeconds(+1);
					continue;
				}
				//ʱ�������ʱ�䵽��糵���˹�����ʱ��
				op->Run_imm(op->trams[i], i);
				//Checked(op->trams[i]);
				if (op->trams[i]->draw)
				{
					array<System::Object^>^createcar = gcnew array<System::Object^>(9);
					createcar[8] = op->trams[i]->voltage;//��ѹ
					createcar[7] = op->trams[i]->current;//����
					createcar[6] = op->trams[i]->peopontram;//��������
					createcar[5] = op->trams[i]->accelerate;//���ٶ�
					createcar[4] = op->trams[i]->velocity;//�ٶ�
					if (op->trams[i]->draw&&op->trams[i]->predraw)
					{
						createcar[3] = 0;//�Ƿ����
					}
					else
					{
						createcar[3] = 1;//�Ƿ����
						op->trams[i]->draw = false;
					}
					if (op->trams[i]->pos <= op->trams[i]->last_pos / 2)
					{
						//λ��
						createcar[2] = ((op->trams[i]->pos) / (op->trams[i]->last_pos / 2)).ToString();
					}
					else
					{
						//λ��
						createcar[2] = ((op->trams[i]->pos - (op->trams[i]->last_pos / 2)) / (op->trams[i]->last_pos / 2)).ToString();
					}
					//λ��
					createcar[1] = op->trams[i]->direction;
					createcar[0] = op->trams[i]->tram_strnum->Trim();//�����
					this->webBrowser1->Document->InvokeScript("CreateCar", createcar);
				}
			}
		}
		else if (this->RepeatradioButton2->Checked == true)//�ظ�ģʽ-���ż���ģʽ
		{
			for (int i = 0; i < op->trams->Count; i++)
			{
				op->Run_imm(op->trams[i], i);
				if (op->trams[i]->draw)
				{
					array<System::Object^>^createcar = gcnew array<System::Object^>(9);
					createcar[8] = op->trams[i]->voltage;//��ѹ
					createcar[7] = op->trams[i]->current;//����
					createcar[6] = op->trams[i]->peopontram;//��������
					createcar[5] = op->trams[i]->accelerate;//���ٶ�
					createcar[4] = op->trams[i]->velocity;//�ٶ�
					if (op->trams[i]->draw&&op->trams[i]->predraw)
					{
						createcar[3] = 0;//�Ƿ����
					}
					else
					{
						createcar[3] = 1;//�Ƿ����
						op->trams[i]->draw = false;
					}
					if (op->trams[i]->pos <= op->trams[i]->last_pos / 2)
					{
						//λ��
						createcar[2] = ((op->trams[i]->pos) / (op->trams[i]->last_pos / 2)).ToString();
					}
					else
					{
						//λ��
						createcar[2] = ((op->trams[i]->pos - (op->trams[i]->last_pos / 2)) / (op->trams[i]->last_pos / 2)).ToString();
					}
					//λ��
					createcar[1] = op->trams[i]->direction;
					createcar[0] = op->trams[i]->tram_strnum->Trim();//�����
					this->webBrowser1->Document->InvokeScript("CreateCar", createcar);
				}
			}
		}
		else if (this->CurrentradioButton1->Checked == true)//ʵʱ����ģʽ-ͬ��
		{
			op->SysRun(op->trams[0]);
			if (op->trams[0]->draw)
			{
				array<System::Object^>^createcar = gcnew array<System::Object^>(9);
				createcar[8] = op->trams[0]->voltage;//��ѹ
				createcar[7] = op->trams[0]->current;//����
				createcar[6] = op->trams[0]->peopontram;//��������
				createcar[5] = op->trams[0]->accelerate;//���ٶ�
				createcar[4] = op->trams[0]->velocity;//�ٶ�
				if (op->trams[0]->draw&&op->trams[0]->predraw)
				{
					createcar[3] = 0;//�Ƿ����
				}
				else
				{
					createcar[3] = 1;//�Ƿ����
					op->trams[0]->draw = false;
				}
				if (op->trams[0]->pos <= op->trams[0]->last_pos / 2)
				{
					createcar[2] = ((op->trams[0]->pos) / (op->trams[0]->last_pos / 2)).ToString();
				}
				else
				{
					createcar[2] = ((op->trams[0]->pos - (op->trams[0]->last_pos / 2)) / (op->trams[0]->last_pos / 2)).ToString();
				}
				createcar[1] = op->trams[0]->direction;
				createcar[0] = op->trams[0]->tram_strnum->Trim();//�����
				this->webBrowser1->Document->InvokeScript("CreateCar", createcar);
			}
		}

		//���л�����ģʽʱ����Ҫ�������ͼ�ϳ�����ֹͣ��ʱ������
		int nodraw = 0;
		for (int i = 0; i < op->trams->Count; i++)
		{
			if (op->trams[i]->predraw == false)
				nodraw = nodraw + 1;
		}
		if (nodraw == op->trams->Count)
		{
			op->trams->Clear();
			op->plan_indexs->Clear();
			this->timer1->Stop();
		}
	}

			 //ģʽѡ��ı䣬Ϊÿ���������°󶨲�ͬģʽ�µ��¼�
	private: System::Void ModeChosenChanged(System::Object^  sender, System::EventArgs^  e) {
		try {
			for (int i = 0; i < op->trams->Count; i++)
			{
				op->RemoveTram(op->trams[i]->planstrnum);
			}
		}
		catch (Exception^e)
		{

		}
		if (this->RepeatradioButton2->Checked == true)
		{
			//��ȡ����·������������з�����Ϣ�����û�ѡ��
			String^selectsql = String::Format("SELECT DISTINCT ������� AS ������� FROM ������Ϣ WHERE ��·���='{0}';", this->RoadNametoolStripComboBox1->Text);
			DataTable^proposalsdt = GetTable(con, selectsql);
			//�ṩ����ѡ��
			this->ѡ�����еķ���ToolStripMenuItem->DropDownItems->Clear();//****************************//ȫ�ֱ�����Ҫ���

			for (int i = 0; i < proposalsdt->Rows->Count; i++)
			{
				DataRow^proposaldr = proposalsdt->Rows[i];
				System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
				toolstripmenuitem->Name = L"toolStripMenuTtem" + (i + 1).ToString();
				toolstripmenuitem->Size = System::Drawing::Size(152, 22);
				toolstripmenuitem->Text = proposaldr["�������"]->ToString();
				toolstripmenuitem->CheckOnClick = true;
				this->ѡ�����еķ���ToolStripMenuItem->DropDownItems->Add(toolstripmenuitem);
				toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &RealRoadForm::toolStripMenuItem_CheckedChanged);
			}
		}
		else if (this->MakeprojectradioButton1->Checked == true)
		{
			//��ȡ����·������������з�����Ϣ�����û�ѡ��
			String^selectsql = String::Format("SELECT DISTINCT ������� AS ������� FROM ������Ϣ WHERE ��·���='{0}';", this->RoadNametoolStripComboBox1->Text);
			DataTable^proposalsdt = GetTable(con, selectsql);
			//�ṩ����ѡ��
			this->ѡ�����еķ���ToolStripMenuItem->DropDownItems->Clear();//****************************//ȫ�ֱ�����Ҫ���

			for (int i = 0; i < proposalsdt->Rows->Count; i++)
			{
				DataRow^proposaldr = proposalsdt->Rows[i];
				System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
				toolstripmenuitem->Name = L"toolStripMenuTtem" + (i + 1).ToString();
				toolstripmenuitem->Size = System::Drawing::Size(152, 22);
				toolstripmenuitem->Text = proposaldr["�������"]->ToString();
				toolstripmenuitem->CheckOnClick = true;
				this->ѡ�����еķ���ToolStripMenuItem->DropDownItems->Add(toolstripmenuitem);
				toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &RealRoadForm::SetStartTime);
			}
			starttime_arr = gcnew List<DateTime>();
		}
		else if (this->CurrentradioButton1->Checked == true)
		{
			//��ȡ����·������������з�����Ϣ�����û�ѡ��
			String^selectsql = String::Format("SELECT DISTINCT ������� AS ������� FROM ������Ϣ WHERE ��·���='{0}';", this->RoadNametoolStripComboBox1->Text);
			DataTable^proposalsdt = GetTable(con, selectsql);
			//�ṩ����ѡ��
			this->ѡ�����еķ���ToolStripMenuItem->DropDownItems->Clear();//****************************//ȫ�ֱ�����Ҫ���
			for (int i = 0; i < proposalsdt->Rows->Count; i++)
			{
				DataRow^proposaldr = proposalsdt->Rows[i];
				System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
				toolstripmenuitem->Name = L"toolStripMenuTtem" + (i + 1).ToString();
				toolstripmenuitem->Size = System::Drawing::Size(152, 22);
				toolstripmenuitem->Text = proposaldr["�������"]->ToString();
				toolstripmenuitem->CheckOnClick = true;
				this->ѡ�����еķ���ToolStripMenuItem->DropDownItems->Add(toolstripmenuitem);
				toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &RealRoadForm::SysMode);
			}
		}
	}
	//���Ժ���
	private:System::Void Checked(RealRoad::Tram^tram1)
	{
		String^str1 = "1." + tram1->tram_strnum +
			"\n2.index:" + tram1->tram_num.ToString() +
			"\n3.datanum:" + tram1->datanum.ToString() +
			"\n4.pos:" + tram1->pos.ToString() +
			"\n5.velocity:" + tram1->velocity +
			"\n6.timeflow:" + tram1->timeflow +
			"\n7.maxpos:" + tram1->last_pos.ToString() +
			"\n8.settime:" + tram1->settime +
			"\n9.predraw:" + tram1->predraw.ToString() +
			"\n10.draw:" + tram1->draw.ToString() +
			"\n11.maxdatanum:" + tram1->maxdatanum.ToString();
		MessageBox::Show(str1);
	}
	//������������
	private: System::Void AdjustRunInterval(System::Object^  sender, System::EventArgs^  e) {
		//1/2/5/8/10
		if (this->AdjustRunIntervalcomboBox1->SelectedIndex == 0)
		{
			this->timer1->Interval = 1000;
		}
		else if (this->AdjustRunIntervalcomboBox1->SelectedIndex == 1)//2����
		{
			this->timer1->Interval = Math::Floor(1000 / 2);
		}
		else if (this->AdjustRunIntervalcomboBox1->SelectedIndex == 2)//5����
		{
			this->timer1->Interval = Math::Floor(1000 / 5);
		}
		else if (this->AdjustRunIntervalcomboBox1->SelectedIndex == 3)//8����
		{
			this->timer1->Interval = Math::Floor(1000 / 8);
		}
		else if (this->AdjustRunIntervalcomboBox1->SelectedIndex == 4)//10����
		{
			this->timer1->Interval = Math::Floor(1000 / 10);
		}
		else if (this->AdjustRunIntervalcomboBox1->SelectedIndex == 5)//����1.5����
		{
			this->timer1->Interval = Math::Floor(1000 *1.5);
		}
		else if (this->AdjustRunIntervalcomboBox1->SelectedIndex == 6)//����2����
		{
			this->timer1->Interval = Math::Floor(1000 *2);
		}
	}
};
}
