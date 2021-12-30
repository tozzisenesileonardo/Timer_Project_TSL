//
// Created by leonardo on 29/12/21.
//

#ifndef TIMER_PROJECT_TSL_OROLOGIO_H
#define TIMER_PROJECT_TSL_OROLOGIO_H

#include <wx/wx.h>
#include "OroType.h"

class Orologio: public wxPanel{
public:

    Orologio(wxWindow* parent);
    virtual ~Orologio();

    OroType *getType() const;

wxDECLARE_EVENT_TABLE();

private:
    wxBoxSizer* mainS=nullptr;
    wxBoxSizer* sceltaS=nullptr;

    wxTextCtrl* blocco=nullptr;
    wxTextCtrl* ap_blocco=nullptr;
    wxTextCtrl* data_blocco=nullptr;

    wxButton* orologioB=nullptr;
    wxButton* timerB=nullptr;
    wxButton* cronoB=nullptr;

    OroType* type=nullptr;

    void timerOn(wxTimerEvent&);

};


#endif //TIMER_PROJECT_TSL_OROLOGIO_H
