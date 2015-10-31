#ifndef IMAGE_H
#define IMAGE_H
#include <linked_list.h>
#include <QPixmap>
#include <QImage>
#include <Constants.h>
#include <QSize>
#include <qlabel.h>
#include <iostream>
#include <stdio.h>

#include <stdlib.h>

using namespace std;
struct pixel{
    int R=0,G=0,B=0;
};
class Image
{
public:
    Image();
    int posX;
    int posY;
    int id;

    QPixmap imagen;
    lista<QPixmap> *listaimagenes = new lista<QPixmap>();
    lista<Image> *listaTotal = new lista<Image> ();
    lista<pixel> *imagepixels = new lista<pixel>();

    lista<lista<pixel>*> *prom=new lista<lista<pixel>*>();
    lista<pixel> *imagepix = new lista<pixel>();

   // QLabel label;



  lista<lista<Image> *> *cutImage(QSize size, int cuadros);
    int getPosX() const;
    void setPosX(int value);
    int getPosY() const;
    void setPosY(int value);
    int getId() const;
    void setId(int value);
    int random1,random2,random3;
    lista<lista<Image>*> *matriz = new lista<lista<Image>*> ();
    QPixmap getImagen() const;
    void setImagen(const QPixmap &value);
    void getPixel(char* filename);
    void Gethighcolor(lista<pixel> *pixels);

    int rndm;
    int len=1;
};

#endif // IMAGE_H
