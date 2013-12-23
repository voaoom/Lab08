#pragma once

// CMainFrameExt

class CMainFrameExt : public CWnd
{
	DECLARE_DYNAMIC(CMainFrameExt)
public:
	CMainFrameExt();
	virtual ~CMainFrameExt();
	BOOL afx_msg CMainFrameExt::OnEraseBkgnd(CDC* pDC);
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
protected:
	CImage * img_koa;
};


