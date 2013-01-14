set -e
echo

time clang++ -Wall -g -O2 main.cpp

clang++ -S -Wall -g -O2 main.cpp

./a.out

echo
echo Printing the remaining hello strings:
echo

strings a.out | grep hello

echo

echo Printing out the constants

echo

cat main.s | grep -e "## imm ="

echo
