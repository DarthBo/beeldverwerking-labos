#include <cstdio>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"

using namespace cv;

const int min_feat = 32;
const int max_feat = 48;

void fast_feat(Mat img, std::vector<KeyPoint>& keypoints)
{
    int nrfound = 0;
    int threshold = 50;

    while(nrfound<min_feat || nrfound>max_feat)
    {
      FastFeatureDetector detector(threshold, true);
      detector.detect(img, keypoints);
      nrfound = keypoints.size();
      if (nrfound < min_feat)
          threshold -= 5;
      else if (nrfound > max_feat)
          threshold += 5;
    }
    //std::cout << "# FAST features:" << nrfound << std::endl;
}

void labo13(const char* file1, const char* file2)
{
    Mat img1 = imread(file1);
    Mat img2 = imread(file2);
    Mat grey1;
    Mat grey2;
    cvtColor(img1, grey1, CV_RGB2GRAY);
    cvtColor(img2, grey2, CV_RGB2GRAY);

    //find FAST features
    std::vector<KeyPoint> keypoints1;
    fast_feat(grey1, keypoints1);
    std::vector<KeyPoint> keypoints2;
    fast_feat(grey2, keypoints2);

    // make BRIEF descriptors
    BriefDescriptorExtractor extractor(32);
    Mat descriptors1, descriptors2;
    extractor.compute(grey1, keypoints1, descriptors1);
    extractor.compute(grey2, keypoints2, descriptors2);

    // find closest matches between descriptors
    BFMatcher matcher(NORM_HAMMING, false);
    vector<DMatch> matches;
    matcher.match(descriptors1, descriptors2, matches);

    // draw matches
    Mat out;
    cv::drawMatches(img1, keypoints1, img2, keypoints2, matches, out);

    imshow("matches", out);
    waitKey();
}

int main(int argc, char **argv)
{
    printf("labo beeldverwerking - opdracht 13\n");

    if (argc == 3)
    {
        printf("Opening:\n file1: %s\n file2: %s\n", argv[1], argv[2]);

        try
        {
            labo13(argv[1], argv[2]);
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
