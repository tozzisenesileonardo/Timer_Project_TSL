//
// Created by leonardo on 23/08/21.
//

#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)
//Quando siamo nell'orologio
    EVT_BUTTON(2,MainFrame::buildTimer)
    EVT_BUTTON(3,MainFrame::buildCrono)
//Quando siamo nel Timer
    EVT_BUTTON(5,MainFrame::buildOrologio)
    EVT_BUTTON(7,MainFrame::buildCrono)
//Quando siamo nel Cronometro
    EVT_BUTTON(10,MainFrame::buildOrologio)
    EVT_BUTTON(11,MainFrame::buildTimer)
wxEND_EVENT_TABLE()

MainFrame::MainFrame():wxFrame(NULL, wxID_ANY, "Orologio", wxDefaultPosition, wxSize(550,300)){
    pannelloCorrente=new Orologio(this);
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

