#pragma once
#include"PowerDissipation.h"
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
	using namespace PowerDissipationAndRunningTimeChart;
	//新增命名空间
	using namespace System::Security::Permissions;
	[System::Runtime::InteropServices::ComVisibleAttribute(true)]
	/// <summary>
	/// PowerDissipationForm 摘要
	/// </summary>
	public ref class PowerDissipationForm : public System::Windows::Forms::Form
	{
	public:
		PowerDissipationForm(void)
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
		~PowerDissipationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  选择需要显示的车次ToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker3;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;














	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::GroupBox^  groupBox3;




	private: System::Windows::Forms::WebBrowser^  webBrowser1;
	private: System::Windows::Forms::WebBrowser^  webBrowser2;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::WebBrowser^  webBrowser3;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::MenuStrip^  menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  选择已有数据年份ToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::WebBrowser^  webBrowser4;
	protected:

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->webBrowser2 = (gcnew System::Windows::Forms::WebBrowser());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->选择需要显示的车次ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->webBrowser4 = (gcnew System::Windows::Forms::WebBrowser());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->webBrowser3 = (gcnew System::Windows::Forms::WebBrowser());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->选择已有数据年份ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker3 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->menuStrip2->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1284, 686);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::White;
			this->tabPage1->Controls->Add(this->webBrowser2);
			this->tabPage1->Controls->Add(this->groupBox3);
			this->tabPage1->Controls->Add(this->chart1);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1276, 660);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"当天各个车次功耗";
			// 
			// webBrowser2
			// 
			this->webBrowser2->Location = System::Drawing::Point(112, 416);
			this->webBrowser2->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser2->Name = L"webBrowser2";
			this->webBrowser2->ScrollBarsEnabled = false;
			this->webBrowser2->Size = System::Drawing::Size(1052, 236);
			this->webBrowser2->TabIndex = 4;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->webBrowser1);
			this->groupBox3->Location = System::Drawing::Point(680, 6);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(590, 404);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"当天个方案各区间运行时间";
			// 
			// webBrowser1
			// 
			this->webBrowser1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->webBrowser1->Location = System::Drawing::Point(3, 17);
			this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->ScrollBarsEnabled = false;
			this->webBrowser1->Size = System::Drawing::Size(584, 384);
			this->webBrowser1->TabIndex = 0;
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			chartArea3->AxisX->InterlacedColor = System::Drawing::Color::White;
			chartArea3->AxisX->Interval = 1;
			chartArea3->AxisX->LineColor = System::Drawing::Color::White;
			chartArea3->AxisX->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Stacked;
			chartArea3->AxisX->Title = L"方案编号";
			chartArea3->AxisX->TitleAlignment = System::Drawing::StringAlignment::Far;
			chartArea3->AxisX->TitleForeColor = System::Drawing::Color::White;
			chartArea3->AxisY->LineColor = System::Drawing::Color::White;
			chartArea3->AxisY->Title = L"各区间能耗";
			chartArea3->AxisY->TitleAlignment = System::Drawing::StringAlignment::Far;
			chartArea3->AxisY->TitleForeColor = System::Drawing::Color::White;
			chartArea3->BackColor = System::Drawing::Color::Transparent;
			chartArea3->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea3);
			legend3->BackColor = System::Drawing::Color::Transparent;
			legend3->ForeColor = System::Drawing::Color::White;
			legend3->Name = L"Legend1";
			this->chart1->Legends->Add(legend3);
			this->chart1->Location = System::Drawing::Point(6, 65);
			this->chart1->Name = L"chart1";
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StackedBar;
			series5->IsValueShownAsLabel = true;
			series5->Legend = L"Legend1";
			series5->Name = L"Series1";
			series6->ChartArea = L"ChartArea1";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StackedBar;
			series6->Legend = L"Legend1";
			series6->Name = L"Series2";
			this->chart1->Series->Add(series5);
			this->chart1->Series->Add(series6);
			this->chart1->Size = System::Drawing::Size(668, 345);
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"chart1";
			title2->ForeColor = System::Drawing::Color::White;
			title2->Name = L"Title1";
			title2->Text = L"图表题目";
			this->chart1->Titles->Add(title2);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->dateTimePicker1);
			this->groupBox1->Controls->Add(this->menuStrip1);
			this->groupBox1->Location = System::Drawing::Point(6, 6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(668, 53);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"方案调整框";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(208, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(113, 12);
			this->label2->TabIndex = 3;
			this->label2->Text = L"勾选需要显示的车次";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 12);
			this->label1->TabIndex = 2;
			this->label1->Text = L"选择日期";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(65, 20);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(123, 21);
			this->dateTimePicker1->TabIndex = 1;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &PowerDissipationForm::dateTimePicker1_ValueChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->AutoSize = false;
			this->menuStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->选择需要显示的车次ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(333, 20);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(156, 24);
			this->menuStrip1->Stretch = false;
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 选择需要显示的车次ToolStripMenuItem
			// 
			this->选择需要显示的车次ToolStripMenuItem->Name = L"选择需要显示的车次ToolStripMenuItem";
			this->选择需要显示的车次ToolStripMenuItem->Size = System::Drawing::Size(128, 20);
			this->选择需要显示的车次ToolStripMenuItem->Text = L"选择需要显示的车次";
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::White;
			this->tabPage2->Controls->Add(this->groupBox6);
			this->tabPage2->Controls->Add(this->groupBox4);
			this->tabPage2->Controls->Add(this->groupBox2);
			this->tabPage2->Controls->Add(this->chart2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1276, 660);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"多天功耗";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->webBrowser4);
			this->groupBox6->Location = System::Drawing::Point(16, 441);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(1252, 195);
			this->groupBox6->TabIndex = 3;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"各年总功耗变化趋势";
			// 
			// webBrowser4
			// 
			this->webBrowser4->Location = System::Drawing::Point(6, 14);
			this->webBrowser4->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser4->Name = L"webBrowser4";
			this->webBrowser4->ScrollBarsEnabled = false;
			this->webBrowser4->Size = System::Drawing::Size(1240, 175);
			this->webBrowser4->TabIndex = 0;
			this->webBrowser4->DocumentCompleted += gcnew System::Windows::Forms::WebBrowserDocumentCompletedEventHandler(this, &PowerDissipationForm::webBrowser4_DocumentCompleted);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->webBrowser3);
			this->groupBox4->Controls->Add(this->groupBox5);
			this->groupBox4->Location = System::Drawing::Point(692, 6);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(576, 414);
			this->groupBox4->TabIndex = 2;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"能耗趋势变化";
			// 
			// webBrowser3
			// 
			this->webBrowser3->Location = System::Drawing::Point(6, 72);
			this->webBrowser3->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser3->Name = L"webBrowser3";
			this->webBrowser3->ScrollBarsEnabled = false;
			this->webBrowser3->Size = System::Drawing::Size(564, 336);
			this->webBrowser3->TabIndex = 1;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->label6);
			this->groupBox5->Controls->Add(this->menuStrip2);
			this->groupBox5->Location = System::Drawing::Point(6, 20);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(564, 46);
			this->groupBox5->TabIndex = 0;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"显示调整框";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 23);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(53, 12);
			this->label6->TabIndex = 1;
			this->label6->Text = L"选择年份";
			// 
			// menuStrip2
			// 
			this->menuStrip2->AutoSize = false;
			this->menuStrip2->Dock = System::Windows::Forms::DockStyle::None;
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->选择已有数据年份ToolStripMenuItem });
			this->menuStrip2->Location = System::Drawing::Point(69, 17);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(125, 24);
			this->menuStrip2->TabIndex = 2;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// 选择已有数据年份ToolStripMenuItem
			// 
			this->选择已有数据年份ToolStripMenuItem->Name = L"选择已有数据年份ToolStripMenuItem";
			this->选择已有数据年份ToolStripMenuItem->Size = System::Drawing::Size(116, 20);
			this->选择已有数据年份ToolStripMenuItem->Text = L"选择已有数据年份";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->comboBox1);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->dateTimePicker3);
			this->groupBox2->Controls->Add(this->dateTimePicker2);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Location = System::Drawing::Point(8, 6);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(674, 66);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"方案调整框";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"最近一周", L"最近一月", L"最近三月", L"最近半年", L"最近一年" });
			this->comboBox1->Location = System::Drawing::Point(65, 30);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 20);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &PowerDissipationForm::comboBox1_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 33);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 12);
			this->label5->TabIndex = 3;
			this->label5->Text = L"快捷时段";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(459, 33);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(11, 12);
			this->label4->TabIndex = 2;
			this->label4->Text = L"-";
			// 
			// dateTimePicker3
			// 
			this->dateTimePicker3->Location = System::Drawing::Point(476, 30);
			this->dateTimePicker3->Name = L"dateTimePicker3";
			this->dateTimePicker3->Size = System::Drawing::Size(121, 21);
			this->dateTimePicker3->TabIndex = 1;
			this->dateTimePicker3->ValueChanged += gcnew System::EventHandler(this, &PowerDissipationForm::dateTimePicker3_ValueChanged);
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(332, 30);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(121, 21);
			this->dateTimePicker2->TabIndex = 1;
			this->dateTimePicker2->ValueChanged += gcnew System::EventHandler(this, &PowerDissipationForm::dateTimePicker2_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(273, 33);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 12);
			this->label3->TabIndex = 0;
			this->label3->Text = L"精确时段";
			// 
			// chart2
			// 
			chartArea4->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea4);
			legend4->Name = L"Legend1";
			this->chart2->Legends->Add(legend4);
			this->chart2->Location = System::Drawing::Point(8, 78);
			this->chart2->Name = L"chart2";
			series7->ChartArea = L"ChartArea1";
			series7->Legend = L"Legend1";
			series7->Name = L"Series1";
			series8->ChartArea = L"ChartArea1";
			series8->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series8->Legend = L"Legend1";
			series8->MarkerBorderColor = System::Drawing::Color::Black;
			series8->MarkerColor = System::Drawing::Color::White;
			series8->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series8->Name = L"Series2";
			this->chart2->Series->Add(series7);
			this->chart2->Series->Add(series8);
			this->chart2->Size = System::Drawing::Size(674, 342);
			this->chart2->TabIndex = 0;
			this->chart2->Text = L"chart2";
			// 
			// PowerDissipationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1284, 686);
			this->Controls->Add(this->tabControl1);
			this->MainMenuStrip = this->menuStrip2;
			this->Name = L"PowerDissipationForm";
			this->Text = L"能耗统计及运行时间";
			this->Load += gcnew System::EventHandler(this, &PowerDissipationForm::PowerDissipationForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private:SqlConnection^con = gcnew SqlConnection();
private:Hashtable^x_proposalsnumht = gcnew Hashtable();
		Hashtable^tranformht = gcnew Hashtable();//用于转换功耗
		Hashtable^tranform1ht = gcnew Hashtable();
		//Hashtable^y_powerdissipaitonht = gcnew Hashtable();
		array<int>^regions;
private:DataTable^GetDataTable(SqlConnection^con1, String^selectsql1)
{
			SqlDataAdapter^da1 = gcnew SqlDataAdapter(selectsql1, con1);
			DataTable^result_dt = gcnew DataTable();
			con1->Open();
			da1->Fill(result_dt);
			con1->Close();
			return result_dt;
}
private:System::Void PaintChart()
{
			//选中某一天日期情况下，默认显示所有当天方案
			this->x_proposalsnumht->Clear();//***************************清除
			for (int i = 0; i < this->选择需要显示的车次ToolStripMenuItem->DropDownItems->Count; i++)
			{
				System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = safe_cast<System::Windows::Forms::ToolStripMenuItem^>(this->选择需要显示的车次ToolStripMenuItem->DropDownItems[i]);
				if (toolstripmenuitem->Checked == true)
				{
					//选择一种方案
					//在该方案中查询所有区间功耗
					String^selectsql = String::Format("SELECT 列车编号 AS 列车编号,区间编号 AS 区间编号,功耗 AS 功耗,运行时间 AS 运行时间 FROM ProjectPowerDissipationTable " +
						"WHERE 时间 BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}')) AND 方案编号='{2}';",
						this->dateTimePicker1->Value.ToShortDateString(), this->dateTimePicker1->Value.ToShortDateString(),
						toolstripmenuitem->Text);
					DataTable^ powerdissipationdt = GetDataTable(con, selectsql);
					ArrayList^proposal_result = gcnew ArrayList();
					for (int j = 0; j < powerdissipationdt->Rows->Count; j++)
					{
						PowerDissipation^powerdissipation = gcnew PowerDissipation();
						DataRow^dr = powerdissipationdt->Rows[j];
						powerdissipation->carnum = dr["列车编号"]->ToString();
						powerdissipation->proposalnum = toolstripmenuitem->Text;
						powerdissipation->regionnum = dr["区间编号"]->ToString();
						powerdissipation->powerdissipation = dr["功耗"]->ToString();
						powerdissipation->runtime = dr["运行时间"]->ToString();
						proposal_result->Add(powerdissipation);
					}
					x_proposalsnumht->Add(toolstripmenuitem->Text, proposal_result);
				}
			}

			//查询最大区间号
			String^selectsql = String::Format("SELECT MAX(cast(区间编号 as float)) AS 最大区间数 FROM ProjectPowerDissipationTable " +
				"WHERE 时间 BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}'));",
				this->dateTimePicker1->Value.ToShortDateString(), this->dateTimePicker1->Value.ToShortDateString());
			DataTable^ maxregionnumdt = GetDataTable(con, selectsql);
			DataRow^maxregionnumdr = maxregionnumdt->Rows[0];
			int maxregionnum = int::Parse(maxregionnumdr["最大区间数"]->ToString());
			int regionnum = maxregionnum;
			//按照最大的区间数创建Series
			this->chart1->Series->Clear();// ***********************************
			for (int i = 0; i < regionnum; i++)
			{
				System::Windows::Forms::DataVisualization::Charting::Series^  series_temp = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
				series_temp->ChartArea = L"ChartArea1";
				series_temp->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StackedBar;
				series_temp->Legend = L"Legend1";
				series_temp->Name = L"区间" + (i + 1).ToString();
				series_temp->IsValueShownAsLabel = true;
				this->chart1->Series->Add(series_temp);
			}
			//按照最大的区间数创建数组
			tranformht->Clear();// *******************************************
			tranform1ht->Clear();
			for each(String^key in x_proposalsnumht->Keys)
			{
				//按照最大区间数创建数组
				array<float>^y_powerdissipations = gcnew array<float>(regionnum);
				array<float>^y_runtimes = gcnew array<float>(regionnum);
				ArrayList^y_arr = safe_cast<ArrayList^>(x_proposalsnumht[key]);
				for (int j = 0; j < y_arr->Count; j++)
				{
					PowerDissipation^pd = safe_cast<PowerDissipation^>(y_arr[j]);
					for (int i = 0; i < regionnum; i++)
					{
						if (int::Parse(pd->regionnum) == (i + 1))
						{
							y_powerdissipations[i] = float::Parse(pd->powerdissipation);
							y_runtimes[i] = float::Parse(pd->runtime);
						}
					}
				}
				tranformht->Add(key, y_powerdissipations);
				tranform1ht->Add(key, y_runtimes);
			}
			for (int i = 0; i < regionnum; i++)//有regionnum个Series
			{
				array<float>^y_result_powerdissipation = gcnew array<float>(x_proposalsnumht->Keys->Count);
				array<String^>^x_result_proposalsnum = gcnew array<String^>(x_proposalsnumht->Keys->Count);
				int biaozhi = 0;
				for each(String^key in tranformht->Keys)

				{
					array<float>^powerdissipation_result = safe_cast<array<float>^>(tranformht[key]);
					y_result_powerdissipation[biaozhi] = powerdissipation_result[i];
					x_result_proposalsnum[biaozhi] = key;
					biaozhi++;
				}
				this->chart1->Series["区间" + (i + 1).ToString()]->Points->DataBindXY(x_result_proposalsnum, y_result_powerdissipation);
			}
			this->chart1->Refresh();

			this->webBrowser1->Document->InvokeScript("ClearAll");
			for (int i = 0; i < regionnum; i++)//有regionnum个Series
			{
				array<float>^y_result_runtime = gcnew array<float>(x_proposalsnumht->Keys->Count);
				array<String^>^x_result_proposalsnum = gcnew array<String^>(x_proposalsnumht->Keys->Count);
				int biaozhi = 0;
				for each(String^key in tranform1ht->Keys)
				{
					array<float>^runtime_result = safe_cast<array<float>^>(tranform1ht[key]);
					y_result_runtime[biaozhi] = runtime_result[i];
					x_result_proposalsnum[biaozhi] = key;
					biaozhi++;
				}
				for (int j = 0; j < x_result_proposalsnum->Length; j++)//方案编号全发送
				{
					if (i == 0)
					{
						array<System::Object^>^sendproposalname = gcnew array<System::Object^>(1);
						sendproposalname[0] = x_result_proposalsnum[j];
						this->webBrowser1->Document->InvokeScript("GetProposalnum", sendproposalname);
					}
					array<System::Object^>^sendruntime = gcnew array<System::Object^>(1);
					sendruntime[0] = y_result_runtime[j];
					this->webBrowser1->Document->InvokeScript("SetSource", sendruntime);
				}
				this->webBrowser1->Document->InvokeScript("SetSource_Result");

			}
			this->webBrowser1->Document->InvokeScript("serie_func");
			this->webBrowser1->Document->InvokeScript("InitChart");


			array<System::Object^>^radiuschart = gcnew array<System::Object^>(5);
			selectsql = String::Format("SELECT 方案编号,功耗 AS 最大功耗 FROM " +
				"(SELECT 方案编号 AS 方案编号,SUM(功耗) AS 功耗 FROM ProjectPowerDissipationTable WHERE 时间 BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}')) " +
				"GROUP BY 方案编号) AS 最大功耗表 ORDER BY 功耗 DESC;", this->dateTimePicker1->Value.ToShortDateString(), this->dateTimePicker1->Value.ToShortDateString());
			DataTable^ maxpowerdissipationdt = GetDataTable(con, selectsql);
			DataRow^dr1 = maxpowerdissipationdt->Rows[0];
			radiuschart[0] = dr1["方案编号"]->ToString();
			radiuschart[1] = dr1["最大功耗"]->ToString();

			selectsql = String::Format("SELECT 方案编号,功耗 AS 最小功耗 FROM " +
				"(SELECT 方案编号 AS 方案编号,SUM(功耗) AS 功耗 FROM ProjectPowerDissipationTable WHERE 时间 BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}')) " +
				"GROUP BY 方案编号) AS 最小功耗表 ORDER BY 功耗;", this->dateTimePicker1->Value.ToShortDateString(), this->dateTimePicker1->Value.ToShortDateString());
			DataTable^minpowerdissipationdt = GetDataTable(con, selectsql);
			DataRow^dr2 = minpowerdissipationdt->Rows[0];
			radiuschart[2] = dr2["方案编号"]->ToString();
			radiuschart[3] = dr2["最小功耗"]->ToString();

			selectsql = String::Format("SELECT AVG(功耗) AS 平均功耗 FROM " +
				"(SELECT 方案编号 AS 方案编号,SUM(功耗) AS 功耗 FROM ProjectPowerDissipationTable WHERE 时间 BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}')) " +
				"GROUP BY 方案编号) AS 最大功耗表;", this->dateTimePicker1->Value.ToShortDateString(), this->dateTimePicker1->Value.ToShortDateString());
			DataTable^avgpowerdissipationdt = GetDataTable(con, selectsql);
			DataRow^dr3 = avgpowerdissipationdt->Rows[0];
			radiuschart[4] = dr3["平均功耗"]->ToString();

			this->webBrowser2->Document->InvokeScript("PaintChart", radiuschart);
}
	
	//初始化webbrowser控件
	private:System::Void InitWebBrowser() {
		String^ path_current = System::Windows::Forms::Application::StartupPath;
		this->webBrowser1->AllowWebBrowserDrop = false;
		this->webBrowser1->IsWebBrowserContextMenuEnabled = false;
		this->webBrowser1->WebBrowserShortcutsEnabled = false;
		this->webBrowser1->ScriptErrorsSuppressed = true;
		this->webBrowser1->ObjectForScripting = this;
		String^ path1 = path_current + "\\运行时间.html";
		this->webBrowser1->Navigate(path1);

		this->webBrowser2->AllowWebBrowserDrop = false;
		this->webBrowser2->IsWebBrowserContextMenuEnabled = false;
		this->webBrowser2->WebBrowserShortcutsEnabled = false;
		this->webBrowser2->ScriptErrorsSuppressed = true;
		this->webBrowser2->ObjectForScripting = this;
		String^ path2 = path_current + "\\环形图.html";
		this->webBrowser2->Navigate(path2);

		this->webBrowser3->AllowWebBrowserDrop = false;
		this->webBrowser3->IsWebBrowserContextMenuEnabled = false;
		this->webBrowser3->WebBrowserShortcutsEnabled = false;
		this->webBrowser3->ScriptErrorsSuppressed = true;
		this->webBrowser3->ObjectForScripting = this;
		String^ path3 = path_current + "\\各年各月份功耗和折线图.html";
		this->webBrowser3->Navigate(path3);

		this->webBrowser4->AllowWebBrowserDrop = false;
		this->webBrowser4->IsWebBrowserContextMenuEnabled = false;
		this->webBrowser4->WebBrowserShortcutsEnabled = false;
		this->webBrowser4->ScriptErrorsSuppressed = true;
		this->webBrowser4->ObjectForScripting = this;
		String^ path4 = path_current + "\\各年功耗总和趋势图.html";
		this->webBrowser4->Navigate(path4);
	}

		//主窗体加载事件
	private: System::Void PowerDissipationForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//初始化webBrowser控件
		InitWebBrowser();
		this->con->ConnectionString = "Data Source=localhost;Initial Catalog=RunDB2;Integrated Security=True";
		//获取当天所有方案编号
		String^ selectsql = String::Format("SELECT DISTINCT 方案编号 AS 方案编号 FROM ProjectPowerDissipationTable WHERE 时间 BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}'));",
			DateTime::Now.ToShortDateString(), DateTime::Now.ToShortDateString());
		DataTable^ proposalsnumdt = GetDataTable(con, selectsql);
		if (proposalsnumdt->Rows->Count <= 0)
			return;
		//如果当天模拟运行方案不为空，则将方案编号添加到下拉勾选菜单中
		for (int i = 0; i < proposalsnumdt->Rows->Count; i++)
		{
			DataRow^ proposaldr = proposalsnumdt->Rows[i];
			System::Windows::Forms::ToolStripMenuItem^ toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
			toolstripmenuitem->Name = L"toolStripMenuTtem" + proposaldr["方案编号"]->ToString();
			toolstripmenuitem->Size = System::Drawing::Size(152, 22);
			toolstripmenuitem->Text = proposaldr["方案编号"]->ToString();
			toolstripmenuitem->CheckOnClick = true;
			toolstripmenuitem->Checked = true;//默认被选中
			this->选择需要显示的车次ToolStripMenuItem->DropDownItems->Add(toolstripmenuitem);
			toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &PowerDissipationForm::toolStripMenuItem_CheckedChanged);
		}
		if (this->选择需要显示的车次ToolStripMenuItem->DropDownItems->Count > 0)
			PaintChart();

		//能耗趋势
		//selectsql = String::Format("SELECT DATEPART(year,时间) AS 时间 FROM 方案功耗数据表;");
		//将数据库中的时间数据提取出年份
		selectsql = String::Format("SELECT DISTINCT 时间 AS 时间 FROM (SELECT DATEPART(year,时间) AS 时间 FROM ProjectPowerDissipationTable) AS 时间表;");
		DataTable^ yearsnumdt = GetDataTable(con, selectsql);
		for (int i = 0; i < yearsnumdt->Rows->Count; i++)
		{
			DataRow^ yeardr = yearsnumdt->Rows[i];
			System::Windows::Forms::ToolStripMenuItem^ toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
			toolstripmenuitem->Name = L"toolStripMenuTtem" + yeardr["时间"]->ToString();
			toolstripmenuitem->Size = System::Drawing::Size(152, 22);
			toolstripmenuitem->Text = yeardr["时间"]->ToString();
			toolstripmenuitem->CheckOnClick = true;
			toolstripmenuitem->Checked = false;//默认被选中
			this->选择已有数据年份ToolStripMenuItem->DropDownItems->Add(toolstripmenuitem);
			toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &PowerDissipationForm::选择已有数据年份ToolStripMenuItem_CheckedChanged);
		}
	}
		   //当天各个车次功耗
