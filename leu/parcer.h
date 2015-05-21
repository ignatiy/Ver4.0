#ifndef PARCER_H
#define PARCER_H

#include <QVector>
#include <QObject>
#include <QWidget>
#include "leu/parcer.h"

class parcer : public QObject
{
    Q_OBJECT
public:

    explicit parcer(QObject *parent = 0);

    void getAllX();
    void getAllY();
    void clearX();
    void clearY();
    void clearAll();

bool isDataOk(QString strX , QString strY);


signals:

public slots:

private:
QVector<int> *vctX;
QVector<int> *vctY;
};

#endif // PARCER_H
