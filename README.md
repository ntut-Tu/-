# lab 2

# argv[]用法

  int main(int argv,char* argv[])

  ./檔名 參數1 參數2

argv[1]=參數1

* 不會有argv[0]

* 注意：C/C++的char*和String在比較時需慎用，做==比較時比較的是位址，只能用

  strcmp(str1,str2)

或像C的逐字比較