#include <cstdio>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

const char* win1 = "input";
const char* win2 = "fixed";

void labo8(const char* filename)
{
    namedWindow(win1);
    //namedWindow(win2);

    Mat img = imread(filename);
    Mat out;

    Mat tt(2,3,CV_32F);
    tt.at<float>(0,0) = 1;
    tt.at<float>(0,1) = -0.2;
    tt.at<float>(0,2) = 50;
    tt.at<float>(1,0) = 0;
    tt.at<float>(1,1) = 1;
    tt.at<float>(1,2) = 0;

    warpAffine(img, out, tt, img.size());
    imshow(win1, img);
    imshow(win2, out);

    waitKey();
}

int main(int argc, char **argv)
{
    printf("labo beeldverwerking - opdracht 8\n");

    if (argc > 1)
    {
        printf("show: %s\n",argv[1]);

        try
        {
            labo8(argv[1]);
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
