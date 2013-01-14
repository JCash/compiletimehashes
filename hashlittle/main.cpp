
#include <stdio.h>
#include <string.h>
#include "hashlittle.h"
#include "thashlittle.h"


int main(int, const char**)
{
	printf("\n");

	//uint32_t originalhash = HashString("0123456789");
	//uint32_t originalhash = HashString("012345678901");
	//uint32_t originalhash = HashString("0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
	//printf("original = %u    %x  (hashlittle)\n", originalhash, originalhash);

	//uint32_t hash = HashStringCompileTime("0123456789");
	uint32_t hash = HashStringCompileTime("012345678901");
	//uint32_t hash = HashStringCompileTime("0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
	//uint32_t hash = HashStringCompileTime("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
	//uint32_t hash = HashStringCompileTime("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
	
	printf("hash = %u    %x   \n", hash, hash);

/*
	uint32_t hash2 = HashStringCompileTime("hello");
	printf("hello = %d    %x   \n", hash2, hash2);

	//uint32_t hash3 = HashString("hello_0123456789"); // 16 chars
	//printf("hello_0123456789 = %d    %x  (hashlittle)\n", hash3, hash3);

	uint32_t hash4 = HashStringCompileTime("hello_0123456789");
	printf("hello_0123456789 = %d    %x   \n", hash4, hash4);

	//uint32_t statichash1 = HashString("hello   abcdefgh01234567abcdefgh01234567abcdefgh01234567abcdefgh01234567abcdefgh");
	//printf("statichash = %d    %x  (hashlittle)\n", statichash, statichash);

	uint32_t statichash1 = HashStringCompileTime("hello   abcdefgh01234567abcdefgh01234567abcdefgh01234567abcdefgh01234567abcdefgh");
	//uint32_t statichash1 = HashStringCompileTime("hello   abcdefgh01234567abcdefgh01234567abcdefgh01234567abcdefgh01234567abcdefghhello   abcdefgh01234567abcdefgh01234567abcdefgh01234567abcdefgh01234567abcdefghhello   abcdefgh01234567abcdefgh01234567abcdefgh01234567abcdefgh01234567abcdefghhello   abcdefgh01234567abcdefgh01234567abcdefgh01234567abcdefgh01234567abcdefghhello   abcdefgh01234567abcdefgh01234567abcdefgh01234567abcdefgh01234567abcdefghhello   abcdefgh01234567abcdefgh01234567abcdefgh01234567abcdefgh01234567abcdefgh");
 	printf("statichash = %d    %x   \n", statichash1, statichash1);
 */
	return 0;
}