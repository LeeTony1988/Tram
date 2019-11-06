#pragma once
#include"xianludingyi.h"
#include"fanganxuanze.h"
#include"liechedingyi.h"
#include"guidaoxuanze.h"

#include"PowerDissipationForm1.h"
#include"PeopleFlowForm.h"
#include"TimeandPeopleFlowForm.h"
#include"StationPeopleTimeForm.h"
#include"Single_Project_UpDownPeopleForm.h"
#include"SimulateRoadForm.h"
#include"StationLogicForm.h"
#include"RealRoadForm.h"

namespace moxingdingyi {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Data::Common;
	using namespace System::Data::OleDb;

	/// <summary>
	/// moxing 摘要
	/// </summary>
	public ref class moxing : public System::Windows::Forms::Form
	{
	public:
		moxing(void)
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
		~moxing()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:




	private: System::Windows::Forms::GroupBox^  groupBox1;







	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::GroupBox^  groupBox2;



	private: System::Windows::Forms::Label^  label17;










	private: System::Windows::Forms::Label^  label11;



	private: System::Windows::Forms::TextBox^  textBox5;



	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox16;





	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::ListView^  zlistView;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;

	private: System::Windows::Forms::ColumnHeader^  columnHeader6;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  textBox18;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::TextBox^  textBox19;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::TextBox^  textBox20;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::TextBox^  textBox21;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::TextBox^  textBox22;
	private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::ListView^  glistView;

	private: System::Windows::Forms::ColumnHeader^  columnHeader7;
	private: System::Windows::Forms::ColumnHeader^  columnHeader8;
	private: System::Windows::Forms::ColumnHeader^  columnHeader9;
	private: System::Windows::Forms::ColumnHeader^  columnHeader10;
	private: System::Windows::Forms::ColumnHeader^  columnHeader11;
	private: System::Windows::Forms::ColumnHeader^  columnHeader12;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
private: System::Windows::Forms::Label^  label37;
private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::Label^  label38;
private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::Label^  label40;
private: System::Windows::Forms::Button^  button15;
private: System::Windows::Forms::Button^  button16;
private: System::Windows::Forms::Button^  button17;
private: System::Windows::Forms::Button^  button18;
private: System::Windows::Forms::TextBox^  textBox23;
private: System::Windows::Forms::TextBox^  textBox25;
private: System::Windows::Forms::Label^  label43;
private: System::Windows::Forms::Label^  label44;
private: System::Windows::Forms::TextBox^  textBox26;
private: System::Windows::Forms::Label^  label45;
private: System::Windows::Forms::TextBox^  textBox27;
private: System::Windows::Forms::Label^  label46;
private: System::Windows::Forms::TextBox^  textBox28;
private: System::Windows::Forms::Label^  label47;
private: System::Windows::Forms::ListView^  hlistView;

private: System::Windows::Forms::ColumnHeader^  columnHeader13;
private: System::Windows::Forms::ColumnHeader^  columnHeader14;
private: System::Windows::Forms::ColumnHeader^  columnHeader15;
private: System::Windows::Forms::ColumnHeader^  columnHeader16;
private: System::Windows::Forms::ColumnHeader^  columnHeader17;



private: System::Windows::Forms::Button^  button19;
private: System::Windows::Forms::Button^  button20;
private: System::Windows::Forms::Button^  button21;
private: System::Windows::Forms::Button^  button22;
private: System::Windows::Forms::TextBox^  textBox24;

private: System::Windows::Forms::TextBox^  textBox29;
private: System::Windows::Forms::Label^  label51;
private: System::Windows::Forms::TextBox^  textBox30;
private: System::Windows::Forms::Label^  label52;
private: System::Windows::Forms::Label^  label53;
private: System::Windows::Forms::TextBox^  textBox31;
private: System::Windows::Forms::Label^  label54;
private: System::Windows::Forms::TextBox^  textBox32;
private: System::Windows::Forms::Label^  label55;
private: System::Windows::Forms::TextBox^  textBox33;
private: System::Windows::Forms::Label^  label56;
private: System::Windows::Forms::ListView^  jlistView;

private: System::Windows::Forms::ColumnHeader^  columnHeader18;
private: System::Windows::Forms::ColumnHeader^  columnHeader19;
private: System::Windows::Forms::ColumnHeader^  columnHeader20;
private: System::Windows::Forms::ColumnHeader^  columnHeader21;
private: System::Windows::Forms::ColumnHeader^  columnHeader22;
private: System::Windows::Forms::ColumnHeader^  columnHeader23;
private: System::Windows::Forms::ColumnHeader^  columnHeader24;
private: System::Windows::Forms::Label^  label50;
private: System::Windows::Forms::Label^  label57;
private: System::Windows::Forms::Label^  label58;
private: System::Windows::Forms::Label^  label49;







private: System::Windows::Forms::Button^  button23;
private: System::Windows::Forms::Button^  button24;
private: System::Windows::Forms::Button^  button25;
private: System::Windows::Forms::Button^  button26;
private: System::Windows::Forms::TabPage^  tabPage5;
private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::GroupBox^  groupBox3;
private: System::Windows::Forms::Button^  button27;
private: System::Windows::Forms::Button^  button28;
private: System::Windows::Forms::ComboBox^  comboBox4;
private: System::Windows::Forms::Button^  button29;
private: System::Windows::Forms::TextBox^  textBox35;
private: System::Windows::Forms::Label^  label59;
private: System::Windows::Forms::TextBox^  textBox36;
private: System::Windows::Forms::Label^  label60;
private: System::Windows::Forms::TextBox^  textBox37;
private: System::Windows::Forms::Label^  label61;
private: System::Windows::Forms::Label^  label62;
private: System::Windows::Forms::TextBox^  textBox38;
private: System::Windows::Forms::Label^  label63;






private: System::Windows::Forms::TextBox^  textBox1;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::TextBox^  textBox7;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label48;
private: System::Windows::Forms::TextBox^  textBox34;
private: System::Windows::Forms::Label^  label42;
private: System::Windows::Forms::TabPage^  tabPage6;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::TextBox^  textBox2;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::TextBox^  textBox3;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Button^  button30;
private: System::Windows::Forms::Button^  button31;
private: System::Windows::Forms::Button^  button32;
private: System::Windows::Forms::Button^  button33;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::TextBox^  textBox4;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::TextBox^  textBox6;
private: System::Windows::Forms::TextBox^  textBox40;
private: System::Windows::Forms::Label^  label64;
private: System::Windows::Forms::Label^  label65;
private: System::Windows::Forms::Label^  label66;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::ListView^  ylistView;



private: System::Windows::Forms::ColumnHeader^  columnHeader25;
private: System::Windows::Forms::ColumnHeader^  columnHeader26;
private: System::Windows::Forms::ColumnHeader^  columnHeader27;
private: System::Windows::Forms::ColumnHeader^  columnHeader28;
private: System::Windows::Forms::ColumnHeader^  columnHeader29;
private: System::Windows::Forms::ColumnHeader^  columnHeader30;
private: System::Windows::Forms::GroupBox^  groupBox5;
private: System::Windows::Forms::Button^  button34;
private: System::Windows::Forms::Button^  button35;
private: System::Windows::Forms::Button^  button36;
private: System::Windows::Forms::ComboBox^  comboBox3;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::TextBox^  textBox8;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::ToolTip^  toolTip1;
private: System::Windows::Forms::TextBox^  textBox9;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::ColumnHeader^  columnHeader5;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::StatusStrip^  statusStrip1;
private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
private: System::Windows::Forms::MenuStrip^  menuStrip1;
private: System::Windows::Forms::ToolStripMenuItem^  视图ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  查看ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  实际线路图ToolStripMenuItem;




private: System::Windows::Forms::ToolStripMenuItem^  逻辑站点图ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  模拟线路图ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  功耗分析视图ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  人流量分析图ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  各天人流量数据统计图ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  人流量的时间分布图ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  人流量时间站点三者分布图ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  空载率分析图ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  各方案车内人数ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  空载率与时间关系ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  多天ToolStripMenuItem;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(moxing::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox38 = (gcnew System::Windows::Forms::TextBox());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->zlistView = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->glistView = (gcnew System::Windows::Forms::ListView());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader10 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader11 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader12 = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->textBox26 = (gcnew System::Windows::Forms::TextBox());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->textBox27 = (gcnew System::Windows::Forms::TextBox());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->textBox28 = (gcnew System::Windows::Forms::TextBox());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->hlistView = (gcnew System::Windows::Forms::ListView());
			this->columnHeader13 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader14 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader15 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader16 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader17 = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->textBox34 = (gcnew System::Windows::Forms::TextBox());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->textBox29 = (gcnew System::Windows::Forms::TextBox());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->textBox30 = (gcnew System::Windows::Forms::TextBox());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->textBox31 = (gcnew System::Windows::Forms::TextBox());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->textBox32 = (gcnew System::Windows::Forms::TextBox());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->textBox33 = (gcnew System::Windows::Forms::TextBox());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->jlistView = (gcnew System::Windows::Forms::ListView());
			this->columnHeader18 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader19 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader20 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader21 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader22 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader23 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader24 = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox40 = (gcnew System::Windows::Forms::TextBox());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->ylistView = (gcnew System::Windows::Forms::ListView());
			this->columnHeader25 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader26 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader27 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader28 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader29 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader30 = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->textBox35 = (gcnew System::Windows::Forms::TextBox());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->textBox36 = (gcnew System::Windows::Forms::TextBox());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->textBox37 = (gcnew System::Windows::Forms::TextBox());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->button36 = (gcnew System::Windows::Forms::Button());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->查看ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->实际线路图ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->逻辑站点图ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->模拟线路图ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->视图ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->功耗分析视图ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->人流量分析图ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->各天人流量数据统计图ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->人流量的时间分布图ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->人流量时间站点三者分布图ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->空载率分析图ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->各方案车内人数ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->空载率与时间关系ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->多天ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->button23);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox1->Location = System::Drawing::Point(5, 171);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(236, 173);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"线路选择";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(82, 66);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(140, 24);
			this->textBox1->TabIndex = 30;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::Control;
			this->label2->Location = System::Drawing::Point(7, 65);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 15);
			this->label2->TabIndex = 16;
			this->label2->Text = L"线路名称:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// button23
			// 
			this->button23->Location = System::Drawing::Point(160, 118);
			this->button23->Margin = System::Windows::Forms::Padding(2);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(68, 26);
			this->button23->TabIndex = 14;
			this->button23->Text = L"删除";
			this->button23->UseVisualStyleBackColor = false;
			this->button23->Click += gcnew System::EventHandler(this, &moxing::button23_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(7, 118);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(68, 26);
			this->button2->TabIndex = 13;
			this->button2->Text = L"添加";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &moxing::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Control;
			this->label1->Location = System::Drawing::Point(7, 30);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 15);
			this->label1->TabIndex = 5;
			this->label1->Text = L"线路编号:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(82, 27);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(140, 22);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &moxing::comboBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(85, 118);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(65, 26);
			this->button1->TabIndex = 4;
			this->button1->Text = L"修改";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &moxing::button1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox38);
			this->groupBox2->Controls->Add(this->label63);
			this->groupBox2->Controls->Add(this->button24);
			this->groupBox2->Controls->Add(this->button25);
			this->groupBox2->Controls->Add(this->button26);
			this->groupBox2->Controls->Add(this->label17);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->textBox5);
			this->groupBox2->Controls->Add(this->comboBox2);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox2->Location = System::Drawing::Point(5, 348);
			this->groupBox2->Margin = System::Windows::Forms::Padding(2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(2);
			this->groupBox2->Size = System::Drawing::Size(236, 238);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"列车定义";
			// 
			// textBox38
			// 
			this->textBox38->Location = System::Drawing::Point(82, 83);
			this->textBox38->Margin = System::Windows::Forms::Padding(2);
			this->textBox38->Name = L"textBox38";
			this->textBox38->ReadOnly = true;
			this->textBox38->Size = System::Drawing::Size(140, 24);
			this->textBox38->TabIndex = 29;
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->Location = System::Drawing::Point(8, 86);
			this->label63->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(75, 15);
			this->label63->TabIndex = 28;
			this->label63->Text = L"载客容量:";
			// 
			// button24
			// 
			this->button24->Location = System::Drawing::Point(152, 181);
			this->button24->Margin = System::Windows::Forms::Padding(2);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(70, 53);
			this->button24->TabIndex = 27;
			this->button24->Text = L"删除";
			this->button24->UseVisualStyleBackColor = false;
			this->button24->Click += gcnew System::EventHandler(this, &moxing::button24_Click);
			// 
			// button25
			// 
			this->button25->Location = System::Drawing::Point(4, 181);
			this->button25->Margin = System::Windows::Forms::Padding(2);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(70, 53);
			this->button25->TabIndex = 26;
			this->button25->Text = L"添加";
			this->button25->UseVisualStyleBackColor = false;
			this->button25->Click += gcnew System::EventHandler(this, &moxing::button25_Click);
			// 
			// button26
			// 
			this->button26->Location = System::Drawing::Point(78, 181);
			this->button26->Margin = System::Windows::Forms::Padding(2);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(70, 53);
			this->button26->TabIndex = 25;
			this->button26->Text = L"修改";
			this->button26->UseVisualStyleBackColor = false;
			this->button26->Click += gcnew System::EventHandler(this, &moxing::button26_Click);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(84, 134);
			this->label17->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(22, 15);
			this->label17->TabIndex = 21;
			this->label17->Text = L"往";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(7, 134);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(75, 15);
			this->label11->TabIndex = 10;
			this->label11->Text = L"行驶方向:";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(110, 131);
			this->textBox5->Margin = System::Windows::Forms::Padding(2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(114, 24);
			this->textBox5->TabIndex = 5;
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(82, 35);
			this->comboBox2->Margin = System::Windows::Forms::Padding(2);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(140, 22);
			this->comboBox2->TabIndex = 1;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &moxing::comboBox2_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 41);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 15);
			this->label3->TabIndex = 0;
			this->label3->Text = L"列车编号:";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->tabControl1->Location = System::Drawing::Point(245, 27);
			this->tabControl1->Margin = System::Windows::Forms::Padding(2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(753, 510);
			this->tabControl1->TabIndex = 8;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::White;
			this->tabPage1->Controls->Add(this->textBox9);
			this->tabPage1->Controls->Add(this->label15);
			this->tabPage1->Controls->Add(this->label12);
			this->tabPage1->Controls->Add(this->textBox7);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->label50);
			this->tabPage1->Controls->Add(this->button10);
			this->tabPage1->Controls->Add(this->button5);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->textBox16);
			this->tabPage1->Controls->Add(this->label27);
			this->tabPage1->Controls->Add(this->textBox13);
			this->tabPage1->Controls->Add(this->label28);
			this->tabPage1->Controls->Add(this->textBox14);
			this->tabPage1->Controls->Add(this->label29);
			this->tabPage1->Controls->Add(this->textBox15);
			this->tabPage1->Controls->Add(this->label30);
			this->tabPage1->Controls->Add(this->zlistView);
			this->tabPage1->Location = System::Drawing::Point(4, 24);
			this->tabPage1->Margin = System::Windows::Forms::Padding(2);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(2);
			this->tabPage1->Size = System::Drawing::Size(745, 482);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"站点定义";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(622, 314);
			this->textBox9->Margin = System::Windows::Forms::Padding(2);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(104, 24);
			this->textBox9->TabIndex = 92;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(551, 314);
			this->label15->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(75, 15);
			this->label15->TabIndex = 91;
			this->label15->Text = L"下车人数:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(730, 224);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(15, 15);
			this->label12->TabIndex = 90;
			this->label12->Text = L"m";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(622, 270);
			this->textBox7->Margin = System::Windows::Forms::Padding(2);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(104, 24);
			this->textBox7->TabIndex = 89;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(551, 270);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(75, 15);
			this->label8->TabIndex = 88;
			this->label8->Text = L"上车人数:";
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(548, 23);
			this->label50->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(112, 15);
			this->label50->TabIndex = 87;
			this->label50->Text = L"请按顺序填写：";
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(647, 414);
			this->button10->Margin = System::Windows::Forms::Padding(2);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(75, 53);
			this->button10->TabIndex = 43;
			this->button10->Text = L"取消";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &moxing::button10_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(568, 414);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 53);
			this->button5->TabIndex = 42;
			this->button5->Text = L"删除";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &moxing::button5_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(647, 357);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 53);
			this->button4->TabIndex = 41;
			this->button4->Text = L"修改";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &moxing::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(568, 358);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 53);
			this->button3->TabIndex = 40;
			this->button3->Text = L"添加";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &moxing::button3_Click);
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(622, 217);
			this->textBox16->Margin = System::Windows::Forms::Padding(2);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(104, 24);
			this->textBox16->TabIndex = 39;
			this->toolTip1->SetToolTip(this->textBox16, L"首站站间距离填0，其他为与上一站的距离");
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(551, 217);
			this->label27->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(75, 15);
			this->label27->TabIndex = 29;
			this->label27->Text = L"站间距离:";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(622, 166);
			this->textBox13->Margin = System::Windows::Forms::Padding(2);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(103, 24);
			this->textBox13->TabIndex = 28;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(550, 168);
			this->label28->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(75, 15);
			this->label28->TabIndex = 27;
			this->label28->Text = L"站点位置:";
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(621, 118);
			this->textBox14->Margin = System::Windows::Forms::Padding(2);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(103, 24);
			this->textBox14->TabIndex = 26;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(549, 120);
			this->label29->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(75, 15);
			this->label29->TabIndex = 25;
			this->label29->Text = L"站点名称:";
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(620, 73);
			this->textBox15->Margin = System::Windows::Forms::Padding(2);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(103, 24);
			this->textBox15->TabIndex = 24;
			this->toolTip1->SetToolTip(this->textBox15, L"按线路的一个方向按顺序填写");
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(548, 75);
			this->label30->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(75, 15);
			this->label30->TabIndex = 23;
			this->label30->Text = L"站点编号:";
			// 
			// zlistView
			// 
			this->zlistView->Alignment = System::Windows::Forms::ListViewAlignment::Default;
			this->zlistView->BackColor = System::Drawing::Color::White;
			this->zlistView->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->zlistView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3, this->columnHeader4, this->columnHeader6, this->columnHeader5
			});
			this->zlistView->FullRowSelect = true;
			this->zlistView->GridLines = true;
			this->zlistView->Location = System::Drawing::Point(0, 0);
			this->zlistView->Margin = System::Windows::Forms::Padding(2);
			this->zlistView->MultiSelect = false;
			this->zlistView->Name = L"zlistView";
			this->zlistView->Size = System::Drawing::Size(544, 480);
			this->zlistView->TabIndex = 7;
			this->zlistView->UseCompatibleStateImageBehavior = false;
			this->zlistView->View = System::Windows::Forms::View::Details;
			this->zlistView->SelectedIndexChanged += gcnew System::EventHandler(this, &moxing::zlistView_SelectedIndexChanged);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"站点编号";
			this->columnHeader1->Width = 80;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"站点名称";
			this->columnHeader2->Width = 90;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"站点位置";
			this->columnHeader3->Width = 130;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"站间距离/m";
			this->columnHeader4->Width = 85;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"上车人数";
			this->columnHeader6->Width = 80;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"下车人数";
			this->columnHeader5->Width = 80;
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::White;
			this->tabPage2->Controls->Add(this->label57);
			this->tabPage2->Controls->Add(this->label37);
			this->tabPage2->Controls->Add(this->label36);
			this->tabPage2->Controls->Add(this->label35);
			this->tabPage2->Controls->Add(this->button11);
			this->tabPage2->Controls->Add(this->button12);
			this->tabPage2->Controls->Add(this->button13);
			this->tabPage2->Controls->Add(this->button14);
			this->tabPage2->Controls->Add(this->textBox17);
			this->tabPage2->Controls->Add(this->label22);
			this->tabPage2->Controls->Add(this->textBox18);
			this->tabPage2->Controls->Add(this->label23);
			this->tabPage2->Controls->Add(this->textBox19);
			this->tabPage2->Controls->Add(this->label24);
			this->tabPage2->Controls->Add(this->label31);
			this->tabPage2->Controls->Add(this->textBox20);
			this->tabPage2->Controls->Add(this->label32);
			this->tabPage2->Controls->Add(this->textBox21);
			this->tabPage2->Controls->Add(this->label33);
			this->tabPage2->Controls->Add(this->textBox22);
			this->tabPage2->Controls->Add(this->label34);
			this->tabPage2->Controls->Add(this->glistView);
			this->tabPage2->Location = System::Drawing::Point(4, 24);
			this->tabPage2->Margin = System::Windows::Forms::Padding(2);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(2);
			this->tabPage2->Size = System::Drawing::Size(745, 482);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"供电区间定义";
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->Location = System::Drawing::Point(537, 25);
			this->label57->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(112, 15);
			this->label57->TabIndex = 87;
			this->label57->Text = L"请按顺序填写：";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(714, 258);
			this->label37->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(15, 15);
			this->label37->TabIndex = 64;
			this->label37->Text = L"V";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(716, 159);
			this->label36->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(15, 15);
			this->label36->TabIndex = 63;
			this->label36->Text = L"m";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(716, 206);
			this->label35->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(15, 15);
			this->label35->TabIndex = 62;
			this->label35->Text = L"m";
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(631, 417);
			this->button11->Margin = System::Windows::Forms::Padding(2);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(75, 53);
			this->button11->TabIndex = 61;
			this->button11->Text = L"取消";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &moxing::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(552, 417);
			this->button12->Margin = System::Windows::Forms::Padding(2);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(75, 53);
			this->button12->TabIndex = 60;
			this->button12->Text = L"删除";
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &moxing::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(631, 360);
			this->button13->Margin = System::Windows::Forms::Padding(2);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(75, 53);
			this->button13->TabIndex = 59;
			this->button13->Text = L"修改";
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &moxing::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(552, 360);
			this->button14->Margin = System::Windows::Forms::Padding(2);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(75, 53);
			this->button14->TabIndex = 58;
			this->button14->Text = L"添加";
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &moxing::button14_Click);
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(638, 204);
			this->textBox17->Margin = System::Windows::Forms::Padding(2);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(72, 24);
			this->textBox17->TabIndex = 57;
			this->toolTip1->SetToolTip(this->textBox17, L"首个供电区间的相邻区间距离填0，其他为与上一供电区间末端的距离");
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(714, 305);
			this->label22->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(15, 15);
			this->label22->TabIndex = 56;
			this->label22->Text = L"A";
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(608, 302);
			this->textBox18->Margin = System::Windows::Forms::Padding(2);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(102, 24);
			this->textBox18->TabIndex = 55;
			this->toolTip1->SetToolTip(this->textBox18, L"电压值为供电区间的标准电流值");
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(537, 305);
			this->label23->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(60, 15);
			this->label23->TabIndex = 54;
			this->label23->Text = L"电流值:";
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(608, 254);
			this->textBox19->Margin = System::Windows::Forms::Padding(2);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(103, 24);
			this->textBox19->TabIndex = 53;
			this->toolTip1->SetToolTip(this->textBox19, L"电压值为供电区间的标准电压值");
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(537, 258);
			this->label24->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(60, 15);
			this->label24->TabIndex = 52;
			this->label24->Text = L"电压值:";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(536, 206);
			this->label31->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(105, 15);
			this->label31->TabIndex = 51;
			this->label31->Text = L"相邻区间距离:";
			// 
			// textBox20
			// 
			this->textBox20->Location = System::Drawing::Point(609, 154);
			this->textBox20->Margin = System::Windows::Forms::Padding(2);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(102, 24);
			this->textBox20->TabIndex = 50;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(538, 157);
			this->label32->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(75, 15);
			this->label32->TabIndex = 49;
			this->label32->Text = L"区间长度:";
			// 
			// textBox21
			// 
			this->textBox21->Location = System::Drawing::Point(608, 110);
			this->textBox21->Margin = System::Windows::Forms::Padding(2);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(103, 24);
			this->textBox21->TabIndex = 48;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(536, 110);
			this->label33->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(75, 15);
			this->label33->TabIndex = 47;
			this->label33->Text = L"所在位置:";
			// 
			// textBox22
			// 
			this->textBox22->Location = System::Drawing::Point(608, 62);
			this->textBox22->Margin = System::Windows::Forms::Padding(2);
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(103, 24);
			this->textBox22->TabIndex = 46;
			this->toolTip1->SetToolTip(this->textBox22, L"按线路的一个方向按顺序填写");
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(536, 64);
			this->label34->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(75, 15);
			this->label34->TabIndex = 45;
			this->label34->Text = L"区间编号:";
			// 
			// glistView
			// 
			this->glistView->BackColor = System::Drawing::Color::White;
			this->glistView->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->glistView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->columnHeader7, this->columnHeader8,
					this->columnHeader9, this->columnHeader10, this->columnHeader11, this->columnHeader12
			});
			this->glistView->FullRowSelect = true;
			this->glistView->GridLines = true;
			this->glistView->Location = System::Drawing::Point(0, 0);
			this->glistView->Margin = System::Windows::Forms::Padding(2);
			this->glistView->MultiSelect = false;
			this->glistView->Name = L"glistView";
			this->glistView->Size = System::Drawing::Size(519, 480);
			this->glistView->TabIndex = 44;
			this->glistView->UseCompatibleStateImageBehavior = false;
			this->glistView->View = System::Windows::Forms::View::Details;
			this->glistView->SelectedIndexChanged += gcnew System::EventHandler(this, &moxing::glistView_SelectedIndexChanged);
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"区间编号";
			this->columnHeader7->Width = 70;
			// 
			// columnHeader8
			// 
			this->columnHeader8->Text = L"所在位置";
			this->columnHeader8->Width = 98;
			// 
			// columnHeader9
			// 
			this->columnHeader9->Text = L"区间长度/m";
			this->columnHeader9->Width = 82;
			// 
			// columnHeader10
			// 
			this->columnHeader10->Text = L"相邻区间距离/m";
			this->columnHeader10->Width = 115;
			// 
			// columnHeader11
			// 
			this->columnHeader11->Text = L"电压值/V";
			this->columnHeader11->Width = 80;
			// 
			// columnHeader12
			// 
			this->columnHeader12->Text = L"电流值/A";
			this->columnHeader12->Width = 80;
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::White;
			this->tabPage3->Controls->Add(this->label41);
			this->tabPage3->Controls->Add(this->label38);
			this->tabPage3->Controls->Add(this->label39);
			this->tabPage3->Controls->Add(this->label40);
			this->tabPage3->Controls->Add(this->button15);
			this->tabPage3->Controls->Add(this->button16);
			this->tabPage3->Controls->Add(this->button17);
			this->tabPage3->Controls->Add(this->button18);
			this->tabPage3->Controls->Add(this->textBox23);
			this->tabPage3->Controls->Add(this->textBox25);
			this->tabPage3->Controls->Add(this->label43);
			this->tabPage3->Controls->Add(this->label44);
			this->tabPage3->Controls->Add(this->textBox26);
			this->tabPage3->Controls->Add(this->label45);
			this->tabPage3->Controls->Add(this->textBox27);
			this->tabPage3->Controls->Add(this->label46);
			this->tabPage3->Controls->Add(this->textBox28);
			this->tabPage3->Controls->Add(this->label47);
			this->tabPage3->Controls->Add(this->hlistView);
			this->tabPage3->Location = System::Drawing::Point(4, 24);
			this->tabPage3->Margin = System::Windows::Forms::Padding(2);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(2);
			this->tabPage3->Size = System::Drawing::Size(745, 482);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"红绿灯定义";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(512, 41);
			this->label41->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(112, 15);
			this->label41->TabIndex = 86;
			this->label41->Text = L"请按顺序填写：";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(699, 279);
			this->label38->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(15, 15);
			this->label38->TabIndex = 85;
			this->label38->Text = L"m";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(699, 183);
			this->label39->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(15, 15);
			this->label39->TabIndex = 84;
			this->label39->Text = L"s";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(699, 230);
			this->label40->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(15, 15);
			this->label40->TabIndex = 83;
			this->label40->Text = L"s";
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(615, 393);
			this->button15->Margin = System::Windows::Forms::Padding(2);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(75, 53);
			this->button15->TabIndex = 82;
			this->button15->Text = L"取消";
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &moxing::button15_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(536, 395);
			this->button16->Margin = System::Windows::Forms::Padding(2);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(75, 53);
			this->button16->TabIndex = 81;
			this->button16->Text = L"删除";
			this->button16->UseVisualStyleBackColor = false;
			this->button16->Click += gcnew System::EventHandler(this, &moxing::button16_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(615, 338);
			this->button17->Margin = System::Windows::Forms::Padding(2);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(75, 53);
			this->button17->TabIndex = 80;
			this->button17->Text = L"修改";
			this->button17->UseVisualStyleBackColor = false;
			this->button17->Click += gcnew System::EventHandler(this, &moxing::button17_Click);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(536, 338);
			this->button18->Margin = System::Windows::Forms::Padding(2);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(75, 53);
			this->button18->TabIndex = 79;
			this->button18->Text = L"添加";
			this->button18->UseVisualStyleBackColor = false;
			this->button18->Click += gcnew System::EventHandler(this, &moxing::button18_Click);
			// 
			// textBox23
			// 
			this->textBox23->Location = System::Drawing::Point(592, 228);
			this->textBox23->Margin = System::Windows::Forms::Padding(2);
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(103, 24);
			this->textBox23->TabIndex = 78;
			this->toolTip1->SetToolTip(this->textBox23, L"绿灯时间为绿灯显示的时间");
			// 
			// textBox25
			// 
			this->textBox25->Location = System::Drawing::Point(630, 276);
			this->textBox25->Margin = System::Windows::Forms::Padding(2);
			this->textBox25->Name = L"textBox25";
			this->textBox25->Size = System::Drawing::Size(66, 24);
			this->textBox25->TabIndex = 74;
			this->toolTip1->SetToolTip(this->textBox25, L"若是首个红绿灯则填写与该线路起点的距离，\r\n否则填写与上一个红绿灯的距离");
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(513, 278);
			this->label43->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(120, 15);
			this->label43->TabIndex = 73;
			this->label43->Text = L"相邻红绿灯距离:";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(513, 230);
			this->label44->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(75, 15);
			this->label44->TabIndex = 72;
			this->label44->Text = L"绿灯时间:";
			// 
			// textBox26
			// 
			this->textBox26->Location = System::Drawing::Point(592, 181);
			this->textBox26->Margin = System::Windows::Forms::Padding(2);
			this->textBox26->Name = L"textBox26";
			this->textBox26->Size = System::Drawing::Size(103, 24);
			this->textBox26->TabIndex = 71;
			this->toolTip1->SetToolTip(this->textBox26, L"红灯时间为红灯显示的时间");
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(513, 183);
			this->label45->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(75, 15);
			this->label45->TabIndex = 70;
			this->label45->Text = L"红灯时间:";
			// 
			// textBox27
			// 
			this->textBox27->Location = System::Drawing::Point(592, 133);
			this->textBox27->Margin = System::Windows::Forms::Padding(2);
			this->textBox27->Name = L"textBox27";
			this->textBox27->Size = System::Drawing::Size(103, 24);
			this->textBox27->TabIndex = 69;
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(512, 133);
			this->label46->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(75, 15);
			this->label46->TabIndex = 68;
			this->label46->Text = L"所在位置:";
			// 
			// textBox28
			// 
			this->textBox28->Location = System::Drawing::Point(602, 81);
			this->textBox28->Margin = System::Windows::Forms::Padding(2);
			this->textBox28->Name = L"textBox28";
			this->textBox28->Size = System::Drawing::Size(94, 24);
			this->textBox28->TabIndex = 67;
			this->toolTip1->SetToolTip(this->textBox28, L"按线路的一个方向按顺序填写");
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(512, 83);
			this->label47->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(90, 15);
			this->label47->TabIndex = 66;
			this->label47->Text = L"红绿灯编号:";
			// 
			// hlistView
			// 
			this->hlistView->BackColor = System::Drawing::Color::White;
			this->hlistView->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->hlistView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->columnHeader13, this->columnHeader14,
					this->columnHeader15, this->columnHeader16, this->columnHeader17
			});
			this->hlistView->FullRowSelect = true;
			this->hlistView->GridLines = true;
			this->hlistView->Location = System::Drawing::Point(0, 0);
			this->hlistView->Margin = System::Windows::Forms::Padding(2);
			this->hlistView->MultiSelect = false;
			this->hlistView->Name = L"hlistView";
			this->hlistView->Size = System::Drawing::Size(495, 480);
			this->hlistView->TabIndex = 65;
			this->hlistView->UseCompatibleStateImageBehavior = false;
			this->hlistView->View = System::Windows::Forms::View::Details;
			this->hlistView->SelectedIndexChanged += gcnew System::EventHandler(this, &moxing::hlistView_SelectedIndexChanged);
			// 
			// columnHeader13
			// 
			this->columnHeader13->Text = L"红绿灯编号";
			this->columnHeader13->Width = 90;
			// 
			// columnHeader14
			// 
			this->columnHeader14->Text = L"所在位置";
			this->columnHeader14->Width = 110;
			// 
			// columnHeader15
			// 
			this->columnHeader15->Text = L"红灯时间/s";
			this->columnHeader15->Width = 85;
			// 
			// columnHeader16
			// 
			this->columnHeader16->Text = L"绿灯时间/s";
			this->columnHeader16->Width = 85;
			// 
			// columnHeader17
			// 
			this->columnHeader17->Text = L"相邻红绿灯距离/m";
			this->columnHeader17->Width = 130;
			// 
			// tabPage4
			// 
			this->tabPage4->BackColor = System::Drawing::Color::White;
			this->tabPage4->Controls->Add(this->label48);
			this->tabPage4->Controls->Add(this->textBox34);
			this->tabPage4->Controls->Add(this->label42);
			this->tabPage4->Controls->Add(this->label58);
			this->tabPage4->Controls->Add(this->label49);
			this->tabPage4->Controls->Add(this->button19);
			this->tabPage4->Controls->Add(this->button20);
			this->tabPage4->Controls->Add(this->button21);
			this->tabPage4->Controls->Add(this->button22);
			this->tabPage4->Controls->Add(this->textBox24);
			this->tabPage4->Controls->Add(this->textBox29);
			this->tabPage4->Controls->Add(this->label51);
			this->tabPage4->Controls->Add(this->textBox30);
			this->tabPage4->Controls->Add(this->label52);
			this->tabPage4->Controls->Add(this->label53);
			this->tabPage4->Controls->Add(this->textBox31);
			this->tabPage4->Controls->Add(this->label54);
			this->tabPage4->Controls->Add(this->textBox32);
			this->tabPage4->Controls->Add(this->label55);
			this->tabPage4->Controls->Add(this->textBox33);
			this->tabPage4->Controls->Add(this->label56);
			this->tabPage4->Controls->Add(this->jlistView);
			this->tabPage4->Location = System::Drawing::Point(4, 24);
			this->tabPage4->Margin = System::Windows::Forms::Padding(2);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(2);
			this->tabPage4->Size = System::Drawing::Size(745, 482);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"监测点定义";
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(730, 188);
			this->label48->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(15, 15);
			this->label48->TabIndex = 90;
			this->label48->Text = L"m";
			// 
			// textBox34
			// 
			this->textBox34->Location = System::Drawing::Point(665, 186);
			this->textBox34->Margin = System::Windows::Forms::Padding(2);
			this->textBox34->Name = L"textBox34";
			this->textBox34->Size = System::Drawing::Size(65, 24);
			this->textBox34->TabIndex = 89;
			this->toolTip1->SetToolTip(this->textBox34, L"若是首个监测点则填写与该线路起点的距离，\r\n其他为与上一个监测点的距离");
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(547, 188);
			this->label42->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(120, 15);
			this->label42->TabIndex = 88;
			this->label42->Text = L"相邻监测点距离:";
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->Location = System::Drawing::Point(545, 18);
			this->label58->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(112, 15);
			this->label58->TabIndex = 87;
			this->label58->Text = L"请按顺序填写：";
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(712, 319);
			this->label49->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(23, 15);
			this->label49->TabIndex = 86;
			this->label49->Text = L"Hz";
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(666, 418);
			this->button19->Margin = System::Windows::Forms::Padding(2);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(75, 53);
			this->button19->TabIndex = 82;
			this->button19->Text = L"取消";
			this->button19->UseVisualStyleBackColor = false;
			this->button19->Click += gcnew System::EventHandler(this, &moxing::button19_Click);
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(550, 418);
			this->button20->Margin = System::Windows::Forms::Padding(2);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(75, 53);
			this->button20->TabIndex = 81;
			this->button20->Text = L"删除";
			this->button20->UseVisualStyleBackColor = false;
			this->button20->Click += gcnew System::EventHandler(this, &moxing::button20_Click);
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(665, 361);
			this->button21->Margin = System::Windows::Forms::Padding(2);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(75, 53);
			this->button21->TabIndex = 80;
			this->button21->Text = L"修改";
			this->button21->UseVisualStyleBackColor = false;
			this->button21->Click += gcnew System::EventHandler(this, &moxing::button21_Click);
			// 
			// button22
			// 
			this->button22->Location = System::Drawing::Point(550, 361);
			this->button22->Margin = System::Windows::Forms::Padding(2);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(75, 53);
			this->button22->TabIndex = 79;
			this->button22->Text = L"添加";
			this->button22->UseVisualStyleBackColor = false;
			this->button22->Click += gcnew System::EventHandler(this, &moxing::button22_Click);
			// 
			// textBox24
			// 
			this->textBox24->Location = System::Drawing::Point(635, 229);
			this->textBox24->Margin = System::Windows::Forms::Padding(2);
			this->textBox24->Name = L"textBox24";
			this->textBox24->Size = System::Drawing::Size(95, 24);
			this->textBox24->TabIndex = 78;
			this->toolTip1->SetToolTip(this->textBox24, L"监测点类型为监测对象的类型，如温度，速度等");
			// 
			// textBox29
			// 
			this->textBox29->Location = System::Drawing::Point(635, 317);
			this->textBox29->Margin = System::Windows::Forms::Padding(2);
			this->textBox29->Name = L"textBox29";
			this->textBox29->Size = System::Drawing::Size(73, 24);
			this->textBox29->TabIndex = 76;
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Location = System::Drawing::Point(547, 319);
			this->label51->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(75, 15);
			this->label51->TabIndex = 75;
			this->label51->Text = L"采样频率:";
			// 
			// textBox30
			// 
			this->textBox30->Location = System::Drawing::Point(635, 272);
			this->textBox30->Margin = System::Windows::Forms::Padding(2);
			this->textBox30->Name = L"textBox30";
			this->textBox30->Size = System::Drawing::Size(95, 24);
			this->textBox30->TabIndex = 74;
			this->toolTip1->SetToolTip(this->textBox30, L"数据类型为采集到数据的类型，如模拟量，离散量等");
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Location = System::Drawing::Point(547, 274);
			this->label52->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(75, 15);
			this->label52->TabIndex = 73;
			this->label52->Text = L"数据类型:";
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->Location = System::Drawing::Point(547, 231);
			this->label53->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(90, 15);
			this->label53->TabIndex = 72;
			this->label53->Text = L"监测点类型:";
			// 
			// textBox31
			// 
			this->textBox31->Location = System::Drawing::Point(635, 140);
			this->textBox31->Margin = System::Windows::Forms::Padding(2);
			this->textBox31->Name = L"textBox31";
			this->textBox31->Size = System::Drawing::Size(95, 24);
			this->textBox31->TabIndex = 71;
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Location = System::Drawing::Point(547, 141);
			this->label54->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(90, 15);
			this->label54->TabIndex = 70;
			this->label54->Text = L"监测点位置:";
			// 
			// textBox32
			// 
			this->textBox32->Location = System::Drawing::Point(635, 91);
			this->textBox32->Margin = System::Windows::Forms::Padding(2);
			this->textBox32->Name = L"textBox32";
			this->textBox32->Size = System::Drawing::Size(95, 24);
			this->textBox32->TabIndex = 69;
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->Location = System::Drawing::Point(547, 94);
			this->label55->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(90, 15);
			this->label55->TabIndex = 68;
			this->label55->Text = L"监测点名称:";
			// 
			// textBox33
			// 
			this->textBox33->Location = System::Drawing::Point(635, 47);
			this->textBox33->Margin = System::Windows::Forms::Padding(2);
			this->textBox33->Name = L"textBox33";
			this->textBox33->Size = System::Drawing::Size(95, 24);
			this->textBox33->TabIndex = 67;
			this->toolTip1->SetToolTip(this->textBox33, L"按线路的一个方向按顺序填写");
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->Location = System::Drawing::Point(545, 50);
			this->label56->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(90, 15);
			this->label56->TabIndex = 66;
			this->label56->Text = L"监测点编号:";
			// 
			// jlistView
			// 
			this->jlistView->BackColor = System::Drawing::Color::White;
			this->jlistView->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->jlistView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {
				this->columnHeader18, this->columnHeader19,
					this->columnHeader20, this->columnHeader21, this->columnHeader22, this->columnHeader23, this->columnHeader24
			});
			this->jlistView->FullRowSelect = true;
			this->jlistView->GridLines = true;
			this->jlistView->Location = System::Drawing::Point(0, 0);
			this->jlistView->Margin = System::Windows::Forms::Padding(2);
			this->jlistView->MultiSelect = false;
			this->jlistView->Name = L"jlistView";
			this->jlistView->Size = System::Drawing::Size(543, 480);
			this->jlistView->TabIndex = 65;
			this->jlistView->UseCompatibleStateImageBehavior = false;
			this->jlistView->View = System::Windows::Forms::View::Details;
			this->jlistView->SelectedIndexChanged += gcnew System::EventHandler(this, &moxing::jlistView_SelectedIndexChanged);
			// 
			// columnHeader18
			// 
			this->columnHeader18->Text = L"编号";
			this->columnHeader18->Width = 50;
			// 
			// columnHeader19
			// 
			this->columnHeader19->Text = L"名称";
			// 
			// columnHeader20
			// 
			this->columnHeader20->Text = L"位置";
			this->columnHeader20->Width = 70;
			// 
			// columnHeader21
			// 
			this->columnHeader21->Text = L"相邻监测点距离";
			this->columnHeader21->Width = 111;
			// 
			// columnHeader22
			// 
			this->columnHeader22->Text = L"监测点类型";
			this->columnHeader22->Width = 92;
			// 
			// columnHeader23
			// 
			this->columnHeader23->Text = L"数据类型";
			this->columnHeader23->Width = 75;
			// 
			// columnHeader24
			// 
			this->columnHeader24->Text = L"采样频率/Hz";
			this->columnHeader24->Width = 90;
			// 
			// tabPage6
			// 
			this->tabPage6->BackColor = System::Drawing::Color::White;
			this->tabPage6->Controls->Add(this->textBox8);
			this->tabPage6->Controls->Add(this->label14);
			this->tabPage6->Controls->Add(this->label19);
			this->tabPage6->Controls->Add(this->textBox2);
			this->tabPage6->Controls->Add(this->label5);
			this->tabPage6->Controls->Add(this->label6);
			this->tabPage6->Controls->Add(this->textBox3);
			this->tabPage6->Controls->Add(this->label7);
			this->tabPage6->Controls->Add(this->button30);
			this->tabPage6->Controls->Add(this->button31);
			this->tabPage6->Controls->Add(this->button32);
			this->tabPage6->Controls->Add(this->button33);
			this->tabPage6->Controls->Add(this->label9);
			this->tabPage6->Controls->Add(this->textBox4);
			this->tabPage6->Controls->Add(this->label10);
			this->tabPage6->Controls->Add(this->label18);
			this->tabPage6->Controls->Add(this->textBox6);
			this->tabPage6->Controls->Add(this->textBox40);
			this->tabPage6->Controls->Add(this->label64);
			this->tabPage6->Controls->Add(this->label65);
			this->tabPage6->Controls->Add(this->label66);
			this->tabPage6->Controls->Add(this->label4);
			this->tabPage6->Controls->Add(this->ylistView);
			this->tabPage6->Location = System::Drawing::Point(4, 24);
			this->tabPage6->Margin = System::Windows::Forms::Padding(2);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(2);
			this->tabPage6->Size = System::Drawing::Size(745, 482);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"列车站间运行定义";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(569, 57);
			this->textBox8->Margin = System::Windows::Forms::Padding(2);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(69, 24);
			this->textBox8->TabIndex = 130;
			this->toolTip1->SetToolTip(this->textBox8, L"该站点编号的内容及顺序应与站点定义时一样");
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(567, 39);
			this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(75, 15);
			this->label14->TabIndex = 129;
			this->label14->Text = L"站点编号:";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(644, 168);
			this->label19->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(31, 15);
			this->label19->TabIndex = 128;
			this->label19->Text = L"min";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(568, 337);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(96, 24);
			this->textBox2->TabIndex = 127;
			this->toolTip1->SetToolTip(this->textBox2, L"该加速度为列车减速的加速度");
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(566, 314);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(150, 15);
			this->label5->TabIndex = 126;
			this->label5->Text = L"站间列车减速加速度:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(667, 339);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(39, 15);
			this->label6->TabIndex = 125;
			this->label6->Text = L"m/s²";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(568, 279);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(94, 24);
			this->textBox3->TabIndex = 124;
			this->toolTip1->SetToolTip(this->textBox3, L"该加速度为列车起步时的加速度");
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(565, 254);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(150, 15);
			this->label7->TabIndex = 123;
			this->label7->Text = L"站间列车加速加速度:";
			// 
			// button30
			// 
			this->button30->Location = System::Drawing::Point(662, 422);
			this->button30->Margin = System::Windows::Forms::Padding(2);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(75, 53);
			this->button30->TabIndex = 122;
			this->button30->Text = L"取消";
			this->button30->UseVisualStyleBackColor = false;
			this->button30->Click += gcnew System::EventHandler(this, &moxing::button30_Click);
			// 
			// button31
			// 
			this->button31->Location = System::Drawing::Point(568, 422);
			this->button31->Margin = System::Windows::Forms::Padding(2);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(75, 53);
			this->button31->TabIndex = 121;
			this->button31->Text = L"删除";
			this->button31->UseVisualStyleBackColor = false;
			this->button31->Click += gcnew System::EventHandler(this, &moxing::button31_Click);
			// 
			// button32
			// 
			this->button32->Location = System::Drawing::Point(662, 365);
			this->button32->Margin = System::Windows::Forms::Padding(2);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(75, 53);
			this->button32->TabIndex = 120;
			this->button32->Text = L"修改";
			this->button32->UseVisualStyleBackColor = false;
			this->button32->Click += gcnew System::EventHandler(this, &moxing::button32_Click);
			// 
			// button33
			// 
			this->button33->Location = System::Drawing::Point(568, 365);
			this->button33->Margin = System::Windows::Forms::Padding(2);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(75, 53);
			this->button33->TabIndex = 119;
			this->button33->Text = L"添加";
			this->button33->UseVisualStyleBackColor = false;
			this->button33->Click += gcnew System::EventHandler(this, &moxing::button33_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(668, 284);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(39, 15);
			this->label9->TabIndex = 113;
			this->label9->Text = L"m/s²";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(568, 165);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(69, 24);
			this->textBox4->TabIndex = 118;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(641, 224);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(38, 15);
			this->label10->TabIndex = 112;
			this->label10->Text = L"㎞/h";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(643, 114);
			this->label18->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(31, 15);
			this->label18->TabIndex = 117;
			this->label18->Text = L"min";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(568, 217);
			this->textBox6->Margin = System::Windows::Forms::Padding(2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(72, 24);
			this->textBox6->TabIndex = 111;
			this->toolTip1->SetToolTip(this->textBox6, L"该速度为列车运行时的匀速速度");
			// 
			// textBox40
			// 
			this->textBox40->Location = System::Drawing::Point(568, 112);
			this->textBox40->Margin = System::Windows::Forms::Padding(2);
			this->textBox40->Name = L"textBox40";
			this->textBox40->Size = System::Drawing::Size(69, 24);
			this->textBox40->TabIndex = 116;
			// 
			// label64
			// 
			this->label64->AutoSize = true;
			this->label64->Location = System::Drawing::Point(565, 94);
			this->label64->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(105, 15);
			this->label64->TabIndex = 115;
			this->label64->Text = L"站点停留时间:";
			// 
			// label65
			// 
			this->label65->AutoSize = true;
			this->label65->Location = System::Drawing::Point(566, 198);
			this->label65->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(105, 15);
			this->label65->TabIndex = 110;
			this->label65->Text = L"站间列车速度:";
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->Location = System::Drawing::Point(566, 144);
			this->label66->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(105, 15);
			this->label66->TabIndex = 114;
			this->label66->Text = L"站间运行时间:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(564, 11);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(112, 15);
			this->label4->TabIndex = 109;
			this->label4->Text = L"请按顺序填写：";
			// 
			// ylistView
			// 
			this->ylistView->BackColor = System::Drawing::Color::White;
			this->ylistView->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ylistView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->columnHeader25, this->columnHeader26,
					this->columnHeader27, this->columnHeader28, this->columnHeader29, this->columnHeader30
			});
			this->ylistView->FullRowSelect = true;
			this->ylistView->GridLines = true;
			this->ylistView->Location = System::Drawing::Point(0, 0);
			this->ylistView->Margin = System::Windows::Forms::Padding(2);
			this->ylistView->MultiSelect = false;
			this->ylistView->Name = L"ylistView";
			this->ylistView->Size = System::Drawing::Size(561, 480);
			this->ylistView->TabIndex = 88;
			this->ylistView->UseCompatibleStateImageBehavior = false;
			this->ylistView->View = System::Windows::Forms::View::Details;
			this->ylistView->SelectedIndexChanged += gcnew System::EventHandler(this, &moxing::ylistView_SelectedIndexChanged);
			// 
			// columnHeader25
			// 
			this->columnHeader25->Text = L"站点编号";
			this->columnHeader25->Width = 71;
			// 
			// columnHeader26
			// 
			this->columnHeader26->Text = L"停留时间";
			this->columnHeader26->Width = 75;
			// 
			// columnHeader27
			// 
			this->columnHeader27->Text = L"站间运行时间";
			this->columnHeader27->Width = 98;
			// 
			// columnHeader28
			// 
			this->columnHeader28->Text = L"站间列车速度";
			this->columnHeader28->Width = 98;
			// 
			// columnHeader29
			// 
			this->columnHeader29->Text = L"列车加速加速度";
			this->columnHeader29->Width = 113;
			// 
			// columnHeader30
			// 
			this->columnHeader30->Text = L"列车减速加速度";
			this->columnHeader30->Width = 116;
			// 
			// tabPage5
			// 
			this->tabPage5->BackColor = System::Drawing::Color::White;
			this->tabPage5->Controls->Add(this->groupBox4);
			this->tabPage5->Controls->Add(this->pictureBox1);
			this->tabPage5->Controls->Add(this->groupBox3);
			this->tabPage5->Location = System::Drawing::Point(4, 24);
			this->tabPage5->Margin = System::Windows::Forms::Padding(2);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(2);
			this->tabPage5->Size = System::Drawing::Size(745, 482);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"轨道定义";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label16);
			this->groupBox4->Location = System::Drawing::Point(30, 358);
			this->groupBox4->Margin = System::Windows::Forms::Padding(2);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(2);
			this->groupBox4->Size = System::Drawing::Size(684, 103);
			this->groupBox4->TabIndex = 2;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"说明";
			// 
			// label16
			// 
			this->label16->Location = System::Drawing::Point(78, 31);
			this->label16->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(549, 61);
			this->label16->TabIndex = 0;
			this->label16->Text = L"    轨道定义可定义列车模拟运行时的实物模拟图的轨道的轨道长度\r\n\r\n以及轨道半径，其中定义中的轨道长度为图中l的长度，轨道半径为图中r的长度。";
			// 
			// pictureBox1
			// 
			//this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(320, 41);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(394, 284);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label21);
			this->groupBox3->Controls->Add(this->label20);
			this->groupBox3->Controls->Add(this->button27);
			this->groupBox3->Controls->Add(this->button28);
			this->groupBox3->Controls->Add(this->comboBox4);
			this->groupBox3->Controls->Add(this->button29);
			this->groupBox3->Controls->Add(this->textBox35);
			this->groupBox3->Controls->Add(this->label59);
			this->groupBox3->Controls->Add(this->textBox36);
			this->groupBox3->Controls->Add(this->label60);
			this->groupBox3->Controls->Add(this->textBox37);
			this->groupBox3->Controls->Add(this->label61);
			this->groupBox3->Controls->Add(this->label62);
			this->groupBox3->Location = System::Drawing::Point(30, 33);
			this->groupBox3->Margin = System::Windows::Forms::Padding(2);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(2);
			this->groupBox3->Size = System::Drawing::Size(251, 295);
			this->groupBox3->TabIndex = 0;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"轨道选择";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(204, 186);
			this->label21->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(23, 15);
			this->label21->TabIndex = 89;
			this->label21->Text = L"cm";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(204, 146);
			this->label20->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(23, 15);
			this->label20->TabIndex = 88;
			this->label20->Text = L"cm";
			// 
			// button27
			// 
			this->button27->Location = System::Drawing::Point(168, 238);
			this->button27->Margin = System::Windows::Forms::Padding(2);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(78, 53);
			this->button27->TabIndex = 17;
			this->button27->Text = L"删除";
			this->button27->UseVisualStyleBackColor = false;
			this->button27->Click += gcnew System::EventHandler(this, &moxing::button27_Click);
			// 
			// button28
			// 
			this->button28->Location = System::Drawing::Point(4, 239);
			this->button28->Margin = System::Windows::Forms::Padding(2);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(78, 53);
			this->button28->TabIndex = 16;
			this->button28->Text = L"添加";
			this->button28->UseVisualStyleBackColor = false;
			this->button28->Click += gcnew System::EventHandler(this, &moxing::button28_Click);
			// 
			// comboBox4
			// 
			this->comboBox4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(106, 46);
			this->comboBox4->Margin = System::Windows::Forms::Padding(2);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(95, 22);
			this->comboBox4->TabIndex = 87;
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &moxing::comboBox4_SelectedIndexChanged);
			// 
			// button29
			// 
			this->button29->Location = System::Drawing::Point(86, 239);
			this->button29->Margin = System::Windows::Forms::Padding(2);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(78, 53);
			this->button29->TabIndex = 15;
			this->button29->Text = L"修改";
			this->button29->UseVisualStyleBackColor = false;
			this->button29->Click += gcnew System::EventHandler(this, &moxing::button29_Click);
			// 
			// textBox35
			// 
			this->textBox35->Location = System::Drawing::Point(106, 184);
			this->textBox35->Margin = System::Windows::Forms::Padding(2);
			this->textBox35->Name = L"textBox35";
			this->textBox35->ReadOnly = true;
			this->textBox35->Size = System::Drawing::Size(95, 24);
			this->textBox35->TabIndex = 86;
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->Location = System::Drawing::Point(17, 186);
			this->label59->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(83, 15);
			this->label59->TabIndex = 85;
			this->label59->Text = L"轨道半径r:";
			// 
			// textBox36
			// 
			this->textBox36->Location = System::Drawing::Point(106, 138);
			this->textBox36->Margin = System::Windows::Forms::Padding(2);
			this->textBox36->Name = L"textBox36";
			this->textBox36->ReadOnly = true;
			this->textBox36->Size = System::Drawing::Size(95, 24);
			this->textBox36->TabIndex = 84;
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->Location = System::Drawing::Point(17, 139);
			this->label60->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(83, 15);
			this->label60->TabIndex = 83;
			this->label60->Text = L"轨道长度l:";
			// 
			// textBox37
			// 
			this->textBox37->Location = System::Drawing::Point(106, 90);
			this->textBox37->Margin = System::Windows::Forms::Padding(2);
			this->textBox37->Name = L"textBox37";
			this->textBox37->ReadOnly = true;
			this->textBox37->Size = System::Drawing::Size(95, 24);
			this->textBox37->TabIndex = 82;
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->Location = System::Drawing::Point(17, 92);
			this->label61->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(75, 15);
			this->label61->TabIndex = 81;
			this->label61->Text = L"轨道名称:";
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->Location = System::Drawing::Point(16, 49);
			this->label62->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(75, 15);
			this->label62->TabIndex = 79;
			this->label62->Text = L"轨道编号:";
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button6->Location = System::Drawing::Point(249, 541);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(130, 45);
			this->button6->TabIndex = 9;
			this->button6->Text = L"保存";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &moxing::button6_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button7->Location = System::Drawing::Point(383, 541);
			this->button7->Margin = System::Windows::Forms::Padding(2);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(130, 45);
			this->button7->TabIndex = 10;
			this->button7->Text = L"刷新";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &moxing::button7_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button8->Location = System::Drawing::Point(517, 541);
			this->button8->Margin = System::Windows::Forms::Padding(2);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(130, 45);
			this->button8->TabIndex = 11;
			this->button8->Text = L"清空";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &moxing::button8_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button9->Location = System::Drawing::Point(651, 541);
			this->button9->Margin = System::Windows::Forms::Padding(2);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(130, 45);
			this->button9->TabIndex = 12;
			this->button9->Text = L"退出";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &moxing::button9_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->button34);
			this->groupBox5->Controls->Add(this->button35);
			this->groupBox5->Controls->Add(this->button36);
			this->groupBox5->Controls->Add(this->comboBox3);
			this->groupBox5->Controls->Add(this->label13);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox5->Location = System::Drawing::Point(5, 27);
			this->groupBox5->Margin = System::Windows::Forms::Padding(2);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Padding = System::Windows::Forms::Padding(2);
			this->groupBox5->Size = System::Drawing::Size(236, 136);
			this->groupBox5->TabIndex = 13;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"方案选择";
			// 
			// button34
			// 
			this->button34->Location = System::Drawing::Point(154, 82);
			this->button34->Margin = System::Windows::Forms::Padding(2);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(68, 26);
			this->button34->TabIndex = 35;
			this->button34->Text = L"删除";
			this->button34->UseVisualStyleBackColor = false;
			this->button34->Click += gcnew System::EventHandler(this, &moxing::button34_Click);
			// 
			// button35
			// 
			this->button35->BackColor = System::Drawing::Color::White;
			this->button35->Location = System::Drawing::Point(7, 82);
			this->button35->Margin = System::Windows::Forms::Padding(2);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(68, 26);
			this->button35->TabIndex = 34;
			this->button35->Text = L"添加";
			this->button35->UseVisualStyleBackColor = false;
			this->button35->Click += gcnew System::EventHandler(this, &moxing::button35_Click);
			// 
			// button36
			// 
			this->button36->Location = System::Drawing::Point(85, 82);
			this->button36->Margin = System::Windows::Forms::Padding(2);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(59, 26);
			this->button36->TabIndex = 33;
			this->button36->Text = L"修改";
			this->button36->UseVisualStyleBackColor = false;
			this->button36->Click += gcnew System::EventHandler(this, &moxing::button36_Click);
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(82, 34);
			this->comboBox3->Margin = System::Windows::Forms::Padding(2);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(140, 22);
			this->comboBox3->TabIndex = 32;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &moxing::comboBox3_SelectedIndexChanged);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->Location = System::Drawing::Point(7, 36);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(75, 15);
			this->label13->TabIndex = 31;
			this->label13->Text = L"方案编号:";
			this->label13->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// statusStrip1
			// 
			this->statusStrip1->BackColor = System::Drawing::Color::Transparent;
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 600);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Padding = System::Windows::Forms::Padding(1, 0, 10, 0);
			this->statusStrip1->Size = System::Drawing::Size(1004, 22);
			this->statusStrip1->TabIndex = 14;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(31, 17);
			this->toolStripStatusLabel1->Text = L"v1.0";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Transparent;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->查看ToolStripMenuItem,
					this->视图ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1004, 25);
			this->menuStrip1->TabIndex = 15;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 查看ToolStripMenuItem
			// 
			this->查看ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->实际线路图ToolStripMenuItem,
					this->逻辑站点图ToolStripMenuItem, this->模拟线路图ToolStripMenuItem
			});
			this->查看ToolStripMenuItem->Name = L"查看ToolStripMenuItem";
			this->查看ToolStripMenuItem->Size = System::Drawing::Size(68, 21);
			this->查看ToolStripMenuItem->Text = L"线路视图";
			// 
			// 实际线路图ToolStripMenuItem
			// 
			this->实际线路图ToolStripMenuItem->Name = L"实际线路图ToolStripMenuItem";
			this->实际线路图ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->实际线路图ToolStripMenuItem->Text = L"实际线路图";
			this->实际线路图ToolStripMenuItem->Click += gcnew System::EventHandler(this, &moxing::实际线路图ToolStripMenuItem_Click);
			// 
			// 逻辑站点图ToolStripMenuItem
			// 
			this->逻辑站点图ToolStripMenuItem->Name = L"逻辑站点图ToolStripMenuItem";
			this->逻辑站点图ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->逻辑站点图ToolStripMenuItem->Text = L"逻辑站点图";
			this->逻辑站点图ToolStripMenuItem->Click += gcnew System::EventHandler(this, &moxing::逻辑站点图ToolStripMenuItem_Click);
			// 
			// 模拟线路图ToolStripMenuItem
			// 
			this->模拟线路图ToolStripMenuItem->Name = L"模拟线路图ToolStripMenuItem";
			this->模拟线路图ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->模拟线路图ToolStripMenuItem->Text = L"模拟线路图";
			this->模拟线路图ToolStripMenuItem->Click += gcnew System::EventHandler(this, &moxing::模拟线路图ToolStripMenuItem_Click);
			// 
			// 视图ToolStripMenuItem
			// 
			this->视图ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->功耗分析视图ToolStripMenuItem,
					this->人流量分析图ToolStripMenuItem, this->空载率分析图ToolStripMenuItem
			});
			this->视图ToolStripMenuItem->Name = L"视图ToolStripMenuItem";
			this->视图ToolStripMenuItem->Size = System::Drawing::Size(68, 21);
			this->视图ToolStripMenuItem->Text = L"数据视图";
			// 
			// 功耗分析视图ToolStripMenuItem
			// 
			this->功耗分析视图ToolStripMenuItem->Name = L"功耗分析视图ToolStripMenuItem";
			this->功耗分析视图ToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->功耗分析视图ToolStripMenuItem->Text = L"功耗分析视图";
			this->功耗分析视图ToolStripMenuItem->Click += gcnew System::EventHandler(this, &moxing::功耗分析视图ToolStripMenuItem_Click);
			// 
			// 人流量分析图ToolStripMenuItem
			// 
			this->人流量分析图ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->各天人流量数据统计图ToolStripMenuItem,
					this->人流量的时间分布图ToolStripMenuItem, this->人流量时间站点三者分布图ToolStripMenuItem
			});
			this->人流量分析图ToolStripMenuItem->Name = L"人流量分析图ToolStripMenuItem";
			this->人流量分析图ToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->人流量分析图ToolStripMenuItem->Text = L"人流量分析图";
			// 
			// 各天人流量数据统计图ToolStripMenuItem
			// 
			this->各天人流量数据统计图ToolStripMenuItem->Name = L"各天人流量数据统计图ToolStripMenuItem";
			this->各天人流量数据统计图ToolStripMenuItem->Size = System::Drawing::Size(244, 22);
			this->各天人流量数据统计图ToolStripMenuItem->Text = L"各天人流量数据统计图";
			this->各天人流量数据统计图ToolStripMenuItem->Click += gcnew System::EventHandler(this, &moxing::各天人流量数据统计图ToolStripMenuItem_Click);
			// 
			// 人流量的时间分布图ToolStripMenuItem
			// 
			this->人流量的时间分布图ToolStripMenuItem->Name = L"人流量的时间分布图ToolStripMenuItem";
			this->人流量的时间分布图ToolStripMenuItem->Size = System::Drawing::Size(244, 22);
			this->人流量的时间分布图ToolStripMenuItem->Text = L"人流量的时间分布图";
			this->人流量的时间分布图ToolStripMenuItem->Click += gcnew System::EventHandler(this, &moxing::人流量的时间分布图ToolStripMenuItem_Click);
			// 
			// 人流量时间站点三者分布图ToolStripMenuItem
			// 
			this->人流量时间站点三者分布图ToolStripMenuItem->Name = L"人流量时间站点三者分布图ToolStripMenuItem";
			this->人流量时间站点三者分布图ToolStripMenuItem->Size = System::Drawing::Size(244, 22);
			this->人流量时间站点三者分布图ToolStripMenuItem->Text = L"人流量、时间、站点三者分布图";
			this->人流量时间站点三者分布图ToolStripMenuItem->Click += gcnew System::EventHandler(this, &moxing::人流量时间站点三者分布图ToolStripMenuItem_Click);
			// 
			// 空载率分析图ToolStripMenuItem
			// 
			this->空载率分析图ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->各方案车内人数ToolStripMenuItem,
					this->空载率与时间关系ToolStripMenuItem, this->多天ToolStripMenuItem
			});
			this->空载率分析图ToolStripMenuItem->Name = L"空载率分析图ToolStripMenuItem";
			this->空载率分析图ToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->空载率分析图ToolStripMenuItem->Text = L"空载率分析图";
			// 
			// 各方案车内人数ToolStripMenuItem
			// 
			this->各方案车内人数ToolStripMenuItem->Name = L"各方案车内人数ToolStripMenuItem";
			this->各方案车内人数ToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->各方案车内人数ToolStripMenuItem->Text = L"各方案车内人数";
			this->各方案车内人数ToolStripMenuItem->Click += gcnew System::EventHandler(this, &moxing::各方案车内人数ToolStripMenuItem_Click);
			// 
			// 空载率与时间关系ToolStripMenuItem
			// 
			this->空载率与时间关系ToolStripMenuItem->Name = L"空载率与时间关系ToolStripMenuItem";
			this->空载率与时间关系ToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->空载率与时间关系ToolStripMenuItem->Text = L"空载率与时间关系";
			// 
			// 多天ToolStripMenuItem
			// 
			this->多天ToolStripMenuItem->Name = L"多天ToolStripMenuItem";
			this->多天ToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->多天ToolStripMenuItem->Text = L"多天方案空载率";
			// 
			// moxing
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1004, 622);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"moxing";
			this->Text = L"模型定义";
			this->Load += gcnew System::EventHandler(this, &moxing::moxing_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			this->tabPage5->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
private:ArrayList^fangMes = gcnew ArrayList();
	    ArrayList^xianMes = gcnew ArrayList();
		ArrayList^cheMes = gcnew ArrayList();
		ArrayList^zhanMes = gcnew ArrayList();
		ArrayList^gongMes = gcnew ArrayList();
		ArrayList^hongMes = gcnew ArrayList();
		ArrayList^jianMes = gcnew ArrayList();
		ArrayList^yunMes = gcnew ArrayList();
		ArrayList^guiMes = gcnew ArrayList();
		int i,j;
 private:String^k, ^p, ^t;
		 int u;
#pragma endregion


private: System::Void moxing_Load(System::Object^  sender, System::EventArgs^  e) {//load函数
			 //加载方案信息
			 DataTable^ table1 = gcnew DataTable;
			 table1 = ExecuteQuery("SELECT * FROM 方案信息 ;");
			 for (i = 0; i < table1->Rows->Count; i++)
			 {
				 fangMes->Add(table1->Rows[i]->ItemArray[1]->ToString()->Trim());
				 this->comboBox3->Items->Add(fangMes[i]);
			 }
			 //加载线路信息
			 DataTable^ table2 = gcnew DataTable;
			 table2= ExecuteQuery("SELECT * FROM 线路信息 ;");
			 for (i = 0; i < table2->Rows->Count; i++)
			 {
				 xianMes->Add(table2->Rows[i]->ItemArray[0]->ToString()->Trim());
				 this->comboBox1->Items->Add(xianMes[i]);
			 }
			 DataTable^ table3 = gcnew DataTable;
			 //加载列车信息
			 table3 = ExecuteQuery("SELECT DISTINCT 列车编号  FROM 列车信息 ;");
			 for (i = 0; i < table3->Rows->Count; i++)
			 {
				 cheMes->Add(table3->Rows[i]->ItemArray[0]->ToString()->Trim());
				 this->comboBox2->Items->Add(cheMes[i]);
			 }
			 DataTable^ table4 = gcnew DataTable;
			 //加载轨道信息
			 table4 = ExecuteQuery("SELECT * FROM 轨道信息 ;");
			 for (i = 0; i < table4->Rows->Count; i++)
			 {
				 guiMes->Add(table4->Rows[i]->ItemArray[0]->ToString()->Trim());
				 this->comboBox4->Items->Add(guiMes[i]);
			 }
			 
}

 public: System::Data::DataTable^ ExecuteQuery(String ^sqlStr){//自定义查询数据库函数
			 String^ cmd = String::Format("Data Source=localhost;Initial Catalog=列车数据库;Integrated Security=True");
			 SqlConnection^ con = gcnew SqlConnection(cmd);
			 con->Open();
			 SqlDataAdapter^ da = gcnew SqlDataAdapter(sqlStr, cmd);
			 DataTable^ dt = gcnew DataTable;
			 da->Fill(dt);
			 con->Close();
			 return dt;
}

public: System::Int32 ExecuteUpdate(String ^sqlStr){//自定义增删改数据库函数
			 String^ cmd = String::Format("Data Source=localhost;Initial Catalog=列车数据库;Integrated Security=True");
			 SqlConnection^ con = gcnew SqlConnection(cmd);
			 con->Open();
			 System::Data::SqlClient::SqlCommand^ kk = gcnew System::Data::SqlClient::SqlCommand(sqlStr, con);
			 int d = kk->ExecuteNonQuery();
			 con->Close();
			 return d;
			
 }

 public: System::Void xianlu(Void){//自定义线路选择函数
			 String^k = this->comboBox1->Text;
			 DataTable^ table1 = gcnew DataTable;
			 table1 = ExecuteQuery("SELECT * FROM 线路信息 WHERE 线路编号='" + k + "';");
			 if (table1->Rows->Count != 0){
				 xianMes->Clear();
				 for (i = 0; i < table1->Columns->Count; i++)
				 {
					 xianMes->Add(table1->Rows[0]->ItemArray[i]);
				 }
				 this->textBox1->Text = xianMes[1]->ToString()->Trim();
			 }
 }
 public: System::Void lieche(Void){//自定义列车选择函数
			 String^k = this->comboBox2->Text;
			 DataTable^ table1 = gcnew DataTable;
			 table1 = ExecuteQuery("SELECT * FROM 列车信息 WHERE 列车编号='" + k + "';");
			 if (table1->Rows->Count != 0)
			 {
				 cheMes->Clear();
				 for (i = 0; i < table1->Columns->Count; i++)
				 {
					 cheMes->Add(table1->Rows[0]->ItemArray[i]);
				 }
				 this->textBox38->Text = cheMes[3]->ToString()->Trim();
				 this->textBox5->Text = cheMes[2]->ToString()->Trim();
			 }
 }
 public: System::Void zhandian(Void){//自定义站点显示函数
			 String^k = this->comboBox1->Text;
			 DataTable^ table1 = gcnew DataTable;
			 table1 = ExecuteQuery("SELECT * FROM 站点信息 WHERE 线路编号='" + k + "';");
			 if (table1->Rows->Count != 0)
			 {
				 zhanMes->Clear();
				 this->zlistView->Items->Clear();
				 for (i = 0; i < table1->Rows->Count; i++)
				 {
					 for (j = 0; j < table1->Columns->Count; j++)
					 {
						 zhanMes->Add(table1->Rows[i]->ItemArray[j]);
					 }
					 ListViewItem^ item1 = gcnew ListViewItem(zhanMes[1]->ToString()->Trim(), 0);
					 item1->SubItems->Add(zhanMes[2]->ToString()->Trim());
					 item1->SubItems->Add(zhanMes[3]->ToString()->Trim());
					 item1->SubItems->Add(zhanMes[4]->ToString()->Trim());
					 item1->SubItems->Add(zhanMes[5]->ToString()->Trim());
					 item1->SubItems->Add(zhanMes[6]->ToString()->Trim());
					 ListViewItem^ addItem = this->zlistView->Items->Add(item1);
					 zhanMes->Clear();
				 }
			 }
 }
 public: System::Void gongdianqujian(Void){//自定义供电区间显示函数
			 String^k = this->comboBox1->Text;
			 DataTable^ table1 = gcnew DataTable;
			 table1 = ExecuteQuery("SELECT * FROM 供电区间信息 WHERE 线路编号='" + k + "';");
			 if (table1->Rows->Count != 0)
			 {
				 gongMes->Clear();
				 this->glistView->Items->Clear();
				 for (i = 0; i < table1->Rows->Count; i++)
				 {
					 for (j = 0; j < table1->Columns->Count; j++)
					 {
						 gongMes->Add(table1->Rows[i]->ItemArray[j]);
					 }
					 ListViewItem^ item1 = gcnew ListViewItem(gongMes[1]->ToString()->Trim(), 0);
					 item1->SubItems->Add(gongMes[2]->ToString()->Trim());
					 item1->SubItems->Add(gongMes[3]->ToString()->Trim());
					 item1->SubItems->Add(gongMes[4]->ToString()->Trim());
					 item1->SubItems->Add(gongMes[5]->ToString()->Trim());
					 item1->SubItems->Add(gongMes[6]->ToString()->Trim());
					 ListViewItem^ addItem = this->glistView->Items->Add(item1);
					 gongMes->Clear();
				 }
			 }
 }
 public: System::Void honglvdeng(Void){//自定义红绿灯显示函数
			 String^k = this->comboBox1->Text;
			 DataTable^ table1 = gcnew DataTable;
			 table1 = ExecuteQuery("SELECT * FROM 红绿灯信息 WHERE 线路编号='" + k + "';");
			 if (table1->Rows->Count != 0)
			 {
				 hongMes->Clear();
				 this->hlistView->Items->Clear();
				 for (i = 0; i < table1->Rows->Count; i++)
				 {
					 for (j = 0; j < table1->Columns->Count; j++)
					 {
						 hongMes->Add(table1->Rows[i]->ItemArray[j]);
					 }
					 ListViewItem^ item1 = gcnew ListViewItem(hongMes[1]->ToString()->Trim(), 0);
					 item1->SubItems->Add(hongMes[2]->ToString()->Trim());
					 item1->SubItems->Add(hongMes[3]->ToString()->Trim());
					 item1->SubItems->Add(hongMes[4]->ToString()->Trim());
					 item1->SubItems->Add(hongMes[5]->ToString()->Trim());
					 ListViewItem^ addItem = this->hlistView->Items->Add(item1);
					 hongMes->Clear();
				 }
			 }
 }
 public: System::Void jiancedian(Void){//自定义监测点显示函数
			 String^k = this->comboBox1->Text;
			 DataTable^ table1 = gcnew DataTable;
			 table1 = ExecuteQuery("SELECT * FROM 监测点信息 WHERE 线路编号='" + k + "';");
			 if (table1->Rows->Count != 0)
			 {
				 jianMes->Clear();
				 this->jlistView->Items->Clear();
				 for (i = 0; i < table1->Rows->Count; i++)
				 {
					 for (j = 0; j < table1->Columns->Count; j++)
					 {
						 jianMes->Add(table1->Rows[i]->ItemArray[j]);
					 }
					 ListViewItem^ item1 = gcnew ListViewItem(jianMes[1]->ToString()->Trim(), 0);
					 item1->SubItems->Add(jianMes[2]->ToString()->Trim());
					 item1->SubItems->Add(jianMes[3]->ToString()->Trim());
					 item1->SubItems->Add(jianMes[4]->ToString()->Trim());
					 item1->SubItems->Add(jianMes[5]->ToString()->Trim());
					 item1->SubItems->Add(jianMes[6]->ToString()->Trim());
					 item1->SubItems->Add(jianMes[7]->ToString()->Trim());
					 ListViewItem^ addItem = this->jlistView->Items->Add(item1);
					 jianMes->Clear();
				 }
			 }
 }
 public: System::Void zhanjianyunxing(Void){//自定义站间运行显示函数
			 String^k = this->comboBox1->Text;
			 String^p = this->comboBox2->Text;
			 DataTable^ table1 = gcnew DataTable;
			 table1 = ExecuteQuery("SELECT * FROM 列车站间运行信息 WHERE 线路编号='" + k + "'AND 列车编号='" + p + "';");
			 if (table1->Rows->Count != 0)
			 {
				 yunMes->Clear();
				 this->ylistView->Items->Clear();
				 for (i = 0; i < table1->Rows->Count; i++)
				 {
					 for (j = 0; j < table1->Columns->Count; j++)
					 {
						 yunMes->Add(table1->Rows[i]->ItemArray[j]);
					 }
					 ListViewItem^ item1 = gcnew ListViewItem(yunMes[2]->ToString()->Trim(), 0);
					 item1->SubItems->Add(yunMes[3]->ToString()->Trim());
					 item1->SubItems->Add(yunMes[4]->ToString()->Trim());
					 item1->SubItems->Add(yunMes[5]->ToString()->Trim());
					 item1->SubItems->Add(yunMes[6]->ToString()->Trim());
					 item1->SubItems->Add(yunMes[7]->ToString()->Trim());
					 ListViewItem^ addItem = this->ylistView->Items->Add(item1);
					 yunMes->Clear();
				 }
			 }
 }
 public: System::Void guidao(Void){//自定义轨道选择函数
			 String^k = this->comboBox4->Text;
			 DataTable^ table1 = gcnew DataTable;
			 table1 = ExecuteQuery("SELECT * FROM 轨道信息 WHERE 轨道编号='" + k + "';");
			 if (table1->Rows->Count != 0){
				 guiMes->Clear();
				 for (i = 0; i < table1->Columns->Count; i++)
				 {
					 guiMes->Add(table1->Rows[0]->ItemArray[i]);
				 }
				 this->textBox37->Text = guiMes[1]->ToString()->Trim();
				 this->textBox36->Text = guiMes[2]->ToString()->Trim();
				 this->textBox35->Text = guiMes[3]->ToString()->Trim();
			 }
 }
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {//选择线路
			 xianlu();
			 zhandian();
			 gongdianqujian();
			 honglvdeng();
			 jiancedian();
			 zhanjianyunxing();
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {//选择列车
			 lieche();
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {//线路选择修改按钮
			 xianludingyi^xian = gcnew xianludingyi;
			 xian->textBox1->Text = this->comboBox1->Text;
			 xian->textBox2->Text = this->textBox1->Text;
			 t = this->comboBox1->Text;
			 DataTable^ table1 = gcnew DataTable;
			 table1 = ExecuteQuery("SELECT * FROM 线路信息 WHERE 线路编号='" + t + "';");
			 if (Windows::Forms::DialogResult::OK == xian->ShowDialog())
			 {
				 k = xian->b;
				 if (this->comboBox1->Items->Contains(k))
				 {
					 MessageBox::Show("线路编号已存在。", "提示");
					 return;
				 }
				 if (table1->Rows->Count != 0){ 
					 ExecuteUpdate("UPDATE  线路信息 SET 线路编号='" + k + "' WHERE 线路编号='" + t + "';"); 
					 ExecuteUpdate("UPDATE  方案信息 SET 线路编号='" + k + "' WHERE 线路编号='" + t + "';");
					 ExecuteUpdate("UPDATE  站点信息 SET 线路编号='" + k + "' WHERE 线路编号='" + t + "';");
					 ExecuteUpdate("UPDATE  列车信息 SET 线路编号='" + k + "' WHERE 线路编号='" + t + "';");
					 ExecuteUpdate("UPDATE  供电区间信息 SET 线路编号='" + k + "' WHERE 线路编号='" + t + "';");
					 ExecuteUpdate("UPDATE  红绿灯信息 SET 线路编号='" + k + "' WHERE 线路编号='" + t + "';");
					 ExecuteUpdate("UPDATE  监测点信息 SET 线路编号='" + k + "' WHERE 线路编号='" + t + "';");
					 ExecuteUpdate("UPDATE  列车站间运行信息 SET 线路编号='" + k + "' WHERE 线路编号='" + t + "';");
				 }
				 this->comboBox1->Items->Remove(t);
				 int nindex = comboBox1->Items->Add(k);
				 comboBox1->SelectedIndex = nindex;
				 this->textBox1->Text = xian->v;
			 }
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {//线路选择添加按钮
			 xianludingyi^xian = gcnew xianludingyi;
			 if (Windows::Forms::DialogResult::OK == xian->ShowDialog())
			 {
				 k = xian->b;
				 if (this->comboBox1->Items->Contains(k))
				 {
					 MessageBox::Show("线路编号已存在。", "提示");
					 return;
				 }
				 int nindex = comboBox1->Items->Add(k);
				 comboBox1->SelectedIndex = nindex;
				 this->textBox1->Text = xian->v;
			 }
}
private: System::Void button23_Click(System::Object^  sender, System::EventArgs^  e) {//线路选择删除按钮
			 // 若当前没有选择项，则返回
			 if (comboBox1->SelectedIndex< 0) {
				 MessageBox::Show("请选定一个列表项！", this->Text);
				 return;
			 }
			 DataTable^table1 = gcnew DataTable;
			 table1 = ExecuteQuery(String::Format("SELECT * FROM 线路信息 WHERE 线路编号='{0}';", this->comboBox1->Text));
			 if (table1->Rows->Count != 0){
				 MessageBoxButtons buttons = MessageBoxButtons::YesNo;
				 if (System::Windows::Forms::DialogResult::Yes ==
					 MessageBox::Show(L"将删除该线路信息的所有数据？",
					 L"确认",               /*标题*/
					 buttons,               /*按钮*/
					 MessageBoxIcon::Question,      /*图标*/
					 MessageBoxDefaultButton::Button1   /*默认按钮*/))
				 {
					 ExecuteUpdate(String::Format("DELETE FROM 站点信息 WHERE 线路编号='{0}';", this->comboBox1->Text));
					 ExecuteUpdate(String::Format("DELETE FROM 供电区间信息 WHERE 线路编号='{0}';", this->comboBox1->Text));
					 ExecuteUpdate(String::Format("DELETE FROM 红绿灯信息 WHERE 线路编号='{0}';", this->comboBox1->Text));
					 ExecuteUpdate(String::Format("DELETE FROM 监测点信息 WHERE 线路编号='{0}';", this->comboBox1->Text));
					 ExecuteUpdate(String::Format("DELETE FROM 列车信息 WHERE 线路编号='{0}';", this->comboBox1->Text));
					 ExecuteUpdate(String::Format("DELETE FROM 方案信息 WHERE 线路编号='{0}';", this->comboBox1->Text));
					 ExecuteUpdate(String::Format("DELETE FROM 列车站间运行信息 WHERE 线路编号='{0}';", this->comboBox1->Text));
					 this->comboBox1->Items->RemoveAt(this->comboBox1->SelectedIndex);
					 this->textBox1->Clear();
				 }
				 else
				 {
					 return;
				 }
			 }
			 else{
				 this->comboBox1->Items->RemoveAt(this->comboBox1->SelectedIndex);
				 this->textBox1->Clear();
			 }
}
private: System::Boolean Check2(System::Void){//自定义判断为空函数
			 if (String::IsNullOrEmpty(this->textBox22->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox21->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox20->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox17->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox19->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox18->Text))return false;
			 return true;
}
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {//供电区间添加按钮
			 if (!Check2()) { MessageBox::Show("请完善供电区间信息。", "提示"); return; }
			 //判断是否有重复的主键添加项
			 for (int i = 0; i < glistView->Items->Count; i++)
			 {
				 if (this->textBox22->Text == glistView->Items[i]->SubItems[0]->Text)
				 {
					 MessageBox::Show("该区间编号已存在。", "提示");
					 return;
				 }
			 }
			 ListViewItem^ item1 = gcnew ListViewItem(this->textBox22->Text, 0);
			 item1->SubItems->Add(this->textBox21->Text);      
			 item1->SubItems->Add(this->textBox20->Text); 
			 item1->SubItems->Add(this->textBox17->Text);
			 item1->SubItems->Add(this->textBox19->Text); 
			 item1->SubItems->Add(this->textBox18->Text); 
			 ListViewItem^ addItem = this->glistView->Items->Add(item1);
		//	 addItem->Selected = true;  // 设置当前添加的列表项为当前选择项
}
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {//供电区间修改按钮
			 if (!Check2()) { MessageBox::Show("请完善供电区间信息。", "提示"); return; }
			 // 若当前没有选择项，则返回
			 if (glistView->SelectedItems->Count <= 0) {
				 MessageBox::Show("请选定一个列表项！", this->Text);
				 return;
			 }
			 // 获取当前选择的列表项
			 ListViewItem^ item1 = glistView->SelectedItems[0];
			 // 修改选择的列表项的内容
			 item1->SubItems[0]->Text = this->textBox22->Text;
			 item1->SubItems[1]->Text = this->textBox21->Text;
			 item1->SubItems[2]->Text = this->textBox20->Text;
			 item1->SubItems[3]->Text = this->textBox17->Text;
			 item1->SubItems[4]->Text = this->textBox19->Text;
			 item1->SubItems[5]->Text = this->textBox18->Text;
}
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {//供电区间删除按钮
			 // 若当前没有选择项，则返回
			 if (glistView->SelectedItems->Count <= 0) {
				 MessageBox::Show("请选定一个列表项！", this->Text);
				 return;
			 }
			 //两种方法选择列表中的项
			 /*第一种方法
			 ListViewItem^ item1 = glistView->FocusedItem;*/
			 /*第二种方法	*/
		    ListViewItem^ item1 = glistView->SelectedItems[0];
				 glistView->Items->Remove(item1);
}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {//供电区间取消按钮
			 this->textBox22->Clear();
			 this->textBox21->Clear();
			 this->textBox20->Clear();
			 this->textBox17->Clear();
			 this->textBox19->Clear();
			 this->textBox18->Clear();
}

private: System::Void glistView_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {//供电区间列表选择函数
			 // 若当前没有选择项，则返回
			 if (glistView->SelectedItems->Count <= 0) {//这个判断很关键，是下面方法的前提
				 return;
			 }
			 //两种方法选择列表中的项
			 /*第一种方法
			 ListViewItem^ item2 = glistView->FocusedItem;*/
			 /*第二种方法	*/
			 ListViewItem^ item2 = glistView->SelectedItems[0];
			 this->textBox22->Text = item2->SubItems[0]->Text;
			 this->textBox21->Text = item2->SubItems[1]->Text;
			 this->textBox20->Text = item2->SubItems[2]->Text;
			 this->textBox17->Text = item2->SubItems[3]->Text;
			 this->textBox19->Text = item2->SubItems[4]->Text;
			 this->textBox18->Text = item2->SubItems[5]->Text;
}
private: System::Boolean Check1(System::Void){//自定义判断为空函数
			 if (String::IsNullOrEmpty(this->textBox15->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox14->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox13->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox16->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox7->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox9->Text))return false;
			 return true;
}
		
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {//站点添加按钮
			 if (!Check1()) { MessageBox::Show("请完善站点信息。", "提示"); return; }
			 //判断是否有重复的主键添加项
			 for (int i = 0; i < zlistView->Items->Count; i++)
			 {
				 if (this->textBox15->Text == zlistView->Items[i]->SubItems[0]->Text)
				 {
					 MessageBox::Show("该站点编号已存在。", "提示");
					 return;
				 }
			 }
			 ListViewItem^ item1 = gcnew ListViewItem(this->textBox15->Text, 0);
			 item1->SubItems->Add(this->textBox14->Text);
			 item1->SubItems->Add(this->textBox13->Text);
			 item1->SubItems->Add(this->textBox16->Text);
			 item1->SubItems->Add(this->textBox7->Text);
			 item1->SubItems->Add(this->textBox9->Text);
			 ListViewItem^ addItem = this->zlistView->Items->Add(item1);

}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {//站点修改按钮
			 if (!Check1()) { MessageBox::Show("请完善站点信息。", "提示"); return; }
			 // 若当前没有选择项，则返回
			 if (zlistView->SelectedItems->Count <= 0) {
				 MessageBox::Show("请选定一个列表项！", this->Text);
				 return;
			 }
			 // 获取当前选择的列表项
			 ListViewItem^ item1 = zlistView->SelectedItems[0];
			 // 修改选择的列表项的内容
			 item1->SubItems[0]->Text = this->textBox15->Text;
			 item1->SubItems[1]->Text = this->textBox14->Text;
			 item1->SubItems[2]->Text = this->textBox13->Text;
			 item1->SubItems[3]->Text = this->textBox16->Text;
			 item1->SubItems[4]->Text = this->textBox7->Text;
			 item1->SubItems[5]->Text = this->textBox9->Text;
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {//站点删除按钮
			 // 若当前没有选择项，则返回
			 if (zlistView->SelectedItems->Count <= 0) {
				 MessageBox::Show("请选定一个列表项！", this->Text);
				 return;
			 }
			 ListViewItem^ item1 = zlistView->SelectedItems[0];
			 zlistView->Items->Remove(item1);
}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {//站点取消按钮
			 this->textBox15->Clear();
			 this->textBox14->Clear();
			 this->textBox13->Clear();
			 this->textBox16->Clear();
			 this->textBox7->Clear();
			 this->textBox9->Clear();
}
private: System::Void zlistView_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {//站点列表选择函数
			 // 若当前没有选择项，则返回
			 if (zlistView->SelectedItems->Count <= 0) {//这个判断很关键，是下面方法的前提
				 return;
			 }
			 ListViewItem^ item2 = zlistView->SelectedItems[0];
			 this->textBox15->Text = item2->SubItems[0]->Text;
			 this->textBox14->Text = item2->SubItems[1]->Text;
			 this->textBox13->Text = item2->SubItems[2]->Text;
			 this->textBox16->Text = item2->SubItems[3]->Text;
			 this->textBox7->Text = item2->SubItems[4]->Text;
			 this->textBox9->Text = item2->SubItems[5]->Text;
}
private: System::Boolean Check3(System::Void){//自定义判断为空函数
			 if (String::IsNullOrEmpty(this->textBox28->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox27->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox26->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox23->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox25->Text))return false;
			 return true;
}
private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {//红绿灯添加按钮
			 if (!Check3()) { MessageBox::Show("请完善红绿灯信息。", "提示"); return; }
			 //判断是否有重复的主键添加项
			 for (int i = 0; i < hlistView->Items->Count; i++)
			 {
				 if (this->textBox28->Text == hlistView->Items[i]->SubItems[0]->Text)
				 {
					 MessageBox::Show("该红绿灯编号已存在。", "提示");
					 return;
				 }
			 }
			 ListViewItem^ item1 = gcnew ListViewItem(this->textBox28->Text, 0);
			 item1->SubItems->Add(this->textBox27->Text);
			 item1->SubItems->Add(this->textBox26->Text);
			 item1->SubItems->Add(this->textBox23->Text);
			 item1->SubItems->Add(this->textBox25->Text);
			 ListViewItem^ addItem = this->hlistView->Items->Add(item1);
}
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {//红绿灯修改按钮
			 if (!Check3()) { MessageBox::Show("请完善红绿灯信息。", "提示"); return; }
			 // 若当前没有选择项，则返回
			 if (hlistView->SelectedItems->Count <= 0) {
				 MessageBox::Show("请选定一个列表项！", this->Text);
				 return;
			 }
			 // 获取当前选择的列表项
			 ListViewItem^ item1 = hlistView->SelectedItems[0];
			 // 修改选择的列表项的内容
			 item1->SubItems[0]->Text = this->textBox28->Text;
			 item1->SubItems[1]->Text = this->textBox27->Text;
			 item1->SubItems[2]->Text = this->textBox26->Text;
			 item1->SubItems[3]->Text = this->textBox23->Text;
			 item1->SubItems[4]->Text = this->textBox25->Text;
}
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {//红绿灯删除按钮
			 // 若当前没有选择项，则返回
			 if (hlistView->SelectedItems->Count <= 0) {
				 MessageBox::Show("请选定一个列表项！", this->Text);
				 return;
			 }
			 ListViewItem^ item1 = hlistView->SelectedItems[0];
			 hlistView->Items->Remove(item1);
}
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {//红绿灯取消按钮
			 this->textBox28->Clear();
			 this->textBox27->Clear();
			 this->textBox26->Clear();
			 this->textBox23->Clear();
			 this->textBox25->Clear();
}
private: System::Void hlistView_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {//红绿灯列表选择函数
			 // 若当前没有选择项，则返回
			 if (hlistView->SelectedItems->Count <= 0) {//这个判断很关键，是下面方法的前提
				 return;
			 }
			 ListViewItem^ item2 = hlistView->SelectedItems[0];
			 this->textBox28->Text = item2->SubItems[0]->Text;
			 this->textBox27->Text = item2->SubItems[1]->Text;
			 this->textBox26->Text = item2->SubItems[2]->Text;
			 this->textBox23->Text = item2->SubItems[3]->Text;
			 this->textBox25->Text = item2->SubItems[4]->Text;
}
private: System::Boolean Check4(System::Void){//自定义判断为空函数
			 if (String::IsNullOrEmpty(this->textBox33->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox32->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox31->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox34->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox24->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox30->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox29->Text))return false;
			 return true;
}
private: System::Void button22_Click(System::Object^  sender, System::EventArgs^  e) {//监测点添加按钮
			 if (!Check4()) { MessageBox::Show("请完善监测点信息。", "提示"); return; }
			 //判断是否有重复的主键添加项
			 for (int i = 0; i < jlistView->Items->Count; i++)
			 {
				 if (this->textBox33->Text == jlistView->Items[i]->SubItems[0]->Text)
				 {
					 MessageBox::Show("该监测点编号已存在。", "提示");
					 return;
				 }
			 }
			 ListViewItem^ item1 = gcnew ListViewItem(this->textBox33->Text, 0);
			 item1->SubItems->Add(this->textBox32->Text);
			 item1->SubItems->Add(this->textBox31->Text);
			 item1->SubItems->Add(this->textBox34->Text);
			 item1->SubItems->Add(this->textBox24->Text);
			 item1->SubItems->Add(this->textBox30->Text);
			 item1->SubItems->Add(this->textBox29->Text);
			 ListViewItem^ addItem = this->jlistView->Items->Add(item1);
}
private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) {//监测点修改按钮
			 if (!Check4()) { MessageBox::Show("请完善监测点信息。", "提示"); return; }
			 // 若当前没有选择项，则返回
			 if (jlistView->SelectedItems->Count <= 0) {
				 MessageBox::Show("请选定一个列表项！", this->Text);
				 return;
			 }
			 // 获取当前选择的列表项
			 ListViewItem^ item1 = jlistView->SelectedItems[0];
			 // 修改选择的列表项的内容
			 item1->SubItems[0]->Text = this->textBox33->Text;
			 item1->SubItems[1]->Text = this->textBox32->Text;
			 item1->SubItems[2]->Text = this->textBox31->Text;
			 item1->SubItems[3]->Text = this->textBox34->Text;
			 item1->SubItems[4]->Text = this->textBox24->Text;
			 item1->SubItems[5]->Text = this->textBox30->Text;
			 item1->SubItems[6]->Text = this->textBox29->Text;
}
private: System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) {//监测点删除按钮
			 // 若当前没有选择项，则返回
			 if (jlistView->SelectedItems->Count <= 0) {
				 MessageBox::Show("请选定一个列表项！", this->Text);
				 return;
			 }
			 ListViewItem^ item1 = jlistView->SelectedItems[0];
			 jlistView->Items->Remove(item1);
}
private: System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) {//监测点取消按钮
			 this->textBox33->Clear();
			 this->textBox32->Clear();
			 this->textBox31->Clear();
			 this->textBox34->Clear();
			 this->textBox24->Clear();
			 this->textBox30->Clear();
			 this->textBox29->Clear();
}
private: System::Void jlistView_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {//监测点列表选择函数
			 // 若当前没有选择项，则返回
			 if (jlistView->SelectedItems->Count <= 0) {//这个判断很关键，是下面方法的前提
				 return;
			 }
			 ListViewItem^ item2 = jlistView->SelectedItems[0];
			 this->textBox33->Text = item2->SubItems[0]->Text;
			 this->textBox32->Text = item2->SubItems[1]->Text;
			 this->textBox31->Text = item2->SubItems[2]->Text;
			 this->textBox34->Text = item2->SubItems[3]->Text;
			 this->textBox24->Text = item2->SubItems[4]->Text;
			 this->textBox30->Text = item2->SubItems[5]->Text;
			 this->textBox29->Text = item2->SubItems[6]->Text;
}
private: System::Boolean Check5(System::Void){//自定义判断为空函数
			 if (String::IsNullOrEmpty(this->textBox40->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox4->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox6->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox3->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox2->Text))return false;
			 return true;
}
		
private: System::Void button33_Click(System::Object^  sender, System::EventArgs^  e) {//站间运行添加按钮
			 if (!Check5()) { MessageBox::Show("请完善列车站间运行信息。", "提示"); return; }
			 ListViewItem^ item1 = gcnew ListViewItem(this->textBox8->Text,0);
			 item1->SubItems->Add(this->textBox40->Text);
			 item1->SubItems->Add(this->textBox4->Text);
			 item1->SubItems->Add(this->textBox6->Text);
			 item1->SubItems->Add(this->textBox3->Text);
			 item1->SubItems->Add(this->textBox2->Text);
			 ListViewItem^ addItem = this->ylistView->Items->Add(item1);  
			 

}
private: System::Void button32_Click(System::Object^  sender, System::EventArgs^  e) {//站间运行修改按钮
			 if (!Check5()) { MessageBox::Show("请完善列车站间运行信息。", "提示"); return; }
			 // 若当前没有选择项，则返回
			 if (ylistView->SelectedItems->Count <= 0) {
				 MessageBox::Show("请选定一个列表项！", this->Text);
				 return;
			 }
			 // 获取当前选择的列表项
			 ListViewItem^ item1 = ylistView->SelectedItems[0];
			 // 修改选择的列表项的内容
			 item1->SubItems[0]->Text = this->textBox8->Text;
			 item1->SubItems[1]->Text = this->textBox40->Text;
			 item1->SubItems[2]->Text = this->textBox4->Text;
			 item1->SubItems[3]->Text = this->textBox6->Text;
			 item1->SubItems[4]->Text = this->textBox3->Text;
			 item1->SubItems[5]->Text = this->textBox2->Text;
}
private: System::Void button31_Click(System::Object^  sender, System::EventArgs^  e) {//站间运行删除按钮
			 // 若当前没有选择项，则返回
			 if (ylistView->SelectedItems->Count <= 0) {
				 MessageBox::Show("请选定一个列表项！", this->Text);
				 return;
			 }
			 ListViewItem^ item1 = ylistView->SelectedItems[0];
			 ylistView->Items->Remove(item1);
}
private: System::Void button30_Click(System::Object^  sender, System::EventArgs^  e) {//站间运行取消按钮
			 this->textBox8->Clear();
			 this->textBox40->Clear();
			 this->textBox4->Clear();
			 this->textBox6->Clear();
			 this->textBox3->Clear();
			 this->textBox2->Clear();
}
private: System::Void ylistView_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {//站间运行列表选择函数
			 // 若当前没有选择项，则返回
			 if (ylistView->SelectedItems->Count <= 0) {//这个判断很关键，是下面方法的前提
				 return;
			 }
			 ListViewItem^ item2 = ylistView->SelectedItems[0];
			 this->textBox40->Text = item2->SubItems[0]->Text;
			 this->textBox4->Text = item2->SubItems[1]->Text;
			 this->textBox6->Text = item2->SubItems[2]->Text;
			 this->textBox3->Text = item2->SubItems[3]->Text;
			 this->textBox2->Text = item2->SubItems[4]->Text;
}
private: System::Boolean CheckValid(System::Void){//自定义判断为空函数

			 if (String::IsNullOrEmpty(this->textBox1->Text))return false;

			 if (String::IsNullOrEmpty(this->textBox2->Text))return false;

			 if (String::IsNullOrEmpty(this->textBox3->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox4->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox5->Text))return false;
			 return true;
}
private: System::Void button35_Click(System::Object^  sender, System::EventArgs^  e) {//方案选择添加按钮
			// fanganxuanze^fang = gcnew fanganxuanze;
			// fang->ShowDialog();
			 p = this->comboBox3->Text;
			 if (String::IsNullOrEmpty(p))
			 {
				 MessageBox::Show("方案编号不能为空。", "提示");
				 return;
			 }
			 if (this->comboBox3->Items->Contains(p))
			 {
				 MessageBox::Show("方案编号已存在。","提示");
				 return;
			 }
			 int nindex = comboBox3->Items->Add(p);
			 comboBox3->SelectedIndex = nindex;
}

private: System::Void button36_Click(System::Object^  sender, System::EventArgs^  e) {//方案修改按钮
			 fanganxuanze^fa = gcnew fanganxuanze;
			 fa->textBox1->Text = this->comboBox3->Text;
			 t = this->comboBox3->Text;
			 DataTable^ table1 = gcnew DataTable;
			 table1 = ExecuteQuery("SELECT * FROM 方案信息 WHERE 方案编号='" + t + "';");
			 
			 if (Windows::Forms::DialogResult::OK == fa->ShowDialog())
			 {
				 k = fa->m;
				 if (String::IsNullOrEmpty(k))
				 {
					 MessageBox::Show("方案编号不能为空。", "提示");
					 return;
				 }
				 if (this->comboBox3->Items->Contains(k))
				 {
					 MessageBox::Show("方案编号已存在。", "提示");
					 return;
				 }
				 if (table1->Rows->Count != 0)ExecuteUpdate("UPDATE  方案信息 SET 方案编号='" + k + "' WHERE 方案编号='" + t + "';");
				 this->comboBox3->Items->Remove(t);
				 int nindex = comboBox3->Items->Add(k);
				 comboBox3->SelectedIndex = nindex;
			 }

}
private: System::Void button34_Click(System::Object^  sender, System::EventArgs^  e) {//方案删除按钮
			 // 若当前没有选择项，则返回
			 if (comboBox3->SelectedIndex< 0) {
				 MessageBox::Show("请选定一个列表项！", this->Text);
				 return;
			 }
			 DataTable^table1 = gcnew DataTable;
			 table1 = ExecuteQuery(String::Format("SELECT * FROM 方案信息 WHERE 方案编号='{0}';", this->comboBox3->Text));
			 if (table1->Rows->Count != 0){
				 MessageBoxButtons buttons = MessageBoxButtons::YesNo;
				 if (System::Windows::Forms::DialogResult::Yes ==
					 MessageBox::Show(L"是否删除该方案？",
					 L"确认",               /*标题*/
					 buttons,               /*按钮*/
					 MessageBoxIcon::Question,      /*图标*/
					 MessageBoxDefaultButton::Button1   /*默认按钮*/))
				 {
					 ExecuteUpdate(String::Format("DELETE FROM 方案信息 WHERE 方案编号='{0}';", this->comboBox3->Text));
					 this->comboBox3->Items->RemoveAt(this->comboBox3->SelectedIndex);
				 }
				 else
				 {
					 return;
				 }
			 }
			 else{
				 this->comboBox3->Items->RemoveAt(this->comboBox3->SelectedIndex);
			 }
}

private: System::Void button25_Click(System::Object^  sender, System::EventArgs^  e) {//列车定义添加按钮
			 liechedingyi^lie = gcnew liechedingyi;
			 if (lie->ShowDialog()==Windows::Forms::DialogResult::OK)
			 {
				 k = lie->r;
				 if (this->comboBox2->Items->Contains(k))
				 {
					 MessageBox::Show("列车编号已存在。", "提示");
					 return;
				 }
				 int nindex = comboBox2->Items->Add(k);
				 comboBox2->SelectedIndex = nindex;
				 this->textBox38->Text = lie->y;
				 this->textBox5->Text = lie->u;
			 }

}
private: System::Void button26_Click(System::Object^  sender, System::EventArgs^  e) {//列车定义修改按钮
			 liechedingyi^che = gcnew liechedingyi;
			 che->textBox1->Text = this->comboBox2->Text->ToString()->Trim();
			 che->textBox2->Text = this->textBox38->Text->Trim();
			 che->textBox3->Text = this->textBox5->Text->Trim();
			 t = this->comboBox2->Text->ToString()->Trim();
			 DataTable^ table1 = gcnew DataTable;
			 table1 = ExecuteQuery("SELECT * FROM 列车信息 WHERE 列车编号='" + t + "';");
			 if (Windows::Forms::DialogResult::OK == che->ShowDialog())
			 {
				 k = che->r;
				 if (this->comboBox2->Items->Contains(k))
				 {
					 //MessageBox::Show("列车编号已存在。", "提示");
					// return;
				 }
				 if (table1->Rows->Count != 0){
					 ExecuteUpdate("UPDATE  列车信息 SET 列车编号='" + k + "' WHERE 列车编号='" + t + "';"); 
					 ExecuteUpdate("UPDATE  方案信息 SET 列车编号='" + k + "' WHERE 列车编号='" + t + "';");
					 ExecuteUpdate("UPDATE  列车站间运行信息 SET 列车编号='" + k + "' WHERE 列车编号='" + t + "';");
				 }
				 this->comboBox2->Items->Remove(t);
				 int nindex = comboBox2->Items->Add(k);
				 comboBox2->SelectedIndex = nindex;
				 this->textBox38->Text = che->y;
				 this->textBox5->Text = che->u;
			 }
}
private: System::Void button24_Click(System::Object^  sender, System::EventArgs^  e) {//列车定义删除按钮
			 // 若当前没有选择项，则返回
			 if (comboBox2->SelectedIndex< 0) {
				 MessageBox::Show("请选定一个列表项！", this->Text);
				 return;
			 }
			 DataTable^table1 = gcnew DataTable;
			 table1 = ExecuteQuery(String::Format("SELECT * FROM 列车信息 WHERE 列车编号='{0}';", this->comboBox2->Text));
			 if (table1->Rows->Count != 0){
				 MessageBoxButtons buttons = MessageBoxButtons::YesNo;
				 if (System::Windows::Forms::DialogResult::Yes ==
					 MessageBox::Show(L"将删除该列车的所有数据？",
					 L"确认",               /*标题*/
					 buttons,               /*按钮*/
					 MessageBoxIcon::Question,      /*图标*/
					 MessageBoxDefaultButton::Button1   /*默认按钮*/))
				 {
					 ExecuteUpdate(String::Format("DELETE FROM 列车信息 WHERE 列车编号='{0}';", this->comboBox2->Text));
					 ExecuteUpdate(String::Format("DELETE FROM 方案信息 WHERE 列车编号='{0}';", this->comboBox2->Text));
					 ExecuteUpdate(String::Format("DELETE FROM 列车站间运行信息 WHERE 列车编号='{0}';", this->comboBox2->Text));
					 this->comboBox2->Items->RemoveAt(this->comboBox2->SelectedIndex);
					 this->textBox38->Clear();
					 this->textBox5->Clear();
				 }
				 else
				 {
					 return;
				 }
			 }
			 else{
				 this->comboBox2->Items->RemoveAt(this->comboBox2->SelectedIndex);
				 this->textBox38->Clear();
				 this->textBox5->Clear();
			 }
}
private: System::Void button28_Click(System::Object^  sender, System::EventArgs^  e) {//轨道选择添加
			 guidaoxuanze^gui = gcnew guidaoxuanze;
			 if (Windows::Forms::DialogResult::OK == gui->ShowDialog())
			 {
				 k = gui->z;
				 if (this->comboBox4->Items->Contains(k))
				 {
					 MessageBox::Show("轨道编号已存在。", "提示");
					 return;
				 }
				 int nindex = comboBox4->Items->Add(k);
				 comboBox4->SelectedIndex = nindex;
				 this->textBox37->Text = gui->x;
				 this->textBox36->Text = gui->c;
				 this->textBox35->Text = gui->v;
			 }
}
private: System::Void button29_Click(System::Object^  sender, System::EventArgs^  e) {//轨道选择修改
			 guidaoxuanze^gui = gcnew guidaoxuanze;
			 gui->textBox1->Text = this->comboBox4->Text->Trim();
			 gui->textBox37->Text = this->textBox37->Text->Trim();
			 gui->textBox36->Text = this->textBox36->Text->Trim();
			 gui->textBox35->Text = this->textBox35->Text->Trim();
			 t = this->comboBox4->Text;
			 DataTable^ table1 = gcnew DataTable;
			 table1 = ExecuteQuery("SELECT * FROM 轨道信息 WHERE 轨道编号='" + t + "';");
			 if (Windows::Forms::DialogResult::OK == gui->ShowDialog())
			 {
				 k = gui->z;
				 if (this->comboBox4->Items->Contains(k))
				 {
				//	 MessageBox::Show("轨道编号已存在。", "提示");
				//	 return;
				 }
				 if (table1->Rows->Count != 0){
					 ExecuteUpdate("UPDATE  轨道信息 SET 轨道编号='" + k + "' WHERE 轨道编号='" + t + "';");
					 ExecuteUpdate("UPDATE  方案信息 SET 轨道编号='" + k + "' WHERE 轨道编号='" + t + "';");
				 }
				 this->comboBox4->Items->Remove(t);
				 int nindex = comboBox4->Items->Add(k);
				 comboBox4->SelectedIndex = nindex;
				 this->textBox37->Text = gui->x;
				 this->textBox36->Text = gui->c;
				 this->textBox35->Text = gui->v;
			 }
}
private: System::Void button27_Click(System::Object^  sender, System::EventArgs^  e) {//轨道选择删除
			 // 若当前没有选择项，则返回
			 if (comboBox4->SelectedIndex< 0) {
				 MessageBox::Show("请选定一个列表项！", this->Text);
				 return;
			 }
			 DataTable^table1 = gcnew DataTable;
			 table1 = ExecuteQuery(String::Format("SELECT * FROM 轨道信息 WHERE 轨道编号='{0}';", this->comboBox4->Text));
			 if (table1->Rows->Count != 0){
				 MessageBoxButtons buttons = MessageBoxButtons::YesNo;
				 if (System::Windows::Forms::DialogResult::Yes ==
					 MessageBox::Show(L"是否删除该轨道？",
					 L"确认",               /*标题*/
					 buttons,               /*按钮*/
					 MessageBoxIcon::Question,      /*图标*/
					 MessageBoxDefaultButton::Button1   /*默认按钮*/))
				 {
					 ExecuteUpdate(String::Format("DELETE FROM 轨道信息 WHERE 轨道编号='{0}';", this->comboBox4->Text));
					 ExecuteUpdate(String::Format("DELETE FROM 方案信息 WHERE 轨道编号='{0}';", this->comboBox4->Text));
					 this->comboBox4->Items->RemoveAt(this->comboBox4->SelectedIndex);
					 this->textBox37->Clear();
					 this->textBox36->Clear();
					 this->textBox35->Clear();
				 }
				 else
				 {
					 return;
				 }
			 }
			 else{
				 this->comboBox4->Items->RemoveAt(this->comboBox4->SelectedIndex);
				 this->textBox37->Clear();
				 this->textBox36->Clear();
				 this->textBox35->Clear();
			 }
}

private: System::Void comboBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {//方案选择框选择函数
			 
			 String^k = this->comboBox3->Text;
			 DataTable^ table1 = gcnew DataTable;
			 table1 = ExecuteQuery("SELECT * FROM 方案信息 WHERE 方案编号='" + k + "';");
			 if (table1->Rows->Count != 0)
			 {
				 qingkong();
				 fangMes->Clear();
				 for (i = 0; i < table1->Columns->Count; i++)
				 {
					 fangMes->Add(table1->Rows[0]->ItemArray[i]->ToString()->Trim());
				 }
				 this->comboBox1->Text = fangMes[2]->ToString();
				 xianlu();
				 this->comboBox2->Text = fangMes[3]->ToString();
				 lieche();
				 zhandian();
				 gongdianqujian();
				 honglvdeng();
				 jiancedian();
				 zhanjianyunxing();
				 this->comboBox4->Text = fangMes[4]->ToString();
				 guidao();
			 }
}
private: System::Void comboBox4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {//轨道选择框函数
			 guidao();
}
private:System::Void qingkong(Void){//清空函数
		//	this->comboBox3->Text = " ";
			this->comboBox1->Text = " ";
			this->textBox1->Clear();
			this->comboBox2->Text = " ";
			this->textBox5->Clear();
			this->textBox38->Clear();
			this->zlistView->Items->Clear();
			this->glistView->Items->Clear();
			this->hlistView->Items->Clear();
			this->jlistView->Items->Clear();
			this->ylistView->Items->Clear();
			this->comboBox4->Text = " ";
			this->textBox37->Clear();
			this->textBox36->Clear();
			this->textBox35->Clear();
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {//清空按钮
			 MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			 if (System::Windows::Forms::DialogResult::Yes ==
				 MessageBox::Show(L"若数据未保存会被删除。",
				 L"确认",               /*标题*/
				 buttons,               /*按钮*/
				 MessageBoxIcon::Question,      /*图标*/
				 MessageBoxDefaultButton::Button1   /*默认按钮*/))
			 {
				 this->comboBox3->Text = " ";
				 qingkong();
			 }
			 else
			 {
				 return;
			 }

}
private: System::Boolean Check(System::Void){//自定义判断为空函数
			 if (String::IsNullOrEmpty(this->comboBox3->Text))return false;
			 if (String::IsNullOrEmpty(this->comboBox1->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox1->Text))return false;
			 if (String::IsNullOrEmpty(this->comboBox2->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox38->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox5->Text))return false;
			 if (String::IsNullOrEmpty(this->comboBox4->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox37->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox36->Text))return false;
			 if (String::IsNullOrEmpty(this->textBox35->Text))return false;
			 if (this->zlistView->Items->Count == 0)return false;
			 if (this->glistView->Items->Count == 0)return false;
			 if (this->hlistView->Items->Count == 0)return false;
			 if (this->jlistView->Items->Count == 0)return false;
			 if (this->ylistView->Items->Count == 0)return false;
			 return true;
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {//保存按钮
			 if (!Check()) { MessageBox::Show("请完善信息。", "提示"); return; }
			 int f = length();  //计算总长度
			 int g = glength(); //计算供电区间总长度
			 int h = hlength(); //计算红绿灯总长度
			 int j = jlength(); //计算监测点总长度
			 if (g > f){ MessageBox::Show("总供电区间长度与线路总长度不匹配。", "提示"); return; }
			 if (h > f){ MessageBox::Show("总红绿灯间隔距离与线路总长度不匹配。", "提示"); return; }
			 if (j > f){ MessageBox::Show("总监测点间隔距离与线路总长度不匹配。", "提示"); return; }
			 MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			 if (System::Windows::Forms::DialogResult::Yes ==
				 MessageBox::Show(L"是否保存所有信息？",
				 L"确认",               /*标题*/
				 buttons,               /*按钮*/
				 MessageBoxIcon::Question,      /*图标*/
				 MessageBoxDefaultButton::Button1   /*默认按钮*/))
			 {
		 //存储方案信息
			 DataTable^ table1 = gcnew DataTable;
			 DateTime^dt = DateTime::Now;
			 table1 = ExecuteQuery(String::Format("SELECT * FROM 方案信息 WHERE 方案编号='{0}';", this->comboBox3->Text));
			 if (table1->Rows->Count != 0){
				 ExecuteUpdate(String::Format("UPDATE  方案信息 SET 时间='{0}',方案编号='{1}',线路编号='{2}',列车编号='{3}',轨道编号='{4}' WHERE 方案编号='{5}';"
, dt, this->comboBox3->Text, this->comboBox1->Text, this->comboBox2->Text, this->comboBox4->Text,this->comboBox3->Text));
			 }
			 else{
				 ExecuteUpdate(String::Format("INSERT INTO 方案信息 VALUES ('{0}', '{1}','{2}','{3}','{4}');"   
, dt, this->comboBox3->Text, this->comboBox1->Text, this->comboBox2->Text, this->comboBox4->Text));
			 }  
			 //存储线路信息
			 t = this->comboBox1->Text;
			 k = this->textBox1->Text;
			 u = this->zlistView->Items->Count;
			 DataTable^ table2 = gcnew DataTable;
			 table2 = ExecuteQuery("SELECT * FROM 线路信息 WHERE 线路编号='" + t + "';");
			 if (table2->Rows->Count != 0){      //如果数据库已存在线路编号
				 ExecuteUpdate("UPDATE  线路信息 SET 线路名称='" + k + "' ,站点数量= '" + u + "',线路总长度= '" + f + "' WHERE 线路编号='" + t + "';");   //更新线路信息

				 ExecuteUpdate(String::Format("DELETE FROM 站点信息  WHERE  线路编号='{0}';" , this->comboBox1->Text));    //删除旧站点信息
				 for each (ListViewItem^ lv in zlistView->Items)
				 {
					 ExecuteUpdate(String::Format("INSERT INTO 站点信息 VALUES ('{0}', '{1}','{2}','{3}','{4}','{5}','{6}');"        //修改旧站点信息
, this->comboBox1->Text, lv->SubItems[0]->Text, lv->SubItems[1]->Text, lv->SubItems[2]->Text, lv->SubItems[3]->Text, lv->SubItems[4]->Text, lv->SubItems[5]->Text));
				 }


				 ExecuteUpdate(String::Format("DELETE FROM 供电区间信息  WHERE  线路编号='{0}';", this->comboBox1->Text));    //删除旧供电区间信息
				 for each (ListViewItem^ lv in glistView->Items)
				 {
					 ExecuteUpdate(String::Format("INSERT INTO 供电区间信息 VALUES ('{0}', '{1}','{2}','{3}','{4}','{5}','{6}');"        //修改旧供电区间信息
, this->comboBox1->Text, lv->SubItems[0]->Text, lv->SubItems[1]->Text, lv->SubItems[2]->Text, lv->SubItems[3]->Text, lv->SubItems[4]->Text, lv->SubItems[5]->Text));
				 }   

				 ExecuteUpdate(String::Format("DELETE FROM 红绿灯信息  WHERE  线路编号='{0}';", this->comboBox1->Text));    //删除旧红绿灯信息
				 for each (ListViewItem^ lv in hlistView->Items)
				 {
					 ExecuteUpdate(String::Format("INSERT INTO 红绿灯信息 VALUES ('{0}', '{1}','{2}','{3}','{4}','{5}');"        //修改旧红绿灯信息
, this->comboBox1->Text, lv->SubItems[0]->Text, lv->SubItems[1]->Text, lv->SubItems[2]->Text, lv->SubItems[3]->Text, lv->SubItems[4]->Text));
				 }

				 ExecuteUpdate(String::Format("DELETE FROM 监测点信息  WHERE  线路编号='{0}';", this->comboBox1->Text));    //删除旧监测点信息
				 for each (ListViewItem^ lv in jlistView->Items)
				 {
					 ExecuteUpdate(String::Format("INSERT INTO 监测点信息 VALUES ('{0}', '{1}','{2}','{3}','{4}','{5}','{6}','{7}');"        //修改旧监测点信息
, this->comboBox1->Text, lv->SubItems[0]->Text, lv->SubItems[1]->Text, lv->SubItems[2]->Text, lv->SubItems[3]->Text, lv->SubItems[4]->Text, lv->SubItems[5]->Text, lv->SubItems[6]->Text));
				 } 

				 ExecuteUpdate(String::Format("DELETE FROM 列车站间运行信息  WHERE  线路编号='{0}';", this->comboBox1->Text));    //删除旧列车站间运行信息信息
				 for each (ListViewItem^ lv in ylistView->Items)
				 {
					 ExecuteUpdate(String::Format("INSERT INTO 列车站间运行信息 VALUES ('{0}', '{1}','{2}','{3}','{4}','{5}','{6}','{7}');"        //修改旧列车站间运行信息
 , this->comboBox2->Text, this->comboBox1->Text, lv->SubItems[0]->Text, lv->SubItems[1]->Text, lv->SubItems[2]->Text, lv->SubItems[3]->Text, lv->SubItems[4]->Text, lv->SubItems[5]->Text));
				 }
			 }
			 else{                              //如果数据库不存在该线路编号
				 ExecuteUpdate(String::Format("INSERT INTO 线路信息 VALUES ('{0}', '{1}','{2}','{3}');"
, this->comboBox1->Text, this->textBox1->Text, f,u.ToString()));  //添加新线路信息
				 for each (ListViewItem^ lv in zlistView->Items)
				 {
					 ExecuteUpdate(String::Format("INSERT INTO 站点信息 VALUES ('{0}', '{1}','{2}','{3}','{4}','{5}','{6}');"        //添加新站点信息
, this->comboBox1->Text, lv->SubItems[0]->Text, lv->SubItems[1]->Text, lv->SubItems[2]->Text, lv->SubItems[3]->Text, lv->SubItems[4]->Text, lv->SubItems[5]->Text));
				 }


				 for each (ListViewItem^ lv in glistView->Items)
				 {
					 ExecuteUpdate(String::Format("INSERT INTO 供电区间信息 VALUES ('{0}', '{1}','{2}','{3}','{4}','{5}','{6}');"        //添加新供电区间信息
, this->comboBox1->Text, lv->SubItems[0]->Text, lv->SubItems[1]->Text, lv->SubItems[2]->Text, lv->SubItems[3]->Text, lv->SubItems[4]->Text, lv->SubItems[5]->Text));
				 }  


				 for each (ListViewItem^ lv in hlistView->Items)
				 {
					 ExecuteUpdate(String::Format("INSERT INTO 红绿灯信息 VALUES ('{0}', '{1}','{2}','{3}','{4}','{5}');"        //添加新红绿灯信息
, this->comboBox1->Text, lv->SubItems[0]->Text, lv->SubItems[1]->Text, lv->SubItems[2]->Text, lv->SubItems[3]->Text, lv->SubItems[4]->Text));
				 }
				 for each (ListViewItem^ lv in jlistView->Items)
				 {
					 ExecuteUpdate(String::Format("INSERT INTO 监测点信息 VALUES ('{0}', '{1}','{2}','{3}','{4}','{5}','{6}','{7}');"        //添加新监测点信息
, this->comboBox1->Text, lv->SubItems[0]->Text, lv->SubItems[1]->Text, lv->SubItems[2]->Text, lv->SubItems[3]->Text, lv->SubItems[4]->Text, lv->SubItems[5]->Text, lv->SubItems[6]->Text));
				 }   
				 for each (ListViewItem^ lv in ylistView->Items)
				 {
					 ExecuteUpdate(String::Format("INSERT INTO 列车站间运行信息 VALUES ('{0}', '{1}','{2}','{3}','{4}','{5}','{6}','{7}');"        //添加新列车站间运行信息
, this->comboBox2->Text, this->comboBox1->Text, lv->SubItems[0]->Text, lv->SubItems[1]->Text, lv->SubItems[2]->Text, lv->SubItems[3]->Text, lv->SubItems[4]->Text, lv->SubItems[5]->Text));
				 }
			 }   
			  //存储列车信息
			 DataTable^ table3 = gcnew DataTable;
			 table3 = ExecuteQuery(String::Format("SELECT * FROM 列车信息 WHERE 列车编号='{0}'AND 线路编号='{1}' ;", this->comboBox2->Text, this->comboBox1->Text));
			 if (table3->Rows->Count != 0){
				 ExecuteUpdate(String::Format("UPDATE  列车信息 SET 列车编号='{0}',线路编号='{1}',行驶方向='{2}',载客容量='{3}'WHERE 列车编号='{4}'AND 线路编号='{5}';"
, this->comboBox2->Text, this->comboBox1->Text, this->textBox5->Text, this->textBox38->Text, this->comboBox2->Text, this->comboBox1->Text));
			 }
			 else{
				 ExecuteUpdate(String::Format("INSERT INTO 列车信息 VALUES ('{0}', '{1}','{2}','{3}');"       
, this->comboBox2->Text, this->comboBox1->Text, this->textBox5->Text, this->textBox38->Text));
			 }   
			  //存储轨道信息
			 DataTable^ table4 = gcnew DataTable;
			 table4 = ExecuteQuery(String::Format("SELECT * FROM 轨道信息 WHERE 轨道编号='{0}';", this->comboBox4->Text));
			 if (table4->Rows->Count != 0){
				 ExecuteUpdate(String::Format("UPDATE  轨道信息 SET 轨道编号='{0}',轨道名称='{1}',轨道长度='{2}',轨道半径='{3}'WHERE 轨道编号='{4}';"
, this->comboBox4->Text->Trim(), this->textBox37->Text, this->textBox36->Text, this->textBox35->Text, this->comboBox4->Text));
			 }
			 else{
				 ExecuteUpdate(String::Format("INSERT INTO 轨道信息 VALUES ('{0}', '{1}','{2}','{3}');"        
, this->comboBox4->Text->Trim(), this->textBox37->Text, this->textBox36->Text, this->textBox35->Text));
			 }

			 //存储列车站间运行信息
			 DataTable^ table5 = gcnew DataTable;
			 table5 = ExecuteQuery(String::Format("SELECT * FROM 列车站间运行信息 WHERE 列车编号='{0}' AND 线路编号='{1}';"
, this->comboBox2->Text, this->comboBox1->Text));
			 if (table5->Rows->Count != 0){
				 ExecuteUpdate(String::Format("DELETE FROM 列车站间运行信息  WHERE  列车编号='{0}' AND 线路编号='{1}';"
, this->comboBox2->Text, this->comboBox1->Text));    //删除旧列车站间运行信息
				 for each (ListViewItem^ lv in ylistView->Items)
				 {
					 ExecuteUpdate(String::Format("INSERT INTO 列车站间运行信息 VALUES ('{0}', '{1}','{2}','{3}','{4}','{5}','{6}','{7}');"        //修改旧列车站间运行信息
, this->comboBox2->Text, this->comboBox1->Text, lv->SubItems[0]->Text, lv->SubItems[1]->Text, lv->SubItems[2]->Text, lv->SubItems[3]->Text, lv->SubItems[4]->Text, lv->SubItems[5]->Text));
				 }
			 }
			 else{
				 for each (ListViewItem^ lv in ylistView->Items)
				 {
					 ExecuteUpdate(String::Format("INSERT INTO 列车站间运行信息 VALUES ('{0}', '{1}','{2}','{3}','{4}','{5}','{6}','{7}');"        //添加新列车站间运行信息
, this->comboBox2->Text, this->comboBox1->Text, lv->SubItems[0]->Text, lv->SubItems[1]->Text, lv->SubItems[2]->Text, lv->SubItems[3]->Text, lv->SubItems[4]->Text, lv->SubItems[5]->Text));
				 }
			 }
			 }
			 else
			 {
				 return;
			 }
			 MessageBox::Show("保存成功","提示");
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {//退出按钮
			 MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			 if (System::Windows::Forms::DialogResult::Yes ==
				 MessageBox::Show(L"退出后未保存的数据将会删除。",
				 L"确认",               /*标题*/
				 buttons,               /*按钮*/
				 MessageBoxIcon::Question,      /*图标*/
				 MessageBoxDefaultButton::Button1   /*默认按钮*/))
			 {
				 this->Close();
			 }
			 else
			 {
				 return;
			 }
}
		 private:int c,d;
private: System::Int32 length(Void){//自定义计算线路总长度函数
			 for each (ListViewItem^ lv in zlistView->Items)
			 {
				 c += Convert::ToInt32(lv->SubItems[3]->Text->ToString());
			 }
			 return c;
}
		
private: System::Int32 glength(Void){//自定义计算供电区间总长度函数
			 for each (ListViewItem^ lv in glistView->Items)
			 {
			  d += Convert::ToInt32(lv->SubItems[2]->Text->ToString()) + Convert::ToInt32(lv->SubItems[3]->Text->ToString());
			 }
			 return d;
}
private: System::Int32 hlength(Void){//自定义红绿灯总长度函数
			 int c;
			 for each (ListViewItem^ lv in hlistView->Items)
			 {
				 c += Convert::ToInt32(lv->SubItems[4]->Text->ToString());
			 }
			 return c;
}
private: System::Int32 jlength(Void){//自定义监测点总长度函数
			 int c;
			 for each (ListViewItem^ lv in jlistView->Items)
			 {
				 c += Convert::ToInt32(lv->SubItems[3]->Text->ToString());
			 }
			 return c;
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {//刷新按钮
			 //加载方案信息
			 this->comboBox3->Items->Clear();
			 this->fangMes->Clear();
			 DataTable^ table1 = gcnew DataTable;
			 table1 = ExecuteQuery("SELECT * FROM 方案信息 ;");
			 for (i = 0; i < table1->Rows->Count; i++)
			 {
				 fangMes->Add(table1->Rows[i]->ItemArray[1]->ToString()->Trim());
				 this->comboBox3->Items->Add(fangMes[i]);
			 }
			 //加载线路信息
			 this->comboBox1->Items->Clear();
			 this->xianMes->Clear();
			 DataTable^ table2 = gcnew DataTable;
			 table2 = ExecuteQuery("SELECT * FROM 线路信息 ;");
			 for (i = 0; i < table2->Rows->Count; i++)
			 {
				 xianMes->Add(table2->Rows[i]->ItemArray[0]->ToString()->Trim());
				 this->comboBox1->Items->Add(xianMes[i]);
			 }
			 DataTable^ table3 = gcnew DataTable;
			 //加载列车信息
			 this->comboBox2->Items->Clear();
			 this->cheMes->Clear();
			 table3 = ExecuteQuery("SELECT DISTINCT 列车编号  FROM 列车信息 ;");
			 for (i = 0; i < table3->Rows->Count; i++)
			 {
				 cheMes->Add(table3->Rows[i]->ItemArray[0]->ToString()->Trim());
				 this->comboBox2->Items->Add(cheMes[i]);
			 }
			 DataTable^ table4 = gcnew DataTable;
			 //加载轨道信息
			 this->comboBox4->Items->Clear();
			 this->guiMes->Clear();
			 table4 = ExecuteQuery("SELECT * FROM 轨道信息 ;");
			 for (i = 0; i < table4->Rows->Count; i++)
			 {
				 guiMes->Add(table4->Rows[i]->ItemArray[0]->ToString()->Trim());
				 this->comboBox4->Items->Add(guiMes[i]);
			 }
			 qingkong();
}

private: System::Void 实际线路图ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 RealRoadForm^realroadform = gcnew RealRoadForm();
			 realroadform->Show();
}
private: System::Void 功耗分析视图ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 PowerDissipationForm^powerdissipationform = gcnew PowerDissipationForm();
			 powerdissipationform->Show();
}
private: System::Void 各天人流量数据统计图ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 PeopleFlowForm^peopleflowform = gcnew PeopleFlowForm();
			 peopleflowform->Show();
}
private: System::Void 人流量的时间分布图ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 TimeandPeopleFlowForm^timeandpeopleflowform = gcnew TimeandPeopleFlowForm();
			 timeandpeopleflowform->Show();
}
private: System::Void 人流量时间站点三者分布图ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 StationPeopleTimeForm^stationpeopletimeform = gcnew StationPeopleTimeForm();
			 stationpeopletimeform->Show();
}
private: System::Void 各方案车内人数ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Single_Project_UpDownPeopleForm^peopleform = gcnew Single_Project_UpDownPeopleForm();
			 peopleform->Show();
}
private: System::Void 模拟线路图ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	SimulateRoadForm^simulateform = gcnew SimulateRoadForm();
	simulateform->Show();
	
}
private: System::Void 逻辑站点图ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	StationLogicForm^stationform = gcnew StationLogicForm();
	stationform->Show();
}
};
}
