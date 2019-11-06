#pragma once
#include"speedForm.h"
#include"trainVIForm.h"
#include"powerVIForm.h"
#include"arriveForm.h"
#include"stdlib.h"
#include"CalculateDataResult.h"
#define train  0x02
#define onground 0x03
#define speedup  0x11
#define speeddown 0x12
#define getdataon 0x13
#define getdataoff 0x14
#define poweron 0x15
#define poweroff 0x16
#define lighton  0x17
#define lightoff 0x18
#define monitor_one 2.23//监测点在轨道模型上的位置
#define monitor_two 2.89
#define monitor_three 0.485
namespace RunTest2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Net::Sockets;
	using namespace System::Net;
	using namespace System::Threading;

	/// <summary>
	/// Form1 摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:

	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::ListView^  listView2;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::ColumnHeader^  columnHeader5;
	private: System::Windows::Forms::ColumnHeader^  columnHeader6;
	private: System::Windows::Forms::ColumnHeader^  columnHeader7;
	private: System::Windows::Forms::ColumnHeader^  columnHeader8;
	private: System::Windows::Forms::ColumnHeader^  columnHeader9;
	private: System::Windows::Forms::ColumnHeader^  columnHeader10;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Data::DataSet^  dataSet1;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;


	private: System::Windows::Forms::ToolStripMenuItem^  速度监测ToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox1;
	private: System::Windows::Forms::TextBox^  receivenumtextBox;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  sendnumtextBox;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  porttextBox;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  trainnametextBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  runwaytextBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  stopnametextBox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  directiontextBox;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  waynametextBox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  modelnametextBox;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  waylengthtextBox;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  stopnumtextBox;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  stopbutton;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::ToolStripMenuItem^  电车电流电压监测ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  供电区间电流电压监测ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  实时站点监测ToolStripMenuItem;


	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->速度监测ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->电车电流电压监测ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->供电区间电流电压监测ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->实时站点监测ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->stopbutton = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->listView2 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader10 = (gcnew System::Windows::Forms::ColumnHeader());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->dataSet1 = (gcnew System::Data::DataSet());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->receivenumtextBox = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->sendnumtextBox = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->porttextBox = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->trainnametextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->runwaytextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->stopnametextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->directiontextBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->waynametextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->modelnametextBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->waylengthtextBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->stopnumtextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Enabled = false;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->速度监测ToolStripMenuItem,
					this->电车电流电压监测ToolStripMenuItem, this->供电区间电流电压监测ToolStripMenuItem, this->实时站点监测ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1587, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Form1::menuStrip1_ItemClicked);
			// 
			// 速度监测ToolStripMenuItem
			// 
			this->速度监测ToolStripMenuItem->Name = L"速度监测ToolStripMenuItem";
			this->速度监测ToolStripMenuItem->Size = System::Drawing::Size(83, 24);
			this->速度监测ToolStripMenuItem->Text = L"速度监测";
			this->速度监测ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::速度监测ToolStripMenuItem_Click);
			// 
			// 电车电流电压监测ToolStripMenuItem
			// 
			this->电车电流电压监测ToolStripMenuItem->Name = L"电车电流电压监测ToolStripMenuItem";
			this->电车电流电压监测ToolStripMenuItem->Size = System::Drawing::Size(149, 24);
			this->电车电流电压监测ToolStripMenuItem->Text = L"电车-电流电压监测";
			this->电车电流电压监测ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::电车电流电压监测ToolStripMenuItem_Click);
			// 
			// 供电区间电流电压监测ToolStripMenuItem
			// 
			this->供电区间电流电压监测ToolStripMenuItem->Name = L"供电区间电流电压监测ToolStripMenuItem";
			this->供电区间电流电压监测ToolStripMenuItem->Size = System::Drawing::Size(179, 24);
			this->供电区间电流电压监测ToolStripMenuItem->Text = L"供电区间-电流电压监测";
			this->供电区间电流电压监测ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::供电区间电流电压监测ToolStripMenuItem_Click);
			// 
			// 实时站点监测ToolStripMenuItem
			// 
			this->实时站点监测ToolStripMenuItem->Name = L"实时站点监测ToolStripMenuItem";
			this->实时站点监测ToolStripMenuItem->Size = System::Drawing::Size(113, 24);
			this->实时站点监测ToolStripMenuItem->Text = L"实时站点监测";
			this->实时站点监测ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::实时站点监测ToolStripMenuItem_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->tabControl1->Location = System::Drawing::Point(363, 50);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1208, 778);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->stopbutton);
			this->tabPage1->Controls->Add(this->label12);
			this->tabPage1->Controls->Add(this->label10);
			this->tabPage1->Controls->Add(this->label11);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->listView1);
			this->tabPage1->Location = System::Drawing::Point(4, 30);
			this->tabPage1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Size = System::Drawing::Size(1200, 744);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"传输指令";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// stopbutton
			// 
			this->stopbutton->Enabled = false;
			this->stopbutton->Location = System::Drawing::Point(195, 668);
			this->stopbutton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->stopbutton->Name = L"stopbutton";
			this->stopbutton->Size = System::Drawing::Size(124, 41);
			this->stopbutton->TabIndex = 3;
			this->stopbutton->Text = L"停止";
			this->stopbutton->UseVisualStyleBackColor = true;
			this->stopbutton->Click += gcnew System::EventHandler(this, &Form1::stopbutton_Click);
			// 
			// label12
			// 
			this->label12->BackColor = System::Drawing::Color::WhiteSmoke;
			this->label12->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label12->Location = System::Drawing::Point(1111, 668);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(49, 20);
			this->label12->TabIndex = 2;
			// 
			// label10
			// 
			this->label10->BackColor = System::Drawing::Color::WhiteSmoke;
			this->label10->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label10->Location = System::Drawing::Point(1111, 700);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(49, 20);
			this->label10->TabIndex = 2;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(985, 668);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(109, 20);
			this->label11->TabIndex = 2;
			this->label11->Text = L"连接指示灯";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(985, 700);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(109, 20);
			this->label9->TabIndex = 2;
			this->label9->Text = L"传输指示灯";
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(32, 668);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(141, 41);
			this->button1->TabIndex = 1;
			this->button1->Text = L"启动";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// listView1
			// 
			this->listView1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->columnHeader2, this->columnHeader3,
					this->columnHeader4, this->columnHeader5, this->columnHeader6
			});
			this->listView1->GridLines = true;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(8, 19);
			this->listView1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(1180, 628);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"设备";
			this->columnHeader2->Width = 109;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"指令类型";
			this->columnHeader3->Width = 84;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"发送时间";
			this->columnHeader4->Width = 200;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"指令内容";
			this->columnHeader5->Width = 345;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"操作";
			this->columnHeader6->Width = 173;
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::White;
			this->tabPage2->Controls->Add(this->listView2);
			this->tabPage2->Location = System::Drawing::Point(4, 30);
			this->tabPage2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Size = System::Drawing::Size(1200, 744);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"接收指令";
			// 
			// listView2
			// 
			this->listView2->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->listView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->columnHeader7, this->columnHeader8,
					this->columnHeader9, this->columnHeader10
			});
			this->listView2->GridLines = true;
			this->listView2->HideSelection = false;
			this->listView2->Location = System::Drawing::Point(8, 22);
			this->listView2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->listView2->Name = L"listView2";
			this->listView2->Size = System::Drawing::Size(1180, 662);
			this->listView2->TabIndex = 0;
			this->listView2->UseCompatibleStateImageBehavior = false;
			this->listView2->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"设备";
			this->columnHeader7->Width = 122;
			// 
			// columnHeader8
			// 
			this->columnHeader8->Text = L"指令类型";
			this->columnHeader8->Width = 80;
			// 
			// columnHeader9
			// 
			this->columnHeader9->Text = L"接收时间";
			this->columnHeader9->Width = 181;
			// 
			// columnHeader10
			// 
			this->columnHeader10->Text = L"指令内容";
			this->columnHeader10->Width = 323;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// dataSet1
			// 
			this->dataSet1->DataSetName = L"NewDataSet";
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 845);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Padding = System::Windows::Forms::Padding(1, 0, 19, 0);
			this->statusStrip1->Size = System::Drawing::Size(1587, 26);
			this->statusStrip1->TabIndex = 4;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(167, 20);
			this->toolStripStatusLabel1->Text = L"toolStripStatusLabel1";
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &Form1::timer2_Tick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->maskedTextBox1);
			this->groupBox1->Controls->Add(this->receivenumtextBox);
			this->groupBox1->Controls->Add(this->label16);
			this->groupBox1->Controls->Add(this->sendnumtextBox);
			this->groupBox1->Controls->Add(this->label15);
			this->groupBox1->Controls->Add(this->porttextBox);
			this->groupBox1->Controls->Add(this->label14);
			this->groupBox1->Controls->Add(this->label13);
			this->groupBox1->Location = System::Drawing::Point(35, 565);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(311, 258);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"连接设置";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(164, 209);
			this->button3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 29);
			this->button3->TabIndex = 3;
			this->button3->Text = L"断开";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(35, 209);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 29);
			this->button2->TabIndex = 3;
			this->button2->Text = L"连接";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Location = System::Drawing::Point(119, 38);
			this->maskedTextBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->maskedTextBox1->Mask = L"999.999.999.999";
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->PromptChar = ' ';
			this->maskedTextBox1->Size = System::Drawing::Size(173, 25);
			this->maskedTextBox1->TabIndex = 2;
			this->maskedTextBox1->Text = L"1921684  1";
			// 
			// receivenumtextBox
			// 
			this->receivenumtextBox->Location = System::Drawing::Point(119, 140);
			this->receivenumtextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->receivenumtextBox->Name = L"receivenumtextBox";
			this->receivenumtextBox->Size = System::Drawing::Size(92, 25);
			this->receivenumtextBox->TabIndex = 1;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(24, 150);
			this->label16->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(82, 15);
			this->label16->TabIndex = 0;
			this->label16->Text = L"接收帧数：";
			// 
			// sendnumtextBox
			// 
			this->sendnumtextBox->Location = System::Drawing::Point(119, 105);
			this->sendnumtextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->sendnumtextBox->Name = L"sendnumtextBox";
			this->sendnumtextBox->Size = System::Drawing::Size(92, 25);
			this->sendnumtextBox->TabIndex = 1;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(24, 116);
			this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(82, 15);
			this->label15->TabIndex = 0;
			this->label15->Text = L"发送帧数：";
			// 
			// porttextBox
			// 
			this->porttextBox->Location = System::Drawing::Point(119, 71);
			this->porttextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->porttextBox->Name = L"porttextBox";
			this->porttextBox->Size = System::Drawing::Size(173, 25);
			this->porttextBox->TabIndex = 1;
			this->porttextBox->Text = L"9000";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(24, 82);
			this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(82, 15);
			this->label14->TabIndex = 0;
			this->label14->Text = L"端口设置：";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(40, 49);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(68, 15);
			this->label13->TabIndex = 0;
			this->label13->Text = L"IP地址：";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(12, 141);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"列车编号：";
			// 
			// trainnametextBox
			// 
			this->trainnametextBox->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->trainnametextBox->Location = System::Drawing::Point(129, 129);
			this->trainnametextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->trainnametextBox->Name = L"trainnametextBox";
			this->trainnametextBox->Size = System::Drawing::Size(167, 30);
			this->trainnametextBox->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(12, 206);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"运行方式：";
			// 
			// runwaytextBox
			// 
			this->runwaytextBox->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->runwaytextBox->Location = System::Drawing::Point(129, 194);
			this->runwaytextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->runwaytextBox->Name = L"runwaytextBox";
			this->runwaytextBox->Size = System::Drawing::Size(167, 30);
			this->runwaytextBox->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(12, 264);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(109, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"起始站名：";
			// 
			// stopnametextBox
			// 
			this->stopnametextBox->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->stopnametextBox->Location = System::Drawing::Point(129, 251);
			this->stopnametextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->stopnametextBox->Name = L"stopnametextBox";
			this->stopnametextBox->Size = System::Drawing::Size(167, 30);
			this->stopnametextBox->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(12, 328);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(109, 20);
			this->label4->TabIndex = 2;
			this->label4->Text = L"行驶方向：";
			// 
			// directiontextBox
			// 
			this->directiontextBox->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->directiontextBox->Location = System::Drawing::Point(129, 315);
			this->directiontextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->directiontextBox->Name = L"directiontextBox";
			this->directiontextBox->Size = System::Drawing::Size(167, 30);
			this->directiontextBox->TabIndex = 3;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label5->Location = System::Drawing::Point(12, 86);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(109, 20);
			this->label5->TabIndex = 2;
			this->label5->Text = L"线路编号：";
			// 
			// waynametextBox
			// 
			this->waynametextBox->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->waynametextBox->Location = System::Drawing::Point(129, 74);
			this->waynametextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->waynametextBox->Name = L"waynametextBox";
			this->waynametextBox->Size = System::Drawing::Size(167, 30);
			this->waynametextBox->TabIndex = 3;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label6->Location = System::Drawing::Point(12, 32);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(109, 20);
			this->label6->TabIndex = 2;
			this->label6->Text = L"方案编号：";
			// 
			// modelnametextBox
			// 
			this->modelnametextBox->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->modelnametextBox->Location = System::Drawing::Point(129, 20);
			this->modelnametextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->modelnametextBox->Name = L"modelnametextBox";
			this->modelnametextBox->Size = System::Drawing::Size(167, 30);
			this->modelnametextBox->TabIndex = 3;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label7->Location = System::Drawing::Point(12, 385);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(109, 20);
			this->label7->TabIndex = 2;
			this->label7->Text = L"线路全长：";
			// 
			// waylengthtextBox
			// 
			this->waylengthtextBox->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->waylengthtextBox->Location = System::Drawing::Point(129, 372);
			this->waylengthtextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->waylengthtextBox->Name = L"waylengthtextBox";
			this->waylengthtextBox->Size = System::Drawing::Size(167, 30);
			this->waylengthtextBox->TabIndex = 3;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label8->Location = System::Drawing::Point(12, 450);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(109, 20);
			this->label8->TabIndex = 2;
			this->label8->Text = L"站点总数：";
			// 
			// stopnumtextBox
			// 
			this->stopnumtextBox->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->stopnumtextBox->Location = System::Drawing::Point(129, 438);
			this->stopnumtextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->stopnumtextBox->Name = L"stopnumtextBox";
			this->stopnumtextBox->Size = System::Drawing::Size(167, 30);
			this->stopnumtextBox->TabIndex = 3;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->stopnumtextBox);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->waylengthtextBox);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->modelnametextBox);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->waynametextBox);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->directiontextBox);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->stopnametextBox);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->runwaytextBox);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->trainnametextBox);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Location = System::Drawing::Point(35, 50);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Size = System::Drawing::Size(311, 492);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			// 
			// timer3
			// 
			this->timer3->Interval = 1000;
			this->timer3->Tick += gcnew System::EventHandler(this, &Form1::timer3_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1587, 871);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:Socket ^newclient;//创建上位机客户端
	public:bool connected;//连接状态
	public:Thread^myThread;//创建线程用于接收数据
	public:delegate void MyInvoke(String^str1,String^str2);

	public:SqlConnection^Conn = gcnew SqlConnection();//创建数据库连接
	public:SqlDataAdapter^Adapter = gcnew SqlDataAdapter();//数据库适配器

	public:array<int>^ s ;//站点距离数组
	public:array<int>^ ua ;//各段加速度
	public:array<int>^ v;//各段行驶速度
	public:array<int>^ da;//各段制动速度
	public:array<int>^staytime;//停靠或等待时间,包括红绿灯等待时间
	public:array<int>^stopstaytime;//到站停靠时间
	public:array<String^>^stopname;//站点名称
	public:int stop_num;//站点个数
	public:array<int>^geton_num;//上车人数
	public:array<int>^getoff_num;//下车人数

	public:array<int>^power_s ;//供电区间位置
	public:array<String^>^power_name;//供电区间编号
	public:int power_l;//供电区间长度

	public:array<int>^light_s ;//红绿灯位置
	public:array<int>^greenlight_t;//绿灯时间
	public:array<int>^redlight_t;//红灯时间

	public:int getdata_f=1;//采样频率,暂定为一秒一条数据
		  
	public:String^modelname="F0012";//方案编号
	public:String^wayname;//线路编号
	public:String^trainname;//列车编号
	public:int zaikeliang;//载客容量
	public:int waylength;//线路总长
	public:double ratio=136.61;//500m与模型周长之比

	/////////////////获取参数//////////////////

	public:void get_data(void)
	{
		Conn->ConnectionString = "server=localhost;Initial Catalog=列车数据库;Integrated Security=True;";
		Conn->Open();
		String^strcmd1 = String::Format("SELECT 列车编号 FROM 方案信息 WHERE 方案编号 = '{0}'", modelname);
		String^strcmd2 = String::Format("SELECT 线路编号 FROM 方案信息 WHERE 方案编号 = '{0}'", modelname);
		Data::SqlClient::SqlCommand ^ cmd1 = gcnew Data::SqlClient::SqlCommand(strcmd1, Conn);
		Data::SqlClient::SqlCommand ^ cmd2 = gcnew Data::SqlClient::SqlCommand(strcmd2, Conn);
		trainname = cmd1->ExecuteScalar()->ToString();
		wayname = cmd2->ExecuteScalar()->ToString();

		int length=0;//数组长度

		String^strcmd3 = String::Format("SELECT * FROM 站点信息 WHERE 线路编号 = '{0}'", wayname);
		Data::SqlClient::SqlCommand ^ cmd3 = gcnew Data::SqlClient::SqlCommand(strcmd3, Conn);
		Adapter->SelectCommand = cmd3;
		Adapter->Fill(dataSet1, "sTable");
		length = dataSet1->Tables["sTable"]->Rows->Count;
		s = gcnew array<int>(length - 1);
		for (int i = 0; i < length - 1; i++)
		{
			DataRow ^row1 = dataSet1->Tables["sTable"]->Rows[i + 1];
			s[i] = Int32::Parse(row1["站间距离"]->ToString());
		}
		stopname = gcnew array<String^>(length);
		geton_num = gcnew array<int>(length);
		getoff_num = gcnew array<int>(length);
		for (int i = 0; i < length; i++)
		{
			DataRow^row2 = dataSet1->Tables["sTable"]->Rows[i];
			stopname[i] = row2["站点名称"]->ToString()->TrimEnd();
			geton_num[i] = Int16::Parse(row2["上车人数"]->ToString());
			getoff_num[i] = Int16::Parse(row2["下车人数"]->ToString());
		}
		

		String^strcmd4 = String::Format("SELECT * FROM 列车站间运行信息 WHERE 列车编号 = '{0}' AND 线路编号 = '{1}'", trainname, wayname);
		Data::SqlClient::SqlCommand ^ cmd4 = gcnew Data::SqlClient::SqlCommand(strcmd4, Conn);
		Adapter->SelectCommand = cmd4;
		Adapter->Fill(dataSet1, "trainTable");
		length = dataSet1->Tables["trainTable"]->Rows->Count;
		v = gcnew array<int>(length - 1);
		ua = gcnew array<int>(length - 1);
		da = gcnew array<int>(length - 1);
		staytime = gcnew array<int>(length - 1);
		for (int i = 0; i < length -1; i++)
		{
			DataRow^row3 = dataSet1->Tables["trainTable"]->Rows[i+1];
			v[i] = Int32::Parse(row3["站间列车速度"]->ToString())/3.6;//将千米每秒转换为米每秒
			ua[i] = Int32::Parse(row3["站间列车加速加速度"]->ToString());
			da[i] = Int32::Parse(row3["站间列车减速加速度"]->ToString());
			staytime[i] = Int32::Parse(row3["站点停留时间"]->ToString());
		}

		String^strcmd5 = String::Format("SELECT * FROM 供电区间信息 WHERE 线路编号 = '{0}'", wayname);
		Data::SqlClient::SqlCommand ^ cmd5 = gcnew Data::SqlClient::SqlCommand(strcmd5, Conn);
		Adapter->SelectCommand = cmd5;
		Adapter->Fill(dataSet1, "powerTable");
		length = dataSet1->Tables["powerTable"]->Rows->Count;
		power_s = gcnew array<int>(length + 1);
		power_name = gcnew array<String^>(length + 1);
		power_s[0] = 0;
		power_name[0] = "Q000";
		int powers_sum = 0;
		for (int i = 0; i < length; i++)
		{
			DataRow^row4 = dataSet1->Tables["powerTable"]->Rows[i];
			power_l = Int32::Parse(row4["区间长度"]->ToString());
			powers_sum += power_l + Int32::Parse(row4["相邻区间距离"]->ToString());
			power_s[i + 1] = powers_sum;
			power_name[i + 1] = row4["区间编号"]->ToString()->Trim();
		}

		String^strcmd6 = String::Format("SELECT * FROM 红绿灯信息 WHERE 线路编号 = '{0}'", wayname);
		Data::SqlClient::SqlCommand ^ cmd6 = gcnew Data::SqlClient::SqlCommand(strcmd6, Conn);
		Adapter->SelectCommand = cmd6;
		Adapter->Fill(dataSet1, "lightTable");
		length = dataSet1->Tables["lightTable"]->Rows->Count;
		light_s = gcnew array<int>(length);
		greenlight_t = gcnew array<int>(length);
		redlight_t = gcnew array<int>(length);
		int lights_sum = 0;
		for (int i = 0; i < length; i++)
		{
			DataRow^row5 = dataSet1->Tables["lightTable"]->Rows[i];
			lights_sum += Int32::Parse(row5["相邻红绿灯距离"]->ToString());
			greenlight_t[i] = Int32::Parse(row5["绿灯时间"]->ToString());
			redlight_t[i] = Int32::Parse(row5["红灯时间"]->ToString());
			light_s[i] = lights_sum;
		}

		String^strcmd7 = String::Format("SELECT 站点数量 FROM 线路信息 WHERE 线路编号 = '{0}'", wayname);
		Data::SqlClient::SqlCommand ^ cmd7 = gcnew Data::SqlClient::SqlCommand(strcmd7, Conn);
		stop_num = Int32::Parse(cmd7->ExecuteScalar()->ToString());

		String^strcmd8 = String::Format("SELECT 行驶方向 FROM 列车信息 WHERE 线路编号 = '{0}' and 列车编号 = '{1}'", wayname,trainname);
		Data::SqlClient::SqlCommand ^ cmd8 = gcnew Data::SqlClient::SqlCommand(strcmd8, Conn);
		String^ xsfx = cmd8->ExecuteScalar()->ToString()->Trim();//行驶方向，末站
		String^strcmd9 = String::Format("SELECT 载客容量 FROM 列车信息 WHERE 线路编号 = '{0}' and 列车编号 = '{1}'", wayname, trainname);
		Data::SqlClient::SqlCommand ^ cmd9 = gcnew Data::SqlClient::SqlCommand(strcmd9, Conn);
		zaikeliang = Int32::Parse(cmd9->ExecuteScalar()->ToString()->Trim());

		Conn->Close();

		for (int i = 0; i < s->Length; i++)
			waylength += s[i];

		if (xsfx == "反向")//表示从线路末站开始运行,需对获取的数组进行反序处理
		{
			Array::Reverse(stopname);
			Array::Reverse(s);
			Array::Reverse(v);
			Array::Reverse(ua);
			Array::Reverse(da);

			for (int i = 0; i < light_s->Length; i++)
			{
				light_s[i] = waylength - light_s[i];
			}
			Array::Reverse(light_s);
			Array::Reverse(greenlight_t);
			Array::Reverse(redlight_t);

			for (int i = 0; i < power_s->Length; i++)
			{
				power_s[i] = waylength - power_s[i]-100;
			}
			Array::Reverse(power_s);

			Array::Reverse(staytime);
			Array::Reverse(geton_num);
			Array::Reverse(getoff_num);
		}

		//数组变化处理
		s = turnstraight(s, 1);
		v = turnstraight(v, 1);
		ua = turnstraight(ua, 1);
		da = turnstraight(da, 1);

		light_s = turnstraight(light_s, 2);
		greenlight_t = turnstraight(greenlight_t, 1);
		redlight_t = turnstraight(redlight_t, 1);

		power_s = turnstraight(power_s, 3);
		power_name = turnpowername(power_name);
		staytime = turnstraight(staytime, 4);
		stopname = turnstopname(stopname);
		geton_num = turnstraight(geton_num, 4);
		getoff_num = turnstraight(getoff_num, 4);
		stopstaytime = staytime;

		//求最终waylength,由于双向运行，故长度变为原来2倍。
		waylength = 0;
		for (int i = 0; i < s->Length; i++)
			waylength += s[i];
	}

	public:array<int>^ turnstraight(array<int>^ arr, int num)//将双向运行转化为单向直线运行参数
	{
		array<int>^ newarr;
		switch (num)
		{
		case 1://第一种情况为以站间距离为代表，变换后数组长度为原来的2倍
			newarr = gcnew array<int>(2 * arr->Length);
			for (int i = 0; i < newarr->Length; i++)
			{
				if (i>arr->Length - 1)
					newarr[i] = arr[newarr->Length - 1 - i];
				else
					newarr[i] = arr[i];
			}
			break;
		case 2://第二种情况求变化后的红绿灯位置
			newarr = gcnew array<int>(2 * arr->Length);
			for (int i = 0; i < newarr->Length; i++)
			{
				if (i>arr->Length - 1)
					newarr[i] = 2 * waylength - light_s[2 * arr->Length - 1 - i];
				else
					newarr[i] = arr[i];
			}
			break;
		case 3://第三种情况求变化后的供电区间位置
			newarr = gcnew array<int>(2 * arr->Length);
			for (int i = 0; i < newarr->Length; i++)
			{
				if (i>arr->Length - 1)
					newarr[i] = 2 * waylength - power_s[2 * arr->Length - 1 - i] - power_l;
				else
					newarr[i] = arr[i];
			}
			break;
		case 4://第四种情况以停留时间和上下车人数为代表，变化后数组长度比原来的2倍少一。
			newarr = gcnew array<int>(2 * arr->Length - 1);
			for (int i = 0; i < newarr->Length; i++)
			{
				if (i>arr->Length - 1)
					newarr[i] = arr[newarr->Length - 1 - i];
				else
					newarr[i] = arr[i];
			}
			break;
		}
		return newarr;
	}
	public:array<String^>^ turnstopname(array<String^>^ arr)
	{
		array<String^>^ newarr = gcnew array<String^>(2 * arr->Length - 1);
		for (int i = 0; i < newarr->Length; i++)
		{
			if (i>arr->Length - 1)
				newarr[i] = arr[newarr->Length - 1 - i];
			else
				newarr[i] = arr[i];
		}
		return newarr;
	}
	public:array<String^>^ turnpowername(array<String^>^ arr)
	{
		array<String^>^ newarr = gcnew array<String^>(2 * arr->Length);
		for (int i = 0; i < newarr->Length; i++)
		{
			if (i>arr->Length - 1)
				newarr[i] = power_name[2 * arr->Length - 1 - i] ;
			else
				newarr[i] = arr[i];
		}
		return newarr;
	}
	

	//构造相应指令

	public:array<Byte>^  getCRC(array<Byte>^ orderbyte)//CRC校验位生成函数
	{
		int i, j;//循环变量
		unsigned short usRegCRC = 0xFFFF;//用于保存CRC的值

		for (i = 0; i < orderbyte->Length; i++)//循环处理数据帧
		{
			usRegCRC ^= orderbyte[i];//异或算法得CRC值
			for (j = 0; j < 8; j++)//循环处理每个bit位
			{
				if (usRegCRC & 0x0001)
					usRegCRC = usRegCRC >> 1 ^ 0xA001;
				else
					usRegCRC >>= 1;
			}
		}
		Byte byteL = usRegCRC & 0xff;
		Byte byteH = (usRegCRC & 0xff00) >> 8;
		array<Byte>^ orderdata = gcnew array < Byte >(orderbyte->Length + 2);//给数据帧添加CRC校验
		for (int i; i < orderdata->Length; i++)
		{
			if (i<orderdata->Length - 2)
				orderdata[i] = orderbyte[i];
			else
			{
				orderdata[i] = byteH;
				orderdata[i + 1] = byteL;
				break;
			}
		}
		return orderdata;
	}
	public:String^ create_order(String^str,int index)
	{
		array<Byte>^databyte = gcnew array<Byte>(100);
		array<Byte>^orderbyte;//指令
		array<int>^inta = gcnew array<int>(2);//int[0]代表整数，int[1]代表小数
		double a;//将参数转换为double类型
		String^datastr;

		if (str =="加速"||str=="减速"||str=="开始采样"||str=="结束采样"||str=="反向加速")
		{
			databyte[0] = 0x01;
			databyte[1] = 0x02;
			if (str == "加速")
			{
				databyte[2] = 10&0xff;//帧长度
				databyte[3] = speedup;
				databyte[4] = 0x00;//正转
				a = Double::Parse((ua[index] / ratio).ToString("f1"));
				inta = doubleturnint(a);
				//databyte[5] = inta[0]&0xff;
				//databyte[6] = inta[1] & 0xff;//小数位
				databyte[5] = 0x02;
				databyte[6] = 0x00;//小数位调试用加速度
				databyte[7] = 0x22;
				a = Double::Parse((v[index] / ratio).ToString("f1"));
				inta = doubleturnint(a);
				databyte[8] = 0x90;//调试用速度
				//databyte[8] = inta[0] & 0xff;
				databyte[9] = inta[1] & 0xff;//小数位

				orderbyte = gcnew array<Byte>(10);
				for (int i = 0; i < 10; i++)
				{
					orderbyte[i] = databyte[i];
				}

			}
			else if (str == "反向加速")
			{
				databyte[2] = 10 & 0xff;//帧长度
				databyte[3] = speedup;
				databyte[4] = 0x01;//反转
				a = Double::Parse((ua[index] / ratio).ToString("f1"));
				inta = doubleturnint(a);
				databyte[5] = inta[0] & 0xff;
				databyte[6] = inta[1] &0xff;//小数位
				databyte[7] = 0x22;
				a = Double::Parse((v[index] / ratio).ToString("f1"));
				inta = doubleturnint(a);
				databyte[8] = inta[0] & 0xff;
				databyte[9] = inta[1] & 0xff;//小数位

				orderbyte = gcnew array<Byte>(10);
				for (int i = 0; i < 10; i++)
				{
					orderbyte[i] = databyte[i];
				}
			}
			else if (str == "减速")
			{
				databyte[2] = 10 & 0xff;//帧长度
				databyte[3] = speeddown;
				a = Double::Parse((da[index] / ratio).ToString("f1"));
				inta = doubleturnint(a);
				databyte[4] = inta[0] & 0xff;
				databyte[5] = inta[1] & 0xff;//小数位
				databyte[6] = 0x22;
				a = Double::Parse((v[index] / ratio).ToString("f1"));
				inta = doubleturnint(a);
				databyte[7] = inta[0] & 0xff;
				databyte[8] = inta[1] & 0xff;//小数位

				orderbyte = gcnew array<Byte>(9);
				for (int i = 0; i < 9; i++)
				{
					orderbyte[i] = databyte[i];
				}
			}
			else if (str == "开始采样")
			{
				databyte[2] = 10&0xff;
				databyte[3] = getdataon;
				databyte[4] = getdata_f & 0xff;
				databyte[5] = 0x00;
				orderbyte = gcnew array<Byte>(6);
				for (int i = 0; i < 6; i++)
				{
					orderbyte[i] = databyte[i];
				}
			}
			else
			{
				databyte[2] = 10&0xff;
				databyte[3] = getdataoff;
				orderbyte = gcnew array<Byte>(4);
				for (int i = 0; i < 4; i++)
				{
					orderbyte[i] = databyte[i];
				}
			}
		}
		if (str == "开供电区间" || str == "关供电区间" || str == "开红绿灯" || str == "关红绿灯")
		{
			databyte[0] = 0x01;
			databyte[1] = 0x03;
			if (str == "开供电区间")
			{
				databyte[2] =10&0xff;
				databyte[3] = poweron;
				databyte[4] = index & 0xff;
				orderbyte = gcnew array<Byte>(5);
				for (int i = 0; i < 5; i++)
				{
					orderbyte[i] = databyte[i];
				}
			}
			else if (str == "关供电区间")
			{
				databyte[2] = 10 & 0xff;
				databyte[3] = poweroff;
				databyte[4] = index & 0xff;

				orderbyte = gcnew array<Byte>(5);
				for (int i = 0; i < 5; i++)
				{
					orderbyte[i] = databyte[i];
				}
			}
			else if (str == "开红绿灯")
			{
				databyte[2] = 10&0xff;
				databyte[3] = lighton;
				databyte[4] = 0x00;//默认起始为绿灯
				databyte[5] = 0x19;
				databyte[6] = greenlight_t[0]& 0xff;
				orderbyte = gcnew array<Byte>(7);
				for (int i = 0; i < 7; i++)
				{
					orderbyte[i] = databyte[i];
				}
			}
			else
			{
				databyte[2] =10&0xff;
				databyte[3] = lightoff;
				orderbyte = gcnew array<Byte>(4);
				for (int i = 0; i < 4; i++)
				{
					orderbyte[i] = databyte[i];
				}
			}
		}
		//将数据帧变为10字节
		array<Byte>^orderdata = gcnew array<Byte>(10);
		for (int i = 0; i < orderdata->Length; i++)
		{
			if (i<orderbyte->Length)
				orderdata[i] = orderbyte[i];
			else
				orderdata[i] = 0x00;
		}
		datastr = BitConverter::ToString(orderdata);
		//datastr = BitConverter::ToString(getCRC(orderbyte));
		return datastr;
	}
	public:array<int>^ doubleturnint(double a)//将double的整数和小数部分分离
	{
		array<int>^ inta = gcnew array<int>(2);
		inta[0] = (int)a;
		inta[1] = (a - inta[0]) * 10;
		return inta;
	}
	//
	//存储指令表
	//

	public:void store_data(array<String^>^s)
	{
		Conn->ConnectionString = "server=localhost;Initial Catalog=RunDB2;Integrated Security=True;";
		String^strcmd = String::Format("INSERT INTO controltable (方案编号,设备编号,设备名称,指令类型,发送时间,指令内容,操作) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}','{6}')", s[0], s[1], s[2], s[3], s[4],s[5],s[6]);
		Data::SqlClient::SqlCommand ^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd,Conn);
		Conn->Open();
		cmd->ExecuteNonQuery();
		Conn->Close();
	}

	//
	//根据红绿灯位置及状态获得列车运行距离数组
	//

	public:array<int>^ insert(array<int>^arr, int s_index, int a, int num,int index)//将红绿灯的各项数据插入到原来的参数数组中
	{
		array<int>^b = gcnew array<int>(arr->Length + 1);
		if (num == 0)
		{
			for (int i = 0; i < b->Length; i++)
			{
				if (i == s_index)
				{
					b[i] = light_s[index] - a;
					b[i + 1] = a + arr[s_index] - light_s[index];
					i++;
				}
				else if (i>s_index + 1)
					b[i] = arr[i - 1];
				else
					b[i] = arr[i];
			}
			return b;
		}
		else if (num == 1)
		{

			for (int i = 0; i < b->Length; i++)
			{
				if (i == s_index)
					b[i] = arr[i];
				else if (i>s_index)
					b[i] = arr[i - 1];
				else
					b[i] = arr[i];
			}
			return b;
		}
		else
		{
			for (int i = 0; i < b->Length; i++)
			{
				if (i == s_index)
					b[i] = a;
				else if (i>s_index)
					b[i] = arr[i - 1];
				else
					b[i] = arr[i];
			}
			return b;
		}
	}

	public:void get_light_s(void)//判断红绿灯是否影响列车运行，若是将其作为一个站点加入站间距离数组中
	{
		for (int i = 0; i < light_s->Length; i++)
		{
			int stop_s = 50;//50为制动距离
			int judge_s = light_s[i] - 50;//红绿灯前判断点距离出发点位置
			int s_sum=0;//站间距离累加
			int s_index=0;//站间距离索引
			for (int i = 0; i < s->Length; i++)//判断红绿灯在哪个站点区间内
			{
				if (judge_s>s_sum&&judge_s < s_sum + s[i])
				{
					s_index = i;
					break;
				}
				else
					s_sum += s[i];
			}
			int t_sum;//运行时间的确定
			if (s_index >= 1)
			{
				for (int i = 0; i < s_index; i++)
				{
					int uspeed_t = v[i] / ua[i];//加速段用时
					int dspeed_t = v[i] / da[i];//减速段用时
					int kspeed_t = (s[i] - 0.5*v[i] * uspeed_t - 0.5*v[i] * dspeed_t) / v[i];//匀速段用时

					t_sum = t_sum + uspeed_t + kspeed_t + dspeed_t + staytime[i];
				}
			}
			int t1 = v[s_index] / ua[s_index] + ((judge_s - s_sum) - 0.5*v[s_index] * v[s_index] / ua[s_index]) / v[s_index];//离判断点前一站出发到到达判断点用时
			//红绿灯初始状态为绿灯
			int t2 = (t1 + t_sum) % (greenlight_t[i] + redlight_t[i]);//判断当前红绿灯的状态
			int t3;//剩余时间i
			int t4 = stop_s / v[s_index];//匀速通过制动距离用时
			int t5;//列车到达红绿灯路口用时
			int wait_t;//等待时间
			if (t2 >= 0 && t2 < greenlight_t[i])
			{
				t3 = greenlight_t[i] - t2;//绿灯剩余时间

				if (t3 <= t4)//列车不能通过，需减速
				{

					s = insert(s, s_index, s_sum, 0,i);
					v = insert(v, s_index, 0, 1,i);
					ua = insert(ua, s_index, 0, 1,i);
					da = insert(da, s_index, 0, 1,i);

					t5 = v[s_index] / da[s_index] + (stop_s - 0.5*v[s_index] * v[s_index] / da[s_index]) / v[s_index];
					wait_t = redlight_t[i] - (t5 - t3);
					staytime = insert(staytime, s_index, wait_t, 2,i);

				}
			}
			else if (t2 >= greenlight_t[i])
			{
				t3 = greenlight_t[i] + redlight_t[i] - t2;//红灯剩余时间
				if (t3 > t4)
				{
					s = insert(s, s_index, s_sum, 0,i);
					v = insert(v, s_index, 0, 1,i);
					ua = insert(ua, s_index, 0, 1,i);
					da = insert(da, s_index, 0, 1,i);

					t5 = v[s_index] / da[s_index] + (stop_s - 0.5*v[s_index] * v[s_index] / da[s_index]) / v[s_index];
					wait_t = t3 - t5;
					staytime = insert(staytime, s_index, wait_t, 2,i);

				}
			}
		}
	}
	//供电区间开启及关闭时间计算
	public:void getpower_t()
	{
		for (int i=0; i < power_s->Length; i++)
		{
			int judge_s = power_s[i];//供电区间距离出发点位置
			int s_sum=0;//站间距离累加
			int s_index=0;//站间距离索引
			for (int i = 0; i < s->Length; i++)//判断供电区间在哪个站点区间内
			{
				if (judge_s>=s_sum&&judge_s <= s_sum + s[i])
				{
					s_index = i;
					break;
				}
				else
					s_sum += s[i];
			}
			int t_sum=0;//运行时间的确定
			if (s_index >= 1)
			{
				for (int i = 0; i < s_index; i++)
				{
					int uspeed_t = v[i] / ua[i];//加速段用时
					int dspeed_t = v[i] / da[i];//减速段用时
					int kspeed_t = (s[i] - 0.5*v[i] * uspeed_t - 0.5*v[i] * dspeed_t) / v[i];//匀速段用时

					t_sum = t_sum + uspeed_t + kspeed_t + dspeed_t + staytime[i];
				}
			}
			int t1=0;
			int t2=0;
			if (((judge_s - s_sum) - 0.5*v[s_index] * v[s_index] / ua[s_index]) >= 0)
			{
				t1 = v[s_index] / ua[s_index] + ((judge_s - s_sum) - 0.5*v[s_index] * v[s_index] / ua[s_index]) / v[s_index];//离判断点前一站出发到到达供电区间用时
			}
			else
			{
				t1 = System::Math::Sqrt(2 * (judge_s - s_sum) / ua[s_index]);
			}
			t2 = t_sum+t1;//列车到达供电区间时间即启用时间

			int t3 = t2+power_l / v[s_index];//关闭时间

			//还需确定供电区间编号,轨道上三个供电区间
			int power_num;
			if (power_s[i] % 500 <= 167)
				power_num = 1;
			else if (power_s[i] % 500 >= 167 && power_s[i] % 500 <= 334)
				power_num = 2;
			else
				power_num = 3;

			//生成指令并储存
			String^order1 = create_order("开供电区间",power_num);
			String^order2 = create_order("关供电区间", power_num);
			array<String^>^str1 = gcnew array < String^ > {modelname, "p", "供电区间", "控制帧", t2.ToString(), order1, "开启供电区间"};
			array<String^>^str2 = gcnew array < String^ > {modelname, "p", "供电区间", "控制帧", t3.ToString(), order2, "关闭供电区间"};
			store_data(str1);
			store_data(str2);
		}
	}

	//
	//生成控制运行指令表
	//

	public:void time_table(void)
	{
		//清空原有数据表
		Conn->ConnectionString = "server=localhost;Initial Catalog=RunDB2;Integrated Security=True;";
		String^strcmd = "DELETE FROM controlTable";
		Data::SqlClient::SqlCommand ^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);
		Conn->Open();
		cmd->ExecuteNonQuery();
		Conn->Close();

		get_data();
		get_light_s();
		getpower_t();
		int uspeed_t;//加速段用时
		int dspeed_t;//减速段用时
		int kspeed_t;//匀速段用时

		int run_t;//启动时刻
		int stop_t;//减速时刻
		int arrive_t;//到站时间
		int sum_t = 0;//运行总时间
		int s_sum=0;
		
		for (int i=0; i < s->Length; i++)
		{
			String^astr = "列车减速";
			String^bstr="列车到站";
			String^cstr;

			//判断该位置是否是红绿灯
			s_sum += s[i];
			for (int j=0; j < light_s->Length; j++)
			{
				if (s_sum == light_s[j])
				{
					astr = "红绿灯减速";
					bstr = "红绿灯等待";
					break;
				}
			}
			

			//判断列车行驶方向
			if (s_sum>=waylength/2)
				cstr = "反向加速";
			else
				cstr = "加速";

			//计算各个时间点
			uspeed_t = v[i] / ua[i];//加速段用时
			dspeed_t = v[i] / da[i];//减速段用时
			kspeed_t = (s[i] - 0.5*v[i] * uspeed_t - 0.5*v[i] * dspeed_t) / v[i];//匀速段用时

			run_t = sum_t;//启动时刻
			stop_t = sum_t + kspeed_t + uspeed_t;//减速时刻
			arrive_t = sum_t + uspeed_t + kspeed_t + dspeed_t;//到站时刻
			if (i!=s->Length-1)
				sum_t = sum_t + uspeed_t + kspeed_t + dspeed_t + staytime[i];

			String^order1 = create_order(cstr, i);
			array<String^>^str1 = gcnew array < String^ > {modelname, "h", "车", "控制帧", run_t.ToString(), order1, "列车加速"};
			store_data(str1);

			String^order2 = create_order("减速",i);
			array<String^>^str2 = gcnew array < String^ > {modelname, "h", "车", "控制帧", stop_t.ToString(), order2, astr};
			store_data(str2);

			array<String^>^str3 = gcnew array < String^ > {modelname, "h", "车", "无", arrive_t.ToString(), "-----", bstr};
			store_data(str3);
		}

	}


