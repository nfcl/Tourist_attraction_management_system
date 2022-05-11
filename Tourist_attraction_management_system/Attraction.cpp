#include "Global.h"

namespace SingleAttraction
{
	AttractionInfo AttractionNow;

	void ShowDescrible();


	void Refresh()
	{
		system("cls");
		Tools::HideCursor(false);
		Tools::ConsoleCursorGotoXY(0, 0);
		Tools::SetBothGround(Colors::Black, Colors::White);
		//			  0         1         2         3         4         5         6         7         8         9         0         1       
		//			  0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567
		printf("\033(0lqqqqqwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwqqqqqk\n");//0 0
		printf("\033(0x 返回x                                                景点信息                                                x 退出x\n");//1
		printf("\033(0tqqqqqvqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvqqqqqu\n");//2
		printf("\033(0x               lqqqqqk             lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk     x\n");//3
		printf("\033(0x     景点编号：x     x   景点名称：x                                                                          x     x\n");//4
		printf("\033(0x               mqqqqqj             mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj     x\n");//5
		printf("\033(0x               lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk     x\n");//6
		printf("\033(0x     景点类型：x                                                                                              x     x\n");//7
		printf("\033(0x               mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj     x\n");//8
		printf("\033(0x               lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk     x\n");//9
		printf("\033(0x     门票价格：x                                                                                              x     x\n");//0 1
		printf("\033(0x               mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj     x\n");//1
		printf("\033(0x               lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk     x\n");//2
		printf("\033(0x     详细信息：x                                                                                            ↑x     x\n");//3
		printf("\033(0x               x                                                                                            x x     x\n");//4
		printf("\033(0x               x                                                                                            x x     x\n");//5
		printf("\033(0x               x                                                                                            x x     x\n");//6
		printf("\033(0x               x                                                                                            x x     x\n");//7
		printf("\033(0x               x                                                                                            x x     x\n");//8
		printf("\033(0x               x                                                                                            x x     x\n");//9
		printf("\033(0x               x                                                                                            x x     x\n");//0 2
		printf("\033(0x               x                                                                                            x x     x\n");//1
		printf("\033(0x               x                                                                                            x x     x\n");//2
		printf("\033(0x               x                                                                                            x x     x\n");//3
		printf("\033(0x               x                                                                                            x x     x\n");//4
		printf("\033(0x               x                                                                                            x x     x\n");//5
		printf("\033(0x               x                                                                                            x x     x\n");//6
		printf("\033(0x               x                                                                                            ↓x     x\n");//7
		printf("\033(0x               mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj     x\n");//8
		printf("\033(0x                                                                                                                    x\n");//9
		printf("\033(0x                                                                                                                    x\n");//0 3
		printf("\033(0x                                                                                                                    x\n");//1
		printf("\033(0mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj\n");//2
		Tools::ConsoleCursorGotoXY(0, 0);
	}

	void ShowSingle()
	{
		setlocale(LC_ALL, "C");
		Tools::SetBothGround(Colors::Black, Colors::White);
		//景点编号
		{
			Tools::ConsoleCursorGotoXY(18, 4);
			printf("\033(B%04d", AttractionNow.id);
		}
		//景点名称
		{
			Tools::ConsoleCursorGotoXY(38, 4);
			printf("\033(B%s", AttractionNow.name);
		}
		//景点类型
		{
			char tmptag[10];
			Tools::ConsoleCursorGotoXY(18, 7);
			Tools::SetBackGround(Colors::LightGray);
			for (int i = 0; i < AttractionNow.Tags.size; ++i)
			{
				AttractionNow.Tags.get(&tmptag, i);
				printf("\033(B%s\033[3C", tmptag);
			}
			Tools::SetBackGround(Colors::White);
		}
		//景点票价
		{
			Tools::ConsoleCursorGotoXY(18, 10);
			printf("\033(B%s", AttractionNow.Price);
		}
		//景点描述
		{
			AttractionNow.wrap(92, 15);
			ShowDescrible();
		}
	}

