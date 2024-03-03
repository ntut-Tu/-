CXX=g++
CXXFLAGS=-std=c++11
LDFLAGS=-lstdc++

TARGETS=main

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

main: $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) $(CXXFLAGS) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGETS) $(OBJS)

