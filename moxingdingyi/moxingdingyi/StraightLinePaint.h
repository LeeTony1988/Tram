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

	//վ��
	ref class Site {
	public:
		String	^ name;
		String^site_no;
		GLfloat actual_dist;		//������һ��վ�������ʼ���ʵ�ʾ���
		GLfloat scale_dist;			//��Ļ�ϵľ���
		Point^ pos;
		bool ifArrived = false;		//�Ƿ񵽴�վ��
		bool ifIn = false;			//����ʱΪ�Ƿ�����վ��Ϊ����վ�䣬����ʱΪ�Ƿ�����վ��Ϊ�յ��վ��
		int arrivedTram_no;			//��վ�г���������������
		int arrivedTram_no1;		//��վ�г�������������
		String^arrivedTram_strnum;	//��վ�г��ַ����
		String^ arrivingTram_strnum = nullptr;//Ԥ����վ�г��ַ����

		int stayTime;//��վͣ��ʱ��
		int times;
		int run_time;//վ������ʱ��
		//float v = 0;
		List<int>^up_people = gcnew List<int>();//�ϳ�����
		List<int>^down_people = gcnew List<int>();//�³�����
		List<int>^peoples = gcnew List<int>();//������
	};

	//�й�糵
	ref class Tram
	{
	public:
		//��Ҫ��ʼ������Ϣ
		String^pronum;//�������
		int tram_no;//�����г����
		String^tram_num;//�г����
		Point^ p1, ^p2, ^p3, ^p4, ^p5, ^p6;		 //��˳ʱ��6����
		int capacity = 150;	//�糵����,Ĭ��150�����������ݿ��в�ѯ����
		bool positive_run;//��ʻ����
		List<Site^>^tram_siteinfo = gcnew List<Site^>();//���й�糵��վ�㴦��Ϣ

		bool draw = false;//���Ʊ�־
		bool finish = false;//��������ɲ�����

		int hasPassed = 0;//��¼�糵�Ѿ�ͨ����վ���

		int passengers_num;	   //�˿���Ŀ
		float rate;//�г�ʵʱ������
		float avg_rate = 0.0f;//�г�ƽ��������
		float min_rate = 0.0f;//�г���С������

		float total_step;//�й�糵����ʻ·�̣�����Ϊ��Ļ�ܲ�������ʱû�õ�������Ļ�е�λ������
		float prepos = 0;//��һʱ�̵����ݿ�λ����Ϣ
		float pos = 0;//�����ݿ��ѯ�ĵ糵λ������
		float cal_step = 0;//����ʵ�ʴ洢λ����������������Ļ���Ʋ���
		float velocity = 0;//�г��ٶ�
		float accelerate = 0;//���ٶ�
		float current = 0;//����
		float voltage = 0;//��ѹ

		int oridatanum;//��һ�����ݵ��������
		int datanum;//��ǰ�������
		int maxdatanum;//����������
		float last_pos;//���ݿ�������λ��
		String^timeflow;//��������ʱ�����������ݿ��е�һ������ʱ����Ϊ���
		String^settime;//�����������˹����õ�ʱ�����

		//�����ݿ��е�λ����Ϣת������Ļ����
		void PosTransform(float scale)
		{
			cal_step = (pos - prepos)*scale;
		}

		//������ı�ʱ��Ҫ��������С��λ��
		void ResetPoint(bool direction, float orbitlen,float tramwidth,float tramtopath,float tramheigh,float tmp)
		{
			if (direction)//����
			{
				p1 = gcnew Point(-orbitlen-tramwidth,tmp+tramtopath+tramheigh);
				p2 = gcnew Point(-orbitlen+tramwidth,tmp+tramtopath+tramheigh);
				p3 = gcnew Point(-orbitlen+tramwidth,tmp+tramtopath);
				p4 = gcnew Point(-orbitlen-tramwidth,tmp+tramtopath);
				p5 = gcnew Point(-orbitlen,tmp+tramtopath);
				p6 = gcnew Point(-orbitlen,tmp-tramtopath);
			}
			else       //����
			{
				p1 = gcnew Point(orbitlen + tramwidth, tmp - tramtopath - tramheigh);
				p2 = gcnew Point(orbitlen - tramwidth, tmp - tramtopath - tramheigh);
				p3 = gcnew Point(orbitlen - tramwidth, tmp - tramtopath);
				p4 = gcnew Point(orbitlen + tramwidth, tmp - tramtopath);
				p5 = gcnew Point(orbitlen, tmp + tramtopath);
				p6 = gcnew Point(orbitlen, tmp - tramtopath);
			}

		}
		//���캯��
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

	//���̵�
	ref class Trafficlight
	{
	public:
		int light_no;//�����ֱ��
		String^lightnum;//�洢���

		String^pos_dis;//��λ������
		GLfloat actural_pos;//��ʵ��λ��
		GLfloat screen_pos;//����Ļλ��
		Point^point;
		bool redf = true;//�������־
		bool greenf = false;//�̵�����־
		float redtime;//���ʱ��
		float greentime;//�̵�ʱ��

		GLfloat hight1 = 0.04f;//�����߶�
		GLfloat width1 = 0.04f;//�ƿ�һ��
		GLfloat hight2 = 0.04f;
	public:
		Trafficlight() {}
		Trafficlight(int light_no1, float pos1)
		{
			light_no = light_no1;
			actural_pos = pos1;
		}

	};

	//OpenGL������
	const float pi = 3.141592f;
	public ref class StraightLinePaint : public System::Windows::Forms::NativeWindow
	{

	public:
		HDC m_hDC;
		HGLRC m_hglrc;
		List<Site^>^  sites;  //����վ��
		List<Site^>^  sites1;//����վ��
		Tram^tram;//�г�
		List<Tram^>^ trams = gcnew List<Tram^>();
		List<Trafficlight^>^trlights = gcnew List<Trafficlight^>();

		int runningMode=0;//����ģʽ��0�Ǽ��ż��У�1��ʵʱ��

		char *line_num; //��·���
		//String^project_num;//�������
		
		//ֱ��ͼ
		//char *tram_num;//�糵���
		float road_len;//��·�ܳ��ȣ����ݿ��в�ѯ����
		//float scale_len = 3.6f;//��Ļ��·�ܳ���
		float scale_len = 1.8f;//��Ļ��·�ܳ���
		float scale;//��Ļ���������ݿ��ж���ʵ����·���ȱ�ֵ
		float path_width = 0.01;//������
		//float orbit_len = 1.8f;//��Ļһ�볤��
		float orbit_len = 0.9f;//��Ļһ�볤��
		float tram_to_path = 0.04f;//�������
		//���̵�
		float lig_to_path=0.065f;
		//�߼�վ��ͼ
		//float stand_len = 1.6f;//�߼�վ��ͼһ��ĳ���
		float stand_len = 0.8f;//�߼�վ��ͼһ��ĳ���

		//�г�����
		float tram_width = 0.02f;//�г�һ�볤��
		float tram_height = 0.02f;//�г��߶�

		bool positive_run = true;//��ʻ����
		float step;//��ʻ����
		//float total_step;//����ʻ·��

		int tram_no = 0;//�����г����
		int tram_no1 = 0;//�����г����

		DataTable^restable;//�洢��ѯ���


	public:
		// ��ʼ����ͼ���ݣ���ʼ��OpenGL����
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
				initGL();
				//��ȡ��·���ȡ�վ����Ϣ
				//DB_assign_value();

				//��ʼ����·����
				//initLine();

				//վ��������ʼ��
				//initSitePeople();

				//��ʼ���г���Ϣ
				//initTram(true);
			}
		}

		//�ص�������ʵʱ����ͼ��
		System::Void Render(int modenum)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// �����Ļ����Ȼ�����
			glLoadIdentity();// ���õ�ǰģ����ͼ����
			glTranslatef(0.0f, 0.0f, -1.5f);

			drawPath();//��˫ֱ�߹��
			showSites();//��˫ֱ�߹���ϵ�Բ��վ��
			drawTrafficLight();//�����̵�
			//showStand();//�����߼�վ��ͼ-��վ������
			//glPushMatrix();

			String^str1("");
			str1 += 1;
			char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
			glRasterPos2f(-4.0f, 0);
			drawCNString(ch);

			//����ͬһʱ�̵������г�
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
			else if (modenum == 3)//ʵʱģʽ
			{
				RunSys(trams[0], 0);
				if (!trams[0]->finish)
				{
					drawTram(0);
				}
			}
			showStand();//�����߼�վ��ͼ-��վ������
			glPushMatrix();
			/*for (int i = 0; i < trams->Count; i++) {
				running(trams[i],i);
			}*/
		}

		//ˢ�»���
		System::Void swapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC);
		}

		//���³���������ʵʱ������
		System::Void updatePeopleOnTramAndEmptyRate(Tram^ tram) {
			if (tram->positive_run)//����
			{

			}
		}

		//�����ݿ��ȡ���ݣ���ȡ��·����route_len������վ����Ϣ��վ������ʱ�䡢���̵�
		ArrayList^fangMes = gcnew ArrayList();//�����ݴ�ÿһ�����ݿ�ȡ������Ϣ
		System::Void DB_assign_value()
		{
			DataTable^ table1 = gcnew DataTable;
			String^ str1 = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)line_num);//����·��Ż�ȡ��·��Ϣ
			String ^sql = "SELECT [��·�ܳ���] FROM [��·��Ϣ] WHERE ��·��� = '" + str1 + "';";
			table1 = ExecuteQuery(sql);

			//��ȡ��·����
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

			//��ȡ��·վ�����
			sql = "SELECT [վ������],[վ�����],[վ����] FROM [վ����Ϣ] WHERE ��·��� = '" + str1 + "' ORDER BY վ����;";
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
				if (String::Equals(fangMes[0]->ToString()->Trim(), "ˮӵ��(���칫԰)"))
				{
					s->name = "ˮӵ��";
				}
				else
				{
					s->name = fangMes[0]->ToString()->Trim();//����
				}
				String^ tmp = fangMes[1]->ToString()->Trim();
				const char* ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				s->actual_dist = atof(ts);//����
				s->site_no = fangMes[2]->ToString()->Trim();//վ����
				sites->Add(s);//����վ��
				//sites1->Add(s);//����վ��
			}
			
			//����վ��:�����Ѳ�������û���⡣��������������һ�������ǽ�site1��������site����ʾ����������֪��Ϊɶ
			sql = "SELECT [վ������], [վ�����],[վ����] FROM [վ����Ϣ] WHERE ��·��� = '" + str1 + "' ORDER BY վ����;";
			table1 = ExecuteQuery(sql);
			sites1 = gcnew List<Site^>();
		
			for (int j = 0; j < table1->Rows->Count; j++) {
				Site^ s = gcnew Site();
				fangMes->Clear();
				for (int i = 0; i < table1->Columns->Count; i++)
				{
					fangMes->Add(table1->Rows[j]->ItemArray[i]);
				}
				if (String::Equals(fangMes[0]->ToString()->Trim(), "ˮӵ��(���칫԰)"))
				{
					s->name = "ˮӵ��";
				}
				else
				{
					s->name = fangMes[0]->ToString()->Trim();//վ������
				}
				String^ tmp = fangMes[1]->ToString()->Trim();
				const char* ts = (char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer();
				s->actual_dist = atof(ts);//վ�����
				s->site_no = fangMes[2]->ToString()->Trim();//վ����
				sites1->Add(s);
			}
			
			//���̵�
			sql = "SELECT ���̵Ʊ��,���̵�λ��,���ʱ��,�̵�ʱ��,���ں��̵ƾ��� FROM ���̵���Ϣ WHERE ��·���='" + str1 + "' ORDER BY ���̵Ʊ��;";
			table1 = ExecuteQuery(sql);
			trlights->Clear();
			for (int i = 0; i < table1->Rows->Count; i++)
			{
				Trafficlight^trlight = gcnew Trafficlight(i+1,float::Parse(table1->Rows[i]->ItemArray[4]->ToString()));
				trlight->lightnum = table1->Rows[i]->ItemArray[0]->ToString();//���ַ����
				trlight->pos_dis = table1->Rows[i]->ItemArray[1]->ToString();//��λ������
				trlight->redtime = float::Parse(table1->Rows[i]->ItemArray[2]->ToString());//���ʱ��
				trlight->greentime= float::Parse(table1->Rows[i]->ItemArray[3]->ToString());//�̵�ʱ��

				trlights->Add(trlight);
			}

			/*
			//��ȡվ������ʱ��
			sql = "SELECT [վ��ͣ��ʱ��], [վ������ʱ��] FROM[�г�վ��������Ϣ] WHERE ������� = '" + "P001" + "' AND �г����='T001';";
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
			}*/
			
		}

		//��ʼ��վ�����ꡢ���̵�����
		System::Void initLine() {
			//վ��
			int site_index = 0;
			//int site1_index = sites1->Count - 1;
			int site1_index = 0;
			float site_dist = 0.0f;
			float total_dist = 0.0f;
			scale = scale_len / road_len;//��Ļ�ܳ�(�Զ���1.8f)����·�ܳ�֮��

			//��ȡ��Ļ���볤��
			for each (Site^ s in sites)
			{
				s->scale_dist = s->actual_dist*scale;//�������վ�������һվ��ľ��루���㵽������Ļ������
			}

			for each (Site^ s in sites1)
			{
				s->scale_dist = s->actual_dist*scale;
			}
			//����վ�㼯��sites,��ȡÿ��վ����;�е�����λ��
			while (site_index < sites->Count)
			{
				site_dist += sites[site_index]->scale_dist;
				sites[site_index]->pos = gcnew Point(site_dist - orbit_len, 0.0f);     //��ȡվ���������
				sites1[site1_index]->pos = gcnew Point(site_dist - orbit_len, -0.1f);     //��ȡվ��������꣬����վ��y��������ƫ��һ��
				/*
				if (site_index < sites->Count - 1) {
					//���վ�����в���
					sites[site_index]->v = sites[site_index + 1]->scale_dist / sites[site_index]->run_time;
					sites1[site_index]->v = sites1[site_index]->scale_dist / sites1[site_index + 1]->run_time;
				}
				*/
				site_index++;
				//site1_index--;
				site1_index++;
			}

			//���̵�
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

		//����վ����Ϣ
		System::Void showSites() {
			GLfloat out_R = 0.02f;//վ���⻷����

			//������վ��ĵ�վ��־λ���㣬�����±�ȡ��ǰʱ�̵�վվ��
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
					//����
					if (trams[j]->positive_run) {
						//�г�����վ��
						if (trams[j]->p5->_x >= sites[i]->pos->_x - out_R && trams[j]->p5->_x < sites[i]->pos->_x + out_R && trams[j]->hasPassed < (sites->Count) && sites[i]->ifIn==false) {
							sites[i]->ifArrived = true;//�г���վ
							sites[i]->ifIn = false;
							sites[i]->arrivedTram_no = j;//ûʹ��
							sites[i]->arrivedTram_no1 = trams[j]->tram_no;//ûʹ��
							sites[i]->arrivedTram_strnum = trams[j]->tram_num;//�ַ��͵糵���
							sites[i]->arrivingTram_strnum = nullptr;
							trams[j]->velocity = 0;//�����г��ٶȣ�վ��ͣ��
							trams[j]->hasPassed=i;//�������һ��վ���hasPassed=13
							//���һ������
							if (trams[j]->hasPassed > 0) {
								sites[trams[j]->hasPassed - 1]->ifIn = false;
							}
						}
						if (i<(sites->Count-1) && !trams[j]->finish && trams[j]->hasPassed>=0 && trams[j]->p5->_x >= (sites[i]->pos->_x + out_R) && trams[j]->hasPassed == i)
						{
							//�г�ʻ��վ����һ�δ������һվ��
							//sites[trams[j]->hasPassed - 1]->ifIn = true;
							sites[i]->ifIn = true;
							sites[i+1]->arrivingTram_strnum = trams[j]->tram_num;
							//��յ�վ��Ϣ
							//sites[trams[j]->hasPassed - 1]->ifArrived = false;
							//sites[trams[j]->hasPassed - 1]->arrivedTram_strnum = nullptr;
							sites[i]->ifArrived = false;
							sites[i]->arrivedTram_strnum = nullptr;
						}
							
					}
					//����
					else {
						if (trams[j]->p5->_x <= sites1[sites1->Count-1-i]->pos->_x + out_R && trams[j]->p5->_x > sites1[sites1->Count - 1 - i]->pos->_x - out_R && trams[j]->hasPassed<(sites1->Count) && sites1[sites1->Count - 1 - i]->ifIn==false) {
							sites1[sites1->Count - 1 - i]->ifArrived = true;//�г���վ
							sites1[sites1->Count - 1 - i]->ifIn = false;
							sites1[sites1->Count - 1 - i]->arrivedTram_no = j;
							sites1[sites1->Count - 1 - i]->arrivedTram_no1 = trams[j]->tram_no;
							sites1[sites1->Count - 1 - i]->arrivedTram_strnum = trams[j]->tram_num;
							sites1[sites1->Count - 1 - i]->arrivingTram_strnum = nullptr;
							trams[j]->velocity = 0;
							trams[j]->hasPassed = i;
							//���һ������
							if (trams[j]->hasPassed > 0) {
								sites1[sites1->Count - 1 - (trams[j]->hasPassed - 1)]->ifIn = false;
							}
						}
						if (i < (sites1->Count - 1) && !trams[j]->finish && trams[j]->hasPassed >= 0 && trams[j]->p5->_x <= sites1[sites1->Count - 1 - i]->pos->_x - out_R && trams[j]->hasPassed == (i))
						{
							sites1[sites1->Count - 1 - i]->ifIn = true;
							sites1[sites1->Count - 1 - i -1]->arrivingTram_strnum = trams[j]->tram_num;
							//��յ�վ��Ϣ
							sites1[sites1->Count - 1 - i]->ifArrived = false;
							sites1[sites1->Count - 1 - i]->arrivedTram_strnum = nullptr;
						}
					}
				}
				//����վ����Ϣ���ػ�վ��
				drawSites(i, sites[i]->pos->_x, sites[i]->pos->_y, 0.02f, sites[i]->ifArrived);
				drawSites(i, sites1[i]->pos->_x, sites1[i]->pos->_y, 0.02f, sites1[i]->ifArrived);
			}
		}

		//����վ��  ifPass �Ƿ񵽴x��yΪԲ������ֵ
		System::Void drawSites(int site_index, float x, float y, float R, bool ifArrive)
		{
			//վ����� Բ��
			static int n = 20;
			glLineWidth(3.0f);
			glBegin(GL_POLYGON);
			glColor3f(0.5f + (ifArrive)*(0.5f), 0.7f, 0.7f);
			//�⻷
			for (int i = 0; i < n; i++)
			{
				glVertex2f(x + R * cosf(2 * pi*i / n), y + R * sinf(2 * pi*i / n));   //��ȡ20������Բ�Ķ���
			}
			glEnd();
			glLineWidth(1.0f);

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
		System::Void initSitePeople() {
			//����վ���������ʼ��
			for (int i = 0; i < sites->Count; i++) {
				if (i < sites->Count - 1) {
					for (int j = 0; j < 28; j++) {
						//�߷�ʱ�ο�����
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
				//���Ϊ�յ�վ���ϳ�����Ϊ0
				else {
					for (int j = 0; j < 28; j++) {
						sites[i]->up_people->Add(0);
						sites[i]->down_people->Add(0);
						sites[i]->peoples->Add(0);
					}

				}
			}
			//����վ���������ʼ��
			for (int i = 0; i < sites1->Count; i++) {
				if (i < sites1->Count - 1) {
					for (int j = 0; j < 28; j++) {
						//�߷�ʱ�ο�����
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
				//���Ϊ�յ�վ���ϳ�����Ϊ0
				else {
					for (int j = 0; j < 28; j++) {
						sites1[i]->up_people->Add(0);
						sites1[i]->down_people->Add(0);
						sites1[i]->peoples->Add(0);
					}

				}
			}
		}

		//����վ������,վ��������isPositive����,time_dexʱ���
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

		//�������
		System::Void drawPath() {
			//�����ɫ
			glColor3f(0.3f, 0.6f, 1.0f);

			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

			//������ֱ�߹��
			glBegin(GL_LINES);
			glVertex2f(-orbit_len, -0.0f);
			glVertex2f(orbit_len, -0.0f);
			glEnd();
			glBegin(GL_LINES);
			glVertex2f(orbit_len, -0.0f - path_width);
			glVertex2f(-orbit_len, -0.0f - path_width);
			glEnd();


			//������ֱ�߹��
			glBegin(GL_LINES);
			glVertex2f(-orbit_len, -0.1f);
			glVertex2f(orbit_len, -0.1f);
			glEnd();
			glBegin(GL_LINES);
			glVertex2f(orbit_len, -0.1f - path_width);
			glVertex2f(-orbit_len, -0.1f - path_width);
			glEnd();

		}

		//�����߼�վ��ͼ-�����ֵ�
		System::Void showStand() 
		{
			//����վ������
			String^ str;
			int site_num = sites->Count;//վ����Ŀ
			int name_max = sites[0]->name->Length;//վ���������ֵ
			//ÿ��վ��ļ��
			float delta_x = 2 * stand_len / site_num;
			//��ʼվ�������ֵ
			float x = -stand_len;
			float x_end = stand_len-delta_x;//�յ�վ�������ֵ
			float dist_x = 0.0f;
			float dist_x1 = 0.0f;
			float R = 0.02f;//վ��Բ�뾶
			float r = 0.015f;//վ��Բ�뾶

			//����վ�㼯�ϣ���ȡվ���������ֵ
			for (int site_index = 0; site_index < site_num; site_index++) {
				if (name_max < sites[site_index]->name->Length) {
					name_max = sites[site_index]->name->Length;
				}
			}
			//�����ϲ�վ�㼯��
			for (int site_index = 0; site_index < site_num; site_index++) {
				//����վ������
				glColor3f(0.2f, 0.2f, 0.2f);
				str = sites[site_index]->name;
				//����������ʾλ��
				float y = 0.45f;//��һ��������ʾ��������
				for (int i = 0; i < str->Length; i++) {
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
					glVertex2f(x + dist_x + 0.025f + R * cos(2 * pi / 20 * i), 0.55f + R * sin(2 * pi / 20 * i));//Բ������
					//glVertex2f(x + dist_x  + R * cos(2 * pi / 20 * i), 0.55f + R * sin(2 * pi / 20 * i));//Բ������
				glEnd();
				glBegin(GL_POLYGON);//��ʼ��Բ
				for (int i = 0; i < 20; ++i)
					glVertex2f(x + dist_x + 0.025f + r * cos(2 * pi / 20 * i), 0.55f + r * sin(2 * pi / 20 * i));//Բ������
					//glVertex2f(x + dist_x  + r * cos(2 * pi / 20 * i), 0.55f + r * sin(2 * pi / 20 * i));//Բ������
				glEnd();

				//�����г���վͼ��
				if (sites[site_index]->ifArrived && sites[site_index]->ifIn==false) {
					glColor3f(1.0f, 0.0f, 0.0f); //������ɫ
					glBegin(GL_POLYGON);//��ʼ��Բ
					for (int i = 0; i < 20; ++i)
						glVertex2f(x + dist_x + 0.025f + 0.025f*cos(2 * pi / 20 * i), 0.59f + 0.025f*sin(2 * pi / 20 * i));//Բ������
						//glVertex2f(x + dist_x  + 0.025f*cos(2 * pi / 20 * i), 0.59f + 0.025f*sin(2 * pi / 20 * i));//Բ������
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
					//�����г�վ��ͼ��
					glColor3f(1.0f, 0.0f, 0.0f); //������ɫ
					glBegin(GL_POLYGON);//��ʼ��Բ
					for (int i = 0; i < 20; ++i)
						glVertex2f(x + dist_x + 0.025f + 0.025f*cos(2 * pi / 20 * i) + delta_x / 2, 0.59f + 0.025f*sin(2 * pi / 20 * i));//Բ������
						//glVertex2f(x + dist_x  + 0.025f*cos(2 * pi / 20 * i) + delta_x / 2, 0.59f + 0.025f*sin(2 * pi / 20 * i));//Բ������
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
					//�����ϲ�����
					glColor3f(0.0f + sites[site_index]->ifIn*1.0f, 0.5f - sites[site_index]->ifIn*0.5f, 0.5f - sites[site_index]->ifIn*0.5f); //������ɫ
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

			//�����²�վ�㼯��
			for (int site_index = site_num - 1; site_index >= 0; site_index=site_index-1) {
				//�����²�վ��Բ
				glColor3f(0.0f + sites1[site_index]->ifArrived*1.0f, 0.5f - sites1[site_index]->ifArrived*0.5f, 0.5f - sites1[site_index]->ifArrived*0.5f); //������ɫ
				glBegin(GL_POLYGON);//��ʼ��Բ
				for (int i = 0; i < 20; ++i)
					glVertex2f(x_end - dist_x1 + 0.025f + R * cos(2 * pi / 20 * i), 0.55f - 0.06f*name_max - 0.08f + R * sin(2 * pi / 20 * i));//Բ������
					//glVertex2f(x + dist_x1 + 0.025f + R * cos(2 * pi / 20 * i), 0.55f - 0.06f*name_max - 0.08f + R * sin(2 * pi / 20 * i));//Բ������
				glEnd();
				glBegin(GL_POLYGON);//��ʼ��Բ
				for (int i = 0; i < 20; ++i)
					glVertex2f(x_end - dist_x1 + 0.025f + r * cos(2 * pi / 20 * i), 0.55f - 0.06f*name_max - 0.08f + r * sin(2 * pi / 20 * i));//Բ������
					//glVertex2f(x_end - dist_x1 - 0.025f - r * cos(2 * pi / 20 * i), 0.55f - 0.06f*name_max - 0.08f + r * sin(2 * pi / 20 * i));//Բ������
				glEnd();

				//�����г���վͼ��
				if (site_index > 0 && sites1[site_index]->ifArrived && sites1[site_index]->ifIn==false) {
					glColor3f(1.0f, 0.0f, 0.0f); //������ɫ
					glBegin(GL_POLYGON);//��ʼ��Բ
					for (int i = 0; i < 20; ++i)
						//glVertex2f(x + dist_x1 + 0.025f + 0.025f*cos(2 * pi / 20 * i), 0.51f - 0.06f*name_max - 0.08f + 0.025f*sin(2 * pi / 20 * i));//Բ������
						glVertex2f(x_end - dist_x1 + 0.025f + 0.025f*cos(2 * pi / 20 * i), 0.51f - 0.06f*name_max - 0.08f + 0.025f*sin(2 * pi / 20 * i));//Բ������
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
					//�����г�վ��ͼ��
					glColor3f(1.0f, 0.0f, 0.0f); //������ɫ
					glBegin(GL_POLYGON);//��ʼ��Բ
					for (int i = 0; i < 20; ++i)
						glVertex2f(x_end - dist_x1 + 0.025f + 0.025f*cos(2 * pi / 20 * i) - delta_x / 2, 0.51f - 0.06f*name_max - 0.08f + 0.025f*sin(2 * pi / 20 * i));//Բ������
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
					glColor3f(0.0f + sites1[site_index]->ifIn*1.0f, 0.5f - sites1[site_index]->ifIn*0.5f, 0.5f - sites1[site_index]->ifIn*0.5f); //������ɫ
					glLineStipple(2, 0x5555);
					glEnable(GL_LINE_STIPPLE);
					//�����²�����
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

		//���Ƶ糵
		System::Void drawTram(int tram_index) {
			//�г�����δ��ɻ����г�
			if (!trams[tram_index]->finish) {
				//�����й�糵
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
				str1 += trams[tram_index]->tram_num;//��ʾ�г����
				char* ch = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str1);
				if (trams[tram_index]->positive_run) {
					glRasterPos2f(trams[tram_index]->p5->_x, trams[tram_index]->p1->_y + 0.01f);//�����ַ�λ��
				}
				else {
					glRasterPos2f(trams[tram_index]->p5->_x, trams[tram_index]->p1->_y - 0.022f);
				}
				drawCNString(ch);
			}
		}

		//���ƺ��̵�
		System::Void drawTrafficLight()
		{
			for (int i = 0; i < trlights->Count; i++)
			{
				int lightindex = i;
				//����
				glColor3f(0.0f,0.0f,0.0f);
				glBegin(GL_LINES);
				glVertex2f(trlights[lightindex]->point->_x, trlights[lightindex]->point->_y);
				glVertex2f(trlights[lightindex]->point->_x, trlights[lightindex]->point->_y - trlights[lightindex]->hight1);
				glEnd();
				//�ƿ�
				glBegin(GL_POLYGON);
				glVertex3f(trlights[lightindex]->point->_x - trlights[lightindex]->width1, trlights[lightindex]->point->_y - trlights[lightindex]->hight1, trlights[lightindex]->point->_z);
				glVertex3f(trlights[lightindex]->point->_x + trlights[lightindex]->width1, trlights[lightindex]->point->_y - trlights[lightindex]->hight1, trlights[lightindex]->point->_z);
				glVertex3f(trlights[lightindex]->point->_x + trlights[lightindex]->width1, trlights[lightindex]->point->_y - trlights[lightindex]->hight1 - trlights[lightindex]->hight2, trlights[lightindex]->point->_z);
				glVertex3f(trlights[lightindex]->point->_x - trlights[lightindex]->width1, trlights[lightindex]->point->_y - trlights[lightindex]->hight1 - trlights[lightindex]->hight2, trlights[lightindex]->point->_z);
				glEnd();
				//��
				GLfloat lig_r = 0.018f;//�ư뾶
				glBegin(GL_POLYGON);//��ʼ��Բ
				glColor3f(0.0f, 1.0f, 0.0f); //�̵�
				for (int i = 0; i < 20; ++i)
					glVertex2f(trlights[lightindex]->point->_x - 0.02f + lig_r * cos(2 * pi / 20 * i), trlights[lightindex]->point->_y - trlights[lightindex]->hight1 - 0.02f + lig_r * sin(2 * pi / 20 * i));//�̵�
				glEnd();
				glBegin(GL_POLYGON);//��ʼ��Բ
				glColor3f(1.0f, 0.0f, 0.0f);//���
				for (int i = 0; i < 20; ++i)
					glVertex2f(trlights[lightindex]->point->_x + 0.02f + lig_r * cos(2 * pi / 20 * i), trlights[lightindex]->point->_y - trlights[lightindex]->hight1 - 0.02f + lig_r * sin(2 * pi / 20 * i));//�̵�
				glEnd();

				int draw_n = 4000;
				if (trlights[lightindex]->greenf)//�̵�
				{
					
					glBegin(GL_POLYGON);//��ʼ��Բ
					glColor3f(0.0f, 1.0f, 0.0f); //��ɫ
					for (int i = 0; i < draw_n; ++i)
						glVertex2f(trlights[lightindex]->point->_x - 0.02f + lig_r * cos(2 * pi / draw_n * i), trlights[lightindex]->point->_y - trlights[lightindex]->hight1 - 0.02f + lig_r * sin(2 * pi / draw_n * i));//�̵�
					glEnd();
					trlights[lightindex]->redf = false;//ȷ������ͬʱΪtrue
				}
				else if(trlights[lightindex]->redf)
				{
					
					glBegin(GL_POLYGON);//��ʼ��Բ
					glColor3f(1.0f, 0.0f, 0.0f);//���
					for (int i = 0; i < draw_n; ++i)
						glVertex2f(trlights[lightindex]->point->_x + 0.02f + lig_r * cos(2 * pi / draw_n * i), trlights[lightindex]->point->_y - trlights[lightindex]->hight1 - 0.02f + lig_r * sin(2 * pi / draw_n * i));//�̵�
					glEnd();
					trlights[lightindex]->greenf = false;//ȷ������ͬʱΪtrue
				}
			}

		}

		//����г�����ʼ���г���λ���Լ���ʼ���λ��
		GLvoid initTram(bool positive_run, String^tram_num, String^pronum)
		{
			float tmp;//�������������

			//total_step = 0;
			//��ʼ���г�λ��
			if (positive_run) {
				//����
				tmp = -0.005f;
				tram = gcnew Tram(
					gcnew Point(-orbit_len - tram_width, tmp + tram_to_path + tram_height),
					gcnew Point(-orbit_len + tram_width, tmp + tram_to_path + tram_height),
					gcnew Point(-orbit_len + tram_width, tmp + tram_to_path),
					gcnew Point(-orbit_len - tram_width, tmp + tram_to_path),
					gcnew Point(-orbit_len, tmp + tram_to_path),
					gcnew Point(-orbit_len, tmp - tram_to_path)
				);
				tram->positive_run = true;//��ʼ�����з���
				//xingye
				tram->pronum = pronum;//��ʼ���������
				tram->tram_no = tram_no;//��ʼ����������Ҫ����
				tram_no++;
				tram->tram_num = tram_num;//��ʼ���糵���

				String^selectsql = "SELECT �ؿ����� FROM �г���Ϣ WHERE �г����='" + tram_num + "';";
				DataTable^peop_load = ExecuteQuery(selectsql);
				tram->capacity = int::Parse(peop_load->Rows[0]->ItemArray[0]->ToString()->Trim());//��ʼ���糵�ؿ�����

				selectsql = "SELECT վ��ͣ��ʱ��,վ������ʱ��,վ���� FROM �г�վ��������Ϣ WHERE �г����='" + tram->tram_num + "' AND " +
					"��·���='" + System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)line_num) + "' ORDER BY վ����;";
				DataTable^tram_run_infotb = ExecuteQuery(selectsql);
				for (int i = 0; i < tram_run_infotb->Rows->Count; i++)
				{
					Site^tmpsite = gcnew Site();
					tmpsite->site_no = tram_run_infotb->Rows[i]->ItemArray[2]->ToString();//վ����
					tmpsite->stayTime = int::Parse(tram_run_infotb->Rows[i]->ItemArray[0]->ToString()->Trim());//վ��ͣ��ʱ��
					tmpsite->run_time = int::Parse(tram_run_infotb->Rows[i]->ItemArray[1]->ToString()->Trim());//վ������ʱ��
					tram->tram_siteinfo->Add(tmpsite);//��ʼ���糵�ڸ�վ�����Ϣ��վ���������
				}

				selectsql = "SELECT MIN(cast(������� as int)),MAX(cast(������� as int)),MAX(cast(λ�� as float)),MIN(cast(ʱ�� as datetime)) FROM trainTable WHERE �������='" + pronum + "' AND �г����='" +
					tram_num + "';";
				DataTable^restable = ExecuteQuery1(selectsql);
				try {
					tram->oridatanum = int::Parse(restable->Rows[0]->ItemArray[0]->ToString()->Trim());//��С�������
					tram->datanum = int::Parse(restable->Rows[0]->ItemArray[0]->ToString()->Trim());//��С�������
					tram->maxdatanum = int::Parse(restable->Rows[0]->ItemArray[1]->ToString()->Trim());//����������
					tram->last_pos = float::Parse(restable->Rows[0]->ItemArray[2]->ToString()->Trim());//����λ��
					tram->timeflow = restable->Rows[0]->ItemArray[3]->ToString();

					tram->total_step = 0;//��ʼ���г������ܲ���

					tram->draw = true;//������ָ���Ϊtrue
					trams->Add(tram);
				}
				catch (Exception ^ e) {
					return;
				}
			}
			else {
				//����
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
				tram->pronum = pronum;//��ʼ���������
				tram->tram_no = tram_no;//��ʼ����������Ҫ����
				tram_no++;
				tram->tram_num = tram_num;//��ʼ���糵���

				String^selectsql = "SELECT �ؿ����� FROM �г���Ϣ WHERE �г����='" + tram_num + "';";
				DataTable^peop_load = ExecuteQuery(selectsql);
				tram->capacity = int::Parse(peop_load->Rows[0]->ItemArray[0]->ToString()->Trim());//��ʼ���糵�ؿ�����

				selectsql = "SELECT վ��ͣ��ʱ��,վ������ʱ��,վ���� FROM �г�վ��������Ϣ WHERE �г����='" + tram->tram_num + "' AND " +
					"��·���='" + System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)line_num) + "' ORDER BY վ����;";
				DataTable^tram_run_infotb = ExecuteQuery(selectsql);
				for (int i = 0; i < tram_run_infotb->Rows->Count; i++)
				{
					Site^tmpsite = gcnew Site();
					tmpsite->site_no = tram_run_infotb->Rows[i]->ItemArray[2]->ToString();//վ����
					tmpsite->stayTime = int::Parse(tram_run_infotb->Rows[i]->ItemArray[0]->ToString()->Trim());//վ��ͣ��ʱ��
					tmpsite->run_time = int::Parse(tram_run_infotb->Rows[i]->ItemArray[1]->ToString()->Trim());//վ������ʱ��
					tram->tram_siteinfo->Add(tmpsite);//��ʼ���糵վ���������
				}

				selectsql = "SELECT MIN(cast(������� as int)),MAX(cast(������� as int)),MAX(cast(λ�� as int)),MIN(cast(ʱ�� as datetime)) FROM trainTable WHERE �������='" + pronum + "' AND �г����='" +
					tram_num + "';";
				DataTable^restable = ExecuteQuery1(selectsql);
				tram->oridatanum = int::Parse(restable->Rows[0]->ItemArray[0]->ToString()->Trim());//��С�������
				tram->datanum = int::Parse(restable->Rows[0]->ItemArray[0]->ToString()->Trim());//��С�������
				tram->maxdatanum = int::Parse(restable->Rows[0]->ItemArray[1]->ToString()->Trim());//����������
				tram->last_pos = float::Parse(restable->Rows[0]->ItemArray[2]->ToString()->Trim());//����λ��
				tram->timeflow = restable->Rows[0]->ItemArray[3]->ToString();

				tram->total_step = 0;//��ʼ���г������ܲ���

				tram->draw = true;//������ָ���Ϊtrue
				trams->Add(tram);
			}

		}

		//����г�����ʼ���г���λ���Լ���ʼ���λ��--ʵʱģʽ
		GLvoid SysMode_initTram(bool positive_run, String^tram_num, String^pronum)
		{
			trams->Clear();//ȷ��ʵʱģʽ��ÿ��ֻ��һ��������
			float tmp;//�������������

			//total_step = 0;
			//��ʼ���г�λ��
			if (positive_run) {
				//����
				tmp = -0.005f;
				tram = gcnew Tram(
					gcnew Point(-orbit_len - tram_width, tmp + tram_to_path + tram_height),
					gcnew Point(-orbit_len + tram_width, tmp + tram_to_path + tram_height),
					gcnew Point(-orbit_len + tram_width, tmp + tram_to_path),
					gcnew Point(-orbit_len - tram_width, tmp + tram_to_path),
					gcnew Point(-orbit_len, tmp + tram_to_path),
					gcnew Point(-orbit_len, tmp - tram_to_path)
				);
				tram->positive_run = true;//��ʼ�����з���
				//xingye
				tram->pronum = pronum;//��ʼ���������
				tram->tram_no = tram_no;//��ʼ����������Ҫ����
				tram_no++;
				tram->tram_num = tram_num;//��ʼ���糵���

				String^selectsql = "SELECT �ؿ����� FROM �г���Ϣ WHERE �г����='" + tram_num + "';";
				DataTable^peop_load = ExecuteQuery(selectsql);
				tram->capacity = int::Parse(peop_load->Rows[0]->ItemArray[0]->ToString()->Trim());//��ʼ���糵�ؿ�����

				selectsql = "SELECT վ��ͣ��ʱ��,վ������ʱ��,վ���� FROM �г�վ��������Ϣ WHERE �г����='" + tram->tram_num + "' AND " +
					"��·���='" + System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)line_num) + "' ORDER BY վ����;";
				DataTable^tram_run_infotb = ExecuteQuery(selectsql);
				for (int i = 0; i < tram_run_infotb->Rows->Count; i++)
				{
					Site^tmpsite = gcnew Site();
					tmpsite->site_no = tram_run_infotb->Rows[i]->ItemArray[2]->ToString();//վ����
					tmpsite->stayTime = int::Parse(tram_run_infotb->Rows[i]->ItemArray[0]->ToString()->Trim());//վ��ͣ��ʱ��
					tmpsite->run_time = int::Parse(tram_run_infotb->Rows[i]->ItemArray[1]->ToString()->Trim());//վ������ʱ��
					tram->tram_siteinfo->Add(tmpsite);//��ʼ���糵վ���������
				}
				tram->total_step = 0;//��ʼ���г������ܲ���

				tram->draw = true;//������ָ���Ϊtrue
				trams->Add(tram);
			}
			else {
				//����
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
				tram->pronum = pronum;//��ʼ���������
				tram->tram_no = tram_no;//��ʼ����������Ҫ����
				tram_no++;
				tram->tram_num = tram_num;//��ʼ���糵���

				String^selectsql = "SELECT �ؿ����� FROM �г���Ϣ WHERE �г����='" + tram_num + "';";
				DataTable^peop_load = ExecuteQuery(selectsql);
				tram->capacity = int::Parse(peop_load->Rows[0]->ItemArray[0]->ToString()->Trim());//��ʼ���糵�ؿ�����

				selectsql = "SELECT վ��ͣ��ʱ��,վ������ʱ��,վ���� FROM �г�վ��������Ϣ WHERE �г����='" + tram->tram_num + "' AND " +
					"��·���='" + System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)line_num) + "' ORDER BY վ����;";
				DataTable^tram_run_infotb = ExecuteQuery(selectsql);
				for (int i = 0; i < tram_run_infotb->Rows->Count; i++)
				{
					Site^tmpsite = gcnew Site();
					tmpsite->site_no = tram_run_infotb->Rows[i]->ItemArray[2]->ToString();//վ����
					tmpsite->stayTime = int::Parse(tram_run_infotb->Rows[i]->ItemArray[0]->ToString()->Trim());//վ��ͣ��ʱ��
					tmpsite->run_time = int::Parse(tram_run_infotb->Rows[i]->ItemArray[1]->ToString()->Trim());//վ������ʱ��
					tram->tram_siteinfo->Add(tmpsite);//��ʼ���糵վ���������
				}
				tram->total_step = 0;//��ʼ���г������ܲ���

				tram->draw = true;//������ָ���Ϊtrue
				trams->Add(tram);
			}

		}

		//�г����к���
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
			//xingye����finish�ж�����

			//
			trams[tram_index] = tram;//���µ糵�������е�����
		}

		//�޸Ĳ���
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
			trams[tram_index] = tram;//���µ糵�������е�����
		}

		//���ż���ģʽ�µ糵���к���
		System::Void Runimm(Tram^tram, int tram_index)
		{
			String^selectsql;
			if (!tram->finish && tram->draw == true && tram->positive_run == true && tram->datanum <= tram->maxdatanum)//����
			{
				//�жϷ����Ƿ�ı䣬���ı䷽����ı�λ��
				int d_num = tram->maxdatanum - tram->oridatanum + 1;
				if (tram->datanum >= (Math::Round(d_num/2)+tram->oridatanum-3) && (tram->hasPassed==sites->Count-1))
				{
					//ȡ��һʱ�̵���ʻ����
					selectsql = "SELECT ��ʻ���� FROM trainTable WHERE �������='"+tram->pronum+"' AND �г����='"+tram->tram_num+"' AND �������='"+(tram->datanum-1)+"';";
					restable = ExecuteQuery1(selectsql);
					String^predir = restable->Rows[0]->ItemArray[0]->ToString()->Trim();
					//ȡ��ǰʱ�̵���ʻ����
					selectsql = "SELECT ��ʻ���� FROM trainTable WHERE �������='" + tram->pronum + "' AND �г����='" + tram->tram_num + "' AND �������='" + (tram->datanum) + "';";
					restable = ExecuteQuery1(selectsql);
					String^nowdir = restable->Rows[0]->ItemArray[0]->ToString()->Trim();
					//�����ǰʱ�̵���ʻ����ͬ����һʱ����ʻ���򣬼�����ı�
					if (!String::Equals(predir, nowdir))
					{
						//tram->ResetPoint(tram->positive_run,orbit_len,tram_width,tram_to_path,tram_height,-0.005f);
						tram->ResetPoint(false, orbit_len, tram_width, tram_to_path, tram_height, -0.105f);
						tram->cal_step = 0;//ûȡ�����ݽ���������
						tram->hasPassed = 0;
						//trams[tram_index] = tram;
						//return;
					}
				}

				selectsql = "SELECT ��ʻ����,�ٶ�,���ٶ�,����,��ѹ,cast(λ�� as decimal(9,2)),cast(ʱ�� as datetime) FROM trainTable WHERE �������='" +
					tram->pronum + "' AND �г����='" + tram->tram_num + "' AND �������='" + tram->datanum + "';";
				restable = ExecuteQuery1(selectsql);
				DateTime timeflow_time = Convert::ToDateTime(tram->timeflow);
				DateTime datatime1 = Convert::ToDateTime(restable->Rows[0]->ItemArray[6]->ToString()->Trim());
				//�ж϶���ʱ�����Ƿ񵽴ﵱǰ�������ڵ�ʱ���
				int timespan = DateTime::Compare(timeflow_time, datatime1);
				//�������
				if (timespan == 0)
				{
					//�����г������ٶȡ����ٶȡ�������ѹ��λ�á�ʱ�䡢�������
					if (String::Equals(restable->Rows[0]->ItemArray[0]->ToString()->Trim(), "����"))
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

					//�����������
					tram->datanum = tram->datanum + 1;
					//���û���ָ��:����糵������˳���
					tram->draw = true;
					//�ж��Ƿ�վ,���Ƿ񵽴��յ�վ
					//tram->ArriveIn();
					//��վ����
					//tram->Moveaway();
					//����ʱ����
					tram->timeflow = (timeflow_time.AddSeconds(+1)).ToString();

					//Checked(tram1);

					//���㲽��
					if (tram->positive_run)
					{
						tram->PosTransform(scale);
					}

					trams[tram_index] = tram;
				}
				else if (timespan < 0)//ʱ����û�е������ݵ�ǰʱ��
				{
					tram->timeflow = (timeflow_time.AddSeconds(+1)).ToString();
					tram->cal_step = 0;//ûȡ�����ݽ���������
					trams[tram_index] = tram;
				}
			}
			else if (!tram->finish && tram->draw == true && tram->positive_run == false && tram->datanum <= tram->maxdatanum)//����
			{
				//�жϷ����Ƿ�ı䣬���ı䷽����ı�λ��
				int d_num = tram->maxdatanum - tram->oridatanum + 1;
				if ((tram->datanum >= (Math::Round(d_num / 2) + tram->oridatanum - 3)) && tram->hasPassed==(sites1->Count-1))
				{
					selectsql = "SELECT ��ʻ���� FROM trainTable WHERE �������='" + tram->pronum + "' AND �г����='" + tram->tram_num + "' AND �������='" + (tram->datanum - 1) + "';";
					restable = ExecuteQuery1(selectsql);
					String^predir = restable->Rows[0]->ItemArray[0]->ToString()->Trim();
					selectsql = "SELECT ��ʻ���� FROM trainTable WHERE �������='" + tram->pronum + "' AND �г����='" + tram->tram_num + "' AND �������='" + (tram->datanum) + "';";
					restable = ExecuteQuery1(selectsql);
					String^nowdir = restable->Rows[0]->ItemArray[0]->ToString()->Trim();
					if (!String::Equals(predir, nowdir))
					{
						//tram->ResetPoint(tram->positive_run, orbit_len, tram_width, tram_to_path, tram_height, -0.105f);
						tram->ResetPoint(true, orbit_len, tram_width, tram_to_path, tram_height, -0.005f);
						tram->cal_step = 0;//ûȡ�����ݽ���������
						tram->hasPassed = 0;
						//trams[tram_index] = tram;
						//return;
					}
				}

				selectsql = "SELECT ��ʻ����,�ٶ�,���ٶ�,����,��ѹ,cast(λ�� as decimal(9,2)),cast(ʱ�� as datetime) FROM trainTable WHERE �������='" +
					tram->pronum + "' AND �г����='" + tram->tram_num + "' AND �������='" + tram->datanum + "';";
				restable = ExecuteQuery1(selectsql);
				DateTime timeflow_time = Convert::ToDateTime(tram->timeflow);
				DateTime datatime1 = Convert::ToDateTime(restable->Rows[0]->ItemArray[6]->ToString()->Trim());
				//MessageBox::Show(restable->Rows[0]->ItemArray[6]->ToString()->Trim());
				int timespan = DateTime::Compare(timeflow_time, datatime1);
				if (timespan == 0)
				{
					//�����г������ٶȡ����ٶȡ�������ѹ��λ�á�ʱ�䡢�������
					if (String::Equals(restable->Rows[0]->ItemArray[0]->ToString()->Trim(), "����"))
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
					//�����������
					tram->datanum = tram->datanum + 1;
					//���û���ָ��:����糵������˳���
					tram->draw = true;
					//�ж��Ƿ�վ,���Ƿ񵽴��յ�վ
					//tram->ArriveIn();
					//��վ����
					//tram->Moveaway();
					//����ʱ����
					tram->timeflow = (timeflow_time.AddSeconds(+1)).ToString();

					//Checked(tram1);

					//���㲽��
					if (tram->positive_run == false)
					{
						tram->PosTransform(scale);
					}

					trams[tram_index] = tram;
				}
				else if (timespan < 0)
				{
					tram->timeflow = (timeflow_time.AddSeconds(+1)).ToString();
					tram->cal_step = 0;//ûȡ�����ݽ���������
					trams[tram_index] = tram;
				}
			}
			UpdateStep(tram, tram_index);
		}
		//ͬ������ģʽ�µ糵���к���
		System::Void RunSys(Tram^tram, int tram_index)
		{	
			String^selectsql;
			if (!tram->finish && tram->draw == true && tram->positive_run == true && tram->datanum <= tram->maxdatanum)//����
			{
				selectsql = "SELECT MAX(�������) FROM trainTable WHERE �������='" + tram->pronum + "' AND �г����='" + tram->tram_num + "';";
				restable = ExecuteQuery1(selectsql);
				tram->maxdatanum = int::Parse(restable->Rows[0]->ItemArray[0]->ToString());//�����������
				selectsql = "SELECT ��ʻ����,�ٶ�,���ٶ�,����,��ѹ,cast(λ�� as decimal(9,2)) FROM trainTable WHERE �������='" +
					tram->pronum + "' AND �г����='" + tram->tram_num + "' AND �������='" + restable->Rows[0]->ItemArray[0]->ToString() + "';";
				restable = ExecuteQuery1(selectsql);
				if (restable->Rows->Count <= 0)//ʵʱ��ʾ����Ҫһֱ��ѯ����������ݣ�������λ����ʼ����
					return;

				//�ж��Ƿ�ı䷽��
				if (String::Equals(restable->Rows[0]->ItemArray[0]->ToString()->Trim(), "����"))//����ı���ʻ����
				{
					tram->ResetPoint(false, orbit_len, tram_width, tram_to_path, tram_height, -0.105f);
					tram->cal_step = 0;//ûȡ�����ݽ���������
					tram->hasPassed = 0;
				}
				//���û�иı䷴���ճ����µ糵����
				//�����г������ٶȡ����ٶȡ�������ѹ��λ�á�ʱ��
				if (String::Equals(restable->Rows[0]->ItemArray[0]->ToString()->Trim(), "����"))
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

				//���û���ָ��:����糵������˳���
				tram->draw = true;

				//���㲽��
				if (tram->positive_run)
				{
					tram->PosTransform(scale);
				}

				//Checked(tram);

				trams[0] = tram;
			}
			else if (!tram->finish && tram->draw == true && tram->positive_run == false && tram->datanum <= tram->maxdatanum)//����
			{
				selectsql = "SELECT MAX(�������) FROM trainTable WHERE �������='" + tram->pronum + "' AND �г����='" + tram->tram_num + "';";
				restable = ExecuteQuery1(selectsql);
				tram->maxdatanum = int::Parse(restable->Rows[0]->ItemArray[0]->ToString());//�����������
				selectsql = "SELECT ��ʻ����,�ٶ�,���ٶ�,����,��ѹ,cast(λ�� as decimal(9,2)) FROM trainTable WHERE �������='" +
					tram->pronum + "' AND �г����='" + tram->tram_num + "' AND �������='" + restable->Rows[0]->ItemArray[0]->ToString() + "';";
				restable = ExecuteQuery1(selectsql);
				if (restable->Rows->Count <= 0)//ʵʱ��ʾ����Ҫһֱ��ѯ����������ݣ�������λ����ʼ����
					return;

				//�ж��Ƿ�ı䷽��
				if (String::Equals(restable->Rows[0]->ItemArray[0]->ToString()->Trim(), "����"))//����ı���ʻ����
				{
					tram->ResetPoint(false, orbit_len, tram_width, tram_to_path, tram_height, -0.105f);
					tram->cal_step = 0;//ûȡ�����ݽ���������
					tram->hasPassed = 0;
				}
				//���û�иı䷴���ճ����µ糵����
				//�����г������ٶȡ����ٶȡ�������ѹ��λ�á�ʱ�䡢�������
				if (String::Equals(restable->Rows[0]->ItemArray[0]->ToString()->Trim(), "����"))
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

				//���û���ָ��:����糵������˳���
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

			glViewport(-20, 0, width / 1.1, height / 1.1);						// Reset The Current Viewport

			glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
			glLoadIdentity();									// Reset The Projection Matrix

			//Calculate The Aspect Ratio Of The Window
			gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

			glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
			glLoadIdentity();									// Reset The Modelview Matrix
		}

		//��ʼ��OpenGL����
		bool initGL()										// All setup for opengl goes here
		{
			glShadeModel(GL_SMOOTH);							// Enable smooth shading
			glClearColor(1.0f, 1.0f, 1.0f, 0.5f);				// 	 ����ɫ
			glClearDepth(1.0f);									// ��Ȼ�������
			(GL_DEPTH_TEST);							// ������Ȳ���
			glDepthFunc(GL_LEQUAL);								// ��Ȳ��Ե�����
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// �ܺõ�͸�Ӽ���

			/*
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
			*/

			return TRUE;										// Initialisation went ok
		}
		//�Զ����ѯ���ݿ⺯��
		//�г����ݿ�
		System::Data::DataTable^ ExecuteQuery(String ^sqlStr)
		{
			SqlConnection^con = gcnew SqlConnection();
			//con->ConnectionString = "Data Source=DESKTOP-5TU40C0;Initial Catalog=�г����ݿ�;Integrated Security=True";
			con->ConnectionString = "Data Source=localhost;Initial Catalog=�г����ݿ�;Integrated Security=True";
			SqlDataAdapter^da = gcnew SqlDataAdapter(sqlStr, con);
			con->Open();
			DataTable^result_dt = gcnew DataTable();
			da->Fill(result_dt);
			con->Close();
			return result_dt;
		}
		//RunDB2���ݿ�
		System::Data::DataTable^ ExecuteQuery1(String ^sqlStr)
		{
			SqlConnection^con = gcnew SqlConnection();
			//con->ConnectionString = "Data Source=DESKTOP-5TU40C0;Initial Catalog=�г����ݿ�;Integrated Security=True";
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
		//���Ժ���
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