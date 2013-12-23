#pragma once
#include "afxcolorbutton.h"
#include "afxwin.h"
#include  "Properties.h"
#include "afxcmn.h"

// диалоговое окно CPropertiesDlg

class CPropertiesDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPropertiesDlg)

public:
	CPropertiesDlg(Properties * properties, CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CPropertiesDlg();

	// Данные диалогового окна
	enum { IDD = IDD_DLG_PROP };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	DECLARE_MESSAGE_MAP()
private:
	CListBox m_func_list;
	//
	CEdit m_func_a;
	CEdit m_func_b;
	CEdit m_func_c;
	CMFCButton m_color_show;
	COLORREF m_color;
	//
	CButton m_func_apply;
	CButton m_func_rem;
	CButton m_func_add;
	//
	Properties * properties;
	void updateFuncProps();
	void updateFuncList();
public:
	afx_msg void OnLbnSelchangeFuncList();
	afx_msg void OnBnClickedFuncRem();
	afx_msg void OnBnClickedFuncAdd();
	afx_msg void OnBnClickedFuncApply();
	afx_msg void OnBnClickedFuncColor();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
private:
public:
	afx_msg void OnBnClickedOk();
};
