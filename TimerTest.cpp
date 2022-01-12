//
// Created by leonardo on 10/01/22.
//

#include "../MainFrame.h"
#include "../Timer.h"
#include "gtest/gtest.h"

class TimerTest:public::testing::Test{
protected:
    virtual void SetUp();
    virtual void TearDown();

    MainFrame* mainFrame;
    Timer* timer;
};

void TimerTest::SetUp() {
    mainFrame=new MainFrame();
    timer=new Timer(mainFrame);

    timer->getType()->setOrimanenti(00);
    timer->getType()->setMrimanenti(30);
    timer->getType()->setSrimanenti(00);
}

void TimerTest::TearDown() {
    delete mainFrame;
}

TEST_F(TimerTest, CorrectAv){   //controlla il corretto avanzamento del tempo
    timer->getType()->tempo();
    std::string tempo1=timer->getType()->getTempoRimanente();

    timer->getType()->calcolaT();
    timer->getType()->tempo();

    std::string tempo2=timer->getType()->getTempoRimanente();
    ASSERT_TRUE(tempo1.compare(tempo2)!=0);
}

TEST_F(TimerTest, CheckStart){  //controlla il corretto avvio del Timer
    timer->getType()->start();
    ASSERT_TRUE(timer->getType()->isAcceso());
}

TEST_F(TimerTest, CheckStop){   //controlla il corretto stop del Timer
    timer->getType()->start();
    timer->getType()->stop();

    ASSERT_TRUE(!(timer->getType()->isAcceso()));
}

TEST_F(TimerTest, CheckInc){    //controlla il corretto andamento
    timer->getType()->start();

    for(int i=0;i<10;i++){
        sleep(1);
        timer->getType()->calcolaT();
    }
    timer->getType()->tempo();
    std::string tempoRim=timer->getType()->getTempoRimanente();
    ASSERT_TRUE(tempoRim.compare("00:29:50")==0);
}


