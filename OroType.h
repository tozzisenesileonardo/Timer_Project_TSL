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
    void setGiorno(int g);
    void setMese(int me);
    void setAnno(int a);
    void setOra(int h);
    void setMin(int m);
    void setSec(int s);
    std::string stampa(int i);
    wxTimer* getT() const;

private:
    static const int intervallo=1000;
    int ore;
    int minuti;
    int secondi;
    int giorno;
    int mese;
    int anno;
    std::string type[3];
    wxTimer* timerNuovo=nullptr;
};


#endif //TIMER_PROJECT_TSL_OROTYPE_H
