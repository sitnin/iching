.SILENT:

all: clean lib tests
	@echo "All done"

prepare:
	# @echo "Making empty build/ directory"
	mkdir -p build

clean:
	# @echo "Deleting build/ directory"
	rm -rf build

check:
	build/test
	build/testcpp

lib: prepare
	@echo "Compiling library"
	gcc -c src/iching.c -o build/iching.o -I include
	ar rcs build/libiching.a build/iching.o
	rm build/iching.o

node: clean lib
	node-gyp configure
	node-gyp build

tests: prepare
	@echo "Compiling tests"
	gcc tests/test.c -Lbuild/ -liching -o build/test -I include
	g++ tests/test.cc -Lbuild/ -liching -o build/testcpp -I include