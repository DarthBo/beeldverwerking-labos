#include <cstdio>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

const char* win1 = "input";
const char* win2 = "fixed";

void unsharpMask(cv::Mat& im)
{
    Mat tmp;
    GaussianBlur(im, tmp, Size(30,30), 5);
    addWeighted(im, 1.5, tmp, -0.5, 0, im);
}

void labo3(const char* filename){
    namedWindow(win1);
    namedWindow(win2);

    Mat img = imread(filename);
    imshow(win1, img);

    unsharpMask(img);
    imshow(win2, img);

    waitKey();
}

int main(int argc, char **argv){
    printf("labo beeldverwerking - opdracht 3\n");

    if (argc > 1)
    {
        printf("show: %s\n",argv[1]);

        try
        {
            labo3(argv[1]);
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


