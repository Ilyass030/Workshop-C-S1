#include <sil/sil.hpp>
#include "random.hpp"

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

void miror(sil::Image& img)
{
    int width =img.width();
    sil::Image copy {img};
    for(int x=0;x<width;x++)
    {
        for(int y=0;y<img.height();y++)

        {
            img.pixel(x,y)=copy.pixel(width-x-1,y);
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
    miror (img);
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

void disk(sil::Image& img)
{
    for(int x=0;x<img.width();x++)
    {
        for (int y=0; y<img.height();y++)
        {
            if //a termienr
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
    //     miror(image);
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
    {
        sil::Image image{500/*width*/, 500/*height*/};
        sil::Image image{"images/photo.jpg"};
        clear_up(image);
        image.save("output/clear_up.png");
    }
    

}