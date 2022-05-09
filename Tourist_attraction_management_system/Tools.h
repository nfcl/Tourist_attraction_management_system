#ifndef _TOOLS_h
#define _TOOLS_h

#include "Global.h"

namespace Tools
{
	/// <summary>
	/// <para/>字符串转整形
	/// <para/>如果存在不合法字符返回到不合法字符前的合法数字
	/// </summary>
	/// <param name="GoalChars">要转换的字符串</param>
	/// <param name="length">要转换的字符串长度</param>
	/// <returns></returns>
	int CharToInt(char* GoalChars, int length);

	/// <summary>
	/// 返回两个整形的较大值
	/// </summary>
	/// <param name="a">整形a</param>
	/// <param name="b">整形b</param>
	/// <returns></returns>
	int Max(int a, int b);

	/// <summary>
	/// 返回两个整形的较小值
	/// </summary>
	/// <param name="a">整形a</param>
	/// <param name="b">整形b</param>
	/// <returns></returns>
	int Min(int a, int b);

	/// <summary>
	/// 隐藏控制台光标
	/// </summary>
	/// <param name="IsHide">True为显示 False为隐藏</param>
	void HideCursor(bool IsHide);

	/// <summary>
	/// 移动控制光标至x,y
	/// </summary>
	/// <param name="x">列坐标</param>
	/// <param name="y">行坐标</param>
	void ConsoleCursorGotoXY(int x, int y);

	/// <summary>
	/// 获得控制台光标位置
	/// </summary>
	/// <returns>COORD结构体包括列坐标X和行坐标Y</returns>
	COORD GetConsoleCursorPosition();

	/// <summary>
	/// 读取键盘信息返回虚拟键值
	/// </summary>
	/// <returns>int(1~254)</returns>
	int ReadKeyboard();

	/// <summary>
	/// 全屏
	/// </summary>
	void full_screen();

	/// <summary>
	/// 设置背景色
	/// </summary>
	/// <param name="background"></param>
	void SetBackGround(Color background);

	/// <summary>
	/// 设置前景色
	/// </summary>
	/// <param name="forgeground"></param>
	void SetForgeGround(Color forgeground);

	/// <summary>
	/// 设置前景色和背景色
	/// </summary>
	/// <param name="forgeground"></param>
	/// <param name="background"></param>
	void SetBothGround(Color forgeground, Color background);
	/// <summary>
	/// char*转wchar_t*
	/// </summary>
	/// <param name="wcharStr"></param>
	/// <param name="charStr"></param>
	/// <returns></returns>
	int Char2Wchar(wchar_t* wcharStr, const char* charStr);

	/// <summary>
	/// 输入事件读取
	/// </summary>
	/// <returns></returns>
	INPUT_RECORD EventInput();

	/// <summary>
	/// <para/>模拟键盘输入
	/// <para/>有效输入支持：
	/// <para/>中文				（unicode"基本汉字"(0x4E00-0x9FA5)）
	/// <para/>数字				（ascii '0' - '9'）
	/// <para/>大小写字母		（ascii 'A' - 'Z' 'a' - 'z'）
	/// <para/>功能键支持：
	/// <para/>Backspace		（ascii 8）
	/// <para/>Delete			（ascii多字符 224 83）
	/// <para/>上下左右			（ascii多字符 224 (72|80|75|77)）
	/// </summary>
	/// <param name="Maxlength">最大输入长度</param>
	/// <param name="BreakValue">打断按键值</param>
	/// <param name="Mode">输入模式从低位到高位分别为小写字母，大写字母，数字，中文</param>
	/// <returns>返回一个wchar_t的Vector</returns>
	void Enter(Vector& tmpBuffer, int Maxlength, int Mode = 0x1111, int BreakValue = 13);

	int Wchar2Char(char* charStr, const wchar_t* wcharStr);
}
#endif // !_TOOLS_h