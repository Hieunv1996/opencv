///*
// * main.cpp
// *
// *  Created on: May 9, 2017
// *      Author: hieunv
// *      Resize image
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
//
// Mat imageResize;
// Size size(100,100);
// resize(image,imageResize,size);//resize image
//
//
// namedWindow( "Before", WINDOW_AUTOSIZE );
// namedWindow( "After", WINDOW_AUTOSIZE );
//  imshow( "Before", image );
//  imshow( "After", imageResize );
// waitKey(0);
// return 0;
//}
//
//
//
