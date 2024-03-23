# Embedded Microprocessor Systems Lab. Spring, 2024.

# setup
 
* Qt5 install (tx2):
  
(should be installed already next time)

    sudo apt-get install qt5-default
    
* copy dir to tx2:

好像會覆蓋

    scp -r <dir>nvidia@<IP>:~
  
* after copy to tx2 

Tx2記得裝qt5

    cd <file dir>
    qmake
    make  


# 使用pixmap注意:

 要用絕對路徑設圖片地址，到圖片資料夾後
 
    pwd

 用程式設定label的pixmap
 
    QPixmap pixmapOn("/home/nvidia/lab3/asset/led.png");
    ui->picLED1->setPixmap(pixmapOn);
    ui->picLED1->setScaledContents(true); 
    ui->picLED1->setFixedSize(41,41);     


# debugger

用法和printf一樣

    qDebug("text here\n");

# 使用QTimer:

chrono的計時器因為主程式執行的方式不是迴圈而是~~不停呼叫main.cpp~~ ?，似乎不能合理的使用，只能用內建的QTime

* 創建計時器:

QTime的邏輯: 每隔(毫秒)就發送一次訊號(在這裡用 connect 就直接變成執行目標函式)
放在建構子之類的地方

    QTimer *timer;
    timer=new QTimer(this);
    bool debugCheck=connect(timer,SIGNAL(timeout()),this,SLOT(update()));

    delete timer //不確定需不需要
    
connect(計時器位址,不知道什麼信號?,this,SLOT(目標函式))  //button的原始邏輯好像也是這樣
有另一種方法，但試過都失敗

    QTimer timer;
    timer.setInterval(1000);  //這個是預設時間
    QObject::connect(&timer, &QTimer::timeout, &update);

開始與結束

    timer->start(500); //500ms
    timer->stop();
    timer->isActive()

* 注意!!!!!!!!

放在connect裡的函式一定要放在private slots 裡面!!!!!!!! 不然呼叫不到

  ![image](https://github.com/ntut-Tu/Embedded-Microprocessor-Systems-Lab.-Spring-2024./assets/160988691/0ee0f96e-3676-4c98-bb30-d1e5f83d7eeb)


# 照片

實驗一

![image](https://github.com/ntut-Tu/Embedded-Microprocessor-Systems-Lab.-Spring-2024./assets/160988691/ad1a6176-ed15-4f92-a5af-51b6abf7b895)

實驗二

![image](https://github.com/ntut-Tu/Embedded-Microprocessor-Systems-Lab.-Spring-2024./assets/160988691/1fd28485-b4da-4a15-809e-1ff542abcaeb)


    
