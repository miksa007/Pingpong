#ifndef BALTSU_H
#define BALTSU_H
/**
* Pallo luokka mÃ€Ã€rittelee pallon paikan ja suunnan
*/
#include <QImage>
class Baltsu
{
public:
    Baltsu();
    Baltsu(QImage *image, int bx, int by, int bdx, int bdy);
    ~Baltsu();

    void laskePaikka();
    int getBx();
    int getBy();
    QImage* getImage();

protected:
//TODO Tahan vois maaritella timer eventin jolloin pallolla olisi yksilollinen nopeus

private:
    QImage *image;
    //paikka
    int bx;
    int by;

    //suunta
    int bdx;
    int bdy;
};

#endif // BALTSU_H
