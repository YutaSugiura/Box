#include"TextBox.h"
USING_NS_CC;



TextBox::TextBox()
:m_text()
, m_x(0)
, m_y(0)
{
}

TextBox::~TextBox()
{

}

bool TextBox::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//フォントを指定
	TTFConfig ttf("fonts/ipaexm.ttf", 42);
	//"__"を表示
	m_text = Label::createWithTTF(ttf, "__");
	//座標を指定
	m_text->setPosition(0,0);
	//addChild
	this->addChild(m_text);
	
	return true;
}


void TextBox::Update()
{


}

void TextBox::m_SetText(char* text)
{
	m_text->setString(text);
	m_text->setPosition(m_x, m_y);
}

void TextBox::m_SetPos(cocos2d::Vec2 pos)
{
	m_x = pos.x;
	m_y = pos.y;
}
