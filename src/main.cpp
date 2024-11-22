#include <sil/sil.hpp>
#include "random.hpp"
#include <sstream>
#include <complex>
#include <iostream>
#include <cmath>

void green_effect(sil::Image& img)
{
    for (glm::vec3& color : img.pixels())
    {
        color.r=0.f;
        color.b=0.f;
    }
}

void exchange_color(sil::Image& img)
{
    for(glm::vec3& color : img.pixels())
    {
        std::swap(color.r,color.b);
        // EST CE QU'IL Y A UNE AUTRE FACON DE FAIRE QUE SWAP???
        // if (color.r &&!color.b && !color.g)
        // {
        //     color.b=color.r;
        //     color.r=0;
        // }
        // if (color.b && !color.r && !color.g)
        // {
        //     color.r=color.b;
        //     color.b=0;
        // }
        
    }
}

void NdW (sil::Image& img)
{
    for (glm::vec3& color : img.pixels())
    {
        float luminance = 0.3f * color.r + 0.59f * color.g + 0.11f * color.b;
        color= glm::vec3 {luminance};
    }
}

void negative(sil::Image& img)
{
    for(glm::vec3& color : img.pixels())
    {
        color.r=1-color.r;
        color.b=1-color.b;
        color.g=1-color.g;
        // color = glm::vec3(1.0f) - color;
    }
}

void gradient(sil::Image& img)
{
    for(int x=0;x<img.width();++x)
    {   
        for (int y=0;y<img.height();++y)
        {
            img.pixel(x,y) =glm::vec3(static_cast<float>(x) / (img.width() - 1)) ;
        }
    }
}

void miror(sil::Image& img, int a, int b)//a=1 et b=0 sym par rapport a x; ou l'inverse
{
    int w =img.width();
    int h =img.height();
    sil::Image copy {img};
    for(int x=0;x<w;x++)
    {
        for(int y=0;y<h;y++)

        {
            img.pixel(x,y)=copy.pixel(a*(w-1-2*x)+x,b*(h-1-2*y)+y);
        }
    }
}

void noise_filter(sil::Image& img)//pas vraiment ce que ca demande
{
    for (glm::vec3& color : img.pixels())
    {
        float a=random_float(0, 0.75);
        float b=random_float(0, 0.75);
        float c=random_float(0, 0.75);
        if (color==glm::vec3{1,1,1})
        {
            color=glm::vec3 {color.r-a,color.g-b,color.b-c};
        }
        color=glm::vec3 {color.r+a,color.g+b,color.b+c};
    }
}

//void noise(sil::Image& img)....

void rotation(sil::Image& img)
{
    int height {img.height()};
    int width {img.width()};
    sil::Image copy=img;
    img=sil::Image {height/*width*/, width/*height*/};
    for (int x=0;x<width;x++)
    {
        for(int y=0;y<height;y++)
        {
            img.pixel(y,x)=copy.pixel(x,y);
            
        }
    }
    miror (img,1,0);
}

void RGB_split(sil::Image& img)
{
    sil::Image copy {img};
    for(int x=0;x<img.width();x++)
    {
        for(int y=0;y<img.height();y++)
        {
            //img.pixel(x,y).g = copy.pixel(x,y);
            img.pixel(x,y)=glm::vec3{0,copy.pixel(x,y).g,0};
            if (x>25)
            {img.pixel(x,y).r= copy.pixel(x-25,y).r;
            }
            if(x<img.width()-26)
            {img.pixel(x,y).b= copy.pixel(x+25,y).b;}
        }   
    }
}

void clear_down (sil::Image& img)
{
    for (glm::vec3& color:img.pixels())
    {
        //color*=color; //c'est un peu trop fort
        color.r=std::pow(color.r,1.5);
        color.b=std::pow(color.b,1.5);
        color.g=std::pow(color.g,1.5);
    }
}

void clear_up (sil::Image& img)
{
    for (glm::vec3& color:img.pixels())
    {
        if (color!=glm::vec3{0,0,0})
        {
            color.r=std::pow(color.r,0.5);
            color.b=std::pow(color.b,0.5);
            color.g=std::pow(color.g,0.5);
        }
        
    }
}

