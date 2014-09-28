#pragma once

#include "DataSource.h"

class FileSource :public DataSource
{
public:
	FileSource();
	FileSource(const char* url);
	~FileSource();
	virtual uint64 size();
	virtual uint64 readAt(uint64 offset, uint64 size, uint8* buffer);
private:
	char* m_szUrl;
	FILE* m_pFile;
	uint64 m_fileSize;
};