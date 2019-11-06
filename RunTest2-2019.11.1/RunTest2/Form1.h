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
#define monitor_one 2.23//�����ڹ��ģ���ϵ�λ��
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
	/// Form1 ժҪ
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
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


	private: System::Windows::Forms::ToolStripMenuItem^  �ٶȼ��ToolStripMenuItem;
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
	private: System::Windows::Forms::ToolStripMenuItem^  �糵������ѹ���ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������������ѹ���ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ʵʱվ����ToolStripMenuItem;


	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// ����������������
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->�ٶȼ��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�糵������ѹ���ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ѹ���ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ʵʱվ����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
				this->�ٶȼ��ToolStripMenuItem,
					this->�糵������ѹ���ToolStripMenuItem, this->�������������ѹ���ToolStripMenuItem, this->ʵʱվ����ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1587, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Form1::menuStrip1_ItemClicked);
			// 
			// �ٶȼ��ToolStripMenuItem
			// 
			this->�ٶȼ��ToolStripMenuItem->Name = L"�ٶȼ��ToolStripMenuItem";
			this->�ٶȼ��ToolStripMenuItem->Size = System::Drawing::Size(83, 24);
			this->�ٶȼ��ToolStripMenuItem->Text = L"�ٶȼ��";
			this->�ٶȼ��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�ٶȼ��ToolStripMenuItem_Click);
			// 
			// �糵������ѹ���ToolStripMenuItem
			// 
			this->�糵������ѹ���ToolStripMenuItem->Name = L"�糵������ѹ���ToolStripMenuItem";
			this->�糵������ѹ���ToolStripMenuItem->Size = System::Drawing::Size(149, 24);
			this->�糵������ѹ���ToolStripMenuItem->Text = L"�糵-������ѹ���";
			this->�糵������ѹ���ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�糵������ѹ���ToolStripMenuItem_Click);
			// 
			// �������������ѹ���ToolStripMenuItem
			// 
			this->�������������ѹ���ToolStripMenuItem->Name = L"�������������ѹ���ToolStripMenuItem";
			this->�������������ѹ���ToolStripMenuItem->Size = System::Drawing::Size(179, 24);
			this->�������������ѹ���ToolStripMenuItem->Text = L"��������-������ѹ���";
			this->�������������ѹ���ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�������������ѹ���ToolStripMenuItem_Click);
			// 
			// ʵʱվ����ToolStripMenuItem
			// 
			this->ʵʱվ����ToolStripMenuItem->Name = L"ʵʱվ����ToolStripMenuItem";
			this->ʵʱվ����ToolStripMenuItem->Size = System::Drawing::Size(113, 24);
			this->ʵʱվ����ToolStripMenuItem->Text = L"ʵʱվ����";
			this->ʵʱվ����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ʵʱվ����ToolStripMenuItem_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->tabPage1->Text = L"����ָ��";
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
			this->stopbutton->Text = L"ֹͣ";
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
			this->label11->Text = L"����ָʾ��";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(985, 700);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(109, 20);
			this->label9->TabIndex = 2;
			this->label9->Text = L"����ָʾ��";
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(32, 668);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(141, 41);
			this->button1->TabIndex = 1;
			this->button1->Text = L"����";
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
			this->columnHeader2->Text = L"�豸";
			this->columnHeader2->Width = 109;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"ָ������";
			this->columnHeader3->Width = 84;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"����ʱ��";
			this->columnHeader4->Width = 200;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"ָ������";
			this->columnHeader5->Width = 345;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"����";
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
			this->tabPage2->Text = L"����ָ��";
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
			this->columnHeader7->Text = L"�豸";
			this->columnHeader7->Width = 122;
			// 
			// columnHeader8
			// 
			this->columnHeader8->Text = L"ָ������";
			this->columnHeader8->Width = 80;
			// 
			// columnHeader9
			// 
			this->columnHeader9->Text = L"����ʱ��";
			this->columnHeader9->Width = 181;
			// 
			// columnHeader10
			// 
			this->columnHeader10->Text = L"ָ������";
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
			this->groupBox1->Text = L"��������";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(164, 209);
			this->button3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 29);
			this->button3->TabIndex = 3;
			this->button3->Text = L"�Ͽ�";
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
			this->button2->Text = L"����";
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
			this->label16->Text = L"����֡����";
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
			this->label15->Text = L"����֡����";
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
			this->label14->Text = L"�˿����ã�";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(40, 49);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(68, 15);
			this->label13->TabIndex = 0;
			this->label13->Text = L"IP��ַ��";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(12, 141);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"�г���ţ�";
			// 
			// trainnametextBox
			// 
			this->trainnametextBox->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->label2->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(12, 206);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"���з�ʽ��";
			// 
			// runwaytextBox
			// 
			this->runwaytextBox->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->label3->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(12, 264);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(109, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"��ʼվ����";
			// 
			// stopnametextBox
			// 
			this->stopnametextBox->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->label4->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(12, 328);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(109, 20);
			this->label4->TabIndex = 2;
			this->label4->Text = L"��ʻ����";
			// 
			// directiontextBox
			// 
			this->directiontextBox->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->label5->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label5->Location = System::Drawing::Point(12, 86);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(109, 20);
			this->label5->TabIndex = 2;
			this->label5->Text = L"��·��ţ�";
			// 
			// waynametextBox
			// 
			this->waynametextBox->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->label6->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label6->Location = System::Drawing::Point(12, 32);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(109, 20);
			this->label6->TabIndex = 2;
			this->label6->Text = L"������ţ�";
			// 
			// modelnametextBox
			// 
			this->modelnametextBox->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->label7->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label7->Location = System::Drawing::Point(12, 385);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(109, 20);
			this->label7->TabIndex = 2;
			this->label7->Text = L"��·ȫ����";
			// 
			// waylengthtextBox
			// 
			this->waylengthtextBox->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->label8->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label8->Location = System::Drawing::Point(12, 450);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(109, 20);
			this->label8->TabIndex = 2;
			this->label8->Text = L"վ��������";
			// 
			// stopnumtextBox
			// 
			this->stopnumtextBox->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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

	public:Socket ^newclient;//������λ���ͻ���
	public:bool connected;//����״̬
	public:Thread^myThread;//�����߳����ڽ�������
	public:delegate void MyInvoke(String^str1,String^str2);

	public:SqlConnection^Conn = gcnew SqlConnection();//�������ݿ�����
	public:SqlDataAdapter^Adapter = gcnew SqlDataAdapter();//���ݿ�������

	public:array<int>^ s ;//վ���������
	public:array<int>^ ua ;//���μ��ٶ�
	public:array<int>^ v;//������ʻ�ٶ�
	public:array<int>^ da;//�����ƶ��ٶ�
	public:array<int>^staytime;//ͣ����ȴ�ʱ��,�������̵Ƶȴ�ʱ��
	public:array<int>^stopstaytime;//��վͣ��ʱ��
	public:array<String^>^stopname;//վ������
	public:int stop_num;//վ�����
	public:array<int>^geton_num;//�ϳ�����
	public:array<int>^getoff_num;//�³�����

	public:array<int>^power_s ;//��������λ��
	public:array<String^>^power_name;//����������
	public:int power_l;//�������䳤��

	public:array<int>^light_s ;//���̵�λ��
	public:array<int>^greenlight_t;//�̵�ʱ��
	public:array<int>^redlight_t;//���ʱ��

	public:int getdata_f=1;//����Ƶ��,�ݶ�Ϊһ��һ������
		  
	public:String^modelname="F0012";//�������
	public:String^wayname;//��·���
	public:String^trainname;//�г����
	public:int zaikeliang;//�ؿ�����
	public:int waylength;//��·�ܳ�
	public:double ratio=136.61;//500m��ģ���ܳ�֮��

	/////////////////��ȡ����//////////////////

	public:void get_data(void)
	{
		Conn->ConnectionString = "server=localhost;Initial Catalog=�г����ݿ�;Integrated Security=True;";
		Conn->Open();
		String^strcmd1 = String::Format("SELECT �г���� FROM ������Ϣ WHERE ������� = '{0}'", modelname);
		String^strcmd2 = String::Format("SELECT ��·��� FROM ������Ϣ WHERE ������� = '{0}'", modelname);
		Data::SqlClient::SqlCommand ^ cmd1 = gcnew Data::SqlClient::SqlCommand(strcmd1, Conn);
		Data::SqlClient::SqlCommand ^ cmd2 = gcnew Data::SqlClient::SqlCommand(strcmd2, Conn);
		trainname = cmd1->ExecuteScalar()->ToString();
		wayname = cmd2->ExecuteScalar()->ToString();

		int length=0;//���鳤��

		String^strcmd3 = String::Format("SELECT * FROM վ����Ϣ WHERE ��·��� = '{0}'", wayname);
		Data::SqlClient::SqlCommand ^ cmd3 = gcnew Data::SqlClient::SqlCommand(strcmd3, Conn);
		Adapter->SelectCommand = cmd3;
		Adapter->Fill(dataSet1, "sTable");
		length = dataSet1->Tables["sTable"]->Rows->Count;
		s = gcnew array<int>(length - 1);
		for (int i = 0; i < length - 1; i++)
		{
			DataRow ^row1 = dataSet1->Tables["sTable"]->Rows[i + 1];
			s[i] = Int32::Parse(row1["վ�����"]->ToString());
		}
		stopname = gcnew array<String^>(length);
		geton_num = gcnew array<int>(length);
		getoff_num = gcnew array<int>(length);
		for (int i = 0; i < length; i++)
		{
			DataRow^row2 = dataSet1->Tables["sTable"]->Rows[i];
			stopname[i] = row2["վ������"]->ToString()->TrimEnd();
			geton_num[i] = Int16::Parse(row2["�ϳ�����"]->ToString());
			getoff_num[i] = Int16::Parse(row2["�³�����"]->ToString());
		}
		

		String^strcmd4 = String::Format("SELECT * FROM �г�վ��������Ϣ WHERE �г���� = '{0}' AND ��·��� = '{1}'", trainname, wayname);
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
			v[i] = Int32::Parse(row3["վ���г��ٶ�"]->ToString())/3.6;//��ǧ��ÿ��ת��Ϊ��ÿ��
			ua[i] = Int32::Parse(row3["վ���г����ټ��ٶ�"]->ToString());
			da[i] = Int32::Parse(row3["վ���г����ټ��ٶ�"]->ToString());
			staytime[i] = Int32::Parse(row3["վ��ͣ��ʱ��"]->ToString());
		}

		String^strcmd5 = String::Format("SELECT * FROM ����������Ϣ WHERE ��·��� = '{0}'", wayname);
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
			power_l = Int32::Parse(row4["���䳤��"]->ToString());
			powers_sum += power_l + Int32::Parse(row4["�����������"]->ToString());
			power_s[i + 1] = powers_sum;
			power_name[i + 1] = row4["������"]->ToString()->Trim();
		}

		String^strcmd6 = String::Format("SELECT * FROM ���̵���Ϣ WHERE ��·��� = '{0}'", wayname);
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
			lights_sum += Int32::Parse(row5["���ں��̵ƾ���"]->ToString());
			greenlight_t[i] = Int32::Parse(row5["�̵�ʱ��"]->ToString());
			redlight_t[i] = Int32::Parse(row5["���ʱ��"]->ToString());
			light_s[i] = lights_sum;
		}

		String^strcmd7 = String::Format("SELECT վ������ FROM ��·��Ϣ WHERE ��·��� = '{0}'", wayname);
		Data::SqlClient::SqlCommand ^ cmd7 = gcnew Data::SqlClient::SqlCommand(strcmd7, Conn);
		stop_num = Int32::Parse(cmd7->ExecuteScalar()->ToString());

		String^strcmd8 = String::Format("SELECT ��ʻ���� FROM �г���Ϣ WHERE ��·��� = '{0}' and �г���� = '{1}'", wayname,trainname);
		Data::SqlClient::SqlCommand ^ cmd8 = gcnew Data::SqlClient::SqlCommand(strcmd8, Conn);
		String^ xsfx = cmd8->ExecuteScalar()->ToString()->Trim();//��ʻ����ĩվ
		String^strcmd9 = String::Format("SELECT �ؿ����� FROM �г���Ϣ WHERE ��·��� = '{0}' and �г���� = '{1}'", wayname, trainname);
		Data::SqlClient::SqlCommand ^ cmd9 = gcnew Data::SqlClient::SqlCommand(strcmd9, Conn);
		zaikeliang = Int32::Parse(cmd9->ExecuteScalar()->ToString()->Trim());

		Conn->Close();

		for (int i = 0; i < s->Length; i++)
			waylength += s[i];

		if (xsfx == "����")//��ʾ����·ĩվ��ʼ����,��Ի�ȡ��������з�����
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

		//����仯����
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

		//������waylength,����˫�����У��ʳ��ȱ�Ϊԭ��2����
		waylength = 0;
		for (int i = 0; i < s->Length; i++)
			waylength += s[i];
	}

	public:array<int>^ turnstraight(array<int>^ arr, int num)//��˫������ת��Ϊ����ֱ�����в���
	{
		array<int>^ newarr;
		switch (num)
		{
		case 1://��һ�����Ϊ��վ�����Ϊ�����任�����鳤��Ϊԭ����2��
			newarr = gcnew array<int>(2 * arr->Length);
			for (int i = 0; i < newarr->Length; i++)
			{
				if (i>arr->Length - 1)
					newarr[i] = arr[newarr->Length - 1 - i];
				else
					newarr[i] = arr[i];
			}
			break;
		case 2://�ڶ��������仯��ĺ��̵�λ��
			newarr = gcnew array<int>(2 * arr->Length);
			for (int i = 0; i < newarr->Length; i++)
			{
				if (i>arr->Length - 1)
					newarr[i] = 2 * waylength - light_s[2 * arr->Length - 1 - i];
				else
					newarr[i] = arr[i];
			}
			break;
		case 3://�����������仯��Ĺ�������λ��
			newarr = gcnew array<int>(2 * arr->Length);
			for (int i = 0; i < newarr->Length; i++)
			{
				if (i>arr->Length - 1)
					newarr[i] = 2 * waylength - power_s[2 * arr->Length - 1 - i] - power_l;
				else
					newarr[i] = arr[i];
			}
			break;
		case 4://�����������ͣ��ʱ������³�����Ϊ�����仯�����鳤�ȱ�ԭ����2����һ��
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
	

	//������Ӧָ��

	public:array<Byte>^  getCRC(array<Byte>^ orderbyte)//CRCУ��λ���ɺ���
	{
		int i, j;//ѭ������
		unsigned short usRegCRC = 0xFFFF;//���ڱ���CRC��ֵ

		for (i = 0; i < orderbyte->Length; i++)//ѭ����������֡
		{
			usRegCRC ^= orderbyte[i];//����㷨��CRCֵ
			for (j = 0; j < 8; j++)//ѭ������ÿ��bitλ
			{
				if (usRegCRC & 0x0001)
					usRegCRC = usRegCRC >> 1 ^ 0xA001;
				else
					usRegCRC >>= 1;
			}
		}
		Byte byteL = usRegCRC & 0xff;
		Byte byteH = (usRegCRC & 0xff00) >> 8;
		array<Byte>^ orderdata = gcnew array < Byte >(orderbyte->Length + 2);//������֡���CRCУ��
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
		array<Byte>^orderbyte;//ָ��
		array<int>^inta = gcnew array<int>(2);//int[0]����������int[1]����С��
		double a;//������ת��Ϊdouble����
		String^datastr;

		if (str =="����"||str=="����"||str=="��ʼ����"||str=="��������"||str=="�������")
		{
			databyte[0] = 0x01;
			databyte[1] = 0x02;
			if (str == "����")
			{
				databyte[2] = 10&0xff;//֡����
				databyte[3] = speedup;
				databyte[4] = 0x00;//��ת
				a = Double::Parse((ua[index] / ratio).ToString("f1"));
				inta = doubleturnint(a);
				//databyte[5] = inta[0]&0xff;
				//databyte[6] = inta[1] & 0xff;//С��λ
				databyte[5] = 0x02;
				databyte[6] = 0x00;//С��λ�����ü��ٶ�
				databyte[7] = 0x22;
				a = Double::Parse((v[index] / ratio).ToString("f1"));
				inta = doubleturnint(a);
				databyte[8] = 0x90;//�������ٶ�
				//databyte[8] = inta[0] & 0xff;
				databyte[9] = inta[1] & 0xff;//С��λ

				orderbyte = gcnew array<Byte>(10);
				for (int i = 0; i < 10; i++)
				{
					orderbyte[i] = databyte[i];
				}

			}
			else if (str == "�������")
			{
				databyte[2] = 10 & 0xff;//֡����
				databyte[3] = speedup;
				databyte[4] = 0x01;//��ת
				a = Double::Parse((ua[index] / ratio).ToString("f1"));
				inta = doubleturnint(a);
				databyte[5] = inta[0] & 0xff;
				databyte[6] = inta[1] &0xff;//С��λ
				databyte[7] = 0x22;
				a = Double::Parse((v[index] / ratio).ToString("f1"));
				inta = doubleturnint(a);
				databyte[8] = inta[0] & 0xff;
				databyte[9] = inta[1] & 0xff;//С��λ

				orderbyte = gcnew array<Byte>(10);
				for (int i = 0; i < 10; i++)
				{
					orderbyte[i] = databyte[i];
				}
			}
			else if (str == "����")
			{
				databyte[2] = 10 & 0xff;//֡����
				databyte[3] = speeddown;
				a = Double::Parse((da[index] / ratio).ToString("f1"));
				inta = doubleturnint(a);
				databyte[4] = inta[0] & 0xff;
				databyte[5] = inta[1] & 0xff;//С��λ
				databyte[6] = 0x22;
				a = Double::Parse((v[index] / ratio).ToString("f1"));
				inta = doubleturnint(a);
				databyte[7] = inta[0] & 0xff;
				databyte[8] = inta[1] & 0xff;//С��λ

				orderbyte = gcnew array<Byte>(9);
				for (int i = 0; i < 9; i++)
				{
					orderbyte[i] = databyte[i];
				}
			}
			else if (str == "��ʼ����")
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
		if (str == "����������" || str == "�ع�������" || str == "�����̵�" || str == "�غ��̵�")
		{
			databyte[0] = 0x01;
			databyte[1] = 0x03;
			if (str == "����������")
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
			else if (str == "�ع�������")
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
			else if (str == "�����̵�")
			{
				databyte[2] = 10&0xff;
				databyte[3] = lighton;
				databyte[4] = 0x00;//Ĭ����ʼΪ�̵�
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
		//������֡��Ϊ10�ֽ�
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
	public:array<int>^ doubleturnint(double a)//��double��������С�����ַ���
	{
		array<int>^ inta = gcnew array<int>(2);
		inta[0] = (int)a;
		inta[1] = (a - inta[0]) * 10;
		return inta;
	}
	//
	//�洢ָ���
	//

	public:void store_data(array<String^>^s)
	{
		Conn->ConnectionString = "server=localhost;Initial Catalog=RunDB2;Integrated Security=True;";
		String^strcmd = String::Format("INSERT INTO controltable (�������,�豸���,�豸����,ָ������,����ʱ��,ָ������,����) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}','{6}')", s[0], s[1], s[2], s[3], s[4],s[5],s[6]);
		Data::SqlClient::SqlCommand ^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd,Conn);
		Conn->Open();
		cmd->ExecuteNonQuery();
		Conn->Close();
	}

	//
	//���ݺ��̵�λ�ü�״̬����г����о�������
	//

	public:array<int>^ insert(array<int>^arr, int s_index, int a, int num,int index)//�����̵Ƶĸ������ݲ��뵽ԭ���Ĳ���������
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

	public:void get_light_s(void)//�жϺ��̵��Ƿ�Ӱ���г����У����ǽ�����Ϊһ��վ�����վ�����������
	{
		for (int i = 0; i < light_s->Length; i++)
		{
			int stop_s = 50;//50Ϊ�ƶ�����
			int judge_s = light_s[i] - 50;//���̵�ǰ�жϵ���������λ��
			int s_sum=0;//վ������ۼ�
			int s_index=0;//վ���������
			for (int i = 0; i < s->Length; i++)//�жϺ��̵����ĸ�վ��������
			{
				if (judge_s>s_sum&&judge_s < s_sum + s[i])
				{
					s_index = i;
					break;
				}
				else
					s_sum += s[i];
			}
			int t_sum;//����ʱ���ȷ��
			if (s_index >= 1)
			{
				for (int i = 0; i < s_index; i++)
				{
					int uspeed_t = v[i] / ua[i];//���ٶ���ʱ
					int dspeed_t = v[i] / da[i];//���ٶ���ʱ
					int kspeed_t = (s[i] - 0.5*v[i] * uspeed_t - 0.5*v[i] * dspeed_t) / v[i];//���ٶ���ʱ

					t_sum = t_sum + uspeed_t + kspeed_t + dspeed_t + staytime[i];
				}
			}
			int t1 = v[s_index] / ua[s_index] + ((judge_s - s_sum) - 0.5*v[s_index] * v[s_index] / ua[s_index]) / v[s_index];//���жϵ�ǰһվ�����������жϵ���ʱ
			//���̵Ƴ�ʼ״̬Ϊ�̵�
			int t2 = (t1 + t_sum) % (greenlight_t[i] + redlight_t[i]);//�жϵ�ǰ���̵Ƶ�״̬
			int t3;//ʣ��ʱ��i
			int t4 = stop_s / v[s_index];//����ͨ���ƶ�������ʱ
			int t5;//�г�������̵�·����ʱ
			int wait_t;//�ȴ�ʱ��
			if (t2 >= 0 && t2 < greenlight_t[i])
			{
				t3 = greenlight_t[i] - t2;//�̵�ʣ��ʱ��

				if (t3 <= t4)//�г�����ͨ���������
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
				t3 = greenlight_t[i] + redlight_t[i] - t2;//���ʣ��ʱ��
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
	//�������俪�����ر�ʱ�����
	public:void getpower_t()
	{
		for (int i=0; i < power_s->Length; i++)
		{
			int judge_s = power_s[i];//����������������λ��
			int s_sum=0;//վ������ۼ�
			int s_index=0;//վ���������
			for (int i = 0; i < s->Length; i++)//�жϹ����������ĸ�վ��������
			{
				if (judge_s>=s_sum&&judge_s <= s_sum + s[i])
				{
					s_index = i;
					break;
				}
				else
					s_sum += s[i];
			}
			int t_sum=0;//����ʱ���ȷ��
			if (s_index >= 1)
			{
				for (int i = 0; i < s_index; i++)
				{
					int uspeed_t = v[i] / ua[i];//���ٶ���ʱ
					int dspeed_t = v[i] / da[i];//���ٶ���ʱ
					int kspeed_t = (s[i] - 0.5*v[i] * uspeed_t - 0.5*v[i] * dspeed_t) / v[i];//���ٶ���ʱ

					t_sum = t_sum + uspeed_t + kspeed_t + dspeed_t + staytime[i];
				}
			}
			int t1=0;
			int t2=0;
			if (((judge_s - s_sum) - 0.5*v[s_index] * v[s_index] / ua[s_index]) >= 0)
			{
				t1 = v[s_index] / ua[s_index] + ((judge_s - s_sum) - 0.5*v[s_index] * v[s_index] / ua[s_index]) / v[s_index];//���жϵ�ǰһվ���������﹩��������ʱ
			}
			else
			{
				t1 = System::Math::Sqrt(2 * (judge_s - s_sum) / ua[s_index]);
			}
			t2 = t_sum+t1;//�г����﹩������ʱ�伴����ʱ��

			int t3 = t2+power_l / v[s_index];//�ر�ʱ��

			//����ȷ������������,�����������������
			int power_num;
			if (power_s[i] % 500 <= 167)
				power_num = 1;
			else if (power_s[i] % 500 >= 167 && power_s[i] % 500 <= 334)
				power_num = 2;
			else
				power_num = 3;

			//����ָ�����
			String^order1 = create_order("����������",power_num);
			String^order2 = create_order("�ع�������", power_num);
			array<String^>^str1 = gcnew array < String^ > {modelname, "p", "��������", "����֡", t2.ToString(), order1, "������������"};
			array<String^>^str2 = gcnew array < String^ > {modelname, "p", "��������", "����֡", t3.ToString(), order2, "�رչ�������"};
			store_data(str1);
			store_data(str2);
		}
	}

	//
	//���ɿ�������ָ���
	//

	public:void time_table(void)
	{
		//���ԭ�����ݱ�
		Conn->ConnectionString = "server=localhost;Initial Catalog=RunDB2;Integrated Security=True;";
		String^strcmd = "DELETE FROM controlTable";
		Data::SqlClient::SqlCommand ^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);
		Conn->Open();
		cmd->ExecuteNonQuery();
		Conn->Close();

		get_data();
		get_light_s();
		getpower_t();
		int uspeed_t;//���ٶ���ʱ
		int dspeed_t;//���ٶ���ʱ
		int kspeed_t;//���ٶ���ʱ

		int run_t;//����ʱ��
		int stop_t;//����ʱ��
		int arrive_t;//��վʱ��
		int sum_t = 0;//������ʱ��
		int s_sum=0;
		
		for (int i=0; i < s->Length; i++)
		{
			String^astr = "�г�����";
			String^bstr="�г���վ";
			String^cstr;

			//�жϸ�λ���Ƿ��Ǻ��̵�
			s_sum += s[i];
			for (int j=0; j < light_s->Length; j++)
			{
				if (s_sum == light_s[j])
				{
					astr = "���̵Ƽ���";
					bstr = "���̵Ƶȴ�";
					break;
				}
			}
			

			//�ж��г���ʻ����
			if (s_sum>=waylength/2)
				cstr = "�������";
			else
				cstr = "����";

			//�������ʱ���
			uspeed_t = v[i] / ua[i];//���ٶ���ʱ
			dspeed_t = v[i] / da[i];//���ٶ���ʱ
			kspeed_t = (s[i] - 0.5*v[i] * uspeed_t - 0.5*v[i] * dspeed_t) / v[i];//���ٶ���ʱ

			run_t = sum_t;//����ʱ��
			stop_t = sum_t + kspeed_t + uspeed_t;//����ʱ��
			arrive_t = sum_t + uspeed_t + kspeed_t + dspeed_t;//��վʱ��
			if (i!=s->Length-1)
				sum_t = sum_t + uspeed_t + kspeed_t + dspeed_t + staytime[i];

			String^order1 = create_order(cstr, i);
			array<String^>^str1 = gcnew array < String^ > {modelname, "h", "��", "����֡", run_t.ToString(), order1, "�г�����"};
			store_data(str1);

			String^order2 = create_order("����",i);
			array<String^>^str2 = gcnew array < String^ > {modelname, "h", "��", "����֡", stop_t.ToString(), order2, astr};
			store_data(str2);

			array<String^>^str3 = gcnew array < String^ > {modelname, "h", "��", "��", arrive_t.ToString(), "-----", bstr};
			store_data(str3);
		}

	}


private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
	//����ָ��ʱ���
	time_table();
	modelnametextBox->Text = modelname;
	trainnametextBox->Text = trainname;
	waynametextBox->Text = wayname;
	runwaytextBox->Text = "�Զ�˫��";
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
		 
//////////////������ť�����п�ʼ///////////////////	

		public:DateTime^runtime ;//����ʱ��
		public:int index = 0;//���ݼ�¼����
		public:int stop_index = 0;//վ������
		public:int people_num=0;//�˿���
		public:DateTime store_time;//��ʾ��һ���������ݿ��м�¼��ʱ��
		public:int zhangdianbianhao = 1;//վ���Ŵ�1��ʼ

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (connected == true)
	{
		//�ں���Ϊ0ʱִ�г����Է�ֹʱ��ȶԵĴ���
		while (1)
		{
			DateTime^ time = DateTime::Now;
			if (time->Millisecond <= 200)
				break;
		}
		label10->BackColor = System::Drawing::Color::Lime;
		//���Ϳ�ʼ�ɼ�ָ��
		sendorder(create_order("��ʼ����", 0));

			//��ʼ�ϳ�����
			people_num = geton_num[0]-getoff_num[0];
			store_time = DateTime::Now;//��һ�����ݼ�¼ʱ��
			Conn->ConnectionString = "server=localhost;Initial Catalog=RunDB2;Integrated Security=True;";

			String^strcmd = String::Format("INSERT INTO peopletable (�������,��·���,�г����,վ����,��վʱ��,��վʱ��,�ϳ�����,�³�����,��������,ʱ����,վ����) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}','{6}','{7}','{8}','{9}','{10}')", modelname, wayname, trainname, stopname[0], DateTime::Now.ToString(), DateTime::Now.ToString(), geton_num[0].ToString(), getoff_num[0].ToString(), people_num.ToString(), "0",zhangdianbianhao.ToString());

			Data::SqlClient::SqlCommand ^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);
			Conn->Open();
			cmd->ExecuteNonQuery();
			Conn->Close();

		//����ָ�����ʾ
		ListViewItem^sendcollectitem = gcnew ListViewItem("ģ�͵糵");
		sendcollectitem->SubItems->Add("����֡");
		sendcollectitem->SubItems->Add(DateTime::Now.ToString());
		sendcollectitem->SubItems->Add(create_order("��ʼ����", 0));
		sendcollectitem->SubItems->Add("��ʼ����");
		sendcollectitem->BackColor = System::Drawing::Color::WhiteSmoke;
		listView1->Items->Add(sendcollectitem);

		ListViewItem^sendlightitem = gcnew ListViewItem("���̵�");
		sendlightitem->SubItems->Add("����֡");
		sendlightitem->SubItems->Add(DateTime::Now.ToString());
		sendlightitem->SubItems->Add(create_order("�����̵�", 0));
		sendlightitem->SubItems->Add("���������ú��̵�");
		sendlightitem->BackColor = System::Drawing::Color::WhiteSmoke;
		listView1->Items->Add(sendlightitem);

		Conn->ConnectionString = "server=localhost;Database=RunDB2;UID=sa;PWD=123456;";
		String^strcmd1 = String::Format("SELECT * FROM controlTable WHERE ������� = '{0}'ORDER BY CAST(����ʱ�� AS INT)", modelname);//��ʱ��˳��ȡ���ݱ�����
		Data::SqlClient::SqlCommand ^ cmd1 = gcnew Data::SqlClient::SqlCommand(strcmd1, Conn);
		Conn->Open();
		Adapter->SelectCommand = cmd1;
		Adapter->Fill(dataSet1, "controlTable");
		Conn->Close();
		for (int i = 0; i < dataSet1->Tables["controlTable"]->Rows->Count; i++)
		{
			DataRow^ row = dataSet1->Tables["controlTable"]->Rows[i];
			ListViewItem^senditem = gcnew ListViewItem(row["�豸����"]->ToString());
			senditem->SubItems->Add(row["ָ������"]->ToString());
			int second = Int32::Parse(row["����ʱ��"]->ToString());
			DateTime^time = DateTime::Now.AddSeconds(second);
			senditem->SubItems->Add(time->ToString());
			senditem->SubItems->Add(row["ָ������"]->ToString());
			senditem->SubItems->Add(row["����"]->ToString());
			listView1->Items->Add(senditem);
		}
		
		//������ʱ��
		timer1->Interval = 100;
		timer1->Enabled = true;
		menuStrip1->Enabled = true;
		sendorder(create_order("�����̵�", 0));
		runtime = DateTime::Now;
		timer1->Start();

		stopbutton->Enabled = true;

		//�������ݲ�����������
		timer3->Enabled = true;
		timer3->Start();
	}
	else
		MessageBox::Show("������ģ�͵糵��");
}

////////////��ʱ������////////////

		public:int s_index=-1;//�����������
		public:DateTime go_time;//�������ʱ��
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	//��ȡ��ǰʱ��
	DateTime nowtime = DateTime::Now;

	//����ʱ��ڵ�
	DataRow^row=dataSet1->Tables["controlTable"]->Rows[index];
	int length = dataSet1->Tables["controlTable"]->Rows->Count;
	int second = Int32::Parse(row["����ʱ��"]->ToString());
	DateTime^time = runtime->AddSeconds(second);

	//�ȶ�ʱ��ʵ�ֶ�ʱ��������
	if ( nowtime.ToString("yyyyMMdd HH:mm:ss") == time->ToString("yyyyMMdd HH:mm:ss"))
	{ 
		listView1->Items[index + 2]->BackColor = System::Drawing::Color::WhiteSmoke;
		if (row["ָ������"]->ToString()->TrimEnd() == "-----")
		{
			IsStop = true;
			if (row["����"]->ToString()->TrimEnd() == "�г���վ")
			{
				//��վ���³���������
				people_num = people_num - getoff_num[stop_index + 1] + geton_num[stop_index + 1];
				DateTime^arrive_time = nowtime;
				DateTime^leave_time;
				String^leave_timestr;
				if (stop_index < stopstaytime->Length)
				{
					leave_time = arrive_time->AddSeconds(stopstaytime[stop_index]);
					leave_timestr = leave_time->ToString();
				}//��վʱ��
				else
					leave_timestr = " ";
				String^name = stopname[stop_index+1];
				TimeSpan ts = nowtime.Subtract(store_time);
				int t_change = ts.TotalSeconds;//���¼���ʱ����

				//��¼վ���ţ�����1��2��3��2��1
				zhangdianbianhao++;

				//����˿����ݱ�
				Conn->ConnectionString = "server=localhost;Initial Catalog=RunDB2;Integrated Security=True;";

				String^strcmd = String::Format("INSERT INTO peopletable (�������,��·���,�г����,վ����,��վʱ��,��վʱ��,�ϳ�����,�³�����,��������,ʱ����,վ����) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}','{6}','{7}','{8}','{9}','{10}')", modelname, wayname, trainname, name, arrive_time->ToString(), leave_timestr, geton_num[stop_index + 1].ToString(), getoff_num[stop_index + 1].ToString(), people_num.ToString(), t_change,zhangdianbianhao.ToString());

				Data::SqlClient::SqlCommand ^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);
				Conn->Open();
				cmd->ExecuteNonQuery();
				Conn->Close();

				//�����¼ʱ�䣬���ڼ���ʱ����
				store_time = nowtime;
				stop_index++;
			}
		}
		else
		{
			String^order = row["ָ������"]->ToString();
			sendorder(order);
			if (row["����"]->ToString()->TrimEnd() == "�г�����")
			{
				IsStop = false;
				s_index++;
				go_time = nowtime;
			}
		} 
		index++;

		//�ж��Ƿ�Ϊ���һ��ָ��
		if (index == length)
		{
			timer1->Stop();//�رռ�ʱ��
			timer3->Stop();//�رշ����ʱ��
			stopbutton->Enabled = false;
			label10->BackColor = System::Drawing::Color::Red;
			sendorder(create_order("��������", 0));
			MessageBox::Show("���н���������ͳ�����ݣ�");
			//stop_num
			CalculatePowerDissipation(modelname);
			CalculatePeopleFlow(modelname,stop_num);
		}
	}
}

	//��������
	public:int send_num = 0;//����֡��
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
			//�ȴ���λ���Ż��źţ�������
			//while (errorflag==-1)
			//{
			//	if (errorflag== 1)//����
			//	{
			//		newclient->Send(orderbyte);
			//		errorflag = -1;
			//	}
			//	else if (errorflag == 0)//��ȷ
			//		break;
			//}
			//errorflag = -1;
			send_num++;
			sendnumtextBox->Text = send_num.ToString();
		}
		catch (SocketException ^e)
		{
			label10->BackColor = System::Drawing::Color::Red;
			MessageBox::Show("����ʧ�ܣ������豸��" + e->Message);
			return;
		}
	}
	//��������
	//public:int errorflag=-1;//�����־����ʼΪ-1����ȷ����Ϊ1������Ϊ0
	public:int receive_num = 0;//����֡��
	public:void ReceiveMsg()
	{
		while (true)
		{
			DateTime receivetime = DateTime::Now;
			array<Byte>^ data = gcnew array<Byte>(1024);//�������ݽ�������  
			newclient->Receive(data);//�������ݵ�data����  

			//�����ж���λ�����������Ƿ���ȷ
			/*if (data[0] = 0xFF)
				errorflag = 1;
			else
				errorflag = 0;*/

			int length = data[2];//��ȡ���ݳ���  
			array<Byte>^ datashow = gcnew array<Byte>(length);
			for (int i = 0; i < length; i++)//��Ҫ��ʾ�����ݴ�ŵ�����datashow��  
				datashow[i] = data[i];
			if (datashow[0] == 0x00)
			{
				String^ stringdata = BitConverter::ToString(datashow);//������ת����16�����ַ���  
				String^sb;//�ж��豸
				if (datashow[1] == 0x02)
					sb = "�糵ģ��";
				else if (datashow[1] == 0x03)
					sb = "���ģ��";
				MyInvoke^ mi = gcnew MyInvoke(this, &Form1::showtext);
				this->Invoke(mi, stringdata, sb);//���߳�����ÿؼ���ʾ
				getmsg(datashow,receivetime);
			}
			receive_num++;
			receivenumtextBox->Text = receive_num.ToString();
		}
	}
	//��ȡ�������ݲ����
	private:int monitorone_pass = 0;
			int monitortwo_pass = 0;
			int monitorthree_pass = 0;
			int powerpassnum=0;//������������Ĵ���
	public:SqlConnection^getConn = gcnew SqlConnection();//�������ݿ�����
	public:void getmsg(array<Byte>^buffer,DateTime time)
	{
		String^strcmd;
		String^str = "����";
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

		if (buffer[1] == 0x02)//�糵ģ��
		{
			car_a = buffer[4] + buffer[5] / 10;
			int n = buffer[7] + buffer[8] / 10;//���ص�ת��
			car_v = (2 * 3.14) / 60*n*0.014*ratio;
			//car_I = buffer[10] + buffer[11] / 10;
			//car_V = buffer[13] + buffer[14] / 10;
			car_I = 20 + rand() % (20 - 30 + 1);
			car_V = 80 + rand() % (80 - 90 + 1);
			car_position = integral_getposition(time, car_v);
			double t = 1/getdata_f;
			if (stop_index>0.5*stopname->Length)//�жϷ���
				str = "����";
			strcmd = String::Format("INSERT INTO trainTable (�������,��·���,�г����,��ʻ����,ʱ��,�ٶ�,���ٶ�,����,��ѹ,λ��,ʱ����) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}','{6}','{7}','{8}','{9}','{10}')", modelname, wayname, trainname, str, time.ToString(), (car_v*3.6).ToString("f1"), car_a.ToString("f1"), car_I.ToString("f1"), car_V.ToString("f1"),car_position.ToString("f1"),t.ToString("f1"));
		}
		if (buffer[1] == 0x03)
		{
			if (buffer[3] == 0x25)//��������
			{
				power_number = buffer[4] ;
				powerpassnum++;
				power_I = buffer[6]  + (buffer[7] ) / 10;
				power_V = buffer[9]  + (buffer[10] ) / 10;
				strcmd = String::Format("INSERT INTO powerTable (�������,��·���,ʱ��,����������,����,��ѹ) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}')", modelname, wayname, time.ToString(),power_name[powerpassnum-1],power_I.ToString("f1"),power_V.ToString("f1"));
			}
			else if (buffer[3] == 0x27)//����
			{
				if (buffer[5] == 0x01)
				{
					monitor_number = buffer[4] ;
					monitor_open = 1;
					adjust_position = getadjustposition(monitor_number);
					iposition = adjust_position;//λ��У��
					strcmd = String::Format("INSERT INTO monitorTable (�������,��·���,ʱ��,������,״̬,У��λ��) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}')", modelname, wayname, time.ToString(), monitor_number.ToString(), monitor_open.ToString(), adjust_position.ToString("f1"));
				}
			}
		}
		
		getConn->ConnectionString = "server=localhost;Initial Catalog=RunDB2;Integrated Security=True;";
		Data::SqlClient::SqlCommand ^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, getConn);
		getConn->Open();
		cmd->ExecuteNonQuery();
		getConn->Close();
	}


	//���ַ���ȡλ�ú���
	public:double iposition=0;
	public:double integral_getposition(DateTime time,double v_get)
	{
		if (v_get == 0)//�ٶ�Ϊ0������ͣ��״̬
		{
			int sum=0;
			for (int i; i <= s_index; i++)
				sum += s[i];
			iposition = sum;//λ��У��
		}
		else
		{
			iposition = iposition + v_get * 0.2;
		}
		return iposition ;
	}
	//���У��λ��
	public: double getadjustposition(Byte monitor_number)
	{
		double adjust_position = 0;
		switch (monitor_number)
		{
		case 0x00:
			if (stop_index <= 0.5*stopname->Length)//����
			{
				monitorone_pass++;
				adjust_position = monitor_one*ratio + 500 * (monitorone_pass - 1);
			}
			else if(stop_index > 0.5*stopname->Length)//����
			{
				adjust_position = waylength - (monitor_one*ratio + 500 * (monitorone_pass - 1));
				monitorone_pass--;
			}
			break;
		case 0x01:
			if (stop_index <= 0.5*stopname->Length)//����
			{
				monitortwo_pass++;
				adjust_position = monitor_two*ratio + 500 * (monitortwo_pass - 1);
			}
			else if (stop_index > 0.5*stopname->Length)//����
			{
				adjust_position = waylength - (monitor_two*ratio + 500 * (monitortwo_pass - 1));
				monitortwo_pass--;
			}
			break;
		case 0x02:
			if (stop_index <= 0.5*stopname->Length)//����
			{
				monitorthree_pass++;
				adjust_position = monitor_three*ratio + 500 * (monitorthree_pass - 1);
			}
			else if (stop_index > 0.5*stopname->Length)//����
			{
				adjust_position = waylength - (monitor_three*ratio + 500 * (monitorthree_pass - 1));
				monitorthree_pass--;
			}
			break;
		}
		return adjust_position;
	}
	//��ʾ��������
	public: void showtext(String ^msg, String^a)
	{

		//���߳����԰�ȫ��ʽ���ÿؼ�  
		ListViewItem^ receiveItem = gcnew ListViewItem(a);
		receiveItem->SubItems->Add("����֡");
		receiveItem->SubItems->Add(DateTime::Now.ToString());
		receiveItem->SubItems->Add(msg);
		listView2->Items->Add(receiveItem);
	}

