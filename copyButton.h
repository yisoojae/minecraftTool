#pragma once
#include "fillButton.h"
class copyButton :
    public fillButton
{
public:
    DECLARE_MESSAGE_MAP()
        afx_msg void OnBnClicked();
};

