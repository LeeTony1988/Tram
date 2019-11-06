#pragma once

//#include"windows.h"
#include <GL/glut.h>
#include <vector>
#include <time.h>
//#include<WinUser.h>
//#include<windef.h>
//#include<synchapi.h>
//#include<wingdi.h>
//#include<WinNls.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Data::Common;
using namespace System::Data::OleDb;
using namespace System::Collections;
using namespace System::Runtime::InteropServices;

namespace StraightPaintForm {
	ref class Point
	{
	public:
		float _x, _y, _z;
		Point() {}
		Point(float x, float y) {
			_x = x;
			_y = y;
			_z = 0.0f;
		}
	};

	//站点
	ref class Site {
	public:
		String	^ name;
		String^site_no;
		GLfloat actual_dist;		//距离上一个站点或者起始点的实际距离
		GLfloat scale_dist;			//屏幕上的距离
		Point^ pos;
		bool ifArrived = false;		//是否到达站点
		bool ifIn = false;			//正向时为是否进入该站点为起点的站间，反向时为是否进入该站点为终点的站间
		int arrivedTram_no;			//到站列车索引，不分正反
		int arrivedTram_no1;		//到站列车索引，分正反
		String^arrivedTram_strnum;	//到站列车字符编号
		String^ arrivingTram_strnum = nullptr;//预备到站列车字符编号

		int stayTime;//到站停留时间
		int times;
		int run_time;//站间运行时间
		//float v = 0;
		List<int>^up_people = gcnew List<int>();//上车人数
		List<int>^down_people = gcnew List<int>();//下车人数
		List<int>^peoples = gcnew List<int>();//客流量
	};

	//有轨电车
	ref class Tram
	{
	public:
		//需要初始化的信息
		String^pronum;//方案编号
		int tram_no;//索引列车编号
		String^tram_num;//列车编号
		Point^ p1, ^p2, ^p3, ^p4, ^p5, ^p6;		 //车顺时针6个点
		int capacity = 150;	//电车容量,默认150，后面会从数据库中查询更新
		bool positive_run;//行驶方向
		List<Site^>^tram_siteinfo = gcnew List<Site^>();//各有轨电车在站点处信息

		bool draw = false;//绘制标志
		bool finish = false;//若运行完成不绘制

		int hasPassed = 0;//记录电车已经通过的站点号

		int passengers_num;	   //乘客数目
		float rate;//列车实时空载率
		float avg_rate = 0.0f;//列车平均空载率
		float min_rate = 0.0f;//列车最小空载率

		float total_step;//有轨电车总行驶路程（步长为屏幕总步长，暂时没用到），屏幕中的位置数据
		float prepos = 0;//上一时刻的数据库位置信息
		float pos = 0;//从数据库查询的电车位置数据
		float cal_step = 0;//利用实际存储位置与比例计算出的屏幕绘制步长
		float velocity = 0;//列车速度
		float accelerate = 0;//加速度
		float current = 0;//电流
		float voltage = 0;//电压

		int oridatanum;//第一个数据的数据序号
		int datanum;//当前数据序号
		int maxdatanum;//最大数据序号
		float last_pos;//数据库中最终位置
		String^timeflow;//数据自身时间流，以数据库中第一条数据时间作为起点
		String^settime;//方案定制中人工设置的时间起点

		//将数据库中的位置信息转换成屏幕绘制
		void PosTransform(float scale)
		{
			cal_step = (pos - prepos)*scale;
		}

		//当方向改变时需要重新设置小车位置
		void ResetPoint(bool direction, float orbitlen,float tramwidth,float tramtopath,float tramheigh,float tmp)
		{
			if (direction)//正向
			{
				p1 = gcnew Point(-orbitlen-tramwidth,tmp+tramtopath+tramheigh);
				p2 = gcnew Point(-orbitlen+tramwidth,tmp+tramtopath+tramheigh);
				p3 = gcnew Point(-orbitlen+tramwidth,tmp+tramtopath);
				p4 = gcnew Point(-orbitlen-tramwidth,tmp+tramtopath);
				p5 = gcnew Point(-orbitlen,tmp+tramtopath);
				p6 = gcnew Point(-orbitlen,tmp-tramtopath);
			}
			else       //反向
			{
				p1 = gcnew Point(orbitlen + tramwidth, tmp - tramtopath - tramheigh);
				p2 = gcnew Point(orbitlen - tramwidth, tmp - tramtopath - tramheigh);
				p3 = gcnew Point(orbitlen - tramwidth, tmp - tramtopath);
				p4 = gcnew Point(orbitlen + tramwidth, tmp - tramtopath);
				p5 = gcnew Point(orbitlen, tmp + tramtopath);
				p6 = gcnew Point(orbitlen, tmp - tramtopath);
			}

		}
		//构造函数
		Tram() {}
		Tram(Point^ _p1, Point^ _p2, Point^ _p3, Point^ _p4, Point^ _p5, Point^ _p6)
		{
			p1 = _p1;
			p2 = _p2;
			p3 = _p3;
			p4 = _p4;
			p5 = _p5;
			p6 = _p6;
		}
	};

	//红绿灯
	ref class Trafficlight
	{
	public:
		int light_no;//灯数字编号
		String^lightnum;//存储编号

		String^pos_dis;//灯位置描述
		GLfloat actural_pos;//灯实际位置
		GLfloat screen_pos;//灯屏幕位置
		Point^point;
		bool redf = true;//红灯亮标志
		bool greenf = false;//绿灯亮标志
		float redtime;//红灯时间
		float greentime;//绿灯时间

		GLfloat hight1 = 0.04f;//灯柱高度
		GLfloat width1 = 0.04f;//灯宽一半
		GLfloat hight2 = 0.04f;
	public:
		Trafficlight() {}
		Trafficlight(int light_no1, float pos1)
		{
			light_no = light_no1;
			actural_pos = pos1;
		}

	};

	//OpenGL窗体类
	const float pi = 3.141592f;
	public ref class StraightLinePaint : public System::Windows::Forms::NativeWindow
	{

	public:
		HDC m_hDC;
		HGLRC m_hglrc;
		List<Site^>^  sites;  //正向站点
		List<Site^>^  sites1;//反向站点
		Tram^tram;//列车
		List<Tram^>^ trams = gcnew List<Tram^>();
		List<Trafficlight^>^trlights = gcnew List<Trafficlight^>();

		int runningMode=0;//运行模式：0是即放即行，1是实时。

		char *line_num; //线路编号
		//String^project_num;//方案编号
		
		//直轨图
		//char *tram_num;//电车编号
		float road_len;//线路总长度，数据库中查询所得
		//float scale_len = 3.6f;//屏幕线路总长度
		float scale_len = 1.8f;//屏幕线路总长度
		float scale;//屏幕长度与数据库中定义实际线路长度比值
		float path_width = 0.01;//轨道宽度
		//float orbit_len = 1.8f;//屏幕一半长度
		float orbit_len = 0.9f;//屏幕一半长度
		float tram_to_path = 0.04f;//车轨距离
		//红绿灯
		float lig_to_path=0.065f;
		//逻辑站点图
		//float stand_len = 1.6f;//逻辑站点图一半的长度
		float stand_len = 0.8f;//逻辑站点图一半的长度

		//列车绘制
		float tram_width = 0.02f;//列车一半长度
		float tram_height = 0.02f;//列车高度

		bool positive_run = true;//行驶方向
		float step;//行驶步长
		//float total_step;//总行驶路程

		int tram_no = 0;//正向列车编号
		int tram_no1 = 0;//反向列车编号

		DataTable^restable;//存储查询结果


	public:
		// 初始化绘图数据，初始化OpenGL窗体
		StraightLinePaint(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight, int x, int y)
		{
			CreateParams^ cp = gcnew CreateParams();	  //CreateParams 来重载窗体的一些特性

			// 设置窗体上的位置
			cp->X = x;
			cp->Y = y;
			cp->Height = iHeight;
			cp->Width = iWidth;
			//指定窗体为父窗体
			cp->Parent = parentForm->Handle;
			// 创建指定父级的子对象并使其符合OpenGL（无剪辑）
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			// 通过cp设置的参数来创建实际窗口
			this->CreateHandle(cp);

			m_hDC = GetDC((HWND)this->Handle.ToPointer());//获取创建窗口的句柄

			//如果窗口创建成功
			if (m_hDC)
			{
				//窗口色素格式设置
				mySetPixelFormat(m_hDC);
				//调整GL窗口大小
				reSizeGLScene(iWidth, iHeight);
				//初始化OpenGL界面  获取线路编号、列车编号、设置轨道长度、半径
				initGL();
				//获取线路长度、站点信息
				//DB_assign_value();

				//初始化线路数据
				//initLine();

				//站点人数初始化
				//initSitePeople();

				//初始化列车信息
				//initTram(true);
			}
		}

		//回调函数，实时绘制图形
		System::Void Render(int modenum)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// 清除屏幕和深度缓冲区
			glLoadIdentity();// 重置当前模型视图矩阵
			glTranslatef(0.0f, 0.0f, -1.5f);

			drawPath();//画双直线轨道
			showSites();//画双直线轨道上的圆形站点
			drawTrafficLight();//画红绿灯
			//showStand();//绘制逻辑站点图-带站点名字
			//glPushMatrix();

			String^str1("");
			str1 += 1;
			char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
			glRasterPos2f(-4.0f, 0);
			drawCNString(ch);

			//绘制同一时刻的所有列车
			if (modenum != 3)
			{
				for (int i = 0; i < trams->Count; i++) {
					if (modenum == 1)
					{
						Runimm(trams[i], i);
					}
					if (!trams[i]->finish)
					{
						drawTram(i);
					}
				}
			}
			else if (modenum == 3)//实时模式
			{
				RunSys(trams[0], 0);
				if (!trams[0]->finish)
				{
					drawTram(0);
				}
			}
			showStand();//绘制逻辑站点图-带站点名字
			glPushMatrix();
			/*for (int i = 0; i < trams->Count; i++) {
				running(trams[i],i);
			}*/
		}

