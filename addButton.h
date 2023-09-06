#pragma once
#include "fillButton.h"
class addButton :
    public fillButton
{
public:
    DECLARE_MESSAGE_MAP()
        afx_msg void OnBnClicked();
};

