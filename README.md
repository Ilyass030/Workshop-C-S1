# 🐣 S1 | Prog: Workshop

## Le préprocesseur
<details>
  <summary>Le préprocesseur !</summary>

```cpp
#include <sil/sil.hpp>
#include "random.hpp"
#include <sstream>
#include <complex>
#include <iostream>
#include <cmath>
```
</details>

---

## ⭐ Ne garder que le vert
![green filter](/output/green_effect.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
void green_effect(sil::Image& img)
{
    for (glm::vec3& color : img.pixels())
    {
        color.r=0.f;
        color.b=0.f;
    }
}
```
</details>

---

## ⭐ Échanger les canaux
  Je me demande s'il n y a pas une **autre facon** à faire que *std::swap*
  On peut aussi améliorer le programe en mettant dans les parametre les couleurs qu'on veut echanger .

![image](/output/exchange_color.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
void exchange_color(sil::Image& img)
{
    for(glm::vec3& color : img.pixels())
    {
        std::swap(color.r,color.b);
        //EST CE QU'IL Y A UNE AUTRE FACON DE FAIRE QUE SWAP???
        if (color.r &&!color.b && !color.g)
        {
            color.b=color.r;
            color.r=0;
        }
        if (color.b && !color.r && !color.g)
        {
            color.r=color.b;
            color.b=0;
        }
        
    }
}
```
</details>

---

## ⭐ Noir & Blanc

Pour le gris il y a 2 methode:
 - Dire que le gris = 0.3*R+0.59*G+0.11B (celle ci est plus proche de ce que voit l'oeil)
 - Prendre gris = x*R+X*G+X*B (avec 
 0<x<1)

![image](/output/NdW.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
void NdW (sil::Image& img)
{
    for (glm::vec3& color : img.pixels())
    {
        float luminance = 0.3f * color.r + 0.59f * color.g + 0.11f * color.b;
        color= glm::vec3 {luminance};
    }
}
```
</details>

---

## ⭐ Négatif

De preference utiliser les *glm::vec3 {x,y,z}* . C'est des cordonnées à 3 valeur.
![image](/output/negative.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
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
```
</details>

---

## ⭐ Dégradé

Pour cet exos, il faut **créer** une image noir de **taille (x,y)** dans le __*int main()*__

<details>
  <summary>Crée image C++ !</summary>

```cpp
sil::Image image{x/*width*/, y/*height*/};
```
</details>

![image](/output/gradient.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
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
```
</details>

---

## ⭐⭐ Miroir

J'ai **ajouter** dans les **paramètres** sur quel **axe** on veut faire la **symétrie**. Car j'utilise cette fonction dans une autre.
![image](/output/miror.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
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
```
</details>

---

## ⭐⭐ Image bruitée

**Problème** !!! **Pas de bruit** sur la  **couleur blanche**, malgré que j'ai mis d'enlever les px si on a que du blanc!

Problème plus ou moins réglé mais ... (Faut trouver une methode plus intéligente)
![image](/output/noise.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
void noise_filter(sil::Image& img)//pas vraiment ce que ca demande
{
    for (glm::vec3& color : img.pixels())
    {
        float a=random_float(0, 0.75);
        float b=random_float(0, 0.75);
        float c=random_float(0, 0.75);
        if (color==glm::vec3{1,1,1})
        {
            color=glm::vec3 {color.r*a,color.g*b,color.b*c};
        }
        color=glm::vec3 {color.r+a,color.g+b,color.b+c};
    }
}
```
</details>

---

## ⭐⭐ Rotation de 90°
![image](/output/rotation.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
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
```
</details>

---
---

## ⭐🔆⭐ Rotation (degré)

**Un petit plus**, c'étais pour créer un schéma que vous trouverez en bas .
<details>
  <summary>La fonction C++ !</summary>

```cpp
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
```
</details>

---
---

## ⭐⭐ RGB split

On peut changer les paramètres pour choisir le nombre de pixels de décalage.
![image](/output/split.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
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
```
</details>

---

## ⭐⭐ Luminosité
Meme fonction, c'est **le choit** du parametre *__l__* qui determine la luminosité.
### éclairssir
![image](/output/clear_up.png)

### assembrir
![image](/output/clear_down.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
void clear_l (sil::Image& img, float l)// 0.3<l<2 si nn trop fort l'effet
{
    for (glm::vec3& color:img.pixels())
    {
        if (l<1)
        {
            if (color!=glm::vec3{0,0,0})
            {
                color.r=std::pow(color.r,0.5);
                color.b=std::pow(color.b,0.5);
                color.g=std::pow(color.g,0.5);
            }
        }
        //color*=color; //c'est un peu trop fort 
        color.r=std::pow(color.r,l);
        color.b=std::pow(color.b,l);
        color.g=std::pow(color.g,l);
    }
}
```
</details>

---

## ⭐⭐(⭐) Disque
![image](/output/disk.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
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
```
</details>

---

## ⭐ Cercle

J'ai mis dans les **paramètres** __*x_center*__ et __*y_center*__ car on reutilise la fonction plus tard.
![image](/output/cercle.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
void circle (sil::Image& img,int r,int t,float x_center,float y_center) //(image, rayon, epaisseur)
{
    //a mettre dans les paramètres si on veut le centre de l'image:
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
```
</details>

---

## ⭐⭐ Animation

**Guillaume** m'a aidé sur des details à la fin pour quelle soit **bien propore**. Tel la **disparitiion totale du disque**.
J'ai aussi demandé à **ChatGPT** pour la **création de plusieur image** dans une fct.J'utilise pour cela: *__std::ostringstream filename;__*
![image](/output/anim.gif)
<details>
  <summary>La fonction C++ !</summary>

```cpp
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
```
</details>

---

## ⭐⭐⭐ Rosace
C'est ici ou j'utilise la fct *__circle__* mais avec des **coordonnées** de **centre** **différents**
![image](/output/rosace.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
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
```
</details>

---

## ⭐⭐⭐(⭐) Fractale de Mandelbrot

Et oui, on a pété les plomb avec **Guillaum** MDR. 
Toute une apres-midi a été consacré pour réaliser cette belle fractale. Franchement c'était **trop amusant**.
![image](/output/fractale.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
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
```
</details>

---

## ⭐⭐⭐⭐ Mosaïque miroir

J'ai utilsé la fonction **_miror_**, et c'est ici ou je de vais **changer** les **axes de symétrie**s.
![image](/output/mosaique_miror.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
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
```
</details>

---

## ⭐⭐⭐ Glitch
C'est pas super beau, je dois encore l'ameliorer
![image](/output/glitch.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
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
```
</details>

---

## ⭐ T...
![image](/output/...)
<details>
  <summary>La fonction C++ !</summary>

```cpp
...
```
</details>

---
---
La j'ai voulu faire des schèmas en se basant sur le ZELIJ (carrelage / Mosaique) Andalouse
![image](/zeloij.JPG)

Pour cela, j'ai du créer plusieurs fonction.

---

## ⭐ Carreau
Fallait dans un premier lieu créer un carré que je peut mettre sur une images.
![image](/output/carre.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
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
```
</details>

---

## ⭐ Premier motif
J'ai utilisé les fonctions déja presenté. 
*__Carreau__* , *__Cercle__* , *__Rotation_deg__* 
![image](/output/andal.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
void andal(sil::Image& img,int r, int t)
{
    circle(img,img.width()/2,t,img.width()/2,img.height()/2);
    carreau(img,std::sqrt(2)*r,t,img.width()/2,img.height()/2);
    rotation_deg(img,M_PI/4);
    carreau(img,std::sqrt(2)*r,t,img.width()/2,img.height()/2);
    //rotation_deg(img,M_PI/4);//solution ponctuel
}
```
</details>

---

## ⭐ Mosaique / Format finale
Pour cette fonction, j'ai mis  **2 facteur** **_(n,f)_**, ils permetent de changé les proportion de l'image.

Et ca donne ca:
![image](/output/mosaique_andal.png)
<details>
  <summary>La fonction C++ !</summary>

```cpp
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
```
</details>