private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->chart1->Titles["Title1"]->Text = this->dateTimePicker1->Value.ToShortDateString() + "各方案能耗统计";
			 //显示一天有多少个方案，可供用户选择显示
			 String^selectsql = String::Format("SELECT DISTINCT 方案编号 AS 方案编号 FROM ProjectPowerDissipationTable WHERE 时间 BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}'));",
				 this->dateTimePicker1->Value.ToShortDateString(), this->dateTimePicker1->Value.ToShortDateString());
			 DataTable^proposalsnumdt = GetDataTable(con, selectsql);

			 this->选择需要显示的车次ToolStripMenuItem->DropDownItems->Clear();
			 for (int i = 0; i < proposalsnumdt->Rows->Count; i++)
			 {
				 DataRow^proposaldr = proposalsnumdt->Rows[i];
				 System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
				 toolstripmenuitem->Name = L"toolStripMenuTtem" + proposaldr["方案编号"]->ToString();
				 toolstripmenuitem->Size = System::Drawing::Size(152, 22);
				 toolstripmenuitem->Text = proposaldr["方案编号"]->ToString();
				 toolstripmenuitem->CheckOnClick = true;
				 toolstripmenuitem->Checked = true;//默认被选中
				 this->选择需要显示的车次ToolStripMenuItem->DropDownItems->Add(toolstripmenuitem);
				 toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &PowerDissipationForm::toolStripMenuItem_CheckedChanged);
			 }
			 if (this->选择需要显示的车次ToolStripMenuItem->DropDownItems->Count>0)
				 PaintChart();
}

