
// Lab08Doc.cpp : реализация класса CLab08Doc
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Lab08.h"
#endif

#include "Lab08Doc.h"
#define LAB08DOC_KEY_BEGIN 0x25F0840D
#define LAB08DOC_VERSION 0x1
#define LAB08DOC_KEY_END 0x5BAED4AC	

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CLab08Doc

IMPLEMENT_DYNCREATE(CLab08Doc, CDocument)

BEGIN_MESSAGE_MAP(CLab08Doc, CDocument)
END_MESSAGE_MAP()


// создание/уничтожение CLab08Doc

CLab08Doc::CLab08Doc()
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CLab08Doc::~CLab08Doc()
{
}

BOOL CLab08Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}

// сериализация CLab08Doc

void CLab08Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << int(LAB08DOC_KEY_BEGIN) << int(LAB08DOC_VERSION);
		ar << properties;
		ar << int(LAB08DOC_KEY_END);
	}
	else
	{
		int begin, version, end;
		ar >> begin >> version;
		if (begin == LAB08DOC_KEY_BEGIN && version == LAB08DOC_VERSION) {
			ar >> properties;
		}
		ar >> end;
		ASSERT(end == LAB08DOC_KEY_END);
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CLab08Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CLab08Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задайте содержимое поиска из данных документа. 
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CLab08Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// диагностика CLab08Doc

#ifdef _DEBUG
void CLab08Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLab08Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);


}
#endif //_DEBUG


// команды CLab08Doc
