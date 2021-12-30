//
// Created by leonardo on 29/12/21.
//

#include "Orologio.h"
#include <ctime>

wxBEGIN_EVENT_TABLE(Orologio, wxPanel)
EVT_TIMER(4, Orologio::timerOn)
wxEND_EVENT_TABLE()

Orologio::Orologio(wxWindow *parent): wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize) {
    mainS=new wxBoxSizer(wxVERTICAL);
    sceltaS=new wxBoxSizer(wxHORIZONTAL);

    wxFont font=wxFont(15, wxFONTFAMILY_ROMAN, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL);

    blocco=new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE| wxTE_READONLY | wxTE_RICH2 | wxTE_CENTER | wxBORDER_NONE);
    blocco->SetFont(font);
    ap_blocco=new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE| wxTE_READONLY | wxTE_RICH2 | wxTE_CENTER | wxBORDER_NONE);
    ap_blocco->SetFont(font);
    data_blocco=new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE| wxTE_READONLY | wxTE_RICH2 | wxTE_CENTER | wxBORDER_NONE);
    data_blocco->SetFont(font);

    orologioB=new wxButton(this,1,"Orologio");
    orologioB->SetFont(font);
    orologioB->Enable(false);

    timerB=new wxButton(this, 2, "Timer");
    timerB->SetFont(font);

    cronoB=new wxButton(this, 3, "Cronometro");
    cronoB->SetFont(font);

    sceltaS->Add(orologioB, 0, wxEXPAND| wxALL, 5);
    sceltaS->Add(timerB, 0, wxEXPAND| wxALL, 5);
    sceltaS->Add(cronoB, 0, wxEXPAND| wxALL, 5);

    mainS->Add(sceltaS,0,wxALIGN_CENTER|wxALL,0);
    mainS->Add(blocco,1,wxALIGN_CENTER|wxALL,5);
    mainS->Add(ap_blocco,1,wxALIGN_CENTER|wxALL,5);
    mainS->Add(data_blocco,1,wxALIGN_CENTER|wxALL,5);

    SetSizerAndFit(mainS);
    SetAutoLayout(true);

    type=new OroType(this);
}

Orologio::~Orologio() {
    delete type;
}

void Orologio::timerOn(wxTimerEvent &) {
    type->creaT();
    type->creaD();
    blocco->SetValue(type->stampa(0));
    ap_blocco->SetValue(type->stampa(1));
    data_blocco->SetValue(type->stampa(2));
}

OroType *Orologio::getType() const {
    return type;
}
