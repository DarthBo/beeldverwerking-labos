#include <cstdio>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

const char* win1 = "input";
const char* win2 = "fixed";

void labo10(const char* filename)
{
    int size = 45;


    // ///////////////////////////////////


    assert(size%2 == 1);

    Mat img = imread(filename);
    imshow(win1, img);
    //1
    Mat gaussk = getGaussianKernel(size, 15.6, CV_32F);
    //2
    Mat vkm = Mat::zeros(size, size, CV_32F);
    gaussk.col(0).copyTo(vkm.col(size/2));
    //3
    Mat gaussrow = getGaussianKernel(size, 0.1, CV_32F).t();
    //4
    Mat gauss2D;
    filter2D(vkm, gauss2D, CV_32F, gaussrow);
    //5
    Mat dog;
    Sobel(gauss2D, dog, CV_32F, 1, 0);
    //dog = abs(dog)/1000;
    //6
    Mat rot = getRotationMatrix2D(Point2f(size/2,size/2), -14, 1);
    Mat fdog;
    warpAffine(dog, fdog, rot, dog.size());
    //7
    Mat imgr;
    cvtColor(img, imgr, CV_RGB2GRAY);
    Mat imgrot;
    filter2D(imgr, imgrot, CV_32F, fdog);

    imshow(win2,abs(imgrot)/1000);

    waitKey();
}


int main(int argc, char **argv)
{
    printf("labo beeldverwerking - opdracht 10\n");

    if (argc > 1)
    {
        printf("show: %s\n",argv[1]);

        try
        {
            labo10(argv[1]);
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
