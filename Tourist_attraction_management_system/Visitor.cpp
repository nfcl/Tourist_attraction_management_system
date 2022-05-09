#include "Global.h"

namespace Visitor
{
	void Refresh()
	{
		system("cls");
		Tools::HideCursor(false);
		Tools::ConsoleCursorGotoXY(0, 0);
		Tools::SetBothGround(Colors::Black, Colors::White);
		//			  0         1         2         3         4         5         6         7         8         9         0         1       
		//			  0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567
		printf("\033(0lqqqqqwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwqqqqqk  \n");//0 0
		printf("\033(0x 注销x                                                 主界面                    游客登陆中.....              x 退出x  \n");//1
		printf("\033(0tqqqqqvqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvqqqqqu  \n");//2
		printf("\033(0x                                                                                                                    x  \n");//3
		printf("\033(0x     lqqqqqqqqqqqqqk                                                                                                x  \n");//4
		printf("\033(0x     x 景点信息查看x                                                                                                x  \n");//5
		printf("\033(0x     mqqqqqqqqqqqqqj                                                                                                x  \n");//6
		printf("\033(0x                                                                                                                    x  \n");//7
		printf("\033(0x     lqqqqqqqqqqqqqk                                                                                                x  \n");//8
		printf("\033(0x     x 酒店信息查看x                                                                                                x  \n");//9
		printf("\033(0x     mqqqqqqqqqqqqqj                                                                                                x  \n");//0 1
		printf("\033(0x                                                                                                                    x  \n");//1
		printf("\033(0x     lqqqqqqqqqqqqqk                                                                                                x  \n");//2
		printf("\033(0x     x 公交信息查看x                                                                                                x  \n");//3
		printf("\033(0x     mqqqqqqqqqqqqqj                                                                                                x  \n");//4
		printf("\033(0x                                                                                                                    x  \n");//5
		printf("\033(0x                                                                                                                    x  \n");//6
		printf("\033(0x                                                                                                                    x  \n");//7
		printf("\033(0x                                                                                                                    x  \n");//8
		printf("\033(0x                                                                                                                    x  \n");//9
		printf("\033(0x                                                                                                                    x  \n");//0 2
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
		printf("\033(B");
	}

	void PressAttractionInfoCheck(Button Sender)
	{
		Attraction::Main();
	}

	void PressHotleInfoCheck(Button Sender)
	{
		Hotel::Main();
	}

	void PressTransitCheck(Button Sender)
	{
		//Transit::Main();
	}

	void LoginOut(Button Sender)
	{
		CharinfoNow.Init();
	}

	void Exit(Button Sender)
	{
		exit(0);
	}

	void Main()
	{
		Refresh();
		Sleep(100);

		int ButtonNum = 5;
		Button Buttons[5]{};
		Buttons[0].NewButton(0, 0, 7, 3, LoginOut, 0, 0, 8);					//注销按钮
		Buttons[1].NewButton(111, 0, 7, 3, Exit, 111, 0, 8);					//退出按钮
		Buttons[2].NewButton(6, 4, 15, 3, PressAttractionInfoCheck, 6, 4, 16);	//景点信息查看按钮
		Buttons[3].NewButton(6, 8, 15, 3, PressHotleInfoCheck, 6, 8, 16);		//酒店信息查看按钮
		Buttons[4].NewButton(6, 12, 15, 3, PressTransitCheck, 6, 12, 16);		//景点公交信息查看按钮
		
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
						for (int i = 0; i < ButtonNum; ++i)
						{
							if (Buttons[i].Is_Click(x, y))
							{
								switch (i)
								{
								case 0://注销按钮
								case 1://退出按钮
								{
									Buttons[i].Click(Buttons[i]);
									return;
								}
								case 2://景点信息查看按钮
								case 3://酒店信息查看按钮
								case 4://景点公交信息查看按钮
								{
									Buttons[i].Click(Buttons[i]);
									break;
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
