#include "Global.h"

//———————————————————————————
//********************一些全局变量**********************
//———————————————————————————
Charinfo CharinfoNow;					//当前登录的账号
Vector Charinfos;						//全部账号
Vector Attractions;						//全部景点信息
Vector Hotels;							//全部酒店信息
Vector Transits;						//全部公交信息
//———————————————————————————

int main()
{
	//进行包括全屏在内的初始化控制台操作
	Tools::full_screen();

	//进入主界面
	Main::Main();
}