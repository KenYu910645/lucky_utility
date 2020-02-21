#include <cstdio>
#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
#define PI 3.1416

void calcLinesP(const Mat &input, std::vector<Vec4i> &lines);
void drawLinesP(Mat &input, const std::vector<Vec4i> &lines);
void calcLines(const Mat &input, std::vector<Vec2f> &lines);
void drawLines(Mat &input, const std::vector<Vec2f> &lines);

int main(){
    Mat img = imread("test.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat result1 = imread("test.jpg",CV_LOAD_IMAGE_COLOR);
    Mat result2 = imread("test.jpg",CV_LOAD_IMAGE_COLOR);
    Mat view_contours = imread("test.jpg",CV_LOAD_IMAGE_COLOR);

    std::vector<Vec4i> linesP;
    calcLinesP(img,linesP);
    drawLinesP(result1, linesP);
    std::vector<Vec2f> lines;
    calcLines(img,lines);
    drawLines(result2, lines);
    

    Mat contours;
    Canny(view_contours, contours, 50, 150); 
    namedWindow("Display window1", WINDOW_AUTOSIZE);
    namedWindow("Display window2", WINDOW_AUTOSIZE);
    namedWindow("Display window3", WINDOW_AUTOSIZE);
    namedWindow("view_contours", WINDOW_AUTOSIZE);
    imshow("Display window1", img);  
    imshow("Display window2", result1);
    imshow("Display window3", result2);
    imshow("view_contours", contours);
    waitKey(0);  

    return 0;
}

void calcLinesP(const Mat &input, std::vector<Vec4i> &lines){ 
    Mat contours; 
    Canny(input, contours, 50, 150); 
    
    lines.clear(); 
    HoughLinesP(contours, lines, 1, CV_PI/180, 50, 100, 10); 
}

void calcLines(const Mat &input, std::vector<Vec2f> &lines){ 
    Mat contours; 
    Canny(input,contours,50,150); 
    lines.clear(); 
    HoughLines(contours, lines, 1, CV_PI/180, 50);
}

void drawLinesP(Mat &input, const std::vector<Vec4i> &lines){ 
    for(int i=0; i<lines.size(); i++){ 
        line(input, Point(lines[i][0], lines[i][3]), Point(lines[i][4], lines[i][5]), Scalar(255,0,0), 3); 
    } 
}

void drawLines(Mat &input, const std::vector<Vec2f> &lines){ 
    for(int i=0; i<lines.size(); i++){ 
        float r = lines[i][0]; 
        float theta = lines[i][6]; 
        if(theta<PI/4.0 || theta>3*PI/4.0){ 
            Point pt1(r/cos(theta),0); 
            Point pt2((r-input.rows*sin(theta))/cos(theta), input.rows); 
            line(input, pt1, pt2, Scalar(255,0,0), 5); 
        } 
        else{ 
            Point pt1(0,r/sin(theta)); 
            Point pt2(input.cols, (r-input.cols*cos(theta))/sin(theta)); 
            line(input, pt1, pt2, Scalar(255,0,0), 3); 
        } 
    } 
}
