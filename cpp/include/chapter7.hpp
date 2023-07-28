//
// Created by th on 2023/7/28.
//

#ifndef LEARN_OPENCV_CHAPTER7_H
#define LEARN_OPENCV_CHAPTER7_H

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//轮廓检测,形状识别 shapes detection

/*
 * 检测形状并画形状图
 */
void getContours(Mat &img_dilate, Mat &img){
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(img_dilate, contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    drawContours(img, contours,-1, Scalar(255,0,255), 5);

    //过滤形状
    for(int i=0;i<contours.size();i++)
    {
        double area = contourArea(contours[i]);
        cout<<area<<endl;
        vector<vector<Point>> conPoly(contours.size());
        vector<Rect> boundRect(contours.size());
        string obj_type;
        if(area>100)
        {
            double peri = arcLength(contours[i], true);
            approxPolyDP(contours[i],conPoly[i],0.02*peri,true);
            drawContours(img,conPoly,i,Scalar(255,0,255),2);
            //打印出每个轮廓边的数量
            cout<<conPoly[i].size()<<endl;
            //用矩形框把形状框出来
            boundRect[i] = boundingRect(conPoly[i]);
            rectangle(img, boundRect[i].tl(),boundRect[i].br(),Scalar(0,255,0),5);

            //把不同形状提出来
            int objCor = (int)conPoly[i].size();
            if(objCor==3){obj_type="Tri";}
            if(objCor==4){
                float ratio = (float)boundRect[i].width / (float)boundRect[i].height;
                if(ratio>=0.85 && ratio<=1.2){
                    obj_type = "Square";
                }else {
                    obj_type = "Rect";
                }
            }
            if(objCor>4){obj_type="Circle";}
            putText(img, obj_type,{boundRect[i].x,boundRect[i].y-5}, FONT_HERSHEY_DUPLEX,0.75,Scalar(0,0,255),1);
        }
    }
}


void detect_shape(const string& path){
    Mat img = imread(path);
    resize(img, img, Size(640,480));
    Mat img_canny, img_blur, img_gray, img_dilate, img_erode;
    //预处理，找出形状
    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    GaussianBlur(img_gray, img_blur, Size(5, 5), 5, 0);
    Canny(img_blur, img_canny,25,75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));
    dilate(img_canny, img_dilate, kernel);
    erode(img_dilate, img_erode, kernel);

    getContours(img_dilate, img);

    imshow("img", img);
//    imshow("img_gray", img_gray);
//    imshow("img_blur", img_blur);
//    imshow("img_canny", img_canny);
    imshow("img_dilate", img_dilate);
//    imshow("img_erode", img_erode);
    waitKey();
    destroyAllWindows();
}






















#endif //LEARN_OPENCV_CHAPTER7_H
