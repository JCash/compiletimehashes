
#ifndef THASHLITTLE_H
#define THASHLITTLE_H

#include <stdio.h>

#if defined(_WIN32) || defined(_WIN64)
	#define ALWAYSINLINE __forceinline
#else // GCC + CLANG
	#define ALWAYSINLINE inline __attribute__((always_inline))
#endif


#define rot(x,k) (((x)<<(k)) ^ ((x)>>(32-(k))))

#define final(a,b,c) \
{ \
  c ^= b; c -= rot(b,14); \
  a ^= c; a -= rot(c,11); \
  b ^= a; b -= rot(a,25); \
  c ^= b; c -= rot(b,16); \
  a ^= c; a -= rot(c,4);  \
  b ^= a; b -= rot(a,14); \
  c ^= b; c -= rot(b,24); \
}

#define mix(a,b,c) \
{ \
  a -= c;  a ^= rot(c, 4);  c += b; \
  b -= a;  b ^= rot(a, 6);  a += c; \
  c -= b;  c ^= rot(b, 8);  b += a; \
  a -= c;  a ^= rot(c,16);  c += b; \
  b -= a;  b ^= rot(a,19);  a += c; \
  c -= b;  c ^= rot(b, 4);  b += a; \
}

ALWAYSINLINE static void HashBlock( const uint8_t* k, uint32_t& a, uint32_t& b, uint32_t& c )
{
	a += k[0];
	a += ((uint32_t)k[1])<<8;
	a += ((uint32_t)k[2])<<16;
	a += ((uint32_t)k[3])<<24;
	b += k[4];
	b += ((uint32_t)k[5])<<8;
	b += ((uint32_t)k[6])<<16;
	b += ((uint32_t)k[7])<<24;
	c += k[8];
	c += ((uint32_t)k[9])<<8;
	c += ((uint32_t)k[10])<<16;
	c += ((uint32_t)k[11])<<24;
	mix(a,b,c);
}

template<size_t N, size_t OFFSET, size_t I>
struct THashStringBlock
{
	ALWAYSINLINE static void Hash( const char (&key)[N+1], uint32_t& a, uint32_t& b, uint32_t& c )
	{
	    HashBlock((const uint8_t *) &key[OFFSET], a, b, c);
	    THashStringBlock<N, OFFSET+12, I-1>::Hash( key, a, b, c );
	}
};

template<size_t N, size_t OFFSET>
struct THashStringBlock<N, OFFSET, 0>
{
	ALWAYSINLINE static void Hash( const char (&key)[N+1], uint32_t& a, uint32_t& b, uint32_t& c )
	{
	}
};

template<size_t N>
struct THashString
{
	ALWAYSINLINE static uint32_t Hash( const char (&key)[N+1], uint32_t& a, uint32_t& b, uint32_t& c )
	{
	    THashStringBlock<N, 0, (N-1)/12>::Hash( key, a, b, c );

    	const size_t length = N - ((N-1)/12) * 12;
	    const uint8_t* k = (const uint8_t *) &key[N-length];

	    /*-------------------------------- last block: affect all 32 bits of (c) */
	    switch(length)                   /* all the case statements fall through */
	    {
	    case 12: c+=((uint32_t)k[11])<<24;
	    case 11: c+=((uint32_t)k[10])<<16;
	    case 10: c+=((uint32_t)k[9])<<8;
	    case 9 : c+=k[8];
	    case 8 : b+=((uint32_t)k[7])<<24;
	    case 7 : b+=((uint32_t)k[6])<<16;
	    case 6 : b+=((uint32_t)k[5])<<8;
	    case 5 : b+=k[4];
	    case 4 : a+=((uint32_t)k[3])<<24;
	    case 3 : a+=((uint32_t)k[2])<<16;
	    case 2 : a+=((uint32_t)k[1])<<8;
	    case 1 : a+=k[0];
	             break;
	    case 0 : return c;
	    }

	    final(a,b,c);
	    return c;
	}
};

#undef rot
#undef mix
#undef final

template<size_t N>
ALWAYSINLINE uint32_t HashStringCompileTime( const char (&str)[N] )
{
	uint32_t a, b, c;
	a = b = c = 0xdeadbeef + ((uint32_t)N-1);
	return THashString<N-1>::Hash( str, a, b, c);
}


#endif
