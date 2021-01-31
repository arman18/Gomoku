#include "displayinfo.h"

#include <QCoreApplication>

DisplayInfo::DisplayInfo(QWidget *parent) : QWidget(parent)
{
    initUi();
    createLayout();
}


void DisplayInfo::manWin()
{
    lblManScore->setNum(++winManCnt);
    lblWinLabel->setText(manWinMsg);
    ckbxMan->setChecked(false);
    ckbxComputer->setChecked(false);
    btnReStart->setDisabled(false);
    btnNext->setDisabled(false);
}

void DisplayInfo::computerWin()
{
    lblComputerScore->setNum(++winComputerCnt);
    lblWinLabel->setText(manLoseMsg);
    ckbxMan->setChecked(false);
    ckbxComputer->setChecked(false);
    btnReStart->setDisabled(false);
    btnNext->setDisabled(false);
}

void DisplayInfo::manTurn()
{
    ckbxMan->setChecked(true);
    ckbxComputer->setChecked(false);
}

void DisplayInfo::computerTurn()
{
    ckbxMan->setChecked(false);
    ckbxComputer->setChecked(true);

}

int DisplayInfo::getButtonClick()
{
    nextBtnClick = 0; restartBtnClick = 0;
    while(true){
        QCoreApplication::processEvents();
        if(nextBtnClick) return nextBtnClick;
        if(restartBtnClick) return restartBtnClick;
    }
}

void DisplayInfo::initUi()
{
    lblWinLabel = new QLabel("");
    lblManScore = new QLabel("0");
    lblComputerScore = new QLabel("0");
    btnReStart = new QPushButton("Restart");
    connect(btnReStart,&QPushButton::clicked,[this](){btnNext->setDisabled(true); restartBtnClick=1;});
    btnNext = new QPushButton("Play");
    btnNext->setDisabled(true);
    connect(btnNext,&QPushButton::clicked,[this](){btnReStart->setDisabled(false);btnNext->setDisabled(true);nextBtnClick=2;});
    ckbxMan = new QCheckBox("You");
    ckbxComputer = new QCheckBox("Computer");
    gridLay = new QGridLayout(this);
}

void DisplayInfo::createLayout()
{
    gridLay->addWidget(lblWinLabel,0,0,1,2,Qt::AlignCenter);
    gridLay->addWidget(btnReStart,1,0);
    gridLay->addWidget(btnNext,1,1);
    gridLay->addWidget(ckbxMan,2,0);
    gridLay->addWidget(lblManScore,3,0,Qt::AlignCenter);
    gridLay->addWidget(ckbxComputer,2,1);
    gridLay->addWidget(lblComputerScore,3,1,Qt::AlignCenter);
}