void disk(sil::Image& img,int r) //(image, rayon)
{
    int x_center{img.width()/2};
    int y_center{img.width()/2};
    for(int x=0;x<img.width();x++)
    {
        for (int y=0; y<img.height();y++)
        {
            int X = static_cast<int>(std::pow((x - x_center), 2));
        int Y = static_cast<int>(std::pow((y - y_center), 2));
        int dist2 = X + Y;
        int dist = static_cast<int>(std::pow(dist2, 0.5));
            if (dist<r)
            {
                img.pixel(x,y)=glm::vec3 {1,1,1};
            }
        }
    }
}

void circle (sil::Image& img,int r,int t,float x_center,float y_center) //(image, rayon, epaisseur)
{
    // int x_center{img.width()/2};
    // int y_center{img.width()/2};
    for(int x=0;x<img.width();x++)
    {
        for (int y=0; y<img.height();y++)
        {
            float X = static_cast<float>(std::pow((x - x_center), 2));
            float Y = static_cast<float>(std::pow((y - y_center), 2));
            float dist2 = X + Y;
            float dist = static_cast<int>(std::pow(dist2, 0.5));
            if (dist<r && r-dist<t)
            {
                img.pixel(x,y)=glm::vec3 {1,1,1};//or:{1,0.84,0}
            }
        }
    }
}

void animation_disk(sil::Image& img, int r, int n)
//AVEC LA COLLABORATION DE GUILLAUM
{   
    disk(img,r);
    sil::Image copy =img;
    for (int i=0;i<=n;i++)
    {
        sil::Image img (copy.width(),copy.height());
        for (int x=0;x<img.width();x++)
        {
            for (int y=0;y<img.height();y++)
            {
                //img.pixel(x,y)=copy.pixel(x+img.width()/(i+1),y);
                int source_x = x + i*(((img.width() - r/2) * 2) / n)-img.width()/2-r;

                // Vérifier si la position source est valide
                if (source_x < copy.width() && source_x >=0)
                {
                    img.pixel(x, y) = copy.pixel(source_x, y);
                }
            }
        }

        // img.save("output/anim\i.png");
        std::ostringstream filename;
        filename << "output/anim/animation" << i << ".png";

        img.save(filename.str());
    }
}

void fractale(sil::Image& img,int n)
{
    for (int x=0;x<img.width();x++)
    {
        for (int y=0;y<img.height();y++)
        {
            float xnv =static_cast <float> (x*2/250.f-2) ;
            float ynv =static_cast <float> (y*2/250.f-2) ;
            std::complex<float> z{0.f, 0.f};
            std::complex<float> c{xnv, ynv};
            float i=0;

            while (i<=n && std::abs(z)<2)
            {
                z=z*z+c;
                
                i++;
            }
            // if(std::abs(z)<2)
            //     {
            //         img.pixel(x,y)=glm::vec3{1,1,1};
            //     }
            
                std::cout << i << std::endl;
                img.pixel(x,y)=glm::vec3{i/n,i/n,i/n};
        }
    }
}

void rosace(sil::Image& img, int r,int t)
{
    
    int xc {img.width()/2};
    int yc {img.height()/2};
    circle(img,r,t,xc,yc);
    for (int i=0;i<6;i++)
    {
        circle(img,r,t,xc+r*cos(i*M_PI/3),yc+r*sin(i*M_PI/3));
    }
}

void carreau(sil::Image& img, int a,int t, int x_c, int y_c)
{
    int x_start = x_c - a / 2;
    int x_end = x_c + a / 2;
    int y_start = y_c - a / 2;
    int y_end = y_c + a / 2;
    t*=1.5;
    for(int x=0;x<img.width();x++)
    {
        for (int y=0;y<img.height();y++)
        {
            if ((x >= x_start && x <= x_end && (y >= y_start && y <= y_start+t)) ||  
                (y >= y_start && y <= y_end && (x >= x_start && x <= x_start+t)) || 
                (x >= x_start && x <= x_end && (y >= y_end-t && y <= y_end)) ||  
                (y >= y_start && y <= y_end && (x >= x_end-t && x <= x_end))) 
            { 
                img.pixel(x, y) = glm::vec3{1, 1, 1}; // Remplir avec du blanc
            }
        }
    }
}

