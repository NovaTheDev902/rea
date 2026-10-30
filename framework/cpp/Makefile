# Makefile - Build native C++ components
# Usage: make (builds rtcp_exploit)
#        make clean

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGETS = rtcp_exploit

all: $(TARGETS)

rtcp_exploit: rtcp_exploit.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS) *.bin

.PHONY: all clean