	void ShowDescrible()
	{
		char* tmplist = (char*)calloc(92, sizeof(char));
		Tools::SetBothGround(Colors::Black, Colors::White);
		for (int i = AttractionNow.DescribleList.BeginLine; i <= AttractionNow.DescribleList.EndLine; ++i)
		{
			Tools::ConsoleCursorGotoXY(18, 13 + i - AttractionNow.DescribleList.BeginLine);
			AttractionNow.DescribleList.Lists.get(tmplist, i);
			printf("\033(B%s", tmplist);
		}
	}

	void PressBack(Button Sender)
	{

	}

	void Exit(Button Sender)
	{
		exit(0);
	}

	void Main(AttractionInfo tmpinfo)
	{
		AttractionNow = tmpinfo;
		Refresh();
		ShowSingle();

		Button Buttons[3]{};
		Buttons[0].NewButton(0, 0, 7, 3, PressBack, 0, 0, 8);						//返回按钮
		Buttons[1].NewButton(111, 0, 7, 3, Exit, 111, 0, 8);						//退出按钮

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
						for (int i = 0; i < 3; ++i)
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
			}
		}
	}
}

namespace Attraction
{
	int PageNow;
	int MaxPage;
	int MaxRowInOnePage = 24;

	void ShowAttractions();

