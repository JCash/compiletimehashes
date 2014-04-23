PWD=`pwd`
BUILDDIR=$PWD/build/darwin
CXXFLAGS="-std=c++11 -g -O3 -stdlib=libc++ -Wall -Wno-c++98-compat -Wno-long-long"
LDFLAGS=""
COMPILER=clang++
LINKER=libtool

if [ ! -d "$BUILDDIR" ]; then
  mkdir -p $BUILDDIR
fi

$COMPILER $CXXFLAGS -c murmur3/MurmurHash3.cpp -o $BUILDDIR/murmur3_darwin.o

$LINKER $LDFLAGS -static -o $BUILDDIR/libmurmur3.a $BUILDDIR/*.o

$COMPILER -std=c++11 -g -O3 -stdlib=libc++ -lc \
        -Isource \
        -Imurmur3 \
        -I. \
        -L${BUILDDIR} \
        -lmurmur3 \
        -o $BUILDDIR/test_words \
        $LDFLAGS \
        tests/test_words.cpp

numbers=(10 100 1000 2000 3000 10000)

for number in "${numbers[@]}"
do
	echo Compiling ${number} hashes   
	time $COMPILER -std=c++11 -g -O3 -stdlib=libc++ -lc \
	        -Isource \
	        -Imurmur3 \
	        -I. \
	        -L${BUILDDIR} \
	        -lmurmur3 \
	        -o $BUILDDIR/test_${number} \
	        $LDFLAGS \
	        tests/test_${number}.cpp
done