private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
	//生成指令时间表
	time_table();
	modelnametextBox->Text = modelname;
	trainnametextBox->Text = trainname;
	waynametextBox->Text = wayname;
	runwaytextBox->Text = "自动双向";
	stopnametextBox->Text = stopname[0];
	directiontextBox->Text = stopname[0] + "->" + stopname[stop_num - 1];
	waylengthtextBox->Text = (waylength / 2).ToString();
	stopnumtextBox->Text = stop_num.ToString();
	/*String ^str;
	for (int i; i < power_name->Length; i++)
	{
		str += power_name[i] + " ";
	}
	str = str + "\n";
	for (int i; i < power_s->Length; i++)
	{
		str += power_s[i].ToString() + " ";
	}
	MessageBox::Show(str);*/
	
}
		 
//////////////启动按钮，运行开始///////////////////	

		public:DateTime^runtime ;//启动时间
		public:int index = 0;//数据记录索引
		public:int stop_index = 0;//站点索引
		public:int people_num=0;//乘客数
		public:DateTime store_time;//表示上一条存入数据库中记录的时间
		public:int zhangdianbianhao = 1;//站点编号从1开始

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (connected == true)
	{
		//在毫秒为0时执行程序以防止时间比对的错误
		while (1)
		{
			DateTime^ time = DateTime::Now;
			if (time->Millisecond <= 200)
				break;
		}
		label10->BackColor = System::Drawing::Color::Lime;
		//发送开始采集指令
		sendorder(create_order("开始采样", 0));

			//初始上车人数
			people_num = geton_num[0]-getoff_num[0];
			store_time = DateTime::Now;//第一条数据记录时间
			Conn->ConnectionString = "server=localhost;Initial Catalog=RunDB2;Integrated Security=True;";

			String^strcmd = String::Format("INSERT INTO peopletable (方案编号,线路编号,列车编号,站点名,到站时间,出站时间,上车人数,下车人数,车内人数,时间间隔,站点编号) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}','{6}','{7}','{8}','{9}','{10}')", modelname, wayname, trainname, stopname[0], DateTime::Now.ToString(), DateTime::Now.ToString(), geton_num[0].ToString(), getoff_num[0].ToString(), people_num.ToString(), "0",zhangdianbianhao.ToString());

			Data::SqlClient::SqlCommand ^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);
			Conn->Open();
			cmd->ExecuteNonQuery();
			Conn->Close();

		//传输指令的显示
		ListViewItem^sendcollectitem = gcnew ListViewItem("模型电车");
		sendcollectitem->SubItems->Add("控制帧");
		sendcollectitem->SubItems->Add(DateTime::Now.ToString());
		sendcollectitem->SubItems->Add(create_order("开始采样", 0));
		sendcollectitem->SubItems->Add("开始采样");
		sendcollectitem->BackColor = System::Drawing::Color::WhiteSmoke;
		listView1->Items->Add(sendcollectitem);

		ListViewItem^sendlightitem = gcnew ListViewItem("红绿灯");
		sendlightitem->SubItems->Add("控制帧");
		sendlightitem->SubItems->Add(DateTime::Now.ToString());
		sendlightitem->SubItems->Add(create_order("开红绿灯", 0));
		sendlightitem->SubItems->Add("开启并设置红绿灯");
		sendlightitem->BackColor = System::Drawing::Color::WhiteSmoke;
		listView1->Items->Add(sendlightitem);

		Conn->ConnectionString = "server=localhost;Database=RunDB2;UID=sa;PWD=123456;";
		String^strcmd1 = String::Format("SELECT * FROM controlTable WHERE 方案编号 = '{0}'ORDER BY CAST(发送时间 AS INT)", modelname);//按时间顺序取数据表数据
		Data::SqlClient::SqlCommand ^ cmd1 = gcnew Data::SqlClient::SqlCommand(strcmd1, Conn);
		Conn->Open();
		Adapter->SelectCommand = cmd1;
		Adapter->Fill(dataSet1, "controlTable");
		Conn->Close();
		for (int i = 0; i < dataSet1->Tables["controlTable"]->Rows->Count; i++)
		{
			DataRow^ row = dataSet1->Tables["controlTable"]->Rows[i];
			ListViewItem^senditem = gcnew ListViewItem(row["设备名称"]->ToString());
			senditem->SubItems->Add(row["指令类型"]->ToString());
			int second = Int32::Parse(row["发送时间"]->ToString());
			DateTime^time = DateTime::Now.AddSeconds(second);
			senditem->SubItems->Add(time->ToString());
			senditem->SubItems->Add(row["指令内容"]->ToString());
			senditem->SubItems->Add(row["操作"]->ToString());
			listView1->Items->Add(senditem);
		}
		
		//启动定时器
		timer1->Interval = 100;
		timer1->Enabled = true;
		menuStrip1->Enabled = true;
		sendorder(create_order("开红绿灯", 0));
		runtime = DateTime::Now;
		timer1->Start();

		stopbutton->Enabled = true;

		//仿真数据产生功能启动
		timer3->Enabled = true;
		timer3->Start();
	}
	else
		MessageBox::Show("请连接模型电车！");
}

