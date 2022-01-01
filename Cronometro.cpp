//
// Created by leonardo on 30/12/21.
//

#include "Cronometro.h"

wxBEGIN_EVENT_TABLE(Cronometro, wxPanel)
EVT_BUTTON(12, Cronometro::cronoOn)
EVT_BUTTON(13, Cronometro::cronoAzz)
EVT_TIMER(14, Cronometro::timerOn)
wxEND_EVENT_TABLE()

Cronometro::Cronometro(wxWindow *parent): wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(550,300)) {
    mainS=new wxBoxSizer(wxVERTICAL);
    sceltaS=new wxBoxSizer(wxHORIZONTAL);
    contS=new wxBoxSizer(wxHORIZONTAL);

    wxFont main_font=wxFont(20, wxFONTFAMILY_ROMAN, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD);
    wxFont font=wxFont(17, wxFONTFAMILY_ROMAN, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL);

    blocco=new wxTextCtrl(this, wxID_ANY,"00:00:00,00", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE| wxTE_READONLY | wxTE_RICH2 | wxTE_CENTER | wxBORDER_NONE);
    blocco->SetFont(main_font);

    orologioB=new wxButton(this,10,"Orologio");
    orologioB->SetFont(main_font);

    timerB=new wxButton(this, 11, "Timer");
    timerB->SetFont(main_font);

    cronoB=new wxButton(this, 12, "Cronometro");
    cronoB->SetFont(main_font);
    cronoB->Enable(false);
    cronoB->SetBackgroundColour(*wxLIGHT_GREY);

    avvia=new wxButton(this, 12, "Avvia");
    avvia->SetFont(font);

    azzera=new wxButton(this, 13, "Azzera");
    azzera->SetFont(font);

    sceltaS->Add(orologioB, 0, wxEXPAND| wxALL, 5);
    sceltaS->Add(timerB, 0, wxEXPAND| wxALL, 5);
    sceltaS->Add(cronoB, 0, wxEXPAND| wxALL, 5);

    contS->Add(avvia,0,wxEXPAND|wxALL,5);
    contS->Add(azzera,0,wxEXPAND|wxALL,5);

    mainS->Add(sceltaS,0,wxEXPAND|wxALL,0);
    mainS->Add(contS,0,wxEXPAND|wxALL,0);
    mainS->Add(blocco,1,wxEXPAND|wxALL,5);

    SetSizerAndFit(mainS);
    SetAutoLayout(true);

    type=new CronoType(this);
}

Cronometro::~Cronometro() {
    delete type;
}

void Cronometro::timerOn(wxTimerEvent &) {
    type->calcolaT();
    type->tempo();
    std::string t=type->getT();
    blocco->SetValue(t);
}

void Cronometro::cronoOn(wxCommandEvent &){
    if(type->spento()){
        type->start();
        avvia->SetLabel("Ferma");
    }
    else{
        type->stop();
        avvia->SetLabel("Avvia");
    }
}

void Cronometro::cronoAzz(wxCommandEvent &){
    type->azzera();
    std::string t=type->getT();
    blocco->SetValue(t);
    avvia->SetLabel("Avvia");
}

CronoType *Cronometro::getType() const {
    return type;
}
