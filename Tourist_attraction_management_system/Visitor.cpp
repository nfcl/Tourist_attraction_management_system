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
		printf("\033(0x ע��x                                                 ������                    �ο͵�½��.....              x �˳�x  \n");//1
		printf("\033(0tqqqqqvqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvqqqqqu  \n");//2
		printf("\033(0x                                                                                                                    x  \n");//3
		printf("\033(0x     lqqqqqqqqqqqqqk                                                                                                x  \n");//4
		printf("\033(0x     x ������Ϣ�鿴x                                                                                                x  \n");//5
		printf("\033(0x     mqqqqqqqqqqqqqj                                                                                                x  \n");//6
		printf("\033(0x                                                                                                                    x  \n");//7
		printf("\033(0x     lqqqqqqqqqqqqqk                                                                                                x  \n");//8
		printf("\033(0x     x �Ƶ���Ϣ�鿴x                                                                                                x  \n");//9
		printf("\033(0x     mqqqqqqqqqqqqqj                                                                                                x  \n");//0 1
		printf("\033(0x                                                                                                                    x  \n");//1
		printf("\033(0x     lqqqqqqqqqqqqqk                                                                                                x  \n");//2
		printf("\033(0x     x ������Ϣ�鿴x                                                                                                x  \n");//3
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
		Buttons[0].NewButton(0, 0, 7, 3, LoginOut, 0, 0, 8);					//ע����ť
		Buttons[1].NewButton(111, 0, 7, 3, Exit, 111, 0, 8);					//�˳���ť
		Buttons[2].NewButton(6, 4, 15, 3, PressAttractionInfoCheck, 6, 4, 16);	//������Ϣ�鿴��ť
		Buttons[3].NewButton(6, 8, 15, 3, PressHotleInfoCheck, 6, 8, 16);		//�Ƶ���Ϣ�鿴��ť
		Buttons[4].NewButton(6, 12, 15, 3, PressTransitCheck, 6, 12, 16);		//���㹫����Ϣ�鿴��ť
		
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
					if (Mouse.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)			//˫��
					{

					}
					else																//����
					{
						for (int i = 0; i < ButtonNum; ++i)
						{
							if (Buttons[i].Is_Click(x, y))
							{
								switch (i)
								{
								case 0://ע����ť
								case 1://�˳���ť
								{
									Buttons[i].Click(Buttons[i]);
									return;
								}
								case 2://������Ϣ�鿴��ť
								case 3://�Ƶ���Ϣ�鿴��ť
								case 4://���㹫����Ϣ�鿴��ť
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
