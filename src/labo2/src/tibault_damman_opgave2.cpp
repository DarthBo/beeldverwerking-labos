#include <cstdio>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

const char* win1 = "input";
const char* win2 = "fixed";

void start_show(const char* filename)
{
    namedWindow(win1);
    namedWindow(win2);
    
	Mat img = imread(filename);
	
	Mat blur;
	Size ksize;
	ksize.width = 5;
	ksize.height = 5;
    GaussianBlur(img, blur, ksize, 1.2);
    
    imshow(win1, img);
    imshow(win2, blur);
	waitKey();
}

int main(int argc, char **argv){
	printf("labo beeldverwerking - opdracht 2\n");
	
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
