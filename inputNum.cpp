#include "pch.h"
#include "inputNum.h"
BEGIN_MESSAGE_MAP(inputNum, inputValue)
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()


BOOL inputNum::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	wchar_t* inputText = (wchar_t*)malloc(20);
	if (inputText)
	{
		::GetWindowText(m_hWnd, inputText, 10);
		_itos(_tstoi(inputText) + (((GetKeyState(VK_CONTROL) & 0x8000) ? 10 : 1) * ((zDelta > 0) ? 1 : -1)), inputText);
		SetWindowText(inputText);
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