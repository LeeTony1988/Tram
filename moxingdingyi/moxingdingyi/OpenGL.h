#pragma once


#include <GL/glut.h>
#include <vector>
#include <time.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Data::Common;
using namespace System::Data::OleDb;
using namespace System::Collections;
using namespace System::Runtime::InteropServices;

namespace OpenGLForm
{
	
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
		GLfloat actual_dist;	//距离上一个站点或者起始点的实际距离
		GLfloat scale_dist;//屏幕上的距离
		Point^ pos;
		int ifArrived;//是否经过

	};	  
	
	//供电区间
	ref class PowerInterval{
	public:
		String	^name;
		GLfloat actual_dist;	//距离上一个供电区间末端或者起始点的实际距离
		GLfloat scale_dist;//屏幕上的实际距离
		GLfloat actual_len;//区间实际长度
		GLfloat scale_len;//区间屏幕上的长度
		List<Point^>^ outer_pos;//区间的外轨道坐标
		List<Point^>^ inner_pos;//区间的内轨道坐标
		bool isPassed;//是否经过
	};

	//监测信息
	ref class  MonitorInfo 
	{
	public:
		//第一次
		tm* first;	//时间
		float first_step;
		//第二次
		tm* second;		//时间
		float second_step;
	};

	//监测点
	ref class MonitorPoint 
	{
	public:
		String	 ^name;
		GLfloat actual_dist;	//距离上一个监测点或者起始点的实际距离
		GLfloat scale_dist;//屏幕上的距离
		Point^ pos;
		GLfloat response_actual_dist;//响应实际距离
		GLfloat response_scale_dist;  //响应屏幕上的距离
		int isPassed;//是否已经经过该监测点
		MonitorInfo^ monitorInfo;
	};

	//红绿灯
	ref class TrafficLight {
	public:
		String	 ^name;
		GLfloat actual_dist;	//距离上一个站点或者起始点的实际距离
		GLfloat scale_dist;//屏幕上的距离
		Point^ pos;
		bool isGreenLight;//是否到绿灯亮
		float greenTime;
		float redTime;
		//void start() { isGreenLight = true; }//电车开始运行时默认绿灯亮
	};

	 //有轨电车
	ref class Tram
	{
	public:
		Point^ p1, ^p2, ^p3, ^p4;		 //车顺时针四个点
		int capacity;	//电车容量
		int passengers_num;	   //乘客数目
		Tram() {}
		Tram(Point^ _p1, Point^ _p2, Point^ _p3, Point^ _p4)
		{
			p1 = _p1;
			p2 = _p2;
			p3 = _p3;
			p4 = _p4;
		}
	};
	
	//模型层
	ref class ModelLayer {
	public:
		List<int>^  sites;  //站点
		List<int>^ powerInterval; //供电区间
		List<int>^ monitorPoint;	 //监测点
		List<int>^ trafficLight;		  //红绿灯
	};

	//交叉点的驶入状态
	enum turn_state
	{
		straight_to_turn,
		turn_to_straight_down,
		turn_to_straight_up,
		reverse_straight_to_turn,
		reverse_turn_to_straight_down,
		reverse_turn_to_straight_up
	};

	const int numOfPoints = 364;	 //轨道的点的个数
	const float pi = 3.141592f;
	const float scale_r = 6.00f;	 //内轨道半径是外轨道半径的比例
	const float scale_t = 0.20f;	  //有轨电车在轨道上下所留的空白间隔
	const float scale_act = 500.0f;//实际线路与轨道一圈的缩放比例 8400/500.0=16.8圈
	const GLfloat interval = 2 / 15.5f;		 //供电区间长度
	
	public ref class COpenGL : public System::Windows::Forms::NativeWindow
	{
	public:
		COpenGL(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight,int x,int y)
		{
			CreateParams^ cp = gcnew CreateParams;	  //CreateParams 来重载窗体的一些特性

			// 设置窗体上的位置
			cp->X = x;
			cp->Y = y;
			cp->Height = iHeight;
			cp->Width = iWidth;

			//指定窗体为父窗体
			cp->Parent = parentForm->Handle;

			// 创建指定父级的子对象并使其符合OpenGL（无剪辑）
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			// 创建实际窗口
			this->CreateHandle(cp);

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			//轨道位置数组初始化
			outer_orbit = gcnew List<Point^>(numOfPoints);
			inner_orbit = gcnew List<Point^>(numOfPoints);

			if (m_hDC)
			{
				mySetPixelFormat(m_hDC);
				reSizeGLScene(iWidth, iHeight);
				initGL();

				getPointsOfOrbit();	  
				initTram();

				DB_assign_value();
				initOrbitInfo();
				
			}
			
		}
		
		System::Void DB_assign_value()
		{
			DataTable^ table1 = gcnew DataTable;
			String^ str1 = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)line_num);
			String ^sql = "SELECT [线路总长度] FROM [线路信息] WHERE 线路编号 = '"+ str1 +"';";
			table1 = ExecuteQuery(sql);
			for (int j = 0; j < table1->Rows->Count; j++) {
				fangMes->Clear();
				for (int i = 0; i < table1->Columns->Count; i++)
				{
					fangMes->Add(table1->Rows[j]->ItemArray[i]);
				}
				String^ tmp = fangMes[0]->ToString()->Trim();
				const char* ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				route_len = atof(ts);
			}
			

			//站点
			sql = "SELECT [站点名称], [站间距离]FROM[站点信息] WHERE 线路编号 = '"+ str1+"';";
			table1 = ExecuteQuery(sql);
			sites = gcnew List<Site^>();
			 for (int j = 0; j < table1->Rows->Count;j++) {
				 Site^ s = gcnew Site();
				 fangMes->Clear();
				 for (int i = 0; i < table1->Columns->Count; i++)
				 {
					 fangMes->Add(table1->Rows[j]->ItemArray[i]);
				 }
				 s->name= fangMes[0]->ToString()->Trim();
				 String^ tmp= fangMes[1]->ToString()->Trim();
				 const char* ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				 s->actual_dist = atof(ts);
				 s->ifArrived = 0;
				 sites->Add(s);
			 }
		
			 //供电区间
			 sql = "SELECT [区间编号], [区间长度] , [相邻区间距离]FROM[供电区间信息]WHERE 线路编号 = '"+str1+"';";
			table1 = ExecuteQuery(sql);
			powerInterval = gcnew   List<PowerInterval^>();
			for (int j = 0; j < table1->Rows->Count; j++) {
				PowerInterval^ p = gcnew PowerInterval();
				fangMes->Clear();
				for (int i = 0; i < table1->Columns->Count; i++)
				{
					fangMes->Add(table1->Rows[j]->ItemArray[i]);
				}
				p->name = fangMes[0]->ToString()->Trim();
				String^ tmp = fangMes[1]->ToString()->Trim();
				const char* ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				p->actual_len = atof(ts);
				tmp = fangMes[2]->ToString()->Trim();
				ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				p->actual_dist = atof(ts);
				p->inner_pos = gcnew List<Point^>();
				p->outer_pos = gcnew List<Point^>();
				p->isPassed = false;
				powerInterval->Add(p);
			}

			//监测点
			sql = "SELECT [监测点编号], [相邻监测点距离]FROM[监测点信息] WHERE 线路编号 = '"+str1+"';";
			table1 = ExecuteQuery(sql);
			monitorPoint = gcnew List<MonitorPoint^>();
			for (int j = 0; j < table1->Rows->Count; j++) {
				MonitorPoint^ m = gcnew MonitorPoint();
				fangMes->Clear();
				for (int i = 0; i < table1->Columns->Count; i++)
				{
					fangMes->Add(table1->Rows[j]->ItemArray[i]);
				}
				m->name= fangMes[0]->ToString()->Trim();
				String^ tmp = fangMes[1]->ToString()->Trim();
				const char* ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				m->actual_dist = atof(ts);
				m->monitorInfo = gcnew MonitorInfo();
				m->isPassed = 0;
				monitorPoint->Add(m);
			}


			//红绿灯
			sql = "SELECT [红绿灯编号], [红灯时间], [绿灯时间], [相邻红绿灯距离]FROM[红绿灯信息]WHERE 线路编号 = '"+str1+"';";
			table1 = ExecuteQuery(sql);
			trafficLight = gcnew List<TrafficLight^>();
			for (int j = 0; j < table1->Rows->Count; j++) 
			{
				TrafficLight^ t = gcnew TrafficLight();
				fangMes->Clear();
				for (int i = 0; i < table1->Columns->Count; i++)
				{
					fangMes->Add(table1->Rows[j]->ItemArray[i]);
				}
				t->name = fangMes[0]->ToString()->Trim();
				String^ tmp = fangMes[1]->ToString()->Trim();
				const char* ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				t->redTime = atof(ts);
				tmp = fangMes[2]->ToString()->Trim();
				ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				t->greenTime = atof(ts);
				tmp = fangMes[3]->ToString()->Trim();
				ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				t->actual_dist = atof(ts);
				t->isGreenLight = true;
				trafficLight->Add(t);
			}
			 /*
			for (int i = 0; i < 15; i++)
			{
				TrafficLight^ l = gcnew TrafficLight();
				l->name = "红绿灯" + i;
				l->actual_dist = 550;
				l->isGreenLight = true;
				trafficLight->Add(l);
			}
			*/
		}

		//设置运行速度
		System::Void setVelocity(float newVel)
		{
				step = newVel;
		}

		bool IfArriveEnd()
		{
			return ifArriveEnd;
		}

		//回调函数
		System::Void Render(System::Void)
		{
			static const GLfloat z = 0.9f;
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear screen and depth buffer
			glLoadIdentity();									// Reset the current modelview matrix
		
			glTranslatef(0.0f, 0.0f, -1.5f);

			//轨道颜色
			glColor3f(0.3f, 0.6f, 1.0f);	
			
			//绘制线条模式
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			//视角位置	//-2.0f
			//glTranslatef(0.0f, 0.0f, -2.0f); 

			//外轨道绘制
			glBegin(GL_POLYGON);
			for each (Point^ var in outer_orbit)
			{
				glVertex3f(var->_x, var->_y, var->_z);
			}
			glEnd();

			//内轨道绘制
			glBegin(GL_POLYGON);
			for each (Point^ var in inner_orbit)
			{
				glVertex3f(var->_x, var->_y, var->_z);
			}
			glEnd();
			glPushMatrix();

			//有轨电车颜色
			glBegin(GL_POLYGON);
			glColor3f(1.0f, 0.3f, 0.6f);
			glVertex3f(tram->p1->_x, tram->p1->_y, tram->p1->_z);
			glVertex3f(tram->p2->_x, tram->p2->_y, tram->p2->_z);
			glVertex3f(tram->p3->_x, tram->p3->_y, tram->p3->_z);
			glVertex3f(tram->p4->_x, tram->p4->_y, tram->p4->_z);
			glEnd();


			//isTramClosePower();
			//drawPowerInterval(0, 0);
			//callModelLayer();
			//subDrawTrafficLight(orbit_len+0.35, 0.0, true);
		    
			

			if (total_step + step > scale_route_len)
			{
				setVelocity(scale_route_len - total_step);
			} 

			Running(positive_run);

			callModelLayer();
			   /*
			if (total_step >= (scale_route_len-step))
			{
				ifArriveEnd = true;
				printf("（%lf，%lf）", tram->p1->_x, tram->p1->_y);
			}
			*/
			//printf("%d ", tram->p3->_y < 0.0f);
			//scale_route_len = 5.0f;
			/*if (total_step<=scale_route_len)
			{
				Running(true);//正向
			}
			else 
			{	
				Running(false);	//逆向
			}
				*/
		}

		//调用模型层
		bool callModelLayer()
		{
			if (total_step >= scale_route_len)
			{
				total_step = 0.0;
				//step = 0.0;
				Sleep(10000);
				positive_run = !positive_run;
				return positive_run;
			}

			

			//printf("%lf\n", scale_route_len-total_step);
			//printf("（%lf，%lf）\n", tram->p1->_x, tram->p2->_y);
			static bool isFirstLayer = true;
			int layer_num = modelLayer->Count;
			int tmp = 2*positive_run -1;
			static float remain = layer_num * total_dist-scale_route_len;
			
			
			//算出此时为模型层第几层
			if (positive_run)
			{
				layer_index = (int)((total_step +0.2f)  / (orbit_len * 4.00f + pi * (outer_radius + inner_radius)));
				layer_index = layer_index >= layer_num ? (layer_num - 1) : layer_index;
				isFirstLayer = true;
			}
			else
			{
				if (isFirstLayer&&total_step<remain)
				{
					layer_index = layer_num - 1;
				}
				else   //补充
				{
					isFirstLayer = false;
					layer_index = layer_num - 1-((int)((total_step +0.25) / (orbit_len * 4.00f + pi * (outer_radius + inner_radius))));
					layer_index = layer_index < 0 ? 0 : layer_index;
				}
			}

			


			//printf("%d\n", layer_index);
			//绘制
			showSites(layer_index,positive_run);
			showPowerInterval(layer_index, positive_run);
			showMonitorPoint(layer_index,positive_run);
			showTrafficLight(layer_index);

			//响应
			return positive_run;
		}

		int getModleLayerNum()
		{
			return layer_index;

		}
		  
		/*红绿灯*/
		//显示红绿灯
		System::Void showTrafficLight(int layer_index)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			int num_light = modelLayer[layer_index]->trafficLight->Count;
			for (int i = 0; i < num_light; i++)
			{
				drawTrafficLight(
					trafficLight[modelLayer[layer_index]->trafficLight[i]]->pos->_x,
					trafficLight[modelLayer[layer_index]->trafficLight[i]]->pos->_y,
					trafficLight[modelLayer[layer_index]->trafficLight[i]]->isGreenLight);
			}
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		
		//绘制红绿灯
		System::Void drawTrafficLight(float _x, float _y, bool isGreen)
		{
			float x = -orbit_len;
			float y = outer_radius + offset_y + 0.04f;
			if (_x<=(orbit_len+0.2)&&_x>=-(orbit_len + 0.2))
			{
				if (_y>inner_radius+offset_y)
				{
					subDrawTrafficLight(_x, outer_radius + offset_y + 0.04f, isGreen);
				}
				else  if (_y < inner_radius + offset_y)
				{
					subDrawTrafficLight(_x, -outer_radius + offset_y - 0.04f, isGreen);
				}
			}
			else  if(_x> (orbit_len + 0.2))
			{
				//subDrawTrafficLight(_x , _y, isGreen);
				subDrawTrafficLight(_x-0.1f, _y, isGreen);
			}
			else if (_x < -(orbit_len + 0.2))
			{
				//subDrawTrafficLight(_x, _y, isGreen);
				subDrawTrafficLight(_x + 0.1f, _y , isGreen);
			}

		}

		//辅助绘制红绿灯
		System::Void subDrawTrafficLight(float x,float y,bool isGreen)
		{

			glColor3f(0.3f, 0.3f, 0.3f);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glBegin(GL_POLYGON);
			glVertex3f(x + 0.06f, y + 0.03f, 0.0f);
			glVertex3f(x + 0.06f, y - 0.03f, 0.0f);
			glVertex3f(x - 0.06f, y - 0.03f, 0.0f);
			glVertex3f(x - 0.06f, y + 0.03f, 0.0f);
			glEnd();

			glColor3f(0.4f + (1-(int)(isGreen))*0.6f, 0.4f - (1 - (int)(isGreen))*0.4f, 0.4f - (1 - (int)(isGreen))*0.4f);
			//glColor3f(1, 0.0, 0.0);
			glBegin(GL_POLYGON);
			float R = 0.02f;
			int n = 30;
			for (int i = 0; i < n; i++)
			{
				glVertex2f(x - 0.03f + R * cos(2 * pi*i / n), y + R * sin(2 * pi*i / n));
			}
			glEnd();

			glColor3f(0.4f-(int)(isGreen)*0.4f, 0.4f + (int)(isGreen)*0.6f, 0.4f - (int)(isGreen)*0.4f);
			glBegin(GL_POLYGON);
			for (int i = 0; i < n; i++)
			{
				glVertex2f(x + 0.03f + R * cos(2 * pi*i / n), y + R * sin(2 * pi*i / n));
			}
			glEnd();

			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		
		//红绿灯转换灯光
		System::Void turnLight()
		{
			int lignt_num = trafficLight->Count;
			for (int i = 0; i < lignt_num; i++)
			{
				trafficLight[i]->isGreenLight = !trafficLight[i]->isGreenLight;
			}
		}

		/*监测点*/
		//显示监测点
		System::Void showMonitorPoint(int layer_index,bool isPositive)
		{	  
			int num_monitor = modelLayer[layer_index]->monitorPoint->Count;
			for (int i = 0; i < num_monitor; i++)
			{
				bool ifPass = false;
				int index = modelLayer[layer_index]->monitorPoint[i];
				float  x = monitorPoint[index]->pos->_x;
				float y = monitorPoint[index]->pos->_y;
				if (x <= orbit_len && x >= -orbit_len)
				{
						if (y>offset_y&&tram->p1->_x <= x && tram->p2->_x >= x&&tram->p1->_y>offset_y)
						{
							ifPass = true;
						}
						else if (y < offset_y&&tram->p1->_x >= x && tram->p2->_x <= x&&tram->p1->_y<offset_y)
						{
							ifPass = true;
						}

				}
				else if (x < -orbit_len)
				{
					if ((tram->p2->_x < -orbit_len || tram->p1->_x < -orbit_len)
						&& ((isPositive && (tram->p3->_y <= y || tram->p2->_y <= y) && (tram->p4->_y >= y || tram->p1->_y >= y))
							|| (!isPositive && (tram->p1->_y <= y || tram->p4->_y <= y) && (tram->p3->_y >= y || tram->p2->_y >= y))))
					{
						ifPass = true;
					}
				}
				else if (x > orbit_len)
				{
					if ((tram->p2->_x > orbit_len || tram->p1->_x > orbit_len)
						&& (tram->p3->_y <= y || tram->p2->_y <= y)
						&& (tram->p4->_y >= y || tram->p1->_y >= y))
					{
						ifPass = true;
					}
				}
				//修改
				
				if (ifPass)
				{
					ouputMonitorInfo(index, isPositive);
					//printf("%d", layer_index);
					//printf("  %d\n", index);
				}
					drawMonitorPoint(index, x, y, ifPass);
					/*
					int out = 0;
					if ((out=SendMonitorSignal(-1))>0)
					{
						printf("%d\n", out);
					}
					 */
			 }
		}

		//绘制监测点
		System::Void drawMonitorPoint(int monitor_index,float _x,float _y, bool ifPass)
		{
			glColor3f(1.0f, 0.6f - (int)ifPass*0.6f, 0);

			//直线
			if (_x<=orbit_len&&_x>=-orbit_len)
			{
				float x, y;
				x = _x;
				y = _y+(outer_radius-inner_radius)/2.00f;
				glBegin(GL_LINES);
				glVertex3f(x + 0.0f, y + 0.0f, 0.0f);
				glVertex3f(x - 0.05f, y + 0.05f, 0.0f);
				glEnd();
				glBegin(GL_LINES);
				glVertex3f(x + 0.0f, y + 0.0f, 0.0f);
				glVertex3f(x + 0.05f, y + 0.05f, 0.0f);
				glEnd();
				glBegin(GL_LINES);
				glVertex3f(x + 0.0f, y + 0.0f, 0.0f);
				glVertex3f(x + 0.0f, y + 0.15f, 0);
				glEnd();
			}
			//半圆
			else if (_x > orbit_len)
			{
				int isUp = _y >= offset_y ? 1:-1;
				float gap = (outer_radius - inner_radius) / 2.00f;
				float sinx = abs(_y - offset_y) / (gap + inner_radius);
				float cosx =(_x - orbit_len) / (gap + inner_radius); 

				float x = inner_radius * cosx + orbit_len;
				float y = isUp*inner_radius * sinx + offset_y;

				if (tram->p1->_x <= x && tram->p2->_x >= x)
					ifPass = true;
				glColor3f(1.0f, 0.6f - (int)ifPass*0.6f, 0);


				drawArrow(gcnew Point((x + orbit_len) / 2.00f, (y + offset_y) / 2.00f), gcnew Point(x, y), 0.08f, 20);

			}
			else  if(_x<-orbit_len)
			{
				int isUp = _y >= offset_y ? 1 : -1;
				float gap = (outer_radius - inner_radius) / 2.00f;
				float sinx = abs(_y - offset_y) / (gap + inner_radius);
				float cosx = abs(_x + orbit_len) / (gap + inner_radius);

				float x = -inner_radius * cosx - orbit_len;
				float y = isUp * inner_radius * sinx + offset_y;

				if (tram->p1->_x <= x && tram->p2->_x >= x)
					ifPass = true;
				glColor3f(1.0f, 0.6f - (int)ifPass*0.6f, 0);

				drawArrow(gcnew Point((x  -orbit_len) / 2.00f, (y + offset_y) / 2.00f), gcnew Point(x, y), 0.08f, 20);
			}
		}
	
		//绘制监测点箭头
		System::Void drawArrow(Point^ pStart, Point^ pEnd, float len, int alpha)
		{
			Point^ arrow=gcnew Point(0,0);
			//计算 θ 角（最简单的一种情况在下面图示中已经展示，关键在于 atan2 函数，详情见下面）   
			double angle = atan2((double)(pStart->_y - pEnd->_y), (double)(pStart->_x - pEnd->_x));

			glBegin(GL_LINES);
			glVertex3f(pStart->_x,pStart->_y,0);
			glVertex3f(pEnd->_x, pEnd->_y, 0.0);
			glEnd();

			//计算箭角边的另一端的端点位置（上面的还是下面的要看箭头的指向，也就是pStart和pEnd的位置） 
			arrow->_x = pEnd->_x+ len * cosf(angle +pi * alpha / 180);

			arrow->_y = pEnd->_y+ len * sinf(angle + pi * alpha / 180);

			glBegin(GL_LINES);
			glVertex3f(arrow->_x, arrow->_y, 0);
			glVertex3f(pEnd->_x, pEnd->_y, 0.0);
			glEnd();

			arrow->_x = pEnd->_x + len * cosf(angle - pi * alpha / 180);
			arrow->_y = pEnd->_y + len * sinf(angle - pi * alpha / 180);

			glBegin(GL_LINES);
			glVertex3f(arrow->_x, arrow->_y, 0);
			glVertex3f(pEnd->_x, pEnd->_y, 0.0);
			glEnd();
		}

		//输出监测信息
		System::Void ouputMonitorInfo(int index,bool isPositive)
		{
			static int ouputed = -1;
			if (ouputed == index||abs(ouputed-index)>1)
			{
				return;
			}
			//printf("%d  ", index);
			//printf("%d ", ouputed);
			//正序运行时
			
			if(isPositive
				&&( (index>0&& monitorPoint[index - 1]->isPassed != monitorPoint[index]->isPassed)
					   ||(index==0&& monitorPoint[index + 1]->isPassed == monitorPoint[index]->isPassed)
					  )
			   )
			{
				ouputed = index;
				//printf("@");
				++monitorPoint[index]->isPassed;
				monitorPoint[index]->isPassed %= 2;
				 //获取时间速度
				if (monitorPoint[index]->isPassed == 0)//第二次运行到该监测点
				{
					time_t tt = time(NULL);//这句返回的只是一个时间cuo
					monitorPoint[index]->monitorInfo->second = localtime(&tt);
					monitorPoint[index]->monitorInfo->second_step = step;
					SendMonitorSignal(index);
				}
				else
				{
					time_t tt = time(NULL);//这句返回的只是一个时间cuo
					monitorPoint[index]->monitorInfo->first= localtime(&tt);
					monitorPoint[index]->monitorInfo->first_step = step;
				}
				//printf("\n");
			}
			else if 
				(!isPositive 
				&&( (index < (monitorPoint->Count-1)&& monitorPoint[index +1]->isPassed != monitorPoint[index]->isPassed) 
					    || (index == (monitorPoint->Count - 1) && monitorPoint[index - 1]->isPassed == monitorPoint[index]->isPassed)
					  )
				)
			{
				ouputed = index;
				//printf("@");
				++monitorPoint[index]->isPassed;
				monitorPoint[index]->isPassed %= 2;
				//获取时间速度
				if (monitorPoint[index]->isPassed == 0)//第二次运行到该监测点
				{
					time_t tt = time(NULL);//这句返回的只是一个时间cuo
					monitorPoint[index]->monitorInfo->second = localtime(&tt);
					monitorPoint[index]->monitorInfo->second_step = step;
					SendMonitorSignal(index);
				}
				else
				{
					time_t tt = time(NULL);//这句返回的只是一个时间cuo
					monitorPoint[index]->monitorInfo->first = localtime(&tt);
					monitorPoint[index]->monitorInfo->first_step = step;
				}
				//printf("\n");

			}

			//printf("（%d， ", ouputed);
			//printf(" %d）\n", monitorPoint[ouputed]->isPassed);
		}

	   //发送监测信号给界面
		int  SendMonitorSignal(int index)
		{
			static int out = -1;
			if (index<0)
			{
				if (out<0)
				{
					return index;
				}
				else
					return out;
			}
			out = index;
			return out;
			
		}

		 /*供电区间*/
		//显示供电区间
		System::Void showPowerInterval(int layer_index,bool isPositive)
		{
			int num_power = modelLayer[layer_index]->powerInterval->Count;

			static bool ifIn = false; //是否在供电区间内
			static int index = -1;	//第i个供电区间
			static int last_index_of = -1;		//第i个供电区间的最后一个坐标

			//printf("(%d,%d)", layer_index, index);
			//正序
			if (isPositive)
			{
				while (!ifIn)
				{
					int i = 0;
					for (i = 0; i < num_power; i++)
					{
						index = modelLayer[layer_index]->powerInterval[i];
						last_index_of = powerInterval[index]->inner_pos->Count - 1;
						drawPowerInterval(index, layer_index, ifIn);
						//跨模型层 供电区间在下一层第一个点不响应
						int j =layer_index<1?-1: modelLayer[layer_index - 1]->powerInterval->Count - 1;
						if (layer_index  >= 1 && modelLayer[layer_index - 1]->powerInterval->Count>0&&index == modelLayer[layer_index - 1]->powerInterval[j])
						{
							continue;
						}
						//printf("%d\n", index);
						if (powerInterval[index]->inner_pos[0]->_x >= -orbit_len
							&& powerInterval[index]->inner_pos[0]->_x <= orbit_len)
						{
							//直线上
							if (powerInterval[index]->inner_pos[0]->_y > offset_y
								&&powerInterval[index]->inner_pos[0]->_y < tram->p3->_y
								&&powerInterval[index]->inner_pos[0]->_x <= tram->p3->_x
								&&tram->p3->_x - powerInterval[index]->inner_pos[0]->_x <= step)
							{
								//printf("1 ");
								ifIn = true;
								drawPowerInterval(index, layer_index, ifIn);
								return;
							}
							//直线下
							if (powerInterval[index]->inner_pos[0]->_y < offset_y
								&&powerInterval[index]->inner_pos[0]->_y > tram->p3->_y
								&&powerInterval[index]->inner_pos[0]->_x >= tram->p3->_x
								&&powerInterval[index]->inner_pos[0]->_x - tram->p3->_x <= step)

							{
								//printf("2 ");
								ifIn = true;
								drawPowerInterval(index, layer_index, ifIn);
								return;
							}
						}
						else if (powerInterval[index]->inner_pos[0]->_x < -orbit_len) {
							//左弧
							if (tram->p3->_x < -orbit_len && tram->p3->_y >= powerInterval[index]->inner_pos[0]->_y
								&&tram->p3->_y - powerInterval[index]->inner_pos[0]->_y <= step)
							{
								//printf("3 ");
								ifIn = true;
								drawPowerInterval(index, layer_index, ifIn);
								return;
							}
						}
						else if (powerInterval[index]->inner_pos[0]->_x >= -orbit_len)
						{
							//printf("(%d,%d,%d)\n", tram->p3->_x >= orbit_len, tram->p3->_y <= powerInterval[index]->inner_pos[0]->_y
								//, powerInterval[index]->inner_pos[0]->_y - tram->p3->_y < step);
							//printf("%lf  %lf   %lf",powerInterval[index]->inner_pos[0]->_y, tram->p3->_y, step);
							//右弧
							if (tram->p3->_x >= orbit_len &&tram->p3->_y <= powerInterval[index]->inner_pos[0]->_y)
								//&&powerInterval[index]->inner_pos[0]->_y - tram->p3->_y < step)
							{
								//printf("%d\n", powerInterval[index]->inner_pos[0]->_y - tram->p3->_y<step);
								//printf("4 ");								
								ifIn = true;
								drawPowerInterval(index, layer_index, ifIn);
								return;
							}
						}
					}
					if (i >= num_power)
						return;
				}
				
				//printf("%d\n", layer_index);
				//printf("(%d,%d)", layer_index, index);

				//直线
				if (ifIn&&powerInterval[index]->inner_pos[last_index_of]->_x >= -orbit_len
					&& powerInterval[index]->inner_pos[last_index_of]->_x <= orbit_len)
				{
					//printf("直线");
					//上侧
					if (powerInterval[index]->inner_pos[last_index_of]->_y > offset_y
						&&powerInterval[index]->inner_pos[last_index_of]->_x <= tram->p4->_x
						&&tram->p3->_x<=orbit_len)
					{
						//printf("上");
						ifIn = false;
					}
					//下侧
					else if (powerInterval[index]->inner_pos[last_index_of]->_y <offset_y
						&&powerInterval[index]->inner_pos[last_index_of]->_x >= tram->p4->_x
						&&tram->p3->_x >= -orbit_len)
					{
						//printf("下");
						ifIn = false;
					}
				}
				//半圆
				if (ifIn&&powerInterval[index]->inner_pos[last_index_of]->_x <= -orbit_len
					&& tram->p1->_y > powerInterval[index]->inner_pos[last_index_of]->_y
					&&tram->p3->_x<=-orbit_len)	 //左侧
				{
					//printf("左");
						ifIn = false;
				}
				else if (ifIn&&powerInterval[index]->inner_pos[last_index_of]->_x >= orbit_len
					&& tram->p1->_y < powerInterval[index]->inner_pos[last_index_of]->_y
					&&tram->p3->_x>=orbit_len)	//右侧
				{
					//printf("右");
					ifIn = false;
				}  
			
			
					//printf("(%d,%d)\n", powerInterval[index]->inner_pos[last_index_of]->_x >= -orbit_len, powerInterval[index]->inner_pos[last_index_of]->_x <= orbit_len);
					//printf("(%lf,%lf)\n", powerInterval[index]->inner_pos[last_index_of]->_x, orbit_len);
					drawPowerInterval(index, layer_index, ifIn);
					
			}
			else
			{
			while (!ifIn)
			{
				int i = 0;
				for (i = 0; i < num_power; i++)
				{
					index = modelLayer[layer_index]->powerInterval[i];
					last_index_of = powerInterval[index]->inner_pos->Count - 1;
					drawPowerInterval(index, layer_index, ifIn);
					//printf("%d\n", index);
					if (powerInterval[index]->inner_pos[last_index_of]->_x >= -orbit_len
						&& powerInterval[index]->inner_pos[last_index_of]->_x <= orbit_len)
					{
						//直线上
						if (powerInterval[index]->inner_pos[last_index_of]->_y > offset_y
							&&powerInterval[index]->inner_pos[last_index_of]->_y < tram->p4->_y
							&&powerInterval[index]->inner_pos[last_index_of]->_x>= tram->p4->_x
							&&powerInterval[index]->inner_pos[last_index_of]->_x-tram->p4->_x   <= step)
						{
							ifIn = true;
							drawPowerInterval(index, layer_index, ifIn);
							return;
						}
						//直线下
						if (powerInterval[index]->inner_pos[last_index_of]->_y < offset_y
							&&powerInterval[index]->inner_pos[last_index_of]->_y > tram->p4->_y
							&&powerInterval[index]->inner_pos[last_index_of]->_x <= tram->p4->_x
							&&tram->p4->_x-powerInterval[index]->inner_pos[last_index_of]->_x   <= step)

						{
							//printf("2 ");
							ifIn = true;
							drawPowerInterval(index, layer_index, ifIn);
							return;
						}
					}
					else if (powerInterval[index]->inner_pos[last_index_of]->_x < -orbit_len) {
						//左弧
						if (tram->p4->_x < -orbit_len && tram->p1->_y <= powerInterval[index]->inner_pos[last_index_of]->_y
							&&powerInterval[index]->inner_pos[last_index_of]->_y-tram->p1->_y   <= step)
						{
							//printf("3 ");
							ifIn = true;
							drawPowerInterval(index, layer_index, ifIn);
							return;
						}
					}
					else if (powerInterval[index]->inner_pos[last_index_of]->_x >= -orbit_len)
					{
						//右弧
						if (tram->p4->_x > orbit_len &&tram->p4->_y >= powerInterval[index]->inner_pos[last_index_of]->_y
							&&tram->p4->_y -powerInterval[index]->inner_pos[last_index_of]->_y  <= step)
						{
							//printf("4 ");								
							ifIn = true;
							drawPowerInterval(index, layer_index, ifIn);
							return;
						}
					}
				}
				if (i >= num_power)
					return;
			}

			//直线
			if (ifIn&&powerInterval[index]->inner_pos[last_index_of]->_x >= -orbit_len
				&& powerInterval[index]->inner_pos[last_index_of]->_x <= orbit_len)
			{
				//上侧
				if (powerInterval[index]->inner_pos[last_index_of]->_y > offset_y
					&&powerInterval[index]->inner_pos[last_index_of]->_x >= tram->p3->_x)
				{
					//printf("上");
					ifIn = false;
				}
				//下侧
				else if (powerInterval[index]->inner_pos[last_index_of]->_y < offset_y
					&&powerInterval[index]->inner_pos[last_index_of]->_x <= tram->p3->_x)
				{
					//printf("下");
					ifIn = false;
				}
			}
			//半圆
			if (ifIn&&powerInterval[index]->inner_pos[0]->_x < -orbit_len
				&& tram->p3->_y < powerInterval[index]->inner_pos[0]->_y
				&&tram->p4->_x<-orbit_len)	 //左侧
			{
				//printf("左");
				ifIn = false;
			}
			else if (ifIn&&powerInterval[index]->inner_pos[0]->_x > orbit_len
				&& tram->p3->_y > powerInterval[index]->inner_pos[0]->_y
				&&tram->p4->_x>orbit_len)	//右侧
			{
				ifIn = false;
			}


				drawPowerInterval(index, layer_index, ifIn);
		
			}
			
		
		}

		//绘制供电区间
		System::Void drawPowerInterval(int power_index,int layer_index,bool ifIn)
		{
			//printf("(%d,%d)\n", power_index,ifIn);
			int n = powerInterval[power_index]->outer_pos->Count;
			int pre_num_power = 0;
			if (layer_index - 1 >= 0)
			{
				pre_num_power = modelLayer[layer_index - 1]->powerInterval->Count;
			}
			for (int i = 0; i < pre_num_power; i++)
			{
				if (power_index == modelLayer[layer_index - 1]->powerInterval[i])
				{
					//return;
				}
			}
			
			glColor3f(0+ifIn*1.0, 0, 1.0-ifIn*1.0);
			glBegin(GL_LINE_STRIP);
			for (int i = 0; i <n; i++)
			{
				glVertex3f(powerInterval[power_index]->outer_pos[i]->_x, powerInterval[power_index]->outer_pos[i]->_y, 0);
			}
			glEnd();
			glBegin(GL_LINE_STRIP);
			for (int i = 0; i < n; i++)
			{
				glVertex3f(powerInterval[power_index]->inner_pos[i]->_x, powerInterval[power_index]->inner_pos[i]->_y, 0);
			}
			glEnd();
		}

		 /*站点*/
		//显示站点
		System::Void showSites(int layer_index,bool isPositive)
		{
			
			int site_num = modelLayer[layer_index]->sites->Count;
			for (int i = 0; i < site_num; i++)
			{
				bool ifArrive = false;
				int index = modelLayer[layer_index]->sites[i];
				float  x = sites[index]->pos->_x;
				float y = sites[index]->pos->_y;
				if (x <= orbit_len && x >= -orbit_len)
				{
						if (y > offset_y&&tram->p1->_x <= x && tram->p2->_x >= x&&tram->p1->_y>offset_y)
						{
							ifArrive = true;
						}
						else if (y < offset_y&&tram->p1->_x >= x && tram->p2->_x <= x&& tram->p1->_y<offset_y)
						{
							ifArrive = true;
						}	
				}
				if (x < -orbit_len)
				{
					if((tram->p2->_x < -orbit_len || tram->p1->_x < -orbit_len)
						&& ((isPositive && (tram->p3->_y <= y || tram->p2->_y <= y)&& (tram->p4->_y >= y || tram->p1->_y >= y))
						|| (!isPositive && (tram->p1->_y <= y || tram->p4->_y <= y)&& (tram->p3->_y >= y || tram->p2->_y >= y))))
					{
						ifArrive = true;
					}
				}
				else if (x > orbit_len)
				{
					if ((tram->p2->_x>orbit_len||tram->p1->_x>orbit_len)
						&& (tram->p3->_y <= y||tram->p2->_y<=y) 
						&& (tram->p4->_y >= y||tram->p1->_y>=y))
					{
						ifArrive = true;
					}
				}
				
				if (ifArrive)
				{
					 //重复
					GetNextSite(index);
					ouputSiteInfo(index, isPositive);
				}

				drawSites(index,x,y,0.01f + (outer_radius - inner_radius) / 2.00f, ifArrive);
			}

		}
		
		//绘制站点  ifPass 是否到达
		System::Void drawSites(int site_index,float x,float y,float R,bool ifArrive)
		{

			//站点绘制 圆环
			static int n = 20;
			glBegin(GL_POLYGON);
			glColor3f(0.5f+(ifArrive)*(0.5f), 0.7f, 0.7f);
		
			for (int i = 0; i < n; i++)
			{
				glVertex2f(x+(0.01f+R)*cosf(2 * pi*i / n), y+(0.01f+R)*sinf(2 * pi*i / n));   //定义顶点
			}
			glEnd();

			glBegin(GL_POLYGON);

			for (int i = 0; i < n; i++)
			{
				glVertex2f(x + (R-0.01f) * cosf(2 * pi*i / n), y + (R-0.01f) * sinf(2 * pi*i / n));   //定义顶点
			}
			glEnd();
		
			//绘制站点名字
			String^ str(" ");
			str += sites[site_index]->name;
			glColor3f(0.2f, 0.2f, 0.2f);
			static float r = (outer_radius + inner_radius) / 2.00;
			float tmp = sinf(y*(90 / r)*(pi / 180));
			char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);

			if (y>(inner_radius+offset_y)&&x>=-orbit_len&&x<=orbit_len)//直线上部
			{
				glRasterPos2f(x - (str->Length) * 0.02f, inner_radius + offset_y - 0.05f);
				drawCNString(ch);
			}
			else if (y < (-inner_radius + offset_y) && x >= -orbit_len && x <= orbit_len)
			{
				glRasterPos2f(x - (str->Length) * 0.02f, -inner_radius + offset_y + 0.03f);
				drawCNString(ch);
			}
			else if (x < -orbit_len)
			{
				glRasterPos2f(x + (1-tmp)*0.02f, y-tmp*0.05f);
				drawCNString(ch);
			}
			else if(x>orbit_len)
			{
				glRasterPos2f(x -  (str->Length) * 0.03f, y-tmp*0.05f);
				drawCNString(ch);
			}

		}

		//输出到站信息
		System::Void ouputSiteInfo(int index, bool isPositive)
		{
			static int ouputed = -1;
			if (ouputed == index || abs(ouputed - index) > 1)
			{
				return;
			}
			//printf("%d  ", index);
			//printf("%d ", ouputed);
			//正序运行时

			if (isPositive
				&& ((index > 0 && sites[index - 1]->ifArrived != sites[index]->ifArrived)
					|| (index == 0 && sites[index + 1]->ifArrived == sites[index]->ifArrived)
					)
				)
			{
				ouputed = index;
				//printf("@");
				++sites[index]->ifArrived;
				sites[index]->ifArrived %= 2;

				//获取时间速度
				if (sites[index]->ifArrived == 0)//第二次运行到该监测点
				{
					/*
					time_t tt = time(NULL);//这句返回的只是一个时间cuo
					monitorPoint[index]->monitorInfo->second = localtime(&tt);
					monitorPoint[index]->monitorInfo->second_step = step;
					SendMonitorSignal(index);
					*/
				}
				else
				{
					/*
					time_t tt = time(NULL);//这句返回的只是一个时间cuo
					monitorPoint[index]->monitorInfo->first = localtime(&tt);
					monitorPoint[index]->monitorInfo->first_step = step;
					*/
				}
				//printf("\n");
			}
			else if
				(!isPositive
					&& ((index < (sites->Count - 1) && sites[index + 1]->ifArrived != sites[index]->ifArrived)
						|| (index == (sites->Count - 1) && sites[index - 1]->ifArrived == sites[index]->ifArrived)
						)
					)
			{
				ouputed = index;
				//printf("@");
				++sites[index]->ifArrived;
				sites[index]->ifArrived %= 2;
				//获取时间速度
				if (sites[index]->ifArrived == 0)//第二次运行到该监测点
				{
					/*
					time_t tt = time(NULL);//这句返回的只是一个时间cuo
					monitorPoint[index]->monitorInfo->second = localtime(&tt);
					monitorPoint[index]->monitorInfo->second_step = step;
					SendMonitorSignal(index);
					*/
				}
				else
				{
					/*
					time_t tt = time(NULL);//这句返回的只是一个时间cuo
					monitorPoint[index]->monitorInfo->first = localtime(&tt);
					monitorPoint[index]->monitorInfo->first_step = step;
					*/
				}
				//printf("\n");

			}

			//printf("（%d， ", ouputed);
			//printf(" %d）\n", monitorPoint[ouputed]->isPassed);
		}

		//绘制文字显示
		#define MAX_CHAR  128
		void drawCNString(const char* str) {
			int len;
			wchar_t* wstring;
			HDC hDC = wglGetCurrentDC();
			GLuint list = glGenLists(1);

			// 计算字符的个数
			// 如果是双字节字符的（比如中文字符），两个字节才算一个字符
			// 否则一个字节算一个字符
			len = 0;
			for (int i = 0; str[i] != '\0'; ++i)
			{
				if (IsDBCSLeadByte(str[i]))
					++i;
				++len;
			}

			// 将混合字符转化为宽字符
			wstring = (wchar_t*)malloc((len+1) * sizeof(wchar_t));
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

		//有轨电车运行  isPositive 是否为正序
		System::Void Running(bool isPositive)
		{
			//弧度=角度*Pi/180;
			static GLfloat angle = 180 * (pi / 180);
			static GLfloat r_angle = 0 * (pi / 180);

			static bool turnRight = false;
			//static bool goStraight = false;
			static float  R =outer_radius;
			static float r = inner_radius;
			static float l =orbit_len;		

			static GLfloat Xstep = 0.0f;
				/*
				if (isPositive&&step<=0.0f)
			{
				return;
			}
				*/
			
			total_step += step;
			 //正序
			if (isPositive) {
				//直线轨道部分运行
				if ((tram->p1->_x + tram->p2->_x) / 2 >= -l
					&& (tram->p1->_x + tram->p2->_x) / 2 <= l)
				{
					//上部分   ->
					if (tram->p1->_y > (r + offset_y))
					{
						Xstep = step;
						if ((tram->p1->_x + tram->p2->_x) / 2 + Xstep > orbit_len)
						{
							float tmp = (tram->p1->_x + tram->p2->_x) / 2;
							GLfloat stepAngle = ((tmp + Xstep - orbit_len) / (pi*((r + R) / 2.00))) * 180 * (pi / 180);
							angle -= stepAngle;
							subRunning(straight_to_turn, orbit_len - tmp, angle);
							return;
						}
					}
					//下部分	<-
					else if (tram->p1->_y < (-r + offset_y))
					{
						Xstep = -step;
						if ((tram->p1->_x + tram->p2->_x) / 2 + Xstep < -orbit_len)
						{
							float tmp = (tram->p1->_x + tram->p2->_x) / 2;
							GLfloat stepAngle = (-(tmp + Xstep + orbit_len) / (pi*((r + R) / 2.00f))) * 180 * (pi / 180);
							angle -= stepAngle;
							subRunning(straight_to_turn, -orbit_len + tmp, angle);
							return;
						}
					}
					else
					{
						printf("直线部分运行错误1");
					}
					tram->p1->_x += Xstep;
					tram->p2->_x += Xstep;
					tram->p3->_x += Xstep;
					tram->p4->_x += Xstep;

				}
				//曲线
				else//弯道
				{
					GLfloat stepAngle = (step / (pi*((r + R) / 2.00f))) * 180 * (pi / 180);
					if (step == Xstep || turnRight) {  //右上
						Xstep = 0.0f;
						turnRight = true;
						angle -= stepAngle;
						if (angle - stepAngle < 0.0)
						{
							angle = 0.0;
							subRunning(turn_to_straight_down, (angle - stepAngle)*((r + R) / 2.00f), 0);
						}
						else
						{
							tram->p1->_x = l + radius1 * cosf(angle1 + angle - 90 * (pi / 180));
							tram->p1->_y = offset_y + radius1 * sinf(angle1 + angle - 90 * (pi / 180));
							tram->p4->_x = l + radius2 * cosf(angle2 + angle - 90 * (pi / 180));
							tram->p4->_y = offset_y + radius2 * sinf(angle2 + angle - 90 * (pi / 180));

							tram->p2->_x = l + radius1 * cosf(angle - angle1 - 90 * (pi / 180));
							tram->p2->_y = offset_y + radius1 * sinf(angle - angle1 - 90 * (pi / 180));
							tram->p3->_x = l + radius2 * cosf(angle - angle2 - 90 * (pi / 180));
							tram->p3->_y = offset_y + radius2 * sinf(angle - angle2 - 90 * (pi / 180));
						}
						if (angle <= 0)
						{
							turnRight = false;
							angle = 180 * (pi / 180);
							return;
						}
					}
					else if (-step == Xstep || !turnRight) {	 //左下
						Xstep = 0.0f;
						turnRight = false;
						angle -= stepAngle;
						if (angle - stepAngle < 0.0)
						{
							angle = 0.0;
							subRunning(turn_to_straight_up, (stepAngle - angle)*((r + R) / 2.00f), 0);
						}
						else
						{
							tram->p2->_x = -l + radius1 * cosf(angle + angle1 + 90 * (pi / 180));
							tram->p2->_y = offset_y + radius1 * sinf(angle + angle1 + 90 * (pi / 180));
							tram->p3->_x = -l + radius2 * cosf(angle + angle2 + 90 * (pi / 180));
							tram->p3->_y = offset_y + radius2 * sinf(angle + angle2 + 90 * (pi / 180));

							tram->p1->_x = -l + radius1 * cosf(angle - angle1 + 90 * (pi / 180));
							tram->p1->_y = offset_y + radius1 * sinf(angle - angle1 + 90 * (pi / 180));
							tram->p4->_x = -l + radius2 * cosf(angle - angle2 + 90 * (pi / 180));
							tram->p4->_y = offset_y + radius2 * sinf(angle - angle2 + 90 * (pi / 180));
						}

						if (angle <= 0)
						{
							angle = 180 * (pi / 180);
							turnRight = false;
							return;
						}

					}
				}
			}
			//逆序
			else 
			{	//直线
			if ((tram->p1->_x + tram->p2->_x) / 2 >= -l
				&& (tram->p1->_x + tram->p2->_x) / 2 <= l)
			{
				//上部分   <-
				if (tram->p1->_y > (r + offset_y))
				{
					Xstep = -step;
					if ((tram->p1->_x + tram->p2->_x) / 2 + Xstep < -orbit_len)
					{
						float tmp = (tram->p1->_x + tram->p2->_x) / 2;
						GLfloat stepAngle = (-(tmp + Xstep + orbit_len) / (pi*((r + R) / 2.00))) * 180 * (pi / 180);
						r_angle += stepAngle;
						subRunning(reverse_straight_to_turn, -orbit_len - tmp, angle);

						return;
					}
				}
				//下部分	->
				else if (tram->p1->_y < (-r + offset_y))
				{
					Xstep = step;
					if ((tram->p1->_x + tram->p2->_x) / 2 + Xstep > orbit_len)
					{
						float tmp = (tram->p1->_x + tram->p2->_x) / 2;
						GLfloat stepAngle = ((tmp + Xstep - orbit_len) / (pi*((r + R) / 2.00f))) * 180 * (pi / 180);
						r_angle += stepAngle;
						subRunning(reverse_straight_to_turn, orbit_len - tmp, r_angle);
						return;
					}
				}
				else
				{
					printf("直线部分运行错误1");
				}

				tram->p1->_x += Xstep;
				tram->p2->_x += Xstep;
				tram->p3->_x += Xstep;
				tram->p4->_x += Xstep;

			}
			//弯道
			else
			{
				if (angle!= 180 * (pi / 180))
				{
					r_angle += angle;
					angle = 180 * (pi / 180);
				}

				GLfloat stepAngle = (step / (pi*((r + R) / 2.00f))) * 180 * (pi / 180);
				if (step == Xstep || turnRight) {  //右下
					Xstep = 0.0f;
					turnRight = true;
					r_angle += stepAngle;
					if (r_angle + stepAngle > 180 * (pi / 180))
					{
						r_angle = 180 * (pi / 180);
						subRunning(reverse_turn_to_straight_up, 
							-(r_angle + stepAngle- 180 * (pi / 180))*((r + R) / 2.00f), 180 * (pi / 180)); 
					}
					else
					{
						tram->p1->_x = l + radius1 * cosf(angle1 + r_angle - 90 * (pi / 180));
						tram->p1->_y = offset_y + radius1 * sinf(angle1 + r_angle - 90 * (pi / 180));
						tram->p4->_x = l + radius2 * cosf(angle2 + r_angle - 90 * (pi / 180));
						tram->p4->_y = offset_y + radius2 * sinf(angle2 + r_angle - 90 * (pi / 180));

						tram->p2->_x = l + radius1 * cosf(r_angle - angle1 - 90 * (pi / 180));
						tram->p2->_y = offset_y + radius1 * sinf(r_angle -angle1 - 90 * (pi / 180));
						tram->p3->_x = l + radius2 * cosf(r_angle - angle2 - 90 * (pi / 180));
						tram->p3->_y = offset_y + radius2 * sinf(r_angle - angle2 - 90 * (pi / 180));

					}
					if (r_angle >=180 * (pi / 180))
					{
						turnRight = false;
						r_angle = 0;
						return;
					}
				}
				else if (-step == Xstep || !turnRight) {	 //左上
					Xstep = 0.0f;
					turnRight = false;
					r_angle += stepAngle;
					if (r_angle + stepAngle > 180 * (pi / 180))
					{
						r_angle = 180 * (pi / 180);
						subRunning(reverse_turn_to_straight_down,
							(r_angle + stepAngle - 180 * (pi / 180))*((r + R) / 2.00f), 180 * (pi / 180));
						
					}
					else
					{
						tram->p2->_x = -l + radius1 * cosf(r_angle - angle1 + 90 * (pi / 180));
						tram->p2->_y = offset_y + radius1 * sinf(r_angle - angle1 + 90 * (pi / 180));
						tram->p3->_x = -l + radius2 * cosf(r_angle - angle2 + 90 * (pi / 180));
						tram->p3->_y = offset_y + radius2 * sinf(r_angle - angle2 + 90 * (pi / 180));

						tram->p1->_x = -l + radius1 * cosf(r_angle + angle1 + 90 * (pi / 180));
						tram->p1->_y = offset_y + radius1 * sinf(r_angle + angle1 + 90 * (pi / 180));
						tram->p4->_x = -l + radius2 * cosf(r_angle + angle2 + 90 * (pi / 180));
						tram->p4->_y = offset_y + radius2 * sinf(r_angle + angle2 + 90 * (pi / 180));
					}

					if (r_angle >= 180 * (pi / 180))
					{
						r_angle = 0;
						turnRight = false;
						return;
					}

				}
			}
			}
		}	

		//补充运行	  一步跨越直线部分和弯道部分
		System::Void subRunning(turn_state state,float xstep,float angle)
		{
			static float  R =outer_radius;
			static float r = inner_radius;
			static float l = orbit_len;
			//正序
			if (state==straight_to_turn)
			{
				tram->p1->_x += xstep;
				tram->p2->_x += xstep;
				tram->p3->_x += xstep;
				tram->p4->_x += xstep;

				if (xstep>0)
				{
					tram->p1->_x = l + radius1 * cosf(angle1 + angle - 90 * (pi / 180));
					tram->p1->_y = offset_y + radius1 * sinf(angle1 + angle - 90 * (pi / 180));
					tram->p4->_x = l + radius2 * cosf(angle2 + angle - 90 * (pi / 180));
					tram->p4->_y = offset_y + radius2 * sinf(angle2 + angle - 90 * (pi / 180));

					tram->p2->_x = l + radius1 * cosf(angle - angle1 - 90 * (pi / 180));
					tram->p2->_y = offset_y + radius1 * sinf(angle - angle1 - 90 * (pi / 180));
					tram->p3->_x = l + radius2 * cosf(angle - angle2 - 90 * (pi / 180));
					tram->p3->_y = offset_y + radius2 * sinf(angle - angle2 - 90 * (pi / 180));
		
				}
				else  if(xstep<=0)
				{
					tram->p2->_x = -l + radius1 * cosf(angle + angle1 + 90 * (pi / 180));
					tram->p2->_y = offset_y + radius1 * sinf(angle + angle1 + 90 * (pi / 180));
					tram->p3->_x = -l + radius2 * cosf(angle + angle2 + 90 * (pi / 180));
					tram->p3->_y = offset_y + radius2 * sinf(angle + angle2 + 90 * (pi / 180));

					tram->p1->_x = -l + radius1 * cosf(angle - angle1 + 90 * (pi / 180));
					tram->p1->_y = offset_y + radius1 * sinf(angle - angle1 + 90 * (pi / 180));
					tram->p4->_x = -l + radius2 * cosf(angle - angle2 + 90 * (pi / 180));
					tram->p4->_y = offset_y + radius2 * sinf(angle - angle2 + 90 * (pi / 180));

				}
				
			}
			else if(state==turn_to_straight_down)
			{
				float tmp = R - R / 6;
				tram->p1->_x = l + rsize;
				tram->p1->_y = -(tmp + (R / 6)*(1 - scale_t)) + offset_y;
				tram->p2->_x = l - rsize;
				tram->p2->_y = -(tmp + (R / 6)*(1 - scale_t)) + offset_y;
				tram->p3->_x = l - rsize;
				tram->p3->_y = -(tmp + (R / 6)* scale_t) + offset_y;
				tram->p4->_x = l + rsize;
				tram->p4->_y = -(tmp + (R / 6)* scale_t) + offset_y; 

				tram->p1->_x += xstep;
				tram->p2->_x += xstep;
				tram->p3->_x += xstep;
				tram->p4->_x += xstep;
			}
			else if(state==turn_to_straight_up)
			{
				float tmp = R - R / 6 ;
				tram->p1->_x = -l - rsize;
				tram->p1->_y = tmp+(R/ 6)*(1 - scale_t) + offset_y;
				tram->p2->_x = -l + rsize;
				tram->p2->_y = tmp + (R / 6)*(1 - scale_t) + offset_y;
				tram->p3->_x = -l + rsize;
				tram->p3->_y = tmp + (R / 6)* scale_t + offset_y;
				tram->p4->_x = -l - rsize;
				tram->p4->_y = tmp + (R / 6)* scale_t + offset_y;

				tram->p1->_x += xstep;
				tram->p2->_x += xstep;
				tram->p3->_x += xstep;
				tram->p4->_x += xstep;

				
			}
			 //逆序
			else if (state == reverse_straight_to_turn)
			{
				tram->p1->_x += xstep;
				tram->p2->_x += xstep;
				tram->p3->_x += xstep;
				tram->p4->_x += xstep;

				if (xstep > 0)
				{

					tram->p1->_x = l + radius1 * cosf(angle1 + angle - 90 * (pi / 180));
					tram->p1->_y = offset_y + radius1 * sinf(angle1 + angle - 90 * (pi / 180));
					tram->p4->_x = l + radius2 * cosf(angle2 + angle - 90 * (pi / 180));
					tram->p4->_y = offset_y + radius2 * sinf(angle2 + angle - 90 * (pi / 180));

					tram->p2->_x = l + radius1 * cosf(angle - angle1 - 90 * (pi / 180));
					tram->p2->_y = offset_y + radius1 * sinf(angle - angle1 - 90 * (pi / 180));
					tram->p3->_x = l + radius2 * cosf(angle - angle2 - 90 * (pi / 180));
					tram->p3->_y = offset_y + radius2 * sinf(angle - angle2 - 90 * (pi / 180));
				}
				else  if (xstep <= 0)
				{
					tram->p2->_x = -l + radius1 * cosf(angle - angle1 + 90 * (pi / 180));
					tram->p2->_y = offset_y - radius1 * sinf(angle - angle1 + 90 * (pi / 180));
					tram->p3->_x = -l + radius2 * cosf(angle - angle2 + 90 * (pi / 180));
					tram->p3->_y = offset_y - radius2 * sinf(angle - angle2 + 90 * (pi / 180));

					tram->p1->_x = -l + radius1 * cosf(angle + angle1 + 90 * (pi / 180));
					tram->p1->_y = offset_y - radius1 * sinf(angle + angle1 + 90 * (pi / 180));
					tram->p4->_x = -l + radius2 * cosf(angle + angle2 + 90 * (pi / 180));
					tram->p4->_y = offset_y - radius2 * sinf(angle + angle2 + 90 * (pi / 180));

				}

			}
			else if (state == reverse_turn_to_straight_down)
			{
				float tmp = R - R / 6;
				tram->p1->_x = -l + rsize;
				tram->p1->_y = -(tmp + (R / 6)*(1 - scale_t)) + offset_y;
				tram->p2->_x = -l - rsize;
				tram->p2->_y = -(tmp + (R / 6)*(1 - scale_t)) + offset_y;
				tram->p3->_x = -l - rsize;
				tram->p3->_y = -(tmp + (R / 6)* scale_t) + offset_y;
				tram->p4->_x = -l + rsize;
				tram->p4->_y = -(tmp + (R / 6)* scale_t) + offset_y;

				tram->p1->_x += xstep;
				tram->p2->_x += xstep;
				tram->p3->_x += xstep;
				tram->p4->_x += xstep;
			}
			else if (state == reverse_turn_to_straight_up)
			{
				float tmp = R - R / 6;
				tram->p1->_x = l - rsize;
				tram->p1->_y = tmp + (R / 6)*(1 - scale_t) + offset_y;
				tram->p2->_x = l + rsize;
				tram->p2->_y = tmp + (R / 6)*(1 - scale_t) + offset_y;
				tram->p3->_x = l + rsize;
				tram->p3->_y = tmp + (R / 6)* scale_t + offset_y;
				tram->p4->_x = l - rsize;
				tram->p4->_y = tmp + (R / 6)* scale_t + offset_y;

				tram->p1->_x += xstep;
				tram->p2->_x += xstep;
				tram->p3->_x += xstep;
				tram->p4->_x += xstep;


			}
			
		}

		//刷新缓冲
		System::Void swapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC);
		}

		//旧 供电区间
		System::Void isTramClosePower(GLvoid)
		{
			//左上
			if (tram->p2->_y>0&&((tram->p2->_x >= outer_orbit[0]->_x&&tram->p2->_x <= outer_orbit[0]->_x + interval)
				|| (tram->p1->_x >= outer_orbit[0]->_x&&tram->p1->_x <= outer_orbit[0]->_x + interval)))
				isPower[0] = true;
			else
				isPower[0] =false;

			//右上
			if (tram->p2->_y > 0 && ((tram->p2->_x <= outer_orbit[1]->_x&&tram->p2->_x >= outer_orbit[1]->_x - interval)
				|| (tram->p1->_x <= outer_orbit[1]->_x&&tram->p1->_x >= outer_orbit[1]->_x - interval)))
				isPower[1] = true;
			else
				isPower[1] = false;

			 //右弯
			if (tram->p3->_x >= inner_orbit[12]->_x || tram->p4->_x >= inner_orbit[12]->_x)
				isPower[2] = true;
			else
				isPower[2] = false;

			//右下
			if (tram->p3->_y < 0 && ((tram->p3->_x <= outer_orbit[32]->_x&&tram->p3->_x >= outer_orbit[32]->_x - interval)
				|| (tram->p4->_x <= outer_orbit[32]->_x&&tram->p4->_x >= outer_orbit[32]->_x - interval))  )
				isPower[3] = true;
			else
				isPower[3] = false;

			//左下
			if(tram->p3->_y < 0&&((tram->p3->_x >= outer_orbit[33]->_x&&tram->p3->_x <= outer_orbit[33]->_x + interval)
				|| (tram->p4->_x >= outer_orbit[33]->_x&&tram->p4->_x <= outer_orbit[33]->_x + interval)) )
				isPower[4] = true;
			else
				isPower[4] = false;

			//左弯
			if (tram->p3->_x <= inner_orbit[44]->_x || tram->p4->_x <= inner_orbit[44]->_x)
				isPower[5] = true;
			else
				isPower[5] = false;

		}

		//供电区间控制显示
		System::Void PowerSupplyInterval(GLvoid)
		{
			
			//直线上部左侧
			if (isPower[0] == true) {
				glColor3f(1.0, 0, 0);
				glBegin(GL_LINES);
				glVertex3f(outer_orbit[0]->_x, outer_orbit[0]->_y, outer_orbit[0]->_z);
				glVertex3f(outer_orbit[0]->_x + interval, outer_orbit[0]->_y, outer_orbit[0]->_z);
				glEnd();
				glBegin(GL_LINES);
				glVertex3f(inner_orbit[0]->_x, inner_orbit[0]->_y, inner_orbit[0]->_z);
				glVertex3f(inner_orbit[0]->_x + interval, inner_orbit[0]->_y, inner_orbit[0]->_z);
				glEnd();
			}

			//直线上部右侧
			if (isPower[1] == true) {
				glColor3f(1.0, 0, 0);
				glBegin(GL_LINES);
				glVertex3f(outer_orbit[1]->_x, outer_orbit[1]->_y, outer_orbit[1]->_z);
				glVertex3f(outer_orbit[1]->_x - interval, outer_orbit[1]->_y, outer_orbit[1]->_z);
				glEnd();
				glBegin(GL_LINES);
				glVertex3f(inner_orbit[1]->_x, inner_orbit[1]->_y, inner_orbit[1]->_z);
				glVertex3f(inner_orbit[1]->_x - interval, inner_orbit[1]->_y, inner_orbit[1]->_z);
				glEnd();
			}

			//轨道弯道右侧
			if (isPower[2] == true) {
				glColor3f(1.0, 0, 0);
				glBegin(GL_LINE_STRIP);
				for (int i = 12; i <= 21; ++i)
				{
					glVertex3f(outer_orbit[i]->_x, outer_orbit[i]->_y, outer_orbit[i]->_z);
				}
				glEnd();
				glBegin(GL_LINE_STRIP);
				for (int i = 12; i <= 21; ++i)
				{
					glVertex3f(inner_orbit[i]->_x, inner_orbit[i]->_y, inner_orbit[i]->_z);
				}
				glEnd();
			}

			//直线下部右侧
			if (isPower[3] == true) {
				glColor3f(1.0, 0, 0);
				glBegin(GL_LINES);
				glVertex3f(outer_orbit[32]->_x, outer_orbit[32]->_y, outer_orbit[32]->_z);
				glVertex3f(outer_orbit[32]->_x - interval, outer_orbit[32]->_y, outer_orbit[32]->_z);
				glEnd();
				glBegin(GL_LINES);
				glVertex3f(inner_orbit[32]->_x, inner_orbit[32]->_y, inner_orbit[32]->_z);
				glVertex3f(inner_orbit[32]->_x - interval, inner_orbit[32]->_y, inner_orbit[32]->_z);
				glEnd();
			}			

			//直线下部	左侧
			if (isPower[4] == true) {
				glColor3f(1.0, 0, 0);
				glBegin(GL_LINES);
				glVertex3f(outer_orbit[33]->_x, outer_orbit[33]->_y, outer_orbit[33]->_z);
				glVertex3f(outer_orbit[33]->_x + interval, outer_orbit[33]->_y, outer_orbit[33]->_z);
				glEnd();
				glBegin(GL_LINES);
				glVertex3f(inner_orbit[33]->_x, inner_orbit[33]->_y, inner_orbit[33]->_z);
				glVertex3f(inner_orbit[33]->_x + interval, inner_orbit[33]->_y, inner_orbit[33]->_z);
				glEnd();

			}

			//轨道弯道左侧
			if (isPower[5] == true) {
				glColor3f(1.0, 0, 0);
				glBegin(GL_LINE_STRIP);
				for (int i = 44; i <= 53; ++i)
				{
					glVertex3f(outer_orbit[i]->_x, outer_orbit[i]->_y, outer_orbit[i]->_z);
				}
				glEnd();
				glBegin(GL_LINE_STRIP);
				for (int i = 44; i <= 53; ++i)
				{
					glVertex3f(inner_orbit[i]->_x, inner_orbit[i]->_y, inner_orbit[i]->_z);
				}
				glEnd();
			}
		
		}
	
	private:
		HDC m_hDC;
		HGLRC m_hglrc;	

		char *project_num;//方案编号
		char *line_num; //线路编号
		char *tram_num;//电车编号
		char *track_num;//电车编号
		
		List<Point^> ^outer_orbit;	 //外轨道坐标集合
		List<Point^>^ inner_orbit; //内轨道坐标集合

		List<Site^>^  sites;  //站点
		List<PowerInterval^>^ powerInterval;  //供电区间
		List<MonitorPoint^>^ monitorPoint;	 //监测点
		List<TrafficLight^>^ trafficLight;		  //红绿灯

		List<PowerInterval^> synPowerInterval;

		List<ModelLayer^>^ modelLayer;//模型层

		Tram^ tram;				  //电车
		List<bool> isPower;			//供电区间
		float step;		 //电车每一步的距离

		float route_len;//实际路线总长度
		float scale_route_len;//屏幕路线总长度

		float straight_line_len;//轨道直线部分长度，由用户选择输入
		float curve_radius;//轨道弯道部分半径，由用户输入
		float total_len ;//轨道水平总长度，用户输入计算出来
		GLfloat rsize; //电车长度

		float scale;//轨道根据长度和半径算出的缩放比例尺
		float offset_y ; //轨道在y轴向上的偏移

		float angle1 ;  	 //偏小的角度
		float angle2 ;	 //偏大的角度
		float  radius1;  //偏长的半径
		float  radius2 ;	//偏短的半径

		float outer_radius ;//屏幕上实际的外轨道半径
		float inner_radius ;//屏幕上实际的内轨道半径
		float orbit_len; //屏幕上实际的轨道（上部或下部）直线部分的长度的一半
		float total_dist;	 //屏幕上轨道一圈的距离
		float total_step; //有轨电车起点到终点或者终点到起点的行驶长度

		bool positive_run ;	//是否为正向运动
		bool ifArriveEnd;//是否到达终点

		int layer_index;

		Tram^ end_pos;

		private:ArrayList^fangMes = gcnew ArrayList();

		public:
			String^ GetTerminusSite()
			{
				if (positive_run)
					return sites[sites->Count - 1]->name;
				else
				{
					return sites[0]->name;
				}
			}

			String^ GetNextSite(int  _i)
			{
				static int i = -1;

				if ( _i<-1)	//错误
					return "";
				else if(_i>=0)	//赋值
				{
					i = _i;
					return "";
					
				}
				else if(_i==-1&&i>=0)	//输出站名
				{
					if (positive_run&&(i+1)<sites->Count)
					{
						return sites[i + 1]->name;
					}
					else  if(!positive_run&&(i-1)>=0)
					{
						return sites[i - 1]->name;
					}
					else
					{
						return "";
					}
				}
			}


	protected:	
		~COpenGL(System::Void)
		{
			this->DestroyHandle();
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

		//初始化OpenGL界面  设置轨道长度、半径
		bool initGL(GLvoid)										// All setup for opengl goes here
		{
			glShadeModel(GL_SMOOTH);							// Enable smooth shading
			glClearColor(1.0f, 1.0f, 1.0f, 0.5f);				// 	 背景色
			glClearDepth(1.0f);									// 深度缓冲设置
			(GL_DEPTH_TEST);							// 启用深度测试
			glDepthFunc(GL_LEQUAL);								// 深度测试的类型
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// 很好的透视计算

			project_num = new char('F002');
			DataTable^  table = gcnew DataTable;
			table = ExecuteQuery("SELECT [线路编号] ,[列车编号],[轨道编号] FROM [方案信息] WHERE 方案编号 ='F002' ");
			for (int i = 0; i < table->Rows->Count; i++)
			{
				fangMes->Clear();
				for (int j = 0; j < table->Columns->Count; j++)
				{
					fangMes->Add(table->Rows[i]->ItemArray[j]);
				}

				String ^tmp = fangMes[0]->ToString()->Trim();
				line_num = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				tmp = fangMes[1]->ToString()->Trim();
				tram_num = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				tmp = fangMes[2]->ToString()->Trim();
				track_num = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
			}

			String^ str1 = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)track_num);
			String ^sql = "SELECT [轨道长度], [轨道半径] FROM[轨道信息] WHERE 轨道编号 = '" + str1 + "';";
			DataTable^ table1 = gcnew DataTable;
			table1 = ExecuteQuery(sql);

			for (int j = 0; j < table1->Rows->Count; j++) {

				fangMes->Clear();
				for (int i = 0; i < table1->Columns->Count; i++)
				{
					fangMes->Add(table1->Rows[j]->ItemArray[i]);
				}
				String^ tmp = fangMes[0]->ToString()->Trim();
				const char* ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				float len = atof(ts);
				tmp = fangMes[1]->ToString()->Trim();
				ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				float ra = atof(ts);
				setOrbitSize(len, ra);
			}
			
			//setOrbitSize(6, 6); 
			//reverse_run = false;

			return TRUE;										// Initialisation went ok
		}

		//调整GL窗口的大小并初始化
		GLvoid reSizeGLScene(GLsizei width, GLsizei height)		
		{
			if (height == 0)										// Prevent A Divide By Zero By
			{
				height = 1;										// Making Height Equal One
			}

			glViewport(0, 0, width, height);						// Reset The Current Viewport

			glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
			glLoadIdentity();									// Reset The Projection Matrix

			 //Calculate The Aspect Ratio Of The Window
			gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

			glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
			glLoadIdentity();									// Reset The Modelview Matrix
		}

		//设置轨道大小
		bool setOrbitSize(GLfloat l, GLfloat r)
		{
			if (l > 0 && r > 0)
			{
				straight_line_len = l;
				curve_radius = r;
				total_len = l + r + r;
				return true;
			}
			return false;
		}

		//获取半圆轨道的坐标	  getPointsOfArc(x_turn, offset_y, outer_radius, inner_radius, 3.14f / 2, -3.14f, numOfTurn);
		GLvoid getPointsOfArc(float cx, float cy, float R, float r,	float start_angle,float arc_angle,int num_segments)
 		{
			float theta = arc_angle / float(num_segments);
			//θ现在由弧角计算，-1位是弧刚打开
			//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

			float tangetial_factor = tanf(theta);
			float radial_factor = cosf(theta);

			float x = R * cosf(start_angle);//现在从起始角度开始
			float y = R * sinf(start_angle);
			float a = r * cosf(start_angle);
			float b = r * sinf(start_angle);

			for (int i = 0; i < num_segments; ++i)
			{
				outer_orbit->Add(gcnew Point(x + cx, y + cy));
				inner_orbit->Add(gcnew Point(a + cx, b + cy));

				float tx = -y;											  
				float ty = x;
				x += tx * tangetial_factor;
				y += ty * tangetial_factor;
				x *= radial_factor;
				y *= radial_factor;

				float ta = -b;
				float tb = a;
				a += ta * tangetial_factor;
				b += tb * tangetial_factor;
				a *= radial_factor;
				b *= radial_factor;
			}
		}

		//获取轨道的坐标
		GLvoid getPointsOfOrbit(GLvoid)
		{
			float tmp = curve_radius / straight_line_len;
			if (tmp <0.5)
				scale = 1;
			else if (tmp <=1)
				scale = 1+tmp*1.5f;
			else if (tmp <= 2)
				scale = tmp*1.4f;
			else if (tmp < 3)
				scale = 1.8f + (tmp - 2)*0.5f;
			else
				scale = 2.3f + (tmp - 3)*0.2f;

			scale /= 1.5f;

			outer_radius = curve_radius/((total_len/2.00f)* scale);
			inner_radius = outer_radius-outer_radius/scale_r;

			float x_turn = (straight_line_len/2.00f)/ ((total_len/2.00f)* scale);

			const static int numOfTurn = 180;

			offset_y =0;//= 0.8 - outer_radius;

			outer_orbit->Add(gcnew Point(-x_turn, outer_radius+ offset_y));
			outer_orbit->Add(gcnew Point(x_turn, outer_radius+ offset_y));
			
			inner_orbit->Add(gcnew Point(-x_turn, inner_radius + offset_y));
			inner_orbit->Add(gcnew Point(x_turn, inner_radius + offset_y));

			getPointsOfArc(x_turn, offset_y, outer_radius, inner_radius, 3.14f / 2, -3.14f, numOfTurn);

			outer_orbit->Add(gcnew Point(x_turn, -outer_radius + offset_y));
			outer_orbit->Add(gcnew Point(-x_turn, -outer_radius + offset_y));
			inner_orbit->Add(gcnew Point(x_turn, -inner_radius + offset_y));
			inner_orbit->Add(gcnew Point(-x_turn, -inner_radius + offset_y));

			getPointsOfArc(-x_turn, offset_y, outer_radius, inner_radius, 1.5f*3.14f, -3.14f, numOfTurn);
		}

		//初始化列车的位置以及起始点的位置
		GLvoid initTram(GLvoid)
		{
			rsize = 20.0f / scale_act;
			orbit_len = (straight_line_len / 2.00f) / ((total_len / 2.00f)* scale);

			float  r = outer_radius;
			float l = orbit_len;

			float tmp = r - r / 6;

			tram = gcnew Tram(
				gcnew Point(-l - rsize, tmp + (r / 6)*(1 - scale_t)+offset_y),
				gcnew Point(-l + rsize, tmp + (r / 6)*(1 - scale_t) + offset_y),
				gcnew Point(-l + rsize, tmp + (r / 6)* scale_t + offset_y),
				gcnew Point(-l - rsize, tmp + (r / 6)* scale_t + offset_y)
			);
			angle1 = atan((rsize) / (tram->p1->_y - offset_y));  	 //偏小的角度
			angle2 = atan((rsize) / (tram->p4->_y - offset_y));	 //偏大的角度
			radius1 = (tram->p1->_y - offset_y) / cosf(angle1);  //偏长的半径
			radius2 = (tram->p4->_y - offset_y) / cosf(angle2);	//偏短的半径

			total_step = 0;
			positive_run = true;
			ifArriveEnd = false;

			

			DataTable^  table = gcnew DataTable;	
			String^ str1 = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)tram_num);
			String ^sql = "SELECT TOP 1000 [行驶方向] FROM [列车信息] WHERE 列车编号 = '"+ str1+"';";
			table = ExecuteQuery(sql);
			for (int i = 0; i < table->Rows->Count; i++)
			{
				fangMes->Clear();
				for (int j = 0; j < table->Columns->Count; j++)
				{
					fangMes->Add(table->Rows[i]->ItemArray[j]);
				}
				String ^tmp = fangMes[0]->ToString()->Trim();
				const char* ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				//tram->capacity = atoi(ts);
			}

			tram->passengers_num = 0;
			/*float  r=	curve_radius / (total_len / 2.00);
			float l = straight_line_len / total_len;
			tram = gcnew Tram(
				gcnew Point(-l - rsize,r-r/6+(r/6)*(1-scale_t)),
				gcnew Point(-l + rsize, r - r / 6 + (r / 6)*(1 - scale_t)),
				gcnew Point(-l + rsize, r - r / 6 + (r / 6)* scale_t),
				gcnew Point(-l - rsize, r - r / 6 + (r / 6)* scale_t)
			);	*/  
			/*tram = gcnew Tram(gcnew Point(-9.5 / 15.5f - rsize, 5.8 / 15.5f), gcnew Point(-9.5 / 15.5f + rsize, 5.8 / 15.5f),
				gcnew Point(-9.5 / 15.5f + rsize, 5.8 / 15.5f - rsize), gcnew Point(-9.5 / 15.5f - rsize, 5.8 / 15.5f - rsize));	 */ 
		
			//初始化起始点的位置
			//start = gcnew Point(-orbit_len, (outer_radius + inner_radius) / 2.00);
		
		}

		GLvoid initPowerInterval(GLvoid)
		{
			int numOfPower = 6;

			for (int i = 0; i < numOfPower; ++i)
				isPower.Add(false);
		}

		//模型层保存 初始化轨道信息（站点、监测点、供电区间、红绿灯）
		GLvoid initOrbitInfo(GLvoid)
		{
			 total_dist = orbit_len * 4 + 2 * pi * (outer_radius + inner_radius) / 2;	  //轨道一圈
			//static float actual_scale =  scale;		  	//实际缩放比例
			scale_route_len = route_len / scale_act * total_dist;
			static int layer_num = ceil((float)route_len / scale_act);	//返回大于或者等于指定表达式的最小整数
			//route_len%scale_act==0? 
				//scale_route_len / total_dist == 0 ?
				//(int)(scale_route_len / total_dist) : (int)(scale_route_len / total_dist) + 1;

			//站点
			for each (Site^ s in sites)
			{
				s->scale_dist = s->actual_dist / scale_act * total_dist;//修改后，其他同样需要修改
				//s->scale_dist = s->actual_dist / actual_scale;
			}
			
			//供电区间
			for each (PowerInterval^ p in powerInterval)
			{
				p->scale_dist = p->actual_dist / scale_act * total_dist;
				p->scale_len = p->actual_len / scale_act * total_dist;
			} 
			
		   //监测点
			for each (MonitorPoint^ m in monitorPoint)
			{
				m->scale_dist = m->actual_dist / scale_act * total_dist;
				//m->response_scale_dist = m->response_actual_dist / scale_act * total_dist;
			}
			
			//红绿灯
			for each (TrafficLight^ t in trafficLight)
			{
				t->scale_dist = t->actual_dist / scale_act * total_dist;
			}
			 
			float site_dist = 0;
			float power_dist = 0;
			float monitor_dist = 0;
			float light_dist = 0;

			int site_index = 0;
			int power_index = 0;
			int monitor_index = 0;
			int light_index = 0;
			int layer_index = 0;

			bool site_first = true;
			bool power_first = true;
			bool monitor_first = true;
			bool light_first = true;

			modelLayer = gcnew List<ModelLayer^>(layer_num);

			while (true)
			{
				ModelLayer^ ml = gcnew  ModelLayer();
				modelLayer->Add(ml);	   //注意跨模型层的
				modelLayer[layer_index]->sites = gcnew List<int>();
				modelLayer[layer_index]->powerInterval=gcnew  List<int>();
				modelLayer[layer_index]->monitorPoint = gcnew List<int>();
				modelLayer[layer_index]->trafficLight = gcnew List<int>();
				//站点存入模型层
				while (site_index<sites->Count)
				{
					if ((int)((site_dist+ sites[site_index]->scale_dist) / total_dist) > layer_index)
						break;
					if ((int)((site_dist + sites[site_index]->scale_dist) / total_dist) == layer_index)
					{
						site_dist += sites[site_index]->scale_dist;
						float tmp_dist = site_dist - layer_index * total_dist;	 //计算出站点距离原点的距离
						sites[site_index]->pos=getCoordinate(tmp_dist);
						modelLayer[layer_index]->sites->Add(site_index);
						site_index++;
					}
				}

				static bool ifAcross = false;
				
				//供电区间存入模型层
				while (power_index < powerInterval->Count)
				{
					if (ifAcross&&modelLayer[layer_index]->powerInterval->Count==0) {
						modelLayer[layer_index]->powerInterval->Add(power_index - 1);
						ifAcross = false;
					}
					if ((int)((power_dist + powerInterval[power_index]->scale_dist) / total_dist) > layer_index)
					{
						break;
					}
					if ((int)((power_dist + powerInterval[power_index]->scale_dist) / total_dist) == layer_index)
					{
						powerInterval[power_index]->outer_pos = gcnew List<Point^>();
						powerInterval[power_index]->inner_pos = gcnew List<Point^>();

						power_dist += powerInterval[power_index]->scale_dist;	
						float tmp_dist = power_dist - layer_index * total_dist;
						power_dist += powerInterval[power_index]->scale_len;
						
						if (ifAcross)
							modelLayer[layer_index]->powerInterval->Add(power_index - 1);

						ifAcross = false;

						ifAcross = getPowerSupplyCoordinate(tmp_dist, powerInterval[power_index]->scale_len,
							powerInterval[power_index]->outer_pos,
							powerInterval[power_index]->inner_pos);

						modelLayer[layer_index]->powerInterval->Add(power_index);

						power_index++;

					}
				}

				
				//监测点存入模型层
				while (monitor_index < monitorPoint->Count)
				{
					if ((int)((monitor_dist+ monitorPoint[monitor_index]->scale_dist) / total_dist) > layer_index)
						break;
					if ((int)((monitor_dist + monitorPoint[monitor_index]->scale_dist) / total_dist) == layer_index)
					{
						monitor_dist += monitorPoint[monitor_index]->scale_dist;
						float tmp_dist = monitor_dist - layer_index * total_dist;
						monitorPoint[monitor_index]->pos = getCoordinate(tmp_dist);
						modelLayer[layer_index]->monitorPoint->Add(monitor_index);
						monitor_index++;
					}
				}	

				 //红绿灯存入模型层
				while (light_index < trafficLight->Count)
				{
					if ((int)((light_dist+ trafficLight[light_index]->scale_dist) / total_dist) > layer_index)
						break;
					if ((int)((light_dist + trafficLight[light_index]->scale_dist) / total_dist) == layer_index)
					{
						light_dist += trafficLight[light_index]->scale_dist;
						float tmp_dist = light_dist - layer_index * total_dist;
						trafficLight[light_index]->pos = getCoordinate(tmp_dist);
						modelLayer[layer_index]->trafficLight->Add(light_index);
						light_index++;
					}
				}

				layer_index++;

				if (layer_index>=layer_num)
				{
					break;
				}
				//if (site_index >= sites->Count)
					//break;
				/*
				if (site_index >= sites->Count&&monitor_index >= monitorPoint->Count
					&&light_index >= trafficLight->Count&&power_index >= powerInterval->Count)
					break;
				*/
			}
		}

		//供电区间获取坐标
		bool getPowerSupplyCoordinate(float dist, float len, List<Point^>^ outer, List<Point^>^ inner)
		{
			static GLfloat angle = 180 * (pi / 180);

			Point^ outer_p = gcnew Point();
			Point^ inner_p=gcnew Point();

			static float tmp = (outer_radius + inner_radius) / 2.00f;

			//第一个点
			subGetPowerSupplyCoordinate(dist, outer_p, inner_p);

			outer->Add(outer_p);
			inner->Add(inner_p);
									   
			//第n个点（n>1）
			if (dist+len <= orbit_len * 2) //最后一个点在直线上部
			{
				outer->Add(gcnew Point(dist + len - orbit_len, outer_radius + offset_y));
				inner->Add(gcnew Point(dist + len - orbit_len, inner_radius + offset_y));
				return false;
				
			}		
			else  if (dist+len <= orbit_len * 2 + pi * tmp)	  //最后一个点在弧线右部
			{
				if (outer_p->_x<orbit_len)
				{
					outer->Add(gcnew Point(orbit_len, outer_radius + offset_y));
					inner->Add(gcnew Point(orbit_len, inner_radius + offset_y));
				
				float tmp_dist = dist+len - 2 * orbit_len;
				float angle = (tmp_dist / (pi*tmp))*180;

				int cover = angle;

				for (int i = 0; i < cover; i++)
				{
					outer->Add(outer_orbit[i+2]);
					inner->Add(inner_orbit[i+2]);
				}
				 }
				else
				{
					float tmp_dist = dist - 2 * orbit_len;
					float start_angle = (tmp_dist / (pi*tmp)) * 180;
					tmp_dist = dist+len - 2 * orbit_len;
					float end_angle = (tmp_dist / (pi*tmp)) * 180;

					int start = start_angle;
					int end = end_angle;

					for (int i = 0; i < end-start; i++)
					{
						outer->Add(outer_orbit[2 + start + i]);
						inner->Add(inner_orbit[2 + start + i]);
					}
				}
				return false;
			
			}
			else if (dist+len <= orbit_len * 4 + pi * tmp)//最后一个点在直线下部
			{
				float tmp_dist = dist - 2 * orbit_len - pi * tmp;
				if (outer_p->_x > orbit_len)
				{
					float angle = ((pi * tmp-(dist-2*orbit_len )) / (pi*tmp)) * 180;//(((2*orbit_len+pi*tmp)-(dist-2*orbit_len))/ (pi*tmp)) * 180 ;
					float start_angle= ( (dist - 2 * orbit_len) / (pi*tmp)) * 180 ;
					int start = start_angle;
					int cover = angle;
					for (int i = 0; i < cover; i++)
					{
						outer->Add(outer_orbit[start + 2 + i]);
						inner->Add(inner_orbit[start + 2 + i]);
					}
					outer->Add(gcnew Point(orbit_len, -outer_radius + offset_y));
					inner->Add(gcnew Point(orbit_len, -inner_radius + offset_y));
				}
				else if (outer_p->_x < orbit_len)
				{
					outer->Add(gcnew Point(orbit_len, outer_radius + offset_y));
					inner->Add(gcnew Point(orbit_len, inner_radius + offset_y));

					for (int i = 0; i < 180; i++)
					{
						outer->Add(outer_orbit[2 + i]);
						inner->Add(inner_orbit[ 2 + i]);
					}

					outer->Add(gcnew Point(orbit_len, -outer_radius + offset_y));
					inner->Add(gcnew Point(orbit_len, -inner_radius + offset_y));
				}
				
					Point^ outer_p_1 = gcnew Point();
					Point^ inner_p_1 = gcnew Point();
					subGetPowerSupplyCoordinate(dist + len, outer_p_1, inner_p_1);
					outer->Add(outer_p_1);
					inner->Add(inner_p_1);

				return false;
			}
			else  if (dist+len < orbit_len * 4 + 2 * pi * tmp)	 //最后一个点在弧线左部
			{
				if (outer_p->_x>orbit_len)
				{
					float tmp_dist = dist - 2 * orbit_len;
					float angle = (tmp_dist / (pi*tmp)) * 180;
					int start = angle;
					int cover = 180 - start;
					for (int i = 0; i < cover; i++)
					{
						outer->Add(outer_orbit[2+start + i]);
						inner->Add(inner_orbit[2 + start + i]);
					}
					outer->Add(gcnew Point(orbit_len, -outer_radius + offset_y));
					inner->Add(gcnew Point(orbit_len, -inner_radius + offset_y));

					outer->Add(gcnew Point(-orbit_len, -outer_radius + offset_y));
					inner->Add(gcnew Point(-orbit_len, -inner_radius + offset_y));

					tmp_dist = dist + len - 4 * orbit_len - pi * tmp;
					angle = (tmp_dist / (pi*tmp)) * 180;

					cover = angle;

					for (int i = 0; i < cover; i++)
					{
						outer->Add(outer_orbit[184 + i]);
						inner->Add(inner_orbit[184 + i]);
					}
				}
				else if (outer_p->_x>=-orbit_len)
				{
					outer->Add(gcnew Point(-orbit_len, -outer_radius + offset_y));
					inner->Add(gcnew Point(-orbit_len, -inner_radius + offset_y));

					float tmp_dist = dist+len - 4 * orbit_len - pi * tmp;
					float angle = (tmp_dist / (pi*tmp)) * 180 ;

					int cover = angle;

					for (int i = 0; i < cover; i++)
					{
						outer->Add(outer_orbit[184 + i]);
						inner->Add(inner_orbit[184 + i]);
					}
					return false;
				}
				else
				{
					float tmp_dist = dist - 4 * orbit_len - pi * tmp;
					float angle = (tmp_dist / (pi*tmp)) * 180;
					int start = angle;
					tmp_dist = dist +len - 4 * orbit_len - pi * tmp;
					angle = (tmp_dist / (pi*tmp)) * 180 ;
					int end = angle;

					for (int i = 0; i < end-start; i++)
					{
						outer->Add(outer_orbit[184 + start + i]);
						inner->Add(inner_orbit[184 + start + i]);
					}
				}
				return false;
			}
			else  if (dist + len<= orbit_len * 6 + 2 * pi * tmp)   //最后一个点在下一层直线上部
			{
				if (outer_p->_x > -orbit_len)
			{
				outer->Add(gcnew Point(-orbit_len, -outer_radius + offset_y));
				inner->Add(gcnew Point(-orbit_len, -inner_radius + offset_y));

				float tmp_dist = dist + len - 4 * orbit_len - pi * tmp;
				float angle = (tmp_dist / (pi*tmp)) * 180;

				int cover = angle;

				for (int i = 0; i < cover; i++)
				{
					outer->Add(outer_orbit[184 + i]);
					inner->Add(inner_orbit[184 + i]);
				}
			}
				else
				{
				float tmp_dist = dist - 4 * orbit_len - pi * tmp;
				float angle = (tmp_dist / (pi*tmp)) * 180;
				int start = angle;

				for (int i = 0; i < 180 - start; i++)
				{
					outer->Add(outer_orbit[184 + start + i]);
					inner->Add(inner_orbit[184 + start + i]);
				}
			}

				outer->Add(gcnew Point(-orbit_len, outer_radius + offset_y));
				inner->Add(gcnew Point(-orbit_len, inner_radius + offset_y));

				outer->Add(gcnew Point(dist + len - orbit_len * 5 - tmp * pi * 2, outer_radius + offset_y));
				inner->Add(gcnew Point(dist + len - orbit_len * 5 - tmp * pi * 2, inner_radius + offset_y));

				return true;
			}	  
			else if (dist + len <= orbit_len * 6 + 3 * pi*tmp)	 //最后一个点在下一层弧线右部
			{
			if (outer_p->_x > -orbit_len)
			{
				outer->Add(gcnew Point(-orbit_len, -outer_radius + offset_y));
				inner->Add(gcnew Point(-orbit_len, -inner_radius + offset_y));

				for (int i = 0; i < 180; i++)
				{
					outer->Add(outer_orbit[184 + i]);
					inner->Add(inner_orbit[184 + i]);
				}

				outer->Add(gcnew Point(-orbit_len, outer_radius + offset_y));
				inner->Add(gcnew Point(-orbit_len, inner_radius + offset_y));
				outer->Add(gcnew Point(orbit_len, outer_radius + offset_y));
				inner->Add(gcnew Point(orbit_len, inner_radius + offset_y));

				float tmp_dist = len - 2 * orbit_len - tmp * pi - (orbit_len + outer_p->_x);
				float angle = (tmp_dist / (pi*tmp)) * 180;

				int cover = angle;
				for (int i = 0; i < cover; i++)
				{
					outer->Add(outer_orbit[2 + i]);
					inner->Add(inner_orbit[2 + i]);
				}
			}
			else  if (outer_p->_x < -orbit_len)
			{
				float tmp_dist = dist - 4 * orbit_len - tmp * pi;
				float angle = (tmp_dist / (pi*tmp)) * 180;
				int start = angle;

				for (int i = 0; i < 180 - start; i++)
				{
					outer->Add(outer_orbit[184 + start + i]);
					inner->Add(inner_orbit[184 + start + i]);
				}

				outer->Add(gcnew Point(-orbit_len, outer_radius + offset_y));
				inner->Add(gcnew Point(-orbit_len, inner_radius + offset_y));
				outer->Add(gcnew Point(orbit_len, outer_radius + offset_y));
				inner->Add(gcnew Point(orbit_len, inner_radius + offset_y));

				float tmp_dist2 = 4 * orbit_len + 2 * tmp*pi - dist;
				tmp_dist = len - 2 * orbit_len - tmp_dist2;
				angle = (tmp_dist / (pi*tmp)) * 180;

				int cover = angle;
				for (int i = 0; i < cover; i++)
				{
					outer->Add(outer_orbit[2 + i]);
					inner->Add(inner_orbit[2 + i]);
				}

			}
			return true;
			}		 
			else
			{
				printf("获取坐标失败2\n");
				
			}
			return false;

		}

		//辅助供电区间获取坐标
		void  subGetPowerSupplyCoordinate(float dist, Point^ outer_p, Point^ inner_p)
		{
			static GLfloat angle = 180 * (pi / 180);
			static float tmp = (outer_radius + inner_radius) / 2.00f;
			if (dist <= orbit_len * 2)
			{
				outer_p->_x = -orbit_len + dist;
				outer_p->_y = outer_radius + offset_y;
				inner_p->_x = -orbit_len + dist;
				inner_p->_y = inner_radius + offset_y;
				
			}
			else  if (dist <= orbit_len * 2 + pi *tmp)
			{
				float tmp_dist = dist - 2 * orbit_len;
				float angle = (tmp_dist / (pi*(outer_radius+inner_radius)/2.00)) * 180 * (pi / 180);

				outer_p->_x = orbit_len + outer_radius * sinf(angle);
				outer_p->_y = outer_radius * cosf(angle) + offset_y;

				

				inner_p->_x = orbit_len + inner_radius * sinf(angle);
				inner_p->_y = inner_radius * cosf(angle) + offset_y;
			
			}
			else if (dist <= orbit_len * 4 + pi * tmp)
			{
				float tmp_dist = dist - 2 * orbit_len - pi * tmp;

				outer_p->_x = orbit_len - tmp_dist;
				outer_p->_y = -outer_radius + offset_y;

				inner_p->_x= orbit_len - tmp_dist;
				inner_p->_y = -inner_radius + offset_y;
			}
			else  if (dist < orbit_len * 4 + 2 * pi * tmp)
			{
				float tmp_dist = dist - 4 * orbit_len - pi * tmp;
				float angle = (tmp_dist / (pi*(outer_radius + inner_radius) / 2.00)) * 180 * (pi / 180);
				//float angle = (tmp_dist / (pi*outer_radius)) * 180 * (pi / 180);

				outer_p->_x= -orbit_len - outer_radius * sinf(angle);
				outer_p->_y= -outer_radius * cosf(angle) + offset_y;

				//angle = (tmp_dist / (pi*inner_radius)) * 180 * (pi / 180);

				inner_p->_x = -orbit_len - inner_radius * sinf(angle);
				inner_p->_y = -inner_radius * cosf(angle) + offset_y;
	
			}
			else
			{
				printf("获取坐标失败3\n");
			}
		}

		//由距离获取坐标
		Point^ getCoordinate(float dist)
		{
			//start = gcnew Point(-orbit_len, (outer_radius + inner_radius) / 2.00);
				//弧度=角度*Pi/180;
			static GLfloat angle = 180 * (pi / 180);
			Point^ p;
			static float tmp = (outer_radius + inner_radius) / 2.00f;
			if (dist<=orbit_len*2)
			{
				p = gcnew Point(-orbit_len+dist, offset_y + tmp);
				return p;
			}
			else  if(dist<=orbit_len*2+pi*tmp)
			{
				float tmp_dist = dist - 2 * orbit_len;
				float angle = (tmp_dist / (pi*tmp)) * 180 * (pi / 180);
				float x = orbit_len + tmp * sinf(angle);
				float y = tmp *cosf(angle)+offset_y;
				p = gcnew Point(x,y);
				return p;
			}
			else if (dist<= orbit_len * 4 + pi * tmp)
			{
				float tmp_dist = dist - 2 * orbit_len-pi*tmp;
				p = gcnew Point(orbit_len-tmp_dist,-tmp+offset_y );
				return p;
			}
			else  if (dist < orbit_len * 4 + 2*pi * tmp)
			{
				float tmp_dist = dist - 4 * orbit_len - pi * tmp;
				float angle = (tmp_dist / (pi*tmp)) * 180 * (pi / 180);
				float x = -orbit_len - tmp * sinf(angle);
				float y = -tmp * cosf(angle) + offset_y;
				p = gcnew Point(x, y);
				return p;
			}
			else
			{
				printf("获取坐标失败1\n");
				
			}
			return p;
		}

		//自定义查询数据库函数
		System::Data::DataTable^ ExecuteQuery(String ^sqlStr) 
		{
			String^ cmd = String::Format("Data Source=localhost;Initial Catalog=列车数据库;Integrated Security=True");
			/*
			Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=E:\项目\列车数据库.mdf;Integrated Security=True;Connect Timeout=30
			*/
			SqlConnection^ con = gcnew SqlConnection(cmd);
			con->Open();
			SqlDataAdapter^ da = gcnew SqlDataAdapter(sqlStr, cmd);
			DataTable^ dt = gcnew DataTable;
			da->Fill(dt);
			con->Close();
			return dt;
		 }

	};
}  