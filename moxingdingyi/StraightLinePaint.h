#pragma once

#include"windows.h"
#include <GL/glut.h>
#include <vector>
#include <time.h>
#include<WinUser.h>
#include<windef.h>
#include<synchapi.h>
#include<wingdi.h>
#include<WinNls.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Data::Common;
using namespace System::Data::OleDb;
using namespace System::Collections;
using namespace System::Runtime::InteropServices;

namespace StraightPaintForm{
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
		GLfloat actual_dist;	//距离上一个站点或者起始点的实际距离
		GLfloat scale_dist;//屏幕上的距离
		Point^ pos;
		bool ifArrived = false;//是否到达站点
		bool ifIn = false;//正向时为是否进入该站点为起点的站间，反向时为是否进入该站点为终点的站间
		int arrivedTram_no;//到站列车索引，不分正反
		int arrivedTram_no1;//到站列车索引，分正反
		int stayTime;//到站停留时间
		int times;
		int run_time;//站间运行时间
		float v = 0;
		List<int>^up_people=gcnew List<int>();//上车人数
		List<int>^down_people = gcnew List<int>();//下车人数
		List<int>^peoples = gcnew List<int>();//客流量
	};

	//有轨电车
	ref class Tram
	{
	public:
		Point^ p1, ^p2, ^p3, ^p4, ^p5, ^p6;		 //车顺时针6个点
		int capacity=150;	//电车容量
		int passengers_num;	   //乘客数目
		bool positive_run;//行驶方向
		bool finish = false;//若运行完成不绘制
		int hasPassed=0;
		float rate;//列车实时空载率
		float avg_rate=0.0f;//列车平均空载率
		float min_rate=0.0f;//列车最小空载率
		int tram_no;
		float v = 0.0f;//列车速度
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

	const float pi = 3.141592f;
	public ref class StraightLinePaint : public System::Windows::Forms::NativeWindow
	{
		
	  public:
		HDC m_hDC;
		HGLRC m_hglrc;
		List<Site^>^  sites;  //正向站点
		List<Site^>^  sites1;//反向站点
		Tram^tram;//列车
		List<Tram^>^ trams=gcnew List<Tram^>();

		String^project_num;//方案编号
		char *line_num; //线路编号
		char *tram_num;//电车编号
		float road_len;//线路总长度
		float scale_len=3.6f;//屏幕线路总长度
		float scale;
		float path_width = 0.02;//轨道宽度
		float orbit_len = 1.8f;//屏幕一半长度
		float stand_len = 1.6f;//逻辑站点图一半的长度

		float tram_width = 0.03f;//列车一半长度
		float tram_height = 0.03f;//列车高度
		bool positive_run=true;//行驶方向
		float step;//行驶步长
		float total_step;//总行驶路程

		int tram_no = 0;//正向列车编号
		int tram_no1 = 0;//反向列车编号


	  public:
		// 初始化绘图数据
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
				initGL("P001");
				//获取线路长度、站点信息
				DB_assign_value();

				//初始化线路数据
				initLine();

				//站点人数初始化
				initSitePeople();

				//初始化列车信息
				initTram(true);
			}
		}

		//回调函数，实时绘制图形
		System::Void Render(System::Void)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// 清除屏幕和深度缓冲区
			glLoadIdentity();// 重置当前模型视图矩阵
			glTranslatef(0.0f, 0.0f, -1.5f);

			drawPath();
			showSites();
			showStand();
			glPushMatrix();

			String^str1("");
			str1 += 1;
			char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
			glRasterPos2f(-4.0f, 0);
			drawCNString(ch);

			//绘制同一时刻的所有列车
			for (int i = 0; i < trams->Count; i++){
				drawTram(i);
			}
			
			for (int i = 0; i < trams->Count; i++){
				running(trams[i]);
			}
		}

		//刷新缓冲
		System::Void swapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC);
		}

		//从数据库获取数据，获取线路长度route_len、正反站点信息及站间运行时间
	    ArrayList^fangMes = gcnew ArrayList();
		System::Void DB_assign_value()
		{
			DataTable^ table1 = gcnew DataTable;
			String^ str1 = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)line_num);//由线路编号获取线路信息
			String ^sql = "SELECT [线路总长度] FROM [road_info] WHERE 线路编号 = '" + str1 + "';";
			table1 = ExecuteQuery(sql);
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


			//站点
			sql = "SELECT [站点名称], [站间距离],[站点编号]FROM[stand_info] WHERE 线路编号 = '" + str1 + "' ORDER BY 站点编号;";
			table1 = ExecuteQuery(sql);
			sites = gcnew List<Site^>();
			for (int j = 0; j < table1->Rows->Count; j++) {
				Site^ s = gcnew Site();
				fangMes->Clear();
				for (int i = 0; i < table1->Columns->Count; i++)
				{
					fangMes->Add(table1->Rows[j]->ItemArray[i]);
				}
				s->name = fangMes[0]->ToString()->Trim();
				String^ tmp = fangMes[1]->ToString()->Trim();
				const char* ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				s->actual_dist = atof(ts);
				s->site_no = fangMes[2]->ToString()->Trim();
				sites->Add(s);
			}
			
			//反向站点
			sql = "SELECT [站点名称], [站间距离],[站点编号]FROM[stand_info] WHERE 线路编号 = '" + str1 + "' ORDER BY 站点编号 DESC;";
			table1 = ExecuteQuery(sql);
			sites1 = gcnew List<Site^>();
			for (int j = 0; j < table1->Rows->Count; j++) {
				Site^ s = gcnew Site();
				fangMes->Clear();
				for (int i = 0; i < table1->Columns->Count; i++)
				{
					fangMes->Add(table1->Rows[j]->ItemArray[i]);
				}
				s->name = fangMes[0]->ToString()->Trim();
				String^ tmp = fangMes[1]->ToString()->Trim();
				const char* ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				s->actual_dist = atof(ts);
				s->site_no = fangMes[2]->ToString()->Trim();
				sites1->Add(s);
			}

			//获取站间运行时间
			sql = "SELECT [站点停留时间], [站点运行时间] FROM[standBet_info] WHERE 方案编号 = '" + "P001" + "' AND 列车编号='T001';";
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
			}
			
		}

		//初始化站点坐标
		System::Void initLine(){
			int site_index = 0;
			int site1_index = sites1->Count-1;
			float site_dist = 0.0f;
			float total_dist = 0.0f;
			scale = scale_len / road_len;

			//获取屏幕距离长度
			//站点
			for each (Site^ s in sites)
			{
				s->scale_dist = s->actual_dist*scale;
			}

			for each (Site^ s in sites1)
			{
				s->scale_dist = s->actual_dist*scale;
			}

			//遍历站点集合sites
			while (site_index<sites->Count)
			{
					site_dist += sites[site_index]->scale_dist;
					sites[site_index]->pos = gcnew Point(site_dist - orbit_len, -0.11f);     //获取站点绘制坐标
					sites1[site1_index]->pos = gcnew Point(site_dist - orbit_len, -0.39f);     //获取站点绘制坐标
					if (site_index < sites->Count - 1){
						//求得站间运行步长
						sites[site_index]->v = sites[site_index+1]->scale_dist / sites[site_index]->run_time;
						sites1[site_index]->v = sites1[site_index]->scale_dist / sites1[site_index + 1]->run_time;
					}
					
					site_index++;
					site1_index--;
			}
		}

		//显示站点
		System::Void showSites(){
			for (int i = 0; i < sites->Count;i++)
			{
				for (int j = 0; j < trams->Count; j++){
					//正向
					if (trams[j]->positive_run){
						if (trams[j]->p5->_x >= sites[i]->pos->_x&&trams[j]->hasPassed == i){
							sites[i]->ifArrived = true;//列车到站
							sites[i]->arrivedTram_no = j;
							sites[i]->arrivedTram_no1 = trams[j]->tram_no;
							trams[j]->v = 0;
							trams[j]->hasPassed++;
						}
					}
					//反向
					else{
						if (trams[j]->p5->_x <= sites1[i]->pos->_x&&trams[j]->hasPassed == i){
							sites1[i]->ifArrived = true;//列车到站
							sites1[i]->arrivedTram_no = j;
							sites1[i]->arrivedTram_no1 = trams[j]->tram_no;
							trams[j]->v = 0;
							trams[j]->hasPassed++;
						}
					}
				}
				drawSites(i, sites[i]->pos->_x, sites[i]->pos->_y, 0.02f, sites[i]->ifArrived);
				drawSites(i, sites1[i]->pos->_x, sites1[i]->pos->_y, 0.02f, sites1[i]->ifArrived);
			}
		}

		//绘制站点  ifPass 是否到达，x，y为圆心坐标值
		System::Void drawSites(int site_index, float x, float y, float R, bool ifArrive)
		{
			//站点绘制 圆环
			static int n = 20;
			glBegin(GL_POLYGON);
			glColor3f(0.5f + (ifArrive)*(0.5f), 0.7f, 0.7f);
			//外环
			for (int i = 0; i < n; i++)
			{
				glVertex2f(x + R*cosf(2 * pi*i / n), y + R*sinf(2 * pi*i / n));   //获取20个绘制圆的顶点
			}
			glEnd();

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
		System::Void initSitePeople(){
			//正向站点的人数初始化
			for (int i = 0; i < sites->Count; i++){
				if (i < sites->Count - 1){
					for (int j = 0; j < 28; j++){
						//高峰时段客流量
						if (j == 1 && j == 2 && j == 3 && j == 4 && j == 20 && j == 21 && j == 22 && j == 23){
							sites[i]->up_people->Add(random->Next(10, 14));
							sites[i]->down_people->Add(0);
							sites[i]->peoples->Add(0);
						}
						else{
							sites[i]->up_people->Add(random->Next(4, 8));
							sites[i]->down_people->Add(0);
							sites[i]->peoples->Add(0);
						}
				 }
				}
				//如果为终点站，上车人数为0
				else{
					for (int j = 0; j < 28; j++){
						sites[i]->up_people->Add(0);
						sites[i]->down_people->Add(0);
						sites[i]->peoples->Add(0);
					}
					
				}
			}
			//反向站点的人数初始化
			for (int i = 0; i < sites1->Count; i++){
				if (i < sites1->Count - 1){
					for (int j = 0; j < 28; j++){
						//高峰时段客流量
						if (j == 0 && j == 1 && j == 2 && j == 3 && j == 19 && j == 20 && j == 21 && j == 22){
							sites1[i]->up_people->Add(random->Next(10, 14));
							sites1[i]->down_people->Add(0);
							sites1[i]->peoples->Add(0);
						}
						else{
							sites1[i]->up_people->Add(random->Next(4, 8));
							sites1[i]->down_people->Add(0);
							sites1[i]->peoples->Add(0);
						}
					}
				}
				//如果为终点站，上车人数为0
				else{
					for (int j = 0; j < 28; j++){
						sites1[i]->up_people->Add(0);
						sites1[i]->down_people->Add(0);
						sites1[i]->peoples->Add(0);
					}
					
				}
			}
		}

		//更新站点人数,站点索引，isPositive方向,time_dex时间段
		System::Void updateSitePeople(int site_index,int time_dex,bool isPositive){
			if (isPositive){
				if (time_dex == 0 && time_dex == 9 && time_dex == 10){
					sites[site_index]->up_people[time_dex]=random->Next(15, 20);
					sites[site_index]->down_people[time_dex]=random->Next(5, 20);
					sites[site_index]->peoples[time_dex] = random->Next(40, 50);
				}
				else{
					sites[site_index]->up_people[time_dex] = random->Next(5, 10);
					sites[site_index]->down_people[time_dex] = random->Next(5, 10);
					sites[site_index]->peoples[time_dex] = random->Next(20, 30);
				}
			}
			else{
				if (time_dex == 0 && time_dex == 9 && time_dex == 10){
					sites1[site_index]->up_people[time_dex] = random->Next(15, 20);
					sites1[site_index]->down_people[time_dex] = random->Next(5, 20);
					sites1[site_index]->peoples[time_dex] = random->Next(40, 50);
				}
				else{
					sites1[site_index]->up_people[time_dex] = random->Next(5, 10);
					sites1[site_index]->down_people[time_dex] = random->Next(5, 10);
					sites1[site_index]->peoples[time_dex] = random->Next(20, 30);
				}
			}
		}

		//轨道绘制
		System::Void drawPath(){
			//轨道颜色
			glColor3f(0.3f, 0.6f, 1.0f);

			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

			//绘制上直线轨道
			glBegin(GL_LINES);
			glVertex2f(-orbit_len, -0.1f);
			glVertex2f(orbit_len, -0.1f);
			glEnd();
			glBegin(GL_LINES);
			glVertex2f(orbit_len, -0.1f - path_width);
			glVertex2f(-orbit_len, -0.1f - path_width);
			glEnd();
			

			//绘制下直线轨道
			glBegin(GL_LINES);
			glVertex2f(-orbit_len, -0.38f);
			glVertex2f(orbit_len, -0.38f);
			glEnd();
			glBegin(GL_LINES);
			glVertex2f(orbit_len, -0.38f - path_width);
			glVertex2f(-orbit_len, -0.38f - path_width);
			glEnd();
			
		}

		//绘制逻辑站点图
		System::Void showStand(){
			//绘制站点名字
			String^ str;
			int site_num = sites->Count;
			int name_max = sites[0]->name->Length;//站点名称最大值
			//每个站点的间隔
			float delta_x = 2*stand_len / site_num;
			//起始站点横坐标值
			float x = -stand_len;
			float dist_x = 0.0f;
			float dist_x1 = 0.0f;
			float R = 0.02f;//站点圆半径
			float r = 0.015f;//站点圆半径

			//遍历站点集合，获取站点名称最大值
			for (int site_index = 0; site_index < site_num; site_index++){
				if (name_max < sites[site_index]->name->Length){
					name_max = sites[site_index]->name->Length;
				}
			}

			//遍历上部站点集合
			for (int site_index = 0; site_index < site_num; site_index++){
				//绘制站点名称
				glColor3f(0.2f, 0.2f, 0.2f);
				str = sites[site_index]->name;
				//设置字体显示位置
				float y = 0.45f;//第一个字体显示的纵坐标
				for (int i = 0; i < str->Length; i++){
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
					glVertex2f(x + dist_x + 0.025f + R*cos(2 * pi / 20 * i), 0.55f + R*sin(2 * pi / 20 * i));//圆的坐标
				glEnd();
				glBegin(GL_POLYGON);//开始画圆
				for (int i = 0; i < 20; ++i)
					glVertex2f(x + dist_x + 0.025f + r*cos(2 * pi / 20 * i), 0.55f + r*sin(2 * pi / 20 * i));//圆的坐标
				glEnd();

				//绘制列车到站图标
				if (sites[site_index]->ifArrived){
					glColor3f(1.0f, 0.0f, 0.0f); //设置颜色
					glBegin(GL_POLYGON);//开始画圆
					for (int i = 0; i < 20; ++i)
						glVertex2f(x + dist_x + 0.025f + 0.025f*cos(2 * pi / 20 * i), 0.59f + 0.025f*sin(2 * pi / 20 * i));//圆的坐标
					glEnd();
					String^str1("");
					str1 += (sites[site_index]->arrivedTram_no1);
					char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
					glRasterPos2f(x + dist_x+0.016f , 0.575f);
					drawCNString(ch);
				}
			
				//绘制列车站间图标
				if (site_index < site_num - 1&&sites[site_index]->ifIn&&!sites[site_index + 1]->ifArrived){
					glColor3f(1.0f, 0.0f, 0.0f); //设置颜色
					glBegin(GL_POLYGON);//开始画圆
					for (int i = 0; i < 20; ++i)
						glVertex2f(x + dist_x + 0.025f + 0.025f*cos(2 * pi / 20 * i) + delta_x / 2, 0.59f + 0.025f*sin(2 * pi / 20 * i));//圆的坐标
					glEnd();
					String^str1("");
					str1 += (sites[site_index]->arrivedTram_no1);
					char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
					glRasterPos2f(x + dist_x + 0.016f + delta_x / 2, 0.575f);
					drawCNString(ch);
				}

				if (site_index < site_num - 1){
					//绘制上部虚线
					glColor3f(0.0f + sites[site_index]->ifIn*1.0f, 0.5f - sites[site_index]->ifIn*0.5f, 0.5f - sites[site_index]->ifIn*0.5f); //设置颜色
					glLineStipple(2, 0x5555);
					glEnable(GL_LINE_STIPPLE);
					glBegin(GL_LINES);
					glVertex2f(x + dist_x + 0.025f + R, 0.55f);
					glVertex2f(x + dist_x + 0.025f + delta_x - R, 0.55f);
					glEnd();
					glDisable(GL_LINE_STIPPLE);
				}
				dist_x = dist_x + delta_x;
			}
			//遍历下部站点集合
			for (int site_index = site_num-1; site_index >=0; site_index--){
				//绘制下部站点圆
				glColor3f(0.0f + sites1[site_index]->ifArrived*1.0f, 0.5f - sites1[site_index]->ifArrived*0.5f, 0.5f - sites1[site_index]->ifArrived*0.5f); //设置颜色
				glBegin(GL_POLYGON);//开始画圆
				for (int i = 0; i < 20; ++i)
					glVertex2f(x + dist_x1 + 0.025f + R*cos(2 * pi / 20 * i), 0.55f - 0.06f*name_max - 0.08f + R*sin(2 * pi / 20 * i));//圆的坐标
				glEnd();
				glBegin(GL_POLYGON);//开始画圆
				for (int i = 0; i < 20; ++i)
					glVertex2f(x + dist_x1 + 0.025f + r*cos(2 * pi / 20 * i), 0.55f - 0.06f*name_max - 0.08f + r*sin(2 * pi / 20 * i));//圆的坐标
				glEnd();

				//绘制列车到站图标
				if (sites1[site_index]->ifArrived){
					glColor3f(1.0f, 0.0f, 0.0f); //设置颜色
					glBegin(GL_POLYGON);//开始画圆
					for (int i = 0; i < 20; ++i)
						glVertex2f(x + dist_x1 + 0.025f + 0.025f*cos(2 * pi / 20 * i), 0.51f - 0.06f*name_max - 0.08f + 0.025f*sin(2 * pi / 20 * i));//圆的坐标
					glEnd();
					String^str1("");
					str1 += (sites1[site_index]->arrivedTram_no1);
					char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
					glRasterPos2f(x + dist_x1 + 0.016f, 0.51f - 0.06f*name_max - 0.08f - 0.025f);
					drawCNString(ch);
				}

				//绘制列车站间图标
				if (site_index >0 && sites1[site_index]->ifIn&&!sites1[site_index]->ifArrived){
					glColor3f(1.0f, 0.0f, 0.0f); //设置颜色
					glBegin(GL_POLYGON);//开始画圆
					for (int i = 0; i < 20; ++i)
						glVertex2f(x + dist_x1 + 0.025f + 0.025f*cos(2 * pi / 20 * i) + delta_x / 2, 0.51f - 0.06f*name_max - 0.08f + 0.025f*sin(2 * pi / 20 * i));//圆的坐标
					glEnd();
					String^str1("");
					str1 += (sites1[site_index-1]->arrivedTram_no1);
					char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
					glRasterPos2f(x + dist_x1 + 0.016f + delta_x / 2, 0.51f - 0.06f*name_max - 0.08f - 0.025f);
					drawCNString(ch);
				}

				if (site_index > 0){
					glColor3f(0.0f + sites1[site_index]->ifIn*1.0f, 0.5f - sites1[site_index]->ifIn*0.5f, 0.5f - sites1[site_index]->ifIn*0.5f); //设置颜色
					glLineStipple(2, 0x5555);
					glEnable(GL_LINE_STIPPLE);
					//绘制下部虚线
					glBegin(GL_LINES);
					glVertex2f(x + dist_x1 + 0.025f + R, 0.55f - 0.06f*name_max - 0.08f);
					glVertex2f(x + dist_x1 + 0.025f + delta_x - R, 0.55f - 0.06f*name_max - 0.08f);
					glEnd();
					glDisable(GL_LINE_STIPPLE);
				}
				dist_x1 = dist_x1 + delta_x;
			}
		}

		//绘制电车
		System::Void drawTram(int tram_index){
			//列车运行未完成绘制列车
			if (!trams[tram_index]->finish){
				//绘制有轨电车
				glBegin(GL_POLYGON);
				glColor3f(1.0f, 0.3f, 0.6f);
				glVertex3f(trams[tram_index]->p1->_x, trams[tram_index]->p1->_y, trams[tram_index]->p1->_z);
				glVertex3f(trams[tram_index]->p2->_x, trams[tram_index]->p2->_y, trams[tram_index]->p2->_z);
				glVertex3f(trams[tram_index]->p3->_x, trams[tram_index]->p3->_y, trams[tram_index]->p3->_z);
				glVertex3f(trams[tram_index]->p4->_x, trams[tram_index]->p4->_y, trams[tram_index]->p4->_z);
				glEnd();
				glBegin(GL_LINES);
				glVertex2f(trams[tram_index]->p5->_x, trams[tram_index]->p5->_y);
				glVertex2f(trams[tram_index]->p6->_x, trams[tram_index]->p6->_y);
				glEnd();
				String^str1("");
				str1 += trams[tram_index]->tram_no;
				char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
				if (trams[tram_index]->positive_run){
					glRasterPos2f(trams[tram_index]->p5->_x, trams[tram_index]->p1->_y + 0.01f);
				}
				else{
					glRasterPos2f(trams[tram_index]->p5->_x, trams[tram_index]->p1->_y - 0.05f);
				}
				drawCNString(ch);
			}
		}

		//列车运行函数
		System::Void running(Tram^tram){
			float step = tram->v;
			total_step += step;
			if (tram->positive_run){
				tram->p1->_x += step;
				tram->p2->_x += step;
				tram->p3->_x += step;
				tram->p4->_x += step;
				tram->p5->_x += step;
				tram->p6->_x += step;
			}
			else{
				tram->p1->_x -= step;
				tram->p2->_x -= step;
				tram->p3->_x -= step;
				tram->p4->_x -= step;
				tram->p5->_x -= step;
				tram->p6->_x -= step;
			}
		}

		//设置步长
		Void setVelocity(float newStep){
			step = newStep;
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

		//添加列车并初始化列车的位置以及起始点的位置
		GLvoid initTram(bool positive_run)
		{
			float tmp;//轨道中心纵坐标

			total_step = 0;
			//初始化列车位置
			if (positive_run){
				//正向
				tmp = -0.11f;
				tram = gcnew Tram(
					gcnew Point(-orbit_len - tram_width, tmp + 0.06f + tram_height),
					gcnew Point(-orbit_len + tram_width, tmp + 0.06f + tram_height),
					gcnew Point(-orbit_len + tram_width, tmp + 0.06f),
					gcnew Point(-orbit_len - tram_width, tmp + 0.06f),
					gcnew Point(-orbit_len, tmp + 0.06f),
					gcnew Point(-orbit_len, tmp - 0.06f)
					);
				tram->positive_run = true;
				tram_no++;
				tram->tram_no = tram_no;
				trams->Add(tram);
			}
			else{
				//反向
				tmp = -0.39f;
				tram = gcnew Tram(
					gcnew Point(orbit_len + tram_width, tmp - 0.06f - tram_height),
					gcnew Point(orbit_len - tram_width, tmp - 0.06f - tram_height),
					gcnew Point(orbit_len - tram_width, tmp - 0.06f),
					gcnew Point(orbit_len + tram_width, tmp - 0.06f),
					gcnew Point(orbit_len, tmp + 0.06f),
					gcnew Point(orbit_len, tmp - 0.06f)
					);
				tram->positive_run = false;
				tram_no1++;
				tram->tram_no = tram_no1;
				trams->Add(tram);
			}

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

			glViewport(-20, 0, width/1.1, height/1.1);						// Reset The Current Viewport

			glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
			glLoadIdentity();									// Reset The Projection Matrix

			//Calculate The Aspect Ratio Of The Window
			gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

			glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
			glLoadIdentity();									// Reset The Modelview Matrix
		}

		//初始化OpenGL界面
		bool initGL(String^project_num)										// All setup for opengl goes here
		{
			glShadeModel(GL_SMOOTH);							// Enable smooth shading
			glClearColor(1.0f, 1.0f, 1.0f, 0.5f);				// 	 背景色
			glClearDepth(1.0f);									// 深度缓冲设置
			(GL_DEPTH_TEST);							// 启用深度测试
			glDepthFunc(GL_LEQUAL);								// 深度测试的类型
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// 很好的透视计算

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

			return TRUE;										// Initialisation went ok
		}

		

		//自定义查询数据库函数
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
		}
	};
}