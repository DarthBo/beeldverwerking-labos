#include <cstdio>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

const char* win1 = "input";
const char* win2 = "fixed";

void labo11(const char* filename)
{
    Mat src = imread(filename);
    imshow(win1, src);

    //convert to grayscale
    Mat grey;
    cvtColor(src, grey, CV_RGB2GRAY);

    //can canny come out to play?
    Mat edges;
    Canny(grey, edges, 5, 15);
    //imshow("canny", outline);

    //find lines
    vector<Vec2f> lines;
    HoughLines(edges, lines, 1, CV_PI/180, 100);

    // draw lines
    Mat out = src.clone();
    for(size_t i = 0; i < lines.size(); i++)
    {
       float rho = lines[i][0], theta = lines[i][1];
       Point pt1, pt2;
       double a = cos(theta), b = sin(theta);
       double x0 = a*rho, y0 = b*rho;
       pt1.x = cvRound(x0 + 1000*(-b));
       pt1.y = cvRound(y0 + 1000*(a));
       pt2.x = cvRound(x0 - 1000*(-b));
       pt2.y = cvRound(y0 - 1000*(a));
       line( out, pt1, pt2, Scalar(0,255,255), 2, CV_AA);
    }

    imshow("lines", out);
    waitKey();
}

int main(int argc, char **argv)
{
    printf("labo beeldverwerking - opdracht 11\n");

    if (argc > 1)
    {
        printf("show: %s\n",argv[1]);

        try
        {
            labo11(argv[1]);
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
