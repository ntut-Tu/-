//
// Created by nudle on 2024/3/24.
//
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer=new QTimer(this);
    bool debugCheck=connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    if(!debugCheck){
        qDebug("connect fail!\n");
    }else{
        qDebug("connect sucess!\n");
    }
}

MainWindow::~MainWindow()
{
    qDebug("delete!\n");
    delete ui;
    delete timer;
}

void MainWindow::update(){
    qDebug("update!\n");
    Switch(b_switchBool);
    RandomMode(b_randomBool);
    if(lastTimer!=timerSpeed){
        timer->setInterval(timerSpeed);
    }
}

void MainWindow::Shining(bool sw){
    if(sw==false){
        return;
    }
    Led1(true,1);
    Led2(true,1);
    Led3(true,1);
    Led4(true,1);
}



void MainWindow::Switch(bool sw){
    if(sw==false){
        return;
    }
    b_first=!b_first;
    b_second=!b_second;
    Led1(b_first,2);
    Led2(b_first,2);
    Led3(b_second,2);
    Led4(b_second,2);
    if(count<=0){
        Led1(false,2);
        Led2(false,2);
        Led3(false,2);
        Led4(false,2);
        b_InProcess=false;
        ui->textDebug->setText("(debug)EndSwitch");
        timer->stop();
        return;
    }
    ui->textDebug->setText("(debug)InSwitch");
    count--;
    b_switchBool=false;
}

void MainWindow::on_shiningLED_clicked()
{
    b_switchBool=false;
    b_shiningBool=true;
    Shining(b_shiningBool);
}

void MainWindow::on_switchLED_clicked()
{
    if(!timer->isActive()){
        b_switchBool=true;
        b_shiningBool=false;
        count=switchTimes;
        b_InProcess=true;
        timer->start(timerSpeed);
        ui->textDebug->setText("(debug)TimerStart");
        qDebug("isActive!\n");
    }
}

void MainWindow::on_checkLED1_toggled(bool checked)
{
    b_led1=checked;
}

void MainWindow::on_checkLED2_toggled(bool checked)
{
    b_led2=checked;
}

void MainWindow::on_checkLED3_toggled(bool checked)
{
    b_led3=checked;
}

void MainWindow::on_checkLED4_toggled(bool checked)
{
    b_led4=checked;
}

void MainWindow::pixmapDebug(){
    QPixmap pixmapOn("/home/nvidia/lab3/asset/led.png");
    QPixmap pixmapOff("/home/nvidia/lab3/asset/unlight.png");
    if (pixmapOn.isNull()) {
        ui->textDebug->setText("(debug)Read error");
    } else {
        ui->textDebug->setText("(debug)Read success");
    }

    if (pixmapOff.isNull()) {
        ui->textDebug->setText("(debug)Read error");
    } else {
        ui->textDebug->setText("(debug)Read success");
    }
}

void MainWindow::Led1(bool sw,int mode){
    QPixmap pixmapOn("/home/nvidia/lab3/asset/led.png");
    QPixmap pixmapOff("/home/nvidia/lab3/asset/unlight.png");
    //pixmapDebug();
    if(mode==1){
        if(sw){
            if(b_led1){
                ui->picLED1->setPixmap(pixmapOn);
            }else{
                ui->picLED1->setPixmap(pixmapOff);
            }
        }else{
            ui->picLED1->setPixmap(pixmapOff);
        }
    }else{
        if(sw){
            ui->picLED1->setPixmap(pixmapOn);
        }else{
            ui->picLED1->setPixmap(pixmapOff);
        }
    }
    ui->picLED1->setScaledContents(true);
    ui->picLED1->setFixedSize(41,41);
}
void MainWindow::Led2(bool sw,int mode){
    QPixmap pixmapOn("/home/nvidia/lab3/asset/led.png");
    QPixmap pixmapOff("/home/nvidia/lab3/asset/unlight.png");
    if(mode==1){
        if(sw){
            if(b_led2){
                ui->picLED2->setPixmap(pixmapOn);
            }else{
                ui->picLED2->setPixmap(pixmapOff);
            }
        }else{
            ui->picLED2->setPixmap(pixmapOff);
        }
    }else{
        if(sw){
            ui->picLED2->setPixmap(pixmapOn);
        }else{
            ui->picLED2->setPixmap(pixmapOff);
        }
    }
    ui->picLED2->setScaledContents(true);
    ui->picLED2->setFixedSize(41,41);
}
void MainWindow::Led3(bool sw,int mode){
    QPixmap pixmapOn("/home/nvidia/lab3/asset/led.png");
    QPixmap pixmapOff("/home/nvidia/lab3/asset/unlight.png");
    if(mode==1){
        if(sw){
            if(b_led3){
                ui->picLED3->setPixmap(pixmapOn);
            }else{
                ui->picLED3->setPixmap(pixmapOff);
            }
        }else{
            ui->picLED3->setPixmap(pixmapOff);
        }
    }else{
        if(sw){
            ui->picLED3->setPixmap(pixmapOn);
        }else{
            ui->picLED3->setPixmap(pixmapOff);
        }
    }
    ui->picLED3->setScaledContents(true);
    ui->picLED3->setFixedSize(41,41);
}
void MainWindow::Led4(bool sw,int mode){
    QPixmap pixmapOn("/home/nvidia/lab3/asset/led.png");
    QPixmap pixmapOff("/home/nvidia/lab3/asset/unlight.png");
    if(mode==1){
        if(sw){
            if(b_led4){
                ui->picLED4->setPixmap(pixmapOn);
            }else{
                ui->picLED4->setPixmap(pixmapOff);
            }
        }else{
            ui->picLED4->setPixmap(pixmapOff);
        }
    }else{
        if(sw){
            ui->picLED4->setPixmap(pixmapOn);
        }else{
            ui->picLED4->setPixmap(pixmapOff);
        }
    }
    ui->picLED4->setScaledContents(true);
    ui->picLED4->setFixedSize(41,41);
}

