#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList list;
    list<<tr("1200")<<tr("2400")<<tr("4800")\
        <<tr("9600")<<tr("19200")<<tr("38400")<<tr("57600")<<tr("115200")<<tr("256000")<<tr("384000")<<tr("576000");
    ui->combo_Baud->addItems(list);
    getPortName();
    serialPort = new QSerialPort;
    connect(serialPort,SIGNAL(readyRead()),this,SLOT(revData()));
    isOpen =false;
    ui->pushButton->setEnabled(false);

    //auto scan port
    timer = new QTimer;
    timer->setInterval(4000);
    timer->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(autoScanPort()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getPortName()
{
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->combo_Port->addItem(info.portName());
    }
}

void MainWindow::ConfigCom()
{
    QString comname=ui->combo_Port->currentText();

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        if(info.portName()==comname)
        {
            serialPort->setPortName(info.systemLocation());
        }
    }

   // QString portName = ui->combo_Port->currentText();
    int cur = ui->combo_Baud ->currentIndex();
    switch (cur) {
    case 0:
            serialPort->setBaudRate(QSerialPort::Baud1200,QSerialPort::AllDirections);
        break;
    case 1:
            serialPort->setBaudRate(QSerialPort::Baud2400,QSerialPort::AllDirections);
        break;
    case 2:
            serialPort->setBaudRate(QSerialPort::Baud4800,QSerialPort::AllDirections);
        break;
    case 3:
            serialPort->setBaudRate(QSerialPort::Baud9600,QSerialPort::AllDirections);
        break;
    case 4:
            serialPort->setBaudRate(QSerialPort::Baud19200,QSerialPort::AllDirections);
        break;
    case 5:
            serialPort->setBaudRate(QSerialPort::Baud38400,QSerialPort::AllDirections);
        break;
    case 6:
            serialPort->setBaudRate(QSerialPort::Baud57600,QSerialPort::AllDirections);
        break;
    case 7:
            serialPort->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);
        break;
    case 8:
            serialPort->setBaudRate(256000,QSerialPort::AllDirections);
        break;
    case 9:
            serialPort->setBaudRate(384000,QSerialPort::AllDirections);
        break;
    case 10:
            serialPort->setBaudRate(576000,QSerialPort::AllDirections);
        break;
    default:
            serialPort->setBaudRate(QSerialPort::UnknownBaud,QSerialPort::AllDirections);
        break;
    }


    serialPort ->setParity(QSerialPort::NoParity);
    serialPort ->setStopBits(QSerialPort::OneStop);
    serialPort ->setFlowControl(QSerialPort::NoFlowControl);
 //   serialPort-> set

}

void MainWindow::openPort()
{



    if(ui->Btn_OorC->text() == "Open Port")
    {
        ConfigCom();
        ui->Btn_OorC->setText(tr("Close Port"));
        serialPort->open(QIODevice::ReadWrite);
        if(serialPort->isOpen()==false)
        {
            QMessageBox::warning(this,tr("Warning"),tr("Cannot open port!"));
            ui->Btn_OorC->setText(tr("Open Port"));

        }
        else
        {

            ui->combo_Baud->setEnabled(false);
            ui->combo_Port->setEnabled(false);
            ui->pushButton->setEnabled(true);
        }


    }
    else
    {
        ui->Btn_OorC->setText(tr("Open Port"));
        serialPort ->close();
        if(serialPort->isOpen()==true)
        {
            QMessageBox::warning(this,tr("Warning"),tr("Cannot close port!"));
            ui->Btn_OorC->setText(tr("Close Port"));
        }
        else
        {
            ui->pushButton->setEnabled(false);
            ui->combo_Baud->setEnabled(true);
            ui->combo_Port->setEnabled(true);
        }


    }


}

void MainWindow::on_Btn_OorC_clicked()
{
    openPort();
}

void MainWindow::on_pushButton_clicked()
{
    isOpen = serialPort->isOpen();
    if(isOpen)
    {
        if(ui->Edt_Send->toPlainText()==tr(""))
        {
            QMessageBox::warning(this,tr("info"),tr("Send data is empty!"));
            ui->statusBar->showMessage(tr("Send data is empty"),2000);
        }
        else
        {
            QString data = ui->Edt_Send->toPlainText();
            QByteArray bData;
            bData.append(data);
            serialPort->write(bData,bData.length());
            ui->statusBar->showMessage(tr("Send successfuily"),2000);
        }
    }
    else
    {
        QMessageBox::warning(this,tr("info"),tr("Serial port haven't been opened!"));
        ui->statusBar->showMessage(tr("Serial port haven't been opened"),2000);
    }
}


void MainWindow::revData()
{

    QByteArray bData;
    bData = serialPort->readAll();
    if(!bData.isEmpty())
    {
        QString str;
        str.prepend(bData);
        str=ui->Edt_Rev->toPlainText()+str;
        ui->Edt_Rev->setText(str);
        ui->Edt_Rev ->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
    }

}


void MainWindow::on_actionScan_port_S_triggered()
{
    ui->combo_Port->clear();
    this->getPortName();
}


void MainWindow::autoScanPort()
{
    if(!serialPort->isOpen())
    {
        ui->combo_Port->clear();
        this->getPortName();
    }

}
