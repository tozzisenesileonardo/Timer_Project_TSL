//
// Created by leonardo on 29/12/21.
//

#include "Orologio.h"
#include <ctime>

wxBEGIN_EVENT_TABLE(Orologio, wxPanel)
EVT_TIMER(4, Orologio::timerOn)
wxEND_EVENT_TABLE()

Orologio::Orologio(wxWindow *parent): wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(550,300)) {
    mainS=new wxBoxSizer(wxVERTICAL);
    sceltaS=new wxBoxSizer(wxHORIZONTAL);

    wxFont main_font=wxFont(20, wxFONTFAMILY_ROMAN, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD);
    wxFont font=wxFont(17, wxFONTFAMILY_ROMAN, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL);

    blocco=new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE| wxTE_READONLY | wxTE_RICH2 | wxTE_CENTER | wxBORDER_NONE);
    blocco->SetFont(main_font);

    ap_blocco=new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE| wxTE_READONLY | wxTE_RICH2 | wxTE_CENTER | wxBORDER_NONE);
    ap_blocco->SetFont(main_font);

    data_blocco=new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE| wxTE_READONLY | wxTE_RICH2 | wxTE_CENTER | wxBORDER_NONE);
    data_blocco->SetFont(main_font);

    orologioB=new wxButton(this,1,"Orologio", wxDefaultPosition,wxSize(168,50));
    orologioB->SetFont(main_font);
    orologioB->Enable(false);
    orologioB->SetBackgroundColour(*wxLIGHT_GREY);

    timerB=new wxButton(this, 2, "Timer", wxDefaultPosition, wxSize(168,50));
    timerB->SetFont(main_font);

    cronoB=new wxButton(this, 3, "Cronometro", wxDefaultPosition, wxSize(184,50));
    cronoB->SetFont(main_font);

    sceltaS->Add(orologioB, 0, wxEXPAND| wxALL, 5);
    sceltaS->Add(timerB, 0, wxEXPAND| wxALL, 5);
    sceltaS->Add(cronoB, 0, wxEXPAND| wxALL, 5);

    mainS->Add(sceltaS,0,wxEXPAND|wxALL,0);
    mainS->Add(blocco,1,wxEXPAND|wxALL,5);
    mainS->Add(ap_blocco,1,wxEXPAND|wxALL,5);
    mainS->Add(data_blocco,1,wxEXPAND|wxALL,5);

    SetSizerAndFit(mainS);
    SetAutoLayout(true);

    type=new OroType(this);
}

Orologio::~Orologio() {
    delete type;
}

void Orologio::timerOn(wxTimerEvent &) {
    type->adesso();
    blocco->SetValue(type->toString(tipo::or_c));
    ap_blocco->SetValue(type->toString(tipo::or_ap));
    data_blocco->SetValue(type->toString(tipo::data));
}

OroType *Orologio::getType() const {
    return type;
}