void MainWindow::on_timesLED_textChanged(const QString &arg1)
{
    switchTimes=arg1.toInt();
}


int MainWindow::gpio_unexport(unsigned int gpio)
{
    int fd, len;
    char buf[64];

    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd < 0)
    {
        perror("gpio/export");
        return fd;
    }

    len = snprintf(buf, sizeof(buf), "%d", gpio); // gpiobuf
    write(fd, buf, len);						// export (gpio)
    close();									//
    return 0;
}

// export
int MainWindow::gpio_export(unsigned int gpio) // Xgpio
{
    int fd, len;
    char buf[64];
    fd = open("/sys/class/gpio/export", O_WRONLY);

    if (fd < 0)
    {
        perror("gpio/export");
        return fd;
    }
    len = snprintf(buf, sizeof(buf), "%d", gpio); // gpiobuf
    write(fd, buf, len);						  // export (gpio)
    close();

    return 0;
}

// direcion
int MainWindow::gpio_set_dir(unsigned int gpio, std::string dirStatus) // gpiooutsin
{
    int fd;
    char buf[64];

    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/direction", gpio);

    fd = open(buf, O_WRONLY);
    if (fd < 0)
    {
        perror("gpio/direction");
        return fd;
    }

    if (dirStatus == "out")
        write(fd, "out", 4);
    else
        write(fd, "in", 3);
    close();

    return 0;
}

// value
int MainWindow::gpio_set_value(unsigned int gpio, int value)
{
    int fd;
    char buf[64];

    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/value", gpio);

    fd = open(buf, O_WRONLY);
    if (fd < 0)
    {
        perror("gpio/direction");
        return fd;
    }

    if (value == 0)
        write(fd, "0", 2);
    else
        write(fd, "1", 2);

    close();
    return 0;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    lastTimer = timerSpeed;
    timerSpeed=defaultSpeed-(value*5);

}

void MainWindow::on_pushButton_clicked()
{
    if(!timer->isActive()){
        b_switchBool=false;
        b_shiningBool=false;
        b_randomBool = true;
        count=switchTimes;
        b_InProcess=true;
        timer->start(timerSpeed);
        ui->textDebug->setText("(debug)TimerStart");
        qDebug("isActive!\n");
    }else{
        b_randomBool = false;
    }
}
void MainWindow::RandomMode(bool sw){
    if(!sw){
        return;
    }
    Led1(false,1);
    Led2(false,1);
    Led3(false,1);
    Led4(false,1);
    b_led1_ON = false;
    b_led2_ON = false;
    b_led3_ON = false;
    b_led4_ON = false;
    switch(rand() %4+1){
    case(1):{
        Led1(true,1);
        b_led1_ON = true;
        break;
    }
    case(2):{
        Led2(true,1);
        b_led2_ON = true;
        break;
    }
    case(3):{
        Led3(true,1);
        b_led3_ON = true;
        break;
    }
    case(4):{
        Led4(true,1);
        b_led4_ON = true;
        break;
    }
    }

}
