#pragma once

#ifdef HASHES_USE_HASHLITTLE
#else

#include "murmur3/MurmurHash3.h"
#include "MurmurHash3c.h"

typedef ConstStringMM3 ConstString;

inline uint64_t HashBuffer64(const void* buffer, size_t len)
{
	uint64_t out[2];
	MurmurHash3_x64_128(buffer, len, 0, out);
	return out[0];
}

#endif


uint64_t HashString64(const char* str)	{ return HashBuffer64(str, strlen(str)); }

uint32_t HashBuffer32(const void* buffer, size_t len) { return HashBuffer64(buffer, len) & 0xFFFFFFFF; }
uint16_t HashBuffer16(const void* buffer, size_t len) { return HashBuffer64(buffer, len) & 0xFFFF; }

#define CHASH(_W)	(ConstString(_W, sizeof(_W)-1).hash())
