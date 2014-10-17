#include "stdafx.h"
#include "FileSource.h"

namespace hdz{

	FileSource::FileSource()
	{
#ifdef __WIN32__
		printf("windows 32 plantform!");
#endif
		m_pFile = NULL;
		m_szUrl = NULL;
		m_fileSize = 0;
	}

	FileSource::FileSource(const char* url)
	{
		if (url != NULL)
		{
			m_szUrl = _strdup(url);
			errno_t err = fopen_s(&m_pFile, url, "rb");
			if (err != 0)
			{
				//error;
			}
		}
		m_fileSize = 0;
	}

	FileSource::~FileSource()
	{
		if (m_szUrl != NULL){
			free(m_szUrl);
		}
		if (m_pFile != NULL){
			fclose(m_pFile);
		}
	}

	uint64 FileSource::size()
	{
		if (m_pFile == NULL){
			return 0;
		}
		if (m_fileSize == 0){
			long curOffset = ftell(m_pFile);
			fseek(m_pFile, 0, SEEK_END);
			m_fileSize = ftell(m_pFile);
			fseek(m_pFile, curOffset, SEEK_SET);
		}
		return m_fileSize;
	}

	uint64 FileSource::readAt(uint64 offset, uint64 size, uint8* buffer)
	{
		if (m_pFile == NULL || buffer == NULL){
			return 0;
		}
		if (offset > this->size()){
			return 0;
		}
		long curOffset = ftell(m_pFile);
		fseek(m_pFile, offset, SEEK_SET);
		uint64 read = (uint64)fread(buffer, 1, size, m_pFile);
		fseek(m_pFile, curOffset, SEEK_SET);
		return read;
	}

}//end namespace