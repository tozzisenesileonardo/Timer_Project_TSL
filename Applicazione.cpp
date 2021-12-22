//
// Created by leonardo on 23/08/21.
//

#include "Applicazione.h"

wxIMPLEMENT_APP(Applicazione);

Applicazione::Applicazione() {}


Applicazione::~Applicazione() {}

bool Applicazione::OnInit() {
    frame=new MainFrame();
    frame->Show();

    return true;
}