//
// Created by leonardo on 23/08/21.
//

#ifndef TIMER_PROJECT_TSL_MAINFRAME_H
#define TIMER_PROJECT_TSL_MAINFRAME_H

#include<wx/wx.h>
#include "Cronometro.h"
#include "Orologio.h"
#include "Timer.h"

class MainFrame : public wxFrame{
public:
    MainFrame();

    virtual ~MainFrame();
    wxDECLARE_EVENT_TABLE();
private:
    wxPanel* pannelloCorrente=nullptr;

    void buildTimer(wxCommandEvent&);
    void buildOrologio(wxCommandEvent&);
    void buildCrono(wxCommandEvent&);


};


#endif //TIMER_PROJECT_TSL_MAINFRAME_H
