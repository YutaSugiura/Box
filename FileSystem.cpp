#include "SystemFiles\FileSystem.h"
#include "cocos2d.h"
#include "platform/CCFileUtils.h"
#include <sstream>
#include <fstream>

using namespace std;

USING_NS_CC;

// 配列 (要素数) の初期数
#define SIZEA 30	//横
#define SIZEB 9		//縦

FileSystem::FileSystem(string name)
{
	//動的に配列を確保する
	m_data = new int*[SIZEA];

	for (int i = 0; i < SIZEA; i++)
	{
		m_data[i] = new int[SIZEB];
	}
	//イメージ
	//m_data[SIZEA][SIZEB]

	//初期化しておく
	for (int i = 0; i < SIZEA; i++)
	{
		for (int j = 0; j < SIZEB; j++)
		{
			m_data[i][j] = 0;
		}
	}



	//読み込むものを一時的に入れておく
	int temp = 0;

	string filePath = cocos2d::FileUtils::sharedFileUtils()->fullPathForFilename(name);

	//文字列のサイズを格納
	ssize_t size;

	//CSVで一行読み込むもの
	string line;

	//txtファイルの読み込み（ファイルのパス, 読み込みモード,文字列サイズ）
	unsigned char* file = cocos2d::FileUtils::getInstance()->getFileData(filePath, "r", &size);

	//ファイルのパスを保存
	m_file_path = filePath;

	stringstream csvStream((char*)file);

	//一時的に読み込んだものを,区切りで入れておく
	string csvCol;

	int j = 0;
	int k = 0;
	while (getline(csvStream, line) && (j < SIZEA))
	{
		//読み込んだ1行を保存
		stringstream csvtemp((string)line);
		
		//Kを0に戻す
		k = 0;
		while (getline(csvtemp, csvCol, ',') && (k < SIZEB) )
		{
			//if ((csvCol.c_str()) == 0)
			//{
			temp = atoi(csvCol.c_str());
			m_data[j][k] = temp;
			k++;
			//}
		}

		j++;
	}

}


FileSystem::~FileSystem()
{
	for (int i = 0; i < SIZEA; i++)
	{
		delete[] m_data[i];
	}
}

int FileSystem::GetNum(int i ,int j)
{
	return m_data[i][j];
}
