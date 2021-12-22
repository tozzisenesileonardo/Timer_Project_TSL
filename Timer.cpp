//
// Created by leonardo on 21/07/21.
//

#include "Timer.h"
#include <iostream>
#include <thread>

Timer::Timer(int h, int m, int s) {
    while(s>=60){
        m=m+1;
        s=s-60;
    }
    while(m>=60){
        h=h+1;
        m=m-60;
    }
    ore=h;
    minuti=m;
    sec=s;
}

int Timer::getOre() const {
    return ore;
}

void Timer::setOre(int ore) {
    Timer::ore = ore;
}

int Timer::getMinuti() const {
    return minuti;
}

void Timer::setMinuti(int minuti) {
    Timer::minuti = minuti;
}

int Timer::getSec() const {
    return sec;
}

void Timer::setSec(int sec) {
    Timer::sec = sec;
}


void Timer::display() {
    std::cout<< "Ore: "<< ore<< " Minuti: "<< minuti << " Secondi: "<< sec <<std::endl;
}

void Timer::startTimer() {
    while(ore!=0 || minuti!=0 || sec!=0){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        sec--;

        if(sec==-1){
            minuti--;
            sec=59;
        }
        if(minuti==-1){
            ore--;
            minuti=59;
        }
        display();
    }

}