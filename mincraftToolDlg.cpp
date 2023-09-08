
// mincraftToolDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "mincraftTool.h"
#include "mincraftToolDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmincraftToolDlg 대화 상자



CmincraftToolDlg::CmincraftToolDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MINCRAFTTOOL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmincraftToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmincraftToolDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CmincraftToolDlg 메시지 처리기

BOOL CmincraftToolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	element.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, { 10,10,100,30 }, this, 1);
	element.nextEdit = &x1;
	element.preEdit = &z2;
	x1.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, { 110,10,200,30 }, this, 2);
	x1.nextEdit = &y1;
	x1.preEdit = &element;
	y1.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, { 210,10,300,30 }, this, 3);
	y1.nextEdit = &z1;
	y1.preEdit = &x1;
	z1.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, { 310,10,400,30 }, this, 4);
	z1.nextEdit = &x2;
	z1.preEdit = &y1;
	copyPaste1.Create(L"복사", WS_CHILD | WS_VISIBLE, { 410,0,480,35 }, this, 8);
	copyPaste2.Create(L"복사", WS_CHILD | WS_VISIBLE, { 410,35,480,70 }, this, 9);
	x2.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, { 110,40,200,60 }, this, 5);
	x2.nextEdit = &y2;
	x2.preEdit = &z1;
	y2.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, { 210,40,300,60 }, this, 6);
	y2.nextEdit = &z2;
	y2.preEdit = &x2;
	z2.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, { 310,40,400,60 }, this, 7);
	z2.nextEdit = &element;
	z2.preEdit = &y2;
	resultFill.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL, { 10,90,400,200 }, this, 10);
	addFill.Create(L"추가", WS_CHILD | WS_VISIBLE, { 410,90,480,140 }, this, 11);
	resetResult.Create(L"초기화", WS_CHILD | WS_VISIBLE, { 410,150,480,200 }, this, 12);
	copyText.Create(L"클립보드", WS_CHILD | WS_VISIBLE, { 10,210,480,320 }, this, 13);

	x1.SetWindowText(L"0");
	y1.SetWindowText(L"0");
	z1.SetWindowText(L"0");
	x2.SetWindowText(L"0");
	y2.SetWindowText(L"0");
	z2.SetWindowText(L"0");
	x1.whichPos = 0b1 | 0b100;
	y1.whichPos = 0b1 | 0b1000;
	z1.whichPos = 0b1 | 0b10000;
	x2.whichPos = 0b10 | 0b100;
	y2.whichPos = 0b10 | 0b1000;
	z2.whichPos = 0b10 | 0b10000;
	copyPaste1.N = false;
	copyPaste2.N = true;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CmincraftToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmincraftToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CmincraftToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CmincraftToolDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	switch (pMsg->message)
	{
	case WM_KEYDOWN:
		switch (pMsg->wParam)
		{
		case VK_ESCAPE:
			::SetFocus(element.m_hWnd);
		case VK_RETURN:
			return false;
		}
	case WM_SYSKEYDOWN:
		switch (pMsg->wParam)
		{
		case VK_MENU:
			return true;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
