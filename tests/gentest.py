
import sys, os

scriptdir = os.path.dirname(__file__)

NUM_KEYS = [10, 100, 1000, 2000, 3000, 10000]



template_main = """

#include <stdio.h>
#include <map>
#include "hash.h"

int main( int argc, char** argv )
{
	if( argc < 2 )
	{
		printf("Pass a word from words.txt\\n");
		return 1;
	}
		
	const char* word = argv[1];
	
	const uint64_t wordhash = HashString64(word);
"""

template_header_switch = """
	int line = -1;
	switch( wordhash )
	{
"""

template_footer_switch = """
	default: printf("The word %%s didn't match any of the first %(num_words)s words\\n", word); return 2;
	}
	
	printf("Line was: %%d\\n", line);
	return 0;
}
"""


template_header_lookup = """
	int line = -1;
	std::map<const uint64_t, uint32_t> lookup;
"""

template_footer_lookup = """
	std::map<const uint64_t, uint32_t>::iterator it = lookup.find(wordhash);
	if( it == lookup.end() )
	{
		printf("The word %%s didn't match any of the first %(num_words)s words\\n", word);
		return 2;
	}
	line = (*it).second;
	
	printf("Line was: %%d\\n", line);
	return 0;
}
"""

template_header_if = """
	int line = -1;
"""

template_footer_if = """
	if( line == -1)
	{
		printf("The word %%s didn't match any of the first %(num_words)s words\\n", word);
		return 2;
	}
	
	printf("Line was: %%d\\n", line);
	return 0;
}
"""

def gen_switch_case(f, word, i):
	f.write('\tcase CHASH("%s"):	line = %d; break;\n' % (word, i) )

def gen_lookup_case(f, word, i):
	f.write('\tlookup.insert( std::make_pair( CHASH("%s"), %d ) );\n' % (word, i) )

def gen_if_case(f, word, i):
	#f.write('\tconstexpr uint64_t hash%d = CHASH("%s");\n' % (i, word) )
	#f.write('\tif( hash%d == wordhash ) line = %d;\n' % (i, i) )
	f.write('\tif( wordhash == CHASH("%s") ) line = %d;\n' % (word, i) )

with open(os.path.join(scriptdir, 'words.txt')) as f:
	words = f.readlines()

words = [x.strip() for x in words if x]

for num_keys in NUM_KEYS:
	path = os.path.join(scriptdir, 'test_%d.cpp' % num_keys)
	with open(path, 'wb') as f:
		
		f.write( template_main )
		
		#header, eachword_fn, footer = (template_header_switch, gen_switch_case, template_footer_switch)
		#header, eachword_fn, footer = (template_header_lookup, gen_lookup_case, template_footer_lookup)
		header, eachword_fn, footer = (template_header_if, gen_if_case, template_footer_if)
		
		f.write( header )
		
		for index, word in enumerate(words):
			eachword_fn(f, word, index)
			if index >= num_keys:
				break
		
		f.write( footer % {'num_words':num_keys} )

		