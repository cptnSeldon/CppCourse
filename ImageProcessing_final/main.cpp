#include "image.h"
int main()
{
    //P1    - black & white
    string in_washington = "Originals/washington.ascii.pbm";
    string out_washington_inverse = "Inverse/washington_inverse.pbm";
    string histogram = "Histogram/test_p1.txt";
    //P2    - grayscale
    string in_gator = "Originals/gator.ascii.pgm";
    string out_gator_inverse = "Inverse/gator_inverse.pgm";
    string out_gator_max_125 = "Max/gator_max_125.pgm";
    string out_gator_min_50 = "Min/gator_min_50.pgm";
    //P3    - rgb
    string in_blackbuck = "Originals/blackbuck.ascii.ppm";
    string out_blackbuck_inverse = "Inverse/blackbuck_inverse.ppm";
    //P3 bis
    string grayscale = "blackbuck_grayscale.ppm";

    //P1
    Image * p1 = new Image(in_washington);
    p1->Inverse();
    p1->WriteImageFromArray(out_washington_inverse);

    p1->Histogram(histogram);

    //P2
    Image * p2 = new Image(in_gator);
    Image p2_1 = *p2;

    string t = "gator.ascii.pgm";
    p2_1.WriteImageFromMatrix(t);

    p2->Inverse();
    p2->WriteImageFromMatrix(out_gator_inverse);

    histogram = "Histogram/test_p2.txt";
    p2->Histogram(histogram);

    p2 = new Image(in_gator);
    p2->SetMax(125);
    p2->WriteImageFromMatrix(out_gator_max_125);

    p2 = new Image(in_gator);
    p2->SetMin(50);
    p2->WriteImageFromMatrix(out_gator_min_50);

    //P3
    Image * p3 = new Image(in_blackbuck);

    p3->Inverse();
    p3->WriteImageFromMatrix(out_blackbuck_inverse);

    histogram = "Histogram/test_p3.txt";
    p3->Histogram(histogram);

    //P3 bis
    Image * p4 = new Image(in_blackbuck);
    p4->ColorToGrayscaleFromMatrix();
    p4->WriteImageFromMatrix(grayscale);

    /* DELETE pointers */
    delete p1;
    p1 = NULL;

    delete p2;
    p2 = NULL;

    delete p3;
    p3 = NULL;

    delete p4;
    p4 = NULL;

    return 0;
}