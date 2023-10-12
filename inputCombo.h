#pragma once


// inputCombo

class inputCombo : public CComboBox
{
	DECLARE_DYNAMIC(inputCombo)

public:
	inputCombo();
	virtual ~inputCombo();
	CWnd* preEdit, * nextEdit;

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};


