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

std::string OroType::stampa(int i) {
    if(i>1 || i<0)
        return type[0];
    return type[i];
}

void OroType::creaD() {
    std::string orario;
    std::string data_gma;

    data_gma=std::to_string(giorno)+"-"+std::to_string(mese)+"-"+std::to_string(anno);
    std::string h=std::to_string(ore);
    std::string m=std::to_string(minuti);
    std::string s=std::to_string(secondi);
    if(ore>10)
        orario=ore+":";
    else
        orario="0"+h+":";
    if(minuti>10)
        orario=minuti+":";
    else
        orario="0"+m+":";
    if(secondi>10)
        orario=secondi+":";
    else
        orario="0"+s;

    type[0]=data_gma;
    type[1]=orario;
}

void OroType::creaT() {
    std::time_t t=std::time(0);
    std::tm* orarioCorr=std::localtime(&t);
    ore=orarioCorr->tm_hour;
    minuti=orarioCorr->tm_min;
    secondi=orarioCorr->tm_sec;
    giorno=orarioCorr->tm_mday;
    mese=orarioCorr->tm_mon+1;
    anno=orarioCorr->tm_year+1900;
}

void OroType::setOra(int h) {
    OroType::ore=h;
}

void OroType::setMin(int m) {
    OroType::minuti=m;
}

void OroType::setSec(int s) {
    OroType::secondi=s;
}

void OroType::setGiorno(int g) {
    OroType::giorno=g;
}

void OroType::setMese(int me) {
    OroType::mese=me;
}

void OroType::setAnno(int a) {
    OroType::anno=a;
}

wxTimer *OroType::getT() const {
    return timerNuovo;
}