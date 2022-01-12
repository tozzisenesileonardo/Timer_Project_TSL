//
// Created by leonardo on 24/12/21.
//

#ifndef TIMER_PROJECT_TSL_OROTYPE_H
#define TIMER_PROJECT_TSL_OROTYPE_H

#include<wx/wx.h>
enum class tipo{or_c,or_ap,data};
class OroType {
public:
    OroType(wxEvtHandler* p);
    virtual ~OroType();
    wxTimer *getTimer() const;
    std::string toString(tipo t);
    void adesso();

    int getOre() const;

    void setOre(int ore);

    int getMinuti() const;

    void setMinuti(int minuti);

    int getSecondi() const;

    void setSecondi(int secondi);

    int getGiorno() const;

    void setGiorno(int giorno);

    int getGiornoW() const;

    void setGiornoW(int giornoW);

    int getMese() const;

    void setMese(int mese);

    int getAnno() const;

    void setAnno(int anno);

private:
    static const int intervallo=1000;
    int ore;
    int minuti;
    int secondi;
    int giorno;
    int giornoW;
    int mese;
    int anno;
    wxTimer* timerNuovo=nullptr;
};


#endif //TIMER_PROJECT_TSL_OROTYPE_H
