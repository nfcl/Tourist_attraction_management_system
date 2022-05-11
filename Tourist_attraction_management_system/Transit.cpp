#include "Global.h"

namespace SingleTransitinfo
{
	ListGrid ListInfos;
	TransitInfo TransitNow;
	int MaxRouteInOnePage = 25;

	void Init();
	void ShowInfos();
	void ShowRoute();

	void Refresh()
	{
		system("cls");
		Tools::HideCursor(false);
		Tools::ConsoleCursorGotoXY(0, 0);
		Tools::SetBothGround(Colors::Black, Colors::White);
		//			  0         1         2         3         4         5         6         7         8         9         0         1       
		//			  0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567
		printf("\033(0lqqqqqwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwqqqqqk\n");//0 0
		printf("\033(0x 返回x                                                                                                        x 退出x\n");//1
		printf("\033(0tqqqqqvqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvqqqqqu\n");//2
		printf("\033(0x            lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk  x\n");//3
		printf("\033(0x  公交名称：x                                                                                                    x  x\n");//4
		printf("\033(0x            mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj  x\n");//5
		printf("\033(0x            lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk  x\n");//6
		printf("\033(0x  时间安排：x                                                                                                    x  x\n");//7
		printf("\033(0x            mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj  x\n");//8
		printf("\033(0x            lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk  x\n");//9
		printf("\033(0x  推荐票价：x                                                                                                    x  x\n");//0 1
		printf("\033(0x            mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj  x\n");//1
		printf("\033(0x  路线：lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk  x\n");//2
		printf("\033(0x        x                                                                                                        x  x\n");//3
		printf("\033(0x        x                                                                                                        x  x\n");//4
		printf("\033(0x        x                                                                                                        x  x\n");//5
		printf("\033(0x        x                                                                                                        x  x\n");//6
		printf("\033(0x        x                                                                                                        x  x\n");//7
		printf("\033(0x        x                                                                                                        x  x\n");//8
		printf("\033(0x        x                                                                                                        x  x\n");//9
		printf("\033(0x        x                                                                                                        x  x\n");//0 2
		printf("\033(0x        x                                                                                                        x  x\n");//1
		printf("\033(0x        x                                                                                                        x  x\n");//2
		printf("\033(0x        x                                                                                                        x  x\n");//3
		printf("\033(0x        x                                                                                                        x  x\n");//4
		printf("\033(0x        x                                                                                                        x  x\n");//5
		printf("\033(0x        x                                                                                                        x  x\n");//6
		printf("\033(0x        x                                                                                                        x  x\n");//7
		printf("\033(0x        x                                                                                                        x  x\n");//8
		printf("\033(0x        mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj  x\n");//9
		printf("\033(0x                                                                                                                    x\n");//0 3
		printf("\033(0x                                                                                                                    x\n");//1
		printf("\033(0x                                                                                                                    x\n");//2
		printf("\033(0mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj\n");//3
		Tools::ConsoleCursorGotoXY(0, 0);
		printf("\033(B");
	}

	void PressBack(Button Sender)
	{

	}

	void Exit(Button Sender)
	{
		exit(0);
	}

