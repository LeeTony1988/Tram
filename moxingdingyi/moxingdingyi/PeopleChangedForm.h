#pragma once

namespace moxingdingyi {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//
	using namespace System::Data::SqlClient;
	using namespace System::Data::Common;
	using namespace System::Data::OleDb;
	/// <summary>
	/// PeopleChangedForm 摘要
	/// </summary>
	public ref class PeopleChangedForm : public System::Windows::Forms::Form
	{
	public:
		PeopleChangedForm(void)
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
		~PeopleChangedForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::GroupBox^  groupBox1;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->AxisX->Interval = 1;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 62);
			this->chart1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::SplineArea;
			series1->IsValueShownAsLabel = true;
			series1->Legend = L"Legend1";
			series1->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series1->Name = L"series1";
			series1->SmartLabelStyle->Enabled = false;
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Single;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int32;
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(1100, 493);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			this->chart1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PeopleChangedForm::chart1_Paint);
			// 
			// groupBox1
			// 
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(970, 45);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"方案调整框";
			// 
			// PeopleChangedForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1019, 563);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->chart1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"PeopleChangedForm";
			this->Text = L"peoplechange";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public: System::Data::DataTable^ ExecuteQuery(String ^sqlStr){//自定义查询数据库函数
				String^ cmd = String::Format("Data Source=localhost;Initial Catalog=电车数据库;Integrated Security=True");
				SqlConnection^ con = gcnew SqlConnection(cmd);
				con->Open();
				SqlDataAdapter^ da = gcnew SqlDataAdapter(sqlStr, cmd);
				DataTable^ dt = gcnew DataTable;
				da->Fill(dt);
				con->Close();
				return dt;
	}
	private: ArrayList^ stationnamelist = gcnew ArrayList();
			 ArrayList^ secondstationnamelist = gcnew ArrayList();
			 ArrayList^ numberlist = gcnew ArrayList();
			 ArrayList^ list2 = gcnew ArrayList();
	private: System::Void chart1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 DataTable^ table1 = gcnew DataTable();
				 DataTable^ table2 = gcnew DataTable();
				 DataTable^ table3 = gcnew DataTable();
				 table1 = ExecuteQuery("SELECT * FROM 线路人流量数据表 WHERE 列车编号='001';");
				 // table2 = ExecuteQuery("SELECT COUNT(DISTINCT 方案编号) FROM 线路人流量数据表;");
				 table2 = ExecuteQuery("SELECT DISTINCT 方案编号 AS 方案编号 FROM 线路人流量数据表;");
				 table3 = ExecuteQuery("SELECT 站点名称 ,车内人数 FROM 线路人流量数据表;");

				 int i, projectcount, stationcount, count;
				 if (table1->Rows->Count != 0){
					 stationnamelist->Clear();
					 for (i = 0; i < table1->Rows->Count; i++){
						 stationnamelist->Add(table1->Rows[i]->ItemArray[2]);
					 }
				 }
				 stationcount = table1->Rows->Count;
				 projectcount = table2->Rows->Count;
				 count = table3->Rows->Count;



				 array<String^>^ site = gcnew array<String^>(stationnamelist->Count);
				 array<String^>^ site1 = gcnew array<String^>(count);

				 for (i = 0; i < stationnamelist->Count; i++){
					 site[i] = stationnamelist[i]->ToString();
				 }

				 array<array<int>^>^ plan = gcnew array<array<int>^>(projectcount);
				 array<int>^ menber = gcnew array<int>(stationcount);

				 array<int>^ menber1 = gcnew array<int>(stationcount*projectcount);



				 secondstationnamelist->Clear();
				 for (i = 0; i < count; i++){
					 secondstationnamelist->Add(table3->Rows[i]->ItemArray[0]);
				 }
				 for (i = 0; i < table3->Rows->Count; i++){
					 site1[i] = secondstationnamelist[i]->ToString();
				 }
				 if (table3->Rows->Count != 0){
					 numberlist->Clear();
					 for (int i = 0, j = 0, k = 0; i < table3->Rows->Count; i++){
						 if (j == stationcount){
							 j = 0;
						 }
						 if (site[j] == site1[k]){
							 numberlist->Add(table3->Rows[i]->ItemArray[1]);
							 k++;
						 }
						 else{
							 numberlist->Add(0);
						 }
						 j++;

					 }
				 }
				 numberlist->CopyTo(menber1);


				 if (table2->Rows->Count != 0){
					 list2->Clear();
					 for (i = 0; i <projectcount; i++){
						 list2->Add(table2->Rows[i]->ItemArray[0]);
					 }
				 }
				 chart1->Series->Clear();
				 int k;

				 for (i = 0; i < projectcount; i++){
					 System::Windows::Forms::DataVisualization::Charting::Series^  series = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
					 series->ChartArea = L"ChartArea1";
					 series->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StackedColumn;
					 series->IsValueShownAsLabel = true;
					 series->Legend = L"Legend1";
					 series->Name = list2[i]->ToString();
					 series->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
					 chart1->Series->Add(series);
					 for (int j = 0; j < stationcount; j++){
						 menber[j] = menber1[j + k];
					 }
					 series->Points->DataBindXY(site, menber);
					 k += stationcount;


				 }

	}
	};
}
