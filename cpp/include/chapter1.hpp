//
// Created by th on 2023/7/27.
//

#ifndef LEARN_OPENCV_CHAPTER1_HPP
#define LEARN_OPENCV_CHAPTER1_HPP
/*
 * read images videos and webcams
 */

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace cv;
using namespace std;

//图像和视频读取

/*
 * 读取图片
 */
Mat read_image(const string& path) {
    Mat img = imread(path);
    imshow("img", img);
    waitKey();
    destroyAllWindows();
    return img;
}


/*
 * 读取视频
 */
void read_video(const string& path) {
    VideoCapture cap(path);
    Mat img;
    if (!cap.isOpened()) {
        return;
    }
    int width = (int)cap.get(CV_CAP_PROP_FRAME_WIDTH);
    int height = (int)cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    int fps = (int)cap.get(CV_CAP_PROP_FPS);
    printf("current fps : %d \n", fps);
    printf("current width : %d \n", width);
    printf("current height : %d \n", height);
    while (cap.read(img)) {
        imshow("camera-demo", img);
        char c = (char)waitKey(20);
        if (c == 'q' || c == 'Q') {
            break;
        }
    }
    cap.release();
    destroyAllWindows();
}


#endif //LEARN_OPENCV_CHAPTER1_HPP
