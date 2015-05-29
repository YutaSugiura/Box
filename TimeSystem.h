/////////////////////////////////////////////////////////////////////////////////////
//
//注意
//
//このクラスを使用する際は
//クラスを作成した際（コンストラクタが呼び出された時）と
//Load()を読んだ時の時刻を取得します
//表示や時間の情報が欲しい場合はWhatTime()で情報を貰えます（配列に情報が順番に入っています）
//
//プログラムの組み方によっては一度Load()を呼ばないと予期せぬエラーが起こる可能性があります
//
#pragma once

#include<iostream> 
#include<time.h>
class TimeSystem
{
private:
	
	//現在のUNIX時間
	time_t m_now_unix;

	int m_time[9];

	

	//現在の時刻
	tm* m_now_time;



public:

	TimeSystem();
	~TimeSystem();

	//時刻の再取得
	void Load();
	//時刻の表示
	int* WhatTime();

};



enum TIME_SYSTEM
{
	e_YEAR,
	e_MON,
	e_DAY,
	e_HOUR,
	e_MIN,
	e_SEC,
	e_WEEK,
	e_TOTAL_DAY,
	e_SUMMER_TIME
};
