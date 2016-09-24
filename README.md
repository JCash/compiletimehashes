hashes
======

A set of common hash functions implemented using C++11 constexpr and user string literals (optional)

How to use
==========

For the barebone usage, just drop the include/MurmurHash3c.h into your project.
It contains the 

	constexpr uint64_t MurmurHash3c_64(const ConstStringMM3& cs, uint64_t seed = 0);
	inline void MurmurHash3c_x64_128( const char* key, int len, const uint32_t seed, void* out );

which both make use of the class

	class ConstStringMM3;
	


For the extended use, there is a high(er) level api in "hash.h".


Performance
===========

When tested in the SMHasher framework it was approximately 30%-50% slower.
(Tested on a 64 bit Macbook Pro @ 2.26 Ghz dual core with 2GB ram)


License
=======

The project has a MIT license (MurmurHash3 is public domain)


Links
=====

https://code.google.com/p/smhasher/wiki/MurmurHash 