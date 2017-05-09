///*
// * ImagePixel.cpp
// *
// *  Created on: May 9, 2017
// *      Author: hieunv
// *      Get pixel with color in this pixel not equals 0
// */
//
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
// int c = image.cols;
// int r = image.rows;
//
// for(int i = 0;i < r;i++){
//	 for(int j = 0;j < c;j++){
//		 Vec3b vec = image.at<Vec3b>(i, j);
//		 if(vec[0] != 0 || vec[1] != 0 || vec[2] != 0){
//			 cout<<"Point("<<i<<", "<<j<<") = "<<vec<<endl;
//		 }
//	 }
// }
//
// namedWindow( imageName, WINDOW_AUTOSIZE );
// imshow( imageName, image );
// waitKey(0);
// return 0;
//}