private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	if (System::Windows::Forms::DialogResult::Yes == MessageBox::Show(L"ϵͳ�����У��Ƿ�Ͽ��������Ӳ��رճ��򣡣���", "ȷ��", MessageBoxButtons::YesNo))
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
			MessageBox::Show("����ʧ�������ԣ�" + e->Message);
			return;
		}
	}
}

private: System::Void �ٶȼ��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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
	int port = Int32::Parse(porttextBox->Text);//��ȡ�˿ں�
	String^ipadd = maskedTextBox1->Text->Replace(" ", "");//��ȡIP
	IPEndPoint^ie = gcnew IPEndPoint(IPAddress::Parse(ipadd), port);
	newclient = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);

	try
	{
		newclient->Connect(ie);
		connected = true;
		label12->BackColor = System::Drawing::Color::Lime;
		button1->Enabled = true;
		//array<Byte>^byte = gcnew array < Byte > {0x00,0x00,0x00,0x00,0x00,0x00,0x00};
		//newclient->Send(byte);//����7���ֽ�������λ��
	}
	catch (SocketException ^e)
	{
		MessageBox::Show("���Ӳ���ģ�͵糵�������豸��" + e->Message);
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
		MessageBox::Show("�ѶϿ����ӣ�");
	}
	connected = false;
}

