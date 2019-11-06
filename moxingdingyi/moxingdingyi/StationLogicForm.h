#pragma once
//#include "StationOpenGL.h"
#include"StraightLinePaint.h"
namespace moxingdingyi {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace StationOpenGLForm;//增加
	using namespace StraightPaintForm;
	//新增
	using namespace System::Data::SqlClient;
	using namespace System::Threading;
	using namespace System::Collections::Generic;

	/// <summary>
	/// StationLogicForm 摘要
	/// </summary>
	public ref class StationLogicForm : public System::Windows::Forms::Form
	{
	public:
		StationLogicForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
			OpenGL = gcnew StraightLinePaint(this, 1300, 700,4,10);
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~StationLogicForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ProjectChoicetoolStripMenuItem1;
	private: System::Windows::Forms::ToolStripComboBox^  RoadChoicetoolStripComboBox1;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox1;
	private: System::Windows::Forms::ToolStripComboBox^  ChooseVelocitytoolStripComboBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  RunOrStoptoolStripMenuItem1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ComboBox^  ChooseTramcomboBox1;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RadioButton^  SysradioButton3;

	private: System::Windows::Forms::RadioButton^  MakeProjectradioButton2;

	private: System::Windows::Forms::RadioButton^  RepeatradioButton1;
	private: System::Windows::Forms::RichTextBox^  TramInforichTextBox1;
	private: System::Windows::Forms::TextBox^  PeopOnTramtextBox2;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  RegiontextBox6;

	private: System::Windows::Forms::TextBox^  PostextBox5;

	private: System::Windows::Forms::TextBox^  NextStationtextBox4;

	private: System::Windows::Forms::TextBox^  EmptyRatetextBox3;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  AcceleratetextBox11;

	private: System::Windows::Forms::TextBox^  VelocitytextBox10;


	private: System::Windows::Forms::TextBox^  VoltagetextBox9;

	private: System::Windows::Forms::TextBox^  CurrenttextBox8;

	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label14;


	private: System::Windows::Forms::Label^  iffinishlabel22;
	private: System::Windows::Forms::Label^  label20;





	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		//System::ComponentModel::Container ^components;
		StraightPaintForm::StraightLinePaint ^ OpenGL;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RoadChoicetoolStripComboBox1 = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->ProjectChoicetoolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripTextBox1 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->ChooseVelocitytoolStripComboBox1 = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->RunOrStoptoolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->TramInforichTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->ChooseTramcomboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SysradioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->MakeProjectradioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->RepeatradioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->RegiontextBox6 = (gcnew System::Windows::Forms::TextBox());
			this->PostextBox5 = (gcnew System::Windows::Forms::TextBox());
			this->NextStationtextBox4 = (gcnew System::Windows::Forms::TextBox());
			this->EmptyRatetextBox3 = (gcnew System::Windows::Forms::TextBox());
			this->AcceleratetextBox11 = (gcnew System::Windows::Forms::TextBox());
			this->VelocitytextBox10 = (gcnew System::Windows::Forms::TextBox());
			this->VoltagetextBox9 = (gcnew System::Windows::Forms::TextBox());
			this->CurrenttextBox8 = (gcnew System::Windows::Forms::TextBox());
			this->PeopOnTramtextBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->iffinishlabel22 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &StationLogicForm::timer1_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->toolStripMenuItem1,
					this->RoadChoicetoolStripComboBox1, this->ProjectChoicetoolStripMenuItem1, this->toolStripTextBox1, this->ChooseVelocitytoolStripComboBox1,
					this->RunOrStoptoolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1292, 29);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Enabled = false;
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(68, 25);
			this->toolStripMenuItem1->Text = L"线路选择";
			// 
			// RoadChoicetoolStripComboBox1
			// 
			this->RoadChoicetoolStripComboBox1->Name = L"RoadChoicetoolStripComboBox1";
			this->RoadChoicetoolStripComboBox1->Size = System::Drawing::Size(121, 25);
			this->RoadChoicetoolStripComboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &StationLogicForm::RoadChoiceChanged);
			// 
			// ProjectChoicetoolStripMenuItem1
			// 
			this->ProjectChoicetoolStripMenuItem1->Name = L"ProjectChoicetoolStripMenuItem1";
			this->ProjectChoicetoolStripMenuItem1->Size = System::Drawing::Size(104, 25);
			this->ProjectChoicetoolStripMenuItem1->Text = L"下拉：方案选择";
			// 
			// toolStripTextBox1
			// 
			this->toolStripTextBox1->Enabled = false;
			this->toolStripTextBox1->Name = L"toolStripTextBox1";
			this->toolStripTextBox1->ReadOnly = true;
			this->toolStripTextBox1->Size = System::Drawing::Size(100, 25);
			this->toolStripTextBox1->Text = L"调整整体运行速度";
			// 
			// ChooseVelocitytoolStripComboBox1
			// 
			this->ChooseVelocitytoolStripComboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"原速", L"加快2倍速", L"加快5倍速",
					L"加快10倍速", L"减慢1.5倍速", L"减慢2倍速"
			});
			this->ChooseVelocitytoolStripComboBox1->Name = L"ChooseVelocitytoolStripComboBox1";
			this->ChooseVelocitytoolStripComboBox1->Size = System::Drawing::Size(121, 25);
			this->ChooseVelocitytoolStripComboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &StationLogicForm::VelocityChanged);
			// 
			// RunOrStoptoolStripMenuItem1
			// 
			this->RunOrStoptoolStripMenuItem1->Name = L"RunOrStoptoolStripMenuItem1";
			this->RunOrStoptoolStripMenuItem1->Size = System::Drawing::Size(68, 25);
			this->RunOrStoptoolStripMenuItem1->Text = L"开始运行";
			this->RunOrStoptoolStripMenuItem1->Click += gcnew System::EventHandler(this, &StationLogicForm::RunOrStoptoolStripMenuItem1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::White;
			this->groupBox1->Controls->Add(this->TramInforichTextBox1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->ChooseTramcomboBox1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->SysradioButton3);
			this->groupBox1->Controls->Add(this->MakeProjectradioButton2);
			this->groupBox1->Controls->Add(this->RepeatradioButton1);
			this->groupBox1->Location = System::Drawing::Point(1129, 32);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(151, 497);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"调整框";
			// 
			// TramInforichTextBox1
			// 
			this->TramInforichTextBox1->BackColor = System::Drawing::Color::White;
			this->TramInforichTextBox1->Location = System::Drawing::Point(6, 244);
			this->TramInforichTextBox1->Name = L"TramInforichTextBox1";
			this->TramInforichTextBox1->ReadOnly = true;
			this->TramInforichTextBox1->Size = System::Drawing::Size(139, 247);
			this->TramInforichTextBox1->TabIndex = 4;
			this->TramInforichTextBox1->Text = L"";
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(0, 114);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(151, 2);
			this->textBox1->TabIndex = 3;
			// 
			// ChooseTramcomboBox1
			// 
			this->ChooseTramcomboBox1->FormattingEnabled = true;
			this->ChooseTramcomboBox1->Location = System::Drawing::Point(8, 184);
			this->ChooseTramcomboBox1->Name = L"ChooseTramcomboBox1";
			this->ChooseTramcomboBox1->Size = System::Drawing::Size(137, 20);
			this->ChooseTramcomboBox1->Sorted = true;
			this->ChooseTramcomboBox1->TabIndex = 2;
			this->ChooseTramcomboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &StationLogicForm::ChooseTramcomboBox1_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(17, 229);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 12);
			this->label3->TabIndex = 1;
			this->label3->Text = L"车次信息";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 159);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 12);
			this->label2->TabIndex = 1;
			this->label2->Text = L"选择车次";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 128);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"查看车次信息";
			// 
			// SysradioButton3
			// 
			this->SysradioButton3->AutoSize = true;
			this->SysradioButton3->Location = System::Drawing::Point(19, 75);
			this->SysradioButton3->Name = L"SysradioButton3";
			this->SysradioButton3->Size = System::Drawing::Size(95, 16);
			this->SysradioButton3->TabIndex = 0;
			this->SysradioButton3->Text = L"实时显示模式";
			this->SysradioButton3->UseVisualStyleBackColor = true;
			this->SysradioButton3->CheckedChanged += gcnew System::EventHandler(this, &StationLogicForm::ModeChanged);
			// 
			// MakeProjectradioButton2
			// 
			this->MakeProjectradioButton2->AutoSize = true;
			this->MakeProjectradioButton2->Location = System::Drawing::Point(19, 53);
			this->MakeProjectradioButton2->Name = L"MakeProjectradioButton2";
			this->MakeProjectradioButton2->Size = System::Drawing::Size(155, 16);
			this->MakeProjectradioButton2->TabIndex = 0;
			this->MakeProjectradioButton2->Text = L"方案定制模式（未完成）";
			this->MakeProjectradioButton2->UseVisualStyleBackColor = true;
			// 
			// RepeatradioButton1
			// 
			this->RepeatradioButton1->AutoSize = true;
			this->RepeatradioButton1->Checked = true;
			this->RepeatradioButton1->Location = System::Drawing::Point(19, 31);
			this->RepeatradioButton1->Name = L"RepeatradioButton1";
			this->RepeatradioButton1->Size = System::Drawing::Size(95, 16);
			this->RepeatradioButton1->TabIndex = 0;
			this->RepeatradioButton1->TabStop = true;
			this->RepeatradioButton1->Text = L"即放即行模式";
			this->RepeatradioButton1->UseVisualStyleBackColor = true;
			this->RepeatradioButton1->CheckedChanged += gcnew System::EventHandler(this, &StationLogicForm::ModeChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::White;
			this->groupBox2->Controls->Add(this->chart1);
			this->groupBox2->Controls->Add(this->textBox12);
			this->groupBox2->Controls->Add(this->textBox7);
			this->groupBox2->Controls->Add(this->RegiontextBox6);
			this->groupBox2->Controls->Add(this->PostextBox5);
			this->groupBox2->Controls->Add(this->NextStationtextBox4);
			this->groupBox2->Controls->Add(this->EmptyRatetextBox3);
			this->groupBox2->Controls->Add(this->AcceleratetextBox11);
			this->groupBox2->Controls->Add(this->VelocitytextBox10);
			this->groupBox2->Controls->Add(this->VoltagetextBox9);
			this->groupBox2->Controls->Add(this->CurrenttextBox8);
			this->groupBox2->Controls->Add(this->PeopOnTramtextBox2);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label19);
			this->groupBox2->Controls->Add(this->label18);
			this->groupBox2->Controls->Add(this->label17);
			this->groupBox2->Controls->Add(this->label16);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label15);
			this->groupBox2->Controls->Add(this->label14);
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Controls->Add(this->iffinishlabel22);
			this->groupBox2->Controls->Add(this->label20);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Location = System::Drawing::Point(12, 535);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(1268, 194);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"信息框";
			// 
			// chart1
			// 
			chartArea1->AxisX->ScrollBar->Enabled = false;
			chartArea1->AxisX->Title = L"时间/t";
			chartArea1->AxisX->TitleAlignment = System::Drawing::StringAlignment::Far;
			chartArea1->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Rotated270;
			chartArea1->AxisY->Title = L"速度m/s";
			chartArea1->AxisY->TitleAlignment = System::Drawing::StringAlignment::Near;
			chartArea1->BackColor = System::Drawing::Color::Transparent;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			legend1->TitleAlignment = System::Drawing::StringAlignment::Far;
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(457, 13);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->IsValueShownAsLabel = true;
			series1->Legend = L"Legend1";
			series1->MarkerBorderColor = System::Drawing::Color::Aqua;
			series1->MarkerColor = System::Drawing::Color::White;
			series1->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series1->Name = L"实时速度m/s";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(805, 175);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			// 
			// textBox12
			// 
			this->textBox12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox12->Location = System::Drawing::Point(449, 7);
			this->textBox12->Multiline = true;
			this->textBox12->Name = L"textBox12";
			this->textBox12->ReadOnly = true;
			this->textBox12->Size = System::Drawing::Size(2, 185);
			this->textBox12->TabIndex = 1;
			// 
			// textBox7
			// 
			this->textBox7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox7->Location = System::Drawing::Point(211, 7);
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(2, 185);
			this->textBox7->TabIndex = 1;
			// 
			// RegiontextBox6
			// 
			this->RegiontextBox6->Location = System::Drawing::Point(77, 162);
			this->RegiontextBox6->Name = L"RegiontextBox6";
			this->RegiontextBox6->Size = System::Drawing::Size(94, 21);
			this->RegiontextBox6->TabIndex = 1;
			// 
			// PostextBox5
			// 
			this->PostextBox5->Location = System::Drawing::Point(77, 123);
			this->PostextBox5->Name = L"PostextBox5";
			this->PostextBox5->Size = System::Drawing::Size(94, 21);
			this->PostextBox5->TabIndex = 1;
			// 
			// NextStationtextBox4
			// 
			this->NextStationtextBox4->Location = System::Drawing::Point(77, 90);
			this->NextStationtextBox4->Name = L"NextStationtextBox4";
			this->NextStationtextBox4->Size = System::Drawing::Size(94, 21);
			this->NextStationtextBox4->TabIndex = 1;
			// 
			// EmptyRatetextBox3
			// 
			this->EmptyRatetextBox3->Location = System::Drawing::Point(77, 55);
			this->EmptyRatetextBox3->Name = L"EmptyRatetextBox3";
			this->EmptyRatetextBox3->Size = System::Drawing::Size(94, 21);
			this->EmptyRatetextBox3->TabIndex = 1;
			// 
			// AcceleratetextBox11
			// 
			this->AcceleratetextBox11->Location = System::Drawing::Point(287, 123);
			this->AcceleratetextBox11->Name = L"AcceleratetextBox11";
			this->AcceleratetextBox11->Size = System::Drawing::Size(94, 21);
			this->AcceleratetextBox11->TabIndex = 1;
			// 
			// VelocitytextBox10
			// 
			this->VelocitytextBox10->Location = System::Drawing::Point(287, 90);
			this->VelocitytextBox10->Name = L"VelocitytextBox10";
			this->VelocitytextBox10->Size = System::Drawing::Size(94, 21);
			this->VelocitytextBox10->TabIndex = 1;
			// 
			// VoltagetextBox9
			// 
			this->VoltagetextBox9->Location = System::Drawing::Point(287, 55);
			this->VoltagetextBox9->Name = L"VoltagetextBox9";
			this->VoltagetextBox9->Size = System::Drawing::Size(94, 21);
			this->VoltagetextBox9->TabIndex = 1;
			// 
			// CurrenttextBox8
			// 
			this->CurrenttextBox8->Location = System::Drawing::Point(287, 20);
			this->CurrenttextBox8->Name = L"CurrenttextBox8";
			this->CurrenttextBox8->Size = System::Drawing::Size(94, 21);
			this->CurrenttextBox8->TabIndex = 1;
			// 
			// PeopOnTramtextBox2
			// 
			this->PeopOnTramtextBox2->Location = System::Drawing::Point(77, 20);
			this->PeopOnTramtextBox2->Name = L"PeopOnTramtextBox2";
			this->PeopOnTramtextBox2->Size = System::Drawing::Size(94, 21);
			this->PeopOnTramtextBox2->TabIndex = 1;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 171);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(53, 12);
			this->label7->TabIndex = 0;
			this->label7->Text = L"当前区间";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 132);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(53, 12);
			this->label6->TabIndex = 0;
			this->label6->Text = L"当前位置";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 99);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(41, 12);
			this->label8->TabIndex = 0;
			this->label8->Text = L"下一站";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 64);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(65, 12);
			this->label5->TabIndex = 0;
			this->label5->Text = L"实时空载率";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(177, 126);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(11, 12);
			this->label11->TabIndex = 0;
			this->label11->Text = L"m";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(177, 58);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(11, 12);
			this->label10->TabIndex = 0;
			this->label10->Text = L"%";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(387, 126);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(47, 12);
			this->label19->TabIndex = 0;
			this->label19->Text = L"m/(s*s)";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(387, 93);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(23, 12);
			this->label18->TabIndex = 0;
			this->label18->Text = L"m/s";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(387, 58);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(11, 12);
			this->label17->TabIndex = 0;
			this->label17->Text = L"V";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(387, 23);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(11, 12);
			this->label16->TabIndex = 0;
			this->label16->Text = L"A";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(177, 23);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(17, 12);
			this->label9->TabIndex = 0;
			this->label9->Text = L"人";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(219, 132);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(65, 12);
			this->label15->TabIndex = 0;
			this->label15->Text = L"当前加速度";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(219, 99);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(53, 12);
			this->label14->TabIndex = 0;
			this->label14->Text = L"当前速度";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(219, 64);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(53, 12);
			this->label13->TabIndex = 0;
			this->label13->Text = L"电机电压";
			// 
			// iffinishlabel22
			// 
			this->iffinishlabel22->BackColor = System::Drawing::Color::Red;
			this->iffinishlabel22->Location = System::Drawing::Point(331, 168);
			this->iffinishlabel22->Name = L"iffinishlabel22";
			this->iffinishlabel22->Size = System::Drawing::Size(50, 15);
			this->iffinishlabel22->TabIndex = 0;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(219, 171);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(77, 12);
			this->label20->TabIndex = 0;
			this->label20->Text = L"是否到达终点";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(219, 28);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(53, 12);
			this->label12->TabIndex = 0;
			this->label12->Text = L"电机电流";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 28);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 12);
			this->label4->TabIndex = 0;
			this->label4->Text = L"车内人数";
			// 
			// StationLogicForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1292, 741);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"StationLogicForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"站点图";
			this->Load += gcnew System::EventHandler(this, &StationLogicForm::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:List<String^>^tram_to_index = gcnew List<String^>();
	private:bool timerflag = false;
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
	{
		//初始化方案选项卡
		this->RoadChoicetoolStripComboBox1->Items->Clear();
		String^selectsql = "SELECT DISTINCT 线路编号 FROM 线路信息;";
		DataTable^roadtb = ExecuteQuery(selectsql);
		for (int i = 0; i < roadtb->Rows->Count; i++)
		{
			this->RoadChoicetoolStripComboBox1->Items->Add(roadtb->Rows[i]->ItemArray[0]->ToString());
		}
		this->timer1->Stop();
	}
		 
			 //选择线路改变
private: System::Void RoadChoiceChanged(System::Object^  sender, System::EventArgs^  e) {
		//初始化线路字符编号
		OpenGL->line_num = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->RoadChoicetoolStripComboBox1->Text->Trim());//初始化opengl线路编号

		this->ProjectChoicetoolStripMenuItem1->DropDownItems->Clear();//****************************//全局变量需要清除，每次改变线路选择，该线路上的方案会改变
		if ((this->RoadChoicetoolStripComboBox1->SelectedIndex < 0) || (String::IsNullOrEmpty(this->RoadChoicetoolStripComboBox1->Text)))
			return;
		//挑选该线路下所有方案，并将方案编号放到下拉选项卡中供用户选择
		//即放即行模式
		if (this->RepeatradioButton1->Checked == true)
		{	
			OpenGL->runningMode = 0;//设置运行模式为即放即行
			String^selectsql = String::Format("SELECT 方案编号 FROM 方案信息 WHERE 线路编号='{0}';", this->RoadChoicetoolStripComboBox1->Text);
			DataTable^projecttb = ExecuteQuery(selectsql);
			for (int i = 0; i < projecttb->Rows->Count; i++)
			{
				System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
				toolstripmenuitem->Name = L"toolStripMenuTtem" + (i + 1).ToString();
				toolstripmenuitem->Size = System::Drawing::Size(152, 22);
				toolstripmenuitem->Text = projecttb->Rows[i]->ItemArray[0]->ToString();
				toolstripmenuitem->CheckOnClick = true;
				toolstripmenuitem->Checked = false;
				this->ProjectChoicetoolStripMenuItem1->DropDownItems->Add(toolstripmenuitem);
				toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &StationLogicForm::toolStripMenuItem_CheckedChanged);
			}
		}
		else if (this->SysradioButton3->Checked == true)//同步模式
		{	
			OpenGL->runningMode = 1;//设置模式为实时运行模式
			String^selectsql = String::Format("SELECT 方案编号 FROM 方案信息 WHERE 线路编号='{0}';", this->RoadChoicetoolStripComboBox1->Text);
			DataTable^projecttb = ExecuteQuery(selectsql);
			for (int i = 0; i < projecttb->Rows->Count; i++)
			{
				System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
				toolstripmenuitem->Name = L"toolStripMenuTtem" + (i + 1).ToString();
				toolstripmenuitem->Size = System::Drawing::Size(152, 22);
				toolstripmenuitem->Text = projecttb->Rows[i]->ItemArray[0]->ToString();
				toolstripmenuitem->CheckOnClick = true;
				toolstripmenuitem->Checked = false;
				this->ProjectChoicetoolStripMenuItem1->DropDownItems->Add(toolstripmenuitem);
				toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &StationLogicForm::SysMode_ItemCheckedChanged);
			}
		}
		//获取线路长度、站点信息
		OpenGL->DB_assign_value();
		//初始化线路数据
		OpenGL->initLine();
		//站点人数初始化
		OpenGL->initSitePeople();
	}
	//方案选项卡（选择运行方案）被选择的函数:即放即行模式
	private: System::Void toolStripMenuItem_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		System::Windows::Forms::ToolStripMenuItem^toolitem = safe_cast<System::Windows::Forms::ToolStripMenuItem^>(sender);
		if (toolitem->Checked == true)
		{
			String^selectsql = "SELECT 列车编号 FROM 方案信息 WHERE 方案编号='" + toolitem->Text->ToString() + "';";
			DataTable^tramnumtb = ExecuteQuery(selectsql);
			selectsql = "SELECT 行驶方向 FROM 列车信息 WHERE 列车编号='"+ tramnumtb->Rows[0]->ItemArray[0]->ToString()+"';";
			DataTable^dirtb = ExecuteQuery(selectsql);
			bool dirflag = false;
			//判断选择方案的方向
			if (String::Equals(dirtb->Rows[0]->ItemArray[0]->ToString()->Trim(), "正向"))
			{
				dirflag = true;
			}
			else
			{
				dirflag = false;
			}
			//初始化电车信息
			OpenGL->initTram(dirflag, tramnumtb->Rows[0]->ItemArray[0]->ToString(),toolitem->Text->ToString());
			tram_to_index->Add(toolitem->Text->Trim());
		}
		else
		{
			//去除一个运行方案
			int index1 = tram_to_index->IndexOf(toolitem->Text->ToString()->Trim());
			
			//更新电车索引--这里好像没用的
			for (int i = 0; i < OpenGL->trams->Count; i++)
			{
				OpenGL->trams[i]->tram_no = i + 1;
			}
			OpenGL->trams->RemoveAt(index1);
			tram_to_index->Remove(toolitem->Text->ToString()->Trim());
		}
		AddChoice(sender, e);
	}

		 //方案选项卡被选择的函数:同步模式
	private:System::Void SysMode_ItemCheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		System::Windows::Forms::ToolStripMenuItem^item = safe_cast<System::Windows::Forms::ToolStripMenuItem^>(sender);
		if (item->Checked == true)
		{
			for each (System::Windows::Forms::ToolStripMenuItem^item1 in this->ProjectChoicetoolStripMenuItem1->DropDownItems)
			{
				if (!String::Equals(item1->Text, sender->ToString()))
				{
					item1->Checked = false;//将其他所有不是当前选中方案去除，同步模式只能显示一辆电车
				}
			}

			if (item->Checked == true)
			{
				String^selectsql = "SELECT 列车编号 FROM 方案信息 WHERE 方案编号='" + item->Text->ToString() + "';";
				DataTable^tramnumtb = ExecuteQuery(selectsql);
				selectsql = "SELECT 行驶方向 FROM 列车信息 WHERE 列车编号='" + tramnumtb->Rows[0]->ItemArray[0]->ToString() + "';";
				DataTable^dirtb = ExecuteQuery(selectsql);
				bool dirflag = false;
				if (String::Equals(dirtb->Rows[0]->ItemArray[0]->ToString()->Trim(), "正向"))
				{
					dirflag = true;
				}
				else
				{
					dirflag = false;
				}
				//初始化电车信息
				OpenGL->SysMode_initTram(dirflag, tramnumtb->Rows[0]->ItemArray[0]->ToString(), item->Text->ToString());
				tram_to_index->Add(item->Text->Trim());
			}
			else if (item->Checked == false)//如果把节点删除
			{
				OpenGL->trams->RemoveAt(0);
				this->timer1->Stop();
			}
		}
		AddChoice(sender, e);
	}

			//往调整框中增加下拉选项
	private:System::Void AddChoice(System::Object^  sender, System::EventArgs^  e)
	{
		System::Windows::Forms::ToolStripMenuItem^item = safe_cast<System::Windows::Forms::ToolStripMenuItem^>(sender);
		if (item->Checked == true)
		{
			this->ChooseTramcomboBox1->Items->Add(item->Text->Trim());
		}
		else
		{
			this->ChooseTramcomboBox1->Items->Remove(item->Text->Trim());
		}
	}
			 //选择模式改变
