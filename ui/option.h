#ifndef OPTION_H
#define OPTION_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "ui/option.h"

class Option : public QMainWindow
{
    Q_OBJECT
public:
    QPushButton * pbtn;
    QLabel * lbl;




    explicit Option(QWidget *parent = 0);


signals:

public slots:
    void quit();

private:

private slots:
};

#endif // OPTION_H
