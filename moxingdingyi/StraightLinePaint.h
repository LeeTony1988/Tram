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

	//վ��
	ref class Site {
	public:
		String	^ name;
		String^site_no;
		GLfloat actual_dist;	//������һ��վ�������ʼ���ʵ�ʾ���
		GLfloat scale_dist;//��Ļ�ϵľ���
		Point^ pos;
		bool ifArrived = false;//�Ƿ񵽴�վ��
		bool ifIn = false;//����ʱΪ�Ƿ�����վ��Ϊ����վ�䣬����ʱΪ�Ƿ�����վ��Ϊ�յ��վ��
		int arrivedTram_no;//��վ�г���������������
		int arrivedTram_no1;//��վ�г�������������
		int stayTime;//��վͣ��ʱ��
		int times;
		int run_time;//վ������ʱ��
		float v = 0;
		List<int>^up_people=gcnew List<int>();//�ϳ�����
		List<int>^down_people = gcnew List<int>();//�³�����
		List<int>^peoples = gcnew List<int>();//������
	};

	//�й�糵
	ref class Tram
	{
	public:
		Point^ p1, ^p2, ^p3, ^p4, ^p5, ^p6;		 //��˳ʱ��6����
		int capacity=150;	//�糵����
		int passengers_num;	   //�˿���Ŀ
		bool positive_run;//��ʻ����
		bool finish = false;//��������ɲ�����
		int hasPassed=0;
		float rate;//�г�ʵʱ������
		float avg_rate=0.0f;//�г�ƽ��������
		float min_rate=0.0f;//�г���С������
		int tram_no;
		float v = 0.0f;//�г��ٶ�
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
		List<Site^>^  sites;  //����վ��
		List<Site^>^  sites1;//����վ��
		Tram^tram;//�г�
		List<Tram^>^ trams=gcnew List<Tram^>();

		String^project_num;//�������
		char *line_num; //��·���
		char *tram_num;//�糵���
		float road_len;//��·�ܳ���
		float scale_len=3.6f;//��Ļ��·�ܳ���
		float scale;
		float path_width = 0.02;//������
		float orbit_len = 1.8f;//��Ļһ�볤��
		float stand_len = 1.6f;//�߼�վ��ͼһ��ĳ���

		float tram_width = 0.03f;//�г�һ�볤��
		float tram_height = 0.03f;//�г��߶�
		bool positive_run=true;//��ʻ����
		float step;//��ʻ����
		float total_step;//����ʻ·��

		int tram_no = 0;//�����г����
		int tram_no1 = 0;//�����г����


	  public:
		// ��ʼ����ͼ����
		StraightLinePaint(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight, int x, int y)
		{
			CreateParams^ cp = gcnew CreateParams();	  //CreateParams �����ش����һЩ����

			// ���ô����ϵ�λ��
			cp->X = x;
			cp->Y = y;
			cp->Height = iHeight;
			cp->Width = iWidth;
			//ָ������Ϊ������
			cp->Parent = parentForm->Handle;
			// ����ָ���������Ӷ���ʹ�����OpenGL���޼�����
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			// ͨ��cp���õĲ���������ʵ�ʴ���
			this->CreateHandle(cp);

			m_hDC = GetDC((HWND)this->Handle.ToPointer());//��ȡ�������ڵľ��

			//������ڴ����ɹ�
			if (m_hDC)
			{
				//����ɫ�ظ�ʽ����
				mySetPixelFormat(m_hDC);
				//����GL���ڴ�С
				reSizeGLScene(iWidth, iHeight);
				//��ʼ��OpenGL����  ��ȡ��·��š��г���š����ù�����ȡ��뾶
				initGL("P001");
				//��ȡ��·���ȡ�վ����Ϣ
				DB_assign_value();

				//��ʼ����·����
				initLine();

				//վ��������ʼ��
				initSitePeople();

				//��ʼ���г���Ϣ
				initTram(true);
			}
		}

		//�ص�������ʵʱ����ͼ��
		System::Void Render(System::Void)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// �����Ļ����Ȼ�����
			glLoadIdentity();// ���õ�ǰģ����ͼ����
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

			//����ͬһʱ�̵������г�
			for (int i = 0; i < trams->Count; i++){
				drawTram(i);
			}
			
			for (int i = 0; i < trams->Count; i++){
				running(trams[i]);
			}
		}

		//ˢ�»���
		System::Void swapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC);
		}

		//�����ݿ��ȡ���ݣ���ȡ��·����route_len������վ����Ϣ��վ������ʱ��
	    ArrayList^fangMes = gcnew ArrayList();
		System::Void DB_assign_value()
		{
			DataTable^ table1 = gcnew DataTable;
			String^ str1 = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)line_num);//����·��Ż�ȡ��·��Ϣ
			String ^sql = "SELECT [��·�ܳ���] FROM [road_info] WHERE ��·��� = '" + str1 + "';";
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


			//վ��
			sql = "SELECT [վ������], [վ�����],[վ����]FROM[stand_info] WHERE ��·��� = '" + str1 + "' ORDER BY վ����;";
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
			
			//����վ��
			sql = "SELECT [վ������], [վ�����],[վ����]FROM[stand_info] WHERE ��·��� = '" + str1 + "' ORDER BY վ���� DESC;";
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

			//��ȡվ������ʱ��
			sql = "SELECT [վ��ͣ��ʱ��], [վ������ʱ��] FROM[standBet_info] WHERE ������� = '" + "P001" + "' AND �г����='T001';";
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

			//��ȡվ������ʱ��
			sql = "SELECT [վ��ͣ��ʱ��], [վ������ʱ��] FROM[standBet_info] WHERE ������� = '" + "P001" + "' AND �г����='T001' ORDER BY վ���� DESC;";
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

		//��ʼ��վ������
		System::Void initLine(){
			int site_index = 0;
			int site1_index = sites1->Count-1;
			float site_dist = 0.0f;
			float total_dist = 0.0f;
			scale = scale_len / road_len;

			//��ȡ��Ļ���볤��
			//վ��
			for each (Site^ s in sites)
			{
				s->scale_dist = s->actual_dist*scale;
			}

			for each (Site^ s in sites1)
			{
				s->scale_dist = s->actual_dist*scale;
			}

			//����վ�㼯��sites
			while (site_index<sites->Count)
			{
					site_dist += sites[site_index]->scale_dist;
					sites[site_index]->pos = gcnew Point(site_dist - orbit_len, -0.11f);     //��ȡվ���������
					sites1[site1_index]->pos = gcnew Point(site_dist - orbit_len, -0.39f);     //��ȡվ���������
					if (site_index < sites->Count - 1){
						//���վ�����в���
						sites[site_index]->v = sites[site_index+1]->scale_dist / sites[site_index]->run_time;
						sites1[site_index]->v = sites1[site_index]->scale_dist / sites1[site_index + 1]->run_time;
					}
					
					site_index++;
					site1_index--;
			}
		}

		//��ʾվ��
		System::Void showSites(){
			for (int i = 0; i < sites->Count;i++)
			{
				for (int j = 0; j < trams->Count; j++){
					//����
					if (trams[j]->positive_run){
						if (trams[j]->p5->_x >= sites[i]->pos->_x&&trams[j]->hasPassed == i){
							sites[i]->ifArrived = true;//�г���վ
							sites[i]->arrivedTram_no = j;
							sites[i]->arrivedTram_no1 = trams[j]->tram_no;
							trams[j]->v = 0;
							trams[j]->hasPassed++;
						}
					}
					//����
					else{
						if (trams[j]->p5->_x <= sites1[i]->pos->_x&&trams[j]->hasPassed == i){
							sites1[i]->ifArrived = true;//�г���վ
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

		//����վ��  ifPass �Ƿ񵽴x��yΪԲ������ֵ
		System::Void drawSites(int site_index, float x, float y, float R, bool ifArrive)
		{
			//վ����� Բ��
			static int n = 20;
			glBegin(GL_POLYGON);
			glColor3f(0.5f + (ifArrive)*(0.5f), 0.7f, 0.7f);
			//�⻷
			for (int i = 0; i < n; i++)
			{
				glVertex2f(x + R*cosf(2 * pi*i / n), y + R*sinf(2 * pi*i / n));   //��ȡ20������Բ�Ķ���
			}
			glEnd();

			glBegin(GL_POLYGON);
			//�ڻ�
			for (int i = 0; i < n; i++)
			{
				glVertex2f(x + (R - 0.005f) * cosf(2 * pi*i / n), y + (R - 0.005f) * sinf(2 * pi*i / n));   //��ȡ20������Բ�Ķ���
			}
			glEnd();
			
		}

		//վ��������ʼ��
		Random^random = gcnew Random();
		System::Void initSitePeople(){
			//����վ���������ʼ��
			for (int i = 0; i < sites->Count; i++){
				if (i < sites->Count - 1){
					for (int j = 0; j < 28; j++){
						//�߷�ʱ�ο�����
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
				//���Ϊ�յ�վ���ϳ�����Ϊ0
				else{
					for (int j = 0; j < 28; j++){
						sites[i]->up_people->Add(0);
						sites[i]->down_people->Add(0);
						sites[i]->peoples->Add(0);
					}
					
				}
			}
			//����վ���������ʼ��
			for (int i = 0; i < sites1->Count; i++){
				if (i < sites1->Count - 1){
					for (int j = 0; j < 28; j++){
						//�߷�ʱ�ο�����
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
				//���Ϊ�յ�վ���ϳ�����Ϊ0
				else{
					for (int j = 0; j < 28; j++){
						sites1[i]->up_people->Add(0);
						sites1[i]->down_people->Add(0);
						sites1[i]->peoples->Add(0);
					}
					
				}
			}
		}

		//����վ������,վ��������isPositive����,time_dexʱ���
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

		//�������
		System::Void drawPath(){
			//�����ɫ
			glColor3f(0.3f, 0.6f, 1.0f);

			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

			//������ֱ�߹��
			glBegin(GL_LINES);
			glVertex2f(-orbit_len, -0.1f);
			glVertex2f(orbit_len, -0.1f);
			glEnd();
			glBegin(GL_LINES);
			glVertex2f(orbit_len, -0.1f - path_width);
			glVertex2f(-orbit_len, -0.1f - path_width);
			glEnd();
			

			//������ֱ�߹��
			glBegin(GL_LINES);
			glVertex2f(-orbit_len, -0.38f);
			glVertex2f(orbit_len, -0.38f);
			glEnd();
			glBegin(GL_LINES);
			glVertex2f(orbit_len, -0.38f - path_width);
			glVertex2f(-orbit_len, -0.38f - path_width);
			glEnd();
			
		}

		//�����߼�վ��ͼ
		System::Void showStand(){
			//����վ������
			String^ str;
			int site_num = sites->Count;
			int name_max = sites[0]->name->Length;//վ���������ֵ
			//ÿ��վ��ļ��
			float delta_x = 2*stand_len / site_num;
			//��ʼվ�������ֵ
			float x = -stand_len;
			float dist_x = 0.0f;
			float dist_x1 = 0.0f;
			float R = 0.02f;//վ��Բ�뾶
			float r = 0.015f;//վ��Բ�뾶

			//����վ�㼯�ϣ���ȡվ���������ֵ
			for (int site_index = 0; site_index < site_num; site_index++){
				if (name_max < sites[site_index]->name->Length){
					name_max = sites[site_index]->name->Length;
				}
			}

			//�����ϲ�վ�㼯��
			for (int site_index = 0; site_index < site_num; site_index++){
				//����վ������
				glColor3f(0.2f, 0.2f, 0.2f);
				str = sites[site_index]->name;
				//����������ʾλ��
				float y = 0.45f;//��һ��������ʾ��������
				for (int i = 0; i < str->Length; i++){
					String^str1("");
					str1 += str[i];
					char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
					glRasterPos2f(x + dist_x, y);
					drawCNString(ch);
					y = y - 0.06f;
				}

				//�����ϲ�վ��Բ
				glColor3f(0.0f + sites[site_index]->ifArrived*1.0f, 0.5f - sites[site_index]->ifArrived*0.5f, 0.5f - sites[site_index]->ifArrived*0.5f); //������ɫ
				glBegin(GL_POLYGON);//��ʼ��Բ
				for (int i = 0; i < 20; ++i)
					glVertex2f(x + dist_x + 0.025f + R*cos(2 * pi / 20 * i), 0.55f + R*sin(2 * pi / 20 * i));//Բ������
				glEnd();
				glBegin(GL_POLYGON);//��ʼ��Բ
				for (int i = 0; i < 20; ++i)
					glVertex2f(x + dist_x + 0.025f + r*cos(2 * pi / 20 * i), 0.55f + r*sin(2 * pi / 20 * i));//Բ������
				glEnd();

				//�����г���վͼ��
				if (sites[site_index]->ifArrived){
					glColor3f(1.0f, 0.0f, 0.0f); //������ɫ
					glBegin(GL_POLYGON);//��ʼ��Բ
					for (int i = 0; i < 20; ++i)
						glVertex2f(x + dist_x + 0.025f + 0.025f*cos(2 * pi / 20 * i), 0.59f + 0.025f*sin(2 * pi / 20 * i));//Բ������
					glEnd();
					String^str1("");
					str1 += (sites[site_index]->arrivedTram_no1);
					char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
					glRasterPos2f(x + dist_x+0.016f , 0.575f);
					drawCNString(ch);
				}
			
				//�����г�վ��ͼ��
				if (site_index < site_num - 1&&sites[site_index]->ifIn&&!sites[site_index + 1]->ifArrived){
					glColor3f(1.0f, 0.0f, 0.0f); //������ɫ
					glBegin(GL_POLYGON);//��ʼ��Բ
					for (int i = 0; i < 20; ++i)
						glVertex2f(x + dist_x + 0.025f + 0.025f*cos(2 * pi / 20 * i) + delta_x / 2, 0.59f + 0.025f*sin(2 * pi / 20 * i));//Բ������
					glEnd();
					String^str1("");
					str1 += (sites[site_index]->arrivedTram_no1);
					char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
					glRasterPos2f(x + dist_x + 0.016f + delta_x / 2, 0.575f);
					drawCNString(ch);
				}

				if (site_index < site_num - 1){
					//�����ϲ�����
					glColor3f(0.0f + sites[site_index]->ifIn*1.0f, 0.5f - sites[site_index]->ifIn*0.5f, 0.5f - sites[site_index]->ifIn*0.5f); //������ɫ
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
			//�����²�վ�㼯��
			for (int site_index = site_num-1; site_index >=0; site_index--){
				//�����²�վ��Բ
				glColor3f(0.0f + sites1[site_index]->ifArrived*1.0f, 0.5f - sites1[site_index]->ifArrived*0.5f, 0.5f - sites1[site_index]->ifArrived*0.5f); //������ɫ
				glBegin(GL_POLYGON);//��ʼ��Բ
				for (int i = 0; i < 20; ++i)
					glVertex2f(x + dist_x1 + 0.025f + R*cos(2 * pi / 20 * i), 0.55f - 0.06f*name_max - 0.08f + R*sin(2 * pi / 20 * i));//Բ������
				glEnd();
				glBegin(GL_POLYGON);//��ʼ��Բ
				for (int i = 0; i < 20; ++i)
					glVertex2f(x + dist_x1 + 0.025f + r*cos(2 * pi / 20 * i), 0.55f - 0.06f*name_max - 0.08f + r*sin(2 * pi / 20 * i));//Բ������
				glEnd();

				//�����г���վͼ��
				if (sites1[site_index]->ifArrived){
					glColor3f(1.0f, 0.0f, 0.0f); //������ɫ
					glBegin(GL_POLYGON);//��ʼ��Բ
					for (int i = 0; i < 20; ++i)
						glVertex2f(x + dist_x1 + 0.025f + 0.025f*cos(2 * pi / 20 * i), 0.51f - 0.06f*name_max - 0.08f + 0.025f*sin(2 * pi / 20 * i));//Բ������
					glEnd();
					String^str1("");
					str1 += (sites1[site_index]->arrivedTram_no1);
					char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
					glRasterPos2f(x + dist_x1 + 0.016f, 0.51f - 0.06f*name_max - 0.08f - 0.025f);
					drawCNString(ch);
				}

				//�����г�վ��ͼ��
				if (site_index >0 && sites1[site_index]->ifIn&&!sites1[site_index]->ifArrived){
					glColor3f(1.0f, 0.0f, 0.0f); //������ɫ
					glBegin(GL_POLYGON);//��ʼ��Բ
					for (int i = 0; i < 20; ++i)
						glVertex2f(x + dist_x1 + 0.025f + 0.025f*cos(2 * pi / 20 * i) + delta_x / 2, 0.51f - 0.06f*name_max - 0.08f + 0.025f*sin(2 * pi / 20 * i));//Բ������
					glEnd();
					String^str1("");
					str1 += (sites1[site_index-1]->arrivedTram_no1);
					char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
					glRasterPos2f(x + dist_x1 + 0.016f + delta_x / 2, 0.51f - 0.06f*name_max - 0.08f - 0.025f);
					drawCNString(ch);
				}

				if (site_index > 0){
					glColor3f(0.0f + sites1[site_index]->ifIn*1.0f, 0.5f - sites1[site_index]->ifIn*0.5f, 0.5f - sites1[site_index]->ifIn*0.5f); //������ɫ
					glLineStipple(2, 0x5555);
					glEnable(GL_LINE_STIPPLE);
					//�����²�����
					glBegin(GL_LINES);
					glVertex2f(x + dist_x1 + 0.025f + R, 0.55f - 0.06f*name_max - 0.08f);
					glVertex2f(x + dist_x1 + 0.025f + delta_x - R, 0.55f - 0.06f*name_max - 0.08f);
					glEnd();
					glDisable(GL_LINE_STIPPLE);
				}
				dist_x1 = dist_x1 + delta_x;
			}
		}

		//���Ƶ糵
		System::Void drawTram(int tram_index){
			//�г�����δ��ɻ����г�
			if (!trams[tram_index]->finish){
				//�����й�糵
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

		//�г����к���
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

		//���ò���
		Void setVelocity(float newStep){
			step = newStep;
		}

		//����������ʾ
        #define MAX_CHAR  128
		void drawCNString(const char* str) {
			int len;
			wchar_t* wstring;
			HDC hDC = wglGetCurrentDC();
			GLuint list = glGenLists(1);

			// �����ַ��ĸ���
			len = 0;
			for (int i = 0; str[i] != '\0'; ++i)
			{
				// �����˫�ֽ��ַ��ģ����������ַ����������ֽڲ���һ���ַ�
				// ����һ���ֽ���һ���ַ�
				if (IsDBCSLeadByte(str[i]))
					++i;
				++len;
			}

			// ������ַ�ת��Ϊ���ַ�
			wstring = (wchar_t*)malloc((len + 1) * sizeof(wchar_t));
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

		//����г�����ʼ���г���λ���Լ���ʼ���λ��
		GLvoid initTram(bool positive_run)
		{
			float tmp;//�������������

			total_step = 0;
			//��ʼ���г�λ��
			if (positive_run){
				//����
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
				//����
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
		//�����������ͷŶ���
		~StraightLinePaint(System::Void)
		{
			this->DestroyHandle();//���ٴ���
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

		//����GL���ڵĴ�С����ʼ��
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

		//��ʼ��OpenGL����
		bool initGL(String^project_num)										// All setup for opengl goes here
		{
			glShadeModel(GL_SMOOTH);							// Enable smooth shading
			glClearColor(1.0f, 1.0f, 1.0f, 0.5f);				// 	 ����ɫ
			glClearDepth(1.0f);									// ��Ȼ�������
			(GL_DEPTH_TEST);							// ������Ȳ���
			glDepthFunc(GL_LEQUAL);								// ��Ȳ��Ե�����
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// �ܺõ�͸�Ӽ���

			DataTable^  table = gcnew DataTable;
			String^sql1 = "SELECT [��·���] ,[�г����] FROM [project_info] WHERE ������� ='" + project_num + "' ";
			table = ExecuteQuery(sql1);
			for (int i = 0; i < table->Rows->Count; i++)
			{
				fangMes->Clear();
				for (int j = 0; j < table->Columns->Count; j++)
				{
					fangMes->Add(table->Rows[i]->ItemArray[j]);
				}

				//��ȡ��·���
				String ^tmp = fangMes[0]->ToString()->Trim();
				line_num = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				//��ȡ�г����
				tmp = fangMes[1]->ToString()->Trim();
				tram_num = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
			}

			return TRUE;										// Initialisation went ok
		}

		

		//�Զ����ѯ���ݿ⺯��
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