	void Main(TransitInfo Transitinfo)
	{
		TransitNow = Transitinfo;

		Init();

		Refresh();
		ShowInfos();
		ShowRoute();

		Button Buttons[2]{};
		Buttons[0].NewButton(0, 0, 7, 3, PressBack, 0, 0, 8);			//返回按钮
		Buttons[1].NewButton(111, 0, 7, 3, Exit, 111, 0, 8);			//退出按钮
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
						for (int i = 0; i < 2; ++i)
						{
							if (Buttons[i].Is_Click(x, y))
							{
								switch (i)
								{
								case 0://返回按钮
								case 1://退出按钮
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
						if ((Mouse.Event.MouseEvent.dwButtonState) >> 24 > 0)//滚轮向用户方向滚
						{
							if (ListInfos.EndLine + 1 < Transitinfo.Route.size)
							{
								ListInfos.BeginLine += 1;
								ListInfos.EndLine += 1;
								ShowRoute();
							}
						}
						else												 //滚轮向远离用户方向滚
						{
							if (ListInfos.BeginLine)
							{
								ListInfos.BeginLine -= 1;
								ListInfos.EndLine -= 1;
								ShowRoute();
							}
						}
					}
				}
			}
		}
	}

	void Init()
	{
		Vector Content;
		Content.newvector(sizeof(char[200]));
		char tmpchar[200];
		char tmproute[40];
		int id;	//tmpchar中的下标
		const char moveo[] = "\033[1B\033[1D";
		const char movet[] = "\033[1B\033[2D";
		for (int i = 0; i < TransitNow.Route.size; ++i)
		{
			memset(tmpchar, '\0', 200);
			strcpy_s(tmpchar, 100, "○\033[1B\033[2D\0");
			id = strlen(tmpchar);
			TransitNow.Route.get(&tmproute, i);
			for (int i = 0; i < 16; ++i)
			{
				if (i < strlen(tmproute))
				{
				if (tmproute[i] > 255 || tmproute[i] < 0)
				{
					tmpchar[id] = tmproute[i];
					id += 1;
					i += 1;
					tmpchar[id] = tmproute[i];
					id += 1;
					strcpy_s(tmpchar + id, 100, movet);
				}
				else
				{
					tmpchar[id] = tmproute[i];
					id += 1;
					strcat_s(tmpchar + id, 100, moveo);
				}
				}
				else
				{
					tmpchar[id] = ' ';
					id += 1;
					i += 1;
					tmpchar[id] = ' ';
					id += 1;
					strcpy_s(tmpchar + id, 100, movet);
				}
				id = strlen(tmpchar);
			}
			Content.push_back(&tmpchar);
		}
		ListInfos.BeginLine = 0;
		ListInfos.EndLine = min(TransitNow.Route.size - 1, MaxRouteInOnePage - 1);
		ListInfos.Lists = Content;
	}

	void ShowInfos()
	{
		Tools::ConsoleCursorGotoXY(15, 4);
		printf("%s", TransitNow.Name);
		Tools::ConsoleCursorGotoXY(15, 7);
		printf("%s", TransitNow.Time);
		Tools::ConsoleCursorGotoXY(15, 10);
		printf("%s", TransitNow.Price);
	}

	void ShowRoute()
	{
		setlocale(LC_ALL, "C");
		char tmpchar[200];
		int MaxHeight = -1;
		int X = 11, Y = 13;
		if (ListInfos.BeginLine)
		{
			Tools::ConsoleCursorGotoXY(X, Y);
			printf("\033(0q");
		}
		else
		{
			Tools::ConsoleCursorGotoXY(X, Y);
			printf("  ");
		}
		if (ListInfos.EndLine < ListInfos.Lists.size - 1)
		{
			Tools::ConsoleCursorGotoXY(X + 4 * MaxRouteInOnePage, Y);
			printf("\033(0q");
		}
		else
		{
			Tools::ConsoleCursorGotoXY(X + 4 * MaxRouteInOnePage, Y);
			printf("  ");
		}
		for (int i = ListInfos.BeginLine; i <= ListInfos.EndLine; ++i)
		{
			ListInfos.Lists.get(&tmpchar, i);
			Tools::ConsoleCursorGotoXY(X + 2 + (i - ListInfos.BeginLine) * 4, Y);
			if (i - ListInfos.BeginLine)
			{
				Tools::ConsoleCursorGotoXY(X + (i - ListInfos.BeginLine) * 4, Y);
				printf("\033(0q");
			}
			Tools::ConsoleCursorGotoXY(X + 2 + (i - ListInfos.BeginLine) * 4, Y);
			printf("\033(B%s", tmpchar);
		}
		setlocale(LC_ALL, "C");
	}
}

namespace Transit
{
	ListGrid ListInfos;
	TransitInfo TransitNow;

	int MaxLinesInOnePage = 24;
	int SelectNum;

	void Init();
	void ListTransitInfo();

	void Refresh()
	{
		system("cls");
		Tools::HideCursor(false);
		Tools::ConsoleCursorGotoXY(0, 0);
		Tools::SetBothGround(Colors::Black, Colors::White);
		//□■
		//			  0         1         2         3         4         5         6         7         8         9         0         1       
		//			  0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567
		printf("\033(0lqqqqqwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwqqqqqk\n");//0 0
		printf("\033(0x 返回x                                              景点公交信息                                              x 退出x\n");//1
		printf("\033(0tqqqqqvqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvqqqqqu\n");//2
		printf("\033(0x                                                                                                                    x\n");//3
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq   x\n");//4
		printf("\033(0x    x  □ x 序号x              公交名称              x           起点站           x           终点站           x    x\n");//5
		printf("\033(0x   qwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwq   x\n");//6
		printf("\033(0x    x                                                                                                          x↑  x\n");//7
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
		printf("\033(0x    x                                                                                                          x↓  x\n");//0 3
		printf("\033(0x   qvqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvq   x\n");//1
		printf("\033(0x                                                                                                                    x\n");//2
		printf("\033(0mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj\n");//3
		Tools::ConsoleCursorGotoXY(0, 0);
		printf("\033(B");
	}

