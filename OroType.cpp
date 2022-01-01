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

void OroType::creaD() {
    std::string orario;
    std::string data_gma;
    std::string ap_orario;

    data_gma=std::to_string(giorno)+"-"+std::to_string(mese)+"-"+std::to_string(anno);
    std::string h=std::to_string(ore);
    std::string m=std::to_string(minuti);
    std::string s=std::to_string(secondi);

    if(ore>=10)
        orario=orario+h+":";
    else
        orario="0"+h+":";
    if(minuti>=10)
        orario=orario+m+":";
    else
        orario=orario+"0"+m+":";
    if(secondi>=10)
        orario=orario+s;
    else
        orario=orario+"0"+s;

    if(ore>=12){
        ap_orario="pm ";
        if(ore-12<10)
            ap_orario=ap_orario+"0"+std::to_string(ore-12);
        else
            ap_orario=ap_orario+std::to_string(ore-12);
    }
    else{
        ap_orario="am ";
        if(ore<10)
            ap_orario=ap_orario+"0"+std::to_string(ore);
        else
            ap_orario=ap_orario+std::to_string(ore);
    }
    ap_orario=ap_orario+":";
    if(minuti>=10)
        ap_orario=ap_orario+m+":";
    else
        ap_orario=ap_orario+"0"+m+":";
    if(secondi>=10)
        ap_orario=ap_orario+s;
    else
        ap_orario=ap_orario+"0"+s;

    typeDate[0]=data_gma;
    typeDate[1]=orario;
    typeDate[2]=ap_orario;
}


std::string OroType::stampa(int i) {
    if(i>2 || i<0)
        return typeDate[0];
    return typeDate[i];
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