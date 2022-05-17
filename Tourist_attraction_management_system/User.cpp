#include "Global.h"

namespace User
{

}

namespace _user_
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
		//����
		//			  0         1         2         3         4         5         6         7         8         9         0         1       
		//			  0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567
		printf("\033(0lqqqqqwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwqqqqqk\n");//0 0
		printf("\033(0x ����x                                              �û���Ϣ����                                              x �˳�x\n");//1
		printf("\033(0tqqqqqvqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvqqqqqu\n");//2
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq   x\n");//3
		printf("\033(0x    x ��x ���x  ��Ա x ����                                                                                        x\n");//4
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwq   x\n");//5
		printf("\033(0x                                                                                                               x��  x\n");//6
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
		printf("\033(0x                                                                                                               x��  x\n");//9
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvq   x\n");//0 3
		printf("\033(0x    x ɾ��x                                                                                                         x\n");//1
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
			if (SelectNum == Charinfos.size)
			{//��ȫѡ��Ϊȫ��δѡ
				Charinfo tmpinfo;
				for (int i = 0; i < Charinfos.size; ++i)
				{
					Charinfos.get(&tmpinfo, i);
					tmpinfo.id = abs(tmpinfo.id);
					Charinfos.set(&tmpinfo, i);
				}
				Tools::ConsoleCursorGotoXY(7, 4);
				Tools::SetBothGround(Colors::Black, Colors::White);
				printf("��");
				SelectNum = 0;
			}
			else
			{//δȫѡ��Ϊȫѡ
				Charinfo tmpinfo;
				for (int i = 0; i < Charinfos.size; ++i)
				{
					Charinfos.get(&tmpinfo, i);
					tmpinfo.id = -abs(tmpinfo.id);
					Charinfos.set(&tmpinfo, i);
				}
				Tools::ConsoleCursorGotoXY(7, 4);
				Tools::SetBothGround(Colors::Black, Colors::White);
				printf("��");
				SelectNum = Charinfos.size;
			}
			ShowLineinfo();
		}
		else if ((size_t)Sender.y - 6 + Listinfos.BeginLine < Charinfos.size)
		{
			Charinfo tmpinfo;
			Charinfos.get(&tmpinfo, (size_t)Sender.y - 6 + Listinfos.BeginLine);
			if (tmpinfo.id > 0)
			{
				SelectNum += 1;
				if (SelectNum == Charinfos.size)
				{
					Tools::ConsoleCursorGotoXY(7, 4);
					Tools::SetBothGround(Colors::Black, Colors::White);
					printf("��");
				}
				Tools::ConsoleCursorGotoXY(7, Sender.y);
				Tools::SetBothGround(Colors::Black, (abs(tmpinfo.id) - 1) % 2 ? Colors::LightGray : Colors::DarkGray);
				printf("��");
			}
			else
			{
				SelectNum -= 1;
				Tools::ConsoleCursorGotoXY(7, 4);
				Tools::SetBothGround(Colors::Black, Colors::White);
				printf("��");
				Tools::ConsoleCursorGotoXY(7, Sender.y);
				Tools::SetBothGround(Colors::Black, (abs(tmpinfo.id) - 1) % 2 ? Colors::LightGray : Colors::DarkGray);
				printf("��");
			}
			tmpinfo.id *= -1;
			Charinfos.set(&tmpinfo, (size_t)Sender.y - 6 + Listinfos.BeginLine);
		}
		Sleep(100);
	}

	void PressDelete(Button Sender)
	{
		wchar_t Describle[] = L"�Ƿ�ɾ��ѡ�еľ�����Ϣ";
		wchar_t Title[] = L"����";
		switch (MessageBox(GetConsoleWindow(), Describle, Title, MB_OKCANCEL))
		{
		case IDOK:
		{
			Vector newCharinfos;
			newCharinfos.newvector(sizeof(Charinfo));
			Charinfo tmpinfo;
			for (int i = 0; i < Charinfos.size; ++i)
			{
				Charinfos.get(&tmpinfo, i);
				if (tmpinfo.id > 0)
				{
					tmpinfo.id = newCharinfos.size + 1;
					newCharinfos.push_back(&tmpinfo);
				}
			}
			SelectNum = 0;
			Charinfos = newCharinfos;
			char Path[] = "Charinfos.txt";
			Data::CharinfoWrite(Charinfos, Path);
			Listinfos.BeginLine = 0;
			Listinfos.EndLine = Tools::Min(MaxRowInOnePage - 1, Charinfos.size - 1);
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
	//MessageBox(GetConsoleWindow(), L"����", L"����", MB_YESNOCANCEL)

	//	��ť����				����
	//	MB_OK					Ĭ��ֵ����һ��ȷ�ϰ�ť�����档
	//	MB_YESNO				���Ǻͷ������档
	//	MB_ABORTRETRYIGNORE		��Abort(����)��Retry(����)��Ignore(����)
	//	MB_YESNOCANCEL			��Ϣ����������ť : Yes��No��Cancel
	//	MB_RETRYCANCEL			��Retry(����)��Cancel(ȡ��)
	//	MB_OKCANCEL				��Ϣ����������ť : OK��Cancel

	//	����					����
	//	MB_ICONEXCLAMATION		һ����̾�ų�������Ϣ��
	//	MB_ICONWARNING			һ����̾�ų�������Ϣ��
	//	MB_ICONINFORMATION		һ��ԲȦ��Сд��ĸi��ɵ�ͼ���������Ϣ��
	//	MB_ICONASTERISK			һ��ԲȦ��Сд��ĸi��ɵ�ͼ���������Ϣ��
	//	MB_ICONQUESTION			һ��������ͼ���������Ϣ��
	//	MB_ICONSTOP				һ��ֹͣ��Ϣͼ���������Ϣ��
	//	MB_ICONERROR			һ��ֹͣ��Ϣͼ���������Ϣ��
	//	MB_ICONHAND				һ��ֹͣ��Ϣͼ���������Ϣ��
	// 
	//ID		ֵ		ѡ���ˡ���
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

		const int ButtonNum = 4;
		Button Buttons[ButtonNum]{};
		Buttons[0].NewButton(0, 0, 7, 3, PressBack, 0, 0, 8);						//���ذ�ť
		Buttons[1].NewButton(111, 0, 7, 3, Exit, 111, 0, 8);						//�˳���ť
		Buttons[2].NewButton(7, 4, 3, 26, PressSelect, 7, 4, 4);					//ѡ��ť
		Buttons[3].NewButton(5, 30, 8, 3, PressDelete, 5, 30, 9);					//ɾ����ť

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
						/*if (x >= 4 && x <= 114 && y >= 6 && y <= 6 + MaxRowInOnePage - 1)
						{
							if (y - 6 + Listinfos.BeginLine < (int)Attractions.size)
							{
								Attractions.get(&ShowInfo, (size_t)y - 6 + Listinfos.BeginLine);
								_singleattraction_::Main(ShowInfo);
								Refresh();
								ShowLineinfo();
							}
						}*/
					}
					else																//����
					{
						for (int i = 0; i < ButtonNum; ++i)
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
								case 2://ѡ��ť
								{
									Buttons[i].x = x;
									Buttons[i].y = y;
									Buttons[i].Click(Buttons[i]);
									break;
								}
								case 3://ɾ����ť
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
						if ((Mouse.Event.MouseEvent.dwButtonState) >> 24 > 0)//�������û������
						{
							if (Listinfos.EndLine + 1 < (int)Attractions.size)
							{
								Listinfos.BeginLine += 1;
								Listinfos.EndLine += 1;
								ShowLineinfo();
							}
						}
						else												 //������Զ���û������
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
		Listinfos.EndLine = Tools::Min(MaxRowInOnePage - 1, Charinfos.size - 1);
	}

	void ShowLineinfo()
	{
		Charinfo tmpinfo;
		for (int i = Listinfos.BeginLine; i <= Listinfos.EndLine; ++i)
		{
			Charinfos.get(&tmpinfo, i);
			Tools::ConsoleCursorGotoXY(5, 6 + i - Listinfos.BeginLine);
			Tools::SetBothGround(Colors::Black, abs(i) % 2 ? Colors::LightGray : Colors::DarkGray);
			printf("\033(0x %sx %04dx %6sx \033(B%-87.87s", tmpinfo.id > 0 ? "��" : "��", abs(tmpinfo.id), tmpinfo.People == Charinfo::People::Adminstrator ? "����Ա" : "��Ա", tmpinfo.Name);
		}
	}
}