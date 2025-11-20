#include<iostream>
#include "FileScanner.h"
#include "FileCLassifier.h"
#include "jsonconfig_loader.h"
#include "json.hpp"
using namespace std;

int main()
{
	cout << "文件管理器启动中..." << endl;
	FileScanner scanner("C:\\Users\\Malei\\Downloads");//路径由客户端传回
	FileCLassifier classifier;
	classifier.classFile(scanner.getAllFiles(scanner.desktopPath), "config/file_categories.json");//路径由客户端传回
	classifier.result() ? cout << "DONE" :cout<<"UNKONWN WRONG";
	system("pause");
}