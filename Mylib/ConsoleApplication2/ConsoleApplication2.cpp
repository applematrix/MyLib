// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
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

