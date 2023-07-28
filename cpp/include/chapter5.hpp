//
// Created by th on 2023/7/28.
//

#ifndef LEARN_OPENCV_CHATPTER5_H
#define LEARN_OPENCV_CHATPTER5_H

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// 仿射变换 wrap images


void wrap_image(const string& path){
    Mat img = imread(path);

    //需要变换的四个点　分别对应左上、右上、左下、右下
    Point2f src[4] = {{80,50},{700,50},{80,420},{600,400}};
    float w = 640.0f;
    float h = 320.0f;
    Point2f dst[4] = {{0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h}};

    //转换矩阵
    Mat matrix,img_wrap;
    matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img, img_wrap, matrix, Point(w,h));

    imshow("img", img);
    imshow("img_wrap", img_wrap);
    waitKey();
    destroyAllWindows();
}




















#endif //LEARN_OPENCV_CHATPTER5_H
