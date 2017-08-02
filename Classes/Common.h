#pragma once
#ifndef __COMMON_H__
#define __COMMON_H__

USING_NS_CC;

#define SCREEN_SIZE CCDirector::sharedDirector()->getWinSize()


enum Level
{
	Level_one=1,
	Level_Two,
	Level_Three,
	Level_Endless,
};

#define Velocity_Base 4.0f

#define Velocity_Monster_Base 1.0f

//char* StrToUTF8(const char* font) {
//	int len = MultiByteToWideChar(CP_ACP, 0, font, -1, NULL, 0);
//	wchar_t *wstr = new wchar_t[len + 1];
//	memset(wstr, 0, len + 1);
//	MultiByteToWideChar(CP_ACP, 0, font, -1, wstr, len);
//	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
//	char *str = new char[len + 1];
//	memset(str, 0, len + 1);
//	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
//	if (wstr)delete[] wstr;
//	return str;
//}

#endif // !__COMMON_H__