private: System::Void toolStripMenuItem_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 for (int i = 0; i < this->选择需要显示的车次ToolStripMenuItem->DropDownItems->Count; i++)
			 {
				 System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = safe_cast<System::Windows::Forms::ToolStripMenuItem^>(this->选择需要显示的车次ToolStripMenuItem->DropDownItems[i]);
				 if (toolstripmenuitem->Checked == false)
				 {
					 this->x_proposalsnumht->Remove(toolstripmenuitem->Text);
				 }
			 }
			 if (this->选择需要显示的车次ToolStripMenuItem->DropDownItems->Count>0)
				 PaintChart();
}
		 //快捷时段功耗显示
private:int datesnum = 0;
private:System::Void ShowDaysPowerdissipation(int days)
{
			array<String^>^x_arr = gcnew array<String^>(days);
			array<float>^y_arr = gcnew array<float>(days);
			for (int i = 0; i < days; i++)
			{
				String^selectsql = String::Format("SELECT SUM(功耗) AS 当天功耗和 FROM ProjectPowerDissipationTable WHERE 时间 BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}'));",
					DateTime::Now.AddDays(-i).ToShortDateString(), DateTime::Now.AddDays(-i).ToShortDateString());
				//String^selectsql = String::Format("SELECT SUM(功耗) FROM 方案功耗数据表 WHERE 时间 BETWEEN '{0}' AND dateadd(day,-"+i+",GETDATE());",
				DataTable^powerdissipationdt = GetDataTable(con, selectsql);
				DataRow^dr = powerdissipationdt->Rows[0];
				//MessageBox::Show(dr["当天功耗和"]->ToString());
				x_arr[days - i - 1] = DateTime::Now.AddDays(-i).ToShortDateString();
				try
				{
					y_arr[days - i - 1] = float::Parse(dr["当天功耗和"]->ToString());
				}
				catch (FormatException^e)
				{
					y_arr[days - i - 1] = 0;
				}
			}

			this->chart2->Series["Series1"]->Points->DataBindXY(x_arr, y_arr);
			this->chart2->Series["Series2"]->Points->DataBindXY(x_arr, y_arr);
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->comboBox1->SelectedIndex == 0)
			 {
				 ShowDaysPowerdissipation(7);
			 }
			 if (this->comboBox1->SelectedIndex == 1)
			 {
				 ShowDaysPowerdissipation(30);
			 }
			 if (this->comboBox1->SelectedIndex == 2)
			 {
				 ShowDaysPowerdissipation(90);
			 }
			 if (this->comboBox1->SelectedIndex == 3)
			 {
				 ShowDaysPowerdissipation(180);
			 }
			 if (this->comboBox1->SelectedIndex == 4)
			 {
				 ShowDaysPowerdissipation(365);
			 }

}
		 //左边选择日期
