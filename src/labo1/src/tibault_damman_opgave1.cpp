#include <cstdio>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

const char* winname = "td.labo1";

Mat loadImg(const char* filename, bool color = true)
{
	return color ? imread(filename) : imread(filename, CV_LOAD_IMAGE_GRAYSCALE);
}

void showImg(const char* window, const Mat* img) 
{
    imshow(window, *img);
	waitKey();
}

void start_show(const char* filename)
{
	namedWindow(winname);
	
	//color
	Mat img = loadImg(filename);
	showImg(winname, &img);
	
	//greyscale
	Mat img_gr;
	cvtColor(img, img_gr, CV_RGB2GRAY);
	showImg(winname, &img_gr);
	
	/* //greyscale - alt
	img_gr = loadImg(filename, false);
	showImg(winname, &img_gr);
	*/
	
	//threshold 50%
	Mat img_thr;
	threshold(img_gr, img_thr, 128, 255, THRESH_TOZERO); //of _BINARY voor Z/W
	showImg(winname, &img_thr);
	
	//writeout
	imwrite("greyscale.png", img_gr);
	imwrite("threshold.png", img_thr);
}

int main(int argc, char **argv){
	printf("labo beeldverwerking - opdracht 1\n");
	
	if (argc > 1)
	{
	    printf("show: %s\n",argv[1]);
	    
	    try 
	    {
		    start_show(argv[1]);
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
