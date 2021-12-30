//
// Created by leonardo on 29/12/21.
//

#ifndef TIMER_PROJECT_TSL_TIMER_H
#define TIMER_PROJECT_TSL_TIMER_H

#include "TimerType.h"
#include <wx/wx.h>

class Timer: public wxPanel{
public:
    Timer(wxWindow* parent);
    virtual ~Timer();

    TimerType *getType() const;
    wxDECLARE_EVENT_TABLE();
    void timerOn(wxTimerEvent&);
    void clickOn(wxCommandEvent&);

private:
    wxBoxSizer* mainS=nullptr;
    wxBoxSizer* sceltaS=nullptr;
    wxBoxSizer* sizeIns=nullptr;

    wxTextCtrl* bloccoOre=nullptr;
    wxTextCtrl* bloccoSepA=nullptr;
    wxTextCtrl* bloccoMin=nullptr;
    wxTextCtrl* bloccoSepB=nullptr;
    wxTextCtrl* bloccoSec=nullptr;
    wxTextCtrl* blocco=nullptr;

    wxButton* orologioB=nullptr;
    wxButton* timerB=nullptr;
    wxButton* cronoB=nullptr;
    wxButton* startB=nullptr;

    TimerType* type=nullptr;
};



#endif //TIMER_PROJECT_TSL_TIMER_H
