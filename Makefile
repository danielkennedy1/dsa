CXX = g++
CXXFLAGS = -Wall -std=c++17 -g

INCLUDES = -Isrc/W1 -Isrc/W2 -Isrc/W3 -Isrc/W4 -Isrc/W5 -Isrc/W6

# CLI input location of the file (with main()) to be compiled
FILE ?=

# Final executable name
OUTPUT = output 

all:
	g++ -g -o $(OUTPUT) $(FILE) $(INCLUDES)