private: System::Void ModeChanged(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Stop();//停掉站点图的绘制
	//初始化开始按钮状态及相关标志位

	OpenGL->trams->Clear();//清理掉电车信息
	this->ProjectChoicetoolStripMenuItem1->DropDownItems->Clear();//****************************//全局变量需要清除
	//挑选该线路下所有方案，并将方案编号放到下拉选项卡中供用户选择
		//即放即行模式
	if (this->RepeatradioButton1->Checked == true)
	{	
		OpenGL->runningMode = 0;
		String^selectsql = String::Format("SELECT 方案编号 FROM 方案信息 WHERE 线路编号='{0}';", this->RoadChoicetoolStripComboBox1->Text);
		DataTable^projecttb = ExecuteQuery(selectsql);
		for (int i = 0; i < projecttb->Rows->Count; i++)
		{
			System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
			toolstripmenuitem->Name = L"toolStripMenuTtem" + (i + 1).ToString();
			toolstripmenuitem->Size = System::Drawing::Size(152, 22);
			toolstripmenuitem->Text = projecttb->Rows[i]->ItemArray[0]->ToString();
			toolstripmenuitem->CheckOnClick = true;
			toolstripmenuitem->Checked = false;
			this->ProjectChoicetoolStripMenuItem1->DropDownItems->Add(toolstripmenuitem);
			toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &StationLogicForm::toolStripMenuItem_CheckedChanged);
		}
	}
	else if (this->SysradioButton3->Checked == true)//同步模式
	{
		OpenGL->runningMode = 1;
		String^selectsql = String::Format("SELECT 方案编号 FROM 方案信息 WHERE 线路编号='{0}';", this->RoadChoicetoolStripComboBox1->Text);
		DataTable^projecttb = ExecuteQuery(selectsql);
		for (int i = 0; i < projecttb->Rows->Count; i++)
		{
			System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
			toolstripmenuitem->Name = L"toolStripMenuTtem" + (i + 1).ToString();
			toolstripmenuitem->Size = System::Drawing::Size(152, 22);
			toolstripmenuitem->Text = projecttb->Rows[i]->ItemArray[0]->ToString();
			toolstripmenuitem->CheckOnClick = true;
			toolstripmenuitem->Checked = false;
			this->ProjectChoicetoolStripMenuItem1->DropDownItems->Add(toolstripmenuitem);
			toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &StationLogicForm::SysMode_ItemCheckedChanged);
		}
	}
}

