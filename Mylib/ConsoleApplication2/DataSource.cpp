#include "stdafx.h"
#include "DataSource.h"
#include <stdio.h>

namespace hdz{

	DataSource::DataSource()
	{
		printf("DataSource Constructor!\n");
	}

	DataSource::DataSource(const char* url)
	{
		printf("DataSource Constructor with url!\n");
	}

	DataSource::~DataSource()
	{
		printf("DataSource Destructor!\n");
	}

	uint64 DataSource::size()
	{
		return 0;
	}

	uint64 DataSource::readAt(uint64 offset, uint64 size, uint8* buffer)
	{
		return 0;
	}

}//end namespace