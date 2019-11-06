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

	//վ��
	ref class Site {
	public:
		String	^ name;
		GLfloat actual_dist;	//������һ��վ�������ʼ���ʵ�ʾ���
		GLfloat scale_dist;//��Ļ�ϵľ���
		Point^ pos;
		int ifArrived;//�Ƿ񾭹�

	};	  
	
	//��������
	ref class PowerInterval{
	public:
		String	^name;
		GLfloat actual_dist;	//������һ����������ĩ�˻�����ʼ���ʵ�ʾ���
		GLfloat scale_dist;//��Ļ�ϵ�ʵ�ʾ���
		GLfloat actual_len;//����ʵ�ʳ���
		GLfloat scale_len;//������Ļ�ϵĳ���
		List<Point^>^ outer_pos;//�������������
		List<Point^>^ inner_pos;//������ڹ������
		bool isPassed;//�Ƿ񾭹�
	};

	//�����Ϣ
	ref class  MonitorInfo 
	{
	public:
		//��һ��
		tm* first;	//ʱ��
		float first_step;
		//�ڶ���
		tm* second;		//ʱ��
		float second_step;
	};

	//����
	ref class MonitorPoint 
	{
	public:
		String	 ^name;
		GLfloat actual_dist;	//������һ�����������ʼ���ʵ�ʾ���
		GLfloat scale_dist;//��Ļ�ϵľ���
		Point^ pos;
		GLfloat response_actual_dist;//��Ӧʵ�ʾ���
		GLfloat response_scale_dist;  //��Ӧ��Ļ�ϵľ���
		int isPassed;//�Ƿ��Ѿ������ü���
		MonitorInfo^ monitorInfo;
	};

	//���̵�
	ref class TrafficLight {
	public:
		String	 ^name;
		GLfloat actual_dist;	//������һ��վ�������ʼ���ʵ�ʾ���
		GLfloat scale_dist;//��Ļ�ϵľ���
		Point^ pos;
		bool isGreenLight;//�Ƿ��̵���
		float greenTime;
		float redTime;
		//void start() { isGreenLight = true; }//�糵��ʼ����ʱĬ���̵���
	};

	 //�й�糵
	ref class Tram
	{
	public:
		Point^ p1, ^p2, ^p3, ^p4;		 //��˳ʱ���ĸ���
		int capacity;	//�糵����
		int passengers_num;	   //�˿���Ŀ
		Tram() {}
		Tram(Point^ _p1, Point^ _p2, Point^ _p3, Point^ _p4)
		{
			p1 = _p1;
			p2 = _p2;
			p3 = _p3;
			p4 = _p4;
		}
	};
	
	//ģ�Ͳ�
	ref class ModelLayer {
	public:
		List<int>^  sites;  //վ��
		List<int>^ powerInterval; //��������
		List<int>^ monitorPoint;	 //����
		List<int>^ trafficLight;		  //���̵�
	};

	//������ʻ��״̬
	enum turn_state
	{
		straight_to_turn,
		turn_to_straight_down,
		turn_to_straight_up,
		reverse_straight_to_turn,
		reverse_turn_to_straight_down,
		reverse_turn_to_straight_up
	};

	const int numOfPoints = 364;	 //����ĵ�ĸ���
	const float pi = 3.141592f;
	const float scale_r = 6.00f;	 //�ڹ���뾶�������뾶�ı���
	const float scale_t = 0.20f;	  //�й�糵�ڹ�����������Ŀհ׼��
	const float scale_act = 500.0f;//ʵ����·����һȦ�����ű��� 8400/500.0=16.8Ȧ
	const GLfloat interval = 2 / 15.5f;		 //�������䳤��
	
	public ref class COpenGL : public System::Windows::Forms::NativeWindow
	{
	public:
		COpenGL(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight,int x,int y)
		{
			CreateParams^ cp = gcnew CreateParams;	  //CreateParams �����ش����һЩ����

			// ���ô����ϵ�λ��
			cp->X = x;
			cp->Y = y;
			cp->Height = iHeight;
			cp->Width = iWidth;

			//ָ������Ϊ������
			cp->Parent = parentForm->Handle;

			// ����ָ���������Ӷ���ʹ�����OpenGL���޼�����
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			// ����ʵ�ʴ���
			this->CreateHandle(cp);

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			//���λ�������ʼ��
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
			String ^sql = "SELECT [��·�ܳ���] FROM [��·��Ϣ] WHERE ��·��� = '"+ str1 +"';";
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
			

			//վ��
			sql = "SELECT [վ������], [վ�����]FROM[վ����Ϣ] WHERE ��·��� = '"+ str1+"';";
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
		
			 //��������
			 sql = "SELECT [������], [���䳤��] , [�����������]FROM[����������Ϣ]WHERE ��·��� = '"+str1+"';";
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

			//����
			sql = "SELECT [������], [���ڼ������]FROM[������Ϣ] WHERE ��·��� = '"+str1+"';";
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


			//���̵�
			sql = "SELECT [���̵Ʊ��], [���ʱ��], [�̵�ʱ��], [���ں��̵ƾ���]FROM[���̵���Ϣ]WHERE ��·��� = '"+str1+"';";
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
				l->name = "���̵�" + i;
				l->actual_dist = 550;
				l->isGreenLight = true;
				trafficLight->Add(l);
			}
			*/
		}

		//���������ٶ�
		System::Void setVelocity(float newVel)
		{
				step = newVel;
		}

		bool IfArriveEnd()
		{
			return ifArriveEnd;
		}

		//�ص�����
		System::Void Render(System::Void)
		{
			static const GLfloat z = 0.9f;
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear screen and depth buffer
			glLoadIdentity();									// Reset the current modelview matrix
		
			glTranslatef(0.0f, 0.0f, -1.5f);

			//�����ɫ
			glColor3f(0.3f, 0.6f, 1.0f);	
			
			//��������ģʽ
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			//�ӽ�λ��	//-2.0f
			//glTranslatef(0.0f, 0.0f, -2.0f); 

			//��������
			glBegin(GL_POLYGON);
			for each (Point^ var in outer_orbit)
			{
				glVertex3f(var->_x, var->_y, var->_z);
			}
			glEnd();

			//�ڹ������
			glBegin(GL_POLYGON);
			for each (Point^ var in inner_orbit)
			{
				glVertex3f(var->_x, var->_y, var->_z);
			}
			glEnd();
			glPushMatrix();

			//�й�糵��ɫ
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
				printf("��%lf��%lf��", tram->p1->_x, tram->p1->_y);
			}
			*/
			//printf("%d ", tram->p3->_y < 0.0f);
			//scale_route_len = 5.0f;
			/*if (total_step<=scale_route_len)
			{
				Running(true);//����
			}
			else 
			{	
				Running(false);	//����
			}
				*/
		}

		//����ģ�Ͳ�
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
			//printf("��%lf��%lf��\n", tram->p1->_x, tram->p2->_y);
			static bool isFirstLayer = true;
			int layer_num = modelLayer->Count;
			int tmp = 2*positive_run -1;
			static float remain = layer_num * total_dist-scale_route_len;
			
			
			//�����ʱΪģ�Ͳ�ڼ���
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
				else   //����
				{
					isFirstLayer = false;
					layer_index = layer_num - 1-((int)((total_step +0.25) / (orbit_len * 4.00f + pi * (outer_radius + inner_radius))));
					layer_index = layer_index < 0 ? 0 : layer_index;
				}
			}

			


			//printf("%d\n", layer_index);
			//����
			showSites(layer_index,positive_run);
			showPowerInterval(layer_index, positive_run);
			showMonitorPoint(layer_index,positive_run);
			showTrafficLight(layer_index);

			//��Ӧ
			return positive_run;
		}

		int getModleLayerNum()
		{
			return layer_index;

		}
		  
		/*���̵�*/
		//��ʾ���̵�
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
		
		//���ƺ��̵�
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

		//�������ƺ��̵�
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
		
		//���̵�ת���ƹ�
		System::Void turnLight()
		{
			int lignt_num = trafficLight->Count;
			for (int i = 0; i < lignt_num; i++)
			{
				trafficLight[i]->isGreenLight = !trafficLight[i]->isGreenLight;
			}
		}

		/*����*/
		//��ʾ����
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
				//�޸�
				
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

		//���Ƽ���
		System::Void drawMonitorPoint(int monitor_index,float _x,float _y, bool ifPass)
		{
			glColor3f(1.0f, 0.6f - (int)ifPass*0.6f, 0);

			//ֱ��
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
			//��Բ
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
	
		//���Ƽ����ͷ
		System::Void drawArrow(Point^ pStart, Point^ pEnd, float len, int alpha)
		{
			Point^ arrow=gcnew Point(0,0);
			//���� �� �ǣ���򵥵�һ�����������ͼʾ���Ѿ�չʾ���ؼ����� atan2 ��������������棩   
			double angle = atan2((double)(pStart->_y - pEnd->_y), (double)(pStart->_x - pEnd->_x));

			glBegin(GL_LINES);
			glVertex3f(pStart->_x,pStart->_y,0);
			glVertex3f(pEnd->_x, pEnd->_y, 0.0);
			glEnd();

			//������Ǳߵ���һ�˵Ķ˵�λ�ã�����Ļ��������Ҫ����ͷ��ָ��Ҳ����pStart��pEnd��λ�ã� 
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

		//��������Ϣ
		System::Void ouputMonitorInfo(int index,bool isPositive)
		{
			static int ouputed = -1;
			if (ouputed == index||abs(ouputed-index)>1)
			{
				return;
			}
			//printf("%d  ", index);
			//printf("%d ", ouputed);
			//��������ʱ
			
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
				 //��ȡʱ���ٶ�
				if (monitorPoint[index]->isPassed == 0)//�ڶ������е��ü���
				{
					time_t tt = time(NULL);//��䷵�ص�ֻ��һ��ʱ��cuo
					monitorPoint[index]->monitorInfo->second = localtime(&tt);
					monitorPoint[index]->monitorInfo->second_step = step;
					SendMonitorSignal(index);
				}
				else
				{
					time_t tt = time(NULL);//��䷵�ص�ֻ��һ��ʱ��cuo
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
				//��ȡʱ���ٶ�
				if (monitorPoint[index]->isPassed == 0)//�ڶ������е��ü���
				{
					time_t tt = time(NULL);//��䷵�ص�ֻ��һ��ʱ��cuo
					monitorPoint[index]->monitorInfo->second = localtime(&tt);
					monitorPoint[index]->monitorInfo->second_step = step;
					SendMonitorSignal(index);
				}
				else
				{
					time_t tt = time(NULL);//��䷵�ص�ֻ��һ��ʱ��cuo
					monitorPoint[index]->monitorInfo->first = localtime(&tt);
					monitorPoint[index]->monitorInfo->first_step = step;
				}
				//printf("\n");

			}

			//printf("��%d�� ", ouputed);
			//printf(" %d��\n", monitorPoint[ouputed]->isPassed);
		}

	   //���ͼ���źŸ�����
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

		 /*��������*/
		//��ʾ��������
		System::Void showPowerInterval(int layer_index,bool isPositive)
		{
			int num_power = modelLayer[layer_index]->powerInterval->Count;

			static bool ifIn = false; //�Ƿ��ڹ���������
			static int index = -1;	//��i����������
			static int last_index_of = -1;		//��i��������������һ������

			//printf("(%d,%d)", layer_index, index);
			//����
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
						//��ģ�Ͳ� ������������һ���һ���㲻��Ӧ
						int j =layer_index<1?-1: modelLayer[layer_index - 1]->powerInterval->Count - 1;
						if (layer_index  >= 1 && modelLayer[layer_index - 1]->powerInterval->Count>0&&index == modelLayer[layer_index - 1]->powerInterval[j])
						{
							continue;
						}
						//printf("%d\n", index);
						if (powerInterval[index]->inner_pos[0]->_x >= -orbit_len
							&& powerInterval[index]->inner_pos[0]->_x <= orbit_len)
						{
							//ֱ����
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
							//ֱ����
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
							//��
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
							//�һ�
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

				//ֱ��
				if (ifIn&&powerInterval[index]->inner_pos[last_index_of]->_x >= -orbit_len
					&& powerInterval[index]->inner_pos[last_index_of]->_x <= orbit_len)
				{
					//printf("ֱ��");
					//�ϲ�
					if (powerInterval[index]->inner_pos[last_index_of]->_y > offset_y
						&&powerInterval[index]->inner_pos[last_index_of]->_x <= tram->p4->_x
						&&tram->p3->_x<=orbit_len)
					{
						//printf("��");
						ifIn = false;
					}
					//�²�
					else if (powerInterval[index]->inner_pos[last_index_of]->_y <offset_y
						&&powerInterval[index]->inner_pos[last_index_of]->_x >= tram->p4->_x
						&&tram->p3->_x >= -orbit_len)
					{
						//printf("��");
						ifIn = false;
					}
				}
				//��Բ
				if (ifIn&&powerInterval[index]->inner_pos[last_index_of]->_x <= -orbit_len
					&& tram->p1->_y > powerInterval[index]->inner_pos[last_index_of]->_y
					&&tram->p3->_x<=-orbit_len)	 //���
				{
					//printf("��");
						ifIn = false;
				}
				else if (ifIn&&powerInterval[index]->inner_pos[last_index_of]->_x >= orbit_len
					&& tram->p1->_y < powerInterval[index]->inner_pos[last_index_of]->_y
					&&tram->p3->_x>=orbit_len)	//�Ҳ�
				{
					//printf("��");
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
						//ֱ����
						if (powerInterval[index]->inner_pos[last_index_of]->_y > offset_y
							&&powerInterval[index]->inner_pos[last_index_of]->_y < tram->p4->_y
							&&powerInterval[index]->inner_pos[last_index_of]->_x>= tram->p4->_x
							&&powerInterval[index]->inner_pos[last_index_of]->_x-tram->p4->_x   <= step)
						{
							ifIn = true;
							drawPowerInterval(index, layer_index, ifIn);
							return;
						}
						//ֱ����
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
						//��
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
						//�һ�
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

			//ֱ��
			if (ifIn&&powerInterval[index]->inner_pos[last_index_of]->_x >= -orbit_len
				&& powerInterval[index]->inner_pos[last_index_of]->_x <= orbit_len)
			{
				//�ϲ�
				if (powerInterval[index]->inner_pos[last_index_of]->_y > offset_y
					&&powerInterval[index]->inner_pos[last_index_of]->_x >= tram->p3->_x)
				{
					//printf("��");
					ifIn = false;
				}
				//�²�
				else if (powerInterval[index]->inner_pos[last_index_of]->_y < offset_y
					&&powerInterval[index]->inner_pos[last_index_of]->_x <= tram->p3->_x)
				{
					//printf("��");
					ifIn = false;
				}
			}
			//��Բ
			if (ifIn&&powerInterval[index]->inner_pos[0]->_x < -orbit_len
				&& tram->p3->_y < powerInterval[index]->inner_pos[0]->_y
				&&tram->p4->_x<-orbit_len)	 //���
			{
				//printf("��");
				ifIn = false;
			}
			else if (ifIn&&powerInterval[index]->inner_pos[0]->_x > orbit_len
				&& tram->p3->_y > powerInterval[index]->inner_pos[0]->_y
				&&tram->p4->_x>orbit_len)	//�Ҳ�
			{
				ifIn = false;
			}


				drawPowerInterval(index, layer_index, ifIn);
		
			}
			
		
		}

		//���ƹ�������
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

		 /*վ��*/
		//��ʾվ��
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
					 //�ظ�
					GetNextSite(index);
					ouputSiteInfo(index, isPositive);
				}

				drawSites(index,x,y,0.01f + (outer_radius - inner_radius) / 2.00f, ifArrive);
			}

		}
		
		//����վ��  ifPass �Ƿ񵽴�
		System::Void drawSites(int site_index,float x,float y,float R,bool ifArrive)
		{

			//վ����� Բ��
			static int n = 20;
			glBegin(GL_POLYGON);
			glColor3f(0.5f+(ifArrive)*(0.5f), 0.7f, 0.7f);
		
			for (int i = 0; i < n; i++)
			{
				glVertex2f(x+(0.01f+R)*cosf(2 * pi*i / n), y+(0.01f+R)*sinf(2 * pi*i / n));   //���嶥��
			}
			glEnd();

			glBegin(GL_POLYGON);

			for (int i = 0; i < n; i++)
			{
				glVertex2f(x + (R-0.01f) * cosf(2 * pi*i / n), y + (R-0.01f) * sinf(2 * pi*i / n));   //���嶥��
			}
			glEnd();
		
			//����վ������
			String^ str(" ");
			str += sites[site_index]->name;
			glColor3f(0.2f, 0.2f, 0.2f);
			static float r = (outer_radius + inner_radius) / 2.00;
			float tmp = sinf(y*(90 / r)*(pi / 180));
			char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);

			if (y>(inner_radius+offset_y)&&x>=-orbit_len&&x<=orbit_len)//ֱ���ϲ�
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

		//�����վ��Ϣ
		System::Void ouputSiteInfo(int index, bool isPositive)
		{
			static int ouputed = -1;
			if (ouputed == index || abs(ouputed - index) > 1)
			{
				return;
			}
			//printf("%d  ", index);
			//printf("%d ", ouputed);
			//��������ʱ

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

				//��ȡʱ���ٶ�
				if (sites[index]->ifArrived == 0)//�ڶ������е��ü���
				{
					/*
					time_t tt = time(NULL);//��䷵�ص�ֻ��һ��ʱ��cuo
					monitorPoint[index]->monitorInfo->second = localtime(&tt);
					monitorPoint[index]->monitorInfo->second_step = step;
					SendMonitorSignal(index);
					*/
				}
				else
				{
					/*
					time_t tt = time(NULL);//��䷵�ص�ֻ��һ��ʱ��cuo
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
				//��ȡʱ���ٶ�
				if (sites[index]->ifArrived == 0)//�ڶ������е��ü���
				{
					/*
					time_t tt = time(NULL);//��䷵�ص�ֻ��һ��ʱ��cuo
					monitorPoint[index]->monitorInfo->second = localtime(&tt);
					monitorPoint[index]->monitorInfo->second_step = step;
					SendMonitorSignal(index);
					*/
				}
				else
				{
					/*
					time_t tt = time(NULL);//��䷵�ص�ֻ��һ��ʱ��cuo
					monitorPoint[index]->monitorInfo->first = localtime(&tt);
					monitorPoint[index]->monitorInfo->first_step = step;
					*/
				}
				//printf("\n");

			}

			//printf("��%d�� ", ouputed);
			//printf(" %d��\n", monitorPoint[ouputed]->isPassed);
		}

		//����������ʾ
		#define MAX_CHAR  128
		void drawCNString(const char* str) {
			int len;
			wchar_t* wstring;
			HDC hDC = wglGetCurrentDC();
			GLuint list = glGenLists(1);

			// �����ַ��ĸ���
			// �����˫�ֽ��ַ��ģ����������ַ����������ֽڲ���һ���ַ�
			// ����һ���ֽ���һ���ַ�
			len = 0;
			for (int i = 0; str[i] != '\0'; ++i)
			{
				if (IsDBCSLeadByte(str[i]))
					++i;
				++len;
			}

			// ������ַ�ת��Ϊ���ַ�
			wstring = (wchar_t*)malloc((len+1) * sizeof(wchar_t));
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str, -1, wstring, len);
			wstring[len] = L'\0';
	
			// �������ַ�
			for (int i = 0; i < len; ++i)
			{
				wglUseFontBitmapsW(hDC, wstring[i], 1, list);
				glCallList(list);
			}

			// ����������ʱ��Դ
			free(wstring);
			glDeleteLists(list, 1);
		}

		//�й�糵����  isPositive �Ƿ�Ϊ����
		System::Void Running(bool isPositive)
		{
			//����=�Ƕ�*Pi/180;
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
			 //����
			if (isPositive) {
				//ֱ�߹����������
				if ((tram->p1->_x + tram->p2->_x) / 2 >= -l
					&& (tram->p1->_x + tram->p2->_x) / 2 <= l)
				{
					//�ϲ���   ->
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
					//�²���	<-
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
						printf("ֱ�߲������д���1");
					}
					tram->p1->_x += Xstep;
					tram->p2->_x += Xstep;
					tram->p3->_x += Xstep;
					tram->p4->_x += Xstep;

				}
				//����
				else//���
				{
					GLfloat stepAngle = (step / (pi*((r + R) / 2.00f))) * 180 * (pi / 180);
					if (step == Xstep || turnRight) {  //����
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
					else if (-step == Xstep || !turnRight) {	 //����
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
			//����
			else 
			{	//ֱ��
			if ((tram->p1->_x + tram->p2->_x) / 2 >= -l
				&& (tram->p1->_x + tram->p2->_x) / 2 <= l)
			{
				//�ϲ���   <-
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
				//�²���	->
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
					printf("ֱ�߲������д���1");
				}

				tram->p1->_x += Xstep;
				tram->p2->_x += Xstep;
				tram->p3->_x += Xstep;
				tram->p4->_x += Xstep;

			}
			//���
			else
			{
				if (angle!= 180 * (pi / 180))
				{
					r_angle += angle;
					angle = 180 * (pi / 180);
				}

				GLfloat stepAngle = (step / (pi*((r + R) / 2.00f))) * 180 * (pi / 180);
				if (step == Xstep || turnRight) {  //����
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
				else if (-step == Xstep || !turnRight) {	 //����
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

		//��������	  һ����Խֱ�߲��ֺ��������
		System::Void subRunning(turn_state state,float xstep,float angle)
		{
			static float  R =outer_radius;
			static float r = inner_radius;
			static float l = orbit_len;
			//����
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
			 //����
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

		//ˢ�»���
		System::Void swapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC);
		}

		//�� ��������
		System::Void isTramClosePower(GLvoid)
		{
			//����
			if (tram->p2->_y>0&&((tram->p2->_x >= outer_orbit[0]->_x&&tram->p2->_x <= outer_orbit[0]->_x + interval)
				|| (tram->p1->_x >= outer_orbit[0]->_x&&tram->p1->_x <= outer_orbit[0]->_x + interval)))
				isPower[0] = true;
			else
				isPower[0] =false;

			//����
			if (tram->p2->_y > 0 && ((tram->p2->_x <= outer_orbit[1]->_x&&tram->p2->_x >= outer_orbit[1]->_x - interval)
				|| (tram->p1->_x <= outer_orbit[1]->_x&&tram->p1->_x >= outer_orbit[1]->_x - interval)))
				isPower[1] = true;
			else
				isPower[1] = false;

			 //����
			if (tram->p3->_x >= inner_orbit[12]->_x || tram->p4->_x >= inner_orbit[12]->_x)
				isPower[2] = true;
			else
				isPower[2] = false;

			//����
			if (tram->p3->_y < 0 && ((tram->p3->_x <= outer_orbit[32]->_x&&tram->p3->_x >= outer_orbit[32]->_x - interval)
				|| (tram->p4->_x <= outer_orbit[32]->_x&&tram->p4->_x >= outer_orbit[32]->_x - interval))  )
				isPower[3] = true;
			else
				isPower[3] = false;

			//����
			if(tram->p3->_y < 0&&((tram->p3->_x >= outer_orbit[33]->_x&&tram->p3->_x <= outer_orbit[33]->_x + interval)
				|| (tram->p4->_x >= outer_orbit[33]->_x&&tram->p4->_x <= outer_orbit[33]->_x + interval)) )
				isPower[4] = true;
			else
				isPower[4] = false;

			//����
			if (tram->p3->_x <= inner_orbit[44]->_x || tram->p4->_x <= inner_orbit[44]->_x)
				isPower[5] = true;
			else
				isPower[5] = false;

		}

		//�������������ʾ
		System::Void PowerSupplyInterval(GLvoid)
		{
			
			//ֱ���ϲ����
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

			//ֱ���ϲ��Ҳ�
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

			//�������Ҳ�
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

			//ֱ���²��Ҳ�
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

			//ֱ���²�	���
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

			//���������
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

		char *project_num;//�������
		char *line_num; //��·���
		char *tram_num;//�糵���
		char *track_num;//�糵���
		
		List<Point^> ^outer_orbit;	 //�������꼯��
		List<Point^>^ inner_orbit; //�ڹ�����꼯��

		List<Site^>^  sites;  //վ��
		List<PowerInterval^>^ powerInterval;  //��������
		List<MonitorPoint^>^ monitorPoint;	 //����
		List<TrafficLight^>^ trafficLight;		  //���̵�

		List<PowerInterval^> synPowerInterval;

		List<ModelLayer^>^ modelLayer;//ģ�Ͳ�

		Tram^ tram;				  //�糵
		List<bool> isPower;			//��������
		float step;		 //�糵ÿһ���ľ���

		float route_len;//ʵ��·���ܳ���
		float scale_route_len;//��Ļ·���ܳ���

		float straight_line_len;//���ֱ�߲��ֳ��ȣ����û�ѡ������
		float curve_radius;//���������ְ뾶�����û�����
		float total_len ;//���ˮƽ�ܳ��ȣ��û�����������
		GLfloat rsize; //�糵����

		float scale;//������ݳ��ȺͰ뾶��������ű�����
		float offset_y ; //�����y�����ϵ�ƫ��

		float angle1 ;  	 //ƫС�ĽǶ�
		float angle2 ;	 //ƫ��ĽǶ�
		float  radius1;  //ƫ���İ뾶
		float  radius2 ;	//ƫ�̵İ뾶

		float outer_radius ;//��Ļ��ʵ�ʵ������뾶
		float inner_radius ;//��Ļ��ʵ�ʵ��ڹ���뾶
		float orbit_len; //��Ļ��ʵ�ʵĹ�����ϲ����²���ֱ�߲��ֵĳ��ȵ�һ��
		float total_dist;	 //��Ļ�Ϲ��һȦ�ľ���
		float total_step; //�й�糵��㵽�յ�����յ㵽������ʻ����

		bool positive_run ;	//�Ƿ�Ϊ�����˶�
		bool ifArriveEnd;//�Ƿ񵽴��յ�

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

				if ( _i<-1)	//����
					return "";
				else if(_i>=0)	//��ֵ
				{
					i = _i;
					return "";
					
				}
				else if(_i==-1&&i>=0)	//���վ��
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

		//�����ڵ�ɫ�ظ�ʽ����
		GLint mySetPixelFormat(HDC hdc)
		{
			static	PIXELFORMATDESCRIPTOR pfd =				// pfd����Windows������Ҫʲô���Ķ���
			{
				sizeof(PIXELFORMATDESCRIPTOR),				// �����ظ�ʽ�������Ĵ�С
				1,											// �汾��
				PFD_DRAW_TO_WINDOW |						// ��ʽ����֧�ִ���
				PFD_SUPPORT_OPENGL
										//��ʽ����֧��OpenGL
				| PFD_DOUBLEBUFFER,							// ��ʽ����֧��˫����
				PFD_TYPE_RGBA,								// ����RGBA��ʽ
				16,										// ѡ�����ǵ���ɫ���
				0, 0, 0, 0, 0, 0,							// ��ɫλ������
				0,											// No Alpha Buffer
				0,											// Shift Bit Ignored
				0,											// No Accumulation Buffer
				0, 0, 0, 0,									// Accumulation Bits Ignored
				0,//16											// 16Bit Z-Buffer (Depth Buffer)  
				0,											// No Stencil Buffer
				0,											// No Auxiliary Buffer
				PFD_MAIN_PLANE,								// ��ͼ�� Main Drawing Layer
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

		//��ʼ��OpenGL����  ���ù�����ȡ��뾶
		bool initGL(GLvoid)										// All setup for opengl goes here
		{
			glShadeModel(GL_SMOOTH);							// Enable smooth shading
			glClearColor(1.0f, 1.0f, 1.0f, 0.5f);				// 	 ����ɫ
			glClearDepth(1.0f);									// ��Ȼ�������
			(GL_DEPTH_TEST);							// ������Ȳ���
			glDepthFunc(GL_LEQUAL);								// ��Ȳ��Ե�����
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// �ܺõ�͸�Ӽ���

			project_num = new char('F002');
			DataTable^  table = gcnew DataTable;
			table = ExecuteQuery("SELECT [��·���] ,[�г����],[������] FROM [������Ϣ] WHERE ������� ='F002' ");
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
			String ^sql = "SELECT [�������], [����뾶] FROM[�����Ϣ] WHERE ������ = '" + str1 + "';";
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

		//����GL���ڵĴ�С����ʼ��
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

		//���ù����С
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

		//��ȡ��Բ���������	  getPointsOfArc(x_turn, offset_y, outer_radius, inner_radius, 3.14f / 2, -3.14f, numOfTurn);
		GLvoid getPointsOfArc(float cx, float cy, float R, float r,	float start_angle,float arc_angle,int num_segments)
 		{
			float theta = arc_angle / float(num_segments);
			//�������ɻ��Ǽ��㣬-1λ�ǻ��մ�
			//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

			float tangetial_factor = tanf(theta);
			float radial_factor = cosf(theta);

			float x = R * cosf(start_angle);//���ڴ���ʼ�Ƕȿ�ʼ
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

		//��ȡ���������
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

		//��ʼ���г���λ���Լ���ʼ���λ��
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
			angle1 = atan((rsize) / (tram->p1->_y - offset_y));  	 //ƫС�ĽǶ�
			angle2 = atan((rsize) / (tram->p4->_y - offset_y));	 //ƫ��ĽǶ�
			radius1 = (tram->p1->_y - offset_y) / cosf(angle1);  //ƫ���İ뾶
			radius2 = (tram->p4->_y - offset_y) / cosf(angle2);	//ƫ�̵İ뾶

			total_step = 0;
			positive_run = true;
			ifArriveEnd = false;

			

			DataTable^  table = gcnew DataTable;	
			String^ str1 = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)tram_num);
			String ^sql = "SELECT TOP 1000 [��ʻ����] FROM [�г���Ϣ] WHERE �г���� = '"+ str1+"';";
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
		
			//��ʼ����ʼ���λ��
			//start = gcnew Point(-orbit_len, (outer_radius + inner_radius) / 2.00);
		
		}

		GLvoid initPowerInterval(GLvoid)
		{
			int numOfPower = 6;

			for (int i = 0; i < numOfPower; ++i)
				isPower.Add(false);
		}

		//ģ�Ͳ㱣�� ��ʼ�������Ϣ��վ�㡢���㡢�������䡢���̵ƣ�
		GLvoid initOrbitInfo(GLvoid)
		{
			 total_dist = orbit_len * 4 + 2 * pi * (outer_radius + inner_radius) / 2;	  //���һȦ
			//static float actual_scale =  scale;		  	//ʵ�����ű���
			scale_route_len = route_len / scale_act * total_dist;
			static int layer_num = ceil((float)route_len / scale_act);	//���ش��ڻ��ߵ���ָ�����ʽ����С����
			//route_len%scale_act==0? 
				//scale_route_len / total_dist == 0 ?
				//(int)(scale_route_len / total_dist) : (int)(scale_route_len / total_dist) + 1;

			//վ��
			for each (Site^ s in sites)
			{
				s->scale_dist = s->actual_dist / scale_act * total_dist;//�޸ĺ�����ͬ����Ҫ�޸�
				//s->scale_dist = s->actual_dist / actual_scale;
			}
			
			//��������
			for each (PowerInterval^ p in powerInterval)
			{
				p->scale_dist = p->actual_dist / scale_act * total_dist;
				p->scale_len = p->actual_len / scale_act * total_dist;
			} 
			
		   //����
			for each (MonitorPoint^ m in monitorPoint)
			{
				m->scale_dist = m->actual_dist / scale_act * total_dist;
				//m->response_scale_dist = m->response_actual_dist / scale_act * total_dist;
			}
			
			//���̵�
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
				modelLayer->Add(ml);	   //ע���ģ�Ͳ��
				modelLayer[layer_index]->sites = gcnew List<int>();
				modelLayer[layer_index]->powerInterval=gcnew  List<int>();
				modelLayer[layer_index]->monitorPoint = gcnew List<int>();
				modelLayer[layer_index]->trafficLight = gcnew List<int>();
				//վ�����ģ�Ͳ�
				while (site_index<sites->Count)
				{
					if ((int)((site_dist+ sites[site_index]->scale_dist) / total_dist) > layer_index)
						break;
					if ((int)((site_dist + sites[site_index]->scale_dist) / total_dist) == layer_index)
					{
						site_dist += sites[site_index]->scale_dist;
						float tmp_dist = site_dist - layer_index * total_dist;	 //�����վ�����ԭ��ľ���
						sites[site_index]->pos=getCoordinate(tmp_dist);
						modelLayer[layer_index]->sites->Add(site_index);
						site_index++;
					}
				}

				static bool ifAcross = false;
				
				//�����������ģ�Ͳ�
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

				
				//�������ģ�Ͳ�
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

				 //���̵ƴ���ģ�Ͳ�
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

		//���������ȡ����
		bool getPowerSupplyCoordinate(float dist, float len, List<Point^>^ outer, List<Point^>^ inner)
		{
			static GLfloat angle = 180 * (pi / 180);

			Point^ outer_p = gcnew Point();
			Point^ inner_p=gcnew Point();

			static float tmp = (outer_radius + inner_radius) / 2.00f;

			//��һ����
			subGetPowerSupplyCoordinate(dist, outer_p, inner_p);

			outer->Add(outer_p);
			inner->Add(inner_p);
									   
			//��n���㣨n>1��
			if (dist+len <= orbit_len * 2) //���һ������ֱ���ϲ�
			{
				outer->Add(gcnew Point(dist + len - orbit_len, outer_radius + offset_y));
				inner->Add(gcnew Point(dist + len - orbit_len, inner_radius + offset_y));
				return false;
				
			}		
			else  if (dist+len <= orbit_len * 2 + pi * tmp)	  //���һ�����ڻ����Ҳ�
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
			else if (dist+len <= orbit_len * 4 + pi * tmp)//���һ������ֱ���²�
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
			else  if (dist+len < orbit_len * 4 + 2 * pi * tmp)	 //���һ�����ڻ�����
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
			else  if (dist + len<= orbit_len * 6 + 2 * pi * tmp)   //���һ��������һ��ֱ���ϲ�
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
			else if (dist + len <= orbit_len * 6 + 3 * pi*tmp)	 //���һ��������һ�㻡���Ҳ�
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
				printf("��ȡ����ʧ��2\n");
				
			}
			return false;

		}

		//�������������ȡ����
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
				printf("��ȡ����ʧ��3\n");
			}
		}

		//�ɾ����ȡ����
		Point^ getCoordinate(float dist)
		{
			//start = gcnew Point(-orbit_len, (outer_radius + inner_radius) / 2.00);
				//����=�Ƕ�*Pi/180;
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
				printf("��ȡ����ʧ��1\n");
				
			}
			return p;
		}

		//�Զ����ѯ���ݿ⺯��
		System::Data::DataTable^ ExecuteQuery(String ^sqlStr) 
		{
			String^ cmd = String::Format("Data Source=localhost;Initial Catalog=�г����ݿ�;Integrated Security=True");
			/*
			Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=E:\��Ŀ\�г����ݿ�.mdf;Integrated Security=True;Connect Timeout=30
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