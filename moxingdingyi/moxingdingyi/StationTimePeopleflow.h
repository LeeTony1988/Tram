#pragma once
using namespace System;
ref class StationTimePeopleflow
{
public:
	StationTimePeopleflow();
public:
	String^stationname;
	int station_x;
	array<int>^y_data = gcnew array<int>(15);
};