private: System::Void dateTimePicker2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 //MessageBox::Show((this->dateTimePicker3->Value-this->dateTimePicker2->Value).ToString);
			 int days = this->dateTimePicker3->Value.DayOfYear - this->dateTimePicker2->Value.DayOfYear;
			 ShowDaysPowerdissipation(days);
}
		 //右边选择日期
private: System::Void dateTimePicker3_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 int days = this->dateTimePicker3->Value.DayOfYear - this->dateTimePicker2->Value.DayOfYear;
			 ShowDaysPowerdissipation(days);
}
private:Hashtable^powerofyearht = gcnew Hashtable();
private: System::Void 选择已有数据年份ToolStripMenuItem_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 powerofyearht->Clear();// ******************************
			 for (int i = 0; i < this->选择已有数据年份ToolStripMenuItem->DropDownItems->Count; i++)
			 {
				 System::Windows::Forms::ToolStripMenuItem^toolstripmenuitem = safe_cast<System::Windows::Forms::ToolStripMenuItem^>(this->选择已有数据年份ToolStripMenuItem->DropDownItems[i]);
				 array<float>^y_arr = gcnew array<float>(12);
				 if (toolstripmenuitem->Checked == true)
				 {
					 String^sql = String::Format("SELECT DATEPART(month,时间) AS 月份,SUM(功耗) AS 当月功耗和 FROM " +
						 "(SELECT 功耗 AS 功耗,时间 AS 时间 FROM ProjectPowerDissipationTable WHERE DATEPART(year,时间)={0}) AS T1 GROUP BY " +
						 "DATEPART(month,时间);", toolstripmenuitem->Text);
					 DataTable^result_dt = GetDataTable(con, sql);
					 for (int j = 0; j < result_dt->Rows->Count; j++)
					 {
						 DataRow^dr = result_dt->Rows[j];
						 y_arr[int::Parse(dr["月份"]->ToString()) - 1] = float::Parse(dr["当月功耗和"]->ToString());
					 }
					 powerofyearht->Add(toolstripmenuitem->Text, y_arr);
				 }
				 if (toolstripmenuitem->Checked == false)
				 {
					 if (powerofyearht->Contains(toolstripmenuitem->Text))
					 {
						 powerofyearht->Remove(toolstripmenuitem->Text);
					 }
				 }
			 }
			 this->webBrowser3->Document->InvokeScript("ClearAll");
			 for each(String^key in powerofyearht->Keys)
			 {
				 array<System::Object^>^senddata = gcnew array<System::Object^>(13);
				 senddata[0] = key;
				 array<float>^y_arr = safe_cast<array<float>^>(powerofyearht[key]);
				 //MessageBox::Show(y_arr->Length.ToString());
				 for (int i = 0; i < y_arr->Length; i++)
				 {
					 senddata[i + 1] = y_arr[i];
				 }
				 this->webBrowser3->Document->InvokeScript("GetData", senddata);
			 }
			 this->webBrowser3->Document->InvokeScript("InitChart");

}
private: System::Void webBrowser4_DocumentCompleted(System::Object^  sender, System::Windows::Forms::WebBrowserDocumentCompletedEventArgs^  e) {
			 String^selectsql = String::Format("SELECT DATEPART(year,时间) AS 年份,SUM(功耗) AS 当年功耗和 FROM ProjectPowerDissipationTable GROUP BY DATEPART(year,时间);");
			 DataTable^powersumofyear = GetDataTable(con, selectsql);
			 this->webBrowser4->Document->InvokeScript("ClearAll");
			 for (int i = 0; i < powersumofyear->Rows->Count; i++)
			 {
				 DataRow^dr_temp = powersumofyear->Rows[i];
				 array<System::Object^>^senddata = gcnew array<System::Object^>(2);
				 senddata[0] = dr_temp["年份"]->ToString();
				 senddata[1] = float::Parse(dr_temp["当年功耗和"]->ToString());
				 //MessageBox::Show(senddata[1]->ToString());
				 this->webBrowser4->Document->InvokeScript("GetData", senddata);
			 }
			 this->webBrowser4->Document->InvokeScript("InitChart");
}
	};
}
