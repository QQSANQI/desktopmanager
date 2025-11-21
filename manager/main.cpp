#include<iostream>
#include "FileScanner.h"
#include "FileCLassifier.h"
#include "jsonconfig_loader.h"
#pragma warning(push)
#pragma warning(disable: 26819) // 屏蔽 C26819（switch 标签之间的尾随 fallthrough）
#include "json.hpp"
#pragma warning(pop)
using namespace std;

int main()
{
	cout << "文件管理器启动中..." << endl;
	FileScanner scanner("C:\\Users\\Malei\\Downloads");//路径由客户端传回
	FileCLassifier classifier;
	classifier.classFile(scanner.getAllFiles(scanner.desktopPath), "file_categories.json","C:\\Users\\Malei\\Downloads");//路径由客户端传回
	classifier.result() 
		? cout << "DONE" <<endl 
		: cout << "UNKONWN WRONG"<<endl;
	system("pause");
}