	void Refresh()
	{
		system("cls");
		Tools::HideCursor(false);
		Tools::ConsoleCursorGotoXY(0, 0);
		Tools::SetBothGround(Colors::Black, Colors::White);
		//			  0         1         2         3         4         5         6         7         8         9         0         1       
		//			  0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567
		printf("\033(0lqqqqqwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwqqqqqk\n");//0 0
		printf("\033(0x 返回x                                                景点信息                                                x 退出x\n");//1
		printf("\033(0tqqqqqvqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvqqqqqu\n");//2
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq   x\n");//3
		printf("\033(0x     序号x 名称                                                                                                     x\n");//4
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq   x\n");//5
		printf("\033(0x                                                                                                                    x\n");//6
		printf("\033(0x                                                                                                                    x\n");//7
		printf("\033(0x                                                                                                                    x\n");//8
		printf("\033(0x                                                                                                                    x\n");//9
		printf("\033(0x                                                                                                                    x\n");//0 1
		printf("\033(0x                                                                                                                    x\n");//1
		printf("\033(0x                                                                                                                    x\n");//2
		printf("\033(0x                                                                                                                    x\n");//3
		printf("\033(0x                                                                                                                    x\n");//4
		printf("\033(0x                                                                                                                    x\n");//5
		printf("\033(0x                                                                                                                    x\n");//6
		printf("\033(0x                                                                                                                    x\n");//7
		printf("\033(0x                                                                                                                    x\n");//8
		printf("\033(0x                                                                                                                    x\n");//9
		printf("\033(0x                                                                                                                    x\n");//0 2
		printf("\033(0x                                                                                                                    x\n");//1
		printf("\033(0x                                                                                                                    x\n");//2
		printf("\033(0x                                                                                                                    x\n");//3
		printf("\033(0x                                                                                                                    x\n");//4
		printf("\033(0x                                                                                                                    x\n");//5
		printf("\033(0x                                                                                                                    x\n");//6
		printf("\033(0x                                                                                                                    x\n");//7
		printf("\033(0x                                                                                                                    x\n");//8
		printf("\033(0x                                                                                                                    x\n");//9
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq   x\n");//0 3
		printf("\033(0x                                      \033(B|\033(0<<       <                  >       >>\033(B|\033(0                                      x\n");//1
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq   x\n");//2
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

	void PressPagesChange(Button Sender)
	{
		int x = Sender.x;
		int y = Sender.y;
		if (x >= 39 && x <= 43)
		{//第一页
			PageNow = 1;
		}
		else if (x >= 48 && x <= 52)
		{//上一页
			if (PageNow > 1)
			{
				PageNow -= 1;
			}
		}
		else if (x >= 67 && x <= 71)
		{//下一页
			if (PageNow < MaxPage)
			{
				PageNow += 1;
			}
		}
		else if (x >= 76 && x <= 80)
		{//最后一页
			PageNow = MaxPage;
		}
		else
		{
			return;
		}
		ShowAttractions();
		Sleep(2);
	}

	void Main()
	{
		Refresh();
		PageNow = 1;
		MaxPage = (Attractions.size + MaxRowInOnePage) / MaxRowInOnePage;
		ShowAttractions();

		AttractionInfo ShowInfo;

		Button Buttons[3]{};
		Buttons[0].NewButton(0, 0, 7, 3, PressBack, 0, 0, 8);						//返回按钮
		Buttons[1].NewButton(111, 0, 7, 3, Exit, 111, 0, 8);						//退出按钮
		Buttons[2].NewButton(39, 30, 41, 3, PressPagesChange, 39, 30, 42);			//页面转换按钮组

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
						if (x >= 4 && x <= 114 && y >= 6 && y <= 6 + MaxRowInOnePage - 1)
						{
							if ((PageNow - 1) * MaxRowInOnePage + y - 6 < (int)Attractions.size)
							{
								Attractions.get(&ShowInfo, ((size_t)PageNow - 1) * MaxRowInOnePage + y - 6);
								SingleAttraction::Main(ShowInfo);
								Refresh();
								ShowAttractions();
							}
						}
					}
					else																//单击
					{
						for (int i = 0; i < 3; ++i)
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
								case 2://翻页按钮组
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
			}
		}
	}

	void ShowAttractions()
	{
		AttractionInfo tmpAttraction;
		for (int i = (PageNow - 1) * MaxRowInOnePage; i < PageNow * MaxRowInOnePage; ++i)
		{
			if (i >= Attractions.size)
			{
				Tools::SetBothGround(Colors::Black, Colors::White);
			}
			else
			{
				Tools::SetBothGround(Colors::Black, ((i - (PageNow - 1) * MaxRowInOnePage) % 2 == 0 ? Colors::DarkGray : Colors::LightGray));
			}
			Tools::ConsoleCursorGotoXY(5, i - (PageNow - 1) * MaxRowInOnePage + 6);
			printf("                                                                                                             ");
			if (i < Attractions.size)
			{
				Attractions.get(&tmpAttraction, i);
				Tools::ConsoleCursorGotoXY(5, i - (PageNow - 1) * MaxRowInOnePage + 6);
				printf("\033(B%5d\033(0x\033(B %.100s", i + 1, tmpAttraction.name);
			}
		}
		Tools::ConsoleCursorGotoXY(51, 31);
		Tools::SetBothGround(Colors::Black, Colors::White);
		printf("%7d/%-8d", PageNow, MaxPage);
		Tools::ConsoleCursorGotoXY(0, 0);
	}
}

namespace _singleattraction_
{

}

namespace _attraction_
{
	ListGrid Listinfos;
	int SelectNum = 0;
	int MaxRowInOnePage = 24;

	void Init();
	void ShowLineinfo();

