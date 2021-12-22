//
// Created by leonardo on 21/07/21.
//

#include "Orologio.h"
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include<wx/wx.h>
int Orologio::getOre() const {
    return ore;
}

void Orologio::setOre(int ore) {
    Orologio::ore = ore;
}

int Orologio::getMinuti() const {
    return minuti;
}

void Orologio::setMinuti(int minuti) {
    Orologio::minuti = minuti;
}

int Orologio::getSec() const {
    return sec;
}

void Orologio::setSec(int sec) {
    Orologio::sec = sec;
}

int Orologio::getGiorno() const {
    return giorno;
}

void Orologio::setGiorno(int giorno) {
    Orologio::giorno = giorno;
}

int Orologio::getMese() const {
    return mese;
}

void Orologio::setMese(int mese) {
    Orologio::mese = mese;
}

int Orologio::getAnno() const {
    return anno;
}

void Orologio::setAnno(int anno) {
    Orologio::anno = anno;
}

void Orologio::oraCorrente() {
    std::time_t tempo= std::time(0);    //metto in tempo il tempo attuale
    std::tm* now = std::localtime(&tempo);
    ore=now->tm_hour;
    minuti=now->tm_min;
    sec=now->tm_sec;
    giorno=now->tm_mday;
    mese=(now->tm_mon)+1;
    anno=(now->tm_year)+1900;
}
void Orologio::startOrologio() {
    while(true){
        oraCorrente(); //imposta l'ora
        display();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //il thread orologio dorme per un secondo
    }
}

void Orologio::display() {
    std::cout<< "Anno: "<< anno<< " Mese: "<< mese << " Giorno: "<< giorno <<std::endl;
    std::cout<< "Ore: "<< ore<< " Minuti: "<< minuti << " Secondi: "<< sec <<std::endl;
}

Orologio::Orologio(wxWindow *parent):wxPanel(parent, wxID_ANY,wxDefaultPosition, wxDefaultSize){

}