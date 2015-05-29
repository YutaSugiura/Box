/////////////////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
#pragma once

#include<iostream> 

class FileSystem
{
private:
	

	int m_end_flag;

	//読み込んだデータ
	int** m_data;
	
	//読み込んだファイルのパス
	std::string m_file_path;



public:

	//読み込むファイルの名前
	FileSystem(std::string name);

	//読み込むファイルの名前＋読み込む行数
	//FileSystem(const char* name,int numLine);

	~FileSystem();
	
	//その行数のデータを貰う
	int GetNum(int i,int j);


};
