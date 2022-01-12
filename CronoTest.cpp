//
// Created by leonardo on 10/01/22.
//


#include "../MainFrame.h"
#include "../Cronometro.h"
#include "gtest/gtest.h"


class CronoTest:public::testing::Test{
protected:
    virtual void SetUp();
    virtual void TearDown();

    MainFrame* mainFrame;
    Cronometro* crono;
};

void CronoTest::SetUp() {
    mainFrame=new MainFrame();
    crono=new Cronometro(mainFrame);
}

void CronoTest::TearDown() {
    delete mainFrame;
}

TEST_F(CronoTest, CheckStart){
    crono->getType()->start();
    bool flag=crono->getType()->spento();
    ASSERT_TRUE(!flag);
}

TEST_F(CronoTest, CheckStop){
    crono->getType()->start();
    crono->getType()->stop();
    ASSERT_TRUE(crono->getType()->spento());
}

TEST_F(CronoTest, CheckAzz){
    for(int i=0;i<200;i++)
    crono->getType()->calcolaT();
    crono->getType()->azzera();
    crono->getType()->tempo();

    std::string tempoAt=crono->getType()->getT();
    ASSERT_TRUE(tempoAt.compare("00:00:00,00")==0);
}

TEST_F(CronoTest, CheckInc){
    for(int i=0;i<200;i++)
    crono->getType()->calcolaT();

    crono->getType()->tempo();
    std::string tempoAt=crono->getType()->getT();
    ASSERT_TRUE(tempoAt.compare("00:00:02,00")==0);
}