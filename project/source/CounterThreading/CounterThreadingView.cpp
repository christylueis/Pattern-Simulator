
// CounterThreadingView.cpp : implementation of the CCounterThreadingView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CounterThreading.h"
#endif

#include "CounterThreadingDoc.h"
#include "CounterThreadingView.h"
#include "TestThread.h"
#include "SelectionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCounterThreadingView

IMPLEMENT_DYNCREATE(CCounterThreadingView, CView)

BEGIN_MESSAGE_MAP(CCounterThreadingView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_THREAD_START, &CCounterThreadingView::OnThreadStart)
	ON_COMMAND(ID_THREAD_PAUSE, &CCounterThreadingView::OnThreadPause)
	ON_COMMAND(ID_THREAD_RESUME, &CCounterThreadingView::OnThreadResume)
	ON_COMMAND(ID_SETUP_SELECTPATTERN, &CCounterThreadingView::OnSetupSelectpattern)
END_MESSAGE_MAP()

// CCounterThreadingView construction/destruction

CCounterThreadingView::CCounterThreadingView()
	
{
	
	
}

CCounterThreadingView::~CCounterThreadingView()
{
}

BOOL CCounterThreadingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCounterThreadingView drawing

void CCounterThreadingView::OnDraw(CDC* pDC)
{
	CCounterThreadingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	switch (iCases)
	{

	case 1:
		for (int iCount = 0; iCount <= (m_Cpoint.GetSize() - 2); iCount++)
		{
			pDC->LineTo(m_Cpoint[iCount].m_dX1, m_Cpoint[iCount].m_dY1);
		}
		break;

	case 2:
		pDC->MoveTo(400, 300);

		for (int iCount = 0; iCount <= (m_Cspiral.GetSize() - 2); iCount++)
		{
			pDC->LineTo(m_Cspiral[iCount].m_dXs, m_Cspiral[iCount].m_dYs);
		}

		break;

	case 3:

		pDC->MoveTo(10, 30);
		pDC->LineTo(10, 500);
		pDC->MoveTo(10, 200);
		pDC->LineTo(800, 200);



		pDC->MoveTo(10, 200);

		for (int iCount = 0; iCount <= m_Cdamped.GetSize() - 1; iCount++)
		{
			pDC->LineTo(m_Cdamped[iCount].m_dXd, m_Cdamped[iCount].m_dYd);

		}
		break;
	default:

		//AfxMessageBox("invalid");
		break;

	}


}


// CCounterThreadingView printing

BOOL CCounterThreadingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCounterThreadingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCounterThreadingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCounterThreadingView diagnostics

#ifdef _DEBUG
void CCounterThreadingView::AssertValid() const
{
	CView::AssertValid();
}

void CCounterThreadingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCounterThreadingDoc* CCounterThreadingView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCounterThreadingDoc)));
	return (CCounterThreadingDoc*)m_pDocument;
}
#endif //_DEBUG


// CCounterThreadingView message handlers


void CCounterThreadingView::OnThreadStart()
{
	pThread = AfxBeginThread(CTestThread::RunThreadFunction, this);
}


void CCounterThreadingView::OnThreadPause()
{
	pThread -> SuspendThread();
}


void CCounterThreadingView::OnThreadResume()
{
	pThread->ResumeThread();
}


void CCounterThreadingView::OnSetupSelectpattern()
{
	// TODO: Add your command handler code here
	CSelectionDlg selectn;
	if (selectn.DoModal() == IDOK)
	{
		if (selectn.strSelectedItem == "Spiral")
		{
			iCases = 2;
		}

		else if (selectn.strSelectedItem == "Random Walk")
		{
			iCases = 1;
		}
		else if (selectn.strSelectedItem == "Damped Harmonic Ocsilation")
		{
			iCases = 3;
		}

	}UpdateData(TRUE);
}