////////////定时器发送////////////

		public:int s_index=-1;//区间距离索引
		public:DateTime go_time;//区间出发时间
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	//获取当前时间
	DateTime nowtime = DateTime::Now;

	//计算时间节点
	DataRow^row=dataSet1->Tables["controlTable"]->Rows[index];
	int length = dataSet1->Tables["controlTable"]->Rows->Count;
	int second = Int32::Parse(row["发送时间"]->ToString());
	DateTime^time = runtime->AddSeconds(second);

	//比对时间实现定时发送数据
	if ( nowtime.ToString("yyyyMMdd HH:mm:ss") == time->ToString("yyyyMMdd HH:mm:ss"))
	{ 
		listView1->Items[index + 2]->BackColor = System::Drawing::Color::WhiteSmoke;
		if (row["指令内容"]->ToString()->TrimEnd() == "-----")
		{
			IsStop = true;
			if (row["操作"]->ToString()->TrimEnd() == "列车到站")
			{
				//到站上下车人数运算
				people_num = people_num - getoff_num[stop_index + 1] + geton_num[stop_index + 1];
				DateTime^arrive_time = nowtime;
				DateTime^leave_time;
				String^leave_timestr;
				if (stop_index < stopstaytime->Length)
				{
					leave_time = arrive_time->AddSeconds(stopstaytime[stop_index]);
					leave_timestr = leave_time->ToString();
				}//出站时间
				else
					leave_timestr = " ";
				String^name = stopname[stop_index+1];
				TimeSpan ts = nowtime.Subtract(store_time);
				int t_change = ts.TotalSeconds;//求记录间的时间间隔

				//记录站点编号，例如1、2、3、2、1
				zhangdianbianhao++;

				//存入乘客数据表
				Conn->ConnectionString = "server=localhost;Initial Catalog=RunDB2;Integrated Security=True;";

				String^strcmd = String::Format("INSERT INTO peopletable (方案编号,线路编号,列车编号,站点名,到站时间,出站时间,上车人数,下车人数,车内人数,时间间隔,站点编号) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}','{6}','{7}','{8}','{9}','{10}')", modelname, wayname, trainname, name, arrive_time->ToString(), leave_timestr, geton_num[stop_index + 1].ToString(), getoff_num[stop_index + 1].ToString(), people_num.ToString(), t_change,zhangdianbianhao.ToString());

				Data::SqlClient::SqlCommand ^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);
				Conn->Open();
				cmd->ExecuteNonQuery();
				Conn->Close();

				//保存记录时间，用于计算时间间隔
				store_time = nowtime;
				stop_index++;
			}
		}
		else
		{
			String^order = row["指令内容"]->ToString();
			sendorder(order);
			if (row["操作"]->ToString()->TrimEnd() == "列车加速")
			{
				IsStop = false;
				s_index++;
				go_time = nowtime;
			}
		} 
		index++;

		//判断是否为最后一条指令
		if (index == length)
		{
			timer1->Stop();//关闭计时器
			timer3->Stop();//关闭仿真计时器
			stopbutton->Enabled = false;
			label10->BackColor = System::Drawing::Color::Red;
			sendorder(create_order("结束采样", 0));
			MessageBox::Show("运行结束，正在统计数据！");
			//stop_num
			CalculatePowerDissipation(modelname);
			CalculatePeopleFlow(modelname,stop_num);
		}
	}
}

	//发送数据
	public:int send_num = 0;//发送帧数
	public:void sendorder(String^order)
	{
		array<String^>^tempArr = order->Split('-');
		array<Byte>^orderbyte = gcnew array<Byte>(tempArr->Length);
		for (int i = 0; i < tempArr->Length; i++)
		{
			orderbyte[i] = Convert::ToByte(tempArr[i],16);
		}
		try
		{
			newclient->Send(orderbyte);
			//等待下位机放回信号，待测试
			//while (errorflag==-1)
			//{
			//	if (errorflag== 1)//出错
			//	{
			//		newclient->Send(orderbyte);
			//		errorflag = -1;
			//	}
			//	else if (errorflag == 0)//正确
			//		break;
			//}
			//errorflag = -1;
			send_num++;
			sendnumtextBox->Text = send_num.ToString();
		}
		catch (SocketException ^e)
		{
			label10->BackColor = System::Drawing::Color::Red;
			MessageBox::Show("连接失败，请检查设备！" + e->Message);
			return;
		}
	}
	//接收数据
	//public:int errorflag=-1;//错误标志，初始为-1，正确接收为1，错误为0
	public:int receive_num = 0;//接收帧数
	public:void ReceiveMsg()
	{
		while (true)
		{
			DateTime receivetime = DateTime::Now;
			array<Byte>^ data = gcnew array<Byte>(1024);//定义数据接收数组  
			newclient->Receive(data);//接收数据到data数组  

			//用于判断下位机接收数据是否正确
			/*if (data[0] = 0xFF)
				errorflag = 1;
			else
				errorflag = 0;*/

			int length = data[2];//读取数据长度  
			array<Byte>^ datashow = gcnew array<Byte>(length);
			for (int i = 0; i < length; i++)//将要显示的数据存放到数组datashow中  
				datashow[i] = data[i];
			if (datashow[0] == 0x00)
			{
				String^ stringdata = BitConverter::ToString(datashow);//把数组转换成16进制字符串  
				String^sb;//判断设备
				if (datashow[1] == 0x02)
					sb = "电车模型";
				else if (datashow[1] == 0x03)
					sb = "轨道模型";
				MyInvoke^ mi = gcnew MyInvoke(this, &Form1::showtext);
				this->Invoke(mi, stringdata, sb);//在线程里调用控件显示
				getmsg(datashow,receivetime);
			}
			receive_num++;
			receivenumtextBox->Text = receive_num.ToString();
		}
	}
	//获取数据内容并存库
	private:int monitorone_pass = 0;
			int monitortwo_pass = 0;
			int monitorthree_pass = 0;
			int powerpassnum=0;//经过供电区间的次数
	public:SqlConnection^getConn = gcnew SqlConnection();//创建数据库连接
	public:void getmsg(array<Byte>^buffer,DateTime time)
	{
		String^strcmd;
		String^str = "正向";
		double car_v=0;
		double car_a=0;
		double car_V = 0;
		double car_I = 0;

		double car_position=0;

		int power_number=0;
		double power_V=0;
		double power_I=0;

		int monitor_number=0;
		int monitor_open=0;
		double adjust_position = 0;

		if (buffer[1] == 0x02)//电车模型
		{
			car_a = buffer[4] + buffer[5] / 10;
			int n = buffer[7] + buffer[8] / 10;//返回的转速
			car_v = (2 * 3.14) / 60*n*0.014*ratio;
			//car_I = buffer[10] + buffer[11] / 10;
			//car_V = buffer[13] + buffer[14] / 10;
			car_I = 20 + rand() % (20 - 30 + 1);
			car_V = 80 + rand() % (80 - 90 + 1);
			car_position = integral_getposition(time, car_v);
			double t = 1/getdata_f;
			if (stop_index>0.5*stopname->Length)//判断方向
				str = "反向";
			strcmd = String::Format("INSERT INTO trainTable (方案编号,线路编号,列车编号,行驶方向,时间,速度,加速度,电流,电压,位置,时间间隔) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}','{6}','{7}','{8}','{9}','{10}')", modelname, wayname, trainname, str, time.ToString(), (car_v*3.6).ToString("f1"), car_a.ToString("f1"), car_I.ToString("f1"), car_V.ToString("f1"),car_position.ToString("f1"),t.ToString("f1"));
		}
		if (buffer[1] == 0x03)
		{
			if (buffer[3] == 0x25)//供电区间
			{
				power_number = buffer[4] ;
				powerpassnum++;
				power_I = buffer[6]  + (buffer[7] ) / 10;
				power_V = buffer[9]  + (buffer[10] ) / 10;
				strcmd = String::Format("INSERT INTO powerTable (方案编号,线路编号,时间,供电区间编号,电流,电压) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}')", modelname, wayname, time.ToString(),power_name[powerpassnum-1],power_I.ToString("f1"),power_V.ToString("f1"));
			}
			else if (buffer[3] == 0x27)//监测点
			{
				if (buffer[5] == 0x01)
				{
					monitor_number = buffer[4] ;
					monitor_open = 1;
					adjust_position = getadjustposition(monitor_number);
					iposition = adjust_position;//位置校正
					strcmd = String::Format("INSERT INTO monitorTable (方案编号,线路编号,时间,监测点编号,状态,校正位置) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}')", modelname, wayname, time.ToString(), monitor_number.ToString(), monitor_open.ToString(), adjust_position.ToString("f1"));
				}
			}
		}
		
		getConn->ConnectionString = "server=localhost;Initial Catalog=RunDB2;Integrated Security=True;";
		Data::SqlClient::SqlCommand ^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, getConn);
		getConn->Open();
		cmd->ExecuteNonQuery();
		getConn->Close();
	}


	//积分法获取位置函数
	public:double iposition=0;
	public:double integral_getposition(DateTime time,double v_get)
	{
		if (v_get == 0)//速度为0，即是停靠状态
		{
			int sum=0;
			for (int i; i <= s_index; i++)
				sum += s[i];
			iposition = sum;//位置校正
		}
		else
		{
			iposition = iposition + v_get * 0.2;
		}
		return iposition ;
	}
	//获得校正位置
	public: double getadjustposition(Byte monitor_number)
	{
		double adjust_position = 0;
		switch (monitor_number)
		{
		case 0x00:
			if (stop_index <= 0.5*stopname->Length)//正向
			{
				monitorone_pass++;
				adjust_position = monitor_one*ratio + 500 * (monitorone_pass - 1);
			}
			else if(stop_index > 0.5*stopname->Length)//反向
			{
				adjust_position = waylength - (monitor_one*ratio + 500 * (monitorone_pass - 1));
				monitorone_pass--;
			}
			break;
		case 0x01:
			if (stop_index <= 0.5*stopname->Length)//正向
			{
				monitortwo_pass++;
				adjust_position = monitor_two*ratio + 500 * (monitortwo_pass - 1);
			}
			else if (stop_index > 0.5*stopname->Length)//反向
			{
				adjust_position = waylength - (monitor_two*ratio + 500 * (monitortwo_pass - 1));
				monitortwo_pass--;
			}
			break;
		case 0x02:
			if (stop_index <= 0.5*stopname->Length)//正向
			{
				monitorthree_pass++;
				adjust_position = monitor_three*ratio + 500 * (monitorthree_pass - 1);
			}
			else if (stop_index > 0.5*stopname->Length)//反向
			{
				adjust_position = waylength - (monitor_three*ratio + 500 * (monitorthree_pass - 1));
				monitorthree_pass--;
			}
			break;
		}
		return adjust_position;
	}
	//显示接收数据
	public: void showtext(String ^msg, String^a)
	{

		//在线程里以安全方式调用控件  
		ListViewItem^ receiveItem = gcnew ListViewItem(a);
		receiveItem->SubItems->Add("数据帧");
		receiveItem->SubItems->Add(DateTime::Now.ToString());
		receiveItem->SubItems->Add(msg);
		listView2->Items->Add(receiveItem);
	}

