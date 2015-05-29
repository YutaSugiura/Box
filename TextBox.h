#pragma once
#include "cocos2d.h"
#pragma execution_character_set("utf-8")
class TextBox :public  cocos2d::Layer
{
private:

	cocos2d::Label* m_text;


public:


	//コンストラクタ
	TextBox();

	//デストラクタ
	~TextBox();

	//生成と初期化
	bool init();

	void Update();

	void SetText(char* text);

	CREATE_FUNC(TextBox);

};
