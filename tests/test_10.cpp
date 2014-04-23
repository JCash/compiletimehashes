

#include <stdio.h>
#include <map>
#include "hash.h"

int main( int argc, char** argv )
{
	if( argc < 2 )
	{
		printf("Pass a word from words.txt\n");
		return 1;
	}
		
	const char* word = argv[1];
	
	const uint64_t wordhash = HashString64(word);

	int line = -1;
	constexpr uint64_t hash0 = CHASH("A");
	if( hash0 == wordhash ) line = 0;
	constexpr uint64_t hash1 = CHASH("a");
	if( hash1 == wordhash ) line = 1;
	constexpr uint64_t hash2 = CHASH("aa");
	if( hash2 == wordhash ) line = 2;
	constexpr uint64_t hash3 = CHASH("aal");
	if( hash3 == wordhash ) line = 3;
	constexpr uint64_t hash4 = CHASH("aalii");
	if( hash4 == wordhash ) line = 4;
	constexpr uint64_t hash5 = CHASH("aam");
	if( hash5 == wordhash ) line = 5;
	constexpr uint64_t hash6 = CHASH("Aani");
	if( hash6 == wordhash ) line = 6;
	constexpr uint64_t hash7 = CHASH("aardvark");
	if( hash7 == wordhash ) line = 7;
	constexpr uint64_t hash8 = CHASH("aardwolf");
	if( hash8 == wordhash ) line = 8;
	constexpr uint64_t hash9 = CHASH("Aaron");
	if( hash9 == wordhash ) line = 9;
	constexpr uint64_t hash10 = CHASH("Aaronic");
	if( hash10 == wordhash ) line = 10;

	if( line == -1)
	{
		printf("The word %s didn't match any of the first 10 words\n", word);
		return 2;
	}
	
	printf("Line was: %d\n", line);
	return 0;
}