private: System::Void stopbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	//����ʱ��Ч�����º󵯳�ѯ�ʴ��ڣ�ȷ�Ϻ�ֹͣ���в�ɾ��������������
	if (System::Windows::Forms::DialogResult::Yes == MessageBox::Show(L"�й�糵�������У��Ƿ��жϱ������в�ɾ���������ݣ�����", "ȷ��", MessageBoxButtons::YesNo))
	{
		try
		{
			sendorder(create_order("����", 1));//ֹͣ�糵ģ��
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
			//ɾ����������
			array<String^>^ tablename = gcnew array<String^>{ "peopleTable","trainTable","powerTable","monitorTable"};
			Conn->ConnectionString = "server=localhost;Initial Catalog=RunDB2;Integrated Security=True;";
			Conn->Open();
			for (int i; i < tablename->Length; i++)
			{
				String^strcmd = String::Format("DELETE  FROM {0} WHERE ������� = '{1}'", tablename[i],modelname);
				Data::SqlClient::SqlCommand ^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);
				cmd->ExecuteNonQuery();
			}
			Conn->Close();
			MessageBox::Show("��ֹͣ���У�");
		}
		catch (SqlException ^e)
		{
			MessageBox::Show("����ʧ�������ԣ�" + e->Message);
			return;
		}
	}
}
		 //���ڵ���ʱ������������
		 public:int S1=0;
		public: bool IsStop;
