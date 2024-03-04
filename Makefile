CROSS_COMPILE = aarch64-linux-gnu-
CXX=$(CROSS_COMPILE)g++
CXXFLAGS=-std=c++11
LDFLAGS=-lstdc++
LD=$(CROSS_COMPILE)ld

TARGETS=main

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

main: $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) $(CXXFLAGS) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGETS) $(OBJS)

