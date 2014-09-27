#pragma once
#include <Windows.h>

class RefBase
{
public:
	RefBase()
	{
		m_refCount = 0;
	}
	~RefBase()
	{

	}

	void addRef()
	{
		m_refCount++;
	}

	int decRef()
	{
		return --m_refCount;
	}

private:
	int m_refCount;
};