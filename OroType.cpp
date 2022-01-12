//
// Created by leonardo on 24/12/21.
//
#include <ctime>
#include "OroType.h"

OroType::OroType(wxEvtHandler* p) {
    timerNuovo=new wxTimer(p,4);
    timerNuovo->Start(intervallo);
}

OroType::~OroType() {
    timerNuovo->Stop();
    delete timerNuovo;
}

std::string OroType::toString(tipo t) {
    if(t==tipo::data) {
        std::string data_gma;
        std::string gW;
        std::string me;
        if (giornoW == 1)
            gW = "Lunedi";
        else if (giornoW == 2)
            gW = "Martedi";
        else if (giornoW == 3)
            gW = "Mercoledi";
        else if (giornoW == 4)
            gW = "Giovedi";
        else if (giornoW == 5)
            gW = "Venerdi";
        else if (giornoW == 6)
            gW = "Sabato";
        else
            gW = "Domenica";

        if (mese == 1)
            me = "Gennaio";
        else if (mese == 2)
            me = "Febbraio";
        else if (mese == 3)
            me = "Marzo";
        else if (mese == 4)
            me = "Aprile";
        else if (mese == 5)
            me = "Maggio";
        else if (mese == 6)
            me = "Giugno";
        else if (mese == 7)
            me = "Luglio";
        else if (mese == 8)
            me = "Agosto";
        else if (mese == 9)
            me = "Settembre";
        else if (mese == 10)
            me = "Ottobre";
        else if (mese == 11)
            me = "Novembre";
        else
            me = "Dicembre";

        return gW + " " + std::to_string(giorno) + " " + me + " " + std::to_string(anno);
    }
    std::string m = std::to_string(minuti);
    std::string s = std::to_string(secondi);

    if(t==tipo::or_c) {
        std::string orario;
        std::string h = std::to_string(ore);


        if (ore >= 10)
            orario = orario + h + ":";
        else
            orario = "0" + h + ":";
        if (minuti >= 10)
            orario = orario + m + ":";
        else
            orario = orario + "0" + m + ":";
        if (secondi >= 10)
            orario = orario + s;
        else
            orario = orario + "0" + s;
        return orario;
    }

    if(t==tipo::or_ap) {
        std::string ap_orario;

        if (ore >= 12) {
            ap_orario = "pm ";
            if (ore - 12 < 10)
                ap_orario = ap_orario + "0" + std::to_string(ore - 12);
            else
                ap_orario = ap_orario + std::to_string(ore - 12);
        } else {
            ap_orario = "am ";
            if (ore < 10)
                ap_orario = ap_orario + "0" + std::to_string(ore);
            else
                ap_orario = ap_orario + std::to_string(ore);
        }
        ap_orario = ap_orario + ":";
        if (minuti >= 10)
            ap_orario = ap_orario + m + ":";
        else
            ap_orario = ap_orario + "0" + m + ":";
        if (secondi >= 10)
            ap_orario = ap_orario + s;
        else
            ap_orario = ap_orario + "0" + s;
        return ap_orario;
    }
}

void OroType::adesso() {
    std::time_t t=std::time(0);
    std::tm* orarioCorr=std::localtime(&t);
    ore=orarioCorr->tm_hour;
    minuti=orarioCorr->tm_min;
    secondi=orarioCorr->tm_sec;
    giorno=orarioCorr->tm_mday;
    giornoW=orarioCorr->tm_wday;
    mese=orarioCorr->tm_mon+1;
    anno=orarioCorr->tm_year+1900;
}

wxTimer *OroType::getTimer() const {
    return timerNuovo;
}

int OroType::getOre() const {
    return ore;
}

void OroType::setOre(int ore) {
    OroType::ore = ore;
}

int OroType::getMinuti() const {
    return minuti;
}

void OroType::setMinuti(int minuti) {
    OroType::minuti = minuti;
}

int OroType::getSecondi() const {
    return secondi;
}

void OroType::setSecondi(int secondi) {
    OroType::secondi = secondi;
}

int OroType::getGiorno() const {
    return giorno;
}

void OroType::setGiorno(int giorno) {
    OroType::giorno = giorno;
}

int OroType::getGiornoW() const {
    return giornoW;
}

void OroType::setGiornoW(int giornoW) {
    OroType::giornoW = giornoW;
}

int OroType::getMese() const {
    return mese;
}

void OroType::setMese(int mese) {
    OroType::mese = mese;
}

int OroType::getAnno() const {
    return anno;
}

void OroType::setAnno(int anno) {
    OroType::anno = anno;
}

