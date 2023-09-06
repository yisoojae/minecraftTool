// inputValue.cpp: 구현 파일
//

#include "pch.h"
#include "mincraftTool.h"
#include "inputValue.h"


// inputValue

IMPLEMENT_DYNAMIC(inputValue, CEdit)

inputValue::inputValue()
{
	preEdit = nullptr, nextEdit = nullptr;
}

inputValue::~inputValue()
{
}


BEGIN_MESSAGE_MAP(inputValue, CEdit)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()



// inputValue 메시지 처리기




BOOL inputValue::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	switch (pMsg->message)
	{
	case WM_KEYDOWN:
		switch (pMsg->wParam)
		{
		case VK_TAB:
			if (GetKeyState(VK_SHIFT) & 0x8000) ::SetFocus(preEdit->m_hWnd);
			else ::SetFocus(nextEdit->m_hWnd);
			return true;
		}
	}

	return CEdit::PreTranslateMessage(pMsg);
}
