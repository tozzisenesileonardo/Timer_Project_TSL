//
// Created by leonardo on 29/12/21.
//

#include "Timer.h"

wxBEGIN_EVENT_TABLE(Timer, wxPanel)
    EVT_BUTTON(8, Timer::clickOn)
    EVT_TIMER(9, Timer::timerOn)
wxEND_EVENT_TABLE()

Timer::Timer(wxWindow *parent): wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize) {
    mainS=new wxBoxSizer(wxVERTICAL);
    sceltaS=new wxBoxSizer(wxHORIZONTAL);

    wxFont font=wxFont(15, wxFONTFAMILY_ROMAN, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL);

    orologioB=new wxButton(this,5,"Orologio", wxDefaultPosition, wxDefaultSize);
    orologioB->SetFont(font);

    timerB=new wxButton(this, 6, "Timer",wxDefaultPosition, wxDefaultSize);
    timerB->SetFont(font);
    timerB->Enable(false);

    cronoB=new wxButton(this, 7, "Cronometro");
    cronoB->SetFont(font);

    sizeIns=new wxBoxSizer(wxHORIZONTAL);
    bloccoOre = new wxTextCtrl(this, wxID_ANY, "00", wxDefaultPosition, wxSize(80,30), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER);
    bloccoOre ->SetFont(font);
    bloccoSepA = new wxTextCtrl(this, wxID_ANY, ":", wxDefaultPosition, wxSize(30,30), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER | wxTE_READONLY | wxBORDER_NONE);
    bloccoSepA ->SetFont(font);
    bloccoMin = new wxTextCtrl(this, wxID_ANY, "00", wxDefaultPosition, wxSize(80,30), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER);
    bloccoMin ->SetFont(font);
    bloccoSepB = new wxTextCtrl(this, wxID_ANY, ":", wxDefaultPosition, wxSize(30,30), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER | wxTE_READONLY | wxBORDER_NONE);
    bloccoSepB ->SetFont(font);
    bloccoSec = new wxTextCtrl(this, wxID_ANY, "00", wxDefaultPosition, wxSize(80,30), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER);
    bloccoSec ->SetFont(font);


    sizeIns->Add(bloccoOre, 0, wxEXPAND | wxALL, 5);
    sizeIns->Add(bloccoSepA, 0, wxEXPAND | wxALL, 0);
    sizeIns->Add(bloccoMin, 0, wxEXPAND | wxALL, 5);
    sizeIns->Add(bloccoSepB, 0, wxEXPAND | wxALL, 0);
    sizeIns->Add(bloccoSec, 0, wxEXPAND | wxALL, 5);

    startB=new wxButton(this, 8, "Start", wxDefaultPosition, wxDefaultSize);
    startB->SetFont(font);

    blocco=new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH2|wxTE_CENTER|wxBORDER_NONE);
    blocco->SetFont(font);

    sceltaS->Add(orologioB, 0, wxEXPAND| wxALL, 5);
    sceltaS->Add(timerB, 0, wxEXPAND| wxALL, 5);
    sceltaS->Add(cronoB, 0, wxEXPAND| wxALL, 5);

    mainS->Add(sceltaS,0,wxALIGN_CENTER|wxALL,0);
    mainS->Add(sizeIns,0,wxALIGN_CENTER|wxALL,0);
    mainS->Add(startB,0,wxALIGN_CENTER|wxALL,5);
    mainS->Add(blocco,1,wxALIGN_CENTER|wxALL,5);

    SetSizerAndFit(mainS);
    SetAutoLayout(true);

    type=new TimerType(this);
}

Timer::~Timer() {
    delete type;
}

void Timer::timerOn(wxTimerEvent &) {
    type->calcolaT();
    type->tempo();
    if(type->isAcceso() && type->getTempoRimanente()=="00:00:00")
        startB->SetLabel("Start");
    std::string tempo=type->getTempoRimanente();
    blocco->SetValue(tempo);
}

void Timer::clickOn(wxCommandEvent &) {
    if(type->isAcceso()){
        startB->SetLabel("Start");
        type->setAcceso(false);
        type->stop();
    }
    else{
        type->setAcceso(true);
        type->setOrimanenti(wxAtoi(bloccoOre->GetValue()));
        type->setMrimanenti(wxAtoi(bloccoMin->GetValue()));
        type->setSrimanenti(wxAtoi(bloccoSec->GetValue()));

        bloccoOre->SetValue("00");
        bloccoMin->SetValue("00");
        bloccoSec->SetValue("00");

        startB->SetLabel("Ferma");
        type->start();
    }
}

TimerType * Timer::getType() const {
    return type;
}