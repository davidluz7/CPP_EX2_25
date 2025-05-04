CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g
LDFLAGS = 

SRC = SquareMat.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = Main

TEST_SRC = test_SquareMat.cpp SquareMat.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TEST_TARGET = test

.PHONY: all Main test valgrind clean

all: Main

Main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)
	./Main

test: $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJ)
	./test

valgrind: test
	valgrind --leak-check=full ./test

clean:
	rm -f *.o Main test