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
 * wxFrame�N���X�̃R���X�g���N�^
 */
HelloWorld::HelloWorld(const wxString& title) :
wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(640, 480)) {

// ���j���[�o�[�̐ݒu
wxMenu *fileMenu = new wxMenu;

wxMenu *helpMenu = new wxMenu;
helpMenu->Append(Minimal_About, "&�w���v...\tF1", "���̃v���O�����ɂ���");
fileMenu->Append(Minimal_Quit, "&�I��\tAlt-X", "���̃v���O�������I�����܂�");

wxMenuBar *menuBar = new wxMenuBar();
menuBar->Append(fileMenu, "&�t�@�C��");
menuBar->Append(helpMenu, "&�w���v");

SetMenuBar(menuBar);

// �X�e�[�^�X�o�[��ݒu����
CreateStatusBar(2);
SetStatusText("wxWidgets�ɂ悤����!");

Centre();
}
/**
 * ������������ۂ̃C�x���g
 */
void HelloWorld::OnQuit(wxCommandEvent& event) {
Close(true);
}
/**
 * �w���v���������ۂ̃C�x���g
 */
void HelloWorld::OnAbout(wxCommandEvent& event) {

wxMessageBox(wxString::Format("%s�ɂ悤����!\n\n"
"�����wxWidgets�̍ŏ��A�v���ł�\n"
"%s���œ��삵�Ă��܂�", wxVERSION_STRING, wxGetOsDescription()),
"���̃A�v���P�[�V�����ɂ���", wxOK | wxICON_INFORMATION, this);
}