#include <cstdio>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

const int maxCorners = 100;
const double qualityLevel = 0.05;
const double minDistance = 15;

void labo12(const char* file1, const char* file2)
{
    Mat img1 = imread(file1);
    Mat img2 = imread(file2);

    // convert to grayscale
    Mat gray1, gray2;
    cvtColor(img1, gray1, CV_RGB2GRAY);
    cvtColor(img2, gray2, CV_RGB2GRAY);

    cv::Canny(gray1, gray1, 100, 300);
    cv::Canny(gray2, gray2, 100, 300);

    // find corners
    vector<Point2f> corners1, corners2;
    goodFeaturesToTrack(gray1, corners1, maxCorners, qualityLevel, minDistance);
    goodFeaturesToTrack(gray2, corners2, maxCorners, qualityLevel, minDistance);

    // draw corners
    for (size_t i=0; i<corners1.size(); i++ ){
        circle(img1, corners1[i], 1, Scalar(0,0,255),2);
    }
    for (size_t i=0; i<corners2.size(); i++ ){
        circle(img2, corners2[i], 1, Scalar(0,0,255),2);
    }

    imshow("Hough corners 1", img1);
    imshow("Hough corners 2", img2);

    waitKey();
}

int main(int argc, char **argv)
{
    printf("labo beeldverwerking - opdracht 12\n");

    if (argc == 3)
    {
        printf("Opening:\n file1: %s\n file2: %s\n", argv[1], argv[2]);

        try
        {
            labo12(argv[1], argv[2]);
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