	void PressSelect(Button Sender)
	{
		TransitInfo tmpinfo;
		if (Sender.y == 5)
		{
			if (SelectNum == Transits.size)
			{
				Tools::ConsoleCursorGotoXY(8, 5);
				printf("□");
				for (int i = 0; i < Transits.size; ++i)
				{
					Transits.get(&tmpinfo, i);
					tmpinfo.id = abs(tmpinfo.id);
					Transits.set(&tmpinfo, i);
				}
				SelectNum = 0;
			}
			else
			{
				Tools::ConsoleCursorGotoXY(8, 5);
				printf("■");
				for (int i = 0; i < Transits.size; ++i)
				{
					Transits.get(&tmpinfo, i);
					tmpinfo.id = -abs(tmpinfo.id);
					Transits.set(&tmpinfo, i);
				}
				SelectNum = Transits.size;
			}
			ListTransitInfo();
		}
		else
		{
			if (Sender.y != 6 && ListInfos.BeginLine + Sender.y - 7 < (int)Transits.size)
			{
				Transits.get(&tmpinfo, ListInfos.BeginLine + Sender.y - 7);
				if (tmpinfo.id < 0)												//>0为未选
				{
					SelectNum -= 1;
					Tools::ConsoleCursorGotoXY(8, 5);
					printf("□");
					Tools::SetBackGround((-tmpinfo.id - 1) % 2 == 0 ? Colors::LightGray : Colors::DarkGray);
					Tools::ConsoleCursorGotoXY(8, Sender.y);
					printf("□");
				}
				else
				{
					SelectNum += 1;
					if (SelectNum == Transits.size)
					{
						Tools::ConsoleCursorGotoXY(8, 5);
						printf("■");
					}
					Tools::SetBackGround((tmpinfo.id - 1) % 2 == 0 ? Colors::LightGray : Colors::DarkGray);
					Tools::ConsoleCursorGotoXY(8, Sender.y);
					printf("■");
				}
				Tools::SetBothGround(Colors::Black, Colors::White);
				tmpinfo.id *= -1;
				Transits.set(&tmpinfo, ListInfos.BeginLine + Sender.y - 7);
			}
		}
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
 		ListTransitInfo();

		SelectNum = 0;
		int ButtonNum = 3;
		Button Buttons[3]{};
		Buttons[0].NewButton(0, 0, 7, 3, PressBack, 0, 0, 8);			//返回按钮
		Buttons[1].NewButton(111, 0, 7, 3, Exit, 111, 0, 8);			//退出按钮
		Buttons[2].NewButton(7, 5, 5, 26, PressSelect, 7, 5, 6);		//全选按钮
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
					if (Mouse.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)			//双击
					{
						if (x >= 7 && x <= 112 && y >= 7 && y <= 30)
						{
							if (ListInfos.BeginLine + y - 7 < (int)Transits.size)
							{
								Transits.get(&TransitNow, ListInfos.BeginLine + y - 7);
								SingleTransitinfo::Main(TransitNow);
								Refresh();
								ListTransitInfo();
							}
						}
					}
					else																//单击
					{
						for (int i = 0; i < ButtonNum; ++i)
						{
							if (Buttons[i].Is_Click(x, y))
							{
								switch (i)
								{
								case 0://返回按钮
								case 1://退出按钮
								{
									Buttons[i].Click(Buttons[i]);
									return;
								}
								case 2://全选按钮
								{
									Buttons[i].x = x;
									Buttons[i].y = y;
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
					if (x >= 7 && x <= 112 && y >= 7 && y <= 30)
					{
						if ((Mouse.Event.MouseEvent.dwButtonState) >> 24 > 0)//滚轮向用户方向滚
						{
							if (ListInfos.EndLine + 1 < (int)Transits.size)
							{
								ListInfos.BeginLine += 1;
								ListInfos.EndLine += 1;
								ListTransitInfo();
							}
						}
						else												 //滚轮向远离用户方向滚
						{
							if (ListInfos.BeginLine)
							{
								ListInfos.BeginLine -= 1;
								ListInfos.EndLine -= 1;
								ListTransitInfo();
							}
						}
					}
				}
			}
		}
	}

	void Init()
	{
		ListInfos.BeginLine = 0;
		ListInfos.EndLine = min(MaxLinesInOnePage - 1, (int)Transits.size - 1);
	}

	void ListTransitInfo()
	{
		TransitInfo tmpinfo;
		char tmpstart[40];
		char tmpend[40];
		for (int i = ListInfos.BeginLine; i <= ListInfos.EndLine; ++i)
		{
			Transits.get(&tmpinfo, i);
			tmpinfo.Route.front(&tmpstart);
			tmpinfo.Route.back(&tmpend);
			Tools::SetBackGround(i % 2 == 0 ? Colors::LightGray : Colors::DarkGray);
			Tools::ConsoleCursorGotoXY(7, i - ListInfos.BeginLine + 7);
			printf(" %s \033(0x %04dx %-35.35sx %-27.27sx %-27.27s", (tmpinfo.id > 0 ? "□" : "■"), (tmpinfo.id > 0 ? tmpinfo.id : -tmpinfo.id), tmpinfo.Name, tmpstart, tmpend);
			Tools::ConsoleCursorGotoXY(7, i - ListInfos.BeginLine + 7);
			Tools::SetBackGround(i % 2 == 0 ? Colors::LightGray : Colors::DarkGray);
		}
		Tools::SetBothGround(Colors::Black, Colors::White);
	}
}