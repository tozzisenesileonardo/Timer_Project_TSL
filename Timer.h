//
// Created by leonardo on 21/07/21.
//

#ifndef TIMER_PROJECT_TSL_TIMER_H
#define TIMER_PROJECT_TSL_TIMER_H


class Timer {
private:
    int ore;
    int minuti;
    int sec;

    void display();
public:
    int getOre() const;

    void setOre(int ore);

    int getMinuti() const;

    void setMinuti(int minuti);

    int getSec() const;

    void setSec(int sec);

    Timer( int h, int m, int s);
    ~Timer();
    void startTimer();
};


#endif //TIMER_PROJECT_TSL_TIMER_H
