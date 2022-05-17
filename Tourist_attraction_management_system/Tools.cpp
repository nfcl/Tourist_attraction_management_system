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
		GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
		CursorInfo.bVisible = IsHide; //���ؿ���̨���
		SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬
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
		mode &= ~ENABLE_QUICK_EDIT_MODE;  //�Ƴ����ٱ༭ģʽ
		mode &= ~ENABLE_INSERT_MODE;      //�Ƴ�����ģʽ
		mode &= ~ENABLE_MOUSE_INPUT;
		SetConsoleMode(hStdin, mode);

		HANDLE Hand;
		CONSOLE_SCREEN_BUFFER_INFO Info;
		Hand = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(Hand, &Info);
		SMALL_RECT rect = Info.srWindow;
		COORD size = { rect.Right + 100 ,rect.Bottom + 10 };	//���建������С�����ֻ�������С����Ļ��Сһ�¼���ȡ���߿� 
		SetConsoleScreenBufferSize(Hand, size);


		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof cfi;
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0; //�ֿ�
		cfi.dwFontSize.Y = 25;//�ָ� ʵ��Ϊ�ֿ�Ϊ0ʱ�ָ�ֱ���趨Ϊ�����С
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;//��ϸ
		wcscpy_s(cfi.FaceName, L"����"); //��������
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
	/// ����Enter�����ַ��Կ���̨��Ӱ��
	/// </summary>
	/// <param name="Tklength">��Ҫ���ַ�����</param>
	/// <param name="Rid">��ǰλ��</param>
	/// <param name="length">�ܳ���</param>
	/// <param name="TOX">��ջ���������true����գ�</param>
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
		int length = 0;		//ʵ�ʳ���
		int Rid = 0;		//��¼��ǰλ��
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
			{//������ȹ��ܼ���ǰһ����
				switch (_getwch())
				{
				case 72:
				{//��
					break;
				}
				case 80:
				{//��
					break;
				}
				case 75:
				{//��
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
				{//��
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
				{//Delete /*��Ȼ���ǰ�ascii���.....*/
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
			{//�س�
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
			{//Сд��ĸ
				tmpBuffer.insert(&tmp, InsertId);
				InsertId += 1;
				wprintf(L"\033[1@%lc", tmp);
				length += 1;
				Rid += 1;
				Tk(1, Rid, length, false);
			}
			else if (tmp >= 'A' && tmp <= 'Z' && tmpBuffer.size < Maxlength && (Mode & 0x0010) != 0)
			{//��д��ĸ
				tmpBuffer.insert(&tmp, InsertId);
				InsertId += 1;
				wprintf(L"\033[1@%lc", tmp);
				length += 1;
				Rid += 1;
				Tk(1, Rid, length, false);
			}
			else if (tmp >= '0' && tmp <= '9' && tmpBuffer.size < Maxlength && (Mode & 0x0100) != 0)
			{//����
				tmpBuffer.insert(&tmp, InsertId);
				InsertId += 1;
				wprintf(L"\033[1@%lc", tmp);
				length += 1;
				Rid += 1;
				Tk(1, Rid, length, false);
			}
			else if (tmp >= 0x4E00 && tmp <= 0x9FA5 && tmpBuffer.size < Maxlength && (Mode & 0x1000) != 0)
			{//���������ַ���Χ
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

	//����					����		˵��						��Ϊ
	//ESC[< n > A			CUU			�������					������� <n> ��
	//ESC[< n > B			CUD			�������					������� <n> ��
	//ESC[< n > C			CUF			�����ǰ					�����ǰ���ң�<n> ��
	//ESC[< n > D			CUB			������					��������<n> ��
	//ESC[< n > E			CNL			�����һ��					���ӵ�ǰλ������ <n> ��
	//ESC[< n > F			CPL			��굱ǰ��					���ӵ�ǰλ������ <n> ��
	//ESC[< n > G			CHA			���Թ��ˮƽ				����ڵ�ǰ����ˮƽ�ƶ����� <n> ��λ��
	//ESC[< n > d			VPA			���Դ�ֱ��λ��				����ڵ�ǰ���д�ֱ�ƶ����� <n> ��λ��
	//ESC[< y >; <x > H		CUP			���λ��					* ����ƶ��� < x >; <�����е� y > ���꣬���� < x > �� y > ֱ�ߵ��� <
	//ESC[< y >; <x > f		HVP			ˮƽ��ֱλ��				*����ƶ��� < x >; <�����е� y > ���꣬���� < x > �� y > ֱ�ߵ��� <
	//ESC[s					ANSISYSSC	������ - Ansi.sys ģ��	**�����κβ���������£�ִ�� save cursor �������� DECSC
	//ESC[u					ANSISYSSC	��ԭ��� - Ansi.sys ģ��	**���û�в�������ִ�л�ԭ�α�������� DECRC
}
