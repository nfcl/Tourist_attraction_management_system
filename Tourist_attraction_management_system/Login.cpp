#include "Global.h"

namespace Login
{
	Charinfo LoginInfo;			//µ±Ç°³¢ÊÔµÇÂ¼µÄÕËºÅ

	enum class TipType
	{
		Enter,
		EmptyAccount,
		EmptyPassword,
		WrongAccountAndPassword,
		LoginSuccessfull
	};

	void Tips(TipType type, bool opacity);

	void Refresh()
	{
		system("cls");
		Tools::HideCursor(false);
		Tools::ConsoleCursorGotoXY(0, 0);
		Tools::SetBothGround(Colors::Black, Colors::White);
		//			  0         1         2         3         4         5         6         7         8         9         0         1       
		//			  0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567
		printf("\033(0lqqqqqwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwqqqqqk  \n");//0 0
		printf("\033(0x ·µ»Øx                                                  µÇÂ¼                                                  x ÍË³öx  \n");//1
		printf("\033(0tqqqqqvqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvqqqqqu  \n");//2
		printf("\033(0x                                                                                                                    x  \n");//3
		printf("\033(0x                                                                                                                    x  \n");//4
		printf("\033(0x                                                                                                                    x  \n");//5
		printf("\033(0x                                                                                                                    x  \n");//6
		printf("\033(0x                                                                                                                    x  \n");//7
		printf("\033(0x                                                                                                                    x  \n");//8
		printf("\033(0x                                                                                                                    x  \n");//9
		printf("\033(0x                                      l qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk                                      x  \n");//0 1
		printf("\033(0x                                      x ÕËºÅx                                x                                      x  \n");//1
		printf("\033(0x                                      m qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj                                      x  \n");//2
		printf("\033(0x                                                                                                                    x  \n");//3
		printf("\033(0x                                                                                                                    x  \n");//4
		printf("\033(0x                                      l qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk                                      x  \n");//5
		printf("\033(0x                                      x ÃÜÂëx                                x                                      x  \n");//6
		printf("\033(0x                                      m qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj                                      x  \n");//7
		printf("\033(0x                                                                                                                    x  \n");//8
		printf("\033(0x                                                                                                                    x  \n");//9
		printf("\033(0x                                                      l qqqqk                                                       x  \n");//0 2
		printf("\033(0x                                                      x µÇÂ¼x                                                       x  \n");//1
		printf("\033(0x                                                      m qqqqj                                                       x  \n");//2
		printf("\033(0x                                                                                                                    x  \n");//3
		printf("\033(0x                                                                                                                    x  \n");//4
		printf("\033(0x                                                                                                                    x  \n");//5
		printf("\033(0x                                                                                                                    x  \n");//6
		printf("\033(0x                                                                                                                    x  \n");//7
		printf("\033(0x                                                                                                                    x  \n");//8
		printf("\033(0x                                                                                                                    x  \n");//9
		printf("\033(0x                                                                                                                    x  \n");//0 3
		printf("\033(0x                                                                                                                    x  \n");//1 
		printf("\033(0x                                                                                                                    x  \n");//2
		printf("\033(0mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj  \n");//3
		Tools::ConsoleCursorGotoXY(0, 0);
	}

	//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
	//°´Å¥ÊÂ¼þÇø																																		 |
	//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª

	void EnterAccount(Button Sender)
	{
		Tips(TipType::WrongAccountAndPassword, 0);

		wchar_t buffer[16] = { '\0' };
		Vector Vbuffer;
		Vbuffer.newvector(sizeof(wchar_t));
		Tools::Char2Wchar(buffer, LoginInfo.Account);
		for (int i = 0; i < lstrlenW(buffer); ++i)
		{
			Vbuffer.push_back(&buffer[i]);
		}

		if (Vbuffer.size == 0)
			Tips(TipType::EmptyAccount, 0);

		Tools::HideCursor(true);
		Tips(TipType::Enter, 1);
		Tools::ConsoleCursorGotoXY(47, 11);
		Tools::Enter(Vbuffer, 15, 0x0111);
		Tips(TipType::Enter, 0);
		Tools::HideCursor(false);
		setlocale(LC_ALL, "C");

		for (int i = 0; i < Vbuffer.size; ++i)
		{
			Vbuffer.get(&buffer[i], i);
		}
		buffer[Vbuffer.size] = '\0';
		Tools::Wchar2Char(LoginInfo.Account, buffer);
	}

	void EnterPassword(Button Sender)
	{
		Tips(TipType::WrongAccountAndPassword, 0);

		wchar_t buffer[16] = { '\0' };
		Vector Vbuffer;
		Vbuffer.newvector(sizeof(wchar_t));
		Tools::Char2Wchar(buffer, LoginInfo.Password);
		for (int i = 0; i < lstrlenW(buffer); ++i)
		{
			Vbuffer.push_back(&buffer[i]);
		}

		if (Vbuffer.size == 0)
			Tips(TipType::EmptyPassword, 0);

		Tools::HideCursor(true);
		Tips(TipType::Enter, 1);
		Tools::ConsoleCursorGotoXY(47, 16);
		Tools::Enter(Vbuffer, 15, 0x0111);
		Tips(TipType::Enter, 0);
		Tools::HideCursor(false);
		setlocale(LC_ALL, "C");

		for (int i = 0; i < Vbuffer.size; ++i)
		{
			Vbuffer.get(&buffer[i], i);
		}
		buffer[Vbuffer.size] = '\0';
		Tools::Wchar2Char(LoginInfo.Password, buffer);
	}

