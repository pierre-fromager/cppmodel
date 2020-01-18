CXX=g++
CC = $(CXX)
CPPFLAGS=-Wall -Wextra -std=c++11 -O3
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