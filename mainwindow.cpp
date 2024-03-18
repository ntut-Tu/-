#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;






void MainWindow::on_switchButton_clicked()
{
    QPixmap pixmap0("unlight.png");
    QPixmap pixmap1("led.png");

    if(m_sw1){
        ui->led1Label->setPixmap(pixmap1);
    }else{
        ui->led1Label->setPixmap(pixmap0);
    }
    if(m_sw2){
         ui->led2Label->setPixmap(pixmap1);
    }else{
         ui->led2Label->setPixmap(pixmap0);
    }
    if(m_sw3){
         ui->led3Label->setPixmap(pixmap1);
    }else{
         ui->led3Label->setPixmap(pixmap0);
    }
    if(m_sw4){
         ui->led4Label->setPixmap(pixmap1);
    }else{
         ui->led4Label->setPixmap(pixmap0);
    }
}


void MainWindow::on_shiningButton_clicked()
{
    m_shine=!m_shine;
    QPixmap pixmap0("unlight.png");
    QPixmap pixmap1("led.png");
            while(m_shine){
                ui->led1Label->setPixmap(pixmap1);
                ui->led2Label->setPixmap(pixmap1);
                ui->led3Label->setPixmap(pixmap1);
                ui->led4Label->setPixmap(pixmap1);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                ui->led1Label->setPixmap(pixmap0);
                ui->led2Label->setPixmap(pixmap0);
                ui->led3Label->setPixmap(pixmap0);
                ui->led4Label->setPixmap(pixmap0);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }

}

void MainWindow::on_ledCheckbox_1_toggled(bool checked)
{
    m_sw1=!m_sw1;
}

void MainWindow::on_ledCheckbox_2_toggled(bool checked)
{
    m_sw2=!m_sw2;
}

void MainWindow::on_ledCheckbox_3_toggled(bool checked)
{
    m_sw3=!m_sw3;
}

void MainWindow::on_ledCheckbox_4_toggled(bool checked)
{
    m_sw4=!m_sw4;
}



