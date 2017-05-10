///*
// * main.cpp
// *
// *  Created on: May 9, 2017
// *      Author: hieunv
// *      Convert RGB image to gray image, show and save image on disk
// */
//#include <opencv2/opencv.hpp>
//#include <iostream>
//using namespace cv;
//using namespace std;
//
//int main( int argc, char** argv )
//{
//
// string imageName = "/home/hieunv/workspace/OpenCV/imgs/1.jpg";
// Mat image;
// image = imread( imageName, 1 );
// if(!image.data )
// {
//   printf( " No image data \n " );
//   return -1;
// }
// Mat gray_image;
// cvtColor( image, gray_image, COLOR_BGR2GRAY );
// imwrite( "/home/hieunv/workspace/OpenCV/imgs/gray.jpg", gray_image );
// namedWindow( imageName, WINDOW_AUTOSIZE );
// namedWindow( "Gray image", WINDOW_AUTOSIZE );
// imshow( imageName, image );
// imshow( "Gray image", gray_image );
// waitKey(0);
// return 0;
//}
//
//
//
