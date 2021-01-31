#ifndef WIDGET_H
#define WIDGET_H

#include "cell.h"
#include "displayinfo.h"

#include <QGridLayout>
#include <QWidget>

class Board : public QWidget
{
    Q_OBJECT
private:
    Cell *cells[10][10];
    QPoint currentCellPosition;
    QGridLayout *glay;
    void initCells();
    void creatLayout();

public slots:
    void getPosition(QPoint position);
public:
    Board(QWidget *parent = nullptr);
    ~Board();
    DisplayInfo info;
    QPoint getClickLocation();
    void setManImage(int x,int y);
    void setComputerImage(int x,int y);
    void man_won(QPoint start,QPoint end);
    void computer_won(QPoint start,QPoint end);
    void resetCells();
};
#endif // WIDGET_H