void rotation_deg(sil::Image& img, float teta) //teta en rad
{
    sil::Image temp(img.width(), img.height());
    int x_c=img.width()/2; //mileu en x
    int y_c=img.height()/2; //milieu en y
    for(int x=0;x<img.width();x++)
    {
        for (int y=0;y<img.height();y++)
        {// Calculer les coordonnées relatives au centre
            int x_rel = x - x_c;
            int y_rel = y - y_c;

            // Calculer les nouvelles coordonnées après rotation
            int new_x = static_cast<int>(x_rel * cos(teta) - y_rel * sin(teta)) + x_c;
            int new_y = static_cast<int>(x_rel * sin(teta) + y_rel * cos(teta)) + y_c;

            // Vérifier que les nouvelles coordonnées sont dans les limites de l'image
            if (new_x >= 0 && new_x < img.width() && new_y >= 0 && new_y < img.height()) {
                // Copier le pixel dans l'image temporaire
                temp.pixel(new_x, new_y) = img.pixel(x, y);
            }
        }
    }
    // Copier l'image temporaire dans l'image originale
    for (int x = 0; x < img.width(); x++)
    {
        for (int y = 0; y < img.height(); y++) {
            img.pixel(x, y) = temp.pixel(x, y);
        }
    }
}

void andal(sil::Image& img,int r, int t)
{
    circle(img,img.width()/2,t,img.width()/2,img.height()/2);
    carreau(img,std::sqrt(2)*r,t,img.width()/2,img.height()/2);
    rotation_deg(img,M_PI/4);
    carreau(img,std::sqrt(2)*r,t,img.width()/2,img.height()/2);
    //rotation_deg(img,M_PI/4);//solution ponctuel
}

void remplissage(sil::Image img)//permet de remplir les px qui sont entouré de 4 px du meme type
{

}

void mosaique(sil::Image& img, int n, int f) {
    sil::Image copy = img; // Créer une copie de l'image originale

    // Redimensionner l'image pour la mosaïque
    img = sil::Image(copy.width() * n, copy.height() * n* f);

    // Remplir la mosaïque
    for (int i = 0; i < n; i++) {         // Parcourir les blocs horizontaux
        for (int j = 0; j < n*f; j++) {     // Parcourir les blocs verticaux
            // Calculer la position du coin supérieur gauche du bloc
            int x_offset = i * copy.width();
            int y_offset = j * copy.height();

            // Copier les pixels de l'image originale dans le bloc
            for (int x = 0; x < copy.width(); x++) {
                for (int y = 0; y < copy.height(); y++) {
                    img.pixel(x + x_offset, y + y_offset) = copy.pixel(x, y);
                }
            }
        }
    }
}

void mosaique_miror(sil::Image& img, int n)
{
    sil::Image copy = img; // Créer une copie de l'image originale

    // Redimensionner l'image pour la mosaïque
    img = sil::Image(copy.width() * n, copy.height() * n);

    // Remplir la mosaïque
    for (int i = 0; i < n; i++) {         // Parcourir les blocs horizontaux
        for (int j = 0; j < n; j++) {     // Parcourir les blocs verticaux
            // Calculer la position du coin supérieur gauche du bloc
            
            int x_offset = i * copy.width();
            int y_offset = j * copy.height();
            sil::Image block = copy;
            miror(block, i % 2, j % 2);

            // Copier les pixels de l'image originale dans le bloc
            for (int x = 0; x < copy.width(); x++) {
                for (int y = 0; y < copy.height(); y++) {
                    img.pixel(x + x_offset, y + y_offset) = block.pixel(x, y);
                }
            }
        }
    }
}

// void glitch(sil::Image& img, int n)
// {
//     sil::Image copy=img;
//     int w=img.width();
//     int h=img.height();
//     for (int i;i<n;i++)
//     {       
//         // int a=random_int(0, 10);
//         // int b=random_int(0, 20);
//         // int x_nv=random_int(0, w);
//         // int y_nv=random_int(0, h);
//         int x_nv = random_int(-w / 4, w / 4); // Décalage horizontal
//         int y_nv = random_int(-h / 4, h / 4); // Décalage vertical

