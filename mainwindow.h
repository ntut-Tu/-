#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void on_shiningButton_clicked();

    void on_switchButton_clicked();

    void on_ledCheckbox_1_toggled(bool checked);

    void on_ledCheckbox_2_toggled(bool checked);

    void on_ledCheckbox_3_toggled(bool checked);

    void on_ledCheckbox_4_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    bool m_shine=false;
    bool m_sw1=false;
    bool m_sw2=false;
    bool m_sw3=false;
    bool m_sw4=false;
};

#endif // MAINWINDOW_H
