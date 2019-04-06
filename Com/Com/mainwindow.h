#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QTimer>

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
    void on_Btn_OorC_clicked();

    void on_pushButton_clicked();

    void revData();

    void on_actionScan_port_S_triggered();

    void autoScanPort();

private:
    Ui::MainWindow *ui;
    void getPortName();
    void openPort();
    QSerialPort *serialPort;
    void ConfigCom();
    bool isOpen;
    QTimer *timer;


};

#endif // MAINWINDOW_H
