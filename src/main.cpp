/*
 * main.cpp
 *
 *  Created on: May 11, 2017
 *      Author: hieunv
 */
#include "BienSo.h"

int main(){
	Mat image = imread("/home/hieunv/Desktop/Car/plate_1972.0(810,350).jpg");

	BienSo *bs = new BienSo(image);

	imshow("Image",bs->getImage());

	Mat gray = bs->img2Gray();

	Mat binary = bs->img2Binary(gray);

	bs->findPlate(binary);

	imshow("Rotate",bs->getImage());

	binary = bs->img2Gray();

	binary = bs->img2Binary(binary);

	imshow("Binary",binary);

	Mat result = bs->cropImg(binary);

	imshow("Result",result);

	waitKey(0);
	return 0;
}



