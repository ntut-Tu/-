假設當亮度最亮+濕度為0時晾6個小時乾


啟動方式:
  安裝arduino IDE 將其燒入裝置，接上tx2 找到串口位置，修改sensor.py成該位置
  
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
![未命名的 Jam 1 (2)](https://github.com/ntut-Tu/Embedded-Microprocessor-Systems-Lab.-Spring-2024./assets/160988691/ebfa6ae0-6849-40a4-8455-3342b3f4e4d9)


https://jamboard.google.com/d/1euOkODaBIiO_SuLjsI4UxyKxn_C_5BAM3Kl3ei3B0mI/viewer?pli=1&f=0
