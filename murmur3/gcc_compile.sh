set -e

g++ -std=c++0x -Wall -O3 -g main.cpp MurmurHash3.cpp

./a.out

echo Printing the remaining hello strings:
strings a.out | grep hello

