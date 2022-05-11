#include "Global.h"

namespace Data
{
	Vector CharinfoRead(char* Path)
	{
		int CharinfoNum;
		Vector Result;
		Result.newvector(sizeof(Charinfo));
		Charinfo tmpinfo;
		FILE* fp = NULL;
		fopen_s(&fp, Path, "r");
		if (fp == 0)return Result;
		fscanf_s(fp, "%d\n", &CharinfoNum);
		for (int i = 0; i < CharinfoNum; ++i)
		{
			fscanf_s(fp, "%s", tmpinfo.Name, 31);
			fscanf_s(fp, "%s", tmpinfo.Account, 31);
			fscanf_s(fp, "%s", tmpinfo.Password, 31	);
			fscanf_s(fp, "%d", &tmpinfo.People);
			Result.push_back(&tmpinfo);
		}
		fclose(fp);
		return Result;
	}

	void CharinfoWrite(Vector Charinfos, char* Path)
	{
		Charinfo tmpinfo;
		FILE* fp = NULL;
		fopen_s(&fp, Path, "w");
		if (fp == 0)return;
		fprintf(fp, "%d\n", (int)Charinfos.size);
		for (int i = 0; i < (int)Charinfos.size; ++i)
		{
			Charinfos.get(&tmpinfo, i);
			fprintf(fp, "%s\n", tmpinfo.Name);
			fprintf(fp, "%s\n", tmpinfo.Account);
			fprintf(fp, "%s\n", tmpinfo.Password);
			fprintf(fp, "%d\n", (int)tmpinfo.People);
		}
		fclose(fp);
	}

	Vector AttractionsRead(char* Path)
	{
		AttractionInfo tmpAttraction;
		int AttractionNum, tmpint;
		Vector Result;
		Result.newvector(sizeof(AttractionInfo));
		FILE* fp;
		fopen_s(&fp, Path, "r");
		if (fp == 0) return Result;
		fscanf_s(fp, "%d", &AttractionNum);
		for (int i = 0; i < AttractionNum; ++i)
		{
			tmpAttraction.id = i + 1;
			fscanf_s(fp, "%s", tmpAttraction.name, 50);
			fscanf_s(fp, "%d", &tmpint);
			tmpAttraction.Tags.newvector(sizeof(char[10]));
			for (int i = 0; i < tmpint; ++i)
			{
				char tmpchar[10];
				fscanf_s(fp, "%s", tmpchar, 10);
				tmpAttraction.Tags.push_back(&tmpchar);
			}
			fscanf_s(fp, "%s", tmpAttraction.Price, 50);
			char tmpchar[200] = { '\0' };
			fgets(tmpchar, 200, fp);
			fgets(tmpchar, 200, fp);
			tmpAttraction.SetDescrible(tmpchar, strlen(tmpchar));
			Result.push_back(&tmpAttraction);
		}
		fclose(fp);
		return Result;
	}

	void WriteAttraction(Vector AttractionInfos, char* Path)
	{
		FILE* fp;
		fopen_s(&fp, Path, "w");
		if (fp == 0)return;
		AttractionInfo tmpinfo;
		char tmptag[10];
		char tmpdescrible;
		fprintf(fp, "%d\n", AttractionInfos.size);
		for (int i = 0; i < AttractionInfos.size; ++i)
		{
			AttractionInfos.get(&tmpinfo, i);
			fprintf(fp, "%s\n", tmpinfo.name);
			fprintf(fp, "%d", tmpinfo.Tags.size);
			for (int j = 0; j < tmpinfo.Tags.size; ++j)
			{
				tmpinfo.Tags.get(&tmptag, j);
				fprintf(fp, " %s", tmptag);
			}
			fprintf(fp, "\n%s\n", tmpinfo.Price);
			for (int j = 0; j < tmpinfo.Describle.size; ++j)
			{
				tmpinfo.Describle.get(&tmpdescrible, j);
				fprintf(fp, "%c", tmpdescrible);
			}
			fprintf(fp, "\n");
		}
		fclose(fp);
	}

