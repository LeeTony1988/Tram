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
	/// ManydaysForm 摘要
	/// </summary>
	public ref class ManydaysForm : public System::Windows::Forms::Form
	{
	public:
		ManydaysForm(void)
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
		~ManydaysForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ToolTip^  toolTip1;
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
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// toolTip1
			// 
			this->toolTip1->AutomaticDelay = 300;
			this->toolTip1->AutoPopDelay = 5000;
			this->toolTip1->InitialDelay = 100;
			this->toolTip1->IsBalloon = true;
			this->toolTip1->ReshowDelay = 60;
			this->toolTip1->UseFading = false;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(257, 44);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 28);
			this->dateTimePicker1->TabIndex = 0;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &ManydaysForm::dateTimePicker1_ValueChanged);
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(641, 44);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(200, 28);
			this->dateTimePicker2->TabIndex = 1;
			this->dateTimePicker2->ValueChanged += gcnew System::EventHandler(this, &ManydaysForm::dateTimePicker2_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(519, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"——";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(84, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 18);
			this->label2->TabIndex = 3;
			this->label2->Text = L"选择日期";
			// 
			// Manydays
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1286, 724);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Name = L"Manydays";
			this->Text = L"Manydays";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &ManydaysForm::Manydays_Load);
			this->Click += gcnew System::EventHandler(this, &ManydaysForm::Manydays_Click);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:SqlConnection^ con = gcnew SqlConnection();
	private:ArrayList^ nemberlist = gcnew ArrayList();
			ArrayList^ secondnemberlist = gcnew ArrayList();
			ArrayList^ trainnemberlist = gcnew ArrayList();



	private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 ShowPeopleFlow();
	}
	private: System::Void dateTimePicker2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 ShowPeopleFlow();
	}
	private:System::Void ShowPeopleFlow(){
				String^ cmd = String::Format("Data Source=DESKTOP-5TU40C0;Initial Catalog=电车数据库;Integrated Security=True");
				con->ConnectionString = cmd;

				int i;

				con->Open();
				String^selectsql = String::Format("SELECT 列车编号, SUM(车内人数) FROM 线路人流量数据表 WHERE 时间 BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}')) GROUP BY 列车编号,时间;",
					this->dateTimePicker1->Value.ToShortDateString(), this->dateTimePicker2->Value.ToShortDateString());
				SqlDataAdapter^ da = gcnew SqlDataAdapter(selectsql, con);
				DataTable^ peopleflowdt = gcnew DataTable();
				da->Fill(peopleflowdt);
				con->Close();

				Graphics^ p = this->CreateGraphics();
				Pen^pen1 = gcnew Pen(this->BackColor);
				SolidBrush^ pbrush1 = gcnew SolidBrush(BackColor);
				Rectangle rec1(0, 0, 1200, 1000);
				p->DrawRectangle(pen1, rec1);
				p->FillRectangle(pbrush1, rec1);
				Rectangle rec2 = Rectangle(1120, 30, 150, 2000);
				p->DrawRectangle(pen1, rec2);
				p->FillRectangle(pbrush1, rec2);

				int days = this->dateTimePicker2->Value.DayOfYear - this->dateTimePicker1->Value.DayOfYear;
				if (days >= 0){
					days++;
					array<array<float>^>^ day = gcnew array<array<float>^>(days);
					array<int>^ trains = gcnew array<int>(days);
					int count = 0, j = 0, count1;
					count1 = peopleflowdt->Rows->Count;

					array<int>^ nember = gcnew array<int>(count1);
					array<float>^ empty1 = gcnew array<float>(count1);
					array<float>^ zero = { 0 };
					con->Open();
					for (i = 0; i < days, j < days; i++){
						String^selectsql1 = String::Format("SELECT 列车编号,SUM(车内人数) FROM 线路人流量数据表 WHERE 时间 BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}')) GROUP BY 列车编号;",
							this->dateTimePicker1->Value.AddDays(i).ToShortDateString(), this->dateTimePicker1->Value.AddDays(i).ToShortDateString());
						SqlDataAdapter^ da1 = gcnew SqlDataAdapter(selectsql1, con);
						DataTable^ peopleflowdt1 = gcnew DataTable();
						da1->Fill(peopleflowdt1);
						nemberlist->Clear();
						if (peopleflowdt1->Rows->Count != 0){
							for (i = 0; i < peopleflowdt1->Rows->Count; i++){
								nemberlist->Add(peopleflowdt1->Rows[i]->ItemArray[1]);
							}
							for (i = 0; i < nemberlist->Count; i++){
								nember[i] = int::Parse(nemberlist[i]->ToString());
							}
							for (i = 0; i < nemberlist->Count; i++){
								empty1[i] = (276 * 14 - nember[i]) / (2.76 * 14);
							}
						}
						count = peopleflowdt1->Rows->Count;
						trains[j] = count;
						if (trains[j]){
							day[j] = empty1;
						}
						else{
							day[j] = zero;
						}
						j++;
					}
					con->Close();
					//画图


					Pen^ pen = gcnew Pen(Brushes::Black);
					Rectangle rec(80, 100, 1000, 500);
					p->DrawRectangle(pen, rec);

					//画横线
					int x, y;
					for (j = 0, y = 0; j < 5; j++){
						Point p3 = Point(80, 100 + y);
						Point p4 = Point(1080, 100 + y);
						p->DrawLine(pen, p3, p4);
						y += 100;
					}
					//设置纵坐标为空载率
					array<String^>^ empty = gcnew array<String^>{"0", "20%", "40%", "60%", "80%", "100%"};
					for (j = 0, y = 0; j < 6; j++){
						p->DrawString(empty[j], Font, Brushes::Black, 52, 595 + y);
						y -= 100;
					}
					p->DrawString("空载率", Font, Brushes::Black, 45, 60);
					//画竖线
					for (i = 0, x = 0; i < 5; i++){
						Point p1 = Point(80 + x, 600);
						Point p2 = Point(80 + x, 100);
						p->DrawLine(pen, p1, p2);
						x += 200;
					}
					//设置横坐标为车辆数

					array<int>^ x_arr = gcnew array<int>(5);
					array<String^>^ x_arr1 = gcnew array<String^>(5);
					int interval = count1 / 5 + 1;
					for (i = 0; i < 5; i++){
						x_arr[i] = interval*(i + 1);
						x_arr1[i] = x_arr[i].ToString();
					}
					for (i = 0, x = 200; i < 5; i++){
						p->DrawString(x_arr1[i], Font, Brushes::Black, 75 + x, 610);
						x += 200;
					}
					p->DrawString("列车数", Font, Brushes::Black, 1080, 640);
					//画柱子


					int k = 0, q, m = 0, b = 0;
					static float a = 0;

					for (k = 0, a = 0, q = 0; k < days; k++){
						if (78 + m>255){
							m -= 175;
						}
						SolidBrush^ brush1 = gcnew SolidBrush(Color::FromArgb(54 + m, 63 + m, 78 + m));
						if (day[k] != zero){
							for (j = 0; j < day[k]->Length; j++){
								Rectangle rec1 = Rectangle(80 + a, 600 - 5 * day[k][j], 200 / interval, 5 * day[k][j]);
								p->DrawRectangle(pen, rec1);
								p->FillRectangle(brush1, rec1);
								a += 200 / interval;
							}
						}
						Rectangle rec2 = Rectangle(1120, 30 + b, 40, 15);
						p->FillRectangle(brush1, rec2);
						p->DrawString(this->dateTimePicker1->Value.AddDays(k).ToShortDateString(), Font, Brushes::Black, 1190, 30 + b);
						b += 20;
						q += 30;
						m += 40;
					}
				}
	}

