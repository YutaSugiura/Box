#include"TextBox.h"
USING_NS_CC;



TextBox::TextBox()
:m_text()
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
	
	this->addChild(m_text);



	return true;
}


void TextBox::Update()
{


}

void TextBox::SetText(char* text)
{
	removeAllChildren();
	//フォントを指定
	TTFConfig ttf("fonts/ipaexm.ttf", 42);
	//表示
	m_text = Label::createWithTTF(ttf, text);
	//表示する座標の設定
	m_text->setPosition(Vec2(250, 390));
	this->addChild(m_text);
}