	void PressLogin(Button Sender)
	{
		bool empty = false;
		if (strlen(LoginInfo.Account) == 0) { empty = true; Tips(TipType::EmptyAccount, 1); }
		if (strlen(LoginInfo.Password) == 0) { empty = true; Tips(TipType::EmptyPassword, 1); }
		if (empty) { return; }

		Charinfo tmpinfo;
		for (int i = 0; i < Charinfos.size; ++i)
		{
			Charinfos.get(&tmpinfo, i);
			if (strcmp(tmpinfo.Account, LoginInfo.Account) == 0)
			{
				if (strcmp(tmpinfo.Password, LoginInfo.Password) == 0)
				{
					CharinfoNow = tmpinfo;
					Tips(TipType::LoginSuccessfull, 1);
					Sleep(2000);
					return;
				}
			}
		}
		Tips(TipType::WrongAccountAndPassword, 1);
	}

	void PressBack(Button Sender)
	{

	}

	void Exit(Button Sender)
	{
		exit(0);
	}

	void Tips(TipType type, bool opacity)
	{
		setlocale(LC_ALL, "C");
		switch (type)
		{
		case TipType::Enter:
		{
			Tools::ConsoleCursorGotoXY(76, 1);
			Tools::SetForgeGround(Colors::Black);
			if (opacity)
				printf("\033(B°´ÏÂEnter½áÊøÊäÈë");
			else
				printf("                 ");
			break;
		}
		case TipType::EmptyAccount:
		{
			Tools::ConsoleCursorGotoXY(47, 11);
			Tools::SetForgeGround(Colors::Red);
			if (opacity)
				printf("\033(BÎ´ÌîÐ´ÕËºÅ");
			else
				printf("          ");
			break;
		}
		case TipType::EmptyPassword:
		{
			Tools::ConsoleCursorGotoXY(47, 16);
			Tools::SetForgeGround(Colors::Red);
			if (opacity)
				printf("\033(BÎ´ÌîÐ´ÃÜÂë");
			else
				printf("          ");
			break;
		}
		case TipType::WrongAccountAndPassword:
		{
			Tools::SetForgeGround(opacity ? Colors::Red : Colors::White);
			Tools::ConsoleCursorGotoXY(41, 27);
			printf("\033(0lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk ");
			Tools::ConsoleCursorGotoXY(41, 28);
			printf("\033(0x ÕËºÅ²»´æÔÚ»òÃÜÂë²»ÕýÈ·ÇëÖØÐÂÊäÈëx ");
			Tools::ConsoleCursorGotoXY(41, 29);
			printf("\033(0mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj ");
			break;
		}
		case TipType::LoginSuccessfull:
		{
			Tools::SetForgeGround(opacity ? Colors::DarkGreen : Colors::White);
			Tools::ConsoleCursorGotoXY(51, 27);
			printf("\033(0lqqqqqqqqqqqqqk");
			Tools::ConsoleCursorGotoXY(51, 28);
			printf("\033(0x ¹§Ï²µÇÂ¼³É¹¦x");
			Tools::ConsoleCursorGotoXY(51, 29);
			printf("\033(0mqqqqqqqqqqqqqj");
			break;
		}
		}
		Tools::ConsoleCursorGotoXY(0, 0);
	}

	void Main()
	{
		LoginInfo.Init();
		CharinfoNow.Init();

		Refresh();
		Sleep(1000);//·ÀÖ¹°´Ì«¿ì

		Button Buttons[5]{};
		Buttons[0].NewButton(39, 10, 41, 3, EnterAccount, 39, 10, 42);	//ÕËºÅÊäÈë¿ò
		Buttons[1].NewButton(39, 15, 41, 3, EnterPassword, 39, 15, 42);	//ÃÜÂëÊäÈë¿ò
		Buttons[2].NewButton(55, 20, 7, 3, PressLogin, 55, 20, 8);		//µÇÂ¼°´Å¥
		Buttons[3].NewButton(0, 0, 7, 3, PressBack, 0, 0, 8);			//·µ»Ø°´Å¥
		Buttons[4].NewButton(111, 0, 7, 3, Exit, 111, 0, 8);

		INPUT_RECORD Mouse;
		int x, y;
		//ÍË³ö°´Å¥
		while (1)
		{
			Tools::HideCursor(false);
			Mouse = Tools::EventInput();
			if (Mouse.EventType == MOUSE_EVENT)
			{
				if (Mouse.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					x = Mouse.Event.MouseEvent.dwMousePosition.X;
					y = Mouse.Event.MouseEvent.dwMousePosition.Y;
					if (Mouse.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)			//Ë«»÷
					{

					}
					else																//µ¥»÷
					{
						for (int i = 0; i < 5; ++i)
						{
							if (Buttons[i].Is_Click(x, y))
							{
								switch (i)
								{
								case 0://ÕËºÅÊäÈë¿ò
								case 1://ÃÜÂëÊäÈë¿ò
								{
									Buttons[i].Click(Buttons[i]);
									break;
								}
								case 2://µÇÂ¼°´Å¥
								{
									Buttons[i].Click(Buttons[i]);
									if (CharinfoNow.People == Charinfo::People::NotLogin)
									{
										break;
									}
									else
									{
										return;
									}
								}
								case 3://·µ»Ø°´Å¥
								case 4://ÍË³ö°´Å¥
								{
									Buttons[i].Click(Buttons[i]);
									return;
								}
								}
								break;
							}
						}
					}

				}
			}
		}
	}
}