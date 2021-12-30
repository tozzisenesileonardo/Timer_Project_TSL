//
// Created by leonardo on 30/12/21.
//

#ifndef TIMER_PROJECT_TSL_CRONOMETRO_H
#define TIMER_PROJECT_TSL_CRONOMETRO_H


#include<wx/wx.h>
#include "CronoType.h"
class Cronometro: public wxPanel{
public:

    Cronometro(wxWindow* parent);
    virtual ~Cronometro();

    CronoType *getType() const;

private:
    wxBoxSizer* mainS=nullptr;
    wxBoxSizer* sceltaS=nullptr;
    wxBoxSizer* contS=nullptr;

    wxButton* orologioB=nullptr;
    wxButton* timerB=nullptr;
    wxButton* cronoB=nullptr;
    wxButton* avvia=nullptr;
    wxButton* azzera=nullptr;

    wxTextCtrl* blocco=nullptr;
    wxTextCtrl* t_blocco=nullptr;

    CronoType* type=nullptr;

    wxDECLARE_EVENT_TABLE();

    void timerOn(wxTimerEvent&);
    void cronoOn(wxCommandEvent&);
    void cronoAzz(wxCommandEvent&);
};



#endif //TIMER_PROJECT_TSL_CRONOMETRO_H
