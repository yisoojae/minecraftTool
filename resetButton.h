#pragma once
#include "fillButton.h"
class resetButton :
    public fillButton
{
public:
    DECLARE_MESSAGE_MAP()
        afx_msg void OnBnClicked();
};

