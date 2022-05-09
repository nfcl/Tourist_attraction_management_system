#include "Global.h"

namespace Transit
{
	ListGrid ListInfos;

	void Refresh()
	{
		system("cls");
		Tools::HideCursor(false);
		Tools::ConsoleCursorGotoXY(0, 0);
		Tools::SetBothGround(Colors::Black, Colors::White);
		//			  0         1         2         3         4         5         6         7         8         9         0         1       
		//			  0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567
		printf("\033(0lqqqqqwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwqqqqqk\n");//0 0
		printf("\033(0x ����x                                              ���㹫����Ϣ                                              x �˳�x\n");//1
		printf("\033(0tqqqqqvqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvqqqqqu\n");//2
		printf("\033(0x                                                                                                                    x\n");//3
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq   x\n");//4
		printf("\033(0x    x ���x               ��������               x            ���վ            x            �յ�վ            x    x\n");//5
		printf("\033(0x   qwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwq   x\n");//6
		printf("\033(0x    x                                                                                                          x��  x\n");//7
		printf("\033(0x    x                                                                                                          xx   x\n");//8
		printf("\033(0x    x                                                                                                          xx   x\n");//9
		printf("\033(0x    x                                                                                                          xx   x\n");//0 1
		printf("\033(0x    x                                                                                                          xx   x\n");//1
		printf("\033(0x    x                                                                                                          xx   x\n");//2
		printf("\033(0x    x                                                                                                          xx   x\n");//3
		printf("\033(0x    x                                                                                                          xx   x\n");//4
		printf("\033(0x    x                                                                                                          xx   x\n");//5
		printf("\033(0x    x                                                                                                          xx   x\n");//6
		printf("\033(0x    x                                                                                                          xx   x\n");//7
		printf("\033(0x    x                                                                                                          xx   x\n");//8
		printf("\033(0x    x                                                                                                          xx   x\n");//9
		printf("\033(0x    x                                                                                                          xx   x\n");//0 2
		printf("\033(0x    x                                                                                                          xx   x\n");//1
		printf("\033(0x    x                                                                                                          xx   x\n");//2
		printf("\033(0x    x                                                                                                          xx   x\n");//3
		printf("\033(0x    x                                                                                                          xx   x\n");//4
		printf("\033(0x    x                                                                                                          xx   x\n");//5
		printf("\033(0x    x                                                                                                          xx   x\n");//6
		printf("\033(0x    x                                                                                                          xx   x\n");//7
		printf("\033(0x    x                                                                                                          xx   x\n");//8
		printf("\033(0x    x                                                                                                          xx   x\n");//9
		printf("\033(0x    x                                                                                                          x��  x\n");//0 3
		printf("\033(0x   qvqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvq   x\n");//1
		printf("\033(0x                                                                                                                    x\n");//2
		printf("\033(0mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj\n");//3
		Tools::ConsoleCursorGotoXY(0, 0);
		printf("\033(B");
	}

	void Main()
	{
		Refresh();
		char TransitInfoPath[] = "Transit.txt";
		Transits = ReadTransitInfo(TransitInfoPath);
		Button Buttons[2]{};
		Buttons[0].NewButton(0, 0, 7, 3, PressBack, 0, 0, 8);			//���ذ�ť
		Buttons[1].NewButton(111, 0, 7, 3, Exit, 111, 0, 8);			//�˳���ť
		Refresh();
		ListTransitInfo();
		Sleep(250);
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
						if (x >= 7 && x <= 112 && y >= 7 && y <= 30)
						{
							if (BeginLine + y - 7 < Transits.size)
							{
								Transits.get(&TransitNow, BeginLine + y - 7);
								SingleTransit::Main(TransitNow);
								Refresh();
								ListTransitInfo();
							}
						}
					}
					else																//����
					{
						for (int i = 0; i < 2; ++i)
						{
							if (Buttons[i].Is_Click(x, y))
							{
								switch (i)
								{
								case 0://���ذ�ť
								case 1://�˳���ť
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
				else if (Mouse.Event.MouseEvent.dwEventFlags == MOUSE_WHEELED)
				{
					x = Mouse.Event.MouseEvent.dwMousePosition.X;
					y = Mouse.Event.MouseEvent.dwMousePosition.Y;
					if (x >= 7 && x <= 112 && y >= 7 && y <= 30)
					{
						if ((Mouse.Event.MouseEvent.dwButtonState) >> 24 > 0)//�������û������
						{
							if (EndLine + 1 < Transits.size)
							{
								BeginLine += 1;
								EndLine += 1;
								ListTransitInfo();
							}
						}
						else												 //������Զ���û������
						{
							if (BeginLine)
							{
								BeginLine -= 1;
								EndLine -= 1;
								ListTransitInfo();
							}
						}
					}
				}
			}
		}
	}
}