private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	if (System::Windows::Forms::DialogResult::Yes == MessageBox::Show(L"系统连接中，是否断开本次连接并关闭程序！！！", "确认", MessageBoxButtons::YesNo))
	{
		try
		{
			timer3->Stop();
			timer1->Stop();
			if (connected == true)
			{
				if (myThread != nullptr)
				{
					if (myThread->IsAlive)
						myThread->Abort();
				}
				newclient->Close();
				label12->BackColor = System::Drawing::Color::Red;
			}
			connected = false;
		}
		catch (SocketException ^e)
		{
			MessageBox::Show("操作失败请重试！" + e->Message);
			return;
		}
	}
}

private: System::Void 速度监测ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	speedForm^speedform = gcnew speedForm();
	speedform->modelname = modelname;
	speedform->wayname = wayname;
	speedform->trainname = trainname;
	speedform->stopname = stopname;
	speedform->Show();
}
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
	toolStripStatusLabel1->Text = DateTime::Now.ToString();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	int port = Int32::Parse(porttextBox->Text);//获取端口号
	String^ipadd = maskedTextBox1->Text->Replace(" ", "");//获取IP
	IPEndPoint^ie = gcnew IPEndPoint(IPAddress::Parse(ipadd), port);
	newclient = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);

	try
	{
		newclient->Connect(ie);
		connected = true;
		label12->BackColor = System::Drawing::Color::Lime;
		button1->Enabled = true;
		//array<Byte>^byte = gcnew array < Byte > {0x00,0x00,0x00,0x00,0x00,0x00,0x00};
		//newclient->Send(byte);//发送7个字节启动下位机
	}
	catch (SocketException ^e)
	{
		MessageBox::Show("连接不上模型电车，请检查设备！" + e->Message);
		return;
	}

	ThreadStart ^myThreaddelegate = gcnew ThreadStart(this, &Form1::ReceiveMsg);
	myThread = gcnew Thread(myThreaddelegate);
	myThread->Start();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Stop();
	if (connected == true)
	{
		if (myThread != nullptr)
		{
			if (myThread->IsAlive)
				myThread->Abort();
		}
		newclient->Close();
		label12->BackColor = System::Drawing::Color::Red;
		MessageBox::Show("已断开连接！");
	}
	connected = false;
}