private: System::Void Manydays_Click(System::Object^  sender, System::EventArgs^  e) {
			 con->Open();
			 String^selectsql11 = String::Format("SELECT 列车编号, SUM(车内人数) FROM 线路人流量数据表 WHERE 时间 BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}')) GROUP BY 列车编号,时间;",
				 this->dateTimePicker1->Value.ToShortDateString(), this->dateTimePicker2->Value.ToShortDateString());
			 SqlDataAdapter^ da2 = gcnew SqlDataAdapter(selectsql11, con);
			 DataTable^ peopleflowdt2 = gcnew DataTable();
			 da2->Fill(peopleflowdt2);
			 con->Close();
			 int i, a;
			 int count = peopleflowdt2->Rows->Count;
			 array<int>^ secondnember = gcnew array<int>(count);
			 array<float>^ secondempty1 = gcnew array<float>(count);
			 array<String^>^ trainmenber = gcnew array<String^>(count);
			 secondnemberlist->Clear();
			 if (peopleflowdt2->Rows->Count != 0){
				 for (i = 0; i < peopleflowdt2->Rows->Count; i++){
					 secondnemberlist->Add(peopleflowdt2->Rows[i]->ItemArray[1]);
				 }
				 for (i = 0; i < secondnemberlist->Count; i++){
					 secondnember[i] = int::Parse(secondnemberlist[i]->ToString());
				 }
				 for (i = 0; i < secondnemberlist->Count; i++){
					 secondempty1[i] = (276 * 14 - secondnember[i]) / (2.76 * 14);
				 }
			 }
			 trainnemberlist->Clear();
			 if (peopleflowdt2->Rows->Count != 0){
				 for (i = 0; i < peopleflowdt2->Rows->Count; i++){
					 trainnemberlist->Add(peopleflowdt2->Rows[i]->ItemArray[0]);
				 }
				 for (i = 0; i < trainnemberlist->Count; i++){
					 trainmenber[i] = trainnemberlist[i]->ToString();
				 }
			 }
			 int interval = count / 5 + 1;
			 array<float>^ xposition = gcnew array<float>(count + 1);
			 array<float>^ yposition = gcnew array<float>(count);
			 //取横坐标
			 for (i = 0, a = 0; i < count + 1; i++){
				 xposition[i] = 80 + a;
				 a += 200 / interval;
			 }
			 //取纵坐标
			 int days = this->dateTimePicker2->Value.DayOfYear - this->dateTimePicker1->Value.DayOfYear;
			 if (days >= 0){
				 days++;
				 array<array<float>^>^ day = gcnew array<array<float>^>(days);
				 array<int>^ trains = gcnew array<int>(days);
				 int  k = 0, j = 0, count1;

				 array<int>^ nember = gcnew array<int>(count);
				 array<float>^ empty1 = gcnew array<float>(count);
				 array<float>^ zero = { 0 };
				 con->Open();
				 for (i = 0; i < days, j < days; i++){
					 String^selectsql1 = String::Format("SELECT 列车编号,SUM(车内人数) FROM 线路人流量数据表 WHERE 时间 BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}')) GROUP BY 列车编号;",
						 this->dateTimePicker1->Value.AddDays(i).ToShortDateString(), this->dateTimePicker1->Value.AddDays(i).ToShortDateString());
					 SqlDataAdapter^ da1 = gcnew SqlDataAdapter(selectsql1, con);
					 DataTable^ peopleflowdt1 = gcnew DataTable();
					 da1->Fill(peopleflowdt1);
					 nemberlist->Clear();
					 if (peopleflowdt1->Rows->Count != 0){
						 for (i = 0; i < peopleflowdt1->Rows->Count; i++){
							 nemberlist->Add(peopleflowdt1->Rows[i]->ItemArray[1]);
						 }
						 for (i = 0; i < nemberlist->Count; i++){
							 nember[i] = int::Parse(nemberlist[i]->ToString());
						 }
						 for (i = 0; i < nemberlist->Count; i++){
							 empty1[i] = (276 * 14 - nember[i]) / (2.76 * 14);
						 }
					 }
					 count1 = peopleflowdt1->Rows->Count;
					 trains[j] = count1;
					 if (trains[j]){
						 day[j] = empty1;
					 }
					 else{
						 day[j] = zero;
					 }
					 j++;
				 }
				 con->Close();

				 for (i = 0; i < days; i++){
					 if (day[i] != zero){
						 for (j = 0; j < day[i]->Length; j++){
							 yposition[k] = 600 - 5 * day[i][j];
							 k++;
						 }
					 }
				 }
				 Point sc = Control::MousePosition;
				 double x = Control::MousePosition.X;
				 double y = Control::MousePosition.Y;
				 toolTip1->Hide(this);
				 if (x >= xposition[0] && x <= xposition[count]){
					 for (i = 0; i < count; i++){
						 if (x >= xposition[i] && x < xposition[i + 1] && y >= yposition[i] + 20 && y < 620){
							 for (j = 0; j < days; j++){
								 if (j != 0){
									 trains[j] = trains[j] + trains[j - 1];
								 }
								 if (i + 1 <= trains[j]){
									 break;
								 }
							 }

							 toolTip1->Show(this->dateTimePicker1->Value.AddDays(j).ToShortDateString() + "\n" + "列车编号： " + trainmenber[i] + "\n" + "空载率： " + secondempty1[i].ToString("0.0") + "%", this, sc);
						 }
					 }
				 }
			 }


}
private: System::Void Manydays_Load(System::Object^  sender, System::EventArgs^  e) {
			 String^ cmd = String::Format("Data Source=localhost;Initial Catalog=电车数据库;Integrated Security=True");
			 con->ConnectionString = cmd;
}
	};
}