	void Refresh()
	{
		system("cls");
		Tools::HideCursor(false);
		Tools::ConsoleCursorGotoXY(0, 0);
		Tools::SetBothGround(Colors::Black, Colors::White);
		//■□
		//			  0         1         2         3         4         5         6         7         8         9         0         1       
		//			  0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567
		printf("\033(0lqqqqqwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwqqqqqk\n");//0 0
		printf("\033(0x 返回x                                                景点信息                                                x 退出x\n");//1
		printf("\033(0tqqqqqvqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvqqqqqu\n");//2
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq   x\n");//3
		printf("\033(0x    x □x 序号x 名称                                                                                                x\n");//4
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwq   x\n");//5
		printf("\033(0x                                                                                                               x↑  x\n");//6
		printf("\033(0x                                                                                                               xx   x\n");//7
		printf("\033(0x                                                                                                               xx   x\n");//8
		printf("\033(0x                                                                                                               xx   x\n");//9
		printf("\033(0x                                                                                                               xx   x\n");//0 1
		printf("\033(0x                                                                                                               xx   x\n");//1
		printf("\033(0x                                                                                                               xx   x\n");//2
		printf("\033(0x                                                                                                               xx   x\n");//3
		printf("\033(0x                                                                                                               xx   x\n");//4
		printf("\033(0x                                                                                                               xx   x\n");//5
		printf("\033(0x                                                                                                               xx   x\n");//6
		printf("\033(0x                                                                                                               xx   x\n");//7
		printf("\033(0x                                                                                                               xx   x\n");//8
		printf("\033(0x                                                                                                               xx   x\n");//9
		printf("\033(0x                                                                                                               xx   x\n");//0 2
		printf("\033(0x                                                                                                               xx   x\n");//1
		printf("\033(0x                                                                                                               xx   x\n");//2
		printf("\033(0x                                                                                                               xx   x\n");//3
		printf("\033(0x                                                                                                               xx   x\n");//4
		printf("\033(0x                                                                                                               xx   x\n");//5
		printf("\033(0x                                                                                                               xx   x\n");//6
		printf("\033(0x                                                                                                               xx   x\n");//7
		printf("\033(0x                                                                                                               xx   x\n");//8
		printf("\033(0x                                                                                                               x↓  x\n");//9
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvq   x\n");//0 3
		printf("\033(0x    x 删除x                                                                                                         x\n");//1
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq   x\n");//2
		printf("\033(0mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj\n");//3
		Tools::ConsoleCursorGotoXY(0, 0);
		printf("\033(B");
	}

	void PressSelect(Button Sender)
	{
		if (Sender.y == 5) return;
		if (Sender.y == 4)
		{
			if (SelectNum == Attractions.size)
			{//已全选设为全部未选
				AttractionInfo tmpinfo;
				for (int i = 0; i < Attractions.size; ++i)
				{
					Attractions.get(&tmpinfo, i);
					tmpinfo.id = abs(tmpinfo.id);
					Attractions.set(&tmpinfo, i);
				}
				Tools::ConsoleCursorGotoXY(7, 4);
				Tools::SetBothGround(Colors::Black, Colors::White);
				printf("□");
				SelectNum = 0;
			}
			else
			{//未全选设为全选
				AttractionInfo tmpinfo;
				for (int i = 0; i < Attractions.size; ++i)
				{
					Attractions.get(&tmpinfo, i);
					tmpinfo.id = -abs(tmpinfo.id);
					Attractions.set(&tmpinfo, i);
				}
				Tools::ConsoleCursorGotoXY(7, 4);
				Tools::SetBothGround(Colors::Black, Colors::White);
				printf("■");
				SelectNum = Attractions.size;
			}
			ShowLineinfo();
		}
		else if (Sender.y - 6 + Listinfos.BeginLine < Attractions.size)
		{
			AttractionInfo tmpinfo;
			Attractions.get(&tmpinfo, Sender.y - 6 + Listinfos.BeginLine);
			if (tmpinfo.id > 0)
			{
				SelectNum += 1;
				if (SelectNum == Attractions.size)
				{
					Tools::ConsoleCursorGotoXY(7, 4);
					Tools::SetBothGround(Colors::Black, Colors::White);
					printf("■");
				}
				Tools::ConsoleCursorGotoXY(7, Sender.y);
				Tools::SetBothGround(Colors::Black, (abs(tmpinfo.id) - 1) % 2 ? Colors::LightGray : Colors::DarkGray);
				printf("■");
			}
			else
			{
				SelectNum -= 1;
				Tools::ConsoleCursorGotoXY(7, 4);
				Tools::SetBothGround(Colors::Black, Colors::White);
				printf("□");
				Tools::ConsoleCursorGotoXY(7, Sender.y);
				Tools::SetBothGround(Colors::Black, (abs(tmpinfo.id) - 1) % 2 ? Colors::LightGray : Colors::DarkGray);
				printf("□");
			}
			tmpinfo.id *= -1;
			Attractions.set(&tmpinfo, Sender.y - 6 + Listinfos.BeginLine);
		}
		Sleep(100);
	}

