#include "Global.h"

namespace Registe
{
	/// <summary>
	/// 正在注册的账户信息
	/// </summary>
	Charinfo RegisteInfo;

	/// <summary>
	/// 提示
	/// </summary>
	enum class TipType
	{
		Enter,				//输入提示
		EmptyName,			//未填写名字
		EmptyAccount,		//未填写账号
		EmptyPassword,		//未填写密码
		ExistAccount,		//账号已存在
		SuccessfullRegiste	//注册成功
	};
	/// <summary>
	/// 提示用户
	/// </summary>
	/// <param name="type"></param>
	/// <param name="opacity"></param>
	void Tips(TipType type, bool opacity);

	//——————————————————————————————————————————————————————————————————————————
	// 设置为姓名可以包括中文不可以超过15个字按宽字节长度算																								 |
	// 账号和密码不可以包括中文只可以包括0-127ascii码内有效字符(不包括' ')																				 |
	//——————————————————————————————————————————————————————————————————————————
	void Refresh()
	{
		system("cls");
		Tools::HideCursor(false);
		Tools::ConsoleCursorGotoXY(0, 0);
		Tools::SetBothGround(Colors::Black, Colors::White);
		//X10		  0         1         2         3         4         5         6         7         8         9         10        11       
		//X1		  0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567
		printf("\033(0lqqqqqwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwqqqqqk  \n");//0 0
		printf("\033(0x 返回x                                                  注册                                                  x 退出x  \n");//1
		printf("\033(0tqqqqqvqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvqqqqqu  \n");//2
		printf("\033(0x                                                                                                                    x  \n");//3
		printf("\033(0x                                                                                                                    x  \n");//4
		printf("\033(0x                                                                                                                    x  \n");//5
		printf("\033(0x                                      l qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk                                      x  \n");//6
		printf("\033(0x                                      x 姓名x                                x                                      x  \n");//7
		printf("\033(0x                                      m qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj                                      x  \n");//8
		printf("\033(0x                                                                                                                    x  \n");//9
		printf("\033(0x                                      l qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk                                      x  \n");//0 1
		printf("\033(0x                                      x 账号x                                x                                      x  \n");//1
		printf("\033(0x                                      m qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj                                      x  \n");//2
		printf("\033(0x                                                                                                                    x  \n");//3
		printf("\033(0x                                      l qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk                                      x  \n");//4
		printf("\033(0x                                      x 密码x                                x                                      x  \n");//5
		printf("\033(0x                                      m qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj                                      x  \n");//6
		printf("\033(0x                                                                                                                    x  \n");//7
		printf("\033(0x                                                                                                                    x  \n");//8
		printf("\033(0x                                           l qqqqqqqqqqqqqqqqqqqqqqqqqqk                                            x  \n");//9
		printf("\033(0x                                           x   ■会员        □管理者  x                                            x  \n");//0 2
		printf("\033(0x                                           m qqqqqqqqqqqqqqqqqqqqqqqqqqj                                            x  \n");//1
		printf("\033(0x                                                                                                                    x  \n");//2
		printf("\033(0x                                                                                                                    x  \n");//3
		printf("\033(0x                                                      l qqqqk                                                       x  \n");//4
		printf("\033(0x                                                      x 注册x                                                       x  \n");//5
		printf("\033(0x                                                      m qqqqj                                                       x  \n");//6
		printf("\033(0x                                                                                                                    x  \n");//7
		printf("\033(0x                                                                                                                    x  \n");//8
		printf("\033(0x                                                                                                                    x  \n");//9
		printf("\033(0x                                                                                                                    x  \n");//0 3
		printf("\033(0x                                                                                                                    x  \n");//1
		printf("\033(0x                                                                                                                    x  \n");//2
		printf("\033(0mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj  \n");//3
		Tools::ConsoleCursorGotoXY(0, 0);
	}

