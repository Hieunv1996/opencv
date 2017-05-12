/*
 * BienSo.cpp
 *
 *  Created on: May 11, 2017
 *      Author: hieunv
 */

#include "BienSo.h"

BienSo::BienSo() {

}

BienSo::BienSo(Mat img) {
	this->image = img;
	resize(image,image,Size(160,120));
}

Mat BienSo::img2Gray(){
	Mat img = getImage().clone();
	Mat gray;
	cvtColor(img,gray,CV_BGR2GRAY);
	normalize(gray, gray, 0, 255, NORM_MINMAX, CV_8UC1);
//	blur( gray, gray, Size(3,3) );
	return gray;
}

Mat BienSo::img2Binary(Mat grayImg){
	int T = 125;
	Mat binary;
	threshold(grayImg, binary, T, 255, CV_THRESH_BINARY);
//	adaptiveThreshold(grayImg, binary, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 9, 0);
	dilate(binary, binary, Mat(), Point(-1, -1), 3, 1, 1);
	return binary;
}

Mat BienSo::findPlate(Mat binaryImg){
	RNG rng(12345);
	Mat canny_output;
	  vector<vector<Point> > contours;
	  vector<Vec4i> hierarchy;

	  /// Detect edges using canny
	  Canny( binaryImg, canny_output, 100, 100*2, 3 );
	  /// Find contours
	  findContours( canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

	  //rotate image


	  // Draw contours
	  Mat drawing;

	  for( int i = 0; i< contours.size(); i++ )
	     {
		  	  vector<Point> item = contours[i];

		  	  int xmin,xmax,ymin,ymax;
		  	  int w,h;

		  	  for(int j = 0;j < item.size();j++){
		  		  if(j == 0){
		  			  xmin = xmax = item[j].x;
		  			  ymin = ymax = item[j].y;
		  		  }
		  		  if(item[j].x > xmax) xmax = item[j].x;
		  		  else if(item[j].x < xmin) xmin = item[j].x;

				  if(item[j].y > ymax) ymax = item[j].y;
				  else if(item[j].y < ymin) ymin = item[j].y;
		  	  }
		  	  w = xmax - xmin;
		  	  h = ymax - ymin;
		  	  //check is bien so xe
		  	  if(w > h && h > 60){
		  		double angle = acos((double)h/sqrt(h*h+w*w))*180/3.14;
		  		cout<<"angle: "<<angle<<endl;
		  		if(angle > 54.5){
		  			rotateImg(54.5 - angle);
		  		}else{
		  			rotateImg(-54.5 + angle);
		  		}
//		  		drawing  = image.clone();
//		  		rectangle(drawing,Point(xmin,ymin), Point(xmax,ymax),CV_RGB(255,0,0),2,8,0);
		  	  }
	     }
	  return drawing;
}

Mat BienSo::cropImg(Mat binaryImg){
	RNG rng(12345);
	Mat canny_output;
	  vector<vector<Point> > contours;
	  vector<Vec4i> hierarchy;

	  /// Detect edges using canny
	  Canny( binaryImg, canny_output, 100, 100*2, 3 );
	  /// Find contours
	  findContours( canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

	  //rotate image


	  // Draw contours
	  Mat drawing;

	  for( int i = 0; i< contours.size(); i++ )
	     {
		  	  vector<Point> item = contours[i];

		  	  int xmin,xmax,ymin,ymax;
		  	  int w,h;

		  	  for(int j = 0;j < item.size();j++){
		  		  if(j == 0){
		  			  xmin = xmax = item[j].x;
		  			  ymin = ymax = item[j].y;
		  		  }
		  		  if(item[j].x > xmax) xmax = item[j].x;
		  		  else if(item[j].x < xmin) xmin = item[j].x;

				  if(item[j].y > ymax) ymax = item[j].y;
				  else if(item[j].y < ymin) ymin = item[j].y;
		  	  }
		  	  w = xmax - xmin;
		  	  h = ymax - ymin;
		  	  //check is bien so xe
		  	  if(w > h && h > 60){
		  		drawing  = image.clone();
		  		Rect rect(xmin,ymin,w,h);
		  		drawing = image(rect);
		  	  }
	     }
	  return drawing;
}

void BienSo::rotateImg(double angle){
	angle = -angle;
	// get rotation matrix for rotating the image around its center
	    cv::Point2f center(image.cols/2.0, image.rows/2.0);
	    cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
	    // determine bounding rectangle
	    cv::Rect bbox = cv::RotatedRect(center,image.size(), angle).boundingRect();
	    // adjust transformation matrix
	    rot.at<double>(0,2) += bbox.width/2.0 - center.x;
	    rot.at<double>(1,2) += bbox.height/2.0 - center.y;

	    cv::warpAffine(image, image, rot, bbox.size());
}

BienSo::~BienSo() {

}

