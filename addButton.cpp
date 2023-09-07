#include "pch.h"
#include "addButton.h"
#include "mincraftToolDlg.h"
BEGIN_MESSAGE_MAP(addButton, fillButton)
	ON_CONTROL_REFLECT(BN_CLICKED, &addButton::OnBnClicked)
END_MESSAGE_MAP()


void addButton::OnBnClicked()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	LPWSTR elementText = (LPWSTR)malloc(sizeof(LPWSTR) * 20);
	LPWSTR x1Text = (LPWSTR)malloc(sizeof(LPWSTR) * 10);
	LPWSTR y1Text = (LPWSTR)malloc(sizeof(LPWSTR) * 10);
	LPWSTR z1Text = (LPWSTR)malloc(sizeof(LPWSTR) * 10);
	LPWSTR x2Text = (LPWSTR)malloc(sizeof(LPWSTR) * 10);
	LPWSTR y2Text = (LPWSTR)malloc(sizeof(LPWSTR) * 10);
	LPWSTR z2Text = (LPWSTR)malloc(sizeof(LPWSTR) * 10);
	if (elementText)
	{
		::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->element), elementText, 20);
		if (x1Text)
		{
			::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->x1), x1Text, 10);
			if (y1Text)
			{
				::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->y1), y1Text, 10);
				if (z1Text)
				{
					::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->z1), z1Text, 10);
					if (x2Text)
					{
						::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->x2), x2Text, 10);
						if (y2Text)
						{
							::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->y2), y2Text, 10);
							if (z2Text)
							{
								::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->z2), z2Text, 10);
								LPWSTR boxText = (LPWSTR)malloc(sizeof(LPWSTR) * 1024);
								CString addText;
								addText.Format(_T("fill %s %s %s %s %s %s minecraft:%s\r\n"), x1Text, y1Text, z1Text, x2Text, y2Text, z2Text, elementText);
								LPWSTR tmp = boxText, tmp1 = (LPWSTR)(LPCWSTR)addText;

								if (boxText)
								{
									::GetWindowTextW((CEdit&)(((CmincraftToolDlg*)GetParent())->resultFill), boxText, 1024);
									while (*tmp != L'\0') ++tmp;
									while (*tmp1 != L'\0')
									{
										*tmp++ = *tmp1++;
									}
									*tmp = L'\0';
									((CEdit&)(((CmincraftToolDlg*)GetParent())->resultFill)).SetWindowText(boxText);
								}
								free(boxText);
							}
						}
					}
				}
			}
		}
	}

	free(x1Text); free(y1Text); free(z1Text); free(x2Text); free(y2Text); free(z2Text); free(elementText);

	::SetFocus(fillButton::pOldWnd->m_hWnd);
}
