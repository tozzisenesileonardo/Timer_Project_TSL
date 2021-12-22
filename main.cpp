#include <wx/wx.h>
#include <iostream>
#include "Orologio.h"
#include "Timer.h"

using namespace std;

int main(){

    Orologio* clock= new Orologio();
    //clock->startOrologio();

    Timer* timer= new Timer(0,1,122);
    timer->startTimer();
    return 0;
}