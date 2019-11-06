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
	//站点
	ref class Site {
	public:
		String^name;//站点名称
		String^str_num;//字符编号
		int inum = 0;//站点编号
		float rel_dis;//距离上一站点的距离
		float rel_pos;//站点实际位置，各站点距离上一站距离之和

		bool ifin = false;//是否有电车到站
		String^in_tramstrnum;//到站电车字符编号

		int up_peop;//站点上车人数
		int down_peop;//站点下车人数

		float staytime;//站点停留时间
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

		//根据自编写算法产生各站点人流数据
		void Updatepeop_my()
		{

		}

	};
	//有轨电车
	ref class Tram {
	public:
		//初始化定义
		String^planstrnum;//方案字符编号，与电车编号唯一绑定
		String^tram_strnum;//电车字符编号
		int tram_num = 0;//电车编号
		int direction = 0;//方向:0为正向，1为反向

		int lastsitenum;//终点站编号，就等于线路最大站点数
		int maxpeop;//最大限载人数

		int passedsitenum = 0;//已经过站点编号、数目
		int presitenum = 0;//预备到达站点编号
		int inv_passedsitenum = 0;//反向行驶已经过站点
		int inv_presitenum = 0;//反向行驶下一站点

		bool ifcompleted = false;//是否到达完成整趟车次
		bool ifarr = false;//是否到站
		bool predraw = false;//预绘制指令
		bool draw = false;//绘制指令false标识不绘制，也表示清除

		int up_peop;//某站点上车人数
		int down_peop;//某站点下车人数
		int peopontram = 0;//车内人数
		float emptyrate;//空载率

		float pos = 0;//电车位置
		float accelerate = 0;//加速度
		float velocity = 0;//速度
		float current;//电机电流
		float voltage;//电机电压
		int maxdatanum;//最大数据序号
		float last_pos;//终点位置
		int datanum;//当前数据序号
		String^timeflow;//数据自身时间流
		String^settime;//设置时间点
		List<Site^>^tram_view_site = gcnew List<Site^>();//正向:电车角度的站点数据,可能需要将数据库中站点信息里加一列列车编号或方案编号
		List<Site^>^inv_tram_view_site = gcnew List<Site^>();//反向

		Tram() {}
		Tram(String^planstrnum1, String^strnum1)
		{
			planstrnum = planstrnum1;
			tram_strnum = strnum1;
		}

		//到站动作
		void ArriveIn()
		{
			if (direction == 0)//正向
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
				if (passedsitenum==0 && (tmp_pos <= tram_view_site[passedsitenum]->rel_pos+1))//第一站
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
						if (pos >= last_pos - 1)//到终点站
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
			else if (direction == 1)//反向
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
				if (inv_passedsitenum == 0 && (tmp_pos <= inv_tram_view_site[inv_passedsitenum]->rel_pos + 1))//第一站
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
						if (pos >= last_pos - 1)//到终点站
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
			peopontram = peopontram + up_peop - down_peop;//更新车内人数
		}
		//离站动作
		void Moveaway()
		{
			if (direction == 0 && passedsitenum<13)//正向,一个方向最后一站不作离站动作
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
		//判断电车位于哪个区间
		void FindRegion()
		{

		}
		//自动根据设定人数更新上下车人数
		void Update_uppeop(int basenum, int site_inum)
		{
			if (site_inum == lastsitenum)
			{
				up_peop = 0;//如果电车到达终点站，没有上车人数
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
			if (site_inum == 0)//如果电车位于起点站
			{
				down_peop = 0;
			}
			else if (site_inum == lastsitenum)
			{
				down_peop = peopontram;//电车到达终点站，终点站的下车人数等于前一时刻车内人数
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

	//运行方案
	ref class myPlan
	{
	public:
		bool ifshow = false;//指示当前方案是否有效
		Tram^tram;//该方案中的车次

		//即放即运行功能
		myPlan(bool ifshow1)
		{
			ifshow = ifshow1;
		}
		//方案定制自设置起始时间点功能
		myPlan(String^starttime1, bool ifshow1)
		{
			tram->settime = starttime1;
			ifshow = ifshow1;
		}
	};

	//电车运行方案操作系统
	public ref class Operate_System
	{
	public:
		String^sql;
		DataTable^restable;
		String^roadstrnum;//线路字符编号
		String^roadname;//线路名称
		float roadlen;//线路总长度
		int road_sitesnum;//线路站点总数
		List<Site^>^sites = gcnew List<Site^>();//正向线路所有站点
		List<Site^>^inv_sites = gcnew List<Site^>();//反向线路所有站点
		int trams_index = 0;//记录选择运行方案总数索引
		List<Tram^>^trams = gcnew List<Tram^>();//线路所有电车、方案
		List<String^>^plan_indexs = gcnew List<String^>();//存储方案编号，以便进行索引

		//初始化线路:名称、长度、站点总数
		void InitPath(String^roadstrnum1)
		{
			roadstrnum = roadstrnum1;
			sql = "SELECT 线路名称,线路总长度,站点数量 FROM 线路信息 WHERE 线路编号='" + roadstrnum + "';";
			restable = GetData(sql);
			roadname = restable->Rows[0]->ItemArray[0]->ToString();
			roadlen = float::Parse(restable->Rows[0]->ItemArray[1]->ToString());
			road_sitesnum = int::Parse(restable->Rows[0]->ItemArray[2]->ToString());
		}
		//初始化站点信息
		void InitSites()
		{
			float tmp_pos = 0;
			float inv_tmp_pos = 0;
			sites->Clear();
			sql = "SELECT 站点编号,站点名称,站间距离 FROM 站点信息 WHERE 线路编号='" + roadstrnum + "' ORDER BY 站点编号;";
			restable = GetData(sql);
			for (int i = 0; i < restable->Rows->Count; i++)
			{
				//没做去空格处理
				//更新站点的字符编号、名字、数字编号、距离上一站距离、实际位置
				//正向站点
				String^strnum = restable->Rows[i]->ItemArray[0]->ToString();
				String^name = restable->Rows[i]->ItemArray[1]->ToString();
				Site^site_t = gcnew Site(strnum, name, i);
				site_t->rel_dis = float::Parse(restable->Rows[i]->ItemArray[2]->ToString()->Trim());
				tmp_pos = tmp_pos + float::Parse(restable->Rows[i]->ItemArray[2]->ToString()->Trim());
				site_t->rel_pos = tmp_pos;
				//MessageBox::Show(site_t->rel_pos.ToString());
				sites->Add(site_t);
				//反向站点
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

		//挑选电车方案进行运行
		//初始化电车
		void InitTram(String^planstrnum)//重复模式下的初始化函数
		{
			sql = "SELECT 列车编号 FROM 方案信息 WHERE 方案编号='" + planstrnum + "';";
			restable = GetData(sql);
			String^tram_strnum = restable->Rows[0]->ItemArray[0]->ToString()->Trim();
			Tram^mytram = gcnew Tram(planstrnum, tram_strnum);
			//初始化电车数字索引
			mytram->tram_num = trams_index;
			trams_index = trams_index + 1;
			sql = "SELECT MIN(cast(数据序号 as int)),MAX(cast(数据序号 as int)),MAX(cast(位置 as int)) FROM trainTable WHERE 方案编号='" + planstrnum + "' AND 列车编号='" +
				tram_strnum + "';";
			restable = GetData1(sql);
			//更新当前数据序号及最大数据序号、最大站点序号、最大位置
			mytram->datanum = int::Parse(restable->Rows[0]->ItemArray[0]->ToString());
			mytram->maxdatanum = int::Parse(restable->Rows[0]->ItemArray[1]->ToString()->Trim());
			mytram->lastsitenum = road_sitesnum;
			mytram->last_pos = float::Parse(restable->Rows[0]->ItemArray[2]->ToString()->Trim());
			//绑定电车角度的站点信息
			mytram->passedsitenum = 0;
			mytram->presitenum = 1;
			mytram->inv_passedsitenum = 0;
			mytram->inv_presitenum = 1;
			mytram->tram_view_site = sites;//正向
			mytram->inv_tram_view_site = inv_sites;//反向
			//

			//初始化预绘制指令
			mytram->predraw = true;

			//初始化数据时间流、数据开始时间点
			sql = "SELECT MIN(cast(时间 as datetime)) FROM trainTable WHERE 方案编号='" + planstrnum + "' AND 列车编号='" +
				tram_strnum + "';";
			restable = GetData1(sql);
			mytram->timeflow = restable->Rows[0]->ItemArray[0]->ToString();
			//mytram->startdatatime = restable->Rows[0]->ItemArray[0]->ToString();
			//存储电车编号以便作为索引、存储电车
			plan_indexs->Add(planstrnum);
			trams->Add(mytram);
		}

		//重载：定制方案模式下的初始函数
		void InitTram(String^planstrnum, String^starttime1)
		{
			sql = "SELECT 列车编号 FROM 方案信息 WHERE 方案编号='" + planstrnum + "';";
			restable = GetData(sql);
			String^tram_strnum = restable->Rows[0]->ItemArray[0]->ToString()->Trim();
			Tram^mytram = gcnew Tram(planstrnum, tram_strnum);
			//初始化电车数字索引
			mytram->tram_num = trams_index;
			trams_index = trams_index + 1;
			sql = "SELECT MIN(cast(数据序号 as int)),MAX(cast(数据序号 as int)),MAX(cast(位置 as int)) FROM trainTable WHERE 方案编号='" + planstrnum + "' AND 列车编号='" +
				tram_strnum + "';";
			restable = GetData1(sql);
			//更新当前数据序号及最大数据序号、最大站点序号、最大位置
			mytram->datanum = int::Parse(restable->Rows[0]->ItemArray[0]->ToString()->Trim());
			mytram->maxdatanum = int::Parse(restable->Rows[0]->ItemArray[1]->ToString()->Trim());
			mytram->lastsitenum = road_sitesnum;
			mytram->last_pos = float::Parse(restable->Rows[0]->ItemArray[2]->ToString()->Trim());

			//绑定电车角度的站点信息
			mytram->passedsitenum = 0;
			mytram->presitenum = 1;
			mytram->inv_passedsitenum = 0;
			mytram->inv_presitenum = 1;
			mytram->tram_view_site = sites;//正向
			mytram->inv_tram_view_site = inv_sites;//反向

			//初始化预绘制指令
			mytram->predraw = true;

			//初始化数据时间流、数据开始时间点
			sql = "SELECT MIN(cast(时间 as datetime)) FROM trainTable WHERE 方案编号='" + planstrnum + "' AND 列车编号='" +
				tram_strnum + "';";
			restable = GetData1(sql);
			mytram->timeflow = restable->Rows[0]->ItemArray[0]->ToString();
			//mytram->startdatatime = starttime1;
			mytram->settime = starttime1;
			//存储电车编号以便作为索引、存储电车
			plan_indexs->Add(planstrnum);
			//Checked(mytram);
			trams->Add(mytram);
		}

		//重载：实时模式下的电车初始化函数
		void InitTram(String^planstrnum, String^mode,String^suibian)
		{
			trams->Clear();//实时模式下每次只有一辆车

			sql = "SELECT 列车编号 FROM 方案信息 WHERE 方案编号='" + planstrnum + "';";
			restable = GetData(sql);
			String^tram_strnum = restable->Rows[0]->ItemArray[0]->ToString()->Trim();
			Tram^mytram = gcnew Tram(planstrnum, tram_strnum);
			//最大位置
			mytram->last_pos = roadlen * 2;

			//绑定电车角度的站点信息
			mytram->passedsitenum = 0;
			mytram->presitenum = 1;
			mytram->inv_passedsitenum = 0;
			mytram->inv_presitenum = 1;
			mytram->tram_view_site = sites;//正向
			mytram->inv_tram_view_site = inv_sites;//反向

			//初始化预绘制指令
			mytram->predraw = true;

			//初始化数据时间流、数据开始时间点
			sql = "SELECT MIN(cast(时间 as datetime)) FROM trainTable WHERE 方案编号='" + planstrnum + "' AND 列车编号='" +
				tram_strnum + "';";
			restable = GetData1(sql);
			mytram->timeflow = restable->Rows[0]->ItemArray[0]->ToString();
			//mytram->startdatatime = starttime1;
			//存储电车编号以便作为索引、存储电车
			plan_indexs->Add(planstrnum);
			//Checked(mytram);
			trams->Add(mytram);
		}

		//即放即运行模式以及方案定制模式均使用此更新功能:假定两条数据间隔为1s
		void Run_imm(Tram^tram1, int tram_index)
		{
			if (!(tram1->ifcompleted) && (tram1->predraw) && (tram1->datanum<=tram1->maxdatanum))//如果电车没到达终点站
			{
				sql = "SELECT 行驶方向,速度,加速度,电流,电压,cast(位置 as decimal(9,2)),cast(时间 as datetime) FROM trainTable WHERE 方案编号='" +
					tram1->planstrnum + "' AND 列车编号='" + tram1->tram_strnum + "' AND 数据序号='" + tram1->datanum + "';";
				restable = GetData1(sql);
				DateTime timeflow_time = Convert::ToDateTime(tram1->timeflow);
				DateTime datatime1 = Convert::ToDateTime(restable->Rows[0]->ItemArray[6]->ToString()->Trim());
				//MessageBox::Show(restable->Rows[0]->ItemArray[6]->ToString()->Trim());
				int timespan = DateTime::Compare(timeflow_time, datatime1);
				if (timespan == 0)
				{
					//更新行车方向、速度、加速度、电流电压、位置、时间、数据序号
					if (String::Equals(restable->Rows[0]->ItemArray[0]->ToString()->Trim(), "正向"))
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
					//更新数据序号
					tram1->datanum = tram1->datanum + 1;
					//设置绘制指令:如果电车完成整趟车程
					tram1->draw = true;
					//判断是否到站,及是否到达终点站
					tram1->ArriveIn();
					//离站动作
					tram1->Moveaway();
					//更新时间流
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

		//实时运行模式下更新数据功能
		void SysRun(Tram^tram1)
		{
			if (!(tram1->ifcompleted) && tram1->predraw)//如果电车没到达终点站
			{
				sql = "SELECT MAX(数据序号) FROM trainTable WHERE 方案编号='" + tram1->planstrnum + "' AND 列车编号='" + tram1->tram_strnum + "';";
				restable = GetData1(sql);
				sql = "SELECT 行驶方向,速度,加速度,电流,电压,cast(位置 as decimal(9,2)) FROM trainTable WHERE 方案编号='" +
					tram1->planstrnum + "' AND 列车编号='" + tram1->tram_strnum + "' AND 数据序号='" + restable->Rows[0]->ItemArray[0]->ToString() + "';";
				restable = GetData1(sql);
				if (restable->Rows->Count <= 0)//实时显示中需要一直查询，如果有数据，代表下位机开始传输
					return;
				//MessageBox::Show(restable->Rows[0]->ItemArray[6]->ToString()->Trim());
				//更新行车方向、速度、加速度、电流电压、位置、时间、数据序号
				if (String::Equals(restable->Rows[0]->ItemArray[0]->ToString()->Trim(), "正向"))
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
				//更新数据序号
				tram1->datanum = tram1->datanum + 1;
				//设置绘制指令:如果电车完成整趟车程
				tram1->draw = true;
				//判断是否到站,及是否到达终点站
				tram1->ArriveIn();
				//离站动作
				tram1->Moveaway();
				//Checked(tram1);
				//
				trams[0] = tram1;
			}
		}

		//去除电车：方案定制模式及即放即行模式
		void RemoveTram(String^plan_strnum1)
		{
			trams[plan_indexs->IndexOf(plan_strnum1)]->predraw = false;
		}
		//重载:实时模式去除电车
		void RemoveTram(String^plan_strnum1,String^mode)
		{
			trams[0]->predraw = false;
		}

		//调试函数
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

		//构造函数
		Operate_System() {};
		Operate_System(String^roadstrnum1)
		{
			roadstrnum = roadstrnum1;
		}

	protected:
		//自定义数据库查询
		DataTable^GetData(String^sqlstr)
		{
			SqlConnection^con = gcnew SqlConnection();
			con->ConnectionString = "Data Source=localhost;Initial Catalog=列车数据库;Integrated Security=True";
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