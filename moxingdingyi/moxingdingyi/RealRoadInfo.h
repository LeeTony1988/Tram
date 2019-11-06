#pragma once
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Data::Common;
using namespace System::Data::OleDb;
using namespace System::Collections;
using namespace System::Runtime::InteropServices;

namespace RealRoad {
	//վ��
	ref class Site {
	public:
		String^name;//վ������
		String^str_num;//�ַ����
		int inum = 0;//վ����
		float rel_dis;//������һվ��ľ���
		float rel_pos;//վ��ʵ��λ�ã���վ�������һվ����֮��

		bool ifin = false;//�Ƿ��е糵��վ
		String^in_tramstrnum;//��վ�糵�ַ����

		int up_peop;//վ���ϳ�����
		int down_peop;//վ���³�����

		float staytime;//վ��ͣ��ʱ��
		Site() {}
		Site(String^str_num1, String^name1, int inum1)
		{
			name = name1;
			str_num = str_num1;
			inum = inum1;
			if (inum == 0)
			{
				ifin = true;
			}
		}

		//�����Ա�д�㷨������վ����������
		void Updatepeop_my()
		{

		}

	};
	//�й�糵
	ref class Tram {
	public:
		//��ʼ������
		String^planstrnum;//�����ַ���ţ���糵���Ψһ��
		String^tram_strnum;//�糵�ַ����
		int tram_num = 0;//�糵���
		int direction = 0;//����:0Ϊ����1Ϊ����

		int lastsitenum;//�յ�վ��ţ��͵�����·���վ����
		int maxpeop;//�����������

		int passedsitenum = 0;//�Ѿ���վ���š���Ŀ
		int presitenum = 0;//Ԥ������վ����
		int inv_passedsitenum = 0;//������ʻ�Ѿ���վ��
		int inv_presitenum = 0;//������ʻ��һվ��

		bool ifcompleted = false;//�Ƿ񵽴�������˳���
		bool ifarr = false;//�Ƿ�վ
		bool predraw = false;//Ԥ����ָ��
		bool draw = false;//����ָ��false��ʶ�����ƣ�Ҳ��ʾ���

		int up_peop;//ĳվ���ϳ�����
		int down_peop;//ĳվ���³�����
		int peopontram = 0;//��������
		float emptyrate;//������

		float pos = 0;//�糵λ��
		float accelerate = 0;//���ٶ�
		float velocity = 0;//�ٶ�
		float current;//�������
		float voltage;//�����ѹ
		int maxdatanum;//����������
		float last_pos;//�յ�λ��
		int datanum;//��ǰ�������
		String^timeflow;//��������ʱ����
		String^settime;//����ʱ���
		List<Site^>^tram_view_site = gcnew List<Site^>();//����:�糵�Ƕȵ�վ������,������Ҫ�����ݿ���վ����Ϣ���һ���г���Ż򷽰����
		List<Site^>^inv_tram_view_site = gcnew List<Site^>();//����

		Tram() {}
		Tram(String^planstrnum1, String^strnum1)
		{
			planstrnum = planstrnum1;
			tram_strnum = strnum1;
		}

		//��վ����
		void ArriveIn()
		{
			if (direction == 0)//����
			{
				float tmp_pos = pos;
				if (pos > last_pos / 2)
				{
					tmp_pos = tmp_pos - (last_pos / 2);
				}
				for (int i = 0,k=1; i < tram_view_site->Count-1; i++,k++)
				{
					if (tmp_pos > tram_view_site[i]->rel_pos + 1 && tmp_pos < tram_view_site[k]->rel_pos - 1)
					{
						passedsitenum = i;
						presitenum = i + 1;
						if (presitenum == tram_view_site->Count)
						{
							presitenum = tram_view_site->Count - 1;
						}
					}
				}
				if (passedsitenum==0 && (tmp_pos <= tram_view_site[passedsitenum]->rel_pos+1))//��һվ
				{
					tram_view_site[passedsitenum]->ifin = true;
					tram_view_site[passedsitenum]->in_tramstrnum = tram_strnum;
					ifarr = true;
				}
				else
				{
					if (presitenum < tram_view_site->Count && tmp_pos >= tram_view_site[presitenum]->rel_pos - 1 && tmp_pos <= tram_view_site[presitenum]->rel_pos + 1)
					{
						tram_view_site[presitenum]->ifin = true;
						tram_view_site[presitenum]->in_tramstrnum = tram_strnum;
						ifarr = true;
						passedsitenum = tram_view_site[presitenum]->inum;
						//presitenum = presitenum + 1;
						//passedsitenum = 13;
						if (pos >= last_pos - 1)//���յ�վ
						{
							//predraw = false;
							draw = false;
							ifcompleted = true;
						}
					}
					else
					{
						tram_view_site[presitenum]->ifin = false;
						tram_view_site[presitenum]->in_tramstrnum = "";
						ifarr = false;
					}
				}
			}
			else if (direction == 1)//����
			{
				float tmp_pos = pos;
				if (pos > last_pos / 2)
				{
					tmp_pos = tmp_pos - (last_pos / 2);
				}
				for (int i = 0,k=1; i < inv_tram_view_site->Count-1; i++,k++)
				{
					if (tmp_pos > inv_tram_view_site[i]->rel_pos + 1 && tmp_pos < inv_tram_view_site[k]->rel_pos - 1)
					{
						inv_passedsitenum = i;
						inv_presitenum = i + 1;
						if (inv_presitenum == inv_tram_view_site->Count)
						{
							inv_presitenum = inv_tram_view_site->Count - 1;
						}
					}
				}
				if (inv_passedsitenum == 0 && (tmp_pos <= inv_tram_view_site[inv_passedsitenum]->rel_pos + 1))//��һվ
				{
					inv_tram_view_site[inv_passedsitenum]->ifin = true;
					inv_tram_view_site[inv_passedsitenum]->in_tramstrnum = tram_strnum;
					ifarr = true;
				}
				else
				{
					if (inv_presitenum < inv_tram_view_site->Count && tmp_pos >= inv_tram_view_site[inv_presitenum]->rel_pos - 1 && tmp_pos <= inv_tram_view_site[inv_presitenum]->rel_pos + 1)
					{
						inv_tram_view_site[inv_presitenum]->ifin = true;
						inv_tram_view_site[inv_presitenum]->in_tramstrnum = tram_strnum;
						ifarr = true;
						inv_passedsitenum = tram_view_site[inv_presitenum]->inum;
						//inv_presitenum = inv_presitenum + 1;
						//passedsitenum = 13;
						if (pos >= last_pos - 1)//���յ�վ
						{
							//predraw = false;
							draw = false;
							ifcompleted = true;
						}
					}
					else
					{
						inv_tram_view_site[inv_presitenum]->ifin = false;
						inv_tram_view_site[inv_presitenum]->in_tramstrnum = "";
						ifarr = false;
					}
				}
			}
			peopontram = peopontram + up_peop - down_peop;//���³�������
		}
		//��վ����
		void Moveaway()
		{
			if (direction == 0 && passedsitenum<13)//����,һ���������һվ������վ����
			{
				if (pos > tram_view_site[passedsitenum]->rel_pos + 5 && pos<tram_view_site[presitenum]->rel_pos-5)
				{
					tram_view_site[passedsitenum]->ifin = false;
					tram_view_site[passedsitenum]->in_tramstrnum = "";
					ifarr = false;
				}
			}
			else if (direction == 1 && inv_passedsitenum < 13)
			{
				if (pos > inv_tram_view_site[inv_passedsitenum]->rel_pos + 5 && pos < inv_tram_view_site[inv_presitenum]->rel_pos - 5)
				{
					inv_tram_view_site[inv_passedsitenum]->ifin = false;
					inv_tram_view_site[inv_passedsitenum]->in_tramstrnum = "";
					ifarr = false;
				}
			}
		}
		//�жϵ糵λ���ĸ�����
		void FindRegion()
		{

		}
		//�Զ������趨�����������³�����
		void Update_uppeop(int basenum, int site_inum)
		{
			if (site_inum == lastsitenum)
			{
				up_peop = 0;//����糵�����յ�վ��û���ϳ�����
			}
			else
			{
				Random^ra = gcnew Random();
				int iseed = ra->Next(1, 101);
				if (iseed <= 80)
				{
					Random^ra1 = gcnew Random(iseed);
					up_peop = ra1->Next(basenum - Math::Floor(0.15*basenum), basenum + Math::Floor(0.15*basenum));
				}
				else
				{
					Random^ra1 = gcnew Random(iseed);
					up_peop = ra1->Next(basenum - Math::Floor(0.5*basenum), basenum + Math::Floor(0.5*basenum));
				}
			}
		}
		void Update_downpeop(int basenum, int site_inum)
		{
			if (site_inum == 0)//����糵λ�����վ
			{
				down_peop = 0;
			}
			else if (site_inum == lastsitenum)
			{
				down_peop = peopontram;//�糵�����յ�վ���յ�վ���³���������ǰһʱ�̳�������
			}
			else
			{
				Random^ra = gcnew Random();
				int iseed = ra->Next(1, 101);
				if (iseed <= 80)
				{
					Random^ra1 = gcnew Random(iseed + 1);
					down_peop = ra1->Next(basenum - Math::Floor(0.15*basenum), basenum + Math::Floor(0.15*basenum));
				}
				else
				{
					Random^ra1 = gcnew Random(iseed + 1);
					down_peop = ra1->Next(basenum - Math::Floor(0.15*basenum), basenum + Math::Floor(0.15*basenum));
				}
			}
		}


	};

