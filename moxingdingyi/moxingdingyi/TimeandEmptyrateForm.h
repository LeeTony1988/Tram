#pragma once
#include"TurnToSingleForm.h"
namespace moxingdingyi {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// TimeandEmptyrateForm 摘要
	/// </summary>
	public ref class TimeandEmptyrateForm : public System::Windows::Forms::Form
	{
	public:
		TimeandEmptyrateForm(void)
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
		~TimeandEmptyrateForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  选择需要显示的方案ToolStripMenuItem;

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->选择需要显示的方案ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->dateTimePicker1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->menuStrip1);
			this->groupBox1->Location = System::Drawing::Point(23, 8);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox1->Size = System::Drawing::Size(668, 44);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"方案调整框";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CalendarTitleBackColor = System::Drawing::Color::White;
			this->dateTimePicker1->Location = System::Drawing::Point(97, 13);
			this->dateTimePicker1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(135, 21);
			this->dateTimePicker1->TabIndex = 6;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &TimeandEmptyrateForm::dateTimePicker1_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(27, 18);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"请选择日期";
			// 
			// menuStrip1
			// 
			this->menuStrip1->AutoSize = false;
			this->menuStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->选择需要显示的方案ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(365, 12);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(135, 23);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 选择需要显示的方案ToolStripMenuItem
			// 
			this->选择需要显示的方案ToolStripMenuItem->BackColor = System::Drawing::Color::White;
			this->选择需要显示的方案ToolStripMenuItem->Name = L"选择需要显示的方案ToolStripMenuItem";
			this->选择需要显示的方案ToolStripMenuItem->Size = System::Drawing::Size(128, 21);
			this->选择需要显示的方案ToolStripMenuItem->Text = L"选择需要显示的方案";
			this->选择需要显示的方案ToolStripMenuItem->CheckedChanged += gcnew System::EventHandler(this, &TimeandEmptyrateForm::选择需要显示的方案ToolStripMenuItem_CheckedChanged);
			// 

			// timeandemptyrate
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(827, 499);
			this->Controls->Add(this->groupBox1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"timeandemptyrate";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Click += gcnew System::EventHandler(this, &TimeandEmptyrateForm::timeandemptyrate_Click);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);


		}
