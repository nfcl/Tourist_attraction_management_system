#ifndef _GLOBAL_h
#define _GLOBAL_h

//————————
//*****标准库*****
//————————
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <conio.h>

//————————
//***一些结构体***
//————————
struct Vector
{
	/// <summary>
	/// 实际元素数量
	/// </summary>
	size_t size;
	/// <summary>
	/// 最大元素数量
	/// </summary>
	size_t capacity;
	/// <summary>
	/// 元素大小（字节为单位）
	/// </summary>
	size_t typesize;
	/// <summary>
	/// 扩容大小
	/// </summary>
	size_t grownum;
	/// <summary>
	/// 存储元素
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
	/// 初始化
	/// </summary>
	/// <param name="TypeSize">类型大小(字节)</param>
	/// <param name="ElementNum">初始大小默认50</param>
	/// <param name="GrowNum">每次满后增加的大小默认30</param>
	void newvector(size_t TypeSize, size_t ElementNum = 50, size_t GrowNum = 30)
	{
		size = 0;
		grownum = GrowNum;
		capacity = ElementNum;
		typesize = TypeSize;
		elements = malloc(typesize * ElementNum);
	}
	/// <summary>
	/// 表尾增加一个元素
	/// </summary>
	/// <param name="Element">新增元素值</param>
	/// <param name="num">新增元素数量</param>
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
	/// 抛出表尾元素
	/// </summary>
	void pop_back()
	{
		if (size)
			--size;
	}
	/// <summary>
	/// 删除指定位置的元素
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
	/// 获得表头元素
	/// </summary>
	/// <param name="Element">用于传出元素值</param>
	void front(void* Element)
	{
		if (size)
		{
			void* destAddr = (char*)elements;
			memcpy(Element, destAddr, typesize);
		}
	}
	/// <summary>
	/// 获得表尾元素
	/// </summary>
	/// <param name="Element">用于传出元素值</param>
	void back(void* Element)
	{
		if (size)
		{
			void* destAddr = (char*)elements + (size - 1) * typesize;
			memcpy(Element, destAddr, typesize);
		}
	}
	/// <summary>
	/// 获得任一位置的元素值
	/// </summary>
	/// <param name="Element">用于传出元素值</param>
	/// <param name="pos">指定位置(下标)</param>
	void get(void* Element, size_t pos)
	{
		if (size)
		{
			void* destAddr = (char*)elements + pos * typesize;
			memcpy(Element, destAddr, typesize);
		}
	}
	/// <summary>
	/// 改变任一位置的元素值
	/// </summary>
	/// <param name="Element">改变后的元素值</param>
	/// <param name="pos">指定位置(下标)</param>
	void set(void* Element, size_t pos)
	{
		if (pos >= 0 && pos < size)
		{
			void* destAddr = (char*)elements + pos * typesize;
			memcpy(destAddr, Element, typesize);
		}
	}
	/// <summary>
	/// 清空表元素
	/// </summary>
	void clear()
	{
		size = 0;
	}
	/// <summary>
	/// 匹配表的容量和现有元素大小相近
	/// </summary>
	void fit()
	{
		capacity = size;
		void* newelements = realloc(elements, size * typesize);
		if (newelements)
			elements = newelements;
	}
	/// <summary>
	/// <para/>在指定位置插入元素
	/// <para/>可在表尾插入
	/// </summary>
	/// <param name="Element">插入的元素值</param>
	/// <param name="position">指定位置</param>
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
		i = 0;//describle中的下标
		j = 0;//tmpchars中的下标
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
	/// 显示的大小
	/// </summary>
	Position UIPos;
	/// <summary>
	/// 按钮响应区域的大小
	/// </summary>
	Position RpseArea;
	/// <summary>
	/// 按钮被按下时的列坐标
	/// </summary>
	int x;
	/// <summary>
	/// 按钮被按下时的行坐标
	/// </summary>
	int y;
	/// <summary>
	/// 按钮响应事件
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
		Vip,			//会员   注册的用户，需要登录才可以进入，可以享受全部服务
		Adminstrator,	//管理员 系统管理者，负责对系统和用户的信息进行一系列操作 
		NotLogin		//未登录
	};

	int id;				//序号

	char Name[31];		//名字
	char Account[31];	//账号
	char Password[31];	//密码
	//最长为15个宽字符所以转换为char最长可能为30

	People People;		//人员类型

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
	int id;					//景点序号
	char name[50];			//景点名字
	char Tags[50];			//景点类型
	char Price[50];			//价格描述
	Vector Describle;		//景点描述
	ListGrid DescribleList;	//景点描述换行

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

//————————
//**一些全局变量**
//————————
extern Charinfo CharinfoNow;			//当前登录的账号
extern Vector Charinfos;				//全部账号
extern Vector Attractions;				//全部景点信息
extern Vector Hotels;					//全部酒店信息
extern Vector Transits;					//全部公交信息

//————————
//****自己的库****
//————————
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

//——————————————
//*要按顺序编译不然会出大问题*
//——————————————

#endif

//———————————————————————————————
// DEC线条绘制转义
//———————————————————————————————
//Hex	ASCII	DEC 线条绘制
//0x6a	  j	         ┘
// 
//0x6b	  k	         ┐
// 
//0x6c	  l	         ┌
// 
//0x6d	  m	         └
// 
//0x6e	  n	         ┼
// 
//0x71	  q	         ─
// 
//0x74	  t	         ├
// 
//0x75	  u	         ┤
// 
//0x76	  v	         ┴
// 
//0x77	  w	         ┬
// 
//0x78	  x	         │
//———————————————————————————————
// 关于打印文字的一些要点
// wchar_t打印时块前一定要加上setlocale(LC_ALL, "zh_CN.UTF-8");
//			离开打印范围前加上setlocale(LC_ALL, "C");
//———————————————————————————————