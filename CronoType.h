//
// Created by leonardo on 22/12/21.
//

#ifndef TIMER_PROJECT_TSL_CRONOTYPE_H
#define TIMER_PROJECT_TSL_CRONOTYPE_H

#include<wx/wx.h>

class CronoType {
public:
    CronoType(wxEvtHandler* p);

    virtual ~CronoType();
    void start();
    void stop();
    void calcolaT();
    void tempo();
    bool spento();
    void azzera();
    const std::string &getT() const;
private:
    wxTimer* timerNuovo=nullptr;
    static const int intervallo=10;
    int ore=0;
    int min=0;
    int sec=0;
    int cent=0;
    std::string t="00:00:00,00";
    bool fermo=true;
};


#endif //TIMER_PROJECT_TSL_CRONOTYPE_H
