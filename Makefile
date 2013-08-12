.SILENT:

all: clean lib tests
	@echo "All done"

prepare:
	# @echo "Make an empty build/ directory"
	mkdir -p build

clean:
	# @echo "Delete build/ directory"
	rm -rf build

lib: prepare
	@echo "Compiling library"
	gcc -c src/iching.c -o build/iching.o -I include -fPIC
	ar rcs build/libiching.a build/iching.o
	rm build/iching.o

build-tests: prepare
	@echo "Compiling tests"
	gcc tests/test.c -Lbuild/ -liching -o build/test -I include
	g++ tests/test.cc -Lbuild/ -liching -o build/testcpp -I include

test: build-tests
	build/test
	build/testcpp

node-lib: lib
	node-gyp configure build

node-test:
	node tests/test.js

node: clean node-lib node-test

check: node
