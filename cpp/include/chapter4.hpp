//
// Created by th on 2023/7/28.
//

#ifndef LEARN_OPENCV_CHAPTER4_H
#define LEARN_OPENCV_CHAPTER4_H

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// drawing shapes and text

/*
 * 绘制空白图像
 */
void draw(){
    //创建空白图像 CV_8UC3表示　　
    // 8表示2**8,表示256个(0-255)
    // U表示unsigned无符号 ,如果没有U表示有符号-127到127
    // C3表示三个通道
    // Scalar 标量　参数是(B,G,R)
    Mat img(512,512,CV_8UC3, Scalar(255,255,255));

    imshow("img", img);
    waitKey();
    destroyAllWindows();
}

/*
 * 画圆
 */
void draw_circle(){
    Mat img(512,512,CV_8UC3, Scalar(255,255,255));
    //Point表示圆在图像img的中心点位置　155表示圆的半径 Scalar表示圆的颜色 10表示圆的厚度，若填FILLED则把圆填充满
    circle(img, Point(256,256),155,Scalar(0,69,255), 10);
    imshow("img", img);
    waitKey();
    destroyAllWindows();
}


#endif //LEARN_OPENCV_CHAPTER4_H
