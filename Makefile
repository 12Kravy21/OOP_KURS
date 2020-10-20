COMPILEFLAGS=-Wall -Werror

all: bin/dictionary format

bin/dictionary: build/main.o build/tree.o build/AVL.o
			$(CXX) $(COMPILEFLAGS) $^ -o $@ -std=c++11

build/%.o: src/%.cpp
			$(CXX) $(COMPILEFLAGS) -I include -I src -c $< -o $@ -std=c++11

format: src/main.cpp src/tree.cpp
			clang-format -i src/*.cpp include/*.h

clean:
	rm -rf build/*.o bin/dictionary

run:
	cd bin/ && ./dictionary