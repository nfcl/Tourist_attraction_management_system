#ifndef _GLOBAL_h
#define _GLOBAL_h

//����������������
//*****��׼��*****
//����������������
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <conio.h>

//����������������
//***һЩ�ṹ��***
//����������������
struct Vector
{
	/// <summary>
	/// ʵ��Ԫ������
	/// </summary>
	size_t size;
	/// <summary>
	/// ���Ԫ������
	/// </summary>
	size_t capacity;
	/// <summary>
	/// Ԫ�ش�С���ֽ�Ϊ��λ��
	/// </summary>
	size_t typesize;
	/// <summary>
	/// ���ݴ�С
	/// </summary>
	size_t grownum;
	/// <summary>
	/// �洢Ԫ��
	/// </summary>
	void* elements;
	void Memset(void* Value, int start, int end)
	{
		for (int i = start; i <= end; ++i)
		{
			set(Value, i);
		}
	}
	/// <summary>
	/// ��ʼ��
	/// </summary>
	/// <param name="TypeSize">���ʹ�С(�ֽ�)</param>
	/// <param name="ElementNum">��ʼ��СĬ��50</param>
	/// <param name="GrowNum">ÿ���������ӵĴ�СĬ��30</param>
	void newvector(size_t TypeSize, size_t ElementNum = 50, size_t GrowNum = 30)
	{
		size = 0;
		grownum = GrowNum;
		capacity = ElementNum;
		typesize = TypeSize;
		elements = malloc(typesize * ElementNum);
	}
	/// <summary>
	/// ��β����һ��Ԫ��
	/// </summary>
	/// <param name="Element">����Ԫ��ֵ</param>
	/// <param name="num">����Ԫ������</param>
	void push_back(void* Element, size_t num = 1)
	{
		if (size >= capacity)
		{
			void* more_elements = realloc(elements, typesize * (capacity + grownum));
			if (more_elements != NULL)
			{
				elements = more_elements;
				capacity += grownum;
			}
		}
		void* tmp = (char*)elements + size * typesize;
		memcpy(tmp, Element, typesize);
		++size;
	}
	/// <summary>
	/// �׳���βԪ��
	/// </summary>
	void pop_back()
	{
		if (size)
			--size;
	}
	/// <summary>
	/// ɾ��ָ��λ�õ�Ԫ��
	/// </summary>
	void remove(size_t position)
	{
		if (position >= 0 && position < size)
		{
			void* copyAddr, * stickAddr;
			copyAddr = (char*)elements + (position + 1) * typesize;
			stickAddr = (char*)elements + position * typesize;
			memcpy(stickAddr, copyAddr, (size - position - 1) * typesize);
			size -= 1;
		}
	}
	/// <summary>
	/// ��ñ�ͷԪ��
	/// </summary>
	/// <param name="Element">���ڴ���Ԫ��ֵ</param>
	void front(void* Element)
	{
		if (size)
		{
			void* destAddr = (char*)elements;
			memcpy(Element, destAddr, typesize);
		}
	}
	/// <summary>
	/// ��ñ�βԪ��
	/// </summary>
	/// <param name="Element">���ڴ���Ԫ��ֵ</param>
	void back(void* Element)
	{
		if (size)
		{
			void* destAddr = (char*)elements + (size - 1) * typesize;
			memcpy(Element, destAddr, typesize);
		}
	}
	/// <summary>
	/// �����һλ�õ�Ԫ��ֵ
	/// </summary>
	/// <param name="Element">���ڴ���Ԫ��ֵ</param>
	/// <param name="pos">ָ��λ��(�±�)</param>
	void get(void* Element, size_t pos)
	{
		if (size)
		{
			void* destAddr = (char*)elements + pos * typesize;
			memcpy(Element, destAddr, typesize);
		}
	}
	/// <summary>
	/// �ı���һλ�õ�Ԫ��ֵ
	/// </summary>
	/// <param name="Element">�ı���Ԫ��ֵ</param>
	/// <param name="pos">ָ��λ��(�±�)</param>
	void set(void* Element, size_t pos)
	{
		if (pos >= 0 && pos < size)
		{
			void* destAddr = (char*)elements + pos * typesize;
			memcpy(destAddr, Element, typesize);
		}
	}
	/// <summary>
	/// ��ձ�Ԫ��
	/// </summary>
	void clear()
	{
		size = 0;
	}
	/// <summary>
	/// ƥ��������������Ԫ�ش�С���
	/// </summary>
	void fit()
	{
		capacity = size;
		void* newelements = realloc(elements, size * typesize);
		if (newelements)
			elements = newelements;
	}
	/// <summary>
	/// <para/>��ָ��λ�ò���Ԫ��
	/// <para/>���ڱ�β����
	/// </summary>
	/// <param name="Element">�����Ԫ��ֵ</param>
	/// <param name="position">ָ��λ��</param>
	void insert(void* Element, int position)
	{
		if (size >= capacity)
		{
			void* new_elements = realloc(elements, typesize * (capacity + grownum));
			if (new_elements)
			{
				elements = new_elements;
			}
		}
		void* copyAddr, * stickAddr;
		copyAddr = (char*)elements + position * typesize;
		stickAddr = (char*)elements + ((size_t)position + 1) * typesize;
		memcpy(stickAddr, copyAddr, (1 + size - position) * typesize);

		copyAddr = Element;
		stickAddr = (char*)elements + position * typesize;
		memcpy(stickAddr, copyAddr, typesize);

		++size;
	}
};

