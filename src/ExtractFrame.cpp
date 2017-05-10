///*
// * ExtractFrame.cpp
// *
// *  Created on: May 10, 2017
// *      Author: hieunv
// */
//
//
//
//
//#include <opencv2/opencv.hpp>
//#include<opencv/highgui.h>
//#include<opencv/ml.h>
//#include<opencv/cxcore.h>
//#include<fstream>
//
//
//
//int main( int argc, char** argv ) {
//cvNamedWindow( "DisplayVideo", CV_WINDOW_AUTOSIZE );
//CvCapture* capture = cvCreateFileCapture( "/home/hieunv/Desktop/1.mp4" );
//IplImage* frame;
//int num=0;
//char s [20];
//while(1) {
//num++;
//frame = cvQueryFrame( capture );
//if( !frame ) break;
//cvShowImage( "DisplayVideo", frame );
//char c = cvWaitKey(33);
//if( c == 27 ) break;
//sprintf(s,"imgs/frame%d.jpg",num);
//cvSaveImage(s,frame);
//}
//cvReleaseCapture( &capture );
//cvDestroyWindow("DisplayVideo" );
//}
