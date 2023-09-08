#include "pch.h"
#include "clipboardSetting.h"
#include "mincraftToolDlg.h"
BEGIN_MESSAGE_MAP(clipboardSetting, fillButton)
	ON_CONTROL_REFLECT(BN_CLICKED, &clipboardSetting::OnBnClicked)
END_MESSAGE_MAP()


void clipboardSetting::OnBnClicked()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	LPWSTR boxText = (LPWSTR)malloc(sizeof(LPWSTR) * 1024);
	if (boxText)
	{
		::GetWindowTextW((CEdit&)(((CmincraftToolDlg*)GetParent())->resultFill), boxText, 1024);
		HGLOBAL clipData = ::GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, 2048);
		if (clipData)
		{
			LPSTR clipData_s = (LPSTR)::GlobalLock(clipData);
			if (clipData_s)
			{
				USES_CONVERSION;
				LPSTR boxTextA = W2A(boxText);
				if (boxTextA) memcpy(clipData_s, boxTextA, 2048);
				::GlobalUnlock(clipData);
				if (::OpenClipboard(m_hWnd))
				{
					::EmptyClipboard();
					SetClipboardData(CF_TEXT, clipData);
					::CloseClipboard();
				}
			}
		}
	}
	free(boxText);

	::SetFocus(fillButton::pOldWnd->m_hWnd);
}
