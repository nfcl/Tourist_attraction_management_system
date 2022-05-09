#include "Global.h"

namespace Hotel
{
	ListGrid ListInfos;
	HotelInfo HotelNow;

	/// <summary>
	/// ���������г�����
	/// </summary>
	void ListHotelInfo(ListGrid ListContent);
	/// <summary>
	/// ���Ҳ�����г��Ƶ�����
	/// </summary>
	void ListHotelDescrible();
	void ListHotelLocation();
	/// <summary>
	/// ���Ҳ����ʾ��ǰѡ�еľƵ�����
	/// </summary>
	/// <param name="id"></param>
	void ShowSingleHotelInfo(int id);
	void Init();

	void Refresh()
	{
		system("cls");
		Tools::HideCursor(false);
		Tools::ConsoleCursorGotoXY(0, 0);
		Tools::SetBothGround(Colors::Black, Colors::White);
		//			  0         1         2         3         4         5         6         7         8         9         0         1       
		//			  0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567
		printf("\033(0lqqqqqwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwqqqqqk\n");//0 0
		printf("\033(0x ����x                                                �Ƶ���Ϣ                                                x �˳�x\n");//1
		printf("\033(0tqqqqqvqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvqqqqqu\n");//2
		printf("\033(0x                                                                                                                    x\n");//3
		printf("\033(0xlqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk              lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk x\n");//4
		printf("\033(0xx ���x �Ƶ�����                               x �Ƶ꼶��    x    �Ƶ����ƣ�x                                     x x\n");//5
		printf("\033(0xtqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqu              mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj x\n");//6
		printf("\033(0xx                                                          ��x              lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk x\n");//7
		printf("\033(0xx                                                          x x    �Ƶ꼶��x                                     x x\n");//8
		printf("\033(0xx                                                          x x              mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj x\n");//9
		printf("\033(0xx                                                          x x              lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk x\n");//0 1
		printf("\033(0xx                                                          x x    �Ƶ���ϸ��x                                   ��x x\n");//1
		printf("\033(0xx                                                          x x              x                                   x x x\n");//2
		printf("\033(0xx                                                          x x              x                                   x x x\n");//3
		printf("\033(0xx                                                          x x              x                                   x x x\n");//4
		printf("\033(0xx                                                          x x              x                                   x x x\n");//5
		printf("\033(0xx                                                          x x              x                                   x x x\n");//6
		printf("\033(0xx                                                          x x              x                                   x x x\n");//7
		printf("\033(0xx                                                          x x              x                                   x x x\n");//8
		printf("\033(0xx                                                          x x              x                                   x x x\n");//9
		printf("\033(0xx                                                          x x              x                                   x x x\n");//0 2
		printf("\033(0xx                                                          x x              x                                   x x x\n");//1
		printf("\033(0xx                                                          x x              x                                   ��x x\n");//2
		printf("\033(0xx                                                          x x              mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj x\n");//3
		printf("\033(0xx                                                          x x              lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk x\n");//4
		printf("\033(0xx                                                          x x    �Ƶ��ַ��x                                     x x\n");//5
		printf("\033(0xx                                                          x x              mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj x\n");//6
		printf("\033(0xx                                                          x x              lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk x\n");//7
		printf("\033(0xx                                                          x x    Ԥ���绰��x                                     x x\n");//8
		printf("\033(0xx                                                          x x              mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj x\n");//9
		printf("\033(0xx                                                          x x                   lqqqqqqqk            lqqqqqqqk     x\n");//0 3
		printf("\033(0xx                                                          ��x                   x <<ǰ��x            x ��>>x     x\n");//1
		printf("\033(0xmqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj                   mqqqqqqqj            mqqqqqqqj     x\n");//2
		printf("\033(0mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj\n");//3
		Tools::ConsoleCursorGotoXY(0, 0);
	}

	void PressLast(Button Sender)
	{
		if (HotelNow.id)
		{
			Hotels.get(&HotelNow, HotelNow.id - 1);
		}
		ShowSingleHotelInfo(HotelNow.id);
	}

	void PressNext(Button Sender)
	{
		if (HotelNow.id < Hotels.size)
		{
			Hotels.get(&HotelNow, HotelNow.id + 1);
		}
		ShowSingleHotelInfo(HotelNow.id);
	}

	void PressBack(Button Sender)
	{

	}

	void Exit(Button Sender)
	{
		exit(0);
	}

