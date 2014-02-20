#include <cstdio>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;


const char* win1 = "input";
const char* win2 = "fixed";

void labo7(const char* filename)
{
    namedWindow(win1);
    namedWindow(win2);

    Mat img = imread(filename);

    //imshow(win1, img);

    //verticale sluiting: dilatatie -> erosie

    imshow(win1, img);

    Mat tmp;
    Mat kern_dil = getStructuringElement(MORPH_RECT,Size(5,5));
    erode(img,tmp,kern_dil);

   // imshow(win1, tmp);

    Mat out;
    Mat kern_er = getStructuringElement(MORPH_RECT,Size(1,5));
    dilate(tmp,out,kern_er,Point(-1,-1),4);

    imshow(win2, out);

    waitKey();
}


int main(int argc, char **argv)
{
    printf("labo beeldverwerking - opdracht 7\n");

    if (argc > 1)
    {
        printf("show: %s\n",argv[1]);

        try
        {
            labo7(argv[1]);
        }
        catch (...)
        {
            printf("Something fucked up\n");
            return 1;
        }
    }
    else
    {
        printf("usage: %s <image>\n",argv[0]);
    }

    return 0;
}
