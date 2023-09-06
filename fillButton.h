#pragma once


// fillButton

class fillButton : public CButton
{
public:
	static CWnd* pOldWnd;
	DECLARE_DYNAMIC(fillButton)

public:
	fillButton();
	virtual ~fillButton();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSetFocus(CWnd* pOldWnd);
};


