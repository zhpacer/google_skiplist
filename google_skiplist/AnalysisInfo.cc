#include "AnalysisInfo.h"

AnalysisInfo::AnalysisInfo(void)
{
}

AnalysisInfo::~AnalysisInfo(void)
{
}


 void AnalysisInfo::TimeStart()
{
#ifdef _WIN32
	int first = 1;
	if(first)
	{
		QueryPerformanceFrequency(&_tfreq);
		first = 0;
	}
	QueryPerformanceCounter(&_tstart);
#else
	gettimeofday(&_tstart,&_tz);
#endif
}


 void AnalysisInfo::TimeEnd()
{
#ifdef _WIN32
	QueryPerformanceCounter(&_tend);
#else
	gettimeofday(&_tend,&_tz);
#endif
}

 double AnalysisInfo::TimeEval()
{
#ifdef _WIN32
	double timeEval =  ((double)_tend.QuadPart-(double)_tstart.QuadPart )/(double)(_tfreq.QuadPart*1e-3);
	return timeEval;
#else
	double t1,t2;
	t1 = (double)_tstart.tv_sec + (double)_tstart.tv_usec/(1000*1000);
	t2 = (double)_tend.tv_sec + (double)_tend.tv_usec/(1000*1000);
	return (double(t2 - t1))*1000;
#endif
}







