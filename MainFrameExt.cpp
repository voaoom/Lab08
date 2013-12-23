// MainFrameExt.cpp: файл реализации
//

#include "stdafx.h"
#include <iostream>
#include "Lab08.h"
#include "MainFrameExt.h"
#include "resource.h"

// CMainFrameExt 
IMPLEMENT_DYNAMIC(CMainFrameExt, CWnd)

	CMainFrameExt::CMainFrameExt() : img_koa(NULL) {}

CMainFrameExt::~CMainFrameExt() {}

BEGIN_MESSAGE_MAP(CMainFrameExt, CWnd)
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// обработчики сообщений CMainFrameExt

BOOL CMainFrameExt::OnEraseBkgnd(CDC* pDC) 
{
	CMemDC dbMem(*pDC, pDC->GetWindow());
	CDC* dbDC = &dbMem.GetDC();

	CRect size;
	pDC->GetWindow()->GetClientRect(size);

	CBrush bgBrush(RGB(127, 95, 95));
	dbDC->FillRect(size, &bgBrush);

	LONG x = size.left + (size.right - size.left) / 2;
	LONG y = size.top + (size.bottom - size.top) / 2;

	size.left += 100;
	size.right -= 100;
	size.top += 100;
	size.bottom -= 100;

	if( img_koa == NULL ) {
		img_koa = new CImage();
		img_koa->LoadFromResource(AfxGetInstanceHandle(), IDB_BITMAP_KOAKUMA);
		ASSERT(!img_koa->IsNull());
		img_koa->SetTransparentColor(RGB(255, 0, 255));
	}

	int vpsz = min(size.Width(), size.Height());
	int isz = max(img_koa->GetWidth(), img_koa->GetHeight());
	int scale = vpsz / isz;
	if (scale < 1) scale = 1;
	int nzx = img_koa->GetWidth() * scale, nzy = img_koa->GetHeight() * scale;

	img_koa->Draw(
		dbDC->GetSafeHdc(),
		x - nzx/2, y - nzx/2, 
		nzx, nzy,
		0, 0,
		img_koa->GetWidth(), img_koa->GetHeight()
	);

	return TRUE;
}

void CMainFrameExt::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
	Invalidate();
}
