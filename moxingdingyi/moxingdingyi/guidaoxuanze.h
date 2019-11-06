#pragma once

namespace moxingdingyi {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// guidaoxuanze 摘要
	/// </summary>
	public ref class guidaoxuanze : public System::Windows::Forms::Form
	{
	public:
		guidaoxuanze(void)
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
		~guidaoxuanze()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	public: System::Windows::Forms::TextBox^  textBox35;
	private: System::Windows::Forms::Label^  label59;
	public: System::Windows::Forms::TextBox^  textBox36;
	private: System::Windows::Forms::Label^  label60;
	public: System::Windows::Forms::TextBox^  textBox37;
	private: System::Windows::Forms::Label^  label61;
	private: System::Windows::Forms::Label^  label62;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	public: System::Windows::Forms::TextBox^  textBox1;

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
			this->textBox35 = (gcnew System::Windows::Forms::TextBox());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->textBox36 = (gcnew System::Windows::Forms::TextBox());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->textBox37 = (gcnew System::Windows::Forms::TextBox());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox35
			// 
			this->textBox35->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->textBox35->Location = System::Drawing::Point(110, 161);
			this->textBox35->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox35->Name = L"textBox35";
			this->textBox35->Size = System::Drawing::Size(95, 24);
			this->textBox35->TabIndex = 94;
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label59->Location = System::Drawing::Point(21, 163);
			this->label59->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(83, 15);
			this->label59->TabIndex = 93;
			this->label59->Text = L"轨道半径r:";
			// 
			// textBox36
			// 
			this->textBox36->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->textBox36->Location = System::Drawing::Point(110, 115);
			this->textBox36->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox36->Name = L"textBox36";
			this->textBox36->Size = System::Drawing::Size(95, 24);
			this->textBox36->TabIndex = 92;
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label60->Location = System::Drawing::Point(21, 116);
			this->label60->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(83, 15);
			this->label60->TabIndex = 91;
			this->label60->Text = L"轨道长度l:";
			// 
			// textBox37
			// 
			this->textBox37->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->textBox37->Location = System::Drawing::Point(110, 66);
			this->textBox37->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox37->Name = L"textBox37";
			this->textBox37->Size = System::Drawing::Size(95, 24);
			this->textBox37->TabIndex = 90;
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label61->Location = System::Drawing::Point(21, 69);
			this->label61->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(75, 15);
			this->label61->TabIndex = 89;
			this->label61->Text = L"轨道名称:";
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label62->Location = System::Drawing::Point(20, 26);
			this->label62->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(75, 15);
			this->label62->TabIndex = 88;
			this->label62->Text = L"轨道编号:";
			// 
			// label1
			// 
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Location = System::Drawing::Point(12, 209);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(210, 2);
			this->label1->TabIndex = 98;
			// 
			// button2
			// 
			this->button2->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button2->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button2->Location = System::Drawing::Point(128, 231);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(64, 31);
			this->button2->TabIndex = 97;
			this->button2->Text = L"取消";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &guidaoxuanze::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button1->Location = System::Drawing::Point(28, 231);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(64, 31);
			this->button1->TabIndex = 96;
			this->button1->Text = L"确定";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &guidaoxuanze::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->textBox1->Location = System::Drawing::Point(110, 23);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(95, 24);
			this->textBox1->TabIndex = 99;
			// 
			// guidaoxuanze
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(233, 276);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox35);
			this->Controls->Add(this->label59);
			this->Controls->Add(this->textBox36);
			this->Controls->Add(this->label60);
			this->Controls->Add(this->textBox37);
			this->Controls->Add(this->label61);
			this->Controls->Add(this->label62);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"guidaoxuanze";
			this->Text = L"轨道定义";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	public:String^z, ^x, ^c,^v;
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {//取消
				 this->Close();
	}
private: System::Boolean CheckValid(System::Void){//自定义判断为空函数
			 if (String::IsNullOrEmpty(this->textBox1->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox37->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox36->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox35->Text))return false;
			 return true;
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {//确定
			 z = this->textBox1->Text->Trim();
			 x = this->textBox37->Text->Trim();
			 c = this->textBox36->Text->Trim();
			 v = this->textBox35->Text->Trim();
			 if (!CheckValid())
			 {
				 MessageBox::Show("请完善轨道信息。", "提示");
				 return;
			 }
			 else
			 {
				 this->DialogResult = System::Windows::Forms::DialogResult::OK;
				 this->Close();
			 }
}
};
}
