#pragma once
#include "fillButton.h"
class copyButton :
    public fillButton
{
public:
    copyButton();
    DECLARE_MESSAGE_MAP()
        afx_msg void OnBnClicked();
public:
    bool N;
};

