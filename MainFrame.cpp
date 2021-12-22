//
// Created by leonardo on 23/08/21.
//

#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)
//Scelte possibili dall'orologio
    EVT_BUTTON(2,MainFrame::buildTimer)
    EVT_BUTTON(3,MainFrame::buildCrono)
//Scelte possibili dal Timer
    EVT_BUTTON(5,MainFrame::buildOrologio)
    EVT_BUTTON(7,MainFrame::buildCrono)
//Scelte possibili dal cronometro
    EVT_BUTTON(10,MainFrame::buildOrologio)
    EVT_BUTTON(11,MainFrame::buildTimer)
wxEND_EVENT_TABLE()

MainFrame::MainFrame():wxFrame(NULL, wxID_ANY, "Orologio", wxDefaultPosition, wxSize(330,250)){

}

MainFrame::~MainFrame() {

}

void MainFrame::buildTimer(wxCommandEvent&){
    this->SetTitle("Timer");
    pannelloCorrente->Destroy();
    pannelloCorrente=new Timer(this);
}

void MainFrame::buildCrono(wxCommandEvent &) {
    this->SetTitle("Cronometro");
    pannelloCorrente->Destroy();
    pannelloCorrente=new Cronometro(this);
}

void MainFrame::buildOrologio(wxCommandEvent &) {
    this->SetTitle("Orologio");
    pannelloCorrente->Destroy();
    pannelloCorrente=new Orologio(this);
}