	void PressDelete(Button Sender)
	{
		wchar_t Describle[] = L"是否删除选中的景点信息";
		wchar_t Title[] = L"警告";
		switch (MessageBox(GetConsoleWindow(), Describle, Title, MB_OKCANCEL))
		{
		case IDOK:
		{
			Vector newAttractions;
			newAttractions.newvector(sizeof(AttractionInfo));
			AttractionInfo tmpinfo;
			for (int i = 0; i < Attractions.size; ++i)
			{
				Attractions.get(&tmpinfo, i);
				if (tmpinfo.id > 0)
				{
					tmpinfo.id = newAttractions.size + 1;
					newAttractions.push_back(&tmpinfo);
				}
			}
			SelectNum = 0;
			Attractions = newAttractions;
			char Path[] = "Attractionsinfo.txt";
			Data::WriteAttraction(Attractions, Path);
			Listinfos.BeginLine = 0;
			Listinfos.EndLine = Tools::Min(MaxRowInOnePage - 1, Attractions.size - 1);
			Tools::SetBackGround(Colors::White);
			for (int i = 6; i <= 29; ++i)
			{
				Tools::ConsoleCursorGotoXY(4, i);
				printf("                                                                                                            ");
			}
			ShowLineinfo();
			break;
		}
		case IDCANCEL:
		{
			return;
		}
		}
	}
	// MessageBox用法及返回值
	//HWND hwnd = GetConsoleWindow();
	//switch (MessageBox(hwnd, L"描述", L"标题", MB_YESNOCANCEL))
	//{
	//case IDOK:
	//{
	//	break;
	//}
	//case IDCANCEL:
	//{
	//	break;
	//}
	//case IDABORT:
	//{
	//	break;
	//}
	//case IDRETRY:
	//{
	//	break;
	//}
	//case IDIGNORE:
	//{
	//	break;
	//}
	//case IDYES:
	//{
	//	break;
	//}
	//case IDNO:
	//{
	//	break;
	//}
	//}

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
		ShowLineinfo();

		AttractionInfo ShowInfo;

		int ButtonNum = 4;
		Button Buttons[4]{};
		Buttons[0].NewButton(0, 0, 7, 3, PressBack, 0, 0, 8);						//返回按钮
		Buttons[1].NewButton(111, 0, 7, 3, Exit, 111, 0, 8);						//退出按钮
		Buttons[2].NewButton(7, 4, 3, 26, PressSelect, 7, 4, 4);					//选择按钮
		Buttons[3].NewButton(5, 30, 8, 3, PressDelete, 5, 30, 9);					//删除按钮

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
						if (x >= 4 && x <= 114 && y >= 6 && y <= 6 + MaxRowInOnePage - 1)
						{

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
								case 2://选择按钮
								{
									Buttons[i].x = x;
									Buttons[i].y = y;
									Buttons[i].Click(Buttons[i]);
									break;
								}
								case 3://删除按钮
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
			}
		}
	}

	void Init()
	{
		Listinfos.BeginLine = 0;
		Listinfos.EndLine = Tools::Min(MaxRowInOnePage - 1, Attractions.size - 1);
	}

	void ShowLineinfo()
	{
		AttractionInfo tmpinfo;
		for (int i = Listinfos.BeginLine; i <= Listinfos.EndLine; ++i)
		{
			Attractions.get(&tmpinfo, i);
			Tools::ConsoleCursorGotoXY(5, 6 + i - Listinfos.BeginLine);
			Tools::SetBothGround(Colors::Black, abs(i) % 2 ? Colors::LightGray : Colors::DarkGray);
			printf("\033(0x %sx %04dx %-95.95s", tmpinfo.id > 0 ? "□" : "■", abs(tmpinfo.id), tmpinfo.name);
		}
	}

}