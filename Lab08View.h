
// Lab08View.h : интерфейс класса CLab08View
//

#pragma once
#include "PropertiesDlg.h"

class CLab08View : public CView
{
protected: // создать только из сериализации
	CLab08View();
	DECLARE_DYNCREATE(CLab08View)

// Атрибуты
public:
	CLab08Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Реализация
public:
	virtual ~CLab08View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

// voaoom
public:
	afx_msg void OnProperties();
// /voaoom
private:
	double t_pixel_to_dim_x(CRect & size, int x);
	double t_pixel_to_dim_y(CRect & size, int y);
	int t_dim_to_pixel_x(CRect & size, double x);
	int t_dim_to_pixel_y(CRect & size, double y);
	void drawPoint(CDC * _pDC, CRect & size, int x, int y, CString & text);
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // отладочная версия в Lab08View.cpp
inline CLab08Doc* CLab08View::GetDocument() const
   { return reinterpret_cast<CLab08Doc*>(m_pDocument); }
#endif

