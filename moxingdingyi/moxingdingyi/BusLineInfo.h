#pragma once
using namespace System;
ref class BusLineInfo
{
public:
	BusLineInfo();
public:
	String^linenum;//��·���
	String^proposalnum;//�������
	String^ carnum;//�����
	int maxdatanum;//����������
	float last_position;//�յ�λ��

	int pre_showflag = 1;
	int showflag = 1;//ָʾ����ͼ��ʱӦ��ɾ�����ǻ���
	String^direction;//��ʻ����
	String^starttime;//��ʼʱ��ڵ㣬��ı�
	String^faketime;//����ʱ����ʼ��,�ڷ�������ģʽ��Ϊ�û�������
	int datanum;//�������
	float position;//��ǰλ��

	
	float carspeed;//�ٶ�
	float caraccelerate;//���ٶ�
	float current;//����
	float voltage;//��ѹ
	float peopleoncar = 0;//��������
};

