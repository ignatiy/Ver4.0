#include "mainwindow.h"
#include "leu/parcer.h"
#include <QToolBar>
#include <QTextEdit>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QString>
#include <QDir>


MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent){
setMinimumSize(640,480);




tbar = new QToolBar;
tbar->addAction(tr("Открыть"),this,SLOT(open()));
tbar->addSeparator();
tbar->addAction(tr("Сохранить"),this,SLOT(save()));
tbar->addSeparator();
tbar->addAction(tr("резерв"),this,SLOT(edit()));
tbar->addSeparator();
tbar->addAction(tr("Очистить всё"),this,SLOT(erase()));
tbar->addSeparator();
tbar->addAction(tr("Очистить X"),this,SLOT(clearX()));
tbar->addSeparator();
tbar->addAction(tr("Очистить Y"),this,SLOT(clearY()));
tbar->addSeparator();
tbar->addAction(tr("О программе"),this,SLOT(help()));
this->addToolBar(tbar);


text1= new QTextEdit();
text1->setGeometry(110,30,200,420);
text1->setReadOnly(true);


text2= new QTextEdit();
text2->setGeometry(330,30,200,420);


text3= new QTextEdit();
text3->setGeometry(330,30,200,420);

lblMain = new QLabel();
setCentralWidget(lblMain);

lay = new QHBoxLayout();
lay->addWidget(text1);
lay->addStretch();
lay->addWidget(text2);
lay->addWidget(text3);
lblMain->setLayout(lay);

pxy=new parcer();

setWindowTitle(tr("Без названия"));

}



void MainWindow::open(){
    qDebug()<<"open";



    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
        tr("Text Files (*.txt)"));

   if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        else{
QString strText2;
                    while(!file.atEnd()){

                        QString str=file.readLine();


                        QStringList lst=str.split(";");

                       for(int i=0;i<lst.count();i++){
                           if (i==0){strText2.append("x="+ lst.at(i));qDebug()<<"x";}
                           qDebug()<<lst.at(i);
                           if (i==1){strText2.append("y="+ lst.at(i));qDebug()<<"y";}
                       }
                       if (lst.count()>=1){
                        qDebug()<<pxy->isDataOk(lst.at(0),lst.at(1));
                       }



                    }
text2->setText(strText2);
pxy->getAllX();
pxy->getAllY();
                }
        }




   QDir mDir;
   text1->clear();
  // QString strPath = text1->text();
   foreach (QFileInfo mIte, mDir.drives() )
// foreach (QFileInfo mIte, mDir.entryInfoList() )

   {
   text1->append(mIte.absoluteFilePath());
   }



 }
void MainWindow::save(){
    qDebug()<<"save";


    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
    tr("Text Files (*.txt)"));

    if (fileName != "") {
       QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {

       } else {
            QTextStream stream(&file);
           stream << text2->toPlainText();
           stream.flush();
           file.close();
       }
    }


}



void MainWindow::edit(){

    QtMsgType type;
char msg;

    QFile fileName("D:/log.txt");
     if(!fileName.open(QIODevice::Append | QIODevice::Text)){
     return;
     }
     QString sCurrDateTime = "[" + QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzz") + "]";
     QTextStream tsTextStream(&fileName);
     switch(type){
     case QtDebugMsg:
     tsTextStream << QString("myProjectLogDebug%1: %2\n").arg(sCurrDateTime).arg(msg);
     break;
     case QtWarningMsg:
     tsTextStream << QString("myProjectLogWarning%1: %2\n").arg(sCurrDateTime).arg(msg);
     break;
     case QtCriticalMsg:
     tsTextStream << QString("myProjectLogCritical%1: %2\n").arg(sCurrDateTime).arg(msg);
     break;
     case QtFatalMsg:
     tsTextStream << QString("myProjectLogFatal%1: %2\n").arg(sCurrDateTime).arg(msg);
     abort();
     }
     tsTextStream.flush();
     fileName.flush();
     fileName.close();



    qDebug()<<"edit";
   // qInstallMsgHandler(myMessageOutput);
     qDebug() << "Project started";
     qWarning() << "test qWarning message";

}


void MainWindow::erase(){
    qDebug()<<"delete";

text2->clear();

}

void MainWindow::clearX(){
    qDebug()<<"deleteX";


}


void MainWindow::clearY(){
    qDebug()<<"deleteY";

}



void MainWindow::help(){
    qDebug()<<"help";


formOption = new Option(this);
formOption->setAttribute(Qt::WA_ShowModal,true);
formOption->setWindowModality(Qt::ApplicationModal);
formOption->show();

}
