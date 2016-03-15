#pragma once


/*
用记录smart解码运行中的各种状态信息
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif



//#include "FST.h"

using namespace std;



class AnalysisInfo
{

public:


	 void TimeStart();
	 void TimeEnd();
	 double TimeEval(/*double tbegin,double tend*/);


public:
  AnalysisInfo(void);
	~AnalysisInfo(void);


private:


#ifdef _WIN32
	LARGE_INTEGER _tstart,_tend,_tfreq;
#else
	struct timeval _tstart,_tend;
	struct timezone _tz;
#endif



};