	Vector ReadHotelInfo(char* Path)
	{
		char inttochar[][3] = { "零","一","二","三","四","五","六","七","八","九" };
		Vector Hotels;
		Hotels.newvector(sizeof(HotelInfo));
		FILE* fp = NULL;
		fopen_s(&fp, Path, "r");
		if (fp == 0)return Hotels;
		HotelInfo tmphotel;
		char tmpchar;
		int n;
		fscanf_s(fp, "%d", &n);
		for (int i = 0; i < n; ++i)
		{
			tmphotel.Init();
			tmphotel.id = i;
			if (i)
				fgetc(fp);
			fscanf_s(fp, "%s", tmphotel.Name, 50);
			fscanf_s(fp, "%d\n", &tmphotel.Level);
			while (1)
			{
				fscanf_s(fp, "%c", &tmpchar, 1);
				if (tmpchar == '\n')
				{
					tmpchar = '\0';
					tmphotel.HotelDescrible.push_back(&tmpchar);
					break;
				}
				tmphotel.HotelDescrible.push_back(&tmpchar);
			}
			tmphotel.DescribleList.Init(tmphotel.HotelDescrible, 34, 12); 
			while (1)
			{
				fscanf_s(fp, "%c", &tmpchar, 1);
				if (tmpchar == '\n')
				{
					tmpchar = '\0';
					tmphotel.Location.push_back(&tmpchar);
					break;
				}
				tmphotel.Location.push_back(&tmpchar);
			}
			tmphotel.LocationList.Init(tmphotel.Location, 34, 1);
			fscanf_s(fp, "%s", tmphotel.Telephone, 50);
			memset(tmphotel.Datagridline, '\0', 59);
			sprintf_s(tmphotel.Datagridline, "%04dx %-39sx %-s星级  ", i + 1, tmphotel.Name, inttochar[tmphotel.Level]);
			Hotels.push_back(&tmphotel);
		}
		fclose(fp);
		return Hotels;
	}

	Vector ReadTransitInfo(char* Path)
	{
		Vector Transits;
		Transits.newvector(sizeof(TransitInfo));
		FILE* fp;
		fopen_s(&fp, Path, "r");
		if (fp == 0)return Transits;
		int n;
		int routenum;
		char tmproute[40];
		fscanf_s(fp, "%d", &n);
		TransitInfo tmpinfo;
		for (int i = 0; i < n; ++i)
		{
			fgetc(fp);
			fgetc(fp);
			tmpinfo.Init();
			tmpinfo.id = i + 1;
			sprintf_s(tmpinfo.LineInfo, "%04d", i + 1);

			fgets(tmpinfo.Name, 100, fp);
			tmpinfo.Name[strlen(tmpinfo.Name) - 1] = '\0';
			sprintf_s(tmpinfo.LineInfo + 4, 150, "x %-38.38s", tmpinfo.Name);

			fgets(tmpinfo.Price, 100, fp);
			tmpinfo.Price[strlen(tmpinfo.Price) - 1] = '\0';

			fgets(tmpinfo.Time, 100, fp);
			tmpinfo.Time[strlen(tmpinfo.Time) - 1] = '\0';

			fscanf_s(fp, " %d", &routenum);
			for (int j = 0; j < routenum; ++j)
			{
				memset(tmproute, '\0', 40);
				fscanf_s(fp, "%s", tmproute, 40);
				tmpinfo.Route.push_back(&tmproute);
				if (j == 0)
				{
					sprintf_s(tmpinfo.LineInfo + 43, 100, "x %-29.29s", tmproute);
				}
				else if (j == routenum - 1)
				{
					sprintf_s(tmpinfo.LineInfo + 74, 100, "x %-29.29s", tmproute);
				}
			}
			Transits.push_back(&tmpinfo);
		}
		fclose(fp);
		return Transits;
	}
}