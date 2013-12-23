// PropertiesDlg.cpp: файл реализации
//
#include <utility>
#include "stdafx.h"
#include "Lab08.h"
#include "PropertiesDlg.h"
#include "Function.h"
#include "afxdialogex.h"

// диалоговое окно CPropertiesDlg

IMPLEMENT_DYNAMIC(CPropertiesDlg, CDialogEx)

	//
CPropertiesDlg::CPropertiesDlg(Properties * p, CWnd* pParent /*=NULL*/) :
	CDialogEx(CPropertiesDlg::IDD, pParent), properties(p)
{
	ASSERT(p != NULL);
	m_color_show.SetMouseCursorHand();

	//updateFuncList();
}

CPropertiesDlg::~CPropertiesDlg() {}

void CPropertiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_X_MIN, properties->x_min);
	DDX_Text(pDX, IDC_X_MAX, properties->x_max);
	DDX_Text(pDX, IDC_X_GRID, properties->x_grid);
	DDX_Text(pDX, IDC_Y_MIN, properties->y_min);
	DDX_Text(pDX, IDC_Y_MAX, properties->y_max);
	DDX_Text(pDX, IDC_Y_GRID, properties->y_grid);
	DDX_Text(pDX, IDC_ACCURACY_EDIT, properties->accuracy);
	DDV_MinMaxInt(pDX, properties->accuracy, 1, 10);
	//
	DDX_Control(pDX, IDC_FUNC_LIST, m_func_list);
	DDX_Control(pDX, IDC_FUNC_REM, m_func_rem);
	DDX_Control(pDX, IDC_FUNC_APPLY, m_func_apply);
	DDX_Control(pDX, IDC_FUNC_ADD, m_func_add);
	//
	DDX_Control(pDX, IDC_FUNC_A, m_func_a);
	DDX_Control(pDX, IDC_FUNC_B, m_func_b);
	DDX_Control(pDX, IDC_FUNC_C, m_func_c);
	DDX_Control(pDX, IDC_FUNC_COLOR_SHOW, m_color_show);
	//

	if(pDX->m_bSaveAndValidate == FALSE) {
		updateFuncList(); // а то не отображалось при открытии окна
		updateFuncProps(); // аналогично
	}
}

BEGIN_MESSAGE_MAP(CPropertiesDlg, CDialogEx)
	ON_BN_CLICKED(IDC_FUNC_REM, &CPropertiesDlg::OnBnClickedFuncRem)
	ON_BN_CLICKED(IDC_FUNC_ADD, &CPropertiesDlg::OnBnClickedFuncAdd)
	ON_BN_CLICKED(IDC_FUNC_APPLY, &CPropertiesDlg::OnBnClickedFuncApply)
	ON_LBN_SELCHANGE(IDC_FUNC_LIST, &CPropertiesDlg::OnLbnSelchangeFuncList)
	ON_BN_CLICKED(IDC_FUNC_COLOR_SHOW, &CPropertiesDlg::OnBnClickedFuncColor)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDOK, &CPropertiesDlg::OnBnClickedOk)
END_MESSAGE_MAP()

// обработчики сообщений CPropertiesDlg

void CPropertiesDlg::OnBnClickedFuncRem()
{
	int id = m_func_list.GetCurSel();
	auto & funcs = properties->functions; // shortcut
	if (id != LB_ERR && id >= 0 && id < funcs.size()) {
		funcs.erase(funcs.begin() + id);
		updateFuncList();
		updateFuncProps();
	}
}


void CPropertiesDlg::OnLbnSelchangeFuncList()
{
	updateFuncProps();
}


void CPropertiesDlg::OnBnClickedFuncAdd()
{
	properties->functions.push_back(std::make_pair(
		Function(), RGB(rand() % 256, rand() % 256, rand() % 256)
	));
	updateFuncList();
	updateFuncProps();
}

void CPropertiesDlg::OnBnClickedFuncApply() {
	auto & funcs = properties->functions; // shortcut
	int id = m_func_list.GetCurSel();
	if ( id != LB_ERR && id >= 0 && id < funcs.size()) {
		CString tmp;
		m_func_a.GetWindowText(tmp); funcs[id].first.a = _tstof(tmp);
		m_func_b.GetWindowText(tmp); funcs[id].first.b = _tstof(tmp);
		m_func_c.GetWindowText(tmp); funcs[id].first.c = _tstof(tmp);
		funcs[id].second = m_color;
		updateFuncList();
	}
}

