// inputCombo.cpp: 구현 파일
//

#include "pch.h"
#include "mincraftTool.h"
#include "inputCombo.h"
#include "mincraftToolDlg.h"


// inputCombo

IMPLEMENT_DYNAMIC(inputCombo, CComboBox)

inputCombo::inputCombo()
{
	preEdit = nullptr, nextEdit = nullptr;
}

inputCombo::~inputCombo()
{
}


BEGIN_MESSAGE_MAP(inputCombo, CComboBox)
END_MESSAGE_MAP()



// inputCombo 메시지 처리기




BOOL inputCombo::PreTranslateMessage(MSG* pMsg)
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
		case VK_RETURN:
			CString comboText;
			GetWindowText(comboText);
			int nLen = WideCharToMultiByte(CP_UTF8, 0, comboText, lstrlenW(comboText), 0, 0, 0, 0);
			LPSTR strUtf8 = (LPSTR)malloc(nLen + 3);
			if (!strUtf8) return true;
			WideCharToMultiByte(CP_UTF8, 0, comboText, lstrlenW(comboText), strUtf8, nLen, 0, 0);
			strUtf8[nLen] = '\r'; strUtf8[nLen + 1] = '\n';
			strUtf8[nLen + 2] = 0;

			CFile dFile;
			if (!dFile.Open(_T("element.txt"), CFile::modeCreate | CFile::modeReadWrite | CFile::modeNoTruncate, NULL))
			{
				free(strUtf8);
				return true;
			}
			LPSTR tmpStrUtf8 = (LPSTR)malloc(dFile.GetLength() + 1);
			if (!tmpStrUtf8) return true;
			LPSTR pStr = tmpStrUtf8;
			LPSTR pStr2 = tmpStrUtf8;
			if (dFile.Read(tmpStrUtf8, (int)strlen(tmpStrUtf8)) != dFile.GetLength()) goto readFile_End;
			while (*pStr)
			{
				if (*pStr == '\r')
				{
					LPSTR tmp = (LPSTR)malloc(pStr - pStr2 + 3);
					if (!tmp) goto readFile_End;
					LPSTR tmp_tmp = tmp;
					while (pStr != pStr2)
					{
						*(tmp_tmp++) = *(pStr2++);
					}
					*(tmp_tmp++) = '\r'; *(tmp_tmp++) = '\n'; *tmp_tmp = 0;
					if (!strcmp(tmp, strUtf8)) // strutf8에 \r\n 붙어있음.
					{
						free(tmp);
						free(tmpStrUtf8);
						dFile.Close();
						free(strUtf8);
						return true;
					}
					free(tmp);
					++pStr; ++pStr2; ++pStr2;
				}
				++pStr;
			}


			dFile.SeekToEnd();
			dFile.Write(strUtf8, strlen(strUtf8));
		readFile_End:
			free(tmpStrUtf8);
			dFile.Close();
			free(strUtf8);
			
			((CmincraftToolDlg*)GetParent())->renewCombo(true);
			return true;
		}
	}

	return CComboBox::PreTranslateMessage(pMsg);
}
