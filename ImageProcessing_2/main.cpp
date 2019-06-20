#include "image.h"

int main()
{
    string bitmap_file = "Originals/washington.ascii.pbm";      //BITMAP
    string graymap_file = "Originals/gator.ascii.pgm";          //GRAYMAP
    string pixmap_file = "Originals/blackbuck.ascii.ppm";       //PIXMAP
    //CREATE IMAGE
    Image<Bitmap> * i = new Image<Bitmap>("P1", 2, 2, -1);

    i->LoadImage(bitmap_file);
    i->PrintInConsole();

    //DELETE IMAGE
    delete i;
    i = NULL;

    return 0;
}