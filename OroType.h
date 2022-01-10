//
// Created by leonardo on 24/12/21.
//

#ifndef TIMER_PROJECT_TSL_OROTYPE_H
#define TIMER_PROJECT_TSL_OROTYPE_H

#include<wx/wx.h>

class OroType {
public:
    OroType(wxEvtHandler* p);
    virtual ~OroType();

    void creaD();
    void creaT();

    std::string stampa(int i);

private:
    static const int intervallo=1000;
    int ore;
    int minuti;
    int secondi;
    int giorno;
    int giornoW;
    int mese;
    int anno;
    std::string data;
    std::string ampm_orario;
    std::string orario_classico;
    wxTimer* timerNuovo=nullptr;
};


#endif //TIMER_PROJECT_TSL_OROTYPE_H