private: System::Void stopbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	//运行时有效，按下后弹出询问窗口，确认后停止运行并删除本次运行数据
	if (System::Windows::Forms::DialogResult::Yes == MessageBox::Show(L"有轨电车正在运行，是否中断本次运行并删除本次数据！！！", "确认", MessageBoxButtons::YesNo))
	{
		try
		{
			sendorder(create_order("减速", 1));//停止电车模型
			timer3->Stop();
			timer1->Stop();
			if (connected == true)
			{
				if (myThread != nullptr)
				{
					if (myThread->IsAlive)
						myThread->Abort();
				}
				newclient->Close();
				label12->BackColor = System::Drawing::Color::Red;
			}
			connected = false;
			//删除本次数据
			array<String^>^ tablename = gcnew array<String^>{ "peopleTable","trainTable","powerTable","monitorTable"};
			Conn->ConnectionString = "server=localhost;Initial Catalog=RunDB2;Integrated Security=True;";
			Conn->Open();
			for (int i; i < tablename->Length; i++)
			{
				String^strcmd = String::Format("DELETE  FROM {0} WHERE 方案编号 = '{1}'", tablename[i],modelname);
				Data::SqlClient::SqlCommand ^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);
				cmd->ExecuteNonQuery();
			}
			Conn->Close();
			MessageBox::Show("已停止运行！");
		}
		catch (SqlException ^e)
		{
			MessageBox::Show("操作失败请重试！" + e->Message);
			return;
		}
	}
}
		 //用于调试时产生仿真数据
		 public:int S1=0;
		public: bool IsStop;
