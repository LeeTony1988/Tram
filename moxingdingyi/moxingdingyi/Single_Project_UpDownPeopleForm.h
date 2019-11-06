#pragma once
#include"ManydaysForm.h"
#include"PeopleChangedForm.h"
#include"TimeandEmptyrateForm.h"

namespace moxingdingyi {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//
	using namespace System::Drawing::Drawing2D;
	using namespace System::Data::SqlClient;
	using namespace System::Data::Common;
	using namespace System::Data::OleDb;

	/// <summary>
	/// Single_Project_UpDownPeopleForm 摘要
	/// </summary>
	public ref class Single_Project_UpDownPeopleForm : public System::Windows::Forms::Form
	{
	public:
		Single_Project_UpDownPeopleForm(void)
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
		~Single_Project_UpDownPeopleForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  多天ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  各方案车内人数ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  运行时间及空载率统计ToolStripMenuItem;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->多天ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->各方案车内人数ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->运行时间及空载率统计ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Transparent;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->多天ToolStripMenuItem,
					this->各方案车内人数ToolStripMenuItem, this->运行时间及空载率统计ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(929, 25);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 多天ToolStripMenuItem
			// 
			this->多天ToolStripMenuItem->Name = L"多天ToolStripMenuItem";
			this->多天ToolStripMenuItem->Size = System::Drawing::Size(104, 21);
			this->多天ToolStripMenuItem->Text = L"多天方案空载率";
			this->多天ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Single_Project_UpDownPeopleForm::多天ToolStripMenuItem_Click);
			// 
			// 各方案车内人数ToolStripMenuItem
			// 
			this->各方案车内人数ToolStripMenuItem->Name = L"各方案车内人数ToolStripMenuItem";
			this->各方案车内人数ToolStripMenuItem->Size = System::Drawing::Size(104, 21);
			this->各方案车内人数ToolStripMenuItem->Text = L"各方案车内人数";
			this->各方案车内人数ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Single_Project_UpDownPeopleForm::各方案车内人数ToolStripMenuItem_Click);
			// 
			// 运行时间及空载率统计ToolStripMenuItem
			// 
			this->运行时间及空载率统计ToolStripMenuItem->Name = L"运行时间及空载率统计ToolStripMenuItem";
			this->运行时间及空载率统计ToolStripMenuItem->Size = System::Drawing::Size(140, 21);
			this->运行时间及空载率统计ToolStripMenuItem->Text = L"运行时间及空载率统计";
			this->运行时间及空载率统计ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Single_Project_UpDownPeopleForm::运行时间及空载率统计ToolStripMenuItem_Click);
			// 
			// Single_Project_UpDownPeopleForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(929, 476);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Single_Project_UpDownPeopleForm";
			this->Text = L"Single_Project_UpDownPeopleForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Single_Project_UpDownPeopleForm::Form1_Paint);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:SqlConnection^ con = gcnew SqlConnection();
	public: System::Data::DataTable^ ExecuteQuery(String ^sqlStr){//自定义查询数据库函数
				String^ cmd = String::Format("Data Source=localhost;Initial Catalog=电车数据库;Integrated Security=True");
				con->ConnectionString = cmd;
				con->Open();
				SqlDataAdapter^ da = gcnew SqlDataAdapter(sqlStr, cmd);
				DataTable^ dt = gcnew DataTable;
				da->Fill(dt);
				con->Close();
				return dt;
	}

	private: ArrayList^ list = gcnew ArrayList();
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 DataTable^ table1 = gcnew DataTable();
				 table1 = ExecuteQuery("SELECT * FROM 线路人流量数据表 WHERE 列车编号='001';");
				 int i;
				 Graphics^ p = this->CreateGraphics();
				 Pen^ pen = gcnew Pen(Brushes::Black);
				 Rectangle rec(80, 100, 900, 400);
				 p->DrawRectangle(pen, rec);
				 int a = table1->Rows->Count;                   //设置站点数
				 //画网格线
				 int x = 0;
				 for (int i = 0; i < a + 1; i++){
					 Point p1 = Point(80 + x, 100);
					 Point p2 = Point(80 + x, 500);
					 p->DrawLine(pen, p1, p2);
					 x += 60;
				 }
				 int y = 0;
				 for (int j = 0; j < 10; j++){
					 Point p3 = Point(80, 100 + y);
					 Point p4 = Point(980, 100 + y);
					 p->DrawLine(pen, p3, p4);
					 y += 40;
				 }
				 //设置横坐标
				 if (table1->Rows->Count != 0){
					 list->Clear();
					 for (i = 0; i < table1->Rows->Count; i++){
						 list->Add(table1->Rows[i]->ItemArray[2]);
					 }
				 }
				 StringFormat^ strf = gcnew StringFormat(StringFormatFlags::DirectionVertical);
				 for (i = 0, x = 60; i < a; i++){
					 p->DrawString(list[i]->ToString(), Font, Brushes::Brown, 75 + x, 505, strf);
					 x += 60;
				 }

				 //画柱状图
				 if (table1->Rows->Count != 0){
					 list->Clear();
					 for (i = 0; i < table1->Rows->Count; i++){
						 list->Add(table1->Rows[i]->ItemArray[3]);
					 }
				 }
				 list->Add(1);
				 list->Add(2);
				 list->Add(3);
				 array<int>^ geton = gcnew array<int>(list->Count);
				 list->CopyTo(geton);

				 for (int k = 0, x = 60; k < a; k++){
					 Rectangle rec1 = Rectangle(70 + x, 500 - 40 * geton[k] / 3, 20, 40 * geton[k] / 3);
					 p->DrawRectangle(pen, rec1);
					 p->FillRectangle(Brushes::SkyBlue, rec1);
					 p->DrawString(geton[k].ToString(), Font, Brushes::Black, 71 + x, 500 - 40 * geton[k] / 6);
					 x += 60;
				 };

				 if (table1->Rows->Count != 0){
					 list->Clear();
					 for (i = 0; i < table1->Rows->Count; i++){
						 list->Add(table1->Rows[i]->ItemArray[4]);
					 }
				 }
				 list->Add(1);
				 list->Add(2);
				 list->Add(3);
				 array<int>^ getoff = gcnew array<int>(list->Count);
				 list->CopyTo(getoff);

				 array<String^>^ getoff1 = gcnew array<String^>(a);
				 for (i = 0; i < a; i++){
					 getoff1[i] = getoff[i].ToString();
				 }
				 for (int k = 0, x = 60; k < a; k++){
					 Rectangle rec2 = Rectangle(70 + x, 500 - 40 * geton[k] / 3 - 40 / 3 * getoff[k], 20, 40 / 3 * getoff[k]);
					 p->DrawRectangle(pen, rec2);
					 p->FillRectangle(Brushes::Orange, rec2);
					 p->DrawString(getoff1[k], Font, Brushes::Black, 71 + x, 500 - 40 / 3 * geton[k] - 40 / 3 * getoff[k] / 2);
					 x += 60;
				 }
				 Rectangle rec3 = Rectangle(1050, 30, 30, 15);
				 p->DrawRectangle(pen, rec3);
				 p->FillRectangle(Brushes::SkyBlue, rec3);
				 p->DrawString("上车人数", Font, Brushes::Black, 1090, 30);
				 Rectangle rec4 = Rectangle(1050, 50, 30, 15);
				 p->DrawRectangle(pen, rec4);
				 p->FillRectangle(Brushes::Orange, rec4);
				 p->DrawString("下车人数", Font, Brushes::Black, 1090, 50);
				 //设置纵坐标
				 array<int>^s = gcnew array<int>(a + 1);
				 s[0] = 0;
				 for (i = 0; i < a; i++){
					 s[i + 1] = geton[i] + getoff[i];
				 }
				 int max;
				 max = s[0];
				 for (i = 1; i < a; i++){
					 if (max < s[i]){
						 max = s[i];
					 }
				 }
				 int n, b;
				 b = max / 10;

				 for (n = 0;; n++){
					 if (max != 10 * b){
						 if (10 * n < max&&max < 10 * (n + 1)){
							 b = 10 * (n + 1);
							 break;
						 }
					 }
				 }
				 array<float>^ number = gcnew array<float>(11);
				 array<String^>^ number1 = gcnew array<String^>(11);
				 for (i = 0; i < 11; i++){
					 number[i] = b / 10 * i;
					 number1[i] = number[i].ToString();
				 }
				 //array<String^>^ number = gcnew array<String^>{ "0", "30", "60", "90", "120", "150", "180", "210", "240", "270", "300" };
				 for (int j = 0, y = 0; j < 11; j++){
					 p->DrawString(number1[j], Font, Brushes::Red, 52, 495 + y);
					 y -= 40;
				 }
				 //显示车内人数
				 array<int>^ sum = gcnew array<int>(a);
				 array<String^>^ sum1 = gcnew array<String^>(a);
				 for (int j = 0; j < a; j++){
					 if (j == 0){
						 sum[j] = geton[j] - getoff[j];
					 }
					 else{
						 sum[j] = sum[j - 1] + geton[j] - getoff[j];
					 }
					 sum1[j] = sum[j].ToString();
				 }
				 for (int i = 0, x = 60; i < a; i++){
					 p->DrawString("车内", Font, Brushes::Black, 75 + x, 40, strf);
					 p->DrawString(sum1[i], Font, Brushes::Black, 73 + x, 70);
					 p->DrawString("人", Font, Brushes::Black, 73 + x, 85);
					 x += 60;
				 }
				 //计算各站空载率
				 for (int i = 0; i < a; i++){
					 sum[i] = (276 - sum[i]) / 2.76;             //设置车内座位为276
					 sum1[i] = sum[i].ToString("0.0");
					 sum1[i] += L"%";
				 }
				 p->DrawString("各站空载率", Font, Brushes::Black, 10, 580);
				 for (int j = 0, x = 60; j < a; j++){
					 p->DrawString(sum1[j], Font, Brushes::Black, 70 + x, 580);
					 x += 60;
				 }
				 //计算平均空载率
				 float aver = 0;
				 for (int i = 0; i < a; i++){
					 aver += sum[i];
				 }
				 aver = aver / a;
				 String^ aver1;
				 aver1 = aver.ToString("0.0");
				 aver1 += L"%";
				 p->DrawString("平均空载率为", Font, Brushes::Black, 10, 610);
				 p->DrawString(aver1, Font, Brushes::Black, 120, 610);
				 //计算该车次总载容量
				 int total = 0;
				 for (int j = 0; j < a; j++){
					 total += geton[j];
				 }
				 String^ total1;
				 total1 = total.ToString();
				 total1 += L"人";
				 p->DrawString("该车次总载容量", Font, Brushes::Black, 10, 640);
				 p->DrawString(total1, Font, Brushes::Black, 120, 640);

	}
	private: System::Void 多天ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 ManydaysForm^form1 = gcnew ManydaysForm();
				 form1->Show();
	}
private: System::Void 各方案车内人数ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 PeopleChangedForm^form2 = gcnew PeopleChangedForm();
			 form2->Show();
}
private: System::Void 运行时间及空载率统计ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 TimeandEmptyrateForm^form3 = gcnew TimeandEmptyrateForm();
			 form3->Show();
}
};
}
