/*
 * main.cpp
 *
 *  Created on: May 11, 2017
 *      Author: hieunv
 */
#include "BienSo.h"
#include <sstream>
#include <dirent.h>
template<typename T>
std::string numberToString(T Number) {
	std::ostringstream ss;
	ss << Number;
	return ss.str();
}

bool checkExtension(string path, string ex){
	string e = "";
	for(int i = path.length()-1;i >= 0;i--){
		if(path[i] =='.') break;
		e = path[i] + e;
	}
	return ex.compare(e) == 0;
}

vector<string> getListItem(char* url) {
	vector<string> v;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(url)) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir(dir)) != NULL) {
			if(checkExtension(ent->d_name,"jpg")){
//				cout<<ent->d_name<<endl;
				v.push_back(ent->d_name);
			}
		}
		closedir(dir);
	} else {
		cout<<"could not open directory"<<endl;
		perror("");
	}
	return v;
}

int main() {
	char *url = ("/home/hieunv/Desktop/Car/");
	string rs = "/home/hieunv/Desktop/result/";
	string bi = "/home/hieunv/Desktop/binary/";
	vector<string> files = getListItem(url);
	for (int i = 0; i < files.size(); ++i) {
		Mat image = imread(url + files[i]);

		BienSo *bs = new BienSo(image);
		Mat gray = bs->img2Gray();
//		imshow("Gray", gray);
		Mat binary = bs->img2Binary(gray);
		string name = bi + files[i];
		imwrite(name, binary);
		Mat plate = bs->findPlate(gray);
		if (plate.data) {
			string name = rs + files[i];
			imwrite(name, plate);
		}else{
		}
	}

	waitKey(0);
	return 0;
}

