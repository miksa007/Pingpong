#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     image = new QImage("pallo.png");
     //lahtopaikka
     bx=50;
     by=50;
    //suunta/vauhti lahdossa
     bdx=5;
     bdy=5;

     //toinen poltsi
     b2 = new Baltsu(image, 100,100,-6,-5);
     b3 = new Baltsu(image, 100,100,-5,4);
     b4 = new Baltsu(image, 100,100,3,-5);
     b5 = new Baltsu(image, 100,0,5,7);
     //timeri event jotta pallo liikkuisi
     startTimer(50); //50millisekuntia
}

MainWindow::~MainWindow()
{
    delete ui;
}
 void MainWindow::paintEvent(QPaintEvent * /* event */)
 {
     QPainter painter(this);
     painter.setPen(Qt::blue);
    //TODO Olisko vektori mitaan??
     painter.drawImage(bx,by, (*image));
     painter.drawImage(b2->getBx(),b2->getBy(), *(b2->getImage()));
     painter.drawImage(b3->getBx(),b3->getBy(), *(b3->getImage()));
     painter.drawImage(b4->getBx(),b4->getBy(), *(b4->getImage()));
     painter.drawImage(b5->getBx(),b5->getBy(), *(b5->getImage()));

 }
void MainWindow::laskePaikka()
{
    bx+=bdx;
    if(bx>560 || bx<0)
        bdx=-bdx;

    by+=bdy;
    if (by>360 || by<0)
        bdy= -bdy;

    //Toinen pallo kanssa
    b2->laskePaikka();
    b3->laskePaikka();
    b4->laskePaikka();
    b5->laskePaikka();

    //piirretaan kuva uudelleen
    update();
}
void MainWindow::laskeTormays()
{
    ;
}
 void MainWindow::timerEvent(QTimerEvent *event)
 {
     laskePaikka();
     //qDebug() << "Timer ID:" << event->timerId();
 }