private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
	int Vtest = 80 + rand() % (80 - 90 + 1);
	int Itest = 20 + rand() % (20 - 30 + 1);
	int vtest = 0;
	int atest = 0;
	vtest = 40 + rand() % (40 - 120 + 1);
	atest = 0 + rand() % (0 - 30 + 1);
	String^ str="正向" ;
	if (IsStop == true)
	{
		vtest = 0;
		atest = 0;
		S1 = S1;
	}
	else
	{
		vtest = 40 + rand() % (40 - 120 + 1);
		atest = 0 + rand() % (0 - 30 + 1);
		S1 = S1 + 10;
	}
	if (stop_index>0.5*stopname->Length)
	{
		str = "反向";
	}
	
	if (S1 <= waylength)
	{
		if (S1 <= 0.5*waylength)
			str = "正向";
		else
			str = "反向";
		Conn->ConnectionString = "server=localhost;Initial Catalog=RunDB2;Integrated Security=True;";
		String^strcmd = String::Format("INSERT INTO traintable (方案编号,线路编号,列车编号,行驶方向,时间,速度,加速度,电流,电压,位置,时间间隔) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}','{6}','{7}','{8}','{9}','{10}')", modelname, wayname, trainname, str, DateTime::Now.ToString(), vtest.ToString(), atest.ToString(), Itest.ToString(), Vtest.ToString(), S1.ToString(), "1");
		Data::SqlClient::SqlCommand ^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);

		String^strcmd1 = String::Format("INSERT INTO powerTable (方案编号,线路编号,时间,供电区间编号,电流,电压) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}')", modelname, wayname,DateTime::Now.ToString(),"Q001",Itest.ToString(), Vtest.ToString());
		Data::SqlClient::SqlCommand ^ cmd1 = gcnew Data::SqlClient::SqlCommand(strcmd1, Conn);
		Conn->Open();
		cmd->ExecuteNonQuery();
		cmd1->ExecuteNonQuery();
		Conn->Close();
	}
	else
	{
		timer3->Stop();
		MessageBox::Show("仿真结束");
		timer3->Enabled = false;
	}
}
private: System::Void 电车电流电压监测ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	trainVIForm^ trainVIform = gcnew trainVIForm();
	trainVIform->modelname = this->modelname;
	trainVIform->trainname = this->trainname;
	trainVIform->wayname = this->wayname;
	trainVIform->Show();
}
private: System::Void 供电区间电流电压监测ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	powerVIForm^ powerVIform = gcnew powerVIForm();
	powerVIform->modelname = this->modelname;
	powerVIform->trainname = this->trainname;
	powerVIform->wayname = this->wayname;
	powerVIform->power_l = this->power_l;
	powerVIform->power_name = this->power_name;
	powerVIform->power_s = this->power_s;
	powerVIform->powerpassnum = this->powerpassnum;
	powerVIform->Show();
}
private: System::Void 实时站点监测ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	arriveForm^ arriveform = gcnew arriveForm();
	arriveform->modelname = this->modelname;
	arriveform->trainname = this->trainname;
	arriveform->wayname = this->wayname;
	arriveform->stopname = this->stopname;
	arriveform->zaikeliang = this->zaikeliang;
	arriveform->Show();
}
private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}
};
}

