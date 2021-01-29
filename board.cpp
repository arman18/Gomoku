#include "board.h"
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
            cells[i][j]->setImage(QImage("://images/star.png"));
            connect(cells[i][j],SIGNAL(getPosition(QPoint)),this,SLOT(getPosition(QPoint)));
        }
}

void Board::creatLayout()
{
    glay = new QGridLayout(this);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            glay->addWidget(cells[i][j],i,j);
}

void Board::resedCells()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            cells[i][j]->clearImage();
        }
}

void Board::getPosition(QPoint position)
{
    currentCellPosition = position;
    qDebug()<<position;
}

Board::~Board()
{
}

QPoint Board::getClickLocation()
{
    currentCellPosition.setX(-1);
    while (currentCellPosition.x()<0 || cells[currentCellPosition.x()][currentCellPosition.y()]->isImageSet()) {
        //wait
    }
    return currentCellPosition;
}

void Board::setUserImage(int x, int y)
{
    //if(x<)
    cells[x][y]->setImage(QImage(""));
}

void Board::setComputerImage(int x, int y)
{
    cells[x][y]->setImage(QImage(""));
}
