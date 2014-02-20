#include <cstdio>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

const char* win1 = "input";
const char* win2 = "fixed";

void labo5(const char* filename)
{
    namedWindow(win1);
    namedWindow(win2);

    Mat img = imread(filename, CV_LOAD_IMAGE_GRAYSCALE);

    imshow(win1, img);

    Mat out;
    Sobel(img, out, CV_32F, 1, 0);
    imshow(win2, abs(out)/1000);

    waitKey();
}


int main(int argc, char **argv)
{
    printf("labo beeldverwerking - opdracht 5\n");

    if (argc > 1)
    {
        printf("show: %s\n",argv[1]);

        try
        {
            labo5(argv[1]);
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



