set -e
echo

time g++ -DGCC -Wall -g -O1 main.cpp

g++ -DGCC -S -fverbose-asm -l -Wall -g -O1 main.cpp

./a.out

echo
echo Printing the remaining hello strings:
echo

strings a.out | grep hello

echo

#echo Printing out the remaining constants

echo

#cat main.s | grep -e "movl"

echo
