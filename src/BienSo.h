/*
 * BienSo.h
 *
 *  Created on: May 11, 2017
 *      Author: hieunv
 */

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <math.h>
using namespace cv;
using namespace std;

#ifndef BIENSO_H_
#define BIENSO_H_


class BienSo {
private:
	Mat image;
public:
	Mat getImage(){
		return image;
	}
	void setImage(Mat img){
		this->image = img;
		resize(image,image,Size(160,120));
	}
	BienSo();
	BienSo(Mat img);
	virtual ~BienSo();
	Mat img2Gray();
	Mat img2Binary(Mat grayImg);
	Mat findPlate(Mat binaryImg); //rotate img
	void rotateImg(double);
	Mat cropImg(Mat binaryImg); // crop after rotate
};

#endif /* BIENSO_H_ */
