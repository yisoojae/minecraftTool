#include "pch.h"
#include "inputNum.h"
#include "mincraftToolDlg.h"
BEGIN_MESSAGE_MAP(inputNum, inputValue)
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()


BOOL inputNum::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	wchar_t* inputText = (wchar_t*)malloc(20);
	if (inputText)
	{
		short keyCtrl	= GetKeyState(VK_CONTROL) & 0x8000,
			keyArt		= GetKeyState(VK_MENU) & 0x8000,
			keyShift	= GetKeyState(VK_SHIFT) & 0x8000;
		if (whichPos & 0b1000) // Y좌표면
		{
			if (whichPos & 0b1) // 위층이면
			{
				::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->y1), inputText, 10);
				_itos(_tstoi(inputText) + ((keyCtrl ? 10 : 1) * ((zDelta > 0) ? 1 : -1)), inputText);
				((inputNum&)(((CmincraftToolDlg*)GetParent())->y1)).SetWindowText(inputText);
				::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->x1), inputText, 10);
				_itos(_tstoi(inputText) + (((keyCtrl ? 10 : 1) * ((zDelta > 0) ? 1 : -1)) * (keyArt ? -1 : (keyShift ? 1 : 0))), inputText);
				((inputNum&)(((CmincraftToolDlg*)GetParent())->x1)).SetWindowText(inputText);
				::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->z1), inputText, 10);
				_itos(_tstoi(inputText) + (((keyCtrl ? 10 : 1) * ((zDelta > 0) ? 1 : -1)) * (keyArt ? -1 : (keyShift ? 1 : 0))), inputText);
				((inputNum&)(((CmincraftToolDlg*)GetParent())->z1)).SetWindowText(inputText);
			}
			else
			{
				::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->y2), inputText, 10);
				_itos(_tstoi(inputText) + ((keyCtrl ? 10 : 1) * ((zDelta > 0) ? 1 : -1)), inputText);
				((inputNum&)(((CmincraftToolDlg*)GetParent())->y2)).SetWindowText(inputText);
				::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->x2), inputText, 10);
				_itos(_tstoi(inputText) + (((keyCtrl ? 10 : 1) * ((zDelta > 0) ? 1 : -1)) * (keyArt ? -1 : (keyShift ? 1 : 0))), inputText);
				((inputNum&)(((CmincraftToolDlg*)GetParent())->x2)).SetWindowText(inputText);
				::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->z2), inputText, 10);
				_itos(_tstoi(inputText) + (((keyCtrl ? 10 : 1) * ((zDelta > 0) ? 1 : -1)) * (keyArt ? -1 : (keyShift ? 1 : 0))), inputText);
				((inputNum&)(((CmincraftToolDlg*)GetParent())->z2)).SetWindowText(inputText);
			}
		}
		else
		{
			if (whichPos & 0b1) // 위층이면
			{
				::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->x1), inputText, 10);
				_itos(_tstoi(inputText) + (((keyCtrl ? 10 : 1) * ((zDelta > 0) ? 1 : -1)) * ((whichPos & 0b100) ? 1 : (keyArt ? -1 : keyShift ? 1 : 0))), inputText);
				((inputNum&)(((CmincraftToolDlg*)GetParent())->x1)).SetWindowText(inputText);
				::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->z1), inputText, 10);
				_itos(_tstoi(inputText) + (((keyCtrl ? 10 : 1) * ((zDelta > 0) ? 1 : -1)) * ((whichPos & 0b10000) ? 1 : (keyArt ? -1 : keyShift ? 1 : 0))), inputText);
				((inputNum&)(((CmincraftToolDlg*)GetParent())->z1)).SetWindowText(inputText);
				::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->y1), inputText, 10);
				_itos(_tstoi(inputText) + (((keyCtrl ? 10 : 1) * ((zDelta > 0) ? 1 : -1)) * (keyArt & GetKeyState(VK_SHIFT) ? 1 : 0)), inputText);
				((inputNum&)(((CmincraftToolDlg*)GetParent())->y1)).SetWindowText(inputText);
			}
			else
			{
				::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->x2), inputText, 10);
				_itos(_tstoi(inputText) + (((keyCtrl ? 10 : 1) * ((zDelta > 0) ? 1 : -1)) * ((whichPos & 0b100) ? 1 : (keyArt ? -1 : keyShift ? 1 : 0))), inputText);
				((inputNum&)(((CmincraftToolDlg*)GetParent())->x2)).SetWindowText(inputText);
				::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->z2), inputText, 10);
				_itos(_tstoi(inputText) + (((keyCtrl ? 10 : 1) * ((zDelta > 0) ? 1 : -1)) * ((whichPos & 0b10000) ? 1 : (keyArt ? -1 : keyShift ? 1 : 0))), inputText);
				((inputNum&)(((CmincraftToolDlg*)GetParent())->z2)).SetWindowText(inputText);
				::GetWindowTextW((inputNum&)(((CmincraftToolDlg*)GetParent())->y2), inputText, 10);
				_itos(_tstoi(inputText) + (((keyCtrl ? 10 : 1) * ((zDelta > 0) ? 1 : -1)) * (keyArt & GetKeyState(VK_SHIFT) ? 1 : 0)), inputText);
				((inputNum&)(((CmincraftToolDlg*)GetParent())->y2)).SetWindowText(inputText);
			}
		}
	}

	free(inputText);

	return inputValue::OnMouseWheel(nFlags, zDelta, pt);
}

void inputNum::_itos(int num, wchar_t* buf)
{
	wchar_t* tmp = (wchar_t*)malloc(20);
	wchar_t* num_s = tmp;
	if (tmp)
	{
		if (num < 0)
		{
			*buf++ = L'-';
			num *= -1;
		}
		while (num > 9)
		{
			*num_s++ = (num % 10) + 0x30;
			num /= 10;
		}
		*num_s = num + 0x30;
		*(num_s + 1) = L'\0';
		while (tmp != num_s)
		{
			*buf++ = *num_s--;
		}
		*buf++ = *num_s;
		*buf = L'\0';
	}

	free(tmp);

	return;
}