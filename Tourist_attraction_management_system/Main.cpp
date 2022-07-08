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
		printf("\033(0x                                                  ������Ϣ����ϵͳ                                            x �˳�x  \n");//1
		printf("\033(0tqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvqqqqqu  \n");//2
		printf("\033(0x                                                                                                                    x  \n");//3
		printf("\033(0x                                                                                                                    x  \n");//4
		printf("\033(0x                                                                                                                    x  \n");//5
		printf("\033(0x                                                                                                                    x  \n");//6
		printf("\033(0x                                                                                                                    x  \n");//7
		printf("\033(0x                                                                                                                    x  \n");//8
		printf("\033(0x                                                                                                                    x  \n");//9
		printf("\033(0x                                                      l qqqqk                                                       x  \n");//0 1
		printf("\033(0x                                                      x ��¼x                                                       x  \n");//1
		printf("\033(0x                                                      m qqqqj                                                       x  \n");//2
		printf("\033(0x                                                                                                                    x  \n");//3
		printf("\033(0x                                                      l qqqqk                                                       x  \n");//4
		printf("\033(0x                                                      x ע��x                                                       x  \n");//5
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
		printf("\033[0m");												//���ת����������

		char CharinfoPath[] = "Charinfos.txt";							//������Ϣ��ȡ
		Charinfos = Data::CharinfoRead(CharinfoPath);

		char AttractionInfoPath[] = "Attractionsinfo.txt";				//������Ϣ��ȡ
		Attractions = Data::AttractionsRead(AttractionInfoPath);

		char HotelInfoPath[] = "HotelInfo.txt";
		Hotels = Data::ReadHotelInfo(HotelInfoPath);					//�Ƶ���Ϣ��ȡ

		char TransitInfoPath[] = "Transit.txt";
		Transits = Data::ReadTransitInfo(TransitInfoPath);				//������Ϣ��ȡ

		CharinfoNow.Init();												//��¼��Ա��Ϣ��ʼ��
	}

	//������������������������������������������������������������������������������������������������
	//��ť�¼���
	//������������������������������������������������������������������������������������������������
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
		Buttons[0].NewButton(55, 10, 7, 3, ToLogin, 55, 10, 8);				//��¼��ť
		Buttons[1].NewButton(55, 14, 7, 3, ToRegiste, 55, 14, 8);			//ע�ᰴť
		Buttons[3].NewButton(111, 0, 7, 3, Exit, 111, 0, 8);				//�˳���ť

		INPUT_RECORD Mouse;
		int x, y;
		while (1)
		{
			Tools::HideCursor(false);
			Mouse = Tools::EventInput();
			if (Mouse.EventType == MOUSE_EVENT)
			{
				if (Mouse.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)	//�����һ���������������
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
								case 0://��¼��ť
								case 1://ע�ᰴť
								case 2://�ο͵�¼��ť
								{
									Buttons[i].Click(Buttons[i]);
									break;
								}
								case 3://�˳���ť
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