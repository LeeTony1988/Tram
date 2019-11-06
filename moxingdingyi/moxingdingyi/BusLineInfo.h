#pragma once
using namespace System;
ref class BusLineInfo
{
public:
	BusLineInfo();
public:
	String^linenum;//线路编号
	String^proposalnum;//方案编号
	String^ carnum;//车编号
	int maxdatanum;//最大数据序号
	float last_position;//终点位置

	int pre_showflag = 1;
	int showflag = 1;//指示绘制图像时应该删除还是绘制
	String^direction;//行驶方向
	String^starttime;//开始时间节点，会改变
	String^faketime;//假设时间起始点,在方案定制模式中为用户自设置
	int datanum;//数据序号
	float position;//当前位置

	
	float carspeed;//速度
	float caraccelerate;//加速度
	float current;//电流
	float voltage;//电压
	float peopleoncar = 0;//车上人数
};

