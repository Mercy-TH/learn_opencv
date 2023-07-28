//
// Created by th on 2023/7/28.
//

#ifndef LEARN_OPENCV_CHAPTER6_H
#define LEARN_OPENCV_CHAPTER6_H

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//图像颜色检测 detect color in image


void detect_color(const string& path){
    Mat img = imread(path);
    resize(img, img, Size(640,480));
    Mat img_hsv, mask;
    cvtColor(img, img_hsv, COLOR_BGR2HSV);

    //设置需要识别的hsv颜色范围
    int hmin=77,smin=108,vmin=151;
    int hmax=113,smax=228,vmax=255;
    //可以调节HSV值的窗口
    namedWindow("Trackbars", (640,200));
    createTrackbar("Hue Min","Trackbars",&hmin,255);
    createTrackbar("Hue Max","Trackbars",&hmax,255);
    createTrackbar("Sat Min","Trackbars",&smin,255);
    createTrackbar("Sat Max","Trackbars",&smax,255);
    createTrackbar("Val Min","Trackbars",&vmin,255);
    createTrackbar("Val Max","Trackbars",&vmax,255);

    while (true) {
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        inRange(img_hsv, lower, upper, mask);

        imshow("img", img);
        imshow("img_hsv", img_hsv);
        imshow("mask", mask);
        char c = (char)waitKey(1);
        if (c == 'q' || c == 'Q') {
            break;
        }
    }
    destroyAllWindows();
}








#endif //LEARN_OPENCV_CHAPTER6_H
