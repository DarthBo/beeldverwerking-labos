#include <cstdio>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;

const char* win1 = "input";
const char* win2 = "fixed";

int total = 0;
Point2f morph[4];

Mat img;

static void onMouse( int event, int x, int y, int, void* )
{
    if (event != EVENT_LBUTTONUP)
        return;

    if (total < 4)
    {
        morph[total].x = x;
        morph[total].y = y;
        ++total;
        std::cout << x << "," << y << std::endl;
    }
    if (total == 4)
    {
        //doe transf
        Point2f goal[4];
        //ga uit van LB, RB, LO, RO
        goal[0].x = morph[2].x;
        goal[0].y = morph[0].y;
        goal[1].x = morph[3].x;
        goal[1].y = morph[0].y;
        goal[2].x = morph[2].x;
        goal[2].y = morph[2].y;
        goal[3].x = morph[3].x;
        goal[3].y = morph[2].y;
        Mat tr = getPerspectiveTransform(morph, goal);

        Mat out;
        warpPerspective(img, out, tr, img.size());

        namedWindow(win2);
        imshow(win2, out);

        //show result
        std::cout << "=======" << std::endl;
    }

}

void labo9(const char* filename)
{
    namedWindow(win1);

    img = imread(filename);

    setMouseCallback(win1,onMouse);

    imshow(win1, img);

    waitKey();
}

int main(int argc, char **argv)
{
    printf("labo beeldverwerking - opdracht 9\n");

    if (argc > 1)
    {
        printf("show: %s\n",argv[1]);

        try
        {
            labo9(argv[1]);
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
