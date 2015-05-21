#include "parcer.h"
#include <QDebug>

parcer::parcer(QObject *parent) : QObject(parent)
{
    vctX=new QVector<int>();
    vctY=new QVector<int>();
}

void parcer::getAllX()
{
    for(int i=0;i<vctX->count();i++){
        qDebug()<<vctX->at(i);

    }

}

void parcer::getAllY()
{
    for(int i=0;i<vctY->count();i++){
        qDebug()<<vctY->at(i);

    }
}

void parcer::clearX()
{
    vctX->clear();

}

void parcer::clearY()
{
    vctY->clear();

}

void parcer::clearAll()
{
    vctX->clear();
    vctY->clear();
}


bool parcer::isDataOk(QString strX, QString strY)
{
    bool ok;
    int val;

    val=strX.toInt(&ok);
    if(!ok){return false;}
    vctX->append(val);
    val=strY.toInt(&ok);
    if(!ok){return false;}
    vctY->append(val);
    return ok;

}


