#include "imageclass.h"

ImageClass::ImageClass()
{
}
void ImageClass::getPixel(char* filename){
        FILE* f = fopen(filename, "rb");
        if(f == NULL)
            throw "Argumento invalido";
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
            {
                // pasa (B, G, R) a (R, G, B)
                tmp = data[j];
                data[j] = data[j+2];
                data[j+2] = tmp;
                pixel tmp;
                tmp.B = (int)data[j];
                tmp.R =  (int)data[j+1];

                tmp.G = (int)data[j+2];
                this->imagepixels.insert_head(tmp);

            }
        }


        fclose(f);
        Gethighcolor(this->imagepixels);
}

void ImageClass::Gethighcolor(lista<pixel> pixels){
    lista<pixel>* win;

    for(int z=0; z<= pixels.length();z++){
        pixel tmp;
        tmp = pixels.rove(z)->get_data();
        cout << "length de pixels inicial" << pixels.length() << endl;
        lista<pixel> *tmp1=new lista<pixel>();
        for(int m =1; m<= pixels.length();m++){
            int total=0;
            pixel tmpm;
            tmpm = pixels.rove(m)->get_data();
            total += std::abs(tmp.R - tmpm.R);
            total += std::abs(tmp.G - tmpm.G);
            total += std::abs(tmp.B - tmpm.B);


                if(total <= 10){
                    tmp1->insert_head(tmpm);
                    pixels.delete_Pos(m);
                    //cout << tmpm.G<<endl;

                }


        }
        cout << z << endl;
        cout << tmp1->length() << "length del color inicial"<<endl;
        cout << "lenght de pixels despues del for principal: "<<pixels.length() << endl;

        pixels.delete_Pos(z);
        this->prom.insert_head(tmp1);
        cout << "length matriz de colores: "<< prom.length() <<endl;

    }

   // cout << "comienza a sacar el color dominante"<< endl;
    win = this->prom.get_head()->get_data();
    //cout << "lengt del win inicial: " << win->length() << endl;

    for(int i=0; i!=this->prom.length();i++){
        if(this->prom.rove(i)->get_data()->length() > win->length()){
            win = this->prom.rove(i)->get_data();
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

    cout << "longitud de win al terminar de sacar el promedio: " << win->length() << endl;
    winner.R = R/win->length();
    winner.G = G/win->length();
    winner.B = B/win->length();
    cout << "valor R ganador: " << winner.R << " valor G ganador: " << winner.G << " valor B ganador: " << winner.B << endl;


}

/*void ImageClass::saveImage(QPixmap imagen){
        string name = "test.bmp";
        QString name1 = "test.bmp";

        string ruta = "/home/bryan/Escritorio/PUZZLE/build-3ProyectoCorto-Desktop_Qt_5_3_0_GCC_32bit-Release/";
        string result = ruta.append(name);
        //imagen.save(name1, "BMP");
        cout <<imagen.width() << endl;
        cout << "por hacer el const"<<endl;
        char* coso1= (const_cast<char*>(result.c_str()));
        cout << coso1 << endl;
        cout << "hizo el const"<<endl;
        getPixel(coso1);


}
*/

