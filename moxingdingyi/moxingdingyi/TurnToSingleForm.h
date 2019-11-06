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
	/// TurnToSingleForm 摘要
	/// </summary>
	public ref class TurnToSingleForm : public System::Windows::Forms::Form
	{
	public:
		TurnToSingleForm(void)
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
		~TurnToSingleForm()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// shiyan
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1286, 724);
			this->Name = L"shiyan";
			this->Text = L"shiyan";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &TurnToSingleForm::shiyan_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &TurnToSingleForm::shiyan_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:SqlConnection^ con = gcnew SqlConnection();
	public:String^ proposal;
		   String^ date;
	private:ArrayList^ GetonNemberlist = gcnew ArrayList();
			ArrayList^ GetoffNemberlist = gcnew ArrayList();
			ArrayList^ SiteName = gcnew ArrayList();
			ArrayList^ StationName = gcnew ArrayList();
	private: System::Void shiyan_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 String^ cmd = String::Format("Data Source=localhost;Initial Catalog=电车数据库;Integrated Security=True");
				 con->ConnectionString = cmd;

				 con->Open();
				 String^ selectsql1 = String::Format("SELECT 站点名称,上车人数,下车人数 FROM 线路人流量数据表 WHERE 方案编号='{0}'AND 时间 BETWEEN '{1}' AND dateadd(second,-1,dateadd(day,1,'{2}'))",
					 proposal, date, date);
				 SqlDataAdapter^ da = gcnew SqlDataAdapter(selectsql1, con);
				 DataTable^ peopleflow = gcnew DataTable();
				 da->Fill(peopleflow);
				 String^ selectsql2 = String::Format("SELECT 站点名称 FROM 线路人流量数据表 WHERE 列车编号='001';");
				 SqlDataAdapter^ da2 = gcnew SqlDataAdapter(selectsql2, con);
				 DataTable^ stationname = gcnew DataTable();
				 da2->Fill(stationname);
				 con->Close();

				 int i;
				 Graphics^ p = this->CreateGraphics();
				 Pen^ pen = gcnew Pen(Brushes::Black);
				 Rectangle rec(80, 100, 900, 400);
				 p->DrawRectangle(pen, rec);
				 int a = stationname->Rows->Count;
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
				 StationName->Clear();
				 for (i = 0; i < stationname->Rows->Count; i++){
					 StationName->Add(stationname->Rows[i]->ItemArray[0]);
				 }
				 array<String^>^ sitename = gcnew array<String^>(StationName->Count);
				 for (i = 0; i < StationName->Count; i++){
					 sitename[i] = StationName[i]->ToString();
				 }

				 SiteName->Clear();
				 if (peopleflow->Rows->Count != 0){
					 for (i = 0; i < peopleflow->Rows->Count; i++){
						 SiteName->Add(peopleflow->Rows[i]->ItemArray[0]);
					 }
				 }
				 array<String^>^ sitename1 = gcnew array<String^>(StationName->Count);
				 for (i = 0; i < SiteName->Count; i++){
					 sitename1[i] = SiteName[i]->ToString();
				 }

				 StringFormat^ strf = gcnew StringFormat(StringFormatFlags::DirectionVertical);
				 for (i = 0, x = 60; i < a; i++){
					 p->DrawString(StationName[i]->ToString(), Font, Brushes::Brown, 75 + x, 505, strf);
					 x += 60;
				 }
				 //画柱状图
				 GetonNemberlist->Clear();
				 if (peopleflow->Rows->Count != 0){
					 for (int i = 0, k = 0; i < peopleflow->Rows->Count; i++){
						 if (sitename[i] == sitename1[k]){
							 GetonNemberlist->Add(peopleflow->Rows[i]->ItemArray[1]);
							 k++;
						 }
						 else{
							 GetonNemberlist->Add(0);
						 }
					 }
				 }
				 MessageBox::Show(GetonNemberlist->Count.ToString());
				 array<int>^ geton = gcnew array<int>(a);
				 GetonNemberlist->CopyTo(geton);

				 for (int k = 0, x = 60; k < a; k++){
					 Rectangle rec1 = Rectangle(70 + x, 500 - 40 * geton[k] / 3, 20, 40 * geton[k] / 3);
					 p->DrawRectangle(pen, rec1);
					 p->FillRectangle(Brushes::SkyBlue, rec1);
					 p->DrawString(geton[k].ToString(), Font, Brushes::Black, 71 + x, 500 - 40 * geton[k] / 6);
					 x += 60;
				 };

				 GetoffNemberlist->Clear();
				 if (peopleflow->Rows->Count != 0){
					 for (int i = 0, k = 0; i < peopleflow->Rows->Count; i++){
						 if (sitename[i] == sitename1[k]){
							 GetoffNemberlist->Add(peopleflow->Rows[i]->ItemArray[2]);
							 k++;
						 }
						 else{
							 GetoffNemberlist->Add(0);
						 }
					 }
				 }
				 array<int>^ getoff = gcnew array<int>(a);
				 GetoffNemberlist->CopyTo(getoff);

				 for (int k = 0, x = 60; k < a; k++){
					 Rectangle rec2 = Rectangle(70 + x, 500 - 40 * geton[k] / 3 - 40 * getoff[k] / 3, 20, 40 * getoff[k] / 3);
					 p->DrawRectangle(pen, rec2);
					 p->FillRectangle(Brushes::Orange, rec2);
					 p->DrawString(getoff[k].ToString(), Font, Brushes::Black, 71 + x, 500 - 40 * geton[k] / 3 - 40 * getoff[k] / 6);
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
				 for (i = 0; i < a; i++){
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
	private: System::Void shiyan_Load(System::Object^  sender, System::EventArgs^  e) {
				 MessageBox::Show(proposal);
				 MessageBox::Show(date);
	}
	};
}