private: System::Void VelocityChanged(System::Object^  sender, System::EventArgs^  e) {
	//1/2/5/8/10
	if (this->ChooseVelocitytoolStripComboBox1->SelectedIndex == 0)
	{
		this->timer1->Interval = 1000;
	}
	else if (this->ChooseVelocitytoolStripComboBox1->SelectedIndex == 1)//2倍速
	{
		this->timer1->Interval = Math::Floor(1000 / 2);
	}
	else if (this->ChooseVelocitytoolStripComboBox1->SelectedIndex == 2)//5倍速
	{
		this->timer1->Interval = Math::Floor(1000 / 5);
	}
	else if (this->ChooseVelocitytoolStripComboBox1->SelectedIndex == 3)//10倍速
	{
		this->timer1->Interval = Math::Floor(1000 / 10);
	}
	else if (this->ChooseVelocitytoolStripComboBox1->SelectedIndex == 4)//减慢1.5倍速
	{
		this->timer1->Interval = Math::Floor(1000 * 1.5);
	}
	else if (this->ChooseVelocitytoolStripComboBox1->SelectedIndex == 5)//减慢2倍速
	{
		this->timer1->Interval = Math::Floor(1000 * 2);
	}

}
		 //开始/停止按钮
private: System::Void RunOrStoptoolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (timerflag==false)
	{
		this->timer1->Enabled = true;
		this->timer1->Start();
		timerflag = true;
		this->RunOrStoptoolStripMenuItem1->Text = "停止运行";
	}
	else if (timerflag==true)
	{
		this->timer1->Enabled = false;
		this->timer1->Stop();
		timerflag = false;
		this->RunOrStoptoolStripMenuItem1->Text = "开始运行";
	}
}

	//定时调用的函数，调用绘制函数和双缓冲函数完成动态显示
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		UNREFERENCED_PARAMETER(sender);
		UNREFERENCED_PARAMETER(e);
		int mode = 0;
		if (this->RepeatradioButton1->Checked == true)
		{
			mode = 1;
			OpenGL->Render(mode);
		}
		else if (this->MakeProjectradioButton2->Checked == true)
		{
			mode = 2;
			OpenGL->Render(mode);
		}
		else if (this->SysradioButton3->Checked == true)
		{
			mode = 3;
			OpenGL->Render(mode);
		}
		OpenGL->swapOpenGLBuffers();
		UpdateTramInfo();
	}
	//下拉查看电车信息功能，电车选项发生改变时