	//���з���
	ref class myPlan
	{
	public:
		bool ifshow = false;//ָʾ��ǰ�����Ƿ���Ч
		Tram^tram;//�÷����еĳ���

		//���ż����й���
		myPlan(bool ifshow1)
		{
			ifshow = ifshow1;
		}
		//����������������ʼʱ��㹦��
		myPlan(String^starttime1, bool ifshow1)
		{
			tram->settime = starttime1;
			ifshow = ifshow1;
		}
	};

	//�糵���з�������ϵͳ
	public ref class Operate_System
	{
	public:
		String^sql;
		DataTable^restable;
		String^roadstrnum;//��·�ַ����
		String^roadname;//��·����
		float roadlen;//��·�ܳ���
		int road_sitesnum;//��·վ������
		List<Site^>^sites = gcnew List<Site^>();//������·����վ��
		List<Site^>^inv_sites = gcnew List<Site^>();//������·����վ��
		int trams_index = 0;//��¼ѡ�����з�����������
		List<Tram^>^trams = gcnew List<Tram^>();//��·���е糵������
		List<String^>^plan_indexs = gcnew List<String^>();//�洢������ţ��Ա��������

		//��ʼ����·:���ơ����ȡ�վ������
		void InitPath(String^roadstrnum1)
		{
			roadstrnum = roadstrnum1;
			sql = "SELECT ��·����,��·�ܳ���,վ������ FROM ��·��Ϣ WHERE ��·���='" + roadstrnum + "';";
			restable = GetData(sql);
			roadname = restable->Rows[0]->ItemArray[0]->ToString();
			roadlen = float::Parse(restable->Rows[0]->ItemArray[1]->ToString());
			road_sitesnum = int::Parse(restable->Rows[0]->ItemArray[2]->ToString());
		}
		//��ʼ��վ����Ϣ
		void InitSites()
		{
			float tmp_pos = 0;
			float inv_tmp_pos = 0;
			sites->Clear();
			sql = "SELECT վ����,վ������,վ����� FROM վ����Ϣ WHERE ��·���='" + roadstrnum + "' ORDER BY վ����;";
			restable = GetData(sql);
			for (int i = 0; i < restable->Rows->Count; i++)
			{
				//û��ȥ�ո���
				//����վ����ַ���š����֡����ֱ�š�������һվ���롢ʵ��λ��
				//����վ��
				String^strnum = restable->Rows[i]->ItemArray[0]->ToString();
				String^name = restable->Rows[i]->ItemArray[1]->ToString();
				Site^site_t = gcnew Site(strnum, name, i);
				site_t->rel_dis = float::Parse(restable->Rows[i]->ItemArray[2]->ToString()->Trim());
				tmp_pos = tmp_pos + float::Parse(restable->Rows[i]->ItemArray[2]->ToString()->Trim());
				site_t->rel_pos = tmp_pos;
				//MessageBox::Show(site_t->rel_pos.ToString());
				sites->Add(site_t);
				//����վ��
				if (i == 0)
				{
					strnum = restable->Rows[restable->Rows->Count - i - 1]->ItemArray[0]->ToString();
					name = restable->Rows[restable->Rows->Count - i - 1]->ItemArray[1]->ToString();
					Site^invsite_t = gcnew Site(strnum, name, i);
					invsite_t->rel_dis = 0;
					inv_tmp_pos = inv_tmp_pos + invsite_t->rel_dis;
					invsite_t->rel_pos = inv_tmp_pos;
					inv_sites->Add(invsite_t);
				}
				else
				{
					strnum = restable->Rows[restable->Rows->Count - i - 1]->ItemArray[0]->ToString();
					name = restable->Rows[restable->Rows->Count - i - 1]->ItemArray[1]->ToString();
					Site^invsite_t = gcnew Site(strnum, name, i);
					invsite_t->rel_dis = float::Parse(restable->Rows[restable->Rows->Count-i]->ItemArray[2]->ToString()->Trim());;
					inv_tmp_pos = inv_tmp_pos + invsite_t->rel_dis;
					invsite_t->rel_pos = inv_tmp_pos;
					inv_sites->Add(invsite_t);
				}
			}
		}

		//��ѡ�糵������������
		//��ʼ���糵
		void InitTram(String^planstrnum)//�ظ�ģʽ�µĳ�ʼ������
		{
			sql = "SELECT �г���� FROM ������Ϣ WHERE �������='" + planstrnum + "';";
			restable = GetData(sql);
			String^tram_strnum = restable->Rows[0]->ItemArray[0]->ToString()->Trim();
			Tram^mytram = gcnew Tram(planstrnum, tram_strnum);
			//��ʼ���糵��������
			mytram->tram_num = trams_index;
			trams_index = trams_index + 1;
			sql = "SELECT MIN(cast(������� as int)),MAX(cast(������� as int)),MAX(cast(λ�� as int)) FROM trainTable WHERE �������='" + planstrnum + "' AND �г����='" +
				tram_strnum + "';";
			restable = GetData1(sql);
			//���µ�ǰ������ż����������š����վ����š����λ��
			mytram->datanum = int::Parse(restable->Rows[0]->ItemArray[0]->ToString());
			mytram->maxdatanum = int::Parse(restable->Rows[0]->ItemArray[1]->ToString()->Trim());
			mytram->lastsitenum = road_sitesnum;
			mytram->last_pos = float::Parse(restable->Rows[0]->ItemArray[2]->ToString()->Trim());
			//�󶨵糵�Ƕȵ�վ����Ϣ
			mytram->passedsitenum = 0;
			mytram->presitenum = 1;
			mytram->inv_passedsitenum = 0;
			mytram->inv_presitenum = 1;
			mytram->tram_view_site = sites;//����
			mytram->inv_tram_view_site = inv_sites;//����
			//

			//��ʼ��Ԥ����ָ��
			mytram->predraw = true;

			//��ʼ������ʱ���������ݿ�ʼʱ���
			sql = "SELECT MIN(cast(ʱ�� as datetime)) FROM trainTable WHERE �������='" + planstrnum + "' AND �г����='" +
				tram_strnum + "';";
			restable = GetData1(sql);
			mytram->timeflow = restable->Rows[0]->ItemArray[0]->ToString();
			//mytram->startdatatime = restable->Rows[0]->ItemArray[0]->ToString();
			//�洢�糵����Ա���Ϊ�������洢�糵
			plan_indexs->Add(planstrnum);
			trams->Add(mytram);
		}

		//���أ����Ʒ���ģʽ�µĳ�ʼ����
		void InitTram(String^planstrnum, String^starttime1)
		{
			sql = "SELECT �г���� FROM ������Ϣ WHERE �������='" + planstrnum + "';";
			restable = GetData(sql);
			String^tram_strnum = restable->Rows[0]->ItemArray[0]->ToString()->Trim();
			Tram^mytram = gcnew Tram(planstrnum, tram_strnum);
			//��ʼ���糵��������
			mytram->tram_num = trams_index;
			trams_index = trams_index + 1;
			sql = "SELECT MIN(cast(������� as int)),MAX(cast(������� as int)),MAX(cast(λ�� as int)) FROM trainTable WHERE �������='" + planstrnum + "' AND �г����='" +
				tram_strnum + "';";
			restable = GetData1(sql);
			//���µ�ǰ������ż����������š����վ����š����λ��
			mytram->datanum = int::Parse(restable->Rows[0]->ItemArray[0]->ToString()->Trim());
			mytram->maxdatanum = int::Parse(restable->Rows[0]->ItemArray[1]->ToString()->Trim());
			mytram->lastsitenum = road_sitesnum;
			mytram->last_pos = float::Parse(restable->Rows[0]->ItemArray[2]->ToString()->Trim());

			//�󶨵糵�Ƕȵ�վ����Ϣ
			mytram->passedsitenum = 0;
			mytram->presitenum = 1;
			mytram->inv_passedsitenum = 0;
			mytram->inv_presitenum = 1;
			mytram->tram_view_site = sites;//����
			mytram->inv_tram_view_site = inv_sites;//����

			//��ʼ��Ԥ����ָ��
			mytram->predraw = true;

			//��ʼ������ʱ���������ݿ�ʼʱ���
			sql = "SELECT MIN(cast(ʱ�� as datetime)) FROM trainTable WHERE �������='" + planstrnum + "' AND �г����='" +
				tram_strnum + "';";
			restable = GetData1(sql);
			mytram->timeflow = restable->Rows[0]->ItemArray[0]->ToString();
			//mytram->startdatatime = starttime1;
			mytram->settime = starttime1;
			//�洢�糵����Ա���Ϊ�������洢�糵
			plan_indexs->Add(planstrnum);
			//Checked(mytram);
			trams->Add(mytram);
		}

		//���أ�ʵʱģʽ�µĵ糵��ʼ������
		void InitTram(String^planstrnum, String^mode,String^suibian)
		{
			trams->Clear();//ʵʱģʽ��ÿ��ֻ��һ����

			sql = "SELECT �г���� FROM ������Ϣ WHERE �������='" + planstrnum + "';";
			restable = GetData(sql);
			String^tram_strnum = restable->Rows[0]->ItemArray[0]->ToString()->Trim();
			Tram^mytram = gcnew Tram(planstrnum, tram_strnum);
			//���λ��
			mytram->last_pos = roadlen * 2;

			//�󶨵糵�Ƕȵ�վ����Ϣ
			mytram->passedsitenum = 0;
			mytram->presitenum = 1;
			mytram->inv_passedsitenum = 0;
			mytram->inv_presitenum = 1;
			mytram->tram_view_site = sites;//����
			mytram->inv_tram_view_site = inv_sites;//����

			//��ʼ��Ԥ����ָ��
			mytram->predraw = true;

			//��ʼ������ʱ���������ݿ�ʼʱ���
			sql = "SELECT MIN(cast(ʱ�� as datetime)) FROM trainTable WHERE �������='" + planstrnum + "' AND �г����='" +
				tram_strnum + "';";
			restable = GetData1(sql);
			mytram->timeflow = restable->Rows[0]->ItemArray[0]->ToString();
			//mytram->startdatatime = starttime1;
			//�洢�糵����Ա���Ϊ�������洢�糵
			plan_indexs->Add(planstrnum);
			//Checked(mytram);
			trams->Add(mytram);
		}

		//���ż�����ģʽ�Լ���������ģʽ��ʹ�ô˸��¹���:�ٶ��������ݼ��Ϊ1s
		void Run_imm(Tram^tram1, int tram_index)
		{
			if (!(tram1->ifcompleted) && (tram1->predraw) && (tram1->datanum<=tram1->maxdatanum))//����糵û�����յ�վ
			{
				sql = "SELECT ��ʻ����,�ٶ�,���ٶ�,����,��ѹ,cast(λ�� as decimal(9,2)),cast(ʱ�� as datetime) FROM trainTable WHERE �������='" +
					tram1->planstrnum + "' AND �г����='" + tram1->tram_strnum + "' AND �������='" + tram1->datanum + "';";
				restable = GetData1(sql);
				DateTime timeflow_time = Convert::ToDateTime(tram1->timeflow);
				DateTime datatime1 = Convert::ToDateTime(restable->Rows[0]->ItemArray[6]->ToString()->Trim());
				//MessageBox::Show(restable->Rows[0]->ItemArray[6]->ToString()->Trim());
				int timespan = DateTime::Compare(timeflow_time, datatime1);
				if (timespan == 0)
				{
					//�����г������ٶȡ����ٶȡ�������ѹ��λ�á�ʱ�䡢�������
					if (String::Equals(restable->Rows[0]->ItemArray[0]->ToString()->Trim(), "����"))
					{
						tram1->direction = 0;
					}
					else
					{
						tram1->direction = 1;
					}
					tram1->velocity = float::Parse(restable->Rows[0]->ItemArray[1]->ToString()->Trim());
					tram1->accelerate = float::Parse(restable->Rows[0]->ItemArray[2]->ToString()->Trim());
					tram1->current = float::Parse(restable->Rows[0]->ItemArray[3]->ToString()->Trim());
					tram1->voltage = float::Parse(restable->Rows[0]->ItemArray[4]->ToString()->Trim());
					tram1->pos = float::Parse(restable->Rows[0]->ItemArray[5]->ToString()->Trim());
					//tram1->datatime = restable->Rows[0]->ItemArray[6]->ToString();
					//�����������
					tram1->datanum = tram1->datanum + 1;
					//���û���ָ��:����糵������˳���
					tram1->draw = true;
					//�ж��Ƿ�վ,���Ƿ񵽴��յ�վ
					tram1->ArriveIn();
					//��վ����
					tram1->Moveaway();
					//����ʱ����
					tram1->timeflow = (timeflow_time.AddSeconds(+1)).ToString();

					//Checked(tram1);
					//
					trams[tram_index] = tram1;
				}
				else if (timespan < 0)
				{
					tram1->timeflow = (timeflow_time.AddSeconds(+1)).ToString();
					trams[tram_index] = tram1;
				}
			}
		}

		//ʵʱ����ģʽ�¸������ݹ���
		void SysRun(Tram^tram1)
		{
			if (!(tram1->ifcompleted) && tram1->predraw)//����糵û�����յ�վ
			{
				sql = "SELECT MAX(�������) FROM trainTable WHERE �������='" + tram1->planstrnum + "' AND �г����='" + tram1->tram_strnum + "';";
				restable = GetData1(sql);
				sql = "SELECT ��ʻ����,�ٶ�,���ٶ�,����,��ѹ,cast(λ�� as decimal(9,2)) FROM trainTable WHERE �������='" +
					tram1->planstrnum + "' AND �г����='" + tram1->tram_strnum + "' AND �������='" + restable->Rows[0]->ItemArray[0]->ToString() + "';";
				restable = GetData1(sql);
				if (restable->Rows->Count <= 0)//ʵʱ��ʾ����Ҫһֱ��ѯ����������ݣ�������λ����ʼ����
					return;
				//MessageBox::Show(restable->Rows[0]->ItemArray[6]->ToString()->Trim());
				//�����г������ٶȡ����ٶȡ�������ѹ��λ�á�ʱ�䡢�������
				if (String::Equals(restable->Rows[0]->ItemArray[0]->ToString()->Trim(), "����"))
				{
					tram1->direction = 0;
				}
				else
				{
					tram1->direction = 1;
				}
				tram1->velocity = float::Parse(restable->Rows[0]->ItemArray[1]->ToString()->Trim());
				tram1->accelerate = float::Parse(restable->Rows[0]->ItemArray[2]->ToString()->Trim());
				tram1->current = float::Parse(restable->Rows[0]->ItemArray[3]->ToString()->Trim());
				tram1->voltage = float::Parse(restable->Rows[0]->ItemArray[4]->ToString()->Trim());
				tram1->pos = float::Parse(restable->Rows[0]->ItemArray[5]->ToString()->Trim());
				//tram1->datatime = restable->Rows[0]->ItemArray[6]->ToString();
				//�����������
				tram1->datanum = tram1->datanum + 1;
				//���û���ָ��:����糵������˳���
				tram1->draw = true;
				//�ж��Ƿ�վ,���Ƿ񵽴��յ�վ
				tram1->ArriveIn();
				//��վ����
				tram1->Moveaway();
				//Checked(tram1);
				//
				trams[0] = tram1;
			}
		}

		//ȥ���糵����������ģʽ�����ż���ģʽ
		void RemoveTram(String^plan_strnum1)
		{
			trams[plan_indexs->IndexOf(plan_strnum1)]->predraw = false;
		}
		//����:ʵʱģʽȥ���糵
		void RemoveTram(String^plan_strnum1,String^mode)
		{
			trams[0]->predraw = false;
		}

		//���Ժ���
		void Checked(Tram^tram1)
		{
			String^str1 = "1." + tram1->tram_strnum +
				"\n2.index:" + tram1->tram_num.ToString() +
				"\n3.datanum:" + tram1->datanum.ToString() +
				"\n4.pos:" + tram1->pos.ToString() +
				"\n5.velocity:" + tram1->velocity.ToString() +
				"\n6.timeflow:" + tram1->timeflow +
				"\n7.maxpos:" + tram1->last_pos.ToString() +
				"\n8.settime:" + tram1->settime +
				"\n9.predraw:" + tram1->predraw.ToString() +
				"\n10.draw:" + tram1->draw.ToString() +
				"\n11.maxdatanum:" + tram1->maxdatanum.ToString()+
				"\n12.passedsitenum:"+tram1->passedsitenum.ToString()+
				"\n13.presitenum:"+tram1->presitenum.ToString();
			MessageBox::Show(str1);
		}

		//���캯��
		Operate_System() {};
		Operate_System(String^roadstrnum1)
		{
			roadstrnum = roadstrnum1;
		}

	protected:
		//�Զ������ݿ��ѯ
		DataTable^GetData(String^sqlstr)
		{
			SqlConnection^con = gcnew SqlConnection();
			con->ConnectionString = "Data Source=localhost;Initial Catalog=�г����ݿ�;Integrated Security=True";
			SqlDataAdapter^da = gcnew SqlDataAdapter(sqlstr, con);
			con->Open();
			DataTable^table1 = gcnew DataTable();
			da->Fill(table1);
			con->Close();
			return table1;
		}
		DataTable^GetData1(String^sqlstr)
		{
			SqlConnection^con = gcnew SqlConnection();
			con->ConnectionString = "Data Source=localhost;Initial Catalog=RunDB2;Integrated Security=True";
			SqlDataAdapter^da = gcnew SqlDataAdapter(sqlstr, con);
			con->Open();
			DataTable^table1 = gcnew DataTable();
			da->Fill(table1);
			con->Close();
			return table1;
		}
	};

}