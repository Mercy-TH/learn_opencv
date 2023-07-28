//
// Created by th on 2023/7/28.
//

#ifndef LEARN_OPENCV_CHAPTER3_H
#define LEARN_OPENCV_CHAPTER3_H

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// resize and crop images

/*
 * 调整图像大小
 */
void resize(const string &path) {
    Mat img = imread(path);
    Mat img_resize;
    cout<<img.size()<<endl;
    //按固定大小 resize
    resize(img, img_resize, Size(640,480));
    //按固定比例 resize
//    resize(img, img_resize, Size(), 0.5,0.5);
    cout<<img_resize.size()<<endl;
    imshow("img", img);
    imshow("img_resize", img_resize);
    waitKey();
    destroyAllWindows();
}

/*
 * 裁剪图像
 */
void crop(const string &path){
    Mat img = imread(path);
    Mat img_crop;
    // 这里的100,100表示需要裁剪的图像的左上角坐标, 300表示裁剪图像的width，250表示裁剪图像的height
    Rect roi(100,100,300,250);
    img_crop = img(roi);
    imshow("img", img);
    imshow("img_crop", img_crop);
    waitKey();
    destroyAllWindows();
}






#endif //LEARN_OPENCV_CHAPTER3_H
