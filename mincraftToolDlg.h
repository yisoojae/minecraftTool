
// mincraftToolDlg.h: 헤더 파일
//

#pragma once
#include "inputValue.h"
#include "fillButton.h"
#include "copyButton.h"
#include "resetButton.h"
#include "addButton.h"
#include "inputNum.h"


// CmincraftToolDlg 대화 상자
class CmincraftToolDlg : public CDialogEx
{
// 생성입니다.
public:
	CmincraftToolDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	inputValue element;
	inputNum x1, x2, y1, y2, z1, z2;
	CEdit resultFill;
	copyButton copyPaste;
	addButton addFill;
	resetButton resetResult;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MINCRAFTTOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
