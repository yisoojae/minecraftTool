// fillButton.cpp: 구현 파일
//

#include "pch.h"
#include "mincraftTool.h"
#include "fillButton.h"
#include "mincraftToolDlg.h"


// fillButton

IMPLEMENT_DYNAMIC(fillButton, CButton)

CWnd* fillButton::pOldWnd = nullptr;
fillButton::fillButton()
{
}

fillButton::~fillButton()
{
}


BEGIN_MESSAGE_MAP(fillButton, CButton)
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()



// fillButton 메시지 처리기




void fillButton::OnSetFocus(CWnd* pOldWnd)
{
	CButton::OnSetFocus(pOldWnd);
	if (pOldWnd != &((CmincraftToolDlg*)GetParent())->copyPaste1
		&& pOldWnd != &((CmincraftToolDlg*)GetParent())->copyPaste2
		&& pOldWnd != &((CmincraftToolDlg*)GetParent())->addFill
		&& pOldWnd != &((CmincraftToolDlg*)GetParent())->resetResult)
	{
		fillButton::pOldWnd = pOldWnd;
	}

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
