#ifndef _DATA_h
#define _DATA_h

#include "Global.h"

namespace Data
{
	/// <summary>
	/// 人员信息读取
	/// </summary>
	/// <param name="Path"></param>
	/// <returns></returns>
	Vector CharinfoRead(char* Path);
	
	/// <summary>
	/// 人员信息写入
	/// </summary>
	/// <param name="Charinfos"></param>
	/// <param name="Path"></param>
	void CharinfoWrite(Vector Charinfos, char* Path);

	/// <summary>
	/// 景点信息读取
	/// </summary>
	/// <param name="Path"></param>
	/// <returns></returns>
	Vector AttractionsRead(char* Path);

	/// <summary>
	/// 景点信息写入
	/// </summary>
	/// <param name="AttractionInfos"></param>
	/// <param name="Path"></param>
	void WriteAttraction(Vector AttractionInfos, char* Path);

	Vector ReadHotelInfo(char* Path);

	Vector ReadTransitInfo(char* Path);
}

#endif // !_DATA_h
