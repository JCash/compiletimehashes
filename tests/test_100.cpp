

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
	constexpr uint64_t hash11 = CHASH("Aaronical");
	if( hash11 == wordhash ) line = 11;
	constexpr uint64_t hash12 = CHASH("Aaronite");
	if( hash12 == wordhash ) line = 12;
	constexpr uint64_t hash13 = CHASH("Aaronitic");
	if( hash13 == wordhash ) line = 13;
	constexpr uint64_t hash14 = CHASH("Aaru");
	if( hash14 == wordhash ) line = 14;
	constexpr uint64_t hash15 = CHASH("Ab");
	if( hash15 == wordhash ) line = 15;
	constexpr uint64_t hash16 = CHASH("aba");
	if( hash16 == wordhash ) line = 16;
	constexpr uint64_t hash17 = CHASH("Ababdeh");
	if( hash17 == wordhash ) line = 17;
	constexpr uint64_t hash18 = CHASH("Ababua");
	if( hash18 == wordhash ) line = 18;
	constexpr uint64_t hash19 = CHASH("abac");
	if( hash19 == wordhash ) line = 19;
	constexpr uint64_t hash20 = CHASH("abaca");
	if( hash20 == wordhash ) line = 20;
	constexpr uint64_t hash21 = CHASH("abacate");
	if( hash21 == wordhash ) line = 21;
	constexpr uint64_t hash22 = CHASH("abacay");
	if( hash22 == wordhash ) line = 22;
	constexpr uint64_t hash23 = CHASH("abacinate");
	if( hash23 == wordhash ) line = 23;
	constexpr uint64_t hash24 = CHASH("abacination");
	if( hash24 == wordhash ) line = 24;
	constexpr uint64_t hash25 = CHASH("abaciscus");
	if( hash25 == wordhash ) line = 25;
	constexpr uint64_t hash26 = CHASH("abacist");
	if( hash26 == wordhash ) line = 26;
	constexpr uint64_t hash27 = CHASH("aback");
	if( hash27 == wordhash ) line = 27;
	constexpr uint64_t hash28 = CHASH("abactinal");
	if( hash28 == wordhash ) line = 28;
	constexpr uint64_t hash29 = CHASH("abactinally");
	if( hash29 == wordhash ) line = 29;
	constexpr uint64_t hash30 = CHASH("abaction");
	if( hash30 == wordhash ) line = 30;
	constexpr uint64_t hash31 = CHASH("abactor");
	if( hash31 == wordhash ) line = 31;
	constexpr uint64_t hash32 = CHASH("abaculus");
	if( hash32 == wordhash ) line = 32;
	constexpr uint64_t hash33 = CHASH("abacus");
	if( hash33 == wordhash ) line = 33;
	constexpr uint64_t hash34 = CHASH("Abadite");
	if( hash34 == wordhash ) line = 34;
	constexpr uint64_t hash35 = CHASH("abaff");
	if( hash35 == wordhash ) line = 35;
	constexpr uint64_t hash36 = CHASH("abaft");
	if( hash36 == wordhash ) line = 36;
	constexpr uint64_t hash37 = CHASH("abaisance");
	if( hash37 == wordhash ) line = 37;
	constexpr uint64_t hash38 = CHASH("abaiser");
	if( hash38 == wordhash ) line = 38;
	constexpr uint64_t hash39 = CHASH("abaissed");
	if( hash39 == wordhash ) line = 39;
	constexpr uint64_t hash40 = CHASH("abalienate");
	if( hash40 == wordhash ) line = 40;
	constexpr uint64_t hash41 = CHASH("abalienation");
	if( hash41 == wordhash ) line = 41;
	constexpr uint64_t hash42 = CHASH("abalone");
	if( hash42 == wordhash ) line = 42;
	constexpr uint64_t hash43 = CHASH("Abama");
	if( hash43 == wordhash ) line = 43;
	constexpr uint64_t hash44 = CHASH("abampere");
	if( hash44 == wordhash ) line = 44;
	constexpr uint64_t hash45 = CHASH("abandon");
	if( hash45 == wordhash ) line = 45;
	constexpr uint64_t hash46 = CHASH("abandonable");
	if( hash46 == wordhash ) line = 46;
	constexpr uint64_t hash47 = CHASH("abandoned");
	if( hash47 == wordhash ) line = 47;
	constexpr uint64_t hash48 = CHASH("abandonedly");
	if( hash48 == wordhash ) line = 48;
	constexpr uint64_t hash49 = CHASH("abandonee");
	if( hash49 == wordhash ) line = 49;
	constexpr uint64_t hash50 = CHASH("abandoner");
	if( hash50 == wordhash ) line = 50;
	constexpr uint64_t hash51 = CHASH("abandonment");
	if( hash51 == wordhash ) line = 51;
	constexpr uint64_t hash52 = CHASH("Abanic");
	if( hash52 == wordhash ) line = 52;
	constexpr uint64_t hash53 = CHASH("Abantes");
	if( hash53 == wordhash ) line = 53;
	constexpr uint64_t hash54 = CHASH("abaptiston");
	if( hash54 == wordhash ) line = 54;
	constexpr uint64_t hash55 = CHASH("Abarambo");
	if( hash55 == wordhash ) line = 55;
	constexpr uint64_t hash56 = CHASH("Abaris");
	if( hash56 == wordhash ) line = 56;
	constexpr uint64_t hash57 = CHASH("abarthrosis");
	if( hash57 == wordhash ) line = 57;
	constexpr uint64_t hash58 = CHASH("abarticular");
	if( hash58 == wordhash ) line = 58;
	constexpr uint64_t hash59 = CHASH("abarticulation");
	if( hash59 == wordhash ) line = 59;
	constexpr uint64_t hash60 = CHASH("abas");
	if( hash60 == wordhash ) line = 60;
	constexpr uint64_t hash61 = CHASH("abase");
	if( hash61 == wordhash ) line = 61;
	constexpr uint64_t hash62 = CHASH("abased");
	if( hash62 == wordhash ) line = 62;
	constexpr uint64_t hash63 = CHASH("abasedly");
	if( hash63 == wordhash ) line = 63;
	constexpr uint64_t hash64 = CHASH("abasedness");
	if( hash64 == wordhash ) line = 64;
	constexpr uint64_t hash65 = CHASH("abasement");
	if( hash65 == wordhash ) line = 65;
	constexpr uint64_t hash66 = CHASH("abaser");
	if( hash66 == wordhash ) line = 66;
	constexpr uint64_t hash67 = CHASH("Abasgi");
	if( hash67 == wordhash ) line = 67;
	constexpr uint64_t hash68 = CHASH("abash");
	if( hash68 == wordhash ) line = 68;
	constexpr uint64_t hash69 = CHASH("abashed");
	if( hash69 == wordhash ) line = 69;
	constexpr uint64_t hash70 = CHASH("abashedly");
	if( hash70 == wordhash ) line = 70;
	constexpr uint64_t hash71 = CHASH("abashedness");
	if( hash71 == wordhash ) line = 71;
	constexpr uint64_t hash72 = CHASH("abashless");
	if( hash72 == wordhash ) line = 72;
	constexpr uint64_t hash73 = CHASH("abashlessly");
	if( hash73 == wordhash ) line = 73;
	constexpr uint64_t hash74 = CHASH("abashment");
	if( hash74 == wordhash ) line = 74;
	constexpr uint64_t hash75 = CHASH("abasia");
	if( hash75 == wordhash ) line = 75;
	constexpr uint64_t hash76 = CHASH("abasic");
	if( hash76 == wordhash ) line = 76;
	constexpr uint64_t hash77 = CHASH("abask");
	if( hash77 == wordhash ) line = 77;
	constexpr uint64_t hash78 = CHASH("Abassin");
	if( hash78 == wordhash ) line = 78;
	constexpr uint64_t hash79 = CHASH("abastardize");
	if( hash79 == wordhash ) line = 79;
	constexpr uint64_t hash80 = CHASH("abatable");
	if( hash80 == wordhash ) line = 80;
	constexpr uint64_t hash81 = CHASH("abate");
	if( hash81 == wordhash ) line = 81;
	constexpr uint64_t hash82 = CHASH("abatement");
	if( hash82 == wordhash ) line = 82;
	constexpr uint64_t hash83 = CHASH("abater");
	if( hash83 == wordhash ) line = 83;
	constexpr uint64_t hash84 = CHASH("abatis");
	if( hash84 == wordhash ) line = 84;
	constexpr uint64_t hash85 = CHASH("abatised");
	if( hash85 == wordhash ) line = 85;
	constexpr uint64_t hash86 = CHASH("abaton");
	if( hash86 == wordhash ) line = 86;
	constexpr uint64_t hash87 = CHASH("abator");
	if( hash87 == wordhash ) line = 87;
	constexpr uint64_t hash88 = CHASH("abattoir");
	if( hash88 == wordhash ) line = 88;
	constexpr uint64_t hash89 = CHASH("Abatua");
	if( hash89 == wordhash ) line = 89;
	constexpr uint64_t hash90 = CHASH("abature");
	if( hash90 == wordhash ) line = 90;
	constexpr uint64_t hash91 = CHASH("abave");
	if( hash91 == wordhash ) line = 91;
	constexpr uint64_t hash92 = CHASH("abaxial");
	if( hash92 == wordhash ) line = 92;
	constexpr uint64_t hash93 = CHASH("abaxile");
	if( hash93 == wordhash ) line = 93;
	constexpr uint64_t hash94 = CHASH("abaze");
	if( hash94 == wordhash ) line = 94;
	constexpr uint64_t hash95 = CHASH("abb");
	if( hash95 == wordhash ) line = 95;
	constexpr uint64_t hash96 = CHASH("Abba");
	if( hash96 == wordhash ) line = 96;
	constexpr uint64_t hash97 = CHASH("abbacomes");
	if( hash97 == wordhash ) line = 97;
	constexpr uint64_t hash98 = CHASH("abbacy");
	if( hash98 == wordhash ) line = 98;
	constexpr uint64_t hash99 = CHASH("Abbadide");
	if( hash99 == wordhash ) line = 99;
	constexpr uint64_t hash100 = CHASH("abbas");
	if( hash100 == wordhash ) line = 100;

	if( line == -1)
	{
		printf("The word %s didn't match any of the first 100 words\n", word);
		return 2;
	}
	
	printf("Line was: %d\n", line);
	return 0;
}
