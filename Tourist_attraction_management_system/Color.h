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
/// ��ɫ	
/// </summary>
namespace Colors
{
	const Color Black = { 0x00,0x00,0x00 };					//1		��ɫ
	const Color Navy = { 0x00,0x00,0x80 };					//2		����
	const Color DarkBlue = { 0x00,0x00,0x8B };				//3		����
	const Color MediumBlue = { 0x00,0x00,0xCD };			//4		����
	const Color Blue = { 0x00,0x00,0xFF };					//5		��ɫ
	const Color DarkGreen = { 0x00,0x64,0x00 };				//6		����
	const Color Green = { 0x00,0x80,0x00 };					//7		������	
	const Color Teal = { 0x00,0x80,0x80 };					//8		Ѽ����	
	const Color DarkCyan = { 0x00,0x8B,0x8B };				//9		����	
	const Color DeepSkyBlue = { 0x00,0xBF,0xFF };			//10	������	
	const Color DarkTurquoise = { 0x00,0xCE,0xD1 };			//11	����ʯ��	
	const Color MediumSpringGreen = { 0x00,0xFA,0x9A };		//12	������	
	const Color Lime = { 0x00,0xFF,0x00 };					//13	��ɫ	
	const Color SpringGreen = { 0x00,0xFF,0x7F };			//14	����	
	const Color Cyan = { 0x00,0xFF,0xFF };					//15	��ɫ	
	const Color MidNightBlue = { 0x19,0x19,0x70 };			//16	��ҹ��		
	const Color DodgerBlue = { 0x1E,0x90,0xFF };			//17	����		
	const Color DarkRed = { 0x8B,0x00,0x00 };				//50	���	
	const Color DarkMagenta = { 0x8B,0x00,0x8B };			//51	��Ʒ��	
	const Color DarkGray = { 0xA9,0xA9,0xA9 };				//62	����	
	const Color LightGray = { 0xD3,0xD3,0xD3 };				//79	����	
	const Color Red = { 0xFF,0x00,0x0 };					//109	��ɫ		
	const Color White = { 0xFF,0xFF,0xFF };					//138	��ɫ		
}

#endif // !_COLOR_h
