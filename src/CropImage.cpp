///*
// * FaceDetect.cpp
// *
// *  Created on: May 10, 2017
// *      Author: hieunv
// */
//
//
//
//
//
//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <vector>
//using namespace cv;
//using namespace std;
//#include <dirent.h>
//
//string getExtension(string);
//vector<string> getListImage(string,string );
//Mat image2Gray(Mat);
//int main()
//{
//	string path = "/home/hieunv/Desktop/Car";
//	vector<string> lst = getListImage(path,".jpg");
//	Mat rgb,gray;
////	for(int i = 0;i < lst.size();i++){
////	int i = 0;
//	rgb = imread("/home/hieunv/Desktop/1.jpg");
//		gray = image2Gray(rgb);
//		namedWindow("show",WINDOW_AUTOSIZE);
//		imshow("show",gray);
//		waitKey(0);
//		return 0;
////	}
//}
//
//
//
//vector<string> getListImage(string path,string format){
//	vector<string> lst;
//	DIR *dir;
//		struct dirent *ent;
//		if ((dir = opendir (path.c_str())) != NULL) {
//		  /* print all the files and directories within directory */
//		  while ((ent = readdir (dir)) != NULL) {
//		    string name = ent->d_name;
//			  if(getExtension(name).compare(format) == 0){
//		    	lst.push_back(path+ "/" + name);
//		    }
//		  }
//		  closedir (dir);
//		} else {
//		  /* could not open directory */\
//		  cout<<"Could not open directory!";
//		  return lst;
//		}
//		return lst;
//}
//
//
//string getExtension(string s){
//	string ans = "";
//	for(int i = s.length() - 1;i >= 0;i--){
//		if(s[i] != '.'){
//			ans = s[i] + ans;
//		}else{
//			break;
//		}
//	}
//	return "." + ans;
//}
//
//Mat image2Gray(Mat image){
//	Mat gray;
////	resize(image,gray,Size(),3,3,INTER_NEAREST);
//	cvtColor(image,gray,CV_RGB2GRAY);
//	return gray;
//}
//
