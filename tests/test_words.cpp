#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "hash.h"
#include "murmur3/MurmurHash3.h"

int main(int argc, char** argv )
{
	if( argc < 2 )
	{
		printf("Usage:\ttest words.txt\n");
		return 1;
	}

	const char* path = argv[1];

	std::ifstream file(path);
	if( !file.is_open() )
	{
		printf("Failed to open %s for reading\n", path);
		return 1;
	}

	std::string line;
	while (std::getline(file, line))
	{
		{
			uint64_t original[2];
			MurmurHash3_x64_128(line.c_str(), line.size(), 0, original);

			uint64_t consthash[2];
			MurmurHash3c_x64_128(line.c_str(), line.size(), 0, consthash);

			if( original[0] != consthash[0] || original[1] != consthash[1] )
			{
				printf("Hashes differ for word '%s':\n", line.c_str());
				printf("\toriginal  = %llX, %llX\n", original[0], original[1]);
				printf("\tconsthash = %llX, %llX\n", consthash[0], consthash[1]);
				return 1;
			}
		}

		{
			const uint64_t original = HashString64(line.c_str());
			const uint64_t consthash = ConstString(line.c_str(), line.size()).hash();
			if( original != consthash)
			{
				printf("Hashes differ for word '%s':\n", line.c_str());
				printf("\toriginal  = %llX\n", original);
				printf("\tconsthash = %llX\n", consthash);

				printf("\t128 bits\n");
				uint64_t referenceoriginal[2];
				MurmurHash3_x64_128(line.c_str(), line.size(), 0, referenceoriginal);

				uint64_t referenceconsthash[2];
				MurmurHash3c_x64_128(line.c_str(), line.size(), 0, referenceconsthash);
				printf("\treferenceoriginal  = %llX, %llX\n", referenceoriginal[0], referenceoriginal[1]);
				printf("\treferenceconsthash = %llX, %llX\n", referenceconsthash[0], referenceconsthash[1]);
				return 1;
			}
		}
	}

	return 0;
}
