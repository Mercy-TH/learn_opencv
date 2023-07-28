//
// Created by th on 2023/7/28.
//

#ifndef LEARN_OPENCV_CHAPTER8_H
#define LEARN_OPENCV_CHAPTER8_H

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>


using namespace cv;
using namespace std;

// face detection

void face_detect(const string& path, const string& asset_path){
    Mat img = imread(path);
    auto *faceCascade = new CascadeClassifier;
    faceCascade->load(asset_path);
    if(faceCascade->empty()){cout<<"xml file not loaded."<<endl;}

    vector<Rect> faces;
    faceCascade->detectMultiScale(img, faces, 1.1,10);

    for(auto & face : faces){
        rectangle(img, face.tl(),face.br(), Scalar(255,0,255), 3);
    }

    imshow("img", img);
    waitKey();
    destroyAllWindows();
}











#endif //LEARN_OPENCV_CHAPTER8_H
