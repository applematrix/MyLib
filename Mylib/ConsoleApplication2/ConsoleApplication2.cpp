// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "DataSource.h"
#include "FileSource.h"


int _tmain(int argc, _TCHAR* argv[])
{
	sp<DataSource> pDataSource = new FileSource("F:\\test.txt");
	uint8 buffer[10] = {0};
	pDataSource->readAt(0, 3, buffer);
	return 0;
}

