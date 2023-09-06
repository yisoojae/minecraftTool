#pragma once


// inputValue

class inputValue : public CEdit
{
	DECLARE_DYNAMIC(inputValue)

public:
	inputValue();
	virtual ~inputValue();
	inputValue *preEdit, *nextEdit;

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};