// voaoom

void CPropertiesDlg::updateFuncProps() {
	int id = m_func_list.GetCurSel();
	auto & funcs = properties->functions; // shortcut
	if (id != LB_ERR && id >= 0 && id < funcs.size()) {
		CString tmp;
		Function & func = funcs[id].first;
		tmp.Format(_T("%g"), func.a); m_func_a.SetWindowTextW(tmp); m_func_a.EnableWindow(TRUE);
		tmp.Format(_T("%g"), func.b); m_func_b.SetWindowTextW(tmp); m_func_b.EnableWindow(TRUE);
		tmp.Format(_T("%g"), func.c); m_func_c.SetWindowTextW(tmp); m_func_c.EnableWindow(TRUE);
		m_color = funcs[id].second;
		m_color_show.SetFaceColor(m_color, TRUE); m_color_show.EnableWindow(TRUE);
		// m_func_list.SetCurSel(id); // костыль
	} else {
		CString empty(_T(""));
		m_func_a.EnableWindow(FALSE); m_func_a.SetWindowTextW(empty); 
		m_func_b.EnableWindow(FALSE); m_func_b.SetWindowTextW(empty); 
		m_func_c.EnableWindow(FALSE); m_func_c.SetWindowTextW(empty); 
		m_color = RGB(0, 0, 0);
		m_color_show.EnableWindow(FALSE); m_color_show.SetFaceColor(m_color, TRUE); 
	}
}

void CPropertiesDlg::updateFuncList() {
	int id = m_func_list.GetCurSel();
	m_func_list.ResetContent();
	auto & funcs = properties->functions; // shortcut
	for(int i = 0; i < funcs.size(); ++i)
		m_func_list.InsertString(i, funcs[i].first.name());
	if (id != LB_ERR && !funcs.empty())
		m_func_list.SetCurSel((id < 0) ? 0 : (id >= funcs.size() ? (funcs.size() - 1) : id));
}


void CPropertiesDlg::OnBnClickedFuncColor()
{
	int id = m_func_list.GetCurSel();
	auto & funcs = properties->functions; // shortcut
	if (id != LB_ERR && id >= 0 && id < funcs.size()) {
		CColorDialog dlg(funcs[id].second, CC_FULLOPEN);
		INT_PTR result = dlg.DoModal();
		if (result == IDOK) {
			ASSERT(m_color_show.IsWindowEnabled());
			m_color = dlg.GetColor();
			m_color_show.SetFaceColor(m_color);
		}
	}
}


int CPropertiesDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	//updateFuncList();
	//updateFuncProps();

	return 0;
}


void CPropertiesDlg::OnBnClickedOk()
{
	CString tmp;
	bool invalid = false;

	UpdateData(TRUE);

	if (properties->x_max <= properties->x_min) {
		invalid = true;
		tmp += _T("Ось X: Максимальная граница должна быть больше минимальной.\n");
	}
	if ( properties->x_grid <= 0 ) {
		invalid = true;
		tmp += _T("Ось X: Масштаб сетки должен быть не отрицательным.\n");
	}
	double dist_x = abs(1.0 * (properties->x_max - properties->x_min) / properties->x_grid);
	if ( dist_x < 0.001 || dist_x > 1000) {
		invalid = true;
		tmp += _T("Ось X: Масштаб сетки должен быть соизмерим с границами построения.\n");
	}
	//
	if (properties->y_max <= properties->y_min) {
		invalid = true;
		tmp += _T("Ось Y: Максимальная граница должна быть больше минимальной.\n");
	}
	if ( properties->y_grid <= 0 ) {
		invalid = true;
		tmp += _T("Ось Y: Масштаб сетки должен быть не отрицательным.\n");
	}
	double dist_y = abs(1.0 * (properties->y_max - properties->y_min) / properties->y_grid);
	if ( dist_y < 0.001 || dist_y > 1000) {
		invalid = true;
		tmp += _T("Ось Y: Масштаб сетки должен быть соизмерим с границами построения.\n");
	}

	if (invalid) MessageBox(tmp, _T("Что-то не так!"), MB_ICONERROR );
	else CDialogEx::OnOK();
}
