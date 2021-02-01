#include "board.h"
#include <QCoreApplication>
#include<QtDebug>

Board::Board(QWidget *parent)
    : QWidget(parent)
{
    initCells();
    creatLayout();
}

void Board::initCells()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            cells[i][j] = new Cell(QPoint(i,j));
            connect(cells[i][j],SIGNAL(getPosition(QPoint)),this,SLOT(getPosition(QPoint)));
        }
    //info = new DisplayInfo();
    imageLabel = new QLabel();
    imageLabel->setPixmap(QPixmap::fromImage(QImage(":/images/gomokiLogo.jpg")));
}

void Board::creatLayout()
{
    glay = new QGridLayout(this);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            glay->addWidget(cells[i][j],i,j);
    glay->addWidget(imageLabel,0,10,7,2);
    glay->addWidget(&info,3,10,8,2,Qt::AlignCenter);
    setFixedSize(sizeHint());
}

void Board::resetCells()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            cells[i][j]->clearImage();
        }
}

void Board::getPosition(QPoint position)
{
    currentCellPosition = position;
}

Board::~Board()
{
}

QPoint Board::getClickLocation()
{
    currentCellPosition.setX(-1);
    while (currentCellPosition.x()<0 || cells[currentCellPosition.x()][currentCellPosition.y()]->isImageSet()) {
        QCoreApplication::processEvents();
    }
    return currentCellPosition;
}

void Board::setManImage(int x, int y)
{
    //if(x<)
    info.computerTurn();
    cells[x][y]->setImage(QImage(":/images/man.png"));
}

void Board::setComputerImage(int x, int y)
{
    info.manTurn();
    cells[x][y]->setImage(QImage(":/images/computer.png"));
}

void Board::man_won(QPoint start, QPoint end)
{
    info.manWin();
    int increI = (end.x()-start.x())/4;
    int increJ = (end.y()-start.y())/4;
    //qDebug()<<"increI "<<increI<<" "<<increJ;
    for(int i=0;i<5;i++){
        cells[start.x()+increI*i][start.y()+increJ*i]->setImage(QImage(":/images/man_won.png"));
        //qDebug()<<start.x()+increI*i<< " "<<start.y()+increJ*i;
    }
}

void Board::computer_won(QPoint start, QPoint end)
{
    info.computerWin();
    int increI = (end.x()-start.x())/4;
    int increJ = (end.y()-start.y())/4;
    //qDebug()<<"increI "<<increI<<" "<<increJ;
    for(int i=0;i<5;i++){
        cells[start.x()+increI*i][start.y()+increJ*i]->setImage(QImage(":/images/computer_won.png"));
    }
}