		//刷新缓冲
		System::Void swapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC);
		}

		//更新车内人数及实时空载率
		System::Void updatePeopleOnTramAndEmptyRate(Tram^ tram) {
			if (tram->positive_run)//正向
			{

			}
		}

		//从数据库获取数据，获取线路长度route_len、正反站点信息及站间运行时间、红绿灯
		ArrayList^fangMes = gcnew ArrayList();//用来暂存每一条数据库取出的信息
		System::Void DB_assign_value()
		{
			DataTable^ table1 = gcnew DataTable;
			String^ str1 = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)line_num);//由线路编号获取线路信息
			String ^sql = "SELECT [线路总长度] FROM [线路信息] WHERE 线路编号 = '" + str1 + "';";
			table1 = ExecuteQuery(sql);

			//获取线路长度
			for (int j = 0; j < table1->Rows->Count; j++) {
				fangMes->Clear();
				for (int i = 0; i < table1->Columns->Count; i++)
				{
					fangMes->Add(table1->Rows[j]->ItemArray[i]);
				}
				String^ tmp = fangMes[0]->ToString()->Trim();
				const char* ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				road_len = atof(ts);
			}

			//获取线路站点情况
			sql = "SELECT [站点名称],[站间距离],[站点编号] FROM [站点信息] WHERE 线路编号 = '" + str1 + "' ORDER BY 站点编号;";
			table1 = ExecuteQuery(sql);
			sites = gcnew List<Site^>();
			//sites1 = gcnew List<Site^>();
			for (int j = 0; j < table1->Rows->Count; j++) {
				Site^ s = gcnew Site();
				fangMes->Clear();
				for (int i = 0; i < table1->Columns->Count; i++)
				{
					fangMes->Add(table1->Rows[j]->ItemArray[i]);
				}
				if (String::Equals(fangMes[0]->ToString()->Trim(), "水拥坑(海天公园)"))
				{
					s->name = "水拥坑";
				}
				else
				{
					s->name = fangMes[0]->ToString()->Trim();//名称
				}
				String^ tmp = fangMes[1]->ToString()->Trim();
				const char* ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				s->actual_dist = atof(ts);//距离
				s->site_no = fangMes[2]->ToString()->Trim();//站点编号
				sites->Add(s);//正向站点
				//sites1->Add(s);//反向站点
			}
			
			//反向站点:这里已测试排序没问题。。这里程序和上面一样，但是将site1放在上面site就显示不出来，不知道为啥
			sql = "SELECT [站点名称], [站间距离],[站点编号] FROM [站点信息] WHERE 线路编号 = '" + str1 + "' ORDER BY 站点编号;";
			table1 = ExecuteQuery(sql);
			sites1 = gcnew List<Site^>();
		
			for (int j = 0; j < table1->Rows->Count; j++) {
				Site^ s = gcnew Site();
				fangMes->Clear();
				for (int i = 0; i < table1->Columns->Count; i++)
				{
					fangMes->Add(table1->Rows[j]->ItemArray[i]);
				}
				if (String::Equals(fangMes[0]->ToString()->Trim(), "水拥坑(海天公园)"))
				{
					s->name = "水拥坑";
				}
				else
				{
					s->name = fangMes[0]->ToString()->Trim();//站点名称
				}
				String^ tmp = fangMes[1]->ToString()->Trim();
				const char* ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				s->actual_dist = atof(ts);//站间距离
				s->site_no = fangMes[2]->ToString()->Trim();//站点编号
				sites1->Add(s);
			}
			
			//红绿灯
			sql = "SELECT 红绿灯编号,红绿灯位置,红灯时间,绿灯时间,相邻红绿灯距离 FROM 红绿灯信息 WHERE 线路编号='" + str1 + "' ORDER BY 红绿灯编号;";
			table1 = ExecuteQuery(sql);
			trlights->Clear();
			for (int i = 0; i < table1->Rows->Count; i++)
			{
				Trafficlight^trlight = gcnew Trafficlight(i+1,float::Parse(table1->Rows[i]->ItemArray[4]->ToString()));
				trlight->lightnum = table1->Rows[i]->ItemArray[0]->ToString();//灯字符编号
				trlight->pos_dis = table1->Rows[i]->ItemArray[1]->ToString();//灯位置描述
				trlight->redtime = float::Parse(table1->Rows[i]->ItemArray[2]->ToString());//红灯时间
				trlight->greentime= float::Parse(table1->Rows[i]->ItemArray[3]->ToString());//绿灯时间

				trlights->Add(trlight);
			}

			/*
			//获取站间运行时间
			sql = "SELECT [站点停留时间], [站点运行时间] FROM[列车站间运行信息] WHERE 方案编号 = '" + "P001" + "' AND 列车编号='T001';";
			table1 = ExecuteQuery(sql);
			for (int j = 0; j < table1->Rows->Count; j++) {
				fangMes->Clear();
				for (int i = 0; i < table1->Columns->Count; i++)
				{
					fangMes->Add(table1->Rows[j]->ItemArray[i]);
				}
				String^ tmp = fangMes[0]->ToString()->Trim();
				const char* ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				sites[j]->stayTime = atoi(ts);
				tmp = fangMes[1]->ToString()->Trim();
				const char* ts1 = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				sites[j]->run_time = atoi(ts1);
			}
			
			//获取站间运行时间
			sql = "SELECT [站点停留时间], [站点运行时间] FROM[standBet_info] WHERE 方案编号 = '" + "P001" + "' AND 列车编号='T001' ORDER BY 站点编号 DESC;";
			table1 = ExecuteQuery(sql);
			for (int j = 0; j < table1->Rows->Count; j++) {
				fangMes->Clear();
				for (int i = 0; i < table1->Columns->Count; i++)
				{
					fangMes->Add(table1->Rows[j]->ItemArray[i]);
				}
				String^ tmp = fangMes[0]->ToString()->Trim();
				const char* ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				sites1[j]->stayTime = atoi(ts);
				tmp = fangMes[1]->ToString()->Trim();
				const char* ts1 = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				sites1[j]->run_time = atoi(ts1);
			}*/
			
		}

		//初始化站点坐标、红绿灯坐标
		System::Void initLine() {
			//站点
			int site_index = 0;
			//int site1_index = sites1->Count - 1;
			int site1_index = 0;
			float site_dist = 0.0f;
			float total_dist = 0.0f;
			scale = scale_len / road_len;//屏幕总长(自定义1.8f)与线路总长之比

			//获取屏幕距离长度
			for each (Site^ s in sites)
			{
				s->scale_dist = s->actual_dist*scale;//这里算出站点距离上一站点的距离（换算到电脑屏幕比例）
			}

			for each (Site^ s in sites1)
			{
				s->scale_dist = s->actual_dist*scale;
			}
			//遍历站点集合sites,获取每个站点在途中的坐标位置
			while (site_index < sites->Count)
			{
				site_dist += sites[site_index]->scale_dist;
				sites[site_index]->pos = gcnew Point(site_dist - orbit_len, 0.0f);     //获取站点绘制坐标
				sites1[site1_index]->pos = gcnew Point(site_dist - orbit_len, -0.1f);     //获取站点绘制坐标，反向站点y坐标向下偏移一点
				/*
				if (site_index < sites->Count - 1) {
					//求得站间运行步长
					sites[site_index]->v = sites[site_index + 1]->scale_dist / sites[site_index]->run_time;
					sites1[site_index]->v = sites1[site_index]->scale_dist / sites1[site_index + 1]->run_time;
				}
				*/
				site_index++;
				//site1_index--;
				site1_index++;
			}

			//红绿灯
			GLfloat lig_dis = 0.0f;
			for each(Trafficlight^lig in trlights)
			{
				lig->screen_pos = lig->actural_pos*scale;
			}
			for (int i = 0; i < trlights->Count; i++)
			{
				lig_dis += trlights[i]->screen_pos;
				trlights[i]->point = gcnew Point(lig_dis-orbit_len,-0.1f-lig_to_path);
			}

		}

		//更新站点信息
		System::Void showSites() {
			GLfloat out_R = 0.02f;//站点外环坐标

			//将所有站点的到站标志位清零，再重新标取当前时刻到站站点
			for (int k = 0; k < sites->Count; k++)
			{
				sites[k]->ifArrived = false;
				sites[k]->ifIn = false;
				sites1[k]->ifArrived = false;
				sites1[k]->ifIn = false;

			}
			for (int i = 0; i < sites->Count; i++)
			{
				for (int j = 0; j < trams->Count; j++) {
					//正向
					if (trams[j]->positive_run) {
						//列车进入站点
						if (trams[j]->p5->_x >= sites[i]->pos->_x - out_R && trams[j]->p5->_x < sites[i]->pos->_x + out_R && trams[j]->hasPassed < (sites->Count) && sites[i]->ifIn==false) {
							sites[i]->ifArrived = true;//列车到站
							sites[i]->ifIn = false;
							sites[i]->arrivedTram_no = j;//没使用
							sites[i]->arrivedTram_no1 = trams[j]->tram_no;//没使用
							sites[i]->arrivedTram_strnum = trams[j]->tram_num;//字符型电车编号
							sites[i]->arrivingTram_strnum = nullptr;
							trams[j]->velocity = 0;//更新列车速度，站点停留
							trams[j]->hasPassed=i;//到达最后一个站点后hasPassed=13
							//清空一下数据
							if (trams[j]->hasPassed > 0) {
								sites[trams[j]->hasPassed - 1]->ifIn = false;
							}
						}
						if (i<(sites->Count-1) && !trams[j]->finish && trams[j]->hasPassed>=0 && trams[j]->p5->_x >= (sites[i]->pos->_x + out_R) && trams[j]->hasPassed == i)
						{
							//列车驶出站点而且还未到达下一站点
							//sites[trams[j]->hasPassed - 1]->ifIn = true;
							sites[i]->ifIn = true;
							sites[i+1]->arrivingTram_strnum = trams[j]->tram_num;
							//清空到站信息
							//sites[trams[j]->hasPassed - 1]->ifArrived = false;
							//sites[trams[j]->hasPassed - 1]->arrivedTram_strnum = nullptr;
							sites[i]->ifArrived = false;
							sites[i]->arrivedTram_strnum = nullptr;
						}
							
					}
					//反向
					else {
						if (trams[j]->p5->_x <= sites1[sites1->Count-1-i]->pos->_x + out_R && trams[j]->p5->_x > sites1[sites1->Count - 1 - i]->pos->_x - out_R && trams[j]->hasPassed<(sites1->Count) && sites1[sites1->Count - 1 - i]->ifIn==false) {
							sites1[sites1->Count - 1 - i]->ifArrived = true;//列车到站
							sites1[sites1->Count - 1 - i]->ifIn = false;
							sites1[sites1->Count - 1 - i]->arrivedTram_no = j;
							sites1[sites1->Count - 1 - i]->arrivedTram_no1 = trams[j]->tram_no;
							sites1[sites1->Count - 1 - i]->arrivedTram_strnum = trams[j]->tram_num;
							sites1[sites1->Count - 1 - i]->arrivingTram_strnum = nullptr;
							trams[j]->velocity = 0;
							trams[j]->hasPassed = i;
							//清空一下数据
							if (trams[j]->hasPassed > 0) {
								sites1[sites1->Count - 1 - (trams[j]->hasPassed - 1)]->ifIn = false;
							}
						}
						if (i < (sites1->Count - 1) && !trams[j]->finish && trams[j]->hasPassed >= 0 && trams[j]->p5->_x <= sites1[sites1->Count - 1 - i]->pos->_x - out_R && trams[j]->hasPassed == (i))
						{
							sites1[sites1->Count - 1 - i]->ifIn = true;
							sites1[sites1->Count - 1 - i -1]->arrivingTram_strnum = trams[j]->tram_num;
							//清空到站信息
							sites1[sites1->Count - 1 - i]->ifArrived = false;
							sites1[sites1->Count - 1 - i]->arrivedTram_strnum = nullptr;
						}
					}
				}
				//更新站点信息后重绘站点
				drawSites(i, sites[i]->pos->_x, sites[i]->pos->_y, 0.02f, sites[i]->ifArrived);
				drawSites(i, sites1[i]->pos->_x, sites1[i]->pos->_y, 0.02f, sites1[i]->ifArrived);
			}
		}

		//绘制站点  ifPass 是否到达，x，y为圆心坐标值
		System::Void drawSites(int site_index, float x, float y, float R, bool ifArrive)
		{
			//站点绘制 圆环
			static int n = 20;
			glLineWidth(3.0f);
			glBegin(GL_POLYGON);
			glColor3f(0.5f + (ifArrive)*(0.5f), 0.7f, 0.7f);
			//外环
			for (int i = 0; i < n; i++)
			{
				glVertex2f(x + R * cosf(2 * pi*i / n), y + R * sinf(2 * pi*i / n));   //获取20个绘制圆的顶点
			}
			glEnd();
			glLineWidth(1.0f);

			glBegin(GL_POLYGON);
			//内环
			for (int i = 0; i < n; i++)
			{
				glVertex2f(x + (R - 0.005f) * cosf(2 * pi*i / n), y + (R - 0.005f) * sinf(2 * pi*i / n));   //获取20个绘制圆的顶点
			}
			glEnd();

		}

		//站点人数初始化
		Random^random = gcnew Random();
		System::Void initSitePeople() {
			//正向站点的人数初始化
			for (int i = 0; i < sites->Count; i++) {
				if (i < sites->Count - 1) {
					for (int j = 0; j < 28; j++) {
						//高峰时段客流量
						if (j == 1 && j == 2 && j == 3 && j == 4 && j == 20 && j == 21 && j == 22 && j == 23) {
							sites[i]->up_people->Add(random->Next(10, 14));
							sites[i]->down_people->Add(0);
							sites[i]->peoples->Add(0);
						}
						else {
							sites[i]->up_people->Add(random->Next(4, 8));
							sites[i]->down_people->Add(0);
							sites[i]->peoples->Add(0);
						}
					}
				}
				//如果为终点站，上车人数为0
				else {
					for (int j = 0; j < 28; j++) {
						sites[i]->up_people->Add(0);
						sites[i]->down_people->Add(0);
						sites[i]->peoples->Add(0);
					}

				}
			}
			//反向站点的人数初始化
			for (int i = 0; i < sites1->Count; i++) {
				if (i < sites1->Count - 1) {
					for (int j = 0; j < 28; j++) {
						//高峰时段客流量
						if (j == 0 && j == 1 && j == 2 && j == 3 && j == 19 && j == 20 && j == 21 && j == 22) {
							sites1[i]->up_people->Add(random->Next(10, 14));
							sites1[i]->down_people->Add(0);
							sites1[i]->peoples->Add(0);
						}
						else {
							sites1[i]->up_people->Add(random->Next(4, 8));
							sites1[i]->down_people->Add(0);
							sites1[i]->peoples->Add(0);
						}
					}
				}
				//如果为终点站，上车人数为0
				else {
					for (int j = 0; j < 28; j++) {
						sites1[i]->up_people->Add(0);
						sites1[i]->down_people->Add(0);
						sites1[i]->peoples->Add(0);
					}

				}
			}
		}

		//更新站点人数,站点索引，isPositive方向,time_dex时间段
		System::Void updateSitePeople(int site_index, int time_dex, bool isPositive) {
			if (isPositive) {
				if (time_dex == 0 && time_dex == 9 && time_dex == 10) {
					sites[site_index]->up_people[time_dex] = random->Next(15, 20);
					sites[site_index]->down_people[time_dex] = random->Next(5, 20);
					sites[site_index]->peoples[time_dex] = random->Next(40, 50);
				}
				else {
					sites[site_index]->up_people[time_dex] = random->Next(5, 10);
					sites[site_index]->down_people[time_dex] = random->Next(5, 10);
					sites[site_index]->peoples[time_dex] = random->Next(20, 30);
				}
			}
			else {
				if (time_dex == 0 && time_dex == 9 && time_dex == 10) {
					sites1[site_index]->up_people[time_dex] = random->Next(15, 20);
					sites1[site_index]->down_people[time_dex] = random->Next(5, 20);
					sites1[site_index]->peoples[time_dex] = random->Next(40, 50);
				}
				else {
					sites1[site_index]->up_people[time_dex] = random->Next(5, 10);
					sites1[site_index]->down_people[time_dex] = random->Next(5, 10);
					sites1[site_index]->peoples[time_dex] = random->Next(20, 30);
				}
			}
		}

		//轨道绘制
		System::Void drawPath() {
			//轨道颜色
			glColor3f(0.3f, 0.6f, 1.0f);

			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

			//绘制上直线轨道
			glBegin(GL_LINES);
			glVertex2f(-orbit_len, -0.0f);
			glVertex2f(orbit_len, -0.0f);
			glEnd();
			glBegin(GL_LINES);
			glVertex2f(orbit_len, -0.0f - path_width);
			glVertex2f(-orbit_len, -0.0f - path_width);
			glEnd();


			//绘制下直线轨道
			glBegin(GL_LINES);
			glVertex2f(-orbit_len, -0.1f);
			glVertex2f(orbit_len, -0.1f);
			glEnd();
			glBegin(GL_LINES);
			glVertex2f(orbit_len, -0.1f - path_width);
			glVertex2f(-orbit_len, -0.1f - path_width);
			glEnd();

		}

		//绘制逻辑站点图-带名字的
		System::Void showStand() 
		{
			//绘制站点名字
			String^ str;
			int site_num = sites->Count;//站点数目
			int name_max = sites[0]->name->Length;//站点名称最大值
			//每个站点的间隔
			float delta_x = 2 * stand_len / site_num;
			//起始站点横坐标值
			float x = -stand_len;
			float x_end = stand_len-delta_x;//终点站点横坐标值
			float dist_x = 0.0f;
			float dist_x1 = 0.0f;
			float R = 0.02f;//站点圆半径
			float r = 0.015f;//站点圆半径

			//遍历站点集合，获取站点名称最大值
			for (int site_index = 0; site_index < site_num; site_index++) {
				if (name_max < sites[site_index]->name->Length) {
					name_max = sites[site_index]->name->Length;
				}
			}
			//遍历上部站点集合
			for (int site_index = 0; site_index < site_num; site_index++) {
				//绘制站点名称
				glColor3f(0.2f, 0.2f, 0.2f);
				str = sites[site_index]->name;
				//设置字体显示位置
				float y = 0.45f;//第一个字体显示的纵坐标
				for (int i = 0; i < str->Length; i++) {
					String^str1("");
					str1 += str[i];
					char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
					glRasterPos2f(x + dist_x, y);
					drawCNString(ch);
					y = y - 0.06f;
				}

				//绘制上部站点圆
				glColor3f(0.0f + sites[site_index]->ifArrived*1.0f, 0.5f - sites[site_index]->ifArrived*0.5f, 0.5f - sites[site_index]->ifArrived*0.5f); //设置颜色
				glBegin(GL_POLYGON);//开始画圆
				for (int i = 0; i < 20; ++i)
					glVertex2f(x + dist_x + 0.025f + R * cos(2 * pi / 20 * i), 0.55f + R * sin(2 * pi / 20 * i));//圆的坐标
					//glVertex2f(x + dist_x  + R * cos(2 * pi / 20 * i), 0.55f + R * sin(2 * pi / 20 * i));//圆的坐标
				glEnd();
				glBegin(GL_POLYGON);//开始画圆
				for (int i = 0; i < 20; ++i)
					glVertex2f(x + dist_x + 0.025f + r * cos(2 * pi / 20 * i), 0.55f + r * sin(2 * pi / 20 * i));//圆的坐标
					//glVertex2f(x + dist_x  + r * cos(2 * pi / 20 * i), 0.55f + r * sin(2 * pi / 20 * i));//圆的坐标
				glEnd();

				//绘制列车到站图标
				if (sites[site_index]->ifArrived && sites[site_index]->ifIn==false) {
					glColor3f(1.0f, 0.0f, 0.0f); //设置颜色
					glBegin(GL_POLYGON);//开始画圆
					for (int i = 0; i < 20; ++i)
						glVertex2f(x + dist_x + 0.025f + 0.025f*cos(2 * pi / 20 * i), 0.59f + 0.025f*sin(2 * pi / 20 * i));//圆的坐标
						//glVertex2f(x + dist_x  + 0.025f*cos(2 * pi / 20 * i), 0.59f + 0.025f*sin(2 * pi / 20 * i));//圆的坐标
					glEnd();
					String^str1("");
					//str1 += (sites[site_index]->arrivedTram_no1);
					str1 += (sites[site_index]->arrivedTram_strnum);
					char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
					glRasterPos2f(x + dist_x + 0.016f, 0.575f);
					drawCNString(ch);
				}
				else if (site_index < site_num - 1 && sites[site_index]->ifIn && !sites[site_index + 1]->ifArrived && !sites[site_index]->ifArrived && !String::Equals(sites[site_index +1]->arrivingTram_strnum,nullptr)) 
				{
					//绘制列车站间图标
					glColor3f(1.0f, 0.0f, 0.0f); //设置颜色
					glBegin(GL_POLYGON);//开始画圆
					for (int i = 0; i < 20; ++i)
						glVertex2f(x + dist_x + 0.025f + 0.025f*cos(2 * pi / 20 * i) + delta_x / 2, 0.59f + 0.025f*sin(2 * pi / 20 * i));//圆的坐标
						//glVertex2f(x + dist_x  + 0.025f*cos(2 * pi / 20 * i) + delta_x / 2, 0.59f + 0.025f*sin(2 * pi / 20 * i));//圆的坐标
					glEnd();
					String^str1("");
					//str1 += (sites[site_index]->arrivedTram_no1);
					str1 += (sites[site_index+1]->arrivingTram_strnum);
					//MessageBox::Show(str1);
					char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
					glRasterPos2f(x + dist_x + 0.016f + delta_x / 2, 0.575f);
					drawCNString(ch);
					//MessageBox::Show(site_index.ToString());
				}

				if (site_index < site_num - 1) {
					//绘制上部虚线
					glColor3f(0.0f + sites[site_index]->ifIn*1.0f, 0.5f - sites[site_index]->ifIn*0.5f, 0.5f - sites[site_index]->ifIn*0.5f); //设置颜色
					glLineStipple(2, 0x5555);
					glEnable(GL_LINE_STIPPLE);
					glBegin(GL_LINES);
					glVertex2f(x + dist_x + 0.025f + R, 0.55f);
					glVertex2f(x + dist_x + 0.025f + delta_x - R, 0.55f);
					//glVertex2f(x + dist_x  + R, 0.55f);
					//glVertex2f(x + dist_x  + delta_x - R, 0.55f);
					glEnd();
					glDisable(GL_LINE_STIPPLE);
				}
				dist_x = dist_x + delta_x;
			}

			//遍历下部站点集合
			for (int site_index = site_num - 1; site_index >= 0; site_index=site_index-1) {
				//绘制下部站点圆
				glColor3f(0.0f + sites1[site_index]->ifArrived*1.0f, 0.5f - sites1[site_index]->ifArrived*0.5f, 0.5f - sites1[site_index]->ifArrived*0.5f); //设置颜色
				glBegin(GL_POLYGON);//开始画圆
				for (int i = 0; i < 20; ++i)
					glVertex2f(x_end - dist_x1 + 0.025f + R * cos(2 * pi / 20 * i), 0.55f - 0.06f*name_max - 0.08f + R * sin(2 * pi / 20 * i));//圆的坐标
					//glVertex2f(x + dist_x1 + 0.025f + R * cos(2 * pi / 20 * i), 0.55f - 0.06f*name_max - 0.08f + R * sin(2 * pi / 20 * i));//圆的坐标
				glEnd();
				glBegin(GL_POLYGON);//开始画圆
				for (int i = 0; i < 20; ++i)
					glVertex2f(x_end - dist_x1 + 0.025f + r * cos(2 * pi / 20 * i), 0.55f - 0.06f*name_max - 0.08f + r * sin(2 * pi / 20 * i));//圆的坐标
					//glVertex2f(x_end - dist_x1 - 0.025f - r * cos(2 * pi / 20 * i), 0.55f - 0.06f*name_max - 0.08f + r * sin(2 * pi / 20 * i));//圆的坐标
				glEnd();

				//绘制列车到站图标
				if (site_index > 0 && sites1[site_index]->ifArrived && sites1[site_index]->ifIn==false) {
					glColor3f(1.0f, 0.0f, 0.0f); //设置颜色
					glBegin(GL_POLYGON);//开始画圆
					for (int i = 0; i < 20; ++i)
						//glVertex2f(x + dist_x1 + 0.025f + 0.025f*cos(2 * pi / 20 * i), 0.51f - 0.06f*name_max - 0.08f + 0.025f*sin(2 * pi / 20 * i));//圆的坐标
						glVertex2f(x_end - dist_x1 + 0.025f + 0.025f*cos(2 * pi / 20 * i), 0.51f - 0.06f*name_max - 0.08f + 0.025f*sin(2 * pi / 20 * i));//圆的坐标
					glEnd();
					String^str1("");
					//str1 += (sites1[site_index]->arrivedTram_no1);
					str1 += (sites1[site_index]->arrivedTram_strnum);
					//MessageBox::Show(str1);
					char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
					//glRasterPos2f(x + dist_x1 + 0.016f, 0.51f - 0.06f*name_max - 0.08f - 0.025f);
					glRasterPos2f(x_end - dist_x1 + 0.016f, 0.51f - 0.06f*name_max - 0.08f - 0.025f);
					drawCNString(ch);
				}
				else if (site_index > 0 && sites1[site_index]->ifIn && !sites1[site_index-1]->ifArrived && sites1[site_index]->ifArrived == false) 
				{
					//绘制列车站间图标
					glColor3f(1.0f, 0.0f, 0.0f); //设置颜色
					glBegin(GL_POLYGON);//开始画圆
					for (int i = 0; i < 20; ++i)
						glVertex2f(x_end - dist_x1 + 0.025f + 0.025f*cos(2 * pi / 20 * i) - delta_x / 2, 0.51f - 0.06f*name_max - 0.08f + 0.025f*sin(2 * pi / 20 * i));//圆的坐标
					glEnd();
					String^str1("");
					//str1 += (sites1[site_index]->arrivedTram_no1);
					str1 += (sites1[site_index - 1]->arrivingTram_strnum);
					char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
					glRasterPos2f(x_end - dist_x1 + 0.016f - delta_x / 2, 0.51f - 0.06f*name_max - 0.08f - 0.025f);
					drawCNString(ch);
					//MessageBox::Show(trams->Count.ToString());
				}

				if (site_index > 0) {
					glColor3f(0.0f + sites1[site_index]->ifIn*1.0f, 0.5f - sites1[site_index]->ifIn*0.5f, 0.5f - sites1[site_index]->ifIn*0.5f); //设置颜色
					glLineStipple(2, 0x5555);
					glEnable(GL_LINE_STIPPLE);
					//绘制下部虚线
					glBegin(GL_LINES);
					//glVertex2f(x + dist_x1 + 0.025f + R, 0.55f - 0.06f*name_max - 0.08f);
					glVertex2f(x_end - dist_x1 + 0.025f - R, 0.55f - 0.06f*name_max - 0.08f);
					glVertex2f(x_end - dist_x1 + 0.025f - delta_x + R, 0.55f - 0.06f*name_max - 0.08f);
					glEnd();
					glDisable(GL_LINE_STIPPLE);
				}
				dist_x1 = dist_x1 + delta_x;
			}
		}

		//绘制电车
		System::Void drawTram(int tram_index) {
			//列车运行未完成绘制列车
			if (!trams[tram_index]->finish) {
				//绘制有轨电车
				glLineWidth(3.0f);//
				glBegin(GL_POLYGON);
				glColor3f(1.0f, 0.3f, 0.6f);
				glVertex3f(trams[tram_index]->p1->_x, trams[tram_index]->p1->_y, trams[tram_index]->p1->_z);
				glVertex3f(trams[tram_index]->p2->_x, trams[tram_index]->p2->_y, trams[tram_index]->p2->_z);
				glVertex3f(trams[tram_index]->p3->_x, trams[tram_index]->p3->_y, trams[tram_index]->p3->_z);
				glVertex3f(trams[tram_index]->p4->_x, trams[tram_index]->p4->_y, trams[tram_index]->p4->_z);
				glEnd();
				glLineWidth(1.0f);//
				glBegin(GL_LINES);
				glVertex2f(trams[tram_index]->p5->_x, trams[tram_index]->p5->_y);
				glVertex2f(trams[tram_index]->p6->_x, trams[tram_index]->p6->_y);
				glEnd();
				String^str1("");
				str1 += trams[tram_index]->tram_num;//显示列车编号
				char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
				if (trams[tram_index]->positive_run) {
					glRasterPos2f(trams[tram_index]->p5->_x, trams[tram_index]->p1->_y + 0.01f);//设置字符位置
				}
				else {
					glRasterPos2f(trams[tram_index]->p5->_x, trams[tram_index]->p1->_y - 0.022f);
				}
				drawCNString(ch);
			}
		}

		//绘制红绿灯
		System::Void drawTrafficLight()
		{
			for (int i = 0; i < trlights->Count; i++)
			{
				int lightindex = i;
				//灯柱
				glColor3f(0.0f,0.0f,0.0f);
				glBegin(GL_LINES);
				glVertex2f(trlights[lightindex]->point->_x, trlights[lightindex]->point->_y);
				glVertex2f(trlights[lightindex]->point->_x, trlights[lightindex]->point->_y - trlights[lightindex]->hight1);
				glEnd();
				//灯框
				glBegin(GL_POLYGON);
				glVertex3f(trlights[lightindex]->point->_x - trlights[lightindex]->width1, trlights[lightindex]->point->_y - trlights[lightindex]->hight1, trlights[lightindex]->point->_z);
				glVertex3f(trlights[lightindex]->point->_x + trlights[lightindex]->width1, trlights[lightindex]->point->_y - trlights[lightindex]->hight1, trlights[lightindex]->point->_z);
				glVertex3f(trlights[lightindex]->point->_x + trlights[lightindex]->width1, trlights[lightindex]->point->_y - trlights[lightindex]->hight1 - trlights[lightindex]->hight2, trlights[lightindex]->point->_z);
				glVertex3f(trlights[lightindex]->point->_x - trlights[lightindex]->width1, trlights[lightindex]->point->_y - trlights[lightindex]->hight1 - trlights[lightindex]->hight2, trlights[lightindex]->point->_z);
				glEnd();
				//灯
				GLfloat lig_r = 0.018f;//灯半径
				glBegin(GL_POLYGON);//开始画圆
				glColor3f(0.0f, 1.0f, 0.0f); //绿灯
				for (int i = 0; i < 20; ++i)
					glVertex2f(trlights[lightindex]->point->_x - 0.02f + lig_r * cos(2 * pi / 20 * i), trlights[lightindex]->point->_y - trlights[lightindex]->hight1 - 0.02f + lig_r * sin(2 * pi / 20 * i));//绿灯
				glEnd();
				glBegin(GL_POLYGON);//开始画圆
				glColor3f(1.0f, 0.0f, 0.0f);//红灯
				for (int i = 0; i < 20; ++i)
					glVertex2f(trlights[lightindex]->point->_x + 0.02f + lig_r * cos(2 * pi / 20 * i), trlights[lightindex]->point->_y - trlights[lightindex]->hight1 - 0.02f + lig_r * sin(2 * pi / 20 * i));//绿灯
				glEnd();

				int draw_n = 4000;
				if (trlights[lightindex]->greenf)//绿灯
				{
					
					glBegin(GL_POLYGON);//开始画圆
					glColor3f(0.0f, 1.0f, 0.0f); //绿色
					for (int i = 0; i < draw_n; ++i)
						glVertex2f(trlights[lightindex]->point->_x - 0.02f + lig_r * cos(2 * pi / draw_n * i), trlights[lightindex]->point->_y - trlights[lightindex]->hight1 - 0.02f + lig_r * sin(2 * pi / draw_n * i));//绿灯
					glEnd();
					trlights[lightindex]->redf = false;//确保不会同时为true
				}
				else if(trlights[lightindex]->redf)
				{
					
					glBegin(GL_POLYGON);//开始画圆
					glColor3f(1.0f, 0.0f, 0.0f);//红灯
					for (int i = 0; i < draw_n; ++i)
						glVertex2f(trlights[lightindex]->point->_x + 0.02f + lig_r * cos(2 * pi / draw_n * i), trlights[lightindex]->point->_y - trlights[lightindex]->hight1 - 0.02f + lig_r * sin(2 * pi / draw_n * i));//绿灯
					glEnd();
					trlights[lightindex]->greenf = false;//确保不会同时为true
				}
			}

		}

		//添加列车并初始化列车的位置以及起始点的位置
		GLvoid initTram(bool positive_run, String^tram_num, String^pronum)
		{
			float tmp;//轨道中心纵坐标

			//total_step = 0;
			//初始化列车位置
			if (positive_run) {
				//正向
				tmp = -0.005f;
				tram = gcnew Tram(
					gcnew Point(-orbit_len - tram_width, tmp + tram_to_path + tram_height),
					gcnew Point(-orbit_len + tram_width, tmp + tram_to_path + tram_height),
					gcnew Point(-orbit_len + tram_width, tmp + tram_to_path),
					gcnew Point(-orbit_len - tram_width, tmp + tram_to_path),
					gcnew Point(-orbit_len, tmp + tram_to_path),
					gcnew Point(-orbit_len, tmp - tram_to_path)
				);
				tram->positive_run = true;//初始化运行方向
				//xingye
				tram->pronum = pronum;//初始化方案编号
				tram->tram_no = tram_no;//初始化索引，需要更新
				tram_no++;
				tram->tram_num = tram_num;//初始化电车编号

				String^selectsql = "SELECT 载客容量 FROM 列车信息 WHERE 列车编号='" + tram_num + "';";
				DataTable^peop_load = ExecuteQuery(selectsql);
				tram->capacity = int::Parse(peop_load->Rows[0]->ItemArray[0]->ToString()->Trim());//初始化电车载客容量

				selectsql = "SELECT 站点停留时间,站间运行时间,站点编号 FROM 列车站间运行信息 WHERE 列车编号='" + tram->tram_num + "' AND " +
					"线路编号='" + System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)line_num) + "' ORDER BY 站点编号;";
				DataTable^tram_run_infotb = ExecuteQuery(selectsql);
				for (int i = 0; i < tram_run_infotb->Rows->Count; i++)
				{
					Site^tmpsite = gcnew Site();
					tmpsite->site_no = tram_run_infotb->Rows[i]->ItemArray[2]->ToString();//站点编号
					tmpsite->stayTime = int::Parse(tram_run_infotb->Rows[i]->ItemArray[0]->ToString()->Trim());//站点停留时间
					tmpsite->run_time = int::Parse(tram_run_infotb->Rows[i]->ItemArray[1]->ToString()->Trim());//站点运行时间
					tram->tram_siteinfo->Add(tmpsite);//初始化电车在各站点的信息及站间运行情况
				}

				selectsql = "SELECT MIN(cast(数据序号 as int)),MAX(cast(数据序号 as int)),MAX(cast(位置 as float)),MIN(cast(时间 as datetime)) FROM trainTable WHERE 方案编号='" + pronum + "' AND 列车编号='" +
					tram_num + "';";
				DataTable^restable = ExecuteQuery1(selectsql);
				try {
					tram->oridatanum = int::Parse(restable->Rows[0]->ItemArray[0]->ToString()->Trim());//最小数据序号
					tram->datanum = int::Parse(restable->Rows[0]->ItemArray[0]->ToString()->Trim());//最小数据序号
					tram->maxdatanum = int::Parse(restable->Rows[0]->ItemArray[1]->ToString()->Trim());//最大数据序号
					tram->last_pos = float::Parse(restable->Rows[0]->ItemArray[2]->ToString()->Trim());//最终位置
					tram->timeflow = restable->Rows[0]->ItemArray[3]->ToString();

					tram->total_step = 0;//初始化列车运行总步长

					tram->draw = true;//将绘制指令调为true
					trams->Add(tram);
				}
				catch (Exception ^ e) {
					return;
				}
			}
			else {
				//反向
				tmp = -0.105f;
				tram = gcnew Tram(
					gcnew Point(orbit_len + tram_width, tmp - tram_to_path - tram_height),
					gcnew Point(orbit_len - tram_width, tmp - tram_to_path - tram_height),
					gcnew Point(orbit_len - tram_width, tmp - tram_to_path),
					gcnew Point(orbit_len + tram_width, tmp - tram_to_path),
					gcnew Point(orbit_len, tmp + tram_to_path),
					gcnew Point(orbit_len, tmp - tram_to_path)
				);
				tram->positive_run = false;
				tram->pronum = pronum;//初始化方案编号
				tram->tram_no = tram_no;//初始化索引，需要更新
				tram_no++;
				tram->tram_num = tram_num;//初始化电车编号

				String^selectsql = "SELECT 载客容量 FROM 列车信息 WHERE 列车编号='" + tram_num + "';";
				DataTable^peop_load = ExecuteQuery(selectsql);
				tram->capacity = int::Parse(peop_load->Rows[0]->ItemArray[0]->ToString()->Trim());//初始化电车载客容量

				selectsql = "SELECT 站点停留时间,站间运行时间,站点编号 FROM 列车站间运行信息 WHERE 列车编号='" + tram->tram_num + "' AND " +
					"线路编号='" + System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)line_num) + "' ORDER BY 站点编号;";
				DataTable^tram_run_infotb = ExecuteQuery(selectsql);
				for (int i = 0; i < tram_run_infotb->Rows->Count; i++)
				{
					Site^tmpsite = gcnew Site();
					tmpsite->site_no = tram_run_infotb->Rows[i]->ItemArray[2]->ToString();//站点编号
					tmpsite->stayTime = int::Parse(tram_run_infotb->Rows[i]->ItemArray[0]->ToString()->Trim());//站点停留时间
					tmpsite->run_time = int::Parse(tram_run_infotb->Rows[i]->ItemArray[1]->ToString()->Trim());//站点运行时间
					tram->tram_siteinfo->Add(tmpsite);//初始化电车站间运行情况
				}

				selectsql = "SELECT MIN(cast(数据序号 as int)),MAX(cast(数据序号 as int)),MAX(cast(位置 as int)),MIN(cast(时间 as datetime)) FROM trainTable WHERE 方案编号='" + pronum + "' AND 列车编号='" +
					tram_num + "';";
				DataTable^restable = ExecuteQuery1(selectsql);
				tram->oridatanum = int::Parse(restable->Rows[0]->ItemArray[0]->ToString()->Trim());//最小数据序号
				tram->datanum = int::Parse(restable->Rows[0]->ItemArray[0]->ToString()->Trim());//最小数据序号
				tram->maxdatanum = int::Parse(restable->Rows[0]->ItemArray[1]->ToString()->Trim());//最大数据序号
				tram->last_pos = float::Parse(restable->Rows[0]->ItemArray[2]->ToString()->Trim());//最终位置
				tram->timeflow = restable->Rows[0]->ItemArray[3]->ToString();

				tram->total_step = 0;//初始化列车运行总步长

				tram->draw = true;//将绘制指令调为true
				trams->Add(tram);
			}

		}

		//添加列车并初始化列车的位置以及起始点的位置--实时模式
		GLvoid SysMode_initTram(bool positive_run, String^tram_num, String^pronum)
		{
			trams->Clear();//确保实时模式下每次只有一辆车运行
			float tmp;//轨道中心纵坐标

			//total_step = 0;
			//初始化列车位置
			if (positive_run) {
				//正向
				tmp = -0.005f;
				tram = gcnew Tram(
					gcnew Point(-orbit_len - tram_width, tmp + tram_to_path + tram_height),
					gcnew Point(-orbit_len + tram_width, tmp + tram_to_path + tram_height),
					gcnew Point(-orbit_len + tram_width, tmp + tram_to_path),
					gcnew Point(-orbit_len - tram_width, tmp + tram_to_path),
					gcnew Point(-orbit_len, tmp + tram_to_path),
					gcnew Point(-orbit_len, tmp - tram_to_path)
				);
				tram->positive_run = true;//初始化运行方向
				//xingye
				tram->pronum = pronum;//初始化方案编号
				tram->tram_no = tram_no;//初始化索引，需要更新
				tram_no++;
				tram->tram_num = tram_num;//初始化电车编号

				String^selectsql = "SELECT 载客容量 FROM 列车信息 WHERE 列车编号='" + tram_num + "';";
				DataTable^peop_load = ExecuteQuery(selectsql);
				tram->capacity = int::Parse(peop_load->Rows[0]->ItemArray[0]->ToString()->Trim());//初始化电车载客容量

				selectsql = "SELECT 站点停留时间,站间运行时间,站点编号 FROM 列车站间运行信息 WHERE 列车编号='" + tram->tram_num + "' AND " +
					"线路编号='" + System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)line_num) + "' ORDER BY 站点编号;";
				DataTable^tram_run_infotb = ExecuteQuery(selectsql);
				for (int i = 0; i < tram_run_infotb->Rows->Count; i++)
				{
					Site^tmpsite = gcnew Site();
					tmpsite->site_no = tram_run_infotb->Rows[i]->ItemArray[2]->ToString();//站点编号
					tmpsite->stayTime = int::Parse(tram_run_infotb->Rows[i]->ItemArray[0]->ToString()->Trim());//站点停留时间
					tmpsite->run_time = int::Parse(tram_run_infotb->Rows[i]->ItemArray[1]->ToString()->Trim());//站点运行时间
					tram->tram_siteinfo->Add(tmpsite);//初始化电车站间运行情况
				}
				tram->total_step = 0;//初始化列车运行总步长

				tram->draw = true;//将绘制指令调为true
				trams->Add(tram);
			}
			else {
				//反向
				tmp = -0.105f;
				tram = gcnew Tram(
					gcnew Point(orbit_len + tram_width, tmp - tram_to_path - tram_height),
					gcnew Point(orbit_len - tram_width, tmp - tram_to_path - tram_height),
					gcnew Point(orbit_len - tram_width, tmp - tram_to_path),
					gcnew Point(orbit_len + tram_width, tmp - tram_to_path),
					gcnew Point(orbit_len, tmp + tram_to_path),
					gcnew Point(orbit_len, tmp - tram_to_path)
				);
				tram->positive_run = false;
				tram->pronum = pronum;//初始化方案编号
				tram->tram_no = tram_no;//初始化索引，需要更新
				tram_no++;
				tram->tram_num = tram_num;//初始化电车编号

				String^selectsql = "SELECT 载客容量 FROM 列车信息 WHERE 列车编号='" + tram_num + "';";
				DataTable^peop_load = ExecuteQuery(selectsql);
				tram->capacity = int::Parse(peop_load->Rows[0]->ItemArray[0]->ToString()->Trim());//初始化电车载客容量

				selectsql = "SELECT 站点停留时间,站间运行时间,站点编号 FROM 列车站间运行信息 WHERE 列车编号='" + tram->tram_num + "' AND " +
					"线路编号='" + System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)line_num) + "' ORDER BY 站点编号;";
				DataTable^tram_run_infotb = ExecuteQuery(selectsql);
				for (int i = 0; i < tram_run_infotb->Rows->Count; i++)
				{
					Site^tmpsite = gcnew Site();
					tmpsite->site_no = tram_run_infotb->Rows[i]->ItemArray[2]->ToString();//站点编号
					tmpsite->stayTime = int::Parse(tram_run_infotb->Rows[i]->ItemArray[0]->ToString()->Trim());//站点停留时间
					tmpsite->run_time = int::Parse(tram_run_infotb->Rows[i]->ItemArray[1]->ToString()->Trim());//站点运行时间
					tram->tram_siteinfo->Add(tmpsite);//初始化电车站间运行情况
				}
				tram->total_step = 0;//初始化列车运行总步长

				tram->draw = true;//将绘制指令调为true
				trams->Add(tram);
			}

		}

		//列车运行函数
		System::Void running(Tram^tram,int tram_index) {
			//float step_t = tram->v;
			//total_step += step_t;
			float step_t = step;
			tram->total_step += step_t;
			if (tram->positive_run) {
				tram->p1->_x += step_t;
				tram->p2->_x += step_t;
				tram->p3->_x += step_t;
				tram->p4->_x += step_t;
				tram->p5->_x += step_t;
				tram->p6->_x += step_t;
			}
			else {
				tram->p1->_x -= step_t;
				tram->p2->_x -= step_t;
				tram->p3->_x -= step_t;
				tram->p4->_x -= step_t;
				tram->p5->_x -= step_t;
				tram->p6->_x -= step_t;
			}
			//MessageBox::Show("step="+step_t.ToString()+" pos"+tram->p1->_x.ToString());
			//xingye增加finish判断条件

			//
			trams[tram_index] = tram;//更新电车在数组中的数据
		}

		//修改步长
		System::Void UpdateStep(Tram^tram, int tram_index) {
			if (tram->positive_run) {
				tram->p1->_x += tram->cal_step;
				tram->p2->_x += tram->cal_step;
				tram->p3->_x += tram->cal_step;
				tram->p4->_x += tram->cal_step;
				tram->p5->_x += tram->cal_step;
				tram->p6->_x += tram->cal_step;
			}
			else {
				tram->p1->_x -= tram->cal_step;
				tram->p2->_x -= tram->cal_step;
				tram->p3->_x -= tram->cal_step;
				tram->p4->_x -= tram->cal_step;
				tram->p5->_x -= tram->cal_step;
				tram->p6->_x -= tram->cal_step;
			}
			//
			trams[tram_index] = tram;//更新电车在数组中的数据
		}

		//即放即行模式下电车运行函数
		System::Void Runimm(Tram^tram, int tram_index)
		{
			String^selectsql;
			if (!tram->finish && tram->draw == true && tram->positive_run == true && tram->datanum <= tram->maxdatanum)//正向
			{
				//判断方向是否改变，若改变方向则改变位置
				int d_num = tram->maxdatanum - tram->oridatanum + 1;
				if (tram->datanum >= (Math::Round(d_num/2)+tram->oridatanum-3) && (tram->hasPassed==sites->Count-1))
				{
					//取上一时刻的行驶方向
					selectsql = "SELECT 行驶方向 FROM trainTable WHERE 方案编号='"+tram->pronum+"' AND 列车编号='"+tram->tram_num+"' AND 数据序号='"+(tram->datanum-1)+"';";
					restable = ExecuteQuery1(selectsql);
					String^predir = restable->Rows[0]->ItemArray[0]->ToString()->Trim();
					//取当前时刻的行驶方向
					selectsql = "SELECT 行驶方向 FROM trainTable WHERE 方案编号='" + tram->pronum + "' AND 列车编号='" + tram->tram_num + "' AND 数据序号='" + (tram->datanum) + "';";
					restable = ExecuteQuery1(selectsql);
					String^nowdir = restable->Rows[0]->ItemArray[0]->ToString()->Trim();
					//如果当前时刻的行驶方向不同于上一时刻行驶方向，即方向改变
					if (!String::Equals(predir, nowdir))
					{
						//tram->ResetPoint(tram->positive_run,orbit_len,tram_width,tram_to_path,tram_height,-0.005f);
						tram->ResetPoint(false, orbit_len, tram_width, tram_to_path, tram_height, -0.105f);
						tram->cal_step = 0;//没取到数据将步长置零
						tram->hasPassed = 0;
						//trams[tram_index] = tram;
						//return;
					}
				}

				selectsql = "SELECT 行驶方向,速度,加速度,电流,电压,cast(位置 as decimal(9,2)),cast(时间 as datetime) FROM trainTable WHERE 方案编号='" +
					tram->pronum + "' AND 列车编号='" + tram->tram_num + "' AND 数据序号='" + tram->datanum + "';";
				restable = ExecuteQuery1(selectsql);
				DateTime timeflow_time = Convert::ToDateTime(tram->timeflow);
				DateTime datatime1 = Convert::ToDateTime(restable->Rows[0]->ItemArray[6]->ToString()->Trim());
				//判断独立时间线是否到达当前数据所在的时间点
				int timespan = DateTime::Compare(timeflow_time, datatime1);
				//如果到达
				if (timespan == 0)
				{
					//更新行车方向、速度、加速度、电流电压、位置、时间、数据序号
					if (String::Equals(restable->Rows[0]->ItemArray[0]->ToString()->Trim(), "正向"))
					{
						tram->positive_run = true;
					}
					else
					{
						tram->positive_run = false;
					}
					tram->velocity = float::Parse(restable->Rows[0]->ItemArray[1]->ToString()->Trim());
					tram->accelerate = float::Parse(restable->Rows[0]->ItemArray[2]->ToString()->Trim());
					tram->current = float::Parse(restable->Rows[0]->ItemArray[3]->ToString()->Trim());
					tram->voltage = float::Parse(restable->Rows[0]->ItemArray[4]->ToString()->Trim());
					tram->prepos = tram->pos;
					tram->pos = float::Parse(restable->Rows[0]->ItemArray[5]->ToString()->Trim());
					//tram1->datatime = restable->Rows[0]->ItemArray[6]->ToString();
					if (tram->datanum >= tram->maxdatanum)
					{
						tram->finish = true;
					}

					//更新数据序号
					tram->datanum = tram->datanum + 1;
					//设置绘制指令:如果电车完成整趟车程
					tram->draw = true;
					//判断是否到站,及是否到达终点站
					//tram->ArriveIn();
					//离站动作
					//tram->Moveaway();
					//更新时间流
					tram->timeflow = (timeflow_time.AddSeconds(+1)).ToString();

					//Checked(tram1);

					//计算步长
					if (tram->positive_run)
					{
						tram->PosTransform(scale);
					}

					trams[tram_index] = tram;
				}
				else if (timespan < 0)//时间线没有到达数据当前时间
				{
					tram->timeflow = (timeflow_time.AddSeconds(+1)).ToString();
					tram->cal_step = 0;//没取到数据将步长置零
					trams[tram_index] = tram;
				}
			}
			else if (!tram->finish && tram->draw == true && tram->positive_run == false && tram->datanum <= tram->maxdatanum)//反向
			{
				//判断方向是否改变，若改变方向则改变位置
				int d_num = tram->maxdatanum - tram->oridatanum + 1;
				if ((tram->datanum >= (Math::Round(d_num / 2) + tram->oridatanum - 3)) && tram->hasPassed==(sites1->Count-1))
				{
					selectsql = "SELECT 行驶方向 FROM trainTable WHERE 方案编号='" + tram->pronum + "' AND 列车编号='" + tram->tram_num + "' AND 数据序号='" + (tram->datanum - 1) + "';";
					restable = ExecuteQuery1(selectsql);
					String^predir = restable->Rows[0]->ItemArray[0]->ToString()->Trim();
					selectsql = "SELECT 行驶方向 FROM trainTable WHERE 方案编号='" + tram->pronum + "' AND 列车编号='" + tram->tram_num + "' AND 数据序号='" + (tram->datanum) + "';";
					restable = ExecuteQuery1(selectsql);
					String^nowdir = restable->Rows[0]->ItemArray[0]->ToString()->Trim();
					if (!String::Equals(predir, nowdir))
					{
						//tram->ResetPoint(tram->positive_run, orbit_len, tram_width, tram_to_path, tram_height, -0.105f);
						tram->ResetPoint(true, orbit_len, tram_width, tram_to_path, tram_height, -0.005f);
						tram->cal_step = 0;//没取到数据将步长置零
						tram->hasPassed = 0;
						//trams[tram_index] = tram;
						//return;
					}
				}

				selectsql = "SELECT 行驶方向,速度,加速度,电流,电压,cast(位置 as decimal(9,2)),cast(时间 as datetime) FROM trainTable WHERE 方案编号='" +
					tram->pronum + "' AND 列车编号='" + tram->tram_num + "' AND 数据序号='" + tram->datanum + "';";
				restable = ExecuteQuery1(selectsql);
				DateTime timeflow_time = Convert::ToDateTime(tram->timeflow);
				DateTime datatime1 = Convert::ToDateTime(restable->Rows[0]->ItemArray[6]->ToString()->Trim());
				//MessageBox::Show(restable->Rows[0]->ItemArray[6]->ToString()->Trim());
				int timespan = DateTime::Compare(timeflow_time, datatime1);
				if (timespan == 0)
				{
					//更新行车方向、速度、加速度、电流电压、位置、时间、数据序号
					if (String::Equals(restable->Rows[0]->ItemArray[0]->ToString()->Trim(), "正向"))
					{
						tram->positive_run = true;
					}
					else
					{
						tram->positive_run = false;
					}
					tram->velocity = float::Parse(restable->Rows[0]->ItemArray[1]->ToString()->Trim());
					tram->accelerate = float::Parse(restable->Rows[0]->ItemArray[2]->ToString()->Trim());
					tram->current = float::Parse(restable->Rows[0]->ItemArray[3]->ToString()->Trim());
					tram->voltage = float::Parse(restable->Rows[0]->ItemArray[4]->ToString()->Trim());
					tram->prepos = tram->pos;
					tram->pos = float::Parse(restable->Rows[0]->ItemArray[5]->ToString()->Trim());
					//tram1->datatime = restable->Rows[0]->ItemArray[6]->ToString();
					if (tram->datanum >= tram->maxdatanum)
					{
						tram->finish = true;
					}
					//更新数据序号
					tram->datanum = tram->datanum + 1;
					//设置绘制指令:如果电车完成整趟车程
					tram->draw = true;
					//判断是否到站,及是否到达终点站
					//tram->ArriveIn();
					//离站动作
					//tram->Moveaway();
					//更新时间流
					tram->timeflow = (timeflow_time.AddSeconds(+1)).ToString();

					//Checked(tram1);

					//计算步长
					if (tram->positive_run == false)
					{
						tram->PosTransform(scale);
					}

					trams[tram_index] = tram;
				}
				else if (timespan < 0)
				{
					tram->timeflow = (timeflow_time.AddSeconds(+1)).ToString();
					tram->cal_step = 0;//没取到数据将步长置零
					trams[tram_index] = tram;
				}
			}
			UpdateStep(tram, tram_index);
		}
		//同步运行模式下电车运行函数
		System::Void RunSys(Tram^tram, int tram_index)
		{	
			String^selectsql;
			if (!tram->finish && tram->draw == true && tram->positive_run == true && tram->datanum <= tram->maxdatanum)//正向
			{
				selectsql = "SELECT MAX(数据序号) FROM trainTable WHERE 方案编号='" + tram->pronum + "' AND 列车编号='" + tram->tram_num + "';";
				restable = ExecuteQuery1(selectsql);
				tram->maxdatanum = int::Parse(restable->Rows[0]->ItemArray[0]->ToString());//更新数据序号
				selectsql = "SELECT 行驶方向,速度,加速度,电流,电压,cast(位置 as decimal(9,2)) FROM trainTable WHERE 方案编号='" +
					tram->pronum + "' AND 列车编号='" + tram->tram_num + "' AND 数据序号='" + restable->Rows[0]->ItemArray[0]->ToString() + "';";
				restable = ExecuteQuery1(selectsql);
				if (restable->Rows->Count <= 0)//实时显示中需要一直查询，如果有数据，代表下位机开始传输
					return;

				//判断是否改变方向
				if (String::Equals(restable->Rows[0]->ItemArray[0]->ToString()->Trim(), "反向"))//如果改变行驶方向
				{
					tram->ResetPoint(false, orbit_len, tram_width, tram_to_path, tram_height, -0.105f);
					tram->cal_step = 0;//没取到数据将步长置零
					tram->hasPassed = 0;
				}
				//如果没有改变反向，照常更新电车数据
				//更新行车方向、速度、加速度、电流电压、位置、时间
				if (String::Equals(restable->Rows[0]->ItemArray[0]->ToString()->Trim(), "正向"))
				{
					tram->positive_run = true;
				}
				else
				{
					tram->positive_run = false;
				}
				tram->velocity = float::Parse(restable->Rows[0]->ItemArray[1]->ToString()->Trim());
				tram->accelerate = float::Parse(restable->Rows[0]->ItemArray[2]->ToString()->Trim());
				tram->current = float::Parse(restable->Rows[0]->ItemArray[3]->ToString()->Trim());
				tram->voltage = float::Parse(restable->Rows[0]->ItemArray[4]->ToString()->Trim());
				tram->prepos = tram->pos;
				tram->pos = float::Parse(restable->Rows[0]->ItemArray[5]->ToString()->Trim());

				//设置绘制指令:如果电车完成整趟车程
				tram->draw = true;

				//计算步长
				if (tram->positive_run)
				{
					tram->PosTransform(scale);
				}

				//Checked(tram);

				trams[0] = tram;
			}
			else if (!tram->finish && tram->draw == true && tram->positive_run == false && tram->datanum <= tram->maxdatanum)//反向
			{
				selectsql = "SELECT MAX(数据序号) FROM trainTable WHERE 方案编号='" + tram->pronum + "' AND 列车编号='" + tram->tram_num + "';";
				restable = ExecuteQuery1(selectsql);
				tram->maxdatanum = int::Parse(restable->Rows[0]->ItemArray[0]->ToString());//更新数据序号
				selectsql = "SELECT 行驶方向,速度,加速度,电流,电压,cast(位置 as decimal(9,2)) FROM trainTable WHERE 方案编号='" +
					tram->pronum + "' AND 列车编号='" + tram->tram_num + "' AND 数据序号='" + restable->Rows[0]->ItemArray[0]->ToString() + "';";
				restable = ExecuteQuery1(selectsql);
				if (restable->Rows->Count <= 0)//实时显示中需要一直查询，如果有数据，代表下位机开始传输
					return;

				//判断是否改变方向
				if (String::Equals(restable->Rows[0]->ItemArray[0]->ToString()->Trim(), "正向"))//如果改变行驶方向
				{
					tram->ResetPoint(false, orbit_len, tram_width, tram_to_path, tram_height, -0.105f);
					tram->cal_step = 0;//没取到数据将步长置零
					tram->hasPassed = 0;
				}
				//如果没有改变反向，照常更新电车数据
				//更新行车方向、速度、加速度、电流电压、位置、时间、数据序号
				if (String::Equals(restable->Rows[0]->ItemArray[0]->ToString()->Trim(), "正向"))
				{
					tram->positive_run = true;
				}
				else
				{
					tram->positive_run = false;
				}
				tram->velocity = float::Parse(restable->Rows[0]->ItemArray[1]->ToString()->Trim());
				tram->accelerate = float::Parse(restable->Rows[0]->ItemArray[2]->ToString()->Trim());
				tram->current = float::Parse(restable->Rows[0]->ItemArray[3]->ToString()->Trim());
				tram->voltage = float::Parse(restable->Rows[0]->ItemArray[4]->ToString()->Trim());
				tram->prepos = tram->pos;
				tram->pos = float::Parse(restable->Rows[0]->ItemArray[5]->ToString()->Trim());

				//设置绘制指令:如果电车完成整趟车程
				tram->draw = true;

				if (!tram->positive_run)
				{
					tram->PosTransform(scale);
				}
				//Checked(tram);
				trams[0] = tram;
			}
			UpdateStep(tram, tram_index);
		}

		//绘制文字显示
