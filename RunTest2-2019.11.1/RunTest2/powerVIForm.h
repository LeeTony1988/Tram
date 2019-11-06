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
	/// powerVIForm 摘要
	/// </summary>
	public ref class powerVIForm : public System::Windows::Forms::Form
	{
	public:
		powerVIForm(void)
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
		~powerVIForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  voltagechart;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  currentchart;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  modelnametextBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  trainnametextBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  waynametextBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  voltagetextBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  powernumbertextBox1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  positiontextBox1;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  powerlongtextBox1;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  currenttextBox1;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  voltagelight;
	private: System::Windows::Forms::Label^  currentlight;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Data::DataSet^  dataSet1;
	private: System::ComponentModel::IContainer^  components;



	protected:

	protected:

	protected:

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
			this->powernumbertextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->positiontextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->powerlongtextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->currenttextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->voltagelight = (gcnew System::Windows::Forms::Label());
			this->currentlight = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
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
			this->currentchart->TabIndex = 0;
			this->currentchart->Text = L"chart1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(40, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"方案编号：";
			// 
			// modelnametextBox1
			// 
			this->modelnametextBox1->Location = System::Drawing::Point(102, 23);
			this->modelnametextBox1->Name = L"modelnametextBox1";
			this->modelnametextBox1->Size = System::Drawing::Size(100, 21);
			this->modelnametextBox1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(250, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 12);
			this->label2->TabIndex = 1;
			this->label2->Text = L"列车编号：";
			// 
			// trainnametextBox1
			// 
			this->trainnametextBox1->Location = System::Drawing::Point(312, 23);
			this->trainnametextBox1->Name = L"trainnametextBox1";
			this->trainnametextBox1->Size = System::Drawing::Size(100, 21);
			this->trainnametextBox1->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(459, 32);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 12);
			this->label3->TabIndex = 1;
			this->label3->Text = L"线路编号：";
			// 
			// waynametextBox1
			// 
			this->waynametextBox1->Location = System::Drawing::Point(521, 23);
			this->waynametextBox1->Name = L"waynametextBox1";
			this->waynametextBox1->Size = System::Drawing::Size(100, 21);
			this->waynametextBox1->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label4->Location = System::Drawing::Point(645, 32);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 12);
			this->label4->TabIndex = 1;
			this->label4->Text = L"电压值：";
			// 
			// voltagetextBox1
			// 
			this->voltagetextBox1->Location = System::Drawing::Point(704, 29);
			this->voltagetextBox1->Name = L"voltagetextBox1";
			this->voltagetextBox1->Size = System::Drawing::Size(68, 21);
			this->voltagetextBox1->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(40, 81);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(89, 12);
			this->label5->TabIndex = 1;
			this->label5->Text = L"供电区间编号：";
			// 
			// powernumbertextBox1
			// 
			this->powernumbertextBox1->Location = System::Drawing::Point(122, 72);
			this->powernumbertextBox1->Name = L"powernumbertextBox1";
			this->powernumbertextBox1->Size = System::Drawing::Size(100, 21);
			this->powernumbertextBox1->TabIndex = 2;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(250, 81);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(65, 12);
			this->label6->TabIndex = 1;
			this->label6->Text = L"起点位置：";
			// 
			// positiontextBox1
			// 
			this->positiontextBox1->Location = System::Drawing::Point(312, 72);
			this->positiontextBox1->Name = L"positiontextBox1";
			this->positiontextBox1->Size = System::Drawing::Size(100, 21);
			this->positiontextBox1->TabIndex = 2;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(460, 81);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(65, 12);
			this->label7->TabIndex = 1;
			this->label7->Text = L"区间长度：";
			// 
			// powerlongtextBox1
			// 
			this->powerlongtextBox1->Location = System::Drawing::Point(521, 72);
			this->powerlongtextBox1->Name = L"powerlongtextBox1";
			this->powerlongtextBox1->Size = System::Drawing::Size(100, 21);
			this->powerlongtextBox1->TabIndex = 2;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label8->Location = System::Drawing::Point(645, 81);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(53, 12);
			this->label8->TabIndex = 1;
			this->label8->Text = L"电流值：";
			// 
			// currenttextBox1
			// 
			this->currenttextBox1->Location = System::Drawing::Point(704, 72);
			this->currenttextBox1->Name = L"currenttextBox1";
			this->currenttextBox1->Size = System::Drawing::Size(68, 21);
			this->currenttextBox1->TabIndex = 2;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label9->Location = System::Drawing::Point(788, 32);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(65, 12);
			this->label9->TabIndex = 3;
			this->label9->Text = L"超限警告：";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label10->Location = System::Drawing::Point(788, 81);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(65, 12);
			this->label10->TabIndex = 3;
			this->label10->Text = L"超限警告：";
			// 
			// voltagelight
			// 
			this->voltagelight->BackColor = System::Drawing::Color::Lime;
			this->voltagelight->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->voltagelight->Location = System::Drawing::Point(849, 31);
			this->voltagelight->Name = L"voltagelight";
			this->voltagelight->Size = System::Drawing::Size(40, 13);
			this->voltagelight->TabIndex = 4;
			// 
			// currentlight
			// 
			this->currentlight->BackColor = System::Drawing::Color::Lime;
			this->currentlight->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->currentlight->Location = System::Drawing::Point(849, 80);
			this->currentlight->Name = L"currentlight";
			this->currentlight->Size = System::Drawing::Size(40, 13);
			this->currentlight->TabIndex = 4;
			// 
			// label11
			// 
			this->label11->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label11->Location = System::Drawing::Point(637, 23);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(261, 31);
			this->label11->TabIndex = 5;
			// 
			// label12
			// 
			this->label12->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label12->Location = System::Drawing::Point(637, 63);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(261, 40);
			this->label12->TabIndex = 5;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &powerVIForm::timer1_Tick);
			// 
			// dataSet1
			// 
			this->dataSet1->DataSetName = L"NewDataSet";
			// 
			// powerVIForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(922, 454);
			this->Controls->Add(this->currentlight);
			this->Controls->Add(this->voltagelight);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->currenttextBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->voltagetextBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->waynametextBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->trainnametextBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->powerlongtextBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->positiontextBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->powernumbertextBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->modelnametextBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->currentchart);
			this->Controls->Add(this->voltagechart);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Location = System::Drawing::Point(39, 123);
			this->Name = L"powerVIForm";
			this->Text = L"供电区间-电流电压监测";
			this->Load += gcnew System::EventHandler(this, &powerVIForm::powerVIForm_Load);
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
	public:array<int>^power_s;//供电区间位置
	public:array<String^>^power_name;//供电区间编号
	public:int power_l;//供电区间长度
	public:int powerpassnum;//经过供电区间次数
	private: System::Void powerVIForm_Load(System::Object^  sender, System::EventArgs^  e) {
		modelnametextBox1->Text = modelname;
		trainnametextBox1->Text = trainname;
		waynametextBox1->Text = wayname;
		timer1->Start();
	}

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	dataSet1->Clear();
	Conn->ConnectionString = "server=localhost;Initial Catalog=RunDB2;Integrated Security=True;";
	Conn->Open();

	String^ strcmd0= String::Format("select count(*) from powerTable where 方案编号 = '{0}'",modelname);
	Data::SqlClient::SqlCommand ^ cmd0= gcnew Data::SqlClient::SqlCommand(strcmd0, Conn);
	int count=Int32::Parse( cmd0->ExecuteScalar()->ToString());//判断数据表行数
	Conn->Close();
	if (count >= 10)
		count = 10;

	Conn->Open();
	String^strcmd = String::Format("select 方案编号,供电区间编号,电压,电流,substring(时间,11,9) as 时间 from (select top {0} * from powerTable  where 方案编号 = '{1}' order by 时间 desc) as a order by 时间",count.ToString(), modelname);
	Data::SqlClient::SqlCommand ^ cmd = gcnew Data::SqlClient::SqlCommand(strcmd, Conn);
	
	Adapter->SelectCommand = cmd;
	Adapter->Fill(dataSet1, "powerTable1");
	Conn->Close();
	this->voltagechart->DataSource = dataSet1->Tables["powerTable1"];
	this->voltagechart->Series["Series1"]->XValueMember = "时间";
	this->voltagechart->Series["Series1"]->YValueMembers = "电压";
	this->voltagechart->Series["Series1"]->LegendText = "电压值";

	this->currentchart->DataSource = dataSet1->Tables["powerTable1"];
	this->currentchart->Series["Series1"]->XValueMember = "时间";
	this->currentchart->Series["Series1"]->YValueMembers = "电流";
	this->currentchart->Series["Series1"]->LegendText = "电流值";

	int index = dataSet1->Tables["powerTable1"]->Rows->Count;
	if (index > 0)
	{
		DataRow^ row = dataSet1->Tables["powerTable1"]->Rows[index - 1];
		voltagetextBox1->Text = row["电压"]->ToString()->Trim() + " V";
		currenttextBox1->Text = row["电流"]->ToString()->Trim() + " A";
		powernumbertextBox1->Text = row["供电区间编号"]->ToString()->Trim();
		powerlongtextBox1->Text = power_l.ToString();
		//positiontextBox1->Text = power_s[powerpassnum - 1].ToString();
	}
}
};
}
