
// MainFrm.cpp : реализация класса CMainFrame
//

#include "stdafx.h"
#include "Lab08.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

	BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
		ON_WM_CREATE()
	END_MESSAGE_MAP()

	static UINT indicators[] =
	{
		ID_SEPARATOR,           // индикатор строки состояния
		ID_INDICATOR_CAPS,
		ID_INDICATOR_NUM,
		ID_INDICATOR_SCRL,
		ID_INDICATOR_KANA
	};

	// создание/уничтожение CMainFrame

	CMainFrame::CMainFrame() {}

	CMainFrame::~CMainFrame() {}

	int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
	{
		if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
			return -1;
		// voaoom super hack
		m_extension.SubclassWindow(m_hWndMDIClient);

		if (!m_wndStatusBar.Create(this))
		{
			TRACE0("Не удалось создать строку состояния\n");
			return -1;      // не удалось создать
		}
		//m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

		return 0;
	}

	BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
	{
		if( !CMDIFrameWnd::PreCreateWindow(cs) )
			return FALSE;
		// TODO: изменить класс Window или стили посредством изменения
		//  CREATESTRUCT cs

		return TRUE;
	}

	// диагностика CMainFrame

#ifdef _DEBUG
	void CMainFrame::AssertValid() const
	{
		CMDIFrameWnd::AssertValid();
	}

	void CMainFrame::Dump(CDumpContext& dc) const
	{
		CMDIFrameWnd::Dump(dc);
	}
#endif //_DEBUG


	// обработчики сообщений CMainFrame
