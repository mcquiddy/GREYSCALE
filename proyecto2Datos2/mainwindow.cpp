#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) {

    cout << ""<< endl;
    setFixedSize(WINDOWS_WIDTH,WINDOWS_HEIGHT);



    scene = new QGraphicsScene();
    setFixedSize(WINDOWS_WIDTH,WINDOWS_HEIGHT);
    scene->setSceneRect(0,0,WINDOWS_WIDTH,WINDOWS_HEIGHT);
    QPixmap pix(BACKGROUND_IMAGE);
  // scene->addPixmap(pix);
    setScene(scene);

    qPen.setColor(Qt::blue);//color de las lineas que dividen la imagen

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    while(datoValido){
        getProfundidad();
        if(profundidad>=1 & profundidad<=5){
            break;
        }
    }


    cuadros=pow(2,(profundidad));
    raiz=cuadros;
    cuadros=pow(cuadros,2);

    sizeX=WINDOWS_WIDTH/ raiz;
    sizeY=WINDOWS_HEIGHT/raiz;


    qSize.setWidth(sizeX);
    qSize.setHeight(sizeY);
    qRectAux.setSize(qSize);

    listaImagen =  matriz->cutImage(qSize,raiz);

/*
   for(int i=1; i<=raiz;i++){//fila
        for(int j=1;j<=raiz;j++){//columna

       pm=scene->addPixmap(listaImagen->rove(i)->get_data()->rove(j)->get_data().getImagen());
       pm->setPos( (i-1)*sizeX,(j-1)*sizeY);

        }
   }*/

    PaintImage(matriz->imagepix);

  //  qRect = new QGraphicsRectItem(qRectAux);
     //setScene(scene);


    if(profundidad>=1){

        if(profundidad==1){
            qLine.setLine(WINDOWS_WIDTH/2,0,WINDOWS_WIDTH/2,WINDOWS_HEIGHT);//
            scene->addLine(qLine);
            qLine.setLine(0,WINDOWS_HEIGHT/2,WINDOWS_WIDTH,WINDOWS_HEIGHT/2);//
            scene->addLine(qLine);
            cout<<"cantidad de cuadros: "<<cuadros<<endl;

        }
        else if(profundidad>1){
            qLine.setLine(WINDOWS_WIDTH/2,0,WINDOWS_WIDTH/2,WINDOWS_HEIGHT);//
            scene->addLine(qLine);
            qLine.setLine(0,WINDOWS_HEIGHT/2,WINDOWS_WIDTH,WINDOWS_HEIGHT/2);//
            scene->addLine(qLine);
            splitImage(0,0,WINDOWS_WIDTH,WINDOWS_HEIGHT,profundidad-1);
            cout<<"cantidad de cuadros: "<<cuadros<<endl;

        }
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

int MainWindow::getProfundidad(){
    bool value;

      profundidad = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),  tr("Profundidad(1-5):"), 1, 0, 100, 1, &value);
      cout<<"prueba"<<endl;
           return profundidad;
}
int MainWindow::changePos(){
     bool value;
    while(datoValido){
        id1= QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),  tr("ingrese primer identificador(1-"+(cuadros)), 1, 0, 100, 1, &value);
        if(id1>=(1) & id1<=cuadros){
            break;
        }

    }
    while(datoValido){
        id2= QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),  tr("ingrese primer identificador(1-"+(cuadros)), 1, 0, 100, 1, &value);
        if(id2>=(1) & id2<=cuadros){
            break;
        }

    }

    cout<<"id1: "<<id1<<", "<<"id2: "<<id2<<endl;





}
void MainWindow::PaintImage(lista<pixel>* topaint){

    int lenght =0;
   for(int i=0; i<raiz;i++){//fila
       for(int j=0;j<raiz;j++){//columna
        pixel tmp = topaint->rove(lenght)->get_data();
           //cout << tmp.R<<endl;
           QGraphicsRectItem* qRect1 = new QGraphicsRectItem(qRectAux);
           qRect1->setBrush(QColor(tmp.R ,tmp.G,tmp.B));
           qRect1->setPos(j*sizeX,i*sizeY);
           //int gris=random1*0.299+random2*0.587+random3*0.114;
           //qRect1->setBrush(QColor(gris,gris,gris));
           scene->addItem(qRect1);
           lenght +=1;

       }


   }}
