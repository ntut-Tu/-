#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <chrono>
#include <QTimer>
#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <thread>
#include <chrono>
using namespace std;

#define P_LED_ON "/home/nvidia/lab3_2/asset/led.png"
#define P_LED_OFF "/home/nvidia/lab3_2/asset/unlight.png"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void Start(){
        gpio_set_dir(466,"out");
        gpio_set_dir(397,"out");
        gpio_set_dir(255,"out");
        gpio_set_dir(481,"out");
    }

private slots:
    void update();

    void on_shiningLED_clicked();

    void on_switchLED_clicked();

    void on_checkLED1_toggled(bool checked);

    void on_checkLED2_toggled(bool checked);

    void on_checkLED3_toggled(bool checked);

    void on_checkLED4_toggled(bool checked);

    void on_timesLED_textChanged(const QString &arg1);

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    bool b_shiningBool=false;
    bool b_switchBool=false;
    bool b_randomBool=false;
    bool b_InProcess=false;
    bool b_led1 = false;
    bool b_led2 = false;
    bool b_led3 = false;
    bool b_led4 = false;

    int switchTimes=0;
    int count=0;
    //std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;

    void Shining(bool sw);
    void Switch(bool sw);
    void RandomMode(bool sw);

    void Led1(bool sw,int mode);
    void Led2(bool sw,int mode);
    void Led3(bool sw,int mode);
    void Led4(bool sw,int mode);

    bool b_first=true;
    bool b_second=false;

    QTimer *timer;
    int defaultSpeed=800;
    int timerSpeed=500;
    int lastTimer=500;

    bool b_led1_ON = false;
    bool b_led2_ON = false;
    bool b_led3_ON = false;
    bool b_led4_ON = false;

    void pixmapDebug();

    //gpio
    int gpio_unexport(unsigned int gpio);
    int gpio_export(unsigned int gpio) ;
    int gpio_set_dir(unsigned int gpio, std::string dirStatus);
    int gpio_set_value(unsigned int gpio, int value);
};

#endif // MAINWINDOW_H
