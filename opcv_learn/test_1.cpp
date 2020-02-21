#include "opencv2/opencv.hpp"
#include <stdio.h>

using namespace std;
using namespace cv;

void showDFT (Mat& source);
void recenterDFT(Mat& source);
void takeDFT (Mat& source, Mat& destination);

int main (int argv  , char** args)
{
    // ------------------- Load, Save File 
    //Mat image = imread("me.jpg", CV_LOAD_IMAGE_UNCHANGED);
    //Mat image_gray = imread("me.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    //Mat gray =  imread("me.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    //imshow("color", image);
    //imshow("gray", gray);
    //imwrite("outputGray.jpg", gray);
    // 
    // ----------------------- new window
/*
    namedWindow("Color", CV_WINDOW_FREERATIO);
    namedWindow("Fixed", CV_WINDOW_AUTOSIZE);
    
   
    imshow("Color", image);
    imshow("Fixed", image_gray);
    
    resizeWindow("Color", image.cols/2, image.rows/2);
    resizeWindow("Fixed", image_gray.cols/2, image_gray.rows/2);
    */



    // =====================
    /*
    Mat original = imread("me.jpg", CV_LOAD_IMAGE_COLOR);
    Mat modified = imread("me.jpg", CV_LOAD_IMAGE_COLOR);

    for (int r = 0 ; r < modified.rows;  r++)
    {
        for (int c = 0 ; c < modified.cols; c++)
        {
            //blue
            modified.at<cv::Vec3b>(r,c)[0] = modified.at<cv::Vec3b>(r,c)[0] * 0;
            //green 
            modified.at<cv::Vec3b>(r,c)[1] = modified.at<cv::Vec3b>(r,c)[1] * 0;
        }
    }
    
    imshow("original", original);
    imshow("modified", modified);
    waitKey();
    */
    //================================Spilt and merge 
    /*
    Mat original = imread("me.jpg", CV_LOAD_IMAGE_COLOR);
    Mat splitChannels[3];

    split(original, splitChannels);

    imshow("original", original);
    imshow("blue", splitChannels[0]);
    imshow("green", splitChannels[1]);
    imshow("red", splitChannels[2]);

    splitChannels[2] = Mat::zeros(splitChannels[2].size(), CV_8UC1);
    Mat output; 
    merge(splitChannels,3, output);
    imshow("output", output);

    waitKey();
    */
    //===========================================   resize
    /*
    Mat original = imread("me.jpg", CV_LOAD_IMAGE_UNCHANGED);
    double SHRINK = 0.3;
    //cout <<"ratio fo original : " << ratio;
    Mat newPic;
    resize(original, newPic, Size(), SHRINK, SHRINK, CV_INTER_AREA);
    imshow("original", original);
    imshow("newPic", newPic);
    imwrite("me_new.jpg", newPic);
    waitKey();
    return 0;
    */

    Mat original = imread("me.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    Mat originalFloat;
    // 0~255  -> 0~1
    original.convertTo(originalFloat, CV_32FC1, 1.0/255.0);
    

    Mat dftOfOriginal;
    takeDFT(originalFloat, dftOfOriginal);
    
    recenterDFT(dftOfOriginal);

    showDFT(dftOfOriginal);

    waitKey();
    return 0;
}

void showDFT (Mat& source)
{
    //visual two channels
    Mat splitArray[2] = {Mat::zeros(source.size(), CV_32F), Mat::zeros(source.size(), CV_32F)};
    
    split (source , splitArray);

    Mat dftMagnitude ;

    magnitude(splitArray[0], splitArray[1], dftMagnitude);

    dftMagnitude += Scalar::all(1);

    log(dftMagnitude, dftMagnitude);

    normalize(dftMagnitude, dftMagnitude, 0 ,1 ,CV_MINMAX);
    imshow("DFT", dftMagnitude);
    waitKey();
}

void takeDFT (Mat& source, Mat& destination)
{
    Mat originalComplex[2] = {source, Mat::zeros(source.size(), CV_32FC1)};
    
    Mat dftReady;

    merge(originalComplex, 2, dftReady);


    Mat dftOfOriginal;

    dft(dftReady, dftOfOriginal, DFT_COMPLEX_OUTPUT);

    destination = dftOfOriginal;
}

void recenterDFT(Mat& source)
{
    int centerX = source.cols / 2 ;
    int centerY = source.rows / 2 ;

    Mat q1(source, Rect(0 ,0 , centerX, centerY));
    Mat q2(source, Rect(centerX ,0 , centerX, centerY));
    Mat q3(source, Rect(0 ,centerY , centerX, centerY));
    Mat q4(source, Rect(centerX ,centerY , centerX, centerY));

    Mat swapMap;

    q1.copyTo(swapMap);
    q4.copyTo(q1);
    swapMap.copyTo(q4);

    q2.copyTo(swapMap);
    q3.copyTo(q2);
    swapMap.copyTo(q3);
    
}