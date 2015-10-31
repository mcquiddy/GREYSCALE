#ifndef IMAGECLASS_H
#define IMAGECLASS_H
#include <stdio.h>
#include "QPixmap"
#include <iostream>
#include <array>
#include "Constants.h"
#include "linked_list.h"
using namespace std;
struct pixel{
        int R=0,G=0,B=0;
};


class ImageClass
{
public:
    lista<pixel> imagepixels;
    lista<lista<pixel>*> prom;
    ImageClass();
    void getPixel(char* filename);
    void Gethighcolor(lista<pixel>pixels);
    void saveImage(QPixmap imagen);

};

#endif // IMAGECLASS_H
