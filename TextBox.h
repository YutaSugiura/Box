#pragma once
#include "cocos2d.h"
#pragma execution_character_set("utf-8")
class TextBox :public  cocos2d::Layer
{
private:

	cocos2d::Label* m_text;
	int m_x;
	int m_y;

public:


	//コンストラクタ
	TextBox();

	//デストラクタ
	~TextBox();

	//生成と初期化
	bool init();

	void Update();
	
	//表示したいテキストを入れる
	void m_SetText(char* text);
	
	//表示座標を指定
	void m_SetPos(cocos2d::Vec2 pos);
	CREATE_FUNC(TextBox);

};
