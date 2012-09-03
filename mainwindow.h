
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QPainter>
#include <QTimerEvent>

#include "baltsu.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent * /* event */);
    void laskePaikka();
    void laskeTormays();
protected:
    void timerEvent(QTimerEvent *event);
private:
    Ui::MainWindow *ui;

     QImage *image;
     int bx;
     int by;
     //suunta
     int bdx;
     int bdy;

     //palloluokan pointteri
     Baltsu *b2;
     Baltsu *b3;
     Baltsu *b4;
     Baltsu *b5;

};

#endif // MAINWINDOW_H