struct Position
{
	int X;
	int Y;
	int Width;
	int Height;
};

struct ListGrid
{
	Vector Lists;
	int BeginLine;
	int EndLine;

	void Init(Vector Describle,int MaxLength, int MaxRows)
	{
		Lists.newvector(sizeof(char) * MaxLength);
		char* tmpchars = (char*)calloc(MaxLength, sizeof(char));
		if (tmpchars == NULL)return;
		memset(tmpchars, '\0', MaxLength);
		int i, j;
		char tmpchar;
		i = 0;//describle�е��±�
		j = 0;//tmpchars�е��±�
		while (i < Describle.size)
		{
			Describle.get(&tmpchar, i);
			if (tmpchar > 255 || tmpchar < 0)
			{
				if (j >= MaxLength - 2)
				{
					j = 0;
					Lists.push_back(tmpchars);
					memset(tmpchars, '\0', MaxLength);
				}
				tmpchars[j] = tmpchar;
				j += 1;
				i += 1;
				Describle.get(&tmpchar, i);
				tmpchars[j] = tmpchar;
				j += 1;
				i += 1;
			}
			else
			{
				if (j >= MaxLength - 1)
				{
					j = 0;
					Lists.push_back(tmpchars);
					memset(tmpchars, '\0', MaxLength);
				}
				tmpchars[j] = tmpchar;
				j += 1;
				i += 1;
			}
		}
		if (strlen(tmpchars))
		{
			Lists.push_back(tmpchars);
		}
		BeginLine = 0;
		EndLine = min(MaxRows - 1,(int)Lists.size - 1);
	}
};

struct Button
{
	/// <summary>
	/// ��ʾ�Ĵ�С
	/// </summary>
	Position UIPos;
	/// <summary>
	/// ��ť��Ӧ����Ĵ�С
	/// </summary>
	Position RpseArea;
	/// <summary>
	/// ��ť������ʱ��������
	/// </summary>
	int x;
	/// <summary>
	/// ��ť������ʱ��������
	/// </summary>
	int y;
	/// <summary>
	/// ��ť��Ӧ�¼�
	/// </summary>
	void(*Click)(Button Sender);

	void NewButton(int x, int y, int width, int height, int Rx = -1, int Ry = -1, int Rw = -1, int Rh = -1)
	{
		UIPos = { x, y, width, height };
		RpseArea = { Rx == -1 ? x : Rx,Ry == -1 ? y : Ry,Rw == -1 ? width : Rw,Rh == -1 ? height : Rh };
	}

	void NewButton(int x, int y, int width, int height, void(*click)(Button Sender), int Rx = -1, int Ry = -1, int Rw = -1, int Rh = -1)
	{
		UIPos = { x, y, width, height };
		RpseArea = { Rx == -1 ? x : Rx,Ry == -1 ? y : Ry,Rw == -1 ? width : Rw,Rh == -1 ? height : Rh };
		Click = click;
	}

	bool Is_Click(int x, int y)
	{
		if ((x >= RpseArea.X && x <= RpseArea.X + RpseArea.Width - 1) && (y >= RpseArea.Y && y <= RpseArea.Y + RpseArea.Height - 1))
			return true;
		return false;
	}
};

