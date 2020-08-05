// TestThread.cpp : implementation file
//

#include "stdafx.h"
#include "CounterThreading.h"
#include "TestThread.h"
#include "CounterThreadingView.h"

// CTestThread

IMPLEMENT_DYNCREATE(CTestThread, CWinThread)

CTestThread::CTestThread()
{
}

CTestThread::~CTestThread()
{
}

BOOL CTestThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CTestThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CTestThread, CWinThread)
END_MESSAGE_MAP()


// CTestThread message handlers


UINT CTestThread::RunThreadFunction(LPVOID param)
{
	CCounterThreadingView *pCounterThreadingView = (CCounterThreadingView *)param;
	CPoints cpoints;
	CPoints cspiral;
	CPoints cd;


	//random walk
	if (pCounterThreadingView->iCases == 1)
	{

		while (1)
		{
			cpoints.m_dX1 = rand() / 100;
			cpoints.m_dY1 = rand() / 100;
			pCounterThreadingView->m_Cpoint.Add(cpoints);
			pCounterThreadingView->Invalidate();
			Sleep(500);
		}

	}

	//spiral
	else if (pCounterThreadingView->iCases == 2)
	{

		while (1)

		{

			cpoints.m_dRadius += 1;

			cspiral.m_dXs = (cpoints.m_dRadius * cos(cpoints.m_dRadius / 10 * 3.14)) + 400;

			cspiral.m_dYs = (cpoints.m_dRadius* sin(cpoints.m_dRadius / 10 * 3.14)) + 300;

			pCounterThreadingView->m_Cspiral.Add(cspiral);
			pCounterThreadingView->Invalidate();
			Sleep(100);
		}

	}

	//Damped
	else if (pCounterThreadingView->iCases == 3)
	{

		while (1)
		{

			int iT = 0;


			iT = cd.m_damplitude;
			for (int p = 1; p < cd.m_damplitude; p++)
			{
				cd.m_dXd += cd.m_dtimePeriod / iT;
				iT--;
				cd.m_dYd -= 1;
				pCounterThreadingView->m_Cdamped.Add(cd);


			}
			iT = 1;
			for (int n = cd.m_damplitude; n > 0; n--)
			{

				cd.m_dXd += cd.m_dtimePeriod / iT;
				iT++;
				cd.m_dYd += 1;
				pCounterThreadingView->m_Cdamped.Add(cd);


			}

			iT = cd.m_damplitude;
			for (int p = 1; p < cd.m_damplitude; p++)
			{
				cd.m_dXd += cd.m_dtimePeriod / iT;
				iT--;
				cd.m_dYd += 1;
				pCounterThreadingView->m_Cdamped.Add(cd);

			}

			iT = 1;
			for (int n = cd.m_damplitude; n > 0; n--)
			{
				cd.m_dXd += cd.m_dtimePeriod / iT;
				iT++;
				cd.m_dYd -= 1;
				pCounterThreadingView->m_Cdamped.Add(cd);

			}
			pCounterThreadingView->m_Cdamped.Add(cd);


			cd.m_damplitude -= 9;

			pCounterThreadingView->Invalidate();
			Sleep(500);
		}
	}
	return 0;
}