//         for (int x=0;x<w;x++)
//         {
//             for (int y=0;y<h;y++)
//             {
//                 int X = std::clamp(x + x_nv, 0, w - 1);
//                 int Y = std::clamp(y + y_nv, 0, h - 1);
//                 if ()
//                 img.pixel(x,y)=copy.pixel(X,Y);
//             }
//         }
//     }  
// }
void glitch(sil::Image& img, int n) {
    sil::Image copy = img; // Faire une copie initiale de l'image
    int w = img.width();
    int h = img.height();

    for (int i = 0; i < n; i++) {
        // Dimensions aléatoires du rectangle
        int a = random_int(0, 10); // Largeur du rectangle aléatoire
        int b = random_int(0, 20); // Hauteur du rectangle aléatoire

        // Position aléatoire pour le rectangle
        int x_nv = random_int(0, w - a);
        int y_nv = random_int(0, h - b);

        // Décalage aléatoire pour le glitch
        int dx = random_int(-a / 2, a / 2);
        int dy = random_int(-b / 2, b / 2);

        for (int x = 0; x < a; x++) {
            for (int y = 0; y < b; y++) {
                // Calculer les nouvelles coordonnées avec décalage
                int src_x = std::clamp(x_nv + x + dx, 0, w - 1);
                int src_y = std::clamp(y_nv + y + dy, 0, h - 1);

                int dest_x = x_nv + x;
                int dest_y = y_nv + y;

                // Copier le pixel avec l'effet glitch
                img.pixel(dest_x, dest_y) = copy.pixel(src_x, src_y);
            }
        }
    }
}
    
    



int main()
{
    // {
    // sil::Image image{"images/logo.png"};
    // green_effect(image);
    // image.save("output/green_effect.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     exchange_color(image);
    //     image.save("output/exchange_color.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     NdW(image);
    //     image.save("output/NdW.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     negative(image);
    //     image.save("output/negative.png");
    // }
//     {
//         sil::Image image{300/*width*/, 200/*height*/};
//         gradient(image);
//         image.save("output/gradient.png");
//     }
    // {
    //     sil::Image image{"images/logo.png"};
    //     miror(image,0,1);
    //     image.save("output/miror.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     noise_filter(image);
    //     image.save("output/noise.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     rotation(image);
    //     image.save("output/rotation.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     RGB_split(image);
    //     image.save("output/split.png");
    // }
    // {
    //     sil::Image image{"images/photo.jpg"};
    //     clear_down(image);
    //     image.save("output/clear_down.png");
    // }
    // {
    //     sil::Image image{"images/photo.jpg"};
    //     clear_up(image);
    //     image.save("output/clear_up.png");
    // }
    // {
    //     sil::Image image{500/*width*/, 500/*height*/};
    //     disk(image,100);
    //     image.save("output/disk.png");
    // }
    // {
    //     sil::Image image{500/*width*/, 500/*height*/};
    //     circle(image,150,15,image.width()/2,image.height()/2);
    //     image.save("output/cercle.png");
    // }
    // {
    //     sil::Image image{500/*width*/, 500/*height*/};
    //     animation_disk(image,150,20);
    // }


    // {
    //     sil::Image image{500/*width*/, 500/*height*/};
    //     fractale(image,20);
    //     image.save("output/fractale.png");
    // }

    // {
    //     sil::Image image{500/*width*/, 500/*height*/};
    //     rosace(image,100,5);
    //     image.save("output/rosace.png");
    // }

    // {
    //     sil::Image image{500/*width*/, 500/*height*/};
    //     andal(image,250,10);
    //     //mosaique(image,6,1.5);
    //     image.save("output/andal.png");
    // }
    // {
    //     sil::Image image{"output/andal.png"};
    //     mosaique(image,6,2);
    //     image.save("output/mosaique_andal.png");
    // }

    // {
    //     sil::Image image{"images/logo.png"};
    //     mosaique(image,6,1);
    //     image.save("output/mosaique.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     mosaique_miror(image,6);
    //     image.save("output/mosaique_miror.png");
    // }
    {
        sil::Image image{"images/logo.png"};
        glitch(image,500);
        image.save("output/glitch.png");
    }

    
}