#pragma endregion
	private:SqlConnection^ con = gcnew SqlConnection();
	public: System::Data::DataTable^ ExecuteQuery(SqlConnection^con1, String ^sqlStr) {//自定义查询数据库函数

		con1->Open();
		SqlDataAdapter^ da = gcnew SqlDataAdapter(sqlStr, con1);
		DataTable^ dt = gcnew DataTable();
		da->Fill(dt);
		con1->Close();
		return dt;
	}
			ArrayList^ Nemberlist = gcnew ArrayList();
			ArrayList^ proposalslist = gcnew ArrayList();
			ArrayList^runtimelist = gcnew ArrayList();
			ArrayList^Serialnumberlist = gcnew ArrayList();
			ArrayList^ flaglist = gcnew ArrayList();
			int count, count1, count2;
	private: System::Void timeandemptyrate_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {


		Graphics^ p = this->CreateGraphics();
		Pen^pen1 = gcnew Pen(this->BackColor);
		SolidBrush^ pbrush1 = gcnew SolidBrush(BackColor);
		Rectangle rec1(0, 100, 1000, 900);
		p->DrawRectangle(pen1, rec1);
		p->FillRectangle(pbrush1, rec1);
		Rectangle rec3 = Rectangle(1000, 30, 30, 15);
		p->DrawRectangle(pen1, rec3);
		p->FillRectangle(pbrush1, rec3);
		p->DrawString("空载率", Font, pbrush1, 1040, 30);
		Rectangle rec4 = Rectangle(1000, 50, 30, 15);
		p->DrawRectangle(pen1, rec4);
		p->FillRectangle(pbrush1, rec4);
		p->DrawString("运行时间", Font, pbrush1, 1040, 50);

		Rectangle rec(80, 100, 900, 400);

		Pen^ pen = gcnew Pen(Brushes::Black);

		int i = 0;

		// MessageBox::Show(count.ToString());
		count1 = 14;
		this->选择需要显示的方案ToolStripMenuItem->DropDownItems->Clear();

		array<String^>^Serialnumber2 = gcnew array<String^>(count2);
		for (i = 0; i < count2; i++) {
			Serialnumber2[i] = Serialnumberlist[i]->ToString();
		}
		//取标志数组
		array<int>^ flag = gcnew array<int>(count2);
		for (i = 0; i < flaglist->Count; i++)
		{
			flag[i] = int::Parse(flaglist[i]->ToString());
		}
		//取方案编号
		if (count != 0) {
			p->DrawRectangle(pen, rec);

			array<String^>^Serialnumber = gcnew array<String^>(count);
			for (i = 0; i < count; i++) {
				Serialnumber[i] = proposalslist[i]->ToString();
			}



			//取车内人数计算空载率					 

			array<String^>^ empty = gcnew array<String^>(count);
			array<float>^ empty1 = gcnew array<float>(count);
			for (i = 0; i < Nemberlist->Count; i++)
			{
				empty1[i] = float::Parse(Nemberlist[i]->ToString());
			}
			for (i = 0; i < count; i++) {
				empty1[i] = (276 * count1 - empty1[i]) / (2.76*count1);
				empty[i] = empty1[i].ToString("0.0");
				empty[i] += L"%";
			}

			//取运行时间

			array<String^>^ time = gcnew array<String^>(count);
			array<float>^ time1 = gcnew array<float>(count);
			for (int i = 0; i < runtimelist->Count; i++)
			{
				//MessageBox::Show(safe_cast<String^>(list[i])->ToString());
				time1[i] = float::Parse(runtimelist[i]->ToString());
			}
			for (i = 0; i < count; i++) {
				time[i] = time1[i].ToString();
			}
			//画网格线
			float x = 0;
			for (i = 0; i < count + 1; i++) {
				Point p1 = Point(80 + x, 100);
				Point p2 = Point(80 + x, 500);
				p->DrawLine(pen, p1, p2);
				x += 900 / (count + 1);
			}
			int y = 0;
			for (int j = 0; j < 10; j++) {
				Point p3 = Point(80, 100 + y);
				Point p4 = Point(980, 100 + y);
				p->DrawLine(pen, p3, p4);
				y += 40;
			}
			//设置横坐标
			for (i = 0, x = 900 / (count + 1); i < count; i++) {
				p->DrawString(Serialnumber[i], Font, Brushes::Brown, 65 + x, 510);
				x += 900 / (count + 1);
			}
			//画柱状图

			for (i = 0, x = 900 / (count + 1); i < count; i++) {
				Rectangle rec1 = Rectangle(65 + x, 500 - empty1[i], 30, empty1[i]);
				p->DrawRectangle(pen, rec1);
				p->FillRectangle(Brushes::SkyBlue, rec1);
				p->DrawString(empty[i], Font, Brushes::Black, 68 + x, 490 - empty1[i] / 2);
				x += 900 / (count + 1);
			}
			for (i = 0, x = 900 / (count + 1); i < count; i++) {
				Rectangle rec2 = Rectangle(65 + x, 500 - empty1[i] - time1[i] / 3, 30, time1[i] / 3);
				p->DrawRectangle(pen, rec2);
				p->FillRectangle(Brushes::Orange, rec2);
				p->DrawString(time[i], Font, Brushes::Black, 70 + x, 500 - empty1[i] - time1[i] / 6);
				x += 900 / (count + 1);
			}
			Rectangle rec3 = Rectangle(850, 30, 30, 15);
			p->DrawRectangle(pen, rec3);
			p->FillRectangle(Brushes::SkyBlue, rec3);
			p->DrawString("空载率", Font, Brushes::Black, 890, 30);
			Rectangle rec4 = Rectangle(850, 50, 30, 15);
			p->DrawRectangle(pen, rec4);
			p->FillRectangle(Brushes::Orange, rec4);
			p->DrawString("运行时间", Font, Brushes::Black, 890, 50);


		}
		//添加方案到控件
		// MessageBox::Show(flaglist->Count.ToString());

		for (i = 0; i < count2; i++) {
			System::Windows::Forms::ToolStripMenuItem^ toolstripmenuitem = gcnew System::Windows::Forms::ToolStripMenuItem();
			toolstripmenuitem->Name = L"toolStripMenuItem" + (i + 1).ToString();
			toolstripmenuitem->Size = System::Drawing::Size(122, 30);
			toolstripmenuitem->Text = Serialnumber2[i]->ToString();
			toolstripmenuitem->CheckOnClick = true;
			if (flag[i] == 1) {
				toolstripmenuitem->Checked = true;
			}
			this->选择需要显示的方案ToolStripMenuItem->DropDownItems->Add(toolstripmenuitem);
			toolstripmenuitem->CheckedChanged += gcnew System::EventHandler(this, &TimeandEmptyrateForm::选择需要显示的方案ToolStripMenuItem_CheckedChanged);
		}

	}
	private: System::Void timeandemptyrate_Click(System::Object^  sender, System::EventArgs^  e) {
		double x = Control::MousePosition.X;
		double y = Control::MousePosition.Y;
		int i = 0;
		String^ name;
		array<String^>^Serialnumber1 = gcnew array<String^>(proposalslist->Count);
		for (i = 0; i < proposalslist->Count; i++) {
			Serialnumber1[i] = proposalslist[i]->ToString();
		}
		float a = 900 / (proposalslist->Count + 1);
		if (y > 510 && y < 540) {
			for (i = 0; i < proposalslist->Count; i++) {
				if (x - a * (i + 1) > 65 && x - a * (i + 1) < 100) {
					name = Serialnumber1[i];
					SendDataTotime(name);
					break;
				}
			}
		}
	}
	private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		String^ cmd = String::Format("Data Source=DESKTOP-5TU40C0;Initial Catalog=电车数据库;Integrated Security=True");
		con->ConnectionString = cmd;

		con->Open();
		String^selectsql = String::Format("SELECT 方案编号,SUM(车内人数),SUM(运行时间) FROM 线路人流量数据表 WHERE 时间 BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}')) GROUP BY 方案编号;",
			this->dateTimePicker1->Value.ToShortDateString(), this->dateTimePicker1->Value.ToShortDateString());
		SqlDataAdapter^da = gcnew SqlDataAdapter(selectsql, con);
		DataTable^peopleflowdt = gcnew DataTable();
		da->Fill(peopleflowdt);
		con->Close();
		count = peopleflowdt->Rows->Count;
		count2 = peopleflowdt->Rows->Count;
		int i;

		proposalslist->Clear();
		if (count != 0) {
			for (i = 0; i < count; i++) {
				proposalslist->Add(peopleflowdt->Rows[i]->ItemArray[0]);
			}
		}

		Serialnumberlist->Clear();
		if (count != 0) {
			for (i = 0; i < count; i++) {
				Serialnumberlist->Add(peopleflowdt->Rows[i]->ItemArray[0]);
			}
		}

		Nemberlist->Clear();
		if (peopleflowdt->Rows->Count != 0) {
			for (i = 0; i < peopleflowdt->Rows->Count; i++) {
				Nemberlist->Add(peopleflowdt->Rows[i]->ItemArray[1]->ToString());
			}
		}

		flaglist->Clear();
		if (peopleflowdt->Rows->Count != 0) {
			for (i = 0; i < peopleflowdt->Rows->Count; i++) {
				flaglist->Add("1");
			}
		}

		runtimelist->Clear();
		if (peopleflowdt->Rows->Count != 0) {

			for (i = 0; i < peopleflowdt->Rows->Count; i++) {
				runtimelist->Add(peopleflowdt->Rows[i]->ItemArray[2]);
			}
		}

		timeandemptyrate_Paint(sender, nullptr);

	}

	private:System::Void SendDataTotime(String^proposalnum)
	{
		String^ datetime = this->dateTimePicker1->Value.ToShortDateString();
		TurnToSingleForm^ a = gcnew TurnToSingleForm();
		a->proposal = proposalnum;
		a->date = datetime;
		a->Show();
	}

	private: System::Void 选择需要显示的方案ToolStripMenuItem_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		String^ cmd = String::Format("Data Source=localhost;Initial Catalog=电车数据库;Integrated Security=True");
		con->ConnectionString = cmd;

		con->Open();
		String^selectsql = String::Format("SELECT 方案编号,SUM(车内人数),SUM(运行时间) FROM 线路人流量数据表 WHERE 时间 BETWEEN '{0}' AND dateadd(second,-1,dateadd(day,1,'{1}')) GROUP BY 方案编号;",
			this->dateTimePicker1->Value.ToShortDateString(), this->dateTimePicker1->Value.ToShortDateString());
		SqlDataAdapter^da = gcnew SqlDataAdapter(selectsql, con);
		DataTable^peopleflowdt = gcnew DataTable();
		da->Fill(peopleflowdt);
		con->Close();
		count = peopleflowdt->Rows->Count;
		count2 = peopleflowdt->Rows->Count;
		int i;

		proposalslist->Clear();
		if (peopleflowdt->Rows->Count != 0) {
			for (i = 0; i < peopleflowdt->Rows->Count; i++) {
				proposalslist->Add(peopleflowdt->Rows[i]->ItemArray[0]);
			}
		}

		Serialnumberlist->Clear();
		if (count != 0) {
			for (i = 0; i < count; i++) {
				Serialnumberlist->Add(peopleflowdt->Rows[i]->ItemArray[0]);
			}
		}

		Nemberlist->Clear();
		if (peopleflowdt->Rows->Count != 0) {
			for (i = 0; i < peopleflowdt->Rows->Count; i++) {
				Nemberlist->Add(peopleflowdt->Rows[i]->ItemArray[1]->ToString());
			}
		}

		runtimelist->Clear();
		if (peopleflowdt->Rows->Count != 0) {

			for (i = 0; i < peopleflowdt->Rows->Count; i++) {
				runtimelist->Add(peopleflowdt->Rows[i]->ItemArray[2]);
			}
		}

		proposalslist->Clear();
		Nemberlist->Clear();
		runtimelist->Clear();
		flaglist->Clear();
		for (i = 0; i < peopleflowdt->Rows->Count; i++) {
			System::Windows::Forms::ToolStripMenuItem^ toolstripmenuitem = safe_cast<System::Windows::Forms::ToolStripMenuItem^>(this->选择需要显示的方案ToolStripMenuItem->DropDownItems[i]);
			if (toolstripmenuitem->Checked == true) {
				proposalslist->Add(peopleflowdt->Rows[i]->ItemArray[0]);
				Nemberlist->Add(peopleflowdt->Rows[i]->ItemArray[1]->ToString());
				runtimelist->Add(peopleflowdt->Rows[i]->ItemArray[2]);
				flaglist->Add(1);
			}
			else {
				flaglist->Add(0);
			}
		}
		count = proposalslist->Count;

		timeandemptyrate_Paint(sender, nullptr);
	}
	};
}
