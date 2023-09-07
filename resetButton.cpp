#include "pch.h"
#include "resetButton.h"
#include "mincraftToolDlg.h"
BEGIN_MESSAGE_MAP(resetButton, fillButton)
	ON_CONTROL_REFLECT(BN_CLICKED, &resetButton::OnBnClicked)
END_MESSAGE_MAP()


void resetButton::OnBnClicked()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CEdit&)(((CmincraftToolDlg*)GetParent())->resultFill)).SetWindowText(L"");

	::SetFocus(fillButton::pOldWnd->m_hWnd);
}
