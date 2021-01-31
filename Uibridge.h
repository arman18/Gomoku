#ifndef UIBRIDGE_H
#define UIBRIDGE_H

#include <QObject>

class Uibridge : public QObject
{
    Q_OBJECT
public:
    explicit Uibridge(QObject *parent = nullptr);
    Q_INVOKABLE int showLog(int n);
    Q_INVOKABLE int countRet();
signals:

};

#endif // UIBRIDGE_H
