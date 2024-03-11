# lab 2

# argv[]用法

    int main(int argv,char* argv[])
使用方法:

    ./檔名 參數1 參數2

    argv[1]=參數1

* 不會有argv[0]

* 注意：C/C++的char*和String在比較時需慎用
  
 做==比較時比較的是位址，只能用

      strcmp(str1,str2)==0

或像C的逐字比較

# 延遲迴圈用法

    #include <iostream>
    #include <thread>
    #include <chrono>

    int main() {
      for (int i = 0; i < 4; ++i) {
          
          std::this_thread::sleep_for(std::chrono::milliseconds(500));
      }

    return 0;
    }

![image](https://github.com/ntut-Tu/Embedded-Microprocessor-Systems-Lab.-Spring-2024./assets/160988691/4ffaa5b7-09d3-430c-89b9-202082a3a6ce)

![image](https://github.com/ntut-Tu/Embedded-Microprocessor-Systems-Lab.-Spring-2024./assets/160988691/07e87eed-d0a5-468e-8aa4-9f643b8012fb)


![image](https://github.com/ntut-Tu/Embedded-Microprocessor-Systems-Lab.-Spring-2024./assets/160988691/098dfdcc-e367-43f8-b766-08bfe6f90247)
