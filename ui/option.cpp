#include "option.h"
#include <QDebug>


Option::Option(QWidget *parent) : QMainWindow(parent)
{
setMinimumSize(320,320);
setWindowTitle(tr("Без названия"));



lbl = new QLabel(this);
lbl->setGeometry(30,20,180,60);
lbl->setWordWrap(true);
lbl->setText(lbl->text() + "Программа STM32_DumpEDIT sdfgsdf  sdgdf g sd bsdf sdb dsfbsdfb");



pbtn = new QPushButton("ОК" , this );
pbtn->setGeometry(110,280,100,20);
pbtn->setStyleSheet("QPushButton { background-color : #e0dedf ; color: #ff0000 }");
connect(pbtn, SIGNAL(clicked()), this,SLOT(quit()));


}

void Option::quit(){
qDebug()<<"quit";
QWidget::close();
}
