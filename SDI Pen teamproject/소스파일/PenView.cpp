
// PenView.cpp: CPenView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Pen.h"
#endif

#include "PenDoc.h"
#include "PenView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPenView

IMPLEMENT_DYNCREATE(CPenView, CView)

BEGIN_MESSAGE_MAP(CPenView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SELECT_COLOR, &CPenView::OnSelectColor)
	ON_COMMAND(ID_SIZE_1, &CPenView::OnSize1)
	ON_COMMAND(ID_SIZE_4, &CPenView::OnSize4)
	ON_COMMAND(ID_SIZE_8, &CPenView::OnSize8)
	ON_COMMAND(ID_SIZE_16, &CPenView::OnSize16)
	ON_COMMAND(ID_SIZE_32, &CPenView::OnSize32)
END_MESSAGE_MAP()

// CPenView 생성/소멸

CPenView::CPenView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPenView::~CPenView()
{
}

BOOL CPenView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPenView 그리기
#include "CLine.h"
void CPenView::OnDraw(CDC* pDC)
{
	CPenDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int n = pDoc->m_oa.GetSize();
	for (int i = 0; i < n; i++) {
		CLine* pLine = (CLine *)pDoc->m_oa[i];//타입캐스팅(형변환)
		pLine->Draw(pDC);
	}
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CPenView 인쇄

BOOL CPenView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPenView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPenView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPenView 진단

#ifdef _DEBUG
void CPenView::AssertValid() const
{
	CView::AssertValid();
}

void CPenView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPenDoc* CPenView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPenDoc)));
	return (CPenDoc*)m_pDocument;
}
#endif //_DEBUG

COLORREF Col;
int Size;
// CPenView 메시지 처리기

#include"CLine.h"
void CPenView::OnMouseMove(UINT nFlags, CPoint point)
{
	
	if (nFlags == MK_LBUTTON) {
		CPenDoc* pDoc = GetDocument();//모든 데이터는 Document에 저장 
		CLine* pLine = new CLine(opnt, point,Size,Col);//새로운 객체 생성
		pDoc->m_oa.Add(pLine);//만들어진 포인터를 m_oa에 집어 넣음
		Invalidate(FALSE);//화면을 새로그려주는것
	}
	opnt = point;
	CView::OnMouseMove(nFlags, point);
	
}


void CPenView::OnSelectColor()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		Col = dlg.GetColor();
		
	}
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CPenView::OnSize1()
{
	Size = 1;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CPenView::OnSize4()
{
	Size = 4;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CPenView::OnSize8()
{
	Size = 8;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CPenView::OnSize16()
{
	Size = 16;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CPenView::OnSize32()
{
	Size = 32;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
