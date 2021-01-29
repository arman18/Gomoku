#ifndef WIDGET_H
#define WIDGET_H

#include "cell.h"

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
    void resedCells();
public slots:
    void getPosition(QPoint position);
public:
    Board(QWidget *parent = nullptr);
    ~Board();
    QPoint getClickLocation();
    void setUserImage(int x,int y);
    void setComputerImage(int x,int y);
};
#endif // WIDGET_H
