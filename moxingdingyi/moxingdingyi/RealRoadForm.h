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
	//新增
	using namespace System::Data::SqlClient;
	using namespace System::Threading;
	using namespace System::Collections::Generic;
	//新增命名空间
	using namespace RealRoad;
	using namespace System::Security::Permissions;
	[System::Runtime::InteropServices::ComVisibleAttribute(true)]

	/// <summary>
	/// RealRoadForm 摘要
	/// </summary>
	public ref class RealRoadForm : public System::Windows::Forms::Form
	{
	public:
		RealRoadForm(void)
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
	private: System::Windows::Forms::ToolStripMenuItem^  选择已有的方案ToolStripMenuItem;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::RadioButton^  MakeprojectradioButton1;


	private: System::Windows::Forms::WebBrowser^  webBrowser1;

	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->CityNametoolStripComboBox2 = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->RoadNametoolStripComboBox1 = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->选择已有的方案ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
					this->RoadNametoolStripComboBox1, this->选择已有的方案ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1292, 29);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// CityNametoolStripComboBox2
			// 
			this->CityNametoolStripComboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"珠海" });
			this->CityNametoolStripComboBox2->Name = L"CityNametoolStripComboBox2";
			this->CityNametoolStripComboBox2->Size = System::Drawing::Size(145, 25);
			this->CityNametoolStripComboBox2->Text = L"选择或输入城市名称";
			this->CityNametoolStripComboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &RealRoadForm::ChooseCityChanged);
			this->CityNametoolStripComboBox2->TextUpdate += gcnew System::EventHandler(this, &RealRoadForm::CityNametoolStripComboBox2_TextUpdate);
			// 
			// RoadNametoolStripComboBox1
			// 
			this->RoadNametoolStripComboBox1->Name = L"RoadNametoolStripComboBox1";
			this->RoadNametoolStripComboBox1->Size = System::Drawing::Size(145, 25);
			this->RoadNametoolStripComboBox1->Text = L"输入或选择已有线路";
			this->RoadNametoolStripComboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &RealRoadForm::ChooseRoadChanged);
			// 
			// 选择已有的方案ToolStripMenuItem
			// 
			this->选择已有的方案ToolStripMenuItem->Name = L"选择已有的方案ToolStripMenuItem";
			this->选择已有的方案ToolStripMenuItem->Size = System::Drawing::Size(104, 25);
			this->选择已有的方案ToolStripMenuItem->Text = L"选择已有的方案";
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
			this->groupBox1->Text = L"模式选择";
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
			this->RepeatradioButton2->Text = L"轨迹重现";
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
			this->MakeprojectradioButton1->Text = L"生成方案";
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
			this->CurrentradioButton1->Text = L"实时显示";
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
			this->groupBox2->Text = L"方案调整框";
			// 
			// AdjustRunIntervalcomboBox1
			// 
			this->AdjustRunIntervalcomboBox1->FormattingEnabled = true;
			this->AdjustRunIntervalcomboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"原速", L"加快2倍速", L"加快5倍速", L"加快8倍速",
					L"加快10倍速", L"减慢1.5倍速", L"减慢2倍速"
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
			this->label3->Text = L"调整运行速度";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(243, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 12);
			this->label2->TabIndex = 0;
			this->label2->Text = L"日期";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(185, 21);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 12);
			this->label4->TabIndex = 0;
			this->label4->Text = L"个方案";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"同时显示";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(978, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 45);
			this->button1->TabIndex = 4;
			this->button1->Text = L"开始运行";
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
			this->button2->Text = L"停止运行";
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
			this->Text = L"实际线路图";
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
	

			//查询函数
	private:DataTable^GetTable(SqlConnection^sqlcon, String^sqlstr)
	{
		sqlcon->Open();
		SqlDataAdapter^da = gcnew SqlDataAdapter(sqlstr, sqlcon);
		DataTable^result_dt = gcnew DataTable();
		da->Fill(result_dt);
		sqlcon->Close();
		return result_dt;
	}
	//加载
	/*
	初始化html脚本
	初始化数据库连接符
	将现存数据库线路名称选出并作为下拉选下卡选项
	*/
	private: System::Void RealRoadForm_Load(System::Object^  sender, System::EventArgs^  e) {

		//this->richTextBox1->AppendText("\t班次\t出发时间\t方向\n\n");

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
		//加载数据库中定义好的线路名称
		con->ConnectionString = "Data Source=localhost;Initial Catalog=列车数据库;Integrated Security=True";

		String^selectsql = "SELECT 线路编号 AS 线路编号,线路名称 AS 线路名称 FROM 线路信息;";
		DataTable^roadinfodt = GetTable(con, selectsql);

		for (int i = 0; i < roadinfodt->Rows->Count; i++)
		{
			DataRow^dr = roadinfodt->Rows[i];
			this->RoadNametoolStripComboBox1->Items->Add(dr["线路编号"]->ToString());
		}
	}
	//选择城市
	/*
	根据现有城市名称进行选择
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
	//输入城市名显示不同地图
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
	//选择线路
	private: System::Void ChooseRoadChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->RoadNametoolStripComboBox1->SelectedIndex >= 0)
		{
			//如果没选择城市使地图显示出来，线路不会加载成功
			if ((this->CityNametoolStripComboBox2->SelectedIndex < 0) || (String::IsNullOrEmpty(this->CityNametoolStripComboBox2->Text)))
				return;
			//获取线路名称
			op = gcnew Operate_System(this->RoadNametoolStripComboBox1->Text);
			op->InitPath(this->RoadNametoolStripComboBox1->Text);

			//初始化线路状况
			this->webBrowser1->Document->InvokeScript("ClearStationsorigin");
			op->InitSites();
			for (int i = 0; i < op->sites->Count; i++)
			{
				String^sitename = op->sites[i]->name->Trim();
				array<System::Object^>^sendstationname = gcnew array<System::Object^>(1);
				sendstationname[0] = sitename;
				this->webBrowser1->Document->InvokeScript("GetStationStatus", sendstationname);
			}
			//将线路名称传给html显示地图
			String^linename = op->roadname;
			array<System::Object^>^sendlinename = gcnew array<System::Object^>(1);
			sendlinename[0] = linename;
			this->webBrowser1->Document->InvokeScript("InitLine", sendlinename);
			//获取该线路编号下所有运行方案信息，供用户选择
			sqlstr = String::Format("SELECT DISTINCT 方案编号 AS 方案编号 FROM 方案信息 WHERE 线路编号='{0}';", op->roadstrnum);
			DataTable^proposalsdt = GetTable(con, sqlstr);
			//将方案编号作为下拉选项卡选项供用户选择
			if (this->RepeatradioButton2->Checked == true)
			{
				//提供方案选择
				this->选择已有的方案ToolStripMenuItem->DropDownItems->Clear();//****************************//全局变量需要清除

				for (int i = 0; i < proposalsdt->Rows->Count; i++)
				{
					DataRow^proposaldr = proposalsdt->Rows[i];
					System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
					toolstripmenuitem->Name = L"toolStripMenuTtem" + (i + 1).ToString();
					toolstripmenuitem->Size = System::Drawing::Size(152, 22);
					toolstripmenuitem->Text = proposaldr["方案编号"]->ToString();
					toolstripmenuitem->CheckOnClick = true;
					this->选择已有的方案ToolStripMenuItem->DropDownItems->Add(toolstripmenuitem);
					toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &RealRoadForm::toolStripMenuItem_CheckedChanged);
				}
			}
			else if (this->MakeprojectradioButton1->Checked == true)
			{
				//提供方案选择
				this->选择已有的方案ToolStripMenuItem->DropDownItems->Clear();//****************************//全局变量需要清除

				for (int i = 0; i < proposalsdt->Rows->Count; i++)
				{
					DataRow^proposaldr = proposalsdt->Rows[i];
					System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
					toolstripmenuitem->Name = L"toolStripMenuTtem" + (i + 1).ToString();
					toolstripmenuitem->Size = System::Drawing::Size(152, 22);
					toolstripmenuitem->Text = proposaldr["方案编号"]->ToString();
					toolstripmenuitem->CheckOnClick = true;
					this->选择已有的方案ToolStripMenuItem->DropDownItems->Add(toolstripmenuitem);
					toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &RealRoadForm::SetStartTime);
				}
				starttime_arr = gcnew List<DateTime>();
			}
			else if (this->CurrentradioButton1->Checked == true)
			{
				//提供方案选择
				this->选择已有的方案ToolStripMenuItem->DropDownItems->Clear();//****************************//全局变量需要清除
				for (int i = 0; i < proposalsdt->Rows->Count; i++)
				{
					DataRow^proposaldr = proposalsdt->Rows[i];
					System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
					toolstripmenuitem->Name = L"toolStripMenuTtem" + (i + 1).ToString();
					toolstripmenuitem->Size = System::Drawing::Size(152, 22);
					toolstripmenuitem->Text = proposaldr["方案编号"]->ToString();
					toolstripmenuitem->CheckOnClick = true;
					this->选择已有的方案ToolStripMenuItem->DropDownItems->Add(toolstripmenuitem);
					toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &RealRoadForm::SysMode);
				}
			}
		}
	}
	//选中线路后将该线路包含所有方案囊括到proposht中
			   /*
			   初始化：
			   不需重复初始化变量：线路编号、方案编号、列车编号、最大数据号、最大位置
			   需重复初始化变量：开始时间点、假设时间点、数据序号、当前位置、绘制与否标识、绘制预标识、行驶方向
			   变化变量：速度、加速度、车内人数等
			   */
	//选择不同的方案添加显示（重复模式下的绑定事件）
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
	//设置起始时间（定制方案模式下的绑定事件）
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
					op->InitTram(item->Text, ppform->maskedTextBox1->Text);//更新人工设置起始时间点
					DateTime temp_time = Convert::ToDateTime(ppform->maskedTextBox1->Text);//这里没用托管***********
					if (!(starttime_arr->Contains(temp_time)))
					{
						starttime_arr->Add(temp_time);
					}
				}
			}
			starttime_arr->Sort();//按递增顺序将虚拟时间起始点进行排序
		}
		else if (item->Checked == false)//如果把节点删除
		{
			op->RemoveTram(item->Text);
		}
	}
	//实时显示模式
	private:System::Void SysMode(System::Object^  sender, System::EventArgs^  e)
	{
		System::Windows::Forms::ToolStripMenuItem^item = safe_cast<System::Windows::Forms::ToolStripMenuItem^>(sender);
		if (item->Checked == true)
		{
			for each (System::Windows::Forms::ToolStripMenuItem^item1 in this->选择已有的方案ToolStripMenuItem->DropDownItems)
			{
				if (!String::Equals(item1->Text, sender->ToString()))
				{
					item1->Checked = false;//将其他所有不是当前选中方案去除
				}
			}

			//MessageBox::Show(sender->ToString());
			if (item->Checked == true)
			{
				op->InitTram(item->Text, "实时", "随便什么");//这里两个参数为了重载函数设置，有点多余
			}
			else if (item->Checked == false)//如果把节点删除
			{
				op->RemoveTram(item->Text, "实时");
			}
		}
	}
			//开始按钮
	private:array<int>^map_starttimetotrams;//映射矩阵，找到对应方案索引
	private:DateTime timemanager;//虚拟时钟线
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->MakeprojectradioButton1->Checked == true)
		{
			map_starttimetotrams = gcnew array<int>(starttime_arr->Count);
			timemanager = starttime_arr[0];//设置虚拟时钟线的起始点
			//this->richTextBox1->Clear();
			//this->richTextBox1->AppendText("班次\t出发时间\t方向\n\n");
			//按照时间组将各车次排序：时间顺序递增（建立映射）
			for (int i = 0; i < op->trams->Count; i++)
			{
				if (!String::IsNullOrEmpty(op->trams[i]->settime))
				{
					DateTime temp_time = Convert::ToDateTime(op->trams[i]->settime);
					int index_1 = starttime_arr->IndexOf(temp_time);//找出该虚拟时间起点对应的索引
					map_starttimetotrams[i] = index_1;
				}
			}
		}
		this->webBrowser1->Document->InvokeScript("RunStart");
	}
			 //停止按钮
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->timer1->Stop();
	}
			 //定时器开始
	public:void Run()
	{

		if (MessageBox::Show("加载完成！", "提示", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::Yes)
		{
			this->timer1->Start();
		}

	}

		   //定时器传输车辆信息到脚本显示
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		//模拟多车方案运行
		if (this->MakeprojectradioButton1->Checked == true)
		{
			for (int i = 0; i < op->trams->Count; i++)
			{
				System::TimeSpan tram_settime = Convert::ToDateTime(op->trams[i]->settime).TimeOfDay;//提取起始时间
				if (timemanager.TimeOfDay < tram_settime)//如果时间管理者没到电车的人工设置开始时间，继续判断下一电车
				{
					timemanager = timemanager.AddSeconds(+1);
					continue;
				}
				//时间管理者时间到达电车的人工设置时间
				op->Run_imm(op->trams[i], i);
				//Checked(op->trams[i]);
				if (op->trams[i]->draw)
				{
					array<System::Object^>^createcar = gcnew array<System::Object^>(9);
					createcar[8] = op->trams[i]->voltage;//电压
					createcar[7] = op->trams[i]->current;//电流
					createcar[6] = op->trams[i]->peopontram;//车内人数
					createcar[5] = op->trams[i]->accelerate;//加速度
					createcar[4] = op->trams[i]->velocity;//速度
					if (op->trams[i]->draw&&op->trams[i]->predraw)
					{
						createcar[3] = 0;//是否绘制
					}
					else
					{
						createcar[3] = 1;//是否绘制
						op->trams[i]->draw = false;
					}
					if (op->trams[i]->pos <= op->trams[i]->last_pos / 2)
					{
						//位置
						createcar[2] = ((op->trams[i]->pos) / (op->trams[i]->last_pos / 2)).ToString();
					}
					else
					{
						//位置
						createcar[2] = ((op->trams[i]->pos - (op->trams[i]->last_pos / 2)) / (op->trams[i]->last_pos / 2)).ToString();
					}
					//位置
					createcar[1] = op->trams[i]->direction;
					createcar[0] = op->trams[i]->tram_strnum->Trim();//车编号
					this->webBrowser1->Document->InvokeScript("CreateCar", createcar);
				}
			}
		}
		else if (this->RepeatradioButton2->Checked == true)//重复模式-即放即行模式
		{
			for (int i = 0; i < op->trams->Count; i++)
			{
				op->Run_imm(op->trams[i], i);
				if (op->trams[i]->draw)
				{
					array<System::Object^>^createcar = gcnew array<System::Object^>(9);
					createcar[8] = op->trams[i]->voltage;//电压
					createcar[7] = op->trams[i]->current;//电流
					createcar[6] = op->trams[i]->peopontram;//车内人数
					createcar[5] = op->trams[i]->accelerate;//加速度
					createcar[4] = op->trams[i]->velocity;//速度
					if (op->trams[i]->draw&&op->trams[i]->predraw)
					{
						createcar[3] = 0;//是否绘制
					}
					else
					{
						createcar[3] = 1;//是否绘制
						op->trams[i]->draw = false;
					}
					if (op->trams[i]->pos <= op->trams[i]->last_pos / 2)
					{
						//位置
						createcar[2] = ((op->trams[i]->pos) / (op->trams[i]->last_pos / 2)).ToString();
					}
					else
					{
						//位置
						createcar[2] = ((op->trams[i]->pos - (op->trams[i]->last_pos / 2)) / (op->trams[i]->last_pos / 2)).ToString();
					}
					//位置
					createcar[1] = op->trams[i]->direction;
					createcar[0] = op->trams[i]->tram_strnum->Trim();//车编号
					this->webBrowser1->Document->InvokeScript("CreateCar", createcar);
				}
			}
		}
		else if (this->CurrentradioButton1->Checked == true)//实时运行模式-同步
		{
			op->SysRun(op->trams[0]);
			if (op->trams[0]->draw)
			{
				array<System::Object^>^createcar = gcnew array<System::Object^>(9);
				createcar[8] = op->trams[0]->voltage;//电压
				createcar[7] = op->trams[0]->current;//电流
				createcar[6] = op->trams[0]->peopontram;//车内人数
				createcar[5] = op->trams[0]->accelerate;//加速度
				createcar[4] = op->trams[0]->velocity;//速度
				if (op->trams[0]->draw&&op->trams[0]->predraw)
				{
					createcar[3] = 0;//是否绘制
				}
				else
				{
					createcar[3] = 1;//是否绘制
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
				createcar[0] = op->trams[0]->tram_strnum->Trim();//车编号
				this->webBrowser1->Document->InvokeScript("CreateCar", createcar);
			}
		}

		//当切换运行模式时，需要清除所有图上车辆并停止计时器运行
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

			 //模式选择改变，为每个方案重新绑定不同模式下的事件
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
			//获取该线路编号下所有运行方案信息，供用户选择
			String^selectsql = String::Format("SELECT DISTINCT 方案编号 AS 方案编号 FROM 方案信息 WHERE 线路编号='{0}';", this->RoadNametoolStripComboBox1->Text);
			DataTable^proposalsdt = GetTable(con, selectsql);
			//提供方案选择
			this->选择已有的方案ToolStripMenuItem->DropDownItems->Clear();//****************************//全局变量需要清除

			for (int i = 0; i < proposalsdt->Rows->Count; i++)
			{
				DataRow^proposaldr = proposalsdt->Rows[i];
				System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
				toolstripmenuitem->Name = L"toolStripMenuTtem" + (i + 1).ToString();
				toolstripmenuitem->Size = System::Drawing::Size(152, 22);
				toolstripmenuitem->Text = proposaldr["方案编号"]->ToString();
				toolstripmenuitem->CheckOnClick = true;
				this->选择已有的方案ToolStripMenuItem->DropDownItems->Add(toolstripmenuitem);
				toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &RealRoadForm::toolStripMenuItem_CheckedChanged);
			}
		}
		else if (this->MakeprojectradioButton1->Checked == true)
		{
			//获取该线路编号下所有运行方案信息，供用户选择
			String^selectsql = String::Format("SELECT DISTINCT 方案编号 AS 方案编号 FROM 方案信息 WHERE 线路编号='{0}';", this->RoadNametoolStripComboBox1->Text);
			DataTable^proposalsdt = GetTable(con, selectsql);
			//提供方案选择
			this->选择已有的方案ToolStripMenuItem->DropDownItems->Clear();//****************************//全局变量需要清除

			for (int i = 0; i < proposalsdt->Rows->Count; i++)
			{
				DataRow^proposaldr = proposalsdt->Rows[i];
				System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
				toolstripmenuitem->Name = L"toolStripMenuTtem" + (i + 1).ToString();
				toolstripmenuitem->Size = System::Drawing::Size(152, 22);
				toolstripmenuitem->Text = proposaldr["方案编号"]->ToString();
				toolstripmenuitem->CheckOnClick = true;
				this->选择已有的方案ToolStripMenuItem->DropDownItems->Add(toolstripmenuitem);
				toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &RealRoadForm::SetStartTime);
			}
			starttime_arr = gcnew List<DateTime>();
		}
		else if (this->CurrentradioButton1->Checked == true)
		{
			//获取该线路编号下所有运行方案信息，供用户选择
			String^selectsql = String::Format("SELECT DISTINCT 方案编号 AS 方案编号 FROM 方案信息 WHERE 线路编号='{0}';", this->RoadNametoolStripComboBox1->Text);
			DataTable^proposalsdt = GetTable(con, selectsql);
			//提供方案选择
			this->选择已有的方案ToolStripMenuItem->DropDownItems->Clear();//****************************//全局变量需要清除
			for (int i = 0; i < proposalsdt->Rows->Count; i++)
			{
				DataRow^proposaldr = proposalsdt->Rows[i];
				System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
				toolstripmenuitem->Name = L"toolStripMenuTtem" + (i + 1).ToString();
				toolstripmenuitem->Size = System::Drawing::Size(152, 22);
				toolstripmenuitem->Text = proposaldr["方案编号"]->ToString();
				toolstripmenuitem->CheckOnClick = true;
				this->选择已有的方案ToolStripMenuItem->DropDownItems->Add(toolstripmenuitem);
				toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &RealRoadForm::SysMode);
			}
		}
	}
	//测试函数
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
	//调整运行速率
	private: System::Void AdjustRunInterval(System::Object^  sender, System::EventArgs^  e) {
		//1/2/5/8/10
		if (this->AdjustRunIntervalcomboBox1->SelectedIndex == 0)
		{
			this->timer1->Interval = 1000;
		}
		else if (this->AdjustRunIntervalcomboBox1->SelectedIndex == 1)//2倍速
		{
			this->timer1->Interval = Math::Floor(1000 / 2);
		}
		else if (this->AdjustRunIntervalcomboBox1->SelectedIndex == 2)//5倍速
		{
			this->timer1->Interval = Math::Floor(1000 / 5);
		}
		else if (this->AdjustRunIntervalcomboBox1->SelectedIndex == 3)//8倍速
		{
			this->timer1->Interval = Math::Floor(1000 / 8);
		}
		else if (this->AdjustRunIntervalcomboBox1->SelectedIndex == 4)//10倍速
		{
			this->timer1->Interval = Math::Floor(1000 / 10);
		}
		else if (this->AdjustRunIntervalcomboBox1->SelectedIndex == 5)//减慢1.5倍速
		{
			this->timer1->Interval = Math::Floor(1000 *1.5);
		}
		else if (this->AdjustRunIntervalcomboBox1->SelectedIndex == 6)//减慢2倍速
		{
			this->timer1->Interval = Math::Floor(1000 *2);
		}
	}
};
}