	//——————————————————————————————————————————————————————————————————————————
	//按钮事件区																																		 |
	//——————————————————————————————————————————————————————————————————————————
	void EnterName(Button Sender)
	{//输入名字
		Tips(TipType::ExistAccount, 0);

		wchar_t buffer[16] = { '\0' };
		Vector Vbuffer;
		Vbuffer.newvector(sizeof(wchar_t));
		Tools::Char2Wchar(buffer, RegisteInfo.Name);
		for (int i = 0; i < lstrlenW(buffer); ++i)
		{
			Vbuffer.push_back(&buffer[i]);
		}

		if (Vbuffer.size == 0)
			Tips(TipType::EmptyName, 0);

		Tools::HideCursor(true);
		Tips(TipType::Enter, 1);
		Tools::ConsoleCursorGotoXY(47, 7);
		Tools::Enter(Vbuffer, 15, 0x1111);
		Tips(TipType::Enter, 0);
		Tools::HideCursor(false);
		setlocale(LC_ALL, "C");

		for (int i = 0; i < Vbuffer.size; ++i)
		{
			Vbuffer.get(&buffer[i], i);
		}
		buffer[Vbuffer.size] = '\0';
		Tools::Wchar2Char(RegisteInfo.Name, buffer);
	}

	void EnterAccount(Button Sender)
	{//输入账号
		Tips(TipType::ExistAccount, 0);

		wchar_t buffer[16] = { '\0' };
		Vector Vbuffer;
		Vbuffer.newvector(sizeof(wchar_t));
		Tools::Char2Wchar(buffer, RegisteInfo.Account);
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
		Tools::Wchar2Char(RegisteInfo.Account, buffer);
	}

	void EnterPassword(Button Sender)
	{//输入密码
		Tips(TipType::ExistAccount, 0);

		wchar_t buffer[16] = { '\0' };
		Vector Vbuffer;
		Vbuffer.newvector(sizeof(wchar_t));
		Tools::Char2Wchar(buffer, RegisteInfo.Password);
		for (int i = 0; i < lstrlenW(buffer); ++i)
		{
			Vbuffer.push_back(&buffer[i]);
		}
		if (Vbuffer.size == 0)
			Tips(TipType::EmptyPassword, 0);
		Tools::HideCursor(true);
		Tips(TipType::Enter, 1);
		Tools::ConsoleCursorGotoXY(47, 15);
		Tools::Enter(Vbuffer, 15, 0x0111);
		Tips(TipType::Enter, 0);
		Tools::HideCursor(false);
		setlocale(LC_ALL, "C");
		for (int i = 0; i < Vbuffer.size; ++i)
		{
			Vbuffer.get(&buffer[i], i);
		}
		buffer[Vbuffer.size] = '\0';
		Tools::Wchar2Char(RegisteInfo.Password, buffer);
	}

	void SelectPeople(Button Sender)
	{//选择注册人员 □■
		Tips(TipType::ExistAccount, 0);

		if (Sender.x >= 47 && Sender.x <= 54)
		{
			Tools::SetForgeGround(Colors::Black);
			Tools::ConsoleCursorGotoXY(48, 20);
			printf("■");
			Tools::ConsoleCursorGotoXY(62, 20);
			printf("□");
			RegisteInfo.People = Charinfo::People::Vip;
		}
		else if (Sender.x >= 61 && Sender.x <= 70)
		{
			Tools::SetForgeGround(Colors::Black);
			Tools::ConsoleCursorGotoXY(48, 20);
			printf("□");
			Tools::ConsoleCursorGotoXY(62, 20);
			printf("■");
			RegisteInfo.People = Charinfo::People::Adminstrator;
		}
		Tools::ConsoleCursorGotoXY(0, 0);
	}

	void PressRegiste(Button Sender)
	{//尝试注册
		bool Empty = false;
		if (strlen(RegisteInfo.Name) == 0) { Empty = true; Tips(TipType::EmptyName, 1); }
		if (strlen(RegisteInfo.Account) == 0) { Empty = true; Tips(TipType::EmptyAccount, 1);}
		if (strlen(RegisteInfo.Password) == 0) { Empty = true; Tips(TipType::EmptyPassword, 1);}

		if (Empty)
			return;
		Charinfo tmpinfo;
		for (int i = 0; i < (int)Charinfos.size; ++i)
		{
			Charinfos.get(&tmpinfo, i);
			if (strcmp(tmpinfo.Account, RegisteInfo.Account) == 0)
			{
				Tips(TipType::ExistAccount, 1);
				return;
			}
		}
		Charinfos.push_back(&RegisteInfo);
		char CharinfoPath[] = "Charinfos.txt";
		Data::CharinfoWrite(Charinfos, CharinfoPath);
		RegisteInfo.People = Charinfo::People::NotLogin;
		Tips(TipType::SuccessfullRegiste, 1);
		Sleep(1000);
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
				printf("\033(B按下Enter结束输入");
			else
				printf("                 ");
			break;
		}
		case TipType::EmptyName:
		{
			Tools::ConsoleCursorGotoXY(47, 7);
			Tools::SetForgeGround(Colors::Red);
			if (opacity)
				printf("\033(B未填写姓名");
			else
				printf("          ");
			break;
		}
		case TipType::EmptyAccount:
		{
			Tools::ConsoleCursorGotoXY(47, 11);
			Tools::SetForgeGround(Colors::Red);
			if (opacity)
				printf("\033(B未填写账号");
			else
				printf("          ");
			break;
		}
		case TipType::EmptyPassword:
		{
			Tools::ConsoleCursorGotoXY(47, 15);
			Tools::SetForgeGround(Colors::Red);
			if (opacity)
				printf("\033(B未填写密码");
			else
				printf("          ");
			break;
		}
		case TipType::ExistAccount:
		{
			if (opacity)
				Tools::SetForgeGround(Colors::Red);
			else
				Tools::SetForgeGround(Colors::White);
			Tools::ConsoleCursorGotoXY(46, 28);
			printf("\033(0l qqqqqqqqqqqqqqqqqqqqqqk");
			Tools::ConsoleCursorGotoXY(46, 29);
			printf("\033(0x 该账号已被其他用户注册x");
			Tools::ConsoleCursorGotoXY(46, 30);
			printf("\033(0m qqqqqqqqqqqqqqqqqqqqqqj");
			Tools::ConsoleCursorGotoXY(0, 0);
			break;
			break;
		}
		case TipType::SuccessfullRegiste:
		{
			Tools::SetForgeGround(Colors::DarkGreen);
			Tools::ConsoleCursorGotoXY(44, 28);
			printf("\033(0l qqqqqqqqqqqqqqqqqqqqqqqqqqqqk");
			Tools::ConsoleCursorGotoXY(44, 29);
			printf("\033(0x 恭喜注册成功，请稍后重新登录x");
			Tools::ConsoleCursorGotoXY(44, 30);
			printf("\033(0m qqqqqqqqqqqqqqqqqqqqqqqqqqqqj");
			Tools::ConsoleCursorGotoXY(0, 0);
			Tools::SetForgeGround(Colors::Black);
			break;
		}
		}
		Tools::ConsoleCursorGotoXY(0, 0);
	}

	void Main()
	{
		RegisteInfo.Init();
		RegisteInfo.People = Charinfo::People::Vip;

		Refresh();
		Sleep(1000);//防止按太快

		int ButtonNum = 7;
		Button Buttons[7]{};
		Buttons[0].NewButton(39, 6, 40, 3, EnterName, 39, 6, 41);			//姓名输入框
		Buttons[1].NewButton(39, 10, 40, 3, EnterAccount, 39, 10, 41);		//账号输入框
		Buttons[2].NewButton(39, 14, 40, 3, EnterPassword, 39, 14, 41);		//密码输入框
		Buttons[3].NewButton(44, 19, 29, 3, SelectPeople, 44, 19, 30);		//选择注册人员按钮
		Buttons[4].NewButton(55, 24, 7, 3, PressRegiste, 55, 24, 8);		//注册按钮
		Buttons[5].NewButton(0, 0, 7, 3, PressBack, 0, 0, 8);				//返回按钮
		Buttons[6].NewButton(111, 0, 7, 3, Exit, 111, 0, 8);				//退出按钮

		INPUT_RECORD Mouse;
		int x, y;
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
					if (Mouse.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)			//双击
					{

					}
					else																//单击
					{
						for (int i = 0; i < 7; ++i)
						{
							if (Buttons[i].Is_Click(x, y))
							{
								Buttons[i].x = x;
								Buttons[i].y = y;
								switch (i)
								{
								case 0://姓名输入框
								case 1://账号输入框
								case 2://密码输入框
								case 3://选择注册人员按钮
								{
									Buttons[i].Click(Buttons[i]);
									break;
								}
								case 4://注册按钮
								{
									Buttons[i].Click(Buttons[i]);
									if (RegisteInfo.People == Charinfo::People::NotLogin)
										return;
									else
										break;
								}
								case 5://返回按钮
								case 6://退出按钮
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