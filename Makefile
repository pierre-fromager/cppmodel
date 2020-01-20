CXX = g++ 
CC = $(CXX)
CPPFLAGS = -std=c++14 -fopenmp -Wall -Wextra -O2 -D_GLIBCXX_PARALLEL
SOURCES = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
OBJECTS=$(SOURCES:%.cpp=%.o)
TARGET=demo

.PHONY: all
	all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS)