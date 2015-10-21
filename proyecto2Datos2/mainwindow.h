#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QObject>
#include <iostream>
#include <QPixmap>
#include <Constants.h>
#include <math.h>
#include <linked_list.h>
#include <Node.h>

#include <QPointF>
#include <QPainter>
#include <QGraphicsLineItem>
#include <QLine>
#include <QPen>
#include <QBrush>
#include <QtGui>
#include <cstdlib>


using namespace std;

class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    //~MainWindow();

    QGraphicsScene* scene;
    QWidget *parent;


    QLine qLine;
    QGraphicsRectItem* qRect;
   QGraphicsRectItem* item1 ;
    QRect qRectAux;
    QBrush qBrush;
    QColor color;

    QPen qPen;
    QSize qSize;

    double sizeX;
    double sizeY;
    int random1;
    int random2;
    int random3;
    int raiz;


   lista<QColor*> *colores= new lista<QColor*>;

    int  cuadros;




    int splitImage(int x1, int y1,int x2, int y2, int profundidad);
    void PaintImage();


};

#endif // MAINWINDOW_H



