#include "Global.h"

namespace Tools
{
	int CharToInt(char* GoalChars, int length)
	{
		int result = 0;
		for (int i = 0; i < length; ++i)
		{
			result *= 10;
			result += GoalChars[i] - '0';
		}
		return result;
	}

	int Max(int a, int b)
	{
		return a > b ? a : b;
	}

	int Min(int a, int b)
	{
		return a < b ? a : b;
	}

	void HideCursor(bool IsHide)
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO CursorInfo;
		GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
		CursorInfo.bVisible = IsHide; //隐藏控制台光标
		SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
	}

	void ConsoleCursorGotoXY(int x, int y)
	{
		COORD pos;
		pos.X = x;
		pos.Y = y;
		HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hout, &csbi);
		SetConsoleCursorPosition(hout, pos);
	}

	COORD GetConsoleCursorPosition()
	{
		HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO bInfo;
		GetConsoleScreenBufferInfo(hout, &bInfo);
		return bInfo.dwCursorPosition;
	}

	void SetBackGround(Color background)
	{
		printf("\033[48;2;%d;%d;%dm", background.R, background.G, background.B);
	}

	void SetForgeGround(Color forgeground)
	{
		printf("\033[38;2;%d;%d;%dm", forgeground.R, forgeground.G, forgeground.B);
	}

	void SetBothGround(Color forgeground, Color background)
	{
		printf("\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm", forgeground.R, forgeground.G, forgeground.B, background.R, background.G, background.B);
	}

	int ReadKeyboard()
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

		DWORD			dwRes;
		INPUT_RECORD	keyRec;

		ReadConsoleInput(hIn, &keyRec, 1, &dwRes);
		if ((bool)keyRec.Event.KeyEvent.bKeyDown == true)
			return keyRec.Event.KeyEvent.wVirtualKeyCode;
		return 0;
	}

	int Char2Wchar(wchar_t* wcharStr, const char* charStr)
	{
		int len = MultiByteToWideChar(CP_ACP, 0, charStr, strlen(charStr), NULL, 0);

		MultiByteToWideChar(CP_ACP, 0, charStr, strlen(charStr), wcharStr, len);
		wcharStr[len] = '\0';
		return len;
	}
	
	int Wchar2Char(char* charStr, const wchar_t* wcharStr) 
	{
		int len = WideCharToMultiByte(CP_ACP, 0, wcharStr, wcslen(wcharStr), NULL, 0, NULL, NULL);
		WideCharToMultiByte(CP_ACP, 0, wcharStr, wcslen(wcharStr), charStr, len, NULL, NULL);
		charStr[len] = '\0';
		return len;
	}

	void full_screen()
	{
		HWND hwnd = GetForegroundWindow();
		int cx = GetSystemMetrics(SM_CXSCREEN);
		int cy = GetSystemMetrics(SM_CYSCREEN);
		LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);
		SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
		SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0); 
		
		HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
		DWORD mode;
		GetConsoleMode(hStdin, &mode);
		mode &= ~ENABLE_QUICK_EDIT_MODE;  //移除快速编辑模式
		mode &= ~ENABLE_INSERT_MODE;      //移除插入模式
		mode &= ~ENABLE_MOUSE_INPUT;
		SetConsoleMode(hStdin, mode);

		HANDLE Hand;
		CONSOLE_SCREEN_BUFFER_INFO Info;
		Hand = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(Hand, &Info);
		SMALL_RECT rect = Info.srWindow;
		COORD size = { rect.Right + 100 ,rect.Bottom + 10 };	//定义缓冲区大小，保持缓冲区大小和屏幕大小一致即可取消边框 
		SetConsoleScreenBufferSize(Hand, size);


		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof cfi;
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0; //字宽
		cfi.dwFontSize.Y = 25;//字高 实际为字宽为0时字高直接设定为字体大小
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;//粗细
		wcscpy_s(cfi.FaceName, L"黑体"); //设置字体
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	}

	INPUT_RECORD EventInput()
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

		INPUT_RECORD	Eventinput;
		DWORD			res;
		SetConsoleMode(hIn, ENABLE_MOUSE_INPUT);

		ReadConsoleInput(hIn, &Eventinput, 1, &res);

		return Eventinput;
	}

	/// <summary>
	/// 消除Enter插入字符对控制台的影响
	/// </summary>
	/// <param name="Tklength">需要的字符长度</param>
	/// <param name="Rid">当前位置</param>
	/// <param name="length">总长度</param>
	/// <param name="TOX">填空还是消除（true是填空）</param>
	void Tk(int Tklength, int Rid, int length, bool TOX)
	{
		if (length - Rid)
			printf("\033[%dC", length - Rid);
		if (TOX)
			printf("\033[%d@", Tklength);
		else
			printf("\033[%dP", Tklength);
		if (length - Rid)
			printf("\033[%dD", length - Rid);
	}

	void Enter(Vector &tmpBuffer,int Maxlength, int Mode, int BreakValue)
	{
		setlocale(LC_ALL, "zh_CN.UTF-8");
		printf("\033(B");
		int length = 0;		//实际长度
		int Rid = 0;		//记录当前位置
		wchar_t tmp;
		for (int i = 0; i < tmpBuffer.size; ++i)
		{
			tmpBuffer.get(&tmp, i);
			if (tmp >= 0x4E00 && tmp <= 0x9FA5)
			{
				length += 2;
				Rid += 2;
			}
			else
			{
				length += 1;
				Rid += 1;
			}
		}
		if (Rid)
			printf("\033[%dC", Rid);
		int InsertId = tmpBuffer.size;
		while (1)
		{
			tmp = _getwch();
			if (tmp == 224)
			{//方向键等功能键的前一个键
				switch (_getwch())
				{
				case 72:
				{//上
					break;
				}
				case 80:
				{//下
					break;
				}
				case 75:
				{//左
					if (InsertId)
					{
						tmpBuffer.get(&tmp, (size_t)InsertId - 1);
						if (tmp >= 0x4E00 && tmp <= 0x9FA5)
						{
							Rid -= 2;
							printf("\033[2D");
						}
						else
						{
							Rid -= 1;
							printf("\033[1D");
						}
						InsertId -= 1;
					}
					break;
				}
				case 77:
				{//右
					if (InsertId < tmpBuffer.size)
					{
						tmpBuffer.get(&tmp, InsertId);
						if (tmp >= 0x4E00 && tmp <= 0x9FA5)
						{
							Rid += 2;
							printf("\033[2C");
						}
						else
						{
							Rid += 1;
							printf("\033[1C");
						}
						InsertId += 1;
					}
					break;
				}
				case 83:
				{//Delete /*竟然不是按ascii码的.....*/
					if (InsertId < tmpBuffer.size)
					{
						tmpBuffer.get(&tmp, InsertId);
						if (tmp >= 0x4E00 && tmp <= 0x9FA5)
						{
							printf("\033[2P");
							length -= 2;
							Tk(2, Rid, length, true);
						}
						else
						{
							printf("\033[1P");
							length -= 1;
							Tk(1, Rid, length, true);

						}
						tmpBuffer.remove(InsertId);
					}
				}
				}
			}
			else if (tmp == 8)
			{//回车
				if (InsertId > 0)
				{
					tmpBuffer.get(&tmp, (size_t)InsertId - 1);
					if (tmp >= 0x4E00 && tmp <= 0x9FA5)
					{
						printf("\033[2D\033[2P");
						length -= 2;
						Rid -= 2;
						Tk(2, Rid, length, true);
					}
					else
					{
						printf("\033[1D\033[1P");
						length -= 1;
						Rid -= 1;
						Tk(1, Rid, length, true);
					}
					tmpBuffer.remove((size_t)InsertId - 1);
					InsertId -= 1;
				}
			}
			else if (tmp >= 'a' && tmp <= 'z' && tmpBuffer.size < Maxlength && (Mode & 0x0001) != 0)
			{//小写字母
				tmpBuffer.insert(&tmp, InsertId);
				InsertId += 1;
				wprintf(L"\033[1@%lc", tmp);
				length += 1;
				Rid += 1;
				Tk(1, Rid, length, false);
			}
			else if (tmp >= 'A' && tmp <= 'Z' && tmpBuffer.size < Maxlength && (Mode & 0x0010) != 0)
			{//大写字母
				tmpBuffer.insert(&tmp, InsertId);
				InsertId += 1;
				wprintf(L"\033[1@%lc", tmp);
				length += 1;
				Rid += 1;
				Tk(1, Rid, length, false);
			}
			else if (tmp >= '0' && tmp <= '9' && tmpBuffer.size < Maxlength && (Mode & 0x0100) != 0)
			{//数字
				tmpBuffer.insert(&tmp, InsertId);
				InsertId += 1;
				wprintf(L"\033[1@%lc", tmp);
				length += 1;
				Rid += 1;
				Tk(1, Rid, length, false);
			}
			else if (tmp >= 0x4E00 && tmp <= 0x9FA5 && tmpBuffer.size < Maxlength && (Mode & 0x1000) != 0)
			{//基本中文字符范围
				tmpBuffer.insert(&tmp, InsertId);
				InsertId += 1;
				wprintf(L"\033[2@%lc", tmp);
				length += 2;
				Rid += 2;
				Tk(2, Rid, length, false);
			}
			else if (tmp == BreakValue)
			{
				break;
			}
		}
	}

	//序列					代码		说明						行为
	//ESC[< n > A			CUU			光标向上					光标向上 <n> 行
	//ESC[< n > B			CUD			光标向下					光标向下 <n> 行
	//ESC[< n > C			CUF			光标向前					光标向前（右）<n> 行
	//ESC[< n > D			CUB			光标向后					光标向后（左）<n> 行
	//ESC[< n > E			CNL			光标下一行					光标从当前位置向下 <n> 行
	//ESC[< n > F			CPL			光标当前行					光标从当前位置向上 <n> 行
	//ESC[< n > G			CHA			绝对光标水平				光标在当前行中水平移动到第 <n> 个位置
	//ESC[< n > d			VPA			绝对垂直行位置				光标在当前列中垂直移动到第 <n> 个位置
	//ESC[< y >; <x > H		CUP			光标位置					* 光标移动到 < x >; <视区中的 y > 坐标，其中 < x > 是 y > 直线的列 <
	//ESC[< y >; <x > f		HVP			水平垂直位置				*光标移动到 < x >; <视区中的 y > 坐标，其中 < x > 是 y > 直线的列 <
	//ESC[s					ANSISYSSC	保存光标 - Ansi.sys 模拟	**不带任何参数的情况下，执行 save cursor 操作，如 DECSC
	//ESC[u					ANSISYSSC	还原光标 - Ansi.sys 模拟	**如果没有参数，则执行还原游标操作，如 DECRC
}