struct Charinfo
{
	enum class People
	{
		Vip,			//��Ա   ע����û�����Ҫ��¼�ſ��Խ��룬��������ȫ������
		Adminstrator,	//����Ա ϵͳ�����ߣ������ϵͳ���û�����Ϣ����һϵ�в��� 
		NotLogin		//δ��¼
	};

	int id;				//���

	char Name[31];		//����
	char Account[31];	//�˺�
	char Password[31];	//����
	//�Ϊ15�����ַ�����ת��Ϊchar�����Ϊ30

	People People;		//��Ա����

	void Init()
	{
		memset(Name, '\0', 31);
		memset(Account, '\0', 16);
		memset(Password, '\0', 16);
		People = People::NotLogin;
	}

	void SetName(char* name, int length)
	{
		for (int i = 0; i < min(length, 31); ++i)
		{
			Name[i] = name[i];
		}
	}
	void SetAccount(char* account, int length)
	{
		for (int i = 0; i < min(length, 16); ++i)
		{
			Account[i] = account[i];
		}
	}
	void SetPassword(char* password, int length)
	{
		for (int i = 0; i < min(length, 16); ++i)
		{
			Password[i] = password[i];
		}
	}
};

struct AttractionInfo
{
	int id;					//�������
	char name[50];			//��������
	char Tags[50];			//��������
	char Price[50];			//�۸�����
	Vector Describle;		//��������
	ListGrid DescribleList;	//������������

	void wrap(int MaxLength,int MaxRow)
	{
		DescribleList.Init(Describle, MaxLength, MaxRow);
	}

	void SetDescrible(char* describle, int length)
	{
		Describle.newvector(sizeof(char));
		for (int i = 0; i < length; ++i)
		{
			Describle.push_back(&describle[i]);
		}
	}
};

struct HotelInfo
{

	int id;
	char Name[50];
	int Level;
	Vector HotelDescrible;
	ListGrid DescribleList;
	char Datagridline[59];
	Vector Location;
	ListGrid LocationList;
	char Telephone[50];

	void Init()
	{
		memset(Name, '\0', 50);
		Level = -1;
		HotelDescrible.newvector(sizeof(char));
		Location.newvector(sizeof(char));
		memset(Telephone, '\0', 50);
	}
};

struct TransitInfo
{
	int id;
	char Name[100];
	char Price[100];
	char Time[100];
	char LineInfo[200];
	Vector Route;

	void Init()
	{
		memset(Name, '\0', sizeof(char[100]));
		memset(Price, '\0', sizeof(char[100]));
		memset(Time, '\0', sizeof(char[100]));
		memset(LineInfo, '\0', sizeof(char[200]));
		Route.newvector(sizeof(char[40]));
	}
};

//����������������
//**һЩȫ�ֱ���**
//����������������
extern Charinfo CharinfoNow;			//��ǰ��¼���˺�
extern Vector Charinfos;				//ȫ���˺�
extern Vector Attractions;				//ȫ��������Ϣ
extern Vector Hotels;					//ȫ���Ƶ���Ϣ
extern Vector Transits;					//ȫ��������Ϣ

//����������������
//****�Լ��Ŀ�****
//����������������
#include "Color.h"
#include "Tools.h"
#include "Data.h"
#include "Main.h"
#include "Registe.h"
#include "Login.h"
#include "Vip.h"
#include "Adminstrator.h"
#include "Attraction.h"
#include "Hotel.h"
#include "Transit.h"
#include "User.h"

//����������������������������
//*Ҫ��˳����벻Ȼ���������*
//����������������������������

#endif

//��������������������������������������������������������������
// DEC��������ת��
//��������������������������������������������������������������
//Hex	ASCII	DEC ��������
//0x6a	  j	         ��
// 
//0x6b	  k	         ��
// 
//0x6c	  l	         ��
// 
//0x6d	  m	         ��
// 
//0x6e	  n	         ��
// 
//0x71	  q	         ��
// 
//0x74	  t	         ��
// 
//0x75	  u	         ��
// 
//0x76	  v	         ��
// 
//0x77	  w	         ��
// 
//0x78	  x	         ��
//��������������������������������������������������������������
// ���ڴ�ӡ���ֵ�һЩҪ��
// wchar_t��ӡʱ��ǰһ��Ҫ����setlocale(LC_ALL, "zh_CN.UTF-8");
//			�뿪��ӡ��Χǰ����setlocale(LC_ALL, "C");
//��������������������������������������������������������������