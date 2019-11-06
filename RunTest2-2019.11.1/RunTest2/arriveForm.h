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
	/// arriveForm 摘要
	/// </summary>
	public ref class arriveForm : public System::Windows::Forms::Form
	{
	public:
		arriveForm(void)
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
		~arriveForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  modelnametextBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  waynametextBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  xsfxtextBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  stopnametextBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  nextstopnametextBox1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  arrivetimetextBox1;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  leavetimetextBox1;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  staytimetextBox1;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  getonnumtextBox1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  getoffnumtextBox1;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  runlightlabel12;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  stoplightlabel13;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Data::DataSet^  dataSet1;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  peoplenumtextBox1;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  trainnametextBox1;

	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  zaikeliangtextBox2;

	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  manzailvtextBox3;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->modelnametextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->waynametextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->xsfxtextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->stopnametextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->nextstopnametextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->arrivetimetextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->leavetimetextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->staytimetextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->getonnumtextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->getoffnumtextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->runlightlabel12 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->stoplightlabel13 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->dataSet1 = (gcnew System::Data::DataSet());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->peoplenumtextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->trainnametextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->zaikeliangtextBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->manzailvtextBox3 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->AxisX->Crossing = -1.7976931348623157E+308;
			chartArea1->AxisX->Interval = 1;
			chartArea1->AxisX->IntervalOffset = 1;
			chartArea1->AxisX->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea1->AxisX->IsLabelAutoFit = false;
			chartArea1->AxisX->IsStartedFromZero = false;
			chartArea1->AxisX->LabelAutoFitMinFontSize = 5;
			chartArea1->AxisX->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Horizontal;
			chartArea1->AxisX->TitleAlignment = System::Drawing::StringAlignment::Far;
			chartArea1->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 8));
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 133);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Series2";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(1123, 464);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"方案编号：";
			// 
			// modelnametextBox1
			// 
			this->modelnametextBox1->Location = System::Drawing::Point(96, 17);
			this->modelnametextBox1->Name = L"modelnametextBox1";
			this->modelnametextBox1->Size = System::Drawing::Size(101, 21);
			this->modelnametextBox1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(222, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 12);
			this->label2->TabIndex = 1;
			this->label2->Text = L"线路编号：";
			// 
			// waynametextBox1
			// 
			this->waynametextBox1->Location = System::Drawing::Point(293, 17);
			this->waynametextBox1->Name = L"waynametextBox1";
			this->waynametextBox1->Size = System::Drawing::Size(124, 21);
			this->waynametextBox1->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(445, 26);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 12);
			this->label3->TabIndex = 1;
			this->label3->Text = L"行驶方向：";
			// 
			// xsfxtextBox1
			// 
			this->xsfxtextBox1->Location = System::Drawing::Point(516, 17);
			this->xsfxtextBox1->Name = L"xsfxtextBox1";
			this->xsfxtextBox1->Size = System::Drawing::Size(124, 21);
			this->xsfxtextBox1->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(913, 23);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(65, 12);
			this->label4->TabIndex = 1;
			this->label4->Text = L"当前站点：";
			// 
			// stopnametextBox1
			// 
			this->stopnametextBox1->Location = System::Drawing::Point(984, 14);
			this->stopnametextBox1->Name = L"stopnametextBox1";
			this->stopnametextBox1->Size = System::Drawing::Size(101, 21);
			this->stopnametextBox1->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label5->Location = System::Drawing::Point(913, 63);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 12);
			this->label5->TabIndex = 1;
			this->label5->Text = L"下一站：";
			// 
			// nextstopnametextBox1
			// 
			this->nextstopnametextBox1->Location = System::Drawing::Point(984, 60);
			this->nextstopnametextBox1->Name = L"nextstopnametextBox1";
			this->nextstopnametextBox1->Size = System::Drawing::Size(101, 21);
			this->nextstopnametextBox1->TabIndex = 2;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(222, 66);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(65, 12);
			this->label6->TabIndex = 1;
			this->label6->Text = L"到站时间：";
			// 
			// arrivetimetextBox1
			// 
			this->arrivetimetextBox1->Location = System::Drawing::Point(293, 57);
			this->arrivetimetextBox1->Name = L"arrivetimetextBox1";
			this->arrivetimetextBox1->Size = System::Drawing::Size(124, 21);
			this->arrivetimetextBox1->TabIndex = 2;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(445, 63);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(65, 12);
			this->label7->TabIndex = 1;
			this->label7->Text = L"出站时间：";
			// 
			// leavetimetextBox1
			// 
			this->leavetimetextBox1->Location = System::Drawing::Point(516, 54);
			this->leavetimetextBox1->Name = L"leavetimetextBox1";
			this->leavetimetextBox1->Size = System::Drawing::Size(124, 21);
			this->leavetimetextBox1->TabIndex = 2;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(25, 66);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(65, 12);
			this->label8->TabIndex = 1;
			this->label8->Text = L"停留时间：";
			// 
			// staytimetextBox1
			// 
			this->staytimetextBox1->Location = System::Drawing::Point(96, 57);
			this->staytimetextBox1->Name = L"staytimetextBox1";
			this->staytimetextBox1->Size = System::Drawing::Size(101, 21);
			this->staytimetextBox1->TabIndex = 2;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(25, 103);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(65, 12);
			this->label9->TabIndex = 1;
			this->label9->Text = L"上车人数：";
			// 
			// getonnumtextBox1
			// 
			this->getonnumtextBox1->Location = System::Drawing::Point(96, 94);
			this->getonnumtextBox1->Name = L"getonnumtextBox1";
			this->getonnumtextBox1->Size = System::Drawing::Size(101, 21);
			this->getonnumtextBox1->TabIndex = 2;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(222, 102);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(65, 12);
			this->label10->TabIndex = 1;
			this->label10->Text = L"下车人数：";
			// 
			// getoffnumtextBox1
			// 
			this->getoffnumtextBox1->Location = System::Drawing::Point(293, 93);
			this->getoffnumtextBox1->Name = L"getoffnumtextBox1";
			this->getoffnumtextBox1->Size = System::Drawing::Size(124, 21);
			this->getoffnumtextBox1->TabIndex = 2;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label11->Location = System::Drawing::Point(905, 91);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(53, 12);
			this->label11->TabIndex = 1;
			this->label11->Text = L"行驶中：";
			// 
			// runlightlabel12
			// 
			this->runlightlabel12->BackColor = System::Drawing::Color::Gainsboro;
			this->runlightlabel12->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->runlightlabel12->Location = System::Drawing::Point(951, 90);
			this->runlightlabel12->Name = L"runlightlabel12";
			this->runlightlabel12->Size = System::Drawing::Size(34, 12);
			this->runlightlabel12->TabIndex = 3;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label12->Location = System::Drawing::Point(1001, 90);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(65, 12);
			this->label12->TabIndex = 1;
			this->label12->Text = L"到站停靠：";
			// 
			// stoplightlabel13
			// 
			this->stoplightlabel13->BackColor = System::Drawing::Color::Gainsboro;
			this->stoplightlabel13->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->stoplightlabel13->Location = System::Drawing::Point(1062, 89);
			this->stoplightlabel13->Name = L"stoplightlabel13";
			this->stoplightlabel13->Size = System::Drawing::Size(34, 12);
			this->stoplightlabel13->TabIndex = 3;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &arriveForm::timer1_Tick);
			// 
			// dataSet1
			// 
			this->dataSet1->DataSetName = L"NewDataSet";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(445, 99);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(65, 12);
			this->label13->TabIndex = 1;
			this->label13->Text = L"车内人数：";
			// 
			// peoplenumtextBox1
			// 
			this->peoplenumtextBox1->Location = System::Drawing::Point(516, 90);
			this->peoplenumtextBox1->Name = L"peoplenumtextBox1";
			this->peoplenumtextBox1->Size = System::Drawing::Size(124, 21);
			this->peoplenumtextBox1->TabIndex = 2;
			// 
			// label14
			// 
			this->label14->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label14->Location = System::Drawing::Point(895, 51);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(215, 61);
			this->label14->TabIndex = 4;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(667, 26);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(65, 12);
			this->label15->TabIndex = 1;
			this->label15->Text = L"列车编号：";
			// 
			// trainnametextBox1
			// 
			this->trainnametextBox1->Location = System::Drawing::Point(738, 17);
			this->trainnametextBox1->Name = L"trainnametextBox1";
			this->trainnametextBox1->Size = System::Drawing::Size(111, 21);
			this->trainnametextBox1->TabIndex = 2;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(655, 63);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(77, 12);
			this->label16->TabIndex = 1;
			this->label16->Text = L"额定载客数：";
			// 
			// zaikeliangtextBox2
			// 
			this->zaikeliangtextBox2->Location = System::Drawing::Point(738, 54);
			this->zaikeliangtextBox2->Name = L"zaikeliangtextBox2";
			this->zaikeliangtextBox2->Size = System::Drawing::Size(111, 21);
			this->zaikeliangtextBox2->TabIndex = 2;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(679, 97);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(53, 12);
			this->label17->TabIndex = 1;
			this->label17->Text = L"满载率：";
			// 
			// manzailvtextBox3
			// 
			this->manzailvtextBox3->Location = System::Drawing::Point(738, 90);
			this->manzailvtextBox3->Name = L"manzailvtextBox3";
			this->manzailvtextBox3->Size = System::Drawing::Size(111, 21);
			this->manzailvtextBox3->TabIndex = 2;
			// 
			// arriveForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1147, 627);
			this->Controls->Add(this->stoplightlabel13);
			this->Controls->Add(this->runlightlabel12);
			this->Controls->Add(this->manzailvtextBox3);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->zaikeliangtextBox2);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->trainnametextBox1);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->xsfxtextBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->waynametextBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->nextstopnametextBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->staytimetextBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->leavetimetextBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->arrivetimetextBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->peoplenumtextBox1);
			this->Controls->Add(this->getoffnumtextBox1);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->getonnumtextBox1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->stopnametextBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->modelnametextBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->label14);
			this->Name = L"arriveForm";
			this->Text = L"站点监测信息";
			this->Load += gcnew System::EventHandler(this, &arriveForm::arriveForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
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
	public:array<String^>^stopname;
	public:int zaikeliang;
	private: System::Void arriveForm_Load(System::Object^  sender, System::EventArgs^  e) {
		modelnametextBox1->Text = modelname;
		waynametextBox1->Text = wayname;
		trainnametextBox1->Text = trainname;
		zaikeliangtextBox2->Text = zaikeliang.ToString();
		stoplightlabel13->BackColor = System::Drawing::Color::Gainsboro;
		runlightlabel12->BackColor = System::Drawing::Color::Lime;
		timer1->Start();
	}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

	dataSet1->Clear();

	Conn->ConnectionString = "server=localhost;Initial Catalog=RunDB2;Integrated Security=True;";
	String^strcmd = String::Format("select top 1 行驶方向 from trainTable  where 方案编号 = '{0}' order by 时间 desc", modelname);
	Data::SqlClient::SqlCommand ^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);
	Conn->Open();
	xsfxtextBox1->Text = cmd->ExecuteScalar()->ToString();
	Conn->Close();

	String^strcmd1 = String::Format("select * from peopleTable  where 方案编号 = '{0}' ", modelname);
	Data::SqlClient::SqlCommand ^ cmd1 = gcnew Data::SqlClient::SqlCommand(strcmd1, Conn);
	Conn->Open();
	Adapter->SelectCommand = cmd1;
	Adapter->Fill(dataSet1, "peopleTable");
	Conn->Close();
	this->chart1->DataSource = dataSet1->Tables["peopleTable"];
	this->chart1->Series["Series1"]->XValueMember = "站点名";
	this->chart1->Series["Series1"]->YValueMembers = "上车人数";
	this->chart1->Series["Series2"]->YValueMembers = "下车人数";
	this->chart1->Series["Series1"]->LegendText = "上车人数";
	this->chart1->Series["Series2"]->LegendText = "下车人数";

	int index = dataSet1->Tables["peopleTable"]->Rows->Count;
	DataRow^ row = dataSet1->Tables["peopleTable"]->Rows[index - 1];
	stopnametextBox1->Text = row["站点名"]->ToString();
	arrivetimetextBox1->Text = row["到站时间"]->ToString();
	leavetimetextBox1->Text = row["出站时间"]->ToString();
	if (row["到站时间"]->ToString()->TrimEnd()->Length != 0 && row["出站时间"]->ToString()->TrimEnd()->Length != 0)
	{
		DateTime arrivetime = Convert::ToDateTime(row["到站时间"]->ToString()->TrimEnd());
		DateTime leavetime = Convert::ToDateTime(row["出站时间"]->ToString()->TrimEnd());
		TimeSpan ts = leavetime.Subtract(arrivetime);
		int stopseconds = ts.TotalSeconds;//求停留时间
		staytimetextBox1->Text = stopseconds.ToString();
		DateTime nowtime = DateTime::Now;
		if (nowtime >= arrivetime&&nowtime <leavetime)
		{
			runlightlabel12->BackColor = System::Drawing::Color::Gainsboro;
			stoplightlabel13->BackColor = System::Drawing::Color::Lime;
		}
		else if (nowtime >= leavetime)
		{
			stoplightlabel13->BackColor = System::Drawing::Color::Gainsboro;
			runlightlabel12->BackColor = System::Drawing::Color::Lime;
		}
	}
	else
		staytimetextBox1->Text = "---";
	getonnumtextBox1->Text = row["上车人数"]->ToString();
	getoffnumtextBox1->Text = row["下车人数"]->ToString();
	peoplenumtextBox1->Text = row["车内人数"]->ToString();
	double manzailv = (double::Parse(peoplenumtextBox1->Text) / zaikeliang)*100;
	manzailvtextBox3->Text = manzailv.ToString() + "%";
	//下一站的判断
	if (xsfxtextBox1->Text->Trim() == "正向")
	{
		for (int i; i < stopname->Length; i++)
		{
			if (row["站点名"]->ToString()->Trim() == stopname[i])
			{
				nextstopnametextBox1->Text = stopname[i + 1];
				break;
			}
		}
	}
	else
	{
		for (int i; i < stopname->Length; i++)
		{
			if (row["站点名"]->ToString()->Trim() == stopname[i]&&i!=0)
			{
				nextstopnametextBox1->Text = stopname[i - 1];
				break;
			}
		}
	}
}
};
}