private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
	int Vtest = 80 + rand() % (80 - 90 + 1);
	int Itest = 20 + rand() % (20 - 30 + 1);
	int vtest = 0;
	int atest = 0;
	vtest = 40 + rand() % (40 - 120 + 1);
	atest = 0 + rand() % (0 - 30 + 1);
	String^ str="����" ;
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
		str = "����";
	}
	
	if (S1 <= waylength)
	{
		if (S1 <= 0.5*waylength)
			str = "����";
		else
			str = "����";
		Conn->ConnectionString = "server=localhost;Initial Catalog=RunDB2;Integrated Security=True;";
		String^strcmd = String::Format("INSERT INTO traintable (�������,��·���,�г����,��ʻ����,ʱ��,�ٶ�,���ٶ�,����,��ѹ,λ��,ʱ����) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}','{6}','{7}','{8}','{9}','{10}')", modelname, wayname, trainname, str, DateTime::Now.ToString(), vtest.ToString(), atest.ToString(), Itest.ToString(), Vtest.ToString(), S1.ToString(), "1");
		Data::SqlClient::SqlCommand ^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);

		String^strcmd1 = String::Format("INSERT INTO powerTable (�������,��·���,ʱ��,����������,����,��ѹ) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}')", modelname, wayname,DateTime::Now.ToString(),"Q001",Itest.ToString(), Vtest.ToString());
		Data::SqlClient::SqlCommand ^ cmd1 = gcnew Data::SqlClient::SqlCommand(strcmd1, Conn);
		Conn->Open();
		cmd->ExecuteNonQuery();
		cmd1->ExecuteNonQuery();
		Conn->Close();
	}
	else
	{
		timer3->Stop();
		MessageBox::Show("�������");
		timer3->Enabled = false;
	}
}
private: System::Void �糵������ѹ���ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	trainVIForm^ trainVIform = gcnew trainVIForm();
	trainVIform->modelname = this->modelname;
	trainVIform->trainname = this->trainname;
	trainVIform->wayname = this->wayname;
	trainVIform->Show();
}
private: System::Void �������������ѹ���ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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
private: System::Void ʵʱվ����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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