	void Main()
	{
		Init();
		Refresh();
		ListHotelInfo(ListInfos);
		

		Button Buttons[4]{};
		Buttons[0].NewButton(0, 0, 7, 3, PressBack, 0, 0, 8);			//���ذ�ť
		Buttons[1].NewButton(111, 0, 7, 3, Exit, 111, 0, 8);			//�˳���ť
		Buttons[2].NewButton(82, 30, 10, 3, PressLast, 82, 30, 11);		//ǰ����ť
		Buttons[3].NewButton(103, 30, 10, 3, PressNext, 103, 30, 11);	//�󷭰�ť

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
						if (x >= 2 && x <= 60 && y >= 7 && y <= 31)
						{
							if (ListInfos.BeginLine + y - 7 < Hotels.size)
								ShowSingleHotelInfo(ListInfos.BeginLine + y - 7);
						}
						for (int i = 0; i < 4; ++i)
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
								case 2:
								case 3:
								{
									Buttons[i].Click(Buttons[i]);
									break;
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
					if (x >= 2 && x <= 60 && y >= 7 && y <= 31)
					{//���оƵ���Ϣ��Ԥ��
						if ((Mouse.Event.MouseEvent.dwButtonState) >> 24 > 0)//�������û������
						{
							if (ListInfos.EndLine + 1 < Hotels.size)
							{
								ListInfos.BeginLine += 1;
								ListInfos.EndLine += 1;
								ListHotelInfo(ListInfos);
							}
						}
						else												 //������Զ���û������
						{
							if (ListInfos.BeginLine)
							{
								ListInfos.BeginLine -= 1;
								ListInfos.EndLine -= 1;
								ListHotelInfo(ListInfos);
							}
						}
					}
					else if (x >= 79 && x <= 113 && y >= 11 && y <= 22)
					{//�Ƶ���ܵ�Ԥ��
						if (HotelNow.Level != -1)
						{
							if ((Mouse.Event.MouseEvent.dwButtonState) >> 24 > 0)//�������û������
							{
								if (HotelNow.DescribleList.EndLine + 1 < HotelNow.DescribleList.Lists.size)
								{
									HotelNow.DescribleList.BeginLine += 1;
									HotelNow.DescribleList.EndLine += 1;
									ListHotelDescrible();
								}
							}
							else												 //������Զ���û������
							{
								if (HotelNow.DescribleList.BeginLine)
								{
									HotelNow.DescribleList.BeginLine -= 1;
									HotelNow.DescribleList.EndLine -= 1;
									ListHotelDescrible();
								}
							}
						}
					}
					else if (x >= 79 && x <= 113 && y >= 25 && y <= 25)
					{//�Ƶ��ַ��Ԥ��
						if ((Mouse.Event.MouseEvent.dwButtonState) >> 24 > 0)//�������û������
						{
							if (HotelNow.LocationList.EndLine + 1 < HotelNow.LocationList.Lists.size)
							{
								HotelNow.LocationList.BeginLine += 1;
								HotelNow.LocationList.EndLine += 1;
								ListHotelLocation();
							}
						}
						else												 //������Զ���û������
						{
							if (HotelNow.LocationList.BeginLine)
							{
								HotelNow.LocationList.BeginLine -= 1;
								HotelNow.LocationList.EndLine -= 1;
								ListHotelLocation();
							}
						}
					}
				}
			}
		}
	}

	void Init()
	{
		Vector ListContent;
		HotelInfo tmpinfo;
		ListContent.newvector(sizeof(char[59]));
		for (int i = 0; i < Hotels.size; ++i)
		{
			Hotels.get(&tmpinfo, i);
			ListContent.push_back(tmpinfo.Datagridline);
		}
		ListInfos.Lists = ListContent;
		ListInfos.BeginLine = 0;
		ListInfos.EndLine = min(25 - 1, Hotels.size - 1);
	}

	void ListHotelInfo(ListGrid ListContent)
	{
		char tmpchars[59];
		Tools::SetForgeGround(Colors::Black);
		for (int i = ListContent.BeginLine; i <= ListContent.EndLine; ++i)
		{
			Tools::ConsoleCursorGotoXY(3, 7 + i - ListContent.BeginLine);
			Tools::SetBackGround(i % 2 ? Colors::LightGray : Colors::DarkGray);
			ListContent.Lists.get(tmpchars, i);
			printf("\033(0%s", tmpchars);
		}
	}

	void ListHotelDescrible()
	{
		printf("\033(B");
		Tools::SetBothGround(Colors::Black, Colors::White);
		char tmplist[34];
		for (int i = HotelNow.DescribleList.BeginLine; i <= HotelNow.DescribleList.EndLine; ++i)
		{
			memset(tmplist, '\0', 34);
			HotelNow.DescribleList.Lists.get(tmplist, i);
			Tools::ConsoleCursorGotoXY(79, 11 + i - HotelNow.DescribleList.BeginLine);
			printf("                                  ");
			Tools::ConsoleCursorGotoXY(79, 11 + i - HotelNow.DescribleList.BeginLine);
			printf("%s", tmplist);
		}
	}

	void ListHotelLocation()
	{
		printf("\033(B");
		Tools::SetBothGround(Colors::Black, Colors::White);
		char tmplist[34];
		for (int i = HotelNow.LocationList.BeginLine; i <= HotelNow.LocationList.EndLine; ++i)
		{
			HotelNow.LocationList.Lists.get(tmplist, i);
			Tools::ConsoleCursorGotoXY(79, 25 + i - HotelNow.LocationList.BeginLine);
			printf("                                    ");
			Tools::ConsoleCursorGotoXY(79, 25 + i - HotelNow.LocationList.BeginLine);
			printf("%s", tmplist);
		}
	}

	void ShowSingleHotelInfo(int id)
	{
		printf("\033(B");
		char itc[][3] = { "��","һ","��","��","��","��","��","��","��","��" };
		Tools::SetBothGround(Colors::Black, Colors::White);
		Hotels.get(&HotelNow, id);
		{
			Tools::ConsoleCursorGotoXY(79, 5);
			printf("                                    ");
			Tools::ConsoleCursorGotoXY(79, 5);
			printf("%s", HotelNow.Name);
		}
		{
			Tools::ConsoleCursorGotoXY(79, 8);
			printf("                                    ");
			Tools::ConsoleCursorGotoXY(79, 8);
			printf("%s�Ǽ�", itc[HotelNow.Level]);
		}
		for (int i = 11; i <= 22; ++i)
		{
			Tools::ConsoleCursorGotoXY(79, i);
			printf("                                  ");
		}
		ListHotelDescrible();
		{
			Tools::ConsoleCursorGotoXY(79, 28);
			printf("                                    ");
			Tools::ConsoleCursorGotoXY(79, 28);
			printf("%s", HotelNow.Telephone);
		}
		{
			Tools::ConsoleCursorGotoXY(79, 25);
			printf("\033(0                                    ");
			Tools::ConsoleCursorGotoXY(79, 25);
			printf("\033(B");
			ListHotelLocation();
		}
	}
}