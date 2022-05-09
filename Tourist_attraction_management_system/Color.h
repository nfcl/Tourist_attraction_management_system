#ifndef _COLOR_h
#define _COLOR_h

struct Color
{
	short R;
	short G;
	short B;

	void Set(int r, int g, int b)
	{
		R = r;
		G = g;
		B = b;
	}
};

/// <summary>
/// 颜色	
/// </summary>
namespace Colors
{
	const Color Black = { 0x00,0x00,0x00 };					//1		黑色
	const Color Navy = { 0x00,0x00,0x80 };					//2		藏青
	const Color DarkBlue = { 0x00,0x00,0x8B };				//3		深蓝
	const Color MediumBlue = { 0x00,0x00,0xCD };			//4		中蓝
	const Color Blue = { 0x00,0x00,0xFF };					//5		蓝色
	const Color DarkGreen = { 0x00,0x64,0x00 };				//6		深绿
	const Color Green = { 0x00,0x80,0x00 };					//7		调和绿	
	const Color Teal = { 0x00,0x80,0x80 };					//8		鸭翅绿	
	const Color DarkCyan = { 0x00,0x8B,0x8B };				//9		深青	
	const Color DeepSkyBlue = { 0x00,0xBF,0xFF };			//10	深天蓝	
	const Color DarkTurquoise = { 0x00,0xCE,0xD1 };			//11	深松石绿	
	const Color MediumSpringGreen = { 0x00,0xFA,0x9A };		//12	中嫩绿	
	const Color Lime = { 0x00,0xFF,0x00 };					//13	绿色	
	const Color SpringGreen = { 0x00,0xFF,0x7F };			//14	春绿	
	const Color Cyan = { 0x00,0xFF,0xFF };					//15	青色	
	const Color MidNightBlue = { 0x19,0x19,0x70 };			//16	午夜蓝		
	const Color DodgerBlue = { 0x1E,0x90,0xFF };			//17	湖蓝		
	const Color DarkRed = { 0x8B,0x00,0x00 };				//50	深红	
	const Color DarkMagenta = { 0x8B,0x00,0x8B };			//51	深品红	
	const Color DarkGray = { 0xA9,0xA9,0xA9 };				//62	暗灰	
	const Color LightGray = { 0xD3,0xD3,0xD3 };				//79	亮灰	
	const Color Red = { 0xFF,0x00,0x0 };					//109	红色		
	const Color White = { 0xFF,0xFF,0xFF };					//138	白色		
}

#endif // !_COLOR_h
