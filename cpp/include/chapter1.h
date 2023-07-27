//
// Created by th on 2023/7/27.
//

#ifndef LEARN_OPENCV_CHAPTER1_H
#define LEARN_OPENCV_CHAPTER1_H
/*
 * read images videos and webcams
 */

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace cv;
using namespace std;

Mat read_image(string path){
    Mat img = imread(path);
    return img;
}






#endif //LEARN_OPENCV_CHAPTER1_H
