#pragma once

namespace RunTest2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	/// <summary>
	/// trainVIForm 摘要
	/// </summary>
	public ref class trainVIForm : public System::Windows::Forms::Form
	{
	public:
		trainVIForm(void)
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
		~trainVIForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  voltagechart;
	protected:

	private: System::Windows::Forms::DataVisualization::Charting::Chart^  currentchart;
	protected:

	protected:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  modelnametextBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  trainnametextBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  waynametextBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  voltagetextBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  currenttextBox2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  xsfxtextBox3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  voltagelight;
	private: System::Windows::Forms::Label^  currentlight;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Data::DataSet^  dataSet1;
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->voltagechart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->currentchart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->modelnametextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->trainnametextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->waynametextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->voltagetextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->currenttextBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->xsfxtextBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->voltagelight = (gcnew System::Windows::Forms::Label());
			this->currentlight = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->dataSet1 = (gcnew System::Data::DataSet());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->voltagechart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentchart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->BeginInit();
			this->SuspendLayout();
			// 
			// voltagechart
			// 
			chartArea1->AxisX->IsLabelAutoFit = false;
			chartArea1->Name = L"ChartArea1";
			this->voltagechart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->voltagechart->Legends->Add(legend1);
			this->voltagechart->Location = System::Drawing::Point(12, 123);
			this->voltagechart->Name = L"voltagechart";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->voltagechart->Series->Add(series1);
			this->voltagechart->Size = System::Drawing::Size(425, 319);
			this->voltagechart->TabIndex = 0;
			this->voltagechart->Text = L"chart1";
			// 
			// currentchart
			// 
			chartArea2->AxisX->IsLabelAutoFit = false;
			chartArea2->Name = L"ChartArea1";
			this->currentchart->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->currentchart->Legends->Add(legend2);
			this->currentchart->Location = System::Drawing::Point(473, 123);
			this->currentchart->Name = L"currentchart";
			this->currentchart->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::EarthTones;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->currentchart->Series->Add(series2);
			this->currentchart->Size = System::Drawing::Size(437, 319);
			this->currentchart->TabIndex = 1;
			this->currentchart->Text = L"chart2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(44, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 12);
			this->label1->TabIndex = 2;
			this->label1->Text = L"方案编号：";
			// 
			// modelnametextBox1
			// 
			this->modelnametextBox1->Location = System::Drawing::Point(115, 25);
			this->modelnametextBox1->Name = L"modelnametextBox1";
			this->modelnametextBox1->Size = System::Drawing::Size(100, 21);
			this->modelnametextBox1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(266, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 12);
			this->label2->TabIndex = 2;
			this->label2->Text = L"列车编号：";
			// 
			// trainnametextBox1
			// 
			this->trainnametextBox1->Location = System::Drawing::Point(337, 25);
			this->trainnametextBox1->Name = L"trainnametextBox1";
			this->trainnametextBox1->Size = System::Drawing::Size(100, 21);
			this->trainnametextBox1->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(485, 34);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 12);
			this->label3->TabIndex = 2;
			this->label3->Text = L"线路编号：";
			// 
			// waynametextBox1
			// 
			this->waynametextBox1->Location = System::Drawing::Point(556, 25);
			this->waynametextBox1->Name = L"waynametextBox1";
			this->waynametextBox1->Size = System::Drawing::Size(100, 21);
			this->waynametextBox1->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(44, 83);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 12);
			this->label4->TabIndex = 2;
			this->label4->Text = L"电压值：";
			// 
			// voltagetextBox1
			// 
			this->voltagetextBox1->Location = System::Drawing::Point(115, 74);
			this->voltagetextBox1->Name = L"voltagetextBox1";
			this->voltagetextBox1->Size = System::Drawing::Size(100, 21);
			this->voltagetextBox1->TabIndex = 3;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(266, 83);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 12);
			this->label5->TabIndex = 2;
			this->label5->Text = L"电流值：";
			// 
			// currenttextBox2
			// 
			this->currenttextBox2->Location = System::Drawing::Point(337, 74);
			this->currenttextBox2->Name = L"currenttextBox2";
			this->currenttextBox2->Size = System::Drawing::Size(100, 21);
			this->currenttextBox2->TabIndex = 3;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(695, 34);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(65, 12);
			this->label6->TabIndex = 2;
			this->label6->Text = L"行驶方向：";
			// 
			// xsfxtextBox3
			// 
			this->xsfxtextBox3->Location = System::Drawing::Point(758, 25);
			this->xsfxtextBox3->Name = L"xsfxtextBox3";
			this->xsfxtextBox3->Size = System::Drawing::Size(131, 21);
			this->xsfxtextBox3->TabIndex = 3;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(489, 83);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(89, 12);
			this->label7->TabIndex = 2;
			this->label7->Text = L"电压超限警告：";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(655, 83);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(89, 12);
			this->label8->TabIndex = 2;
			this->label8->Text = L"电流超限警告：";
			// 
			// voltagelight
			// 
			this->voltagelight->BackColor = System::Drawing::Color::Lime;
			this->voltagelight->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->voltagelight->Location = System::Drawing::Point(584, 83);
			this->voltagelight->Name = L"voltagelight";
			this->voltagelight->Size = System::Drawing::Size(42, 12);
			this->voltagelight->TabIndex = 4;
			// 
			// currentlight
			// 
			this->currentlight->BackColor = System::Drawing::Color::Lime;
			this->currentlight->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->currentlight->Location = System::Drawing::Point(750, 82);
			this->currentlight->Name = L"currentlight";
			this->currentlight->Size = System::Drawing::Size(42, 12);
			this->currentlight->TabIndex = 4;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &trainVIForm::timer1_Tick);
			// 
			// dataSet1
			// 
			this->dataSet1->DataSetName = L"NewDataSet";
			// 
			// trainVIForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(922, 454);
			this->Controls->Add(this->currentlight);
			this->Controls->Add(this->voltagelight);
			this->Controls->Add(this->currenttextBox2);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->voltagetextBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->xsfxtextBox3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->waynametextBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->trainnametextBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->modelnametextBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->currentchart);
			this->Controls->Add(this->voltagechart);
			this->Name = L"trainVIForm";
			this->Text = L"电车-电流电压监测";
			this->Load += gcnew System::EventHandler(this, &trainVIForm::trainVIForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->voltagechart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentchart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:SqlConnection^Conn = gcnew SqlConnection();//创建数据库连接
	public:SqlDataAdapter^Adapter = gcnew SqlDataAdapter();
	public:String^modelname;
	public:String^wayname;//线路编号
	public:String^trainname;//列车编号
	private: System::Void trainVIForm_Load(System::Object^  sender, System::EventArgs^  e) {
		modelnametextBox1->Text = modelname;
		trainnametextBox1->Text = trainname;
		waynametextBox1->Text = wayname;
		timer1->Start();
	}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	dataSet1->Clear();
	Conn->ConnectionString = "server=localhost;Initial Catalog=RunDB2;Integrated Security=True;";
	String^strcmd = String::Format("select 方案编号,行驶方向,电压,电流,substring(时间,11,9) as 时间 from (select top 10 * from trainTable  where 方案编号 = '{0}' order by 时间 desc) as a order by 时间", modelname);
	Data::SqlClient::SqlCommand ^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);
	Conn->Open();
	Adapter->SelectCommand = cmd;
	Adapter->Fill(dataSet1, "trainTable1");
	Conn->Close();
	this->voltagechart->DataSource = dataSet1->Tables["trainTable1"];
	this->voltagechart->Series["Series1"]->XValueMember = "时间";
	this->voltagechart->Series["Series1"]->YValueMembers = "电压";
	this->voltagechart->Series["Series1"]->LegendText = "电压值";

	this->currentchart->DataSource = dataSet1->Tables["trainTable1"];
	this->currentchart->Series["Series1"]->XValueMember = "时间";
	this->currentchart->Series["Series1"]->YValueMembers = "电流";
	this->currentchart->Series["Series1"]->LegendText = "电流值";

	DataRow^ row = dataSet1->Tables["trainTable1"]->Rows[9];
	
	xsfxtextBox3->Text = row["行驶方向"]->ToString();
	voltagetextBox1->Text = row["电压"]->ToString()->Trim() + " V";
	currenttextBox2->Text = row["电流"]->ToString()->Trim() + " A";
}
};
}
