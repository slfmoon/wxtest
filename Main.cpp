//============================================================================
// Name        : Main.cpp
// Author      : Hiroyuki Nagata
// Version     : 1.0.0
// Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
// Description : Hello World in wxWidgets with Japanese
// Licence     : wxWindows Library Licence, Version 3.1
//============================================================================
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "HelloWorld.h"

/**
 * wxApp�̃N���X�錾
 */
class MyApp: public wxApp {
public:
virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

/**
 * wxApp�̎���
 */
bool MyApp::OnInit()
{
HelloWorld* hello = new HelloWorld("wxWidgets��HelloWorld!!");
hello->Show(true);

    return true;
}