# Embedded Microprocessor Systems Lab. Spring, 2024.
 # Qt5 install (tx2):(should be installed already next time)
    sudo apt-get install qt5-default
# copy dir to tx2:
    scp -r <dir>nvidia@<IP>:~
# after copy to tx2 
    cd <file dir>
    qmake
    make  
# TODO
 find how to set Image throught QIcon

# 使用pixmap注意:

 要用絕對路徑設圖片地址，到圖片資料夾後
 
    pwd

 用程式設定label的pixmap
 
    QPixmap pixmapOn("/home/nvidia/lab3/asset/led.png");
    ui->picLED1->setPixmap(pixmapOn);
    ui->picLED1->setScaledContents(true); 
    ui->picLED1->setFixedSize(41,41);     

![image](https://github.com/ntut-Tu/Embedded-Microprocessor-Systems-Lab.-Spring-2024./assets/160988691/ad1a6176-ed15-4f92-a5af-51b6abf7b895)
