//
// Created by leonardo on 29/12/21.
//

#ifndef TIMER_PROJECT_TSL_TIMERTYPE_H
#define TIMER_PROJECT_TSL_TIMERTYPE_H

#include <wx/wx.h>
class TimerType {
public:
    TimerType(wxEvtHandler *p);

    virtual ~TimerType();

    int getSrimanenti() const;

    void setSrimanenti(int srimanenti);

    int getMrimanenti() const;

    void setMrimanenti(int mrimanenti);

    int getOrimanenti() const;

    void setOrimanenti(int orimanenti);

    bool isAcceso() const;

    void setAcceso(bool acceso);

    const std::string &getTempoRimanente() const;

    void setTempoRimanente(const std::string &tempoRimanente);

    void start();
    void stop();
    void calcolaT();
    void tempo();

private:
    int Srimanenti;
    int Mrimanenti;
    int Orimanenti;
    bool acceso=false;
    std::string tempoRimanente;
    wxTimer* timerN= nullptr;
    static const int intervallo=1000;

};


#endif //TIMER_PROJECT_TSL_TIMERTYPE_H
