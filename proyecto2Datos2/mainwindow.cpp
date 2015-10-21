#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) {


    setFixedSize(WINDOWS_WIDTH,WINDOWS_HEIGHT);

     cout<<"random: "<<random;



    //setTitle(QString("Proyecto 2"));

    scene = new QGraphicsScene();
    setFixedSize(WINDOWS_WIDTH,WINDOWS_HEIGHT);
    scene->setSceneRect(0,0,WINDOWS_WIDTH,WINDOWS_HEIGHT);
    QPixmap pix(BACKGROUND_IMAGE);
    scene->addPixmap(pix);

    qPen.setColor(Qt::blue);//color de las lineas que dividen la imagen

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

     cuadros=pow(2,(profundidad+1));
     raiz=cuadros;
     cuadros=pow(cuadros,2);



    sizeX=WINDOWS_WIDTH/ raiz;
    sizeY=WINDOWS_HEIGHT/raiz;

    qSize.setWidth(sizeX);
    qSize.setHeight(sizeY);;
    qRectAux.setSize(qSize);//se define tama;o
    qRect = new QGraphicsRectItem(qRectAux);
    cout<<"yama;o: "<<sizeX;
     setScene(scene);


   PaintImage();

     //this->show();



    if(profundidad>=0){
        if(profundidad==0){
            qLine.setLine(WINDOWS_WIDTH/2,0,WINDOWS_WIDTH/2,WINDOWS_HEIGHT);//
            scene->addLine(qLine);
            qLine.setLine(0,WINDOWS_HEIGHT/2,WINDOWS_WIDTH,WINDOWS_HEIGHT/2);//
            scene->addLine(qLine);
            cout<<"cantidad de cuadros: "<<cuadros<<endl;
        }
        else if(profundidad>=1){
            qLine.setLine(WINDOWS_WIDTH/2,0,WINDOWS_WIDTH/2,WINDOWS_HEIGHT);//
            scene->addLine(qLine);
            qLine.setLine(0,WINDOWS_HEIGHT/2,WINDOWS_WIDTH,WINDOWS_HEIGHT/2);//
            scene->addLine(qLine);
            splitImage(0,0,WINDOWS_WIDTH,WINDOWS_HEIGHT,profundidad);

           cout<<"cantidad de cuadros: "<<cuadros<<endl;
            }
        else{

            cout<<"profundidad no valida"<<endl;
        }

    }
    else{
         cout<<"profundidad no valida, debe ser mayor a 1"<<endl;
    }





}

int MainWindow::splitImage(int x1, int y1,int x2, int y2, int profundidad){

      if (profundidad<=0){

          return 0;
      }



      if(profundidad>0){
        splitImage(x1,y1,x1+(x2-x1)/2,y1+(y2-y1)/2,profundidad-1);
        qLine.setLine(x1 +((x2-x1)/4),y1,x1+((x2-x1)/4),y1+(y2-y1)/2);//agrega linea primer cuadrante vertical
         scene->addLine(qLine);
         qLine.setLine(x1,y1 +((y2-y1)/4),x1+((x2-x1)/2),y1+(y2-y1)/4);//agrega linea primer cuadrante horizontal
        scene->addLine(qLine);

        splitImage(x1+(x2-x1)/2,y1,x2,y1+(y2-y1)/2,profundidad-1);
        qLine.setLine(((x2-x1)/2)+((x2-x1)/4)+x1,y1,((x2-x1)/2)+((x2-x1)/4)+x1,((y2-y1)/2)+y1);//agrega linea segundo cuadrante vertical
        scene->addLine(qLine);
        qLine.setLine(x1,((y2-y1)/2)+((y2-y1)/4)+y1,((x2-x1)/2)+x1,((y2-y1)/2)+((y2-y1)/4)+y1);//agrega linea segundo cuadrante horizontal
       scene->addLine(qLine);

        splitImage(x1,y1+(y2-y1)/2,x1+(x2-x1)/2,y2,profundidad-1);
        qLine.setLine(x1+((x2-x1)/4),y1,x1+((x2-x1)/4),y2);//agrega linea tercer cuadrante vertical
        scene->addLine(qLine);
         qLine.setLine(x1,y1+((y2-y1)/4),x2,y1+((y2-y1)/4));//agrega linea tercer cuadrante horizontal
        scene->addLine(qLine);

        splitImage(x1+(x2-x1)/2,y1+(y2-y1)/2,x2,y2,profundidad-1);
        qLine.setLine(x1+((x2-x1)/2)+((x2-x1)/4),y1,x1+((x2-x1)/2)+((x2-x1)/4),y2);//agrega linea cuarto cuadrante vertical
        scene->addLine(qLine);//agrega linea cuarto cuadrante horizontal
        qLine.setLine(x1,y1+((y2-y1)/2)+((y2-y1)/4),x2,y1+((y2-y1)/2)+((y2-y1)/4));
       scene->addLine(qLine);
    }





}

void MainWindow::PaintImage(){


   for(int i=0; i<raiz;i++){//fila
       for(int j=0;j<raiz;j++){//columna
           random1= rand() % 254;
           random2= rand() % 254;
           random3= rand() % 254;
           QGraphicsRectItem* qRect1 = new QGraphicsRectItem(qRectAux);
           qRect1->setBrush(QColor(random1,random2,random3));
           qRect1->setPos(j*sizeX,i*sizeY);
           int gris=random1*0.299+random2*0.587+random3*0.114;
           qRect1->setBrush(QColor(gris,gris,gris));
           scene->addItem(qRect1);

       }


   }











}

