//
// Created by leonardo on 29/12/21.
//

#include "TimerType.h"

TimerType::TimerType(wxEvtHandler *p) {
    timerN=new wxTimer(p,9);
}

TimerType::~TimerType() {
    delete timerN;
}

int TimerType::getSrimanenti() const {
    return Srimanenti;
}

void TimerType::setSrimanenti(int srimanenti) {
    Srimanenti = srimanenti;
}

int TimerType::getMrimanenti() const {
    return Mrimanenti;
}

void TimerType::setMrimanenti(int mrimanenti) {
    Mrimanenti = mrimanenti;
}

int TimerType::getOrimanenti() const {
    return Orimanenti;
}

void TimerType::setOrimanenti(int orimanenti) {
    Orimanenti = orimanenti;
}

bool TimerType::isAcceso() const {
    return acceso;
}

void TimerType::setAcceso(bool acceso) {
    TimerType::acceso = acceso;
}

const std::string &TimerType::getTempoRimanente() const {
    return tempoRimanente;
}

void TimerType::setTempoRimanente(const std::string &tempoRimanente) {
    TimerType::tempoRimanente = tempoRimanente;
}

void TimerType::tempo() {
    std::string time;
    std::string h=std::to_string(Orimanenti);
    std::string m=std::to_string(Mrimanenti);
    std::string s=std::to_string(Srimanenti);
    if(Orimanenti>=10)
        time=time+h+":";
    else
        time=time+"0"+h+":";
    if(Mrimanenti>=10)
        time=time+m+":";
    else
        time=time+"0"+m+":";
    if(Srimanenti>=10)
        time=time+s;
    else
        time=time+"0"+s;
    tempoRimanente=time;
}

void TimerType::calcolaT() {
    while(Srimanenti>59){
        Srimanenti-=60;
        Mrimanenti++;
    }

    while(Mrimanenti>59){
        Mrimanenti-=60;
        Orimanenti++;
    }

    if(Srimanenti==0 && Mrimanenti==0 && Orimanenti==0){
        timerN->Stop();
        acceso=false;
    }
    else{
        if(Srimanenti==0 && Mrimanenti==0){
            Orimanenti--;
            Srimanenti=59;
            Mrimanenti=59;
        }
        else{
            if(Srimanenti==0){
                Mrimanenti--;
                Srimanenti=59;
            } else{
                Srimanenti--;
            }
        }
    }
}

void TimerType::start() {
    timerN->Start(intervallo);
    acceso=true;
}

void TimerType::stop() {
    timerN->Stop();
    acceso=false;
}