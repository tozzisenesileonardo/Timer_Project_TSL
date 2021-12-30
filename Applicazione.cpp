//
// Created by leonardo on 23/08/21.
//

#include "Applicazione.h"

Applicazione::Applicazione() {}


Applicazione::~Applicazione() {}

bool Applicazione::OnInit() {
    frame=new MainFrame();
    frame->Show();
    return true;
}