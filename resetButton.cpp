#include "pch.h"
#include "resetButton.h"
#include "mincraftToolDlg.h"
BEGIN_MESSAGE_MAP(resetButton, fillButton)
	ON_CONTROL_REFLECT(BN_CLICKED, &resetButton::OnBnClicked)
END_MESSAGE_MAP()


void resetButton::OnBnClicked()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	((CEdit&)(((CmincraftToolDlg*)GetParent())->resultFill)).SetWindowText(L"");

	::SetFocus(fillButton::pOldWnd->m_hWnd);
}
