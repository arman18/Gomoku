#include "Uibridge.h"
#include <QDebug>
#include <iostream>

Uibridge::Uibridge(QObject *parent) : QObject(parent)
{

}

int count = 1;

int Uibridge::showLog(int n)
{
    int x = (n / 10) + 1;
    int y = (n % 10) + 1;
    qDebug() << x << " " << y;
    count=count+1;
    return count;
}

int Uibridge::countRet()
{

    return count;
}

