//
// Created by leonardo on 23/08/21.
//

#ifndef TIMER_PROJECT_TSL_APPLICAZIONE_H
#define TIMER_PROJECT_TSL_APPLICAZIONE_H

#include<wx/wx.h>
#include "MainFrame.h"

class Applicazione : public wxApp{
public:
    Applicazione();
    ~Applicazione();

    virtual bool OnInit();

private:
    MainFrame* frame=nullptr;
};


#endif //TIMER_PROJECT_TSL_APPLICAZIONE_H
