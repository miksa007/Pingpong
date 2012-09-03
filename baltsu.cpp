
#include "baltsu.h"

Baltsu::Baltsu()
{
    ;
}
Baltsu::~Baltsu()
{
    ;
}
Baltsu::Baltsu(QImage *image, int bx, int by, int bdx, int bdy)
    : image(image), bx(bx),by(by),bdx(bdx),bdy(bdy)
{
    ;
}
int Baltsu::getBx()
{
    return bx;
}

int Baltsu::getBy()
{
    return by;
}
QImage * Baltsu::getImage()
{
    return image;
}
void Baltsu::laskePaikka()
{
    bx+=bdx;
    if(bx>560 || bx<0)
        bdx=-bdx;

    by+=bdy;
    if (by>360 || by<0)
        bdy= -bdy;
}
