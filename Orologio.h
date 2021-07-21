//
// Created by leonardo on 21/07/21.
//

#ifndef TIMER_PROJECT_TSL_OROLOGIO_H
#define TIMER_PROJECT_TSL_OROLOGIO_H

class Orologio{
private:
    int ore;
    int minuti;
    int sec;
    int giorno;
    int mese;
    int anno;

    void oraCorrente(); //imposta nell'orologio l'ora
    void display();
public:

    Orologio(){};
    ~Orologio(){};

    int getOre() const;

    void setOre(int ore);

    int getMinuti() const;

    void setMinuti(int minuti);

    int getSec() const;

    void setSec(int sec);

    int getGiorno() const;

    void setGiorno(int giorno);

    int getMese() const;

    void setMese(int mese);

    int getAnno() const;

    void setAnno(int anno);

    void startOrologio();

};
#endif //TIMER_PROJECT_TSL_OROLOGIO_H
