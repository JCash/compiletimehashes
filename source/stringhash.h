#pragma once

#include "hash.h"

#if defined(DEBUG)
class StringHash
{
public:
	constexpr StringHash(uint64_t hash, const char* str) : m_Hash(hash), m_String(str) {}
	constexpr operator uint64_t () const { return m_Hash; }
	constexpr operator const char* () const { return m_String; }
private:
	uint64_t m_Hash;
	const char* const m_String;
};

constexpr StringHash operator "" _shash(const char* str, size_t len)
{
	return StringHash( ConstString(str, len).hash(), str );
}

#else

typedef uint64_t StringHash;

constexpr StringHash operator "" _shash(const char* str, size_t len)
{
	return ConstString(str, len).hash();
}

#endif


constexpr uint64_t ConstHashString(const char* str, size_t len)	  { return ConstString(str, len).hash(); }
