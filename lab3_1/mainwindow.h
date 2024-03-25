#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <chrono>
#include <QTimer>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void update();

    void on_shiningLED_clicked();

    void on_switchLED_clicked();

    void on_checkLED1_toggled(bool checked);

    void on_checkLED2_toggled(bool checked);

    void on_checkLED3_toggled(bool checked);

    void on_checkLED4_toggled(bool checked);

    void on_timesLED_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    bool b_shiningBool=false;
    bool b_switchBool=false;
    bool b_InProcess=false;
    bool b_led1 = false;
    bool b_led2 = false;
    bool b_led3 = false;
    bool b_led4 = false;

    int switchTimes=0;
    int count=0;
    //std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;

    void Shining(bool sw);
    void Switch();

    void Led1(bool sw,int mode);
    void Led2(bool sw,int mode);
    void Led3(bool sw,int mode);
    void Led4(bool sw,int mode);

    bool b_first=true;
    bool b_second=false;
    QTimer *timer;

    void pixmapDebug();

};

#endif // MAINWINDOW_H
