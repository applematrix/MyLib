// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataSource.h"


int _tmain(int argc, _TCHAR* argv[])
{
	{
		sp<DataSource> pOther;
		{
			sp<DataSource> pDataSource = new DataSource();
			{
				pOther = pDataSource;
			}
		}
	}
	return 0;
}

