#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QToolBar>
#include "ui/option.h"
#include "leu/parcer.h"
class MainWindow : public QMainWindow
{
Q_OBJECT
public:
        QLabel * lblMain;
        QTextEdit * text1;
        QTextEdit * text2;
        QTextEdit * text3;
        QHBoxLayout * lay;
        QToolBar * tbar;
        parcer * pxy;

explicit MainWindow(QWidget *parent = 0);
signals:
public slots:
    void open();
    void save();
    void edit();
    void erase();
    void clearX();
    void clearY();
    void help();

private:

    Option *formOption;

};
#endif // MAINWINDOW_H
