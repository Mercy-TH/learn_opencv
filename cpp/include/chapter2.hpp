//
// Created by th on 2023/7/28.
//

#ifndef LEARN_OPENCV_CHAPTER2_HPP
#define LEARN_OPENCV_CHAPTER2_HPP

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace cv;
using namespace std;


// 图像基本操作

/*
 * BGR to GRAY
 */
void rgb2gray(const string &path) {
    Mat img = imread(path);
    Mat img_gray;
    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    imshow("img_gray", img_gray);
    waitKey();
    destroyAllWindows();
}

/*
 * 高斯模糊
 */
void gaussianBlur(const string &path) {
    Mat img = imread(path);
    Mat img_blur;
    GaussianBlur(img, img_blur, Size(7, 7), 5, 0);
    imshow("img_blur", img_blur);
    waitKey();
    destroyAllWindows();
}

/*
 * canny边缘检测
 */
void canny(const string &path){
    Mat img = imread(path);
    Mat img_canny, img_blur;
    GaussianBlur(img, img_blur, Size(7, 7), 5, 0);
    Canny(img_blur, img_canny,25,75);
    imshow("img_canny", img_canny);
    waitKey();
    destroyAllWindows();
}

/*
 * 扩大图像边缘
 */
void dilate(const string &path){
    Mat img = imread(path);
    Mat img_canny, img_blur, img_dilate;
    GaussianBlur(img, img_blur, Size(7, 7), 5, 0);
    Canny(img_blur, img_canny,25,75);
    //定义核结构
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));
    dilate(img_canny, img_dilate, kernel);
    imshow("img_canny", img_canny);
    imshow("img_dilate", img_dilate);
    waitKey();
    destroyAllWindows();
}

/*
 * 腐蚀图像
 */
void erode(const string &path){
    Mat img = imread(path);
    Mat img_canny, img_blur, img_dilate, img_erode;
    GaussianBlur(img, img_blur, Size(7, 7), 5, 0);
    Canny(img_blur, img_canny,25,75);
    //定义核结构
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));
    dilate(img_canny, img_dilate, kernel);

    erode(img_dilate, img_erode, kernel);
    imshow("img_canny", img_canny);
    imshow("img_dilate", img_dilate);
    imshow("img_erode", img_erode);
    waitKey();
    destroyAllWindows();
}



#endif //LEARN_OPENCV_CHAPTER2_HPP
