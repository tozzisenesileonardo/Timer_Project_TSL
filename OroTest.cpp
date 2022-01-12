//
// Created by leonardo on 10/01/22.
//


#include "../MainFrame.h"
#include "../Orologio.h"
#include "gtest/gtest.h"


class OroTest:public::testing::Test{
protected:
    virtual void SetUp();
    virtual void TearDown();

    MainFrame* mainFrame;
    Orologio* oro;
};

void OroTest::SetUp() {
    mainFrame=new MainFrame();
    oro=new Orologio(mainFrame);
}

void OroTest::TearDown() {
    delete mainFrame;
}

TEST_F(OroTest, CheckIncOrario){    //controlla cambiamento orario in formato classico
    oro->getType()->getTimer()->Notify();
    std::string tempoA=oro->getType()->toString(tipo::or_c);
    sleep(3);
    oro->getType()->getTimer()->Notify();
    std::string tempoB=oro->getType()->toString(tipo::or_c);

    ASSERT_TRUE(tempoA.compare(tempoB)!=0);
}

TEST_F(OroTest, CheckIncOrarioAMPM){    //controlla cambiamento orario in formato AM/PM
    oro->getType()->getTimer()->Notify();
    std::string tempoA=oro->getType()->toString(tipo::or_ap);
    sleep(3);
    oro->getType()->getTimer()->Notify();
    std::string tempoB=oro->getType()->toString(tipo::or_ap);

    ASSERT_TRUE(tempoA.compare(tempoB)!=0);
}

TEST_F(OroTest, CheckOrario){   //controlla la corretta visualizzazzione dell'orario
    oro->getType()->setOre(15);
    oro->getType()->setMinuti(25);
    oro->getType()->setSecondi(40);
    std::string classicOr=oro->getType()->toString(tipo::or_c);

    ASSERT_TRUE(classicOr.compare("15:25:40")==0);
}

TEST_F(OroTest, CheckOrarioAMPM){   //controlla la corretta visualizzazzione dell'orario in formato AM/PM
    oro->getType()->setOre(15);
    oro->getType()->setMinuti(25);
    oro->getType()->setSecondi(40);
    std::string ampmOr=oro->getType()->toString(tipo::or_ap);

    ASSERT_TRUE(ampmOr.compare("pm 03:25:40")==0);
}

TEST_F(OroTest, CheckData){ //controlla la corretta visualizzazione della data
    oro->getType()->setGiornoW(1);
    oro->getType()->setGiorno(10);
    oro->getType()->setMese(1);
    oro->getType()->setAnno(2022);
    std::string dataF= oro->getType()->toString(tipo::data);

    ASSERT_TRUE(dataF.compare("Lunedi 10 Gennaio 2022")==0);
}
