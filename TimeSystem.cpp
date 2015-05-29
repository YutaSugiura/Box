#include "TimeSystem.h"


TimeSystem::TimeSystem()
:m_time()
{
	
	//時刻の取得？
	time(&m_now_unix);

	//日本の時間に直す
	m_now_time = localtime(&m_now_unix);

}


TimeSystem::~TimeSystem()
{

}

//時刻の再取得
void TimeSystem::Load()
{
	//時刻の取得？
	time(&m_now_unix);

	//日本の時間に直す
	m_now_time = localtime(&m_now_unix);
}

//時刻の表示
int* TimeSystem::WhatTime()
{


	//↓のように書くとint型で年の情報がもらえます
	//nama->WhatTime()[e_YEAR]
	//↓のように書くとint型で月の情報がもらえます
	//nama->WhatTime()[e_MON]

	//***********************************************
	//使い方例
	//
	//①表示したい場合は表示用に確保
	//char text[100] = { 0 };
	//②itoaを使いintをchar*に変換
	//itoa(nama->WhatTime()[e_YEAR], text, 10);
	//③前もって作っておいたもので表示（この場合TextBoxクラスを使用）
	//tb->SetText(text);
	////
	//
	//***********************************************

	m_time[e_YEAR] = 1900 + (m_now_time->tm_year);
	m_time[e_MON] = 1 + m_now_time->tm_mon;
	m_time[e_DAY] = m_now_time->tm_mday;
	m_time[e_HOUR] = m_now_time->tm_hour;
	m_time[e_MIN] = m_now_time->tm_min;
	m_time[e_SEC] = m_now_time->tm_sec;
	m_time[e_WEEK] = m_now_time->tm_wday;
	m_time[e_TOTAL_DAY] = m_now_time->tm_yday;
	m_time[e_SUMMER_TIME] = m_now_time->tm_isdst;

	return m_time;
}
