啟動方式:
  先編譯DHT_reader並執行DHT_reader
  
  安裝讀取ardiuno輸出的函式庫
  
    sudo apt-get install python3-pip
    sudo pip3 install pyserial

完成後安裝驅動:

    make
    g++ -o test test.cpp
    sudo insmod
    dmesg

運行server


流程圖:
![未命名的 Jam 1 (1)](https://github.com/ntut-Tu/Embedded-Microprocessor-Systems-Lab.-Spring-2024./assets/160988691/56a80494-de80-40ce-ae28-5ed23e4c2bc3)

https://jamboard.google.com/d/1euOkODaBIiO_SuLjsI4UxyKxn_C_5BAM3Kl3ei3B0mI/viewer?pli=1&f=0
