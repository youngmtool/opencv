// =======================================================================
// 1. Drawing
// =======================================================================
// 1. point, line, polyline, circle, ...
// 1. text out on image
// 1. drawContours (contours)

// =======================================================================
// 1. Mouse event
// =======================================================================
// 1. Basic event
// 1. Application

// =======================================================================
// 1. Control
// =======================================================================
// 1. Slide bar


// =======================================================================
// Codes
// =======================================================================

// http://cvlecture.marearts.com/2016/12/opencv-lecture-3-3_23.html

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int, char)
{
    // c img : Mat type, (500,500) matrix
    Mat img(500, 500, CV_8UC3);
    // White color
    img.setTo(255);

    // =======================================================================
    // line example
    // =======================================================================
    // c pt: ending point
    cv::Point pt(300, 300);
    
    // starting point
    // ending point
    // line color
    // ine thickness
    line(img, Point(10, 10), pt, CV_RGB(255, 0, 0), 2);

    // You can use Scalar as color valur, other is bgr
    line(img, Point(300, 10), Point(30,300), Scalar(255, 0, 0), 2);

    // img 2018-05-20 09-03-05.png     
    
    // =======================================================================
    // Circle example
    // =======================================================================
    // Point(250, 250) : centroid point of circle
    // 100 : radius of circle
    // CV_RGB(0, 255, 0) : color of circle line
    // 3 : thickness of circle line
    circle(img, Point(250, 250), 100, CV_RGB(0, 255, 0), 3); 
    cv::Point center(400, 400);
    circle(img, center, 300, Scalar(255,255,0), 10);
    // -1 : fill color in circle
    circle(img, Point(40,40), 10, Scalar(255, 0, 0), -1);
    
    // img 2018-05-20 09-06-48.png
   
    // =======================================================================
    // rectangle example
    // =======================================================================
    // c img : Mat type variable
    // 10, 10 : x,y coordinates
    // 200, 200 : width and height
    // CV_RGB(255, 0, 0) : color of rectangle line
    // 2 : thickness of rectangle line
    rectangle(img, Rect(10, 10, 200, 200), CV_RGB(255, 0, 0), 2);

    // Point(40, 40) : starting point
    // Point(400, 400) : width and height
    rectangle(img, Rect(Point(40, 40), Point(400, 400)), Scalar(255, 0, 0), 10);
 
    // =======================================================================
    // ellipse example 1
    // =======================================================================
    // img : Mat type variable
    // Point(100, 100) : centroid point of ellipse
    // Size(100, 50) : long axis and short axis
    // 0 : rotation angle
    // 0 : starting angle
    // 360 : ending angle (full ellpise)
    // CV_RGB(255, 0, 0) : color
    ellipse(img, Point(100, 100), Size(100, 50), 0, 0, 360, CV_RGB(255, 0, 0));
    ellipse(img, Point(100, 100), Size(100, 50), 30, 0, 360, CV_RGB(0, 255, 0)); 
    ellipse(img, Point(100, 100), Size(100, 50), 60, 0, 360, CV_RGB(0, 0, 255));

    ellipse(img, Point(300, 300), Size(100, 50), 0, 0, 180, CV_RGB(255, 0, 0));
    ellipse(img, Point(300, 300), Size(100, 50), 30, 0, 270, CV_RGB(0, 255, 0));
    ellipse(img, Point(300, 300), Size(100, 50), 60, 0, 360, CV_RGB(0, 0, 255));

    // =======================================================================
    // ellipse example 2
    // =======================================================================
    
    // RotatedRect() is used to rotate rectangle
    // Point2f(300, 300) : centroid point of rectangle
    // Size2f(300, 100) : width and height
    // 30 : rotation angle
    RotatedRect rRect = RotatedRect(Point2f(300, 300), Size2f(300, 100), 30);
    // You input rotated rectangle (rRect) into ellipse()
    ellipse(img, rRect, CV_RGB(255, 0, 0));
    
    // You draw rect and inside rect in RotatedRect
    // c vertices : Point2f type variable, 4 spaces array
    Point2f vertices[4];
    rRect.points(vertices);
    for (int i = 0; i <  4; i++)
        line(img, vertices[i], vertices[(i + 1) % 4], Scalar(0, 255, 0));
            Rect brect = rRect.boundingRect();
    rectangle(img, brect, Scalar(255, 0, 0));
    
    // =======================================================================
    // polylines example 1 
    // =======================================================================
    
    // c contour : Point stucture with vector type
    vector< Point> contour;
    contour.push_back(Point(50, 50));
    contour.push_back(Point(300, 50));
    contour.push_back(Point(350, 200));
    contour.push_back(Point(300, 150));
    contour.push_back(Point(150, 350));
    contour.push_back(Point(100, 100));

    // You cast coutour (vector) as May type,
    // then you get address of data,
    // then you cast address of data as Point type address,
    // then you assign Point type address into pts
    const Point *pts = (const cv::Point*) Mat(contour).data;
    int npts = Mat(contour).rows;

    std::cout <<  "Number of polygon vertices: " <<  npts <<  std::endl;
    // You draw the polygon by passing &pts
    // &npts : number of points
    // 1 : number of poly line
    polylines(img, &pts, &npts, 1, false, Scalar(0, 255, 0));

    // =======================================================================
    // polylines example 2 
    // =======================================================================
    
    // You clear all value in contour
    contour.clear();
    // You push back 3 points
    contour.push_back(Point(400, 400));
    contour.push_back(Point(250, 250));
    contour.push_back(Point(50, 300));

    pts = (const cv::Point*) Mat(contour).data;
    npts = Mat(contour).rows;
    polylines(img, &pts, &npts, 1, true, Scalar(255, 0, 0));

    // =======================================================================
    // polylines example 3 by using for loop
    // =======================================================================

    vector< Point> contour;
    contour.push_back(Point(50, 50));
    contour.push_back(Point(300, 50));
    contour.push_back(Point(350, 200));
    contour.push_back(Point(300, 150));
    contour.push_back(Point(150, 350));
    contour.push_back(Point(100, 100));

    // You draw polyline with for loop
    for (int i=0;i<contour.size()-1;++i)
        line(img,contour[i],contour[i+1],CV_RGB(255,0,0),2);
    line(img,contour[contour.size()-2],contour[contour.size()-1],CV_RGB(255,0,0),2);

    // =======================================================================
    // fillConvexPoly example 1 
    // =======================================================================
    // c ptss : Point type array (4 spaces)
    cv::Point ptss[4]; 
    ptss[0] = cv::Point(100, 100);
    ptss[1] = cv::Point(150, 200);
    ptss[2] = cv::Point(300, 300);
    ptss[3] = cv::Point(400, 100);
    // img : Mat type variable
    // 4 : number of units
    cv::fillConvexPoly(img, ptss, 4, cv::Scalar(0, 0, 200));

    // =======================================================================
    // textout example 1
    // =======================================================================
    
    // You can add text onto image
    char TestStr[100];
    sprintf(TestStr, "total time : %lf sec", 0.001);
    // TestStr : string
    // Point(10, 250) : x,y coordinates starting string
    // 1 : value of scale
    // Scalar(0, 0, 0) : size of font
    // 1 : thinkness of font
    // 1 : type of font (line, dot, ...)
    putText(img, TestStr, Point(10, 250), CV_FONT_NORMAL, 1, Scalar(0, 0, 0), 1, 1); //OutImg is Mat class;

    imshow("show0", img);
 
    // =======================================================================
    // drawContour example1
    // =======================================================================
    
    // This draws multiple polygons, which is convinient when drawing contour

    // You create 3 named empty windows
    namedWindow("show1",0);
    namedWindow("threshhold",0);
    namedWindow("contours",0);

    Mat img;
    img=imread("pattern.jpg");
    cvtColor(img, img, CV_RGB2GRAY);
    imshow("show1",img);

    // criterion : 128
    // based on 128, value is either 255 or 0
    // CV_THRESH_BINARY : option is binary
    threshold(img,img,128,255,CV_THRESH_BINARY);
    imshow("threshhold",img);

    // img.setTo(0);
    rectangle(img, Rect(10, 10, 200, 200), CV_RGB(255, 255, 255), CV_FILLED );
    imshow("show1", img);

    Mat dst = Mat::zeros(img.rows, img.cols, CV_8UC3);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    // You can assume there exist muliple chunks on binary image
    // findContours() selects those chunks and creates contours of them,
    // then findContours() assigns those contours into contours variable
    findContours(img, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);

    // You iterate through all the top-level contours,
    // draw each connected component with its own random color
    int idx = 0;
    for (; idx >= 0; idx = hierarchy[idx][0])
    {
        Scalar color(rand() & 255, rand() & 255, rand() & 255);
        // drawContours(dst, contours, idx, color, FILLED, 8, hierarchy);
        drawContours(dst, contours, idx, color, 1, 8, hierarchy);
    }

    imshow("show2", dst);
    waitKey(0);

    return 0;
}
