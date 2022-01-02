//
// Created by leonardo on 29/12/21.
//

#include "Timer.h"

wxBEGIN_EVENT_TABLE(Timer, wxPanel)
    EVT_BUTTON(8, Timer::clickOn)
    EVT_TIMER(9, Timer::timerOn)
wxEND_EVENT_TABLE()

Timer::Timer(wxWindow *parent): wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(550,300)) {
    mainS=new wxBoxSizer(wxVERTICAL);
    sceltaS=new wxBoxSizer(wxHORIZONTAL);

    wxFont main_font=wxFont(20, wxFONTFAMILY_ROMAN, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD);
    wxFont font=wxFont(17, wxFONTFAMILY_ROMAN, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL);

    orologioB=new wxButton(this,5,"Orologio", wxDefaultPosition, wxSize(168,50));
    orologioB->SetFont(main_font);

    timerB=new wxButton(this, 6, "Timer",wxDefaultPosition, wxSize(168,50));
    timerB->SetFont(main_font);
    timerB->Enable(false);
    timerB->SetBackgroundColour(*wxLIGHT_GREY);

    cronoB=new wxButton(this, 7, "Cronometro",wxDefaultPosition,wxSize(184,50));
    cronoB->SetFont(main_font);

    sizeIns=new wxBoxSizer(wxHORIZONTAL);
    bloccoOre = new wxTextCtrl(this, wxID_ANY, "00", wxDefaultPosition, wxSize(150,40), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER);
    bloccoOre ->SetFont(main_font);
    bloccoSepA = new wxTextCtrl(this, wxID_ANY, ":", wxDefaultPosition, wxSize(35,40), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER | wxTE_READONLY | wxBORDER_NONE);
    bloccoSepA ->SetFont(main_font);
    bloccoMin = new wxTextCtrl(this, wxID_ANY, "00", wxDefaultPosition, wxSize(150,40), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER);
    bloccoMin ->SetFont(main_font);
    bloccoSepB = new wxTextCtrl(this, wxID_ANY, ":", wxDefaultPosition, wxSize(35,40), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER | wxTE_READONLY | wxBORDER_NONE);
    bloccoSepB ->SetFont(main_font);
    bloccoSec = new wxTextCtrl(this, wxID_ANY, "00", wxDefaultPosition, wxSize(150,40), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER);
    bloccoSec ->SetFont(main_font);


    sizeIns->Add(bloccoOre, 0, wxEXPAND | wxALL, 5);
    sizeIns->Add(bloccoSepA, 0, wxEXPAND | wxALL, 0);
    sizeIns->Add(bloccoMin, 0, wxEXPAND | wxALL, 5);
    sizeIns->Add(bloccoSepB, 0, wxEXPAND | wxALL, 0);
    sizeIns->Add(bloccoSec, 0, wxEXPAND | wxALL, 5);

    startB=new wxButton(this, 8, "Start", wxDefaultPosition, wxDefaultSize);
    startB->SetFont(font);
    startB->SetBackgroundColour(*wxGREEN);

    blocco=new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH2|wxTE_CENTER|wxBORDER_NONE);
    blocco->SetFont(main_font);

    sceltaS->Add(orologioB, 0, wxEXPAND| wxALL, 5);
    sceltaS->Add(timerB, 0, wxEXPAND| wxALL, 5);
    sceltaS->Add(cronoB, 0, wxEXPAND| wxALL, 5);

    mainS->Add(sceltaS,0,wxEXPAND|wxALL,0);
    mainS->Add(sizeIns,0,wxEXPAND|wxALL,0);
    mainS->Add(startB,0,wxEXPAND|wxALL,5);
    mainS->Add(blocco,1,wxEXPAND|wxALL,5);

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
    if(type->isAcceso() && type->getTempoRimanente()=="00:00:00") {
        startB->SetLabel("Start");
        startB->SetBackgroundColour(*wxGREEN);
    }
    std::string tempo=type->getTempoRimanente();
    blocco->SetValue(tempo);
}

void Timer::clickOn(wxCommandEvent &) {
    if(type->isAcceso()){
        startB->SetLabel("Start");
        startB->SetBackgroundColour(*wxGREEN);
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
        startB->SetBackgroundColour(*wxRED);
        type->start();
    }
}

TimerType * Timer::getType() const {
    return type;
}