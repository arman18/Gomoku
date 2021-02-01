#ifndef DISPLAYINFO_H
#define DISPLAYINFO_H

#include <QCheckBox>
#include <QPushButton>
#include <QWidget>
#include <qboxlayout.h>
#include <qlabel.h>
class DisplayInfo : public QWidget
{
    Q_OBJECT
public:
    int restartBtnClick=0;
    explicit DisplayInfo(QWidget *parent = nullptr);
    void manWin();
    void computerWin();
    void draw();
    void manTurn();
    void computerTurn();
    int getButtonClick();

signals:
private:
    int nextBtnClick=0;
    const QString manWinMsg = "Congratulations...";
    const QString manLoseMsg = "You Lose...";
    const QString drawMsg = "Draw...";
    int winComputerCnt = 0;
    int winManCnt = 0;
    QLabel *lblWinLabel,*lblManScore,*lblComputerScore;
    QPushButton *btnReStart,*btnNext;
    QCheckBox *ckbxMan,*ckbxComputer;
    QGridLayout *gridLay;
    void initUi();
    void createLayout();

};

#endif // DISPLAYINFO_H
