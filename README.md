

## 正常的編譯指令:

g++	-std=c++11	-c	ellipse.cpp	-o	ellipse.o

g++	-std=c++11	-c	triangle.cpp	-o	triangle.o

g++	-std=c++11	-c	circular_sector.cpp	-o	circular_sector.o

g++	-std=c++11	-c	sort.cpp	-o	sort.o

g++	-std=c++11	-c	main.cpp	-o	main.o

g++	-o	all	ellipse.o triangle.o circular_sector.o sort.o main.o	-std=c++11	-lstdc++

# 使用Makefile編譯教學
>註: #ifndef 在window上能正常運作，但到ubuntu上後會失效

* 用window執行時(git bash)
* 需安裝:mingw-get install msys-make
* 用mingw32-make取代make
* 執行: ./main.exe (ubuntu 打 ./main 就好)
* mingw32-make clean 來刪除.o

# Makefile簡介
## 編譯器與函式庫
	CXX=g++
	CXXFLAGS=-std=c++11
	LDFLAGS=-lstdc++

## 輸出的檔案:
	TARGETS=main
>*輸出的exe檔名*

	SRCS=$(wildcard *.cpp)
>wildcard  *.cpp  : 所有包含.cpp的檔案

	OBJS=$(SRCS:.cpp=.o)
>將SRCS裡的檔案轉成.o

	main: $(OBJS)
		$(CXX) -o $@ $^ $(LDFLAGS) $(CXXFLAGS)
>用所有 $(OBJS) 組成main.exe
$^ 用來引用 $(OBJS) 中的所有目標檔案，$@ 代表目標（這裡是 main）。
最後的指令使用 $(CXX)（編譯器）將所有目標檔案連接起來，生成可執行檔 'main'。
$(LDFLAGS) 包含了鏈接時需要的一些參數，$(CXXFLAGS) 包含了編譯時的一些參數。

	%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@
>對於所有的 .o 目標檔案，如果有對應的 .cpp 源文件，就使用 $(CXX)（編譯器）和 $(CXXFLAGS)這些指令來將源文件編譯成目標檔案，$< 表示源文件，$@ 表示目標檔案。

	clean:
		rm -f $(TARGETS) $(OBJS)
>$(TARGETS) 代表所有的目標檔案，這裡主要是 'main'。
$(OBJS) 代表所有的目標檔案（.o 檔案）。


# -