#define MAX_CHAR  128
		void drawCNString(const char* str) {
			int len;
			wchar_t* wstring;
			HDC hDC = wglGetCurrentDC();
			GLuint list = glGenLists(1);

			// 计算字符的个数
			len = 0;
			for (int i = 0; str[i] != '\0'; ++i)
			{
				// 如果是双字节字符的（比如中文字符），两个字节才算一个字符
				// 否则一个字节算一个字符
				if (IsDBCSLeadByte(str[i]))
					++i;
				++len;
			}

			// 将混合字符转化为宽字符
			wstring = (wchar_t*)malloc((len + 1) * sizeof(wchar_t));
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str, -1, wstring, len);
			wstring[len] = L'\0';

			// 逐个输出字符
			for (int i = 0; i < len; ++i)
			{
				wglUseFontBitmapsW(hDC, wstring[i], 1, list);
				glCallList(list);
			}

			// 回收所有临时资源
			free(wstring);
			glDeleteLists(list, 1);
		}





	protected:
		//析构函数，释放对象
		~StraightLinePaint(System::Void)
		{
			this->DestroyHandle();//销毁窗口
		}

		//本窗口的色素格式设置
		GLint mySetPixelFormat(HDC hdc)
		{
			static	PIXELFORMATDESCRIPTOR pfd =				// pfd告诉Windows我们想要什么样的东西
			{
				sizeof(PIXELFORMATDESCRIPTOR),				// 该像素格式描述符的大小
				1,											// 版本号
				PFD_DRAW_TO_WINDOW |						// 格式必须支持窗口
				PFD_SUPPORT_OPENGL
				//格式必须支持OpenGL
				| PFD_DOUBLEBUFFER,							// 格式必须支持双缓冲
				PFD_TYPE_RGBA,								// 请求RGBA格式
				16,										// 选择我们的颜色深度
				0, 0, 0, 0, 0, 0,							// 颜色位被忽略
				0,											// No Alpha Buffer
				0,											// Shift Bit Ignored
				0,											// No Accumulation Buffer
				0, 0, 0, 0,									// Accumulation Bits Ignored
				0,//16											// 16Bit Z-Buffer (Depth Buffer)  
				0,											// No Stencil Buffer
				0,											// No Auxiliary Buffer
				PFD_MAIN_PLANE,								// 主图层 Main Drawing Layer
				0,											// Reserved
				0, 0, 0										// Layer Masks Ignored
			};

			GLint  iPixelFormat;

			// get the device context's best, available pixel format match 
			if ((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}

			// make that match the device context's current pixel format 
			if (SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}

			if ((m_hglrc = wglCreateContext(m_hDC)) == NULL)
			{
				MessageBox::Show("wglCreateContext Failed");
				return 0;
			}

			if ((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return 0;
			}


			return 1;
		}

		//调整GL窗口的大小并初始化
		GLvoid reSizeGLScene(GLsizei width, GLsizei height)
		{
			if (height == 0)										// Prevent A Divide By Zero By
			{
				height = 1;										// Making Height Equal One
			}

			glViewport(-20, 0, width / 1.1, height / 1.1);						// Reset The Current Viewport

			glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
			glLoadIdentity();									// Reset The Projection Matrix

			//Calculate The Aspect Ratio Of The Window
			gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

			glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
			glLoadIdentity();									// Reset The Modelview Matrix
		}

		//初始化OpenGL界面
		bool initGL()										// All setup for opengl goes here
		{
			glShadeModel(GL_SMOOTH);							// Enable smooth shading
			glClearColor(1.0f, 1.0f, 1.0f, 0.5f);				// 	 背景色
			glClearDepth(1.0f);									// 深度缓冲设置
			(GL_DEPTH_TEST);							// 启用深度测试
			glDepthFunc(GL_LEQUAL);								// 深度测试的类型
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// 很好的透视计算

			/*
			DataTable^  table = gcnew DataTable;
			String^sql1 = "SELECT [线路编号] ,[列车编号] FROM [project_info] WHERE 方案编号 ='" + project_num + "' ";
			table = ExecuteQuery(sql1);

			for (int i = 0; i < table->Rows->Count; i++)
			{
				fangMes->Clear();
				for (int j = 0; j < table->Columns->Count; j++)
				{
					fangMes->Add(table->Rows[i]->ItemArray[j]);
				}

				//获取线路编号
				String ^tmp = fangMes[0]->ToString()->Trim();
				line_num = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				//获取列车编号
				tmp = fangMes[1]->ToString()->Trim();
				tram_num = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
			}
			*/

			return TRUE;										// Initialisation went ok
		}
		//自定义查询数据库函数
		//列车数据库
		System::Data::DataTable^ ExecuteQuery(String ^sqlStr)
		{
			SqlConnection^con = gcnew SqlConnection();
			//con->ConnectionString = "Data Source=DESKTOP-5TU40C0;Initial Catalog=列车数据库;Integrated Security=True";
			con->ConnectionString = "Data Source=localhost;Initial Catalog=列车数据库;Integrated Security=True";
			SqlDataAdapter^da = gcnew SqlDataAdapter(sqlStr, con);
			con->Open();
			DataTable^result_dt = gcnew DataTable();
			da->Fill(result_dt);
			con->Close();
			return result_dt;
		}
		//RunDB2数据库
		System::Data::DataTable^ ExecuteQuery1(String ^sqlStr)
		{
			SqlConnection^con = gcnew SqlConnection();
			//con->ConnectionString = "Data Source=DESKTOP-5TU40C0;Initial Catalog=列车数据库;Integrated Security=True";
			con->ConnectionString = "Data Source=localhost;Initial Catalog=RunDB2;Integrated Security=True";
			SqlDataAdapter^da = gcnew SqlDataAdapter(sqlStr, con);
			con->Open();
			DataTable^result_dt = gcnew DataTable();
			da->Fill(result_dt);
			con->Close();
			return result_dt;
		}
		/*
		System::Data::DataTable^ ExecuteQuery(String ^sqlStr)
		{
			String ^ Conn = String::Format("Provider=Microsoft.ACE.OLEDB.12.0; Data Source={0}\\data.accdb", Application::StartupPath);
			OleDbConnection^con1 = gcnew OleDbConnection(Conn);
			OleDbDataAdapter^ oda;
			con1->Open();
			oda = gcnew OleDbDataAdapter(sqlStr, Conn);
			DataTable^ dt = gcnew DataTable;
			oda->Fill(dt);
			con1->Close();
			return dt;
		}*/
		//调试函数
		void Checked(Tram^tram1)
		{
			String^str1 = "1." + tram1->tram_num +
				"\n2.index:" + tram1->tram_no.ToString() +
				"\n3.datanum:" + tram1->datanum.ToString() +
				"\n4.pos:" + tram1->pos.ToString() +
				"\n5.prepos:"+tram1->prepos.ToString()+
				"\n6.cal_step:"+tram1->cal_step.ToString()+
				"\n5.velocity:" + tram1->velocity.ToString() +
				"\n6.timeflow:" + tram1->timeflow +
				"\n7.maxpos:" + tram1->last_pos.ToString() +
				"\n8.settime:" + tram1->settime +
				"\n9.predraw:" + tram1->finish.ToString() +
				"\n10.draw:" + tram1->draw.ToString() +
				"\n11.maxdatanum:" + tram1->maxdatanum.ToString() ;
			MessageBox::Show(str1);
		}
	};
}