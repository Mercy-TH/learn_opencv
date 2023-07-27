//
// Created by th on 2023/7/27.
//

#ifndef LEARN_OPENCV_TEST_H
#define LEARN_OPENCV_TEST_H

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace cv;
using namespace std;

void test_opencv() {
    string path = "../dog.jpg";
    Mat img = imread(path);
    imshow("dog", img);
    waitKey();
    destroyAllWindows();
}


#endif //LEARN_OPENCV_TEST_H