private: System::Void ChooseTramcomboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	this->TramInforichTextBox1->Clear();
	int t_index;
	try {
		t_index = tram_to_index->IndexOf(this->ChooseTramcomboBox1->Items[this->ChooseTramcomboBox1->SelectedIndex]->ToString());
	}
	catch(Exception^e)
	{
		t_index = 0;
	}
	String^traminfo = "方案编号：" + OpenGL->trams[t_index]->pronum+"\n"+
		"列车编号："+OpenGL->trams[t_index]->tram_num+"\n"+
		"载客容量："+OpenGL->trams[t_index]->capacity;
	this->TramInforichTextBox1->Text = traminfo;
	UpdateTramInfo();
}
	//更新动态的电车信息显示函数
private:System::Void UpdateTramInfo()
{
	if (this->ChooseTramcomboBox1->SelectedIndex < 0)
		return;
	int t_index = tram_to_index->IndexOf(this->ChooseTramcomboBox1->Items[this->ChooseTramcomboBox1->SelectedIndex]->ToString());
	this->PeopOnTramtextBox2->Text = OpenGL->trams[t_index]->passengers_num.ToString()->Trim();//车内人数
	this->EmptyRatetextBox3->Text = OpenGL->trams[t_index]->rate.ToString()->Trim();//实时空载率
	if (OpenGL->trams[t_index]->positive_run && OpenGL->trams[t_index]->hasPassed < OpenGL->sites->Count-1)//正向
		this->NextStationtextBox4->Text = OpenGL->sites[OpenGL->trams[t_index]->hasPassed + 1]->name->Trim();//下一站名字
	else if(OpenGL->trams[t_index]->positive_run == false && OpenGL->trams[t_index]->hasPassed < OpenGL->sites1->Count - 1)//反向
		this->NextStationtextBox4->Text = OpenGL->sites1[OpenGL->sites1->Count-1 - (OpenGL->trams[t_index]->hasPassed + 1)]->name->Trim();
	this->PostextBox5->Text = OpenGL->trams[t_index]->pos.ToString();//当前位置
	this->RegiontextBox6->Text = (OpenGL->trams[t_index]->hasPassed).ToString();//区间号
	this->CurrenttextBox8->Text = OpenGL->trams[t_index]->current.ToString()->Trim();//电流
	this->VoltagetextBox9->Text = OpenGL->trams[t_index]->voltage.ToString()->Trim();//电压
	this->VelocitytextBox10->Text = OpenGL->trams[t_index]->velocity.ToString()->Trim();//车速
	this->AcceleratetextBox11->Text = OpenGL->trams[t_index]->accelerate.ToString()->Trim();//当前加速度
	if (OpenGL->trams[t_index]->finish)//如果运行完成就绿灯，没完成就红灯
		this->iffinishlabel22->BackColor = System::Drawing::Color::Lime;
	else
		this->iffinishlabel22->BackColor = System::Drawing::Color::Red;
	//绘制速度曲线图
	//这里的OpenGL->trams[t_index]->datanum为什么要减5.要取6个数据显示
	String^ selectsql;
	if (OpenGL->runningMode == 0) {
		selectsql = "SELECT cast(时间 as datetime),cast(速度 as float) FROM trainTable WHERE 数据序号>'" + (OpenGL->trams[t_index]->datanum - 5).ToString() + "' AND " +
			"数据序号<='" + OpenGL->trams[t_index]->datanum.ToString() + "';";
	}
	else if (OpenGL->runningMode == 1) {
		selectsql = "SELECT cast(时间 as datetime),cast(速度 as float) FROM trainTable WHERE 数据序号>'" + (OpenGL->trams[t_index]->maxdatanum - 5).ToString() + "' AND " +
			"数据序号<='" + OpenGL->trams[t_index]->maxdatanum.ToString() + "';";
	}
	DataTable^v_s = ExecuteQuery1(selectsql);
	array<String^>^x_t = gcnew array<String^>(v_s->Rows->Count);
	array<float>^y_v = gcnew array<float>(v_s->Rows->Count);
	for (int i = 0; i < v_s->Rows->Count;i++)
	{
		x_t[i] = v_s->Rows[i]->ItemArray[0]->ToString();
		y_v[i] = float::Parse(v_s->Rows[i]->ItemArray[1]->ToString());
	}
	this->chart1->Series[0]->Name = OpenGL->trams[t_index]->pronum;
	this->chart1->Series[0]->Points->DataBindXY(x_t,y_v);
}

		//自定义查询数据库函数
private:System::Data::DataTable^ ExecuteQuery(String ^sqlStr)
{
	SqlConnection^con = gcnew SqlConnection();
	con->ConnectionString = "Data Source=localhost;Initial Catalog=列车数据库;Integrated Security=True";
	SqlDataAdapter^da = gcnew SqlDataAdapter(sqlStr, con);
	con->Open();
	DataTable^result_dt = gcnew DataTable();
	da->Fill(result_dt);
	con->Close();
	return result_dt;
}
private:System::Data::DataTable^ ExecuteQuery1(String ^sqlStr)
{
	SqlConnection^con = gcnew SqlConnection();
	con->ConnectionString = "Data Source=localhost;Initial Catalog=RunDB2;Integrated Security=True";
	SqlDataAdapter^da = gcnew SqlDataAdapter(sqlStr, con);
	con->Open();
	DataTable^result_dt = gcnew DataTable();
	da->Fill(result_dt);
	con->Close();
	return result_dt;
}
};
}
