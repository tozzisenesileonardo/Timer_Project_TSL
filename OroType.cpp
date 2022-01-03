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
    std::string gW;
    std::string me;
    std::string ap_orario;

    if(giornoW==1)
        gW="Lunedi";
    else if(giornoW==2)
        gW="Martedi";
    else if(giornoW==3)
        gW="Mercoledi";
    else if(giornoW==4)
        gW="Giovedi";
    else if(giornoW==5)
        gW="Venerdi";
    else if(giornoW==6)
        gW="Sabato";
    else
        gW="Domenica";

    if(mese==1)
        me="Gennaio";
    else if(mese==2)
        me="Febbraio";
    else if(mese==3)
        me="Marzo";
    else if(mese==4)
        me="Aprile";
    else if(mese==5)
        me="Maggio";
    else if(mese==6)
        me="Giugno";
    else if(mese==7)
        me="Luglio";
    else if(mese==8)
        me="Agosto";
    else if(mese==9)
        me="Settembre";
    else if(mese==10)
        me="Ottobre";
    else if(mese==11)
        me="Novembre";
    else
        me="Dicembre";

    data_gma=gW+" "+std::to_string(giorno)+" "+me+" "+std::to_string(anno);
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
    giornoW=orarioCorr->tm_wday;
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

void OroType::setGiornoW(int gw) {
    OroType::giornoW=gw;
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