#pragma once
#include "inputValue.h"
class inputNum :
    public inputValue
{
public:
    DECLARE_MESSAGE_MAP()
        afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
    void _itos(int, wchar_t*);
};

