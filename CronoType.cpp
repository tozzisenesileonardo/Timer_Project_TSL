//
// Created by leonardo on 22/12/21.
//

#include "CronoType.h"

CronoType::CronoType(wxEvtHandler* parent) {
    timerNuovo= new wxTimer(parent, 14);
}

CronoType::~CronoType() {
    delete timerNuovo;
}

void CronoType::start() {
    timerNuovo->Start(intervallo);
    fermo=false;
}

void CronoType::stop() {
    timerNuovo->Stop();
    fermo=true;
}

void CronoType::tempo() {
    std::string time;
    std::string h=std::to_string(ore);
    std::string m=std::to_string(min);
    std::string s=std::to_string(sec);
    std::string c=std::to_string(cent);
    if(ore>10)
        time=ore+":";
    else
        time="0"+h+":";
    if(min>10)
        time=min+":";
    else
        time="0"+m+":";
    if(sec>10)
        time=sec+":";
    else
        time="0"+s+":";
    if(cent>10)
        time=cent;
    else
        time="0"+c+":";
    t=time;
}

void CronoType::calcolaT() {
    if(cent==99)
        sec++;
    if(sec==59)
        min++;
    if(min=59)
        ore++;
}

void CronoType::azzera() {
    if(fermo==false) {
        timerNuovo->Stop();
        fermo = true;
    }
    ore=0;
    min=0;
    sec=0;
    cent=0;
    t="00:00:00,00";
}

const std::string &CronoType::getT() const {
    return t;
}

bool CronoType::spento() {
    return fermo;
}
