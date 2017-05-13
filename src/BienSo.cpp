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
	resize(image, image, Size(160, 120));
}

Mat BienSo::img2Gray() {
	Mat img = getImage().clone();
	Mat gray;

//	GaussianBlur( img, img, Size( 3, 3 ), 0, 0 );
	cvtColor(img, gray, CV_BGR2GRAY);
	normalize(gray, gray, 0, 255, NORM_MINMAX, CV_8UC1);
	blur(gray, gray, Size(3, 3));
	return gray;
}

Mat BienSo::img2Binary(Mat grayImg) {
	int T = 150;
	Mat binary;
//	threshold(grayImg, binary, T, 255, CV_THRESH_BINARY);
	adaptiveThreshold(grayImg, binary, 255, CV_ADAPTIVE_THRESH_MEAN_C,
			CV_THRESH_BINARY, 15, 7);
//	dilate(binary, binary, Mat());
//	erode(binary,binary,Mat());
	return binary;
}

Mat BienSo::findPlate(Mat binaryImg) {
	Mat canny_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	/// Detect edges using canny
	Canny(binaryImg, canny_output, 100, 100 * 2, 3);
	/// Find contours
	findContours(canny_output, contours, hierarchy, CV_RETR_TREE,
			CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	Mat rs = image.clone();
	if (contours.size() > 0) {
		for (int i = 0; i < contours.size(); ++i) {
			Rect rec = boundingRect(contours[i]);
			rectangle(rs, rec, CV_RGB(0, 255, 0), 1);

		}
	}

	Mat drawing = getImage().clone();
	for (int i = 0; i < contours.size(); i++) {
		vector<Point> item = contours[i];

		int xmin, xmax, ymin, ymax;
		int w, h;

		for (int j = 0; j < item.size(); j++) {
			if (j == 0) {
				xmin = xmax = item[j].x;
				ymin = ymax = item[j].y;
			}
			if (item[j].x > xmax)
				xmax = item[j].x;
			else if (item[j].x < xmin)
				xmin = item[j].x;

			if (item[j].y > ymax)
				ymax = item[j].y;
			else if (item[j].y < ymin)
				ymin = item[j].y;
		}
		w = xmax - xmin;
		h = ymax - ymin;
		//check is bien so xe
		if (w > 120 && h > 80 && w > h) {
//			double angle = acos((double) h / sqrt(h * h + w * w)) * 180 / 3.14;
//			cout << "angle: " << angle << endl;
//			if (angle > 54.5) {
//				rotateImg(54.5 - angle);
//			} else {
//				rotateImg(-54.5 + angle);
//			}
//			cout << "x-y: " << xmin << " " << ymin << " " << xmax << " " << ymax
//					<< endl;
			rectangle(drawing, Point(xmin, ymin), Point(xmax, ymax),
					CV_RGB(255, 0, 0), 2, 8, 0);
//			Rect rect(xmin, ymin, w, h);
//			drawing = image(rect);
		}
	}
//	return drawing;
	return rs;
}

Mat BienSo::cropImg(Mat binaryImg) {
//	Rect rect;
//	int w = 28,h = 20;
//	int c = binaryImg.cols, r = binaryImg.rows;
//	for(int i = 0;i < c - 2*w;++i){
//		for(int j = 0;j < c - 2*h;++j){
//
//		}
//	}
}

void BienSo::rotateImg(double angle) {
	angle = -angle;
	// get rotation matrix for rotating the image around its center
	cv::Point2f center(image.cols / 2.0, image.rows / 2.0);
	cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
	// determine bounding rectangle
	cv::Rect bbox = cv::RotatedRect(center, image.size(), angle).boundingRect();
	// adjust transformation matrix
	rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;

	cv::warpAffine(image, image, rot, bbox.size());
//	resize(image, image, Size(160, 120));
}

BienSo::~BienSo() {

}

