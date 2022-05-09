#ifndef _TOOLS_h
#define _TOOLS_h

#include "Global.h"

namespace Tools
{
	/// <summary>
	/// <para/>�ַ���ת����
	/// <para/>������ڲ��Ϸ��ַ����ص����Ϸ��ַ�ǰ�ĺϷ�����
	/// </summary>
	/// <param name="GoalChars">Ҫת�����ַ���</param>
	/// <param name="length">Ҫת�����ַ�������</param>
	/// <returns></returns>
	int CharToInt(char* GoalChars, int length);

	/// <summary>
	/// �����������εĽϴ�ֵ
	/// </summary>
	/// <param name="a">����a</param>
	/// <param name="b">����b</param>
	/// <returns></returns>
	int Max(int a, int b);

	/// <summary>
	/// �����������εĽ�Сֵ
	/// </summary>
	/// <param name="a">����a</param>
	/// <param name="b">����b</param>
	/// <returns></returns>
	int Min(int a, int b);

	/// <summary>
	/// ���ؿ���̨���
	/// </summary>
	/// <param name="IsHide">TrueΪ��ʾ FalseΪ����</param>
	void HideCursor(bool IsHide);

	/// <summary>
	/// �ƶ����ƹ����x,y
	/// </summary>
	/// <param name="x">������</param>
	/// <param name="y">������</param>
	void ConsoleCursorGotoXY(int x, int y);

	/// <summary>
	/// ��ÿ���̨���λ��
	/// </summary>
	/// <returns>COORD�ṹ�����������X��������Y</returns>
	COORD GetConsoleCursorPosition();

	/// <summary>
	/// ��ȡ������Ϣ���������ֵ
	/// </summary>
	/// <returns>int(1~254)</returns>
	int ReadKeyboard();

	/// <summary>
	/// ȫ��
	/// </summary>
	void full_screen();

	/// <summary>
	/// ���ñ���ɫ
	/// </summary>
	/// <param name="background"></param>
	void SetBackGround(Color background);

	/// <summary>
	/// ����ǰ��ɫ
	/// </summary>
	/// <param name="forgeground"></param>
	void SetForgeGround(Color forgeground);

	/// <summary>
	/// ����ǰ��ɫ�ͱ���ɫ
	/// </summary>
	/// <param name="forgeground"></param>
	/// <param name="background"></param>
	void SetBothGround(Color forgeground, Color background);
	/// <summary>
	/// char*תwchar_t*
	/// </summary>
	/// <param name="wcharStr"></param>
	/// <param name="charStr"></param>
	/// <returns></returns>
	int Char2Wchar(wchar_t* wcharStr, const char* charStr);

	/// <summary>
	/// �����¼���ȡ
	/// </summary>
	/// <returns></returns>
	INPUT_RECORD EventInput();

	/// <summary>
	/// <para/>ģ���������
	/// <para/>��Ч����֧�֣�
	/// <para/>����				��unicode"��������"(0x4E00-0x9FA5)��
	/// <para/>����				��ascii '0' - '9'��
	/// <para/>��Сд��ĸ		��ascii 'A' - 'Z' 'a' - 'z'��
	/// <para/>���ܼ�֧�֣�
	/// <para/>Backspace		��ascii 8��
	/// <para/>Delete			��ascii���ַ� 224 83��
	/// <para/>��������			��ascii���ַ� 224 (72|80|75|77)��
	/// </summary>
	/// <param name="Maxlength">������볤��</param>
	/// <param name="BreakValue">��ϰ���ֵ</param>
	/// <param name="Mode">����ģʽ�ӵ�λ����λ�ֱ�ΪСд��ĸ����д��ĸ�����֣�����</param>
	/// <returns>����һ��wchar_t��Vector</returns>
	void Enter(Vector& tmpBuffer, int Maxlength, int Mode = 0x1111, int BreakValue = 13);

	int Wchar2Char(char* charStr, const wchar_t* wcharStr);
}
#endif // !_TOOLS_h