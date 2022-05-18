#include "Global.h"

namespace User
{

}

namespace _user_
{
	ListGrid Listinfos;
	int SelectNum = 0;
	int MaxRowInOnePage = 24;
	Charinfo ShowInfo;

	void Init();
	void ShowLineinfo();
	void ShowSingleInfo();

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
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq                                                             x\n");//3
		printf("\033(0x    x ��x ���x  ��Ա x ����                                                                                        x\n");//4
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwq                                                             x\n");//5
		printf("\033(0x                                                     x��            lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk       x\n");//6
		printf("\033(0x                                                     xx       ���ƣ�x                                       x       x\n");//7
		printf("\033(0x                                                     xx             mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj       x\n");//8
		printf("\033(0x                                                     xx                                                             x\n");//9
		printf("\033(0x                                                     xx             lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk       x\n");//0 1
		printf("\033(0x                                                     xx       �˺ţ�x                                       x       x\n");//1
		printf("\033(0x                                                     xx             mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj       x\n");//2
		printf("\033(0x                                                     xx                                                             x\n");//3
		printf("\033(0x                                                     xx             lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk       x\n");//4
		printf("\033(0x                                                     xx       ���룺x                                       x       x\n");//5
		printf("\033(0x                                                     xx             mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj       x\n");//6
		printf("\033(0x                                                     xx                                                             x\n");//7
		printf("\033(0x                                                     xx                   lqqqqqqqqqqqqqqqqqqqqqqqqqqqk             x\n");//8
		printf("\033(0x                                                     xx                   x   ����Ա        ��������  x             x\n");//9
		printf("\033(0x                                                     xx                   mqqqqqqqqqqqqqqqqqqqqqqqqqqqj             x\n");//0 2
		printf("\033(0x                                                     xx                                                             x\n");//1
		printf("\033(0x                                                     xx                             lqqqqqqqk                       x\n");//2
		printf("\033(0x                                                     xx                             x  ���� x                       x\n");//3
		printf("\033(0x                                                     xx                             mqqqqqqqj                       x\n");//4
		printf("\033(0x                                                     xx                                                             x\n");//8
		printf("\033(0x                                                     xx                             lqqqqqqqk                       x\n");//5
		printf("\033(0x                                                     xx                             x  ���� x                       x\n");//6
		printf("\033(0x                                                     xx                             mqqqqqqqj                       x\n");//7
		printf("\033(0x                                                     x��                                                            x\n");//9
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvq                                                             x\n");//0 3
		printf("\033(0x    x ɾ��x                                                                                                         x\n");//1
		printf("\033(0x   qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq                                                             x\n");//2
		printf("\033(0mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj\n");//3
		Tools::ConsoleCursorGotoXY(0, 0);
		printf("\033(B");
	}

	void ChangeName(Button Sender)
	{
		Tools::SetBothGround(Colors::Black, Colors::White);
		wchar_t buffer[16] = { '\0' };
		Vector Vbuffer;
		Vbuffer.newvector(sizeof(wchar_t));
		Tools::Char2Wchar(buffer, ShowInfo.Name);
		for (int i = 0; i < lstrlenW(buffer); ++i)
		{
			Vbuffer.push_back(&buffer[i]);
		}

		Tools::HideCursor(true);
		Tools::ConsoleCursorGotoXY(71, 7);
		Tools::Enter(Vbuffer, 15, 0x1111);
		Tools::HideCursor(false);
		setlocale(LC_ALL, "C");

		for (int i = 0; i < Vbuffer.size; ++i)
		{
			Vbuffer.get(&buffer[i], i);
		}
		buffer[Vbuffer.size] = '\0';
		Tools::Wchar2Char(ShowInfo.Name, buffer);
	}

	void ChangeAccount(Button Sender)
	{
		Tools::SetBothGround(Colors::Black, Colors::White);
		wchar_t buffer[16] = { '\0' };
		Vector Vbuffer;
		Vbuffer.newvector(sizeof(wchar_t));
		Tools::Char2Wchar(buffer, ShowInfo.Account);
		for (int i = 0; i < lstrlenW(buffer); ++i)
		{
			Vbuffer.push_back(&buffer[i]);
		}

		Tools::HideCursor(true);
		Tools::ConsoleCursorGotoXY(71, 11);
		Tools::Enter(Vbuffer, 15, 0x0111);
		Tools::HideCursor(false);
		setlocale(LC_ALL, "C");

		for (int i = 0; i < Vbuffer.size; ++i)
		{
			Vbuffer.get(&buffer[i], i);
		}
		buffer[Vbuffer.size] = '\0';
		Tools::Wchar2Char(ShowInfo.Account, buffer);
	}

	void ChangePassword(Button Sender)
	{
		Tools::SetBothGround(Colors::Black, Colors::White);
		wchar_t buffer[16] = { '\0' };
		Vector Vbuffer;
		Vbuffer.newvector(sizeof(wchar_t));
		Tools::Char2Wchar(buffer, ShowInfo.Password);
		for (int i = 0; i < lstrlenW(buffer); ++i)
		{
			Vbuffer.push_back(&buffer[i]);
		}

		Tools::HideCursor(true);
		Tools::ConsoleCursorGotoXY(71, 15);
		Tools::Enter(Vbuffer, 15, 0x0111);
		Tools::HideCursor(false);
		setlocale(LC_ALL, "C");

		for (int i = 0; i < Vbuffer.size; ++i)
		{
			Vbuffer.get(&buffer[i], i);
		}
		buffer[Vbuffer.size] = '\0';
		Tools::Wchar2Char(ShowInfo.Password, buffer);
	}

	void ChangePeople(Button Sender)
	{
		if (Sender.x >= 79 && Sender.x <= 85 && Sender.y >= 19 && Sender.y <= 19)
		{
			ShowInfo.People = Charinfo::People::Vip;

		}
		else if (Sender.x >= 93 && Sender.x <= 101 && Sender.y >= 19 && Sender.y <= 19)
		{
			ShowInfo.People = Charinfo::People::Adminstrator;
		}

		Tools::SetBothGround(Colors::Black, Colors::White);
		Tools::ConsoleCursorGotoXY(79, 19);
		printf("%s", ShowInfo.People == Charinfo::People::Vip ? "��" : "��");
		Tools::ConsoleCursorGotoXY(93, 19);
		printf("%s", ShowInfo.People == Charinfo::People::Adminstrator ? "��" : "��");
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

	void PressSave(Button Sender)
	{
		wchar_t Describle[] = L"�Ƿ񱣴�";
		wchar_t Title[] = L"����";
		switch (MessageBox(GetConsoleWindow(), Describle, Title, MB_OKCANCEL))
		{
		case IDOK:
		{
			Charinfos.set(&ShowInfo, (size_t)ShowInfo.id - 1);
			char Path[] = "Charinfos.txt";
			Data::CharinfoWrite(Charinfos, Path);
			ShowLineinfo();
			break;
		}
		case IDCANCEL:
		{
			break;
		}
		}
	}

	void PressResert(Button Sender)
	{
		wchar_t Describle[] = L"�Ƿ�����";
		wchar_t Title[] = L"����";
		switch (MessageBox(GetConsoleWindow(), Describle, Title, MB_OKCANCEL))
		{
		case IDOK:
		{
			Charinfos.get(&ShowInfo, (size_t)ShowInfo.id - 1);
			ShowSingleInfo();
			break;
		}
		case IDCANCEL:
		{
			break;
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
		ShowLineinfo();


		const int ButtonNum = 10;
		Button Buttons[ButtonNum]{};
		Buttons[0].NewButton(0, 0, 7, 3, PressBack, 0, 0, 8);						//���ذ�ť
		Buttons[1].NewButton(111, 0, 7, 3, Exit, 111, 0, 8);						//�˳���ť
		Buttons[2].NewButton(7, 4, 3, 26, PressSelect, 7, 4, 4);					//ѡ��ť
		Buttons[3].NewButton(5, 30, 8, 3, PressDelete, 5, 30, 9);					//ɾ����ť
		Buttons[4].NewButton(71, 7, 39, 1, ChangeName, 71, 7, 40);					//���Ƹ��İ�ť
		Buttons[5].NewButton(71, 11, 39, 1, ChangeAccount, 71, 11, 40);				//�˺Ÿ��İ�ť
		Buttons[6].NewButton(71, 15, 39, 1, ChangePassword, 71, 15, 40);			//������İ�ť
		Buttons[7].NewButton(79, 19, 23, 1, ChangePeople, 79, 19, 24);				//��Ա���İ�ť
		Buttons[8].NewButton(85, 22, 10, 3, PressSave, 85, 22, 11);					//���水ť
		Buttons[9].NewButton(85, 25, 10, 3, PressResert, 85, 25, 11);				//���ð�ť

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
						if (x >= 4 && x <= 54 && y >= 6 && y <= 6 + MaxRowInOnePage - 1)
						{
							if (y - 6 + Listinfos.BeginLine < (int)Attractions.size)
							{
								Charinfos.get(&ShowInfo, (size_t)y - 6 + Listinfos.BeginLine);
								ShowSingleInfo();
							}
						}
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
								case 7://��Ա���İ�ť
								{
									Buttons[i].x = x;
									Buttons[i].y = y;
									Buttons[i].Click(Buttons[i]);
									break;
								}
								case 3://ɾ����ť
								case 4://���Ƹ��İ�ť
								case 5://�˺Ÿ��İ�ť
								case 6://������İ�ť
								case 8://���水ť
								case 9://���ð�ť
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
							if (Listinfos.EndLine + 1 < (int)Charinfos.size)
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
			printf("\033(0x %sx %04dx %6sx \033(B%-29.29s", tmpinfo.id > 0 ? "��" : "��", abs(tmpinfo.id), tmpinfo.People == Charinfo::People::Adminstrator ? "����Ա" : "��Ա", tmpinfo.Name);
		}
	}

	void ShowSingleInfo()
	{
		printf("\033(B");
		Tools::SetBothGround(Colors::Black, Colors::White);
		{//����
			Tools::ConsoleCursorGotoXY(71, 7);
			printf("                                      ");
			Tools::ConsoleCursorGotoXY(71, 7);
			printf("%s", ShowInfo.Name);
		}
		{//�˺�
			Tools::ConsoleCursorGotoXY(71, 11);
			printf("                                      ");
			Tools::ConsoleCursorGotoXY(71, 11);
			printf("%s", ShowInfo.Account);
		}
		{//����
			Tools::ConsoleCursorGotoXY(71, 15);
			printf("                                      ");
			Tools::ConsoleCursorGotoXY(71, 15);
			printf("%s", ShowInfo.Password);
		}
		{//��Ա
			Tools::ConsoleCursorGotoXY(79, 19);
			printf("%s", ShowInfo.People == Charinfo::People::Vip ? "��" : "��");
			Tools::ConsoleCursorGotoXY(93, 19);
			printf("%s", ShowInfo.People == Charinfo::People::Adminstrator ? "��" : "��");
		}
	}
}