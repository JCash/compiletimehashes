set -e

clang++ -DDEBUG -std=c++0x -Wall -g main.cpp MurmurHash3.cpp

./a.out

echo Printing the remaining 'hello' strings:
strings a.out | grep hello

