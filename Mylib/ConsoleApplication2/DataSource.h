#pragma once
#include "sp.h"
#include "DataType.h"
#include "RefBase.h"

namespace hdz{

	class DataSource : public RefBase{
	public:
		DataSource();
		DataSource(const char* url);
		virtual ~DataSource();
		virtual uint64 size();
		virtual uint64 readAt(uint64 offset, uint64 size, uint8* buffer);
	};

}//end namespace