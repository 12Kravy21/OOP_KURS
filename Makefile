COMPILEFLAGS=-Wall -Werror

all: bin/dictionary format

bin/dictionary: build/main.o build/tree.o build/AVL.o
			$(CXX) $(COMPILEFLAGS) build/main.o build/tree.o build/AVL.o -o $@ 

build/%.o: src/%.cpp include/tree.h include/AVL.h
			$(CXX) $(COMPILEFLAGS) -I include -I src -c $< -o $@ 

format: src/main.cpp src/tree.cpp
			clang-format -i src/main.cpp src/tree.cpp include/tree.h src/AVL.cpp include/AVL.h

clean:
	rm -rf build/*.o bin/dictionary

run:
	cd bin/ && ./dictionary