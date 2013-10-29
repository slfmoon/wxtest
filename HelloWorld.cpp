//============================================================================
// Name        : HelloWorld.cpp
// Author      : Hiroyuki Nagata
// Version     : 1.0.0
// Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
// Description : Hello World in wxWidgets with Japanese
// Licence     : wxWindows Library Licence, Version 3.1
//============================================================================

#include "HelloWorld.h"

enum {
Minimal_Quit = wxID_EXIT, Minimal_About = wxID_ABOUT
};

BEGIN_EVENT_TABLE(HelloWorld, wxFrame)
EVT_MENU(Minimal_Quit, HelloWorld::OnQuit)
EVT_MENU(Minimal_About, HelloWorld::OnAbout)
END_EVENT_TABLE()

/**
 * wxFrameクラスのコンストラクタ
 */
HelloWorld::HelloWorld(const wxString& title) :
wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(640, 480)) {

// メニューバーの設置
wxMenu *fileMenu = new wxMenu;

wxMenu *helpMenu = new wxMenu;
helpMenu->Append(Minimal_About, "&ヘルプ...\tF1", "このプログラムについて");
fileMenu->Append(Minimal_Quit, "&終了\tAlt-X", "このプログラムを終了します");

wxMenuBar *menuBar = new wxMenuBar();
menuBar->Append(fileMenu, "&ファイル");
menuBar->Append(helpMenu, "&ヘルプ");

SetMenuBar(menuBar);

// ステータスバーを設置する
CreateStatusBar(2);
SetStatusText("wxWidgetsにようこそ!");

Centre();
}
/**
 * 閉じるを押した際のイベント
 */
void HelloWorld::OnQuit(wxCommandEvent& event) {
Close(true);
}
/**
 * ヘルプを押した際のイベント
 */
void HelloWorld::OnAbout(wxCommandEvent& event) {

wxMessageBox(wxString::Format("%sにようこそ!\n\n"
"これはwxWidgetsの最小アプリです\n"
"%s環境で動作しています", wxVERSION_STRING, wxGetOsDescription()),
"このアプリケーションについて", wxOK | wxICON_INFORMATION, this);
}