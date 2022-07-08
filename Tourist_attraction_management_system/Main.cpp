#include "Global.h"

namespace Main
{
	void Refresh()
	{
		system("cls");
		Tools::HideCursor(false);
		Tools::ConsoleCursorGotoXY(0, 0);
		Tools::SetBothGround(Colors::Black, Colors::White);
		//			  0         1         2         3         4         5         6         7         8         9         0         1       
		//			  0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567
		printf("\033(0lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwqqqqqk  \n");//0 0
		printf("\033(0x                                                  旅游信息管理系统                                            x 退出x  \n");//1
		printf("\033(0tqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvqqqqqu  \n");//2
		printf("\033(0x                                                                                                                    x  \n");//3
		printf("\033(0x                                                                                                                    x  \n");//4
		printf("\033(0x                                                                                                                    x  \n");//5
		printf("\033(0x                                                                                                                    x  \n");//6
		printf("\033(0x                                                                                                                    x  \n");//7
		printf("\033(0x                                                                                                                    x  \n");//8
		printf("\033(0x                                                                                                                    x  \n");//9
		printf("\033(0x                                                      l qqqqk                                                       x  \n");//0 1
		printf("\033(0x                                                      x 登录x                                                       x  \n");//1
		printf("\033(0x                                                      m qqqqj                                                       x  \n");//2
		printf("\033(0x                                                                                                                    x  \n");//3
		printf("\033(0x                                                      l qqqqk                                                       x  \n");//4
		printf("\033(0x                                                      x 注册x                                                       x  \n");//5
		printf("\033(0x                                                      m qqqqj                                                       x  \n");//6
		printf("\033(0x                                                                                                                    x  \n");//7
		printf("\033(0x                                                                                                                    x  \n");//8
		printf("\033(0x                                                                                                                    x  \n");//8
		printf("\033(0x                                                                                                                    x  \n");//8
		printf("\033(0x                                                                                                                    x  \n");//1
		printf("\033(0x                                                                                                                    x  \n");//2
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

	void Init()
	{
		printf("\033[0m");												//清除转义序列属性

		char CharinfoPath[] = "Charinfos.txt";							//人物信息读取
		Charinfos = Data::CharinfoRead(CharinfoPath);

		char AttractionInfoPath[] = "Attractionsinfo.txt";				//景点信息读取
		Attractions = Data::AttractionsRead(AttractionInfoPath);

		char HotelInfoPath[] = "HotelInfo.txt";
		Hotels = Data::ReadHotelInfo(HotelInfoPath);					//酒店信息读取

		char TransitInfoPath[] = "Transit.txt";
		Transits = Data::ReadTransitInfo(TransitInfoPath);				//公交信息读取

		CharinfoNow.Init();												//登录人员信息初始化
	}

	//————————————————————————————————————————————————
	//按钮事件区
	//————————————————————————————————————————————————
	void ToLogin(Button Sender)
	{
		Login::Main();
		switch (CharinfoNow.People)
		{
		case Charinfo::People::NotLogin:
		{
			break;
		}
		case Charinfo::People::Adminstrator:
		{
			Adminstrator::Main();
			break;
		}
		case Charinfo::People::Vip:
		{
			Vip::Main();
			break;
		}
		}
	}

	void ToRegiste(Button Sender)
	{
		Registe::Main();
	}

	void Exit(Button Sender)
	{
		exit(0);
	}

	void Main()
	{
		Init();
		Refresh();

		int ButtonNum = 4;
		Button Buttons[4]{};
		Buttons[0].NewButton(55, 10, 7, 3, ToLogin, 55, 10, 8);				//登录按钮
		Buttons[1].NewButton(55, 14, 7, 3, ToRegiste, 55, 14, 8);			//注册按钮
		Buttons[3].NewButton(111, 0, 7, 3, Exit, 111, 0, 8);				//退出按钮

		INPUT_RECORD Mouse;
		int x, y;
		while (1)
		{
			Tools::HideCursor(false);
			Mouse = Tools::EventInput();
			if (Mouse.EventType == MOUSE_EVENT)
			{
				if (Mouse.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)	//左起第一个按键即左键按下
				{
					x = Mouse.Event.MouseEvent.dwMousePosition.X;
					y = Mouse.Event.MouseEvent.dwMousePosition.Y;
					if (Mouse.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)			//双击
					{

					}
					else																//单击
					{
						for (int i = 0; i < ButtonNum; ++i)
						{
							if (Buttons[i].Is_Click(x, y))
							{
								switch (i)
								{
								case 0://登录按钮
								case 1://注册按钮
								case 2://游客登录按钮
								{
									Buttons[i].Click(Buttons[i]);
									break;
								}
								case 3://退出按钮
								{
									Buttons[i].Click(Buttons[i]);
									return;
								}
								}
								Refresh();
								break;
							}
						}
					}

				}
			}
		}
	}
}