#include "image.h"

Image::Image()
{


}
QPixmap Image::getImagen() const
{
    return this->imagen;
}

void Image::setImagen(const QPixmap &value)
{
    imagen = value;
}

int Image::getId() const
{
    return this->id;
}

void Image::setId(int value)
{
    id = value;
}

int Image::getPosY() const
{
    return this->posY;
}

void Image::setPosY(int value)
{
    posY = value;
}

int Image::getPosX() const
{
    return this->posX;
}

void Image::setPosX(int value)
{
    posX = value;
}

/**
  * @brief Image::cutImage
  * @param size
  * @param cuadros
  * @return
  */
 lista<lista<Image>*>*  Image::cutImage(QSize size, int cuadros){
    QString name = "test.bmp";
    char* coso1= (const_cast<char*>(ROUTE.c_str()));
    len=cuadros*cuadros;
    //Corta una sección de una imagen más grande
    for(int i=0; i<cuadros;i++){//fila

        for(int j=0;j<cuadros;j++){//columna
            Image info;
            info.setPosX(i*size.width());
            info.setPosY(j*size.height());
            QPixmap test = QPixmap((BACKGROUND_IMAGE));
            QPixmap chunk = test.copy(info.getPosX(),info.getPosY(),size.width(),size.height());

            //listaimagenes->insert_head(chunk);
            chunk.save(name, "BMP");
            info.setImagen(chunk);
            getPixel(coso1);
            cout <<"pixel de cuadro: "<< imagepix->length()<<endl;
            info.setId(len);
            len+=1;

            listaTotal->insert_tail(info);//imagen cortada y agregada en orden a la lista
        }
    }
        int lenght=1;
        for(int i=1; i<=cuadros;i++){//fila
            lista<Image> *fila = new lista<Image> ();

            for(int j=1;j<=cuadros;j++){//columna
                //cout<<"len>: "<<listaTotal->length()<<", "<<"rndm: "<<rndm << endl;
                fila->insert_tail(listaTotal->rove(lenght)->get_data());
                lenght+=1;
            }

             matriz->insert_tail(fila);
        }




    return matriz;

}
 /**
  * @brief Image::getPixel
  * @param filename
  */
 void Image::getPixel(char* filename){
         FILE* f = fopen(filename, "rb");
         if(f == NULL)
             throw "Argumento invalido";
         //se hace un arreglo de 54 posiciones para almacenar el header del bmp
         unsigned char info[54];
         fread(info, sizeof(unsigned char), 54, f);
         int width = *(int*)&info[18];
         int height = *(int*)&info[22];
         int row_padded = (width*3 + 3) & (~3);
         unsigned char* data = new unsigned char[row_padded];
         unsigned char tmp;
         for(int i = 0; i < height; i++)
         {
             fread(data, sizeof(unsigned char), row_padded, f);
             for(int j = 0; j < width*3; j += 3)
             { // pasa (B, G, R) a (R, G, B)
                 tmp = data[j];
                 data[j] = data[j+2];
                 data[j+2] = tmp;
                 pixel tmp;
                 tmp.R = (int)data[j];
                 tmp.G =  (int)data[j+1];

                 tmp.B = (int)data[j+2];
                 this->imagepixels->insert_head(tmp);

             }
         }


         fclose(f);
         Gethighcolor(this->imagepixels);
 }
 /**
  * @brief Image::Gethighcolor
  * @param pixels
  * @return
  */
void Image::Gethighcolor(lista<pixel> *pixels){
     lista<pixel>* win;
     prom = new lista<lista<pixel>*>();

     for(int z=0; z<= pixels->length();z++){
         pixel tmp;
         tmp = pixels->rove(z)->get_data();
         //cout << "length de pixels inicial" << pixels->length() << endl;
         lista<pixel> *tmp1=new lista<pixel>();
         for(int m =1; m<= pixels->length();m++){
             int total=0;
             pixel tmpm;
             tmpm = pixels->rove(m)->get_data();
             total += std::abs(tmp.R - tmpm.R);
             total += std::abs(tmp.G - tmpm.G);
             total += std::abs(tmp.B - tmpm.B);


                 if(total <= 70){
                     tmp1->insert_head(tmpm);
                     pixels->delete_Pos(m);
                     //cout << tmpm.G<<endl;

                 }
         }
         //cout << z << endl;
         //cout << tmp1->length() << "length del color inicial"<<endl;
         //cout << "lenght de pixels despues del for principal: "<<pixels->length() << endl;

         pixels->delete_Pos(z);
         this->prom->insert_head(tmp1);
         //cout << "length matriz de colores: "<< prom->length() <<endl;

     }

    // cout << "comienza a sacar el color dominante"<< endl;
     win = this->prom->get_head()->get_data();
     //cout << "lengt del win inicial: " << win->length() << endl;

     for(int i=0; i!=this->prom->length();i++){
         if(this->prom->rove(i)->get_data()->length() > win->length()){
             win = this->prom->rove(i)->get_data();
       //      cout << "win cambió " << endl;
         }
     }
     //cout << "valor de la longitud de win al terminar de buscar el dominante: " << win->length() << endl;
   pixel winner= win->get_head()->get_data();
   int R=0,G=0,B=0;
     for(int x=0; x!= win->length();x++){
         pixel tmp = win->rove(x)->get_data();
         R+= tmp.R;
         G+= tmp.G;
         B+= tmp.B;
     }
     winner.R = R/win->length();
     winner.G = G/win->length();
     winner.B = B/win->length();
     cout << "valor R ganador: " << winner.R << " valor G ganador: " << winner.G << " valor B ganador: " << winner.B << endl;
    this->imagepix->insert_head(winner);

 }





















