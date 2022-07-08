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
			Tools::ConsoleCursorGotoXY(18, 7);
			printf("\033(B%s", AttractionNow.Tags);
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
	Vector FindSource;

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
		printf("\033(0x                                                                                                                    x\n");//6
		printf("\033(0x                                                                                                                    x\n");//6
		printf("\033(0x                                                                                                                    x\n");//6
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq   x\n");//7
		printf("\033(0x                                      \033(B|\033(0<<       <                  >       >>\033(B|\033(0                                      x\n");//8
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq   x\n");//9
		printf("\033(0mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj\n");//3
		Tools::ConsoleCursorGotoXY(0, 0);
		printf("\033(B");
	}

	void EnterFind(Button Sender)
	{
		Vector Vbuffer;
		Vbuffer.newvector(sizeof(wchar_t));
		Vbuffer = FindSource;
		Tools::HideCursor(true);
		Tools::ConsoleCursorGotoXY(2, 31);
		Tools::Enter(Vbuffer, 30, 0x1111);
		Tools::HideCursor(false);
		setlocale(LC_ALL, "C");
		FindSource = Vbuffer;
	}

	void PressFind(Button Sender)
	{
		wchar_t wfindsource[50];
		char findsource[100];
		for (int i = 0; i < FindSource.size ; ++i)
		{
			FindSource.get(&wfindsource[i], i);
			if (wfindsource[i] == '\0')break;
		}
		Tools::Wchar2Char(findsource, wfindsource);
		AttractionInfo tmpinfo;
		for (int i = 0; i < Attractions.size; ++i)
		{
			Attractions.get(&tmpinfo, i);
			if (strstr(tmpinfo.name, findsource) != NULL)
			{

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
	AttractionInfo AttractionNow;

	void ShowSingle();
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
		printf("\033(0x                                         lqqqqqqqqqqk          lqqqqqqqqqqk                                         x\n");//9
		printf("\033(0x                                         x   保 存  x          x   重 置  x                                         x\n");//0 3
		printf("\033(0x                                         mqqqqqqqqqqj          mqqqqqqqqqqj                                         x\n");//1
		printf("\033(0mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj\n");//2
		Tools::ConsoleCursorGotoXY(0, 0);
	}

	void ChangeName(Button Sender)
	{
		wchar_t buffer[37] = { '\0' };
		Vector Vbuffer;
		Vbuffer.newvector(sizeof(wchar_t));
		Tools::Char2Wchar(buffer, AttractionNow.name);
		for (int i = 0; i < lstrlenW(buffer); ++i)
		{
			Vbuffer.push_back(&buffer[i]);
		}

		Tools::HideCursor(true);
		Tools::ConsoleCursorGotoXY(38, 4);
		Tools::Enter(Vbuffer, 36, 0x1111);
		Tools::HideCursor(false);
		setlocale(LC_ALL, "C");

		for (int i = 0; i < Vbuffer.size; ++i)
		{
			Vbuffer.get(&buffer[i], i);
		}
		buffer[Vbuffer.size] = '\0';
		Tools::Wchar2Char(AttractionNow.name, buffer);
	}

	void ChangeTags(Button Sender) 
	{
		wchar_t buffer[47] = { '\0' };
		Vector Vbuffer;
		Vbuffer.newvector(sizeof(wchar_t));
		Tools::Char2Wchar(buffer, AttractionNow.Tags);
		for (int i = 0; i < lstrlenW(buffer); ++i)
		{
			Vbuffer.push_back(&buffer[i]);
		}

		Tools::HideCursor(true);
		Tools::ConsoleCursorGotoXY(18, 7);
		Tools::Enter(Vbuffer, 36, 0x1111);
		Tools::HideCursor(false);
		setlocale(LC_ALL, "C");

		for (int i = 0; i < Vbuffer.size; ++i)
		{
			Vbuffer.get(&buffer[i], i);
		}
		buffer[Vbuffer.size] = '\0';
		Tools::Wchar2Char(AttractionNow.Tags, buffer);
	}

	void ChangePrice(Button Sender)
	{
		wchar_t buffer[47] = { '\0' };
		Vector Vbuffer;
		Vbuffer.newvector(sizeof(wchar_t));
		Tools::Char2Wchar(buffer, AttractionNow.Price);
		for (int i = 0; i < lstrlenW(buffer); ++i)
		{
			Vbuffer.push_back(&buffer[i]);
		}

		Tools::HideCursor(true);
		Tools::ConsoleCursorGotoXY(18, 10);
		Tools::Enter(Vbuffer, 46, 0x1111);
		Tools::HideCursor(false);
		setlocale(LC_ALL, "C");

		for (int i = 0; i < Vbuffer.size; ++i)
		{
			Vbuffer.get(&buffer[i], i);
		}
		buffer[Vbuffer.size] = '\0';
		Tools::Wchar2Char(AttractionNow.Price, buffer);
	}

	void ChangeDescrible(Button Sender)
	{

	}

	void PressSave(Button Sender)
	{
		wchar_t Describle[] = L"是否保存";
		wchar_t Title[] = L"提示";
		switch (MessageBox(GetConsoleWindow(), Describle, Title, MB_OKCANCEL))
		{
		case IDOK:
		{
			Attractions.set(&AttractionNow, (size_t)AttractionNow.id - 1);
			char path[] = "Attractionsinfo.txt";
			Data::WriteAttraction(Attractions, path);
			break;
		}
		case IDCANCEL:
		{
			return;
		}
		}
	}

	void PressRestart(Button Sender)
	{
		wchar_t Describle[] = L"是否重置";
		wchar_t Title[] = L"提示";
		switch (MessageBox(GetConsoleWindow(), Describle, Title, MB_OKCANCEL))
		{
		case IDOK:
		{
			Attractions.get(&AttractionNow, (size_t)AttractionNow.id - 1);
			ShowSingle();
			break;
		}
		case IDCANCEL:
		{
			return;
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

	void Main(AttractionInfo tmpinfo)
	{
		AttractionNow = tmpinfo;
		Refresh();
		ShowSingle();

		int ButtonNum = 8;
		Button Buttons[8]{};
		Buttons[0].NewButton(0, 0, 7, 3, PressBack, 0, 0, 8);						//返回按钮
		Buttons[1].NewButton(111, 0, 7, 3, Exit, 111, 0, 8);						//退出按钮
		Buttons[2].NewButton(38, 4, 74, 1, ChangeName, 38, 4, 74);					//更改名称按钮
		Buttons[3].NewButton(18, 7, 94, 1, ChangeTags, 18, 7, 94);					//更改类型按钮
		Buttons[4].NewButton(18, 10, 94, 1, ChangePrice, 18, 10, 94);				//更改价格按钮
		Buttons[5].NewButton(18, 13, 94, 15, ChangeDescrible, 18, 13, 94);			//更改描述按钮
		Buttons[6].NewButton(42, 29, 13, 3, PressSave, 42, 29, 14);					//保存按钮
		Buttons[7].NewButton(64, 29, 13, 3, PressRestart, 64, 29, 14);				//重置按钮

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
								case 0://返回按钮
								case 1://退出按钮
								{
									Buttons[i].Click(Buttons[i]);
									return;
								}
								case 2://更改名称按钮
								case 3://更改类型按钮
								case 4://更改价格按钮
								case 5://更改描述按钮
								{
									Buttons[i].x = x;
									Buttons[i].y = y;
									Buttons[i].Click(Buttons[i]);
									break;
								}
								case 6://保存按钮
								case 7://重置按钮
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

	void ShowSingle()
	{
		setlocale(LC_ALL, "C");

		Tools::SetBothGround(Colors::DarkGray, Colors::White);
		//景点编号
		{
			Tools::ConsoleCursorGotoXY(18, 4);
			printf("\033(B%04d", AttractionNow.id);
		}
		Tools::SetBothGround(Colors::Black, Colors::White);
		//景点名称
		{
			Tools::ConsoleCursorGotoXY(38, 4);
			printf("                                                                         ");
			Tools::ConsoleCursorGotoXY(38, 4);
			printf("\033(B%s", AttractionNow.name);
		}
		//景点类型
		{
			Tools::ConsoleCursorGotoXY(18, 7);
			printf("                                                                                             ");
			Tools::ConsoleCursorGotoXY(18, 7);
			printf("\033(B%s", AttractionNow.Tags);
		}
		//景点票价
		{
			Tools::ConsoleCursorGotoXY(18, 10);
			printf("                                                                                             ");
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
		else if ((size_t)Sender.y - 6 + Listinfos.BeginLine < Attractions.size)
		{
			AttractionInfo tmpinfo;
			Attractions.get(&tmpinfo, (size_t)Sender.y - 6 + Listinfos.BeginLine);
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
			Attractions.set(&tmpinfo, (size_t)Sender.y - 6 + Listinfos.BeginLine);
		}
		Sleep(100);
	}

	void PressDelete(Button Sender)
	{
		if (SelectNum == 0)
		{
			MessageBox(GetConsoleWindow(), L"当前无选中景点", L"提示", MB_OK); 
			return;
		}
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
	//MessageBox(GetConsoleWindow(), L"描述", L"标题", MB_YESNOCANCEL)

	//	按钮参数				含义
	//	MB_OK					默认值。有一个确认按钮在里面。
	//	MB_YESNO				有是和否在里面。
	//	MB_ABORTRETRYIGNORE		有Abort(放弃)，Retry(重试)和Ignore(跳过)
	//	MB_YESNOCANCEL			消息框含有三个按钮 : Yes，No和Cancel
	//	MB_RETRYCANCEL			有Retry(重试)和Cancel(取消)
	//	MB_OKCANCEL				消息框含有两个按钮 : OK和Cancel
	 
	//	参数					含义
	//	MB_ICONEXCLAMATION		一个惊叹号出现在消息框
	//	MB_ICONWARNING			一个惊叹号出现在消息框
	//	MB_ICONINFORMATION		一个圆圈中小写字母i组成的图标出现在消息框
	//	MB_ICONASTERISK			一个圆圈中小写字母i组成的图标出现在消息框
	//	MB_ICONQUESTION			一个问题标记图标出现在消息框
	//	MB_ICONSTOP				一个停止消息图标出现在消息框
	//	MB_ICONERROR			一个停止消息图标出现在消息框
	//	MB_ICONHAND				一个停止消息图标出现在消息框
	// 
	//ID		值		选择了……
	//IDOK		(1)		OK
	//IDCANCEL	(2)		CANCEL
	//IDABORT	(3)		ABORT
	//IDRETRY	(4)		RETRY
	//IDIGNORE	(5)		IGNORE
	//IDYES		(6)		YES
	//IDNO		(7)		NO

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
							if (y - 6 + Listinfos.BeginLine < (int)Attractions.size)
							{
								Attractions.get(&ShowInfo, (size_t)y - 6 + Listinfos.BeginLine);
								_singleattraction_::Main(ShowInfo);
								Refresh();
								ShowLineinfo();
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
				else if (Mouse.Event.MouseEvent.dwEventFlags == MOUSE_WHEELED)
				{
					x = Mouse.Event.MouseEvent.dwMousePosition.X;
					y = Mouse.Event.MouseEvent.dwMousePosition.Y;
					if (x >= 6 && x <= 112 && y >= 6 && y <= 29)
					{
						if ((Mouse.Event.MouseEvent.dwButtonState) >> 24 > 0)//滚轮向用户方向滚
						{
							if (Listinfos.EndLine + 1 < (int)Attractions.size)
							{
								Listinfos.BeginLine += 1;
								Listinfos.EndLine += 1;
								ShowLineinfo();
							}
						}
						else												 //滚轮向远离用户方向滚
						{
							if (Listinfos.BeginLine)
							{
								Listinfos.BeginLine -= 1;
								Listinfos.EndLine -= 1;
								ShowLineinfo();
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