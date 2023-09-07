#include "pch.h"
#include "copyButton.h"
#include "mincraftToolDlg.h"
BEGIN_MESSAGE_MAP(copyButton, fillButton)
	ON_CONTROL_REFLECT(BN_CLICKED, &copyButton::OnBnClicked)
END_MESSAGE_MAP()


copyButton::copyButton()
{
	N = false;
}

void copyButton::OnBnClicked()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	LPWSTR x1Text = (LPWSTR)malloc(sizeof(LPWSTR) * 10);
	LPWSTR y1Text = (LPWSTR)malloc(sizeof(LPWSTR) * 10);
	LPWSTR z1Text = (LPWSTR)malloc(sizeof(LPWSTR) * 10);
	if (N)
	{
		if (x1Text)
		{
			::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->x2), x1Text, 10);
			((inputNum&)(((CmincraftToolDlg*)GetParent())->x1)).SetWindowText(x1Text);
		}
		if (y1Text)
		{
			::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->y2), y1Text, 10);
			((inputNum&)(((CmincraftToolDlg*)GetParent())->y1)).SetWindowText(y1Text);
		}
		if (z1Text)
		{
			::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->z2), z1Text, 10);
			((inputNum&)(((CmincraftToolDlg*)GetParent())->z1)).SetWindowText(z1Text);
		}
	}
	else
	{
		if (x1Text)
		{
			::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->x1), x1Text, 10);
			((inputNum&)(((CmincraftToolDlg*)GetParent())->x2)).SetWindowText(x1Text);
		}
		if (y1Text)
		{
			::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->y1), y1Text, 10);
			((inputNum&)(((CmincraftToolDlg*)GetParent())->y2)).SetWindowText(y1Text);
		}
		if (z1Text)
		{
			::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->z1), z1Text, 10);
			((inputNum&)(((CmincraftToolDlg*)GetParent())->z2)).SetWindowText(z1Text);
		}
	}
	
	free(x1Text); free(y1Text); free(z1Text);

	::SetFocus(fillButton::pOldWnd->m_hWnd);
}
