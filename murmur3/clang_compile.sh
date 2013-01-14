set -e

clang++ -std=c++0x -Wall -g -O3 main.cpp MurmurHash3.cpp

./a.out

echo Printing the remaining 'hello' strings:
strings a.out | grep hello

