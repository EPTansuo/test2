/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionScan_port_S;
    QWidget *centralWidget;
    QPushButton *Btn_OorC;
    QGroupBox *groupBox;
    QComboBox *combo_Baud;
    QLabel *baud;
    QComboBox *combo_Port;
    QLabel *protName;
    QPushButton *pushButton;
    QPlainTextEdit *Edt_Send;
    QTextEdit *Edt_Rev;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menuOperation_O;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(742, 539);
        QFont font;
        font.setFamily(QStringLiteral("YaHei Consolas Hybrid"));
        font.setPointSize(12);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/USB_48px_1138496_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionScan_port_S = new QAction(MainWindow);
        actionScan_port_S->setObjectName(QStringLiteral("actionScan_port_S"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Btn_OorC = new QPushButton(centralWidget);
        Btn_OorC->setObjectName(QStringLiteral("Btn_OorC"));
        Btn_OorC->setGeometry(QRect(540, 180, 101, 41));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(440, 20, 291, 151));
        combo_Baud = new QComboBox(groupBox);
        combo_Baud->setObjectName(QStringLiteral("combo_Baud"));
        combo_Baud->setGeometry(QRect(120, 110, 141, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("YaHei Consolas Hybrid"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        combo_Baud->setFont(font1);
        baud = new QLabel(groupBox);
        baud->setObjectName(QStringLiteral("baud"));
        baud->setGeometry(QRect(40, 110, 51, 20));
        baud->setFont(font1);
        combo_Port = new QComboBox(groupBox);
        combo_Port->setObjectName(QStringLiteral("combo_Port"));
        combo_Port->setGeometry(QRect(120, 50, 141, 31));
        combo_Port->setFont(font1);
        protName = new QLabel(groupBox);
        protName->setObjectName(QStringLiteral("protName"));
        protName->setGeometry(QRect(10, 60, 101, 21));
        protName->setFont(font1);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(540, 230, 101, 41));
        Edt_Send = new QPlainTextEdit(centralWidget);
        Edt_Send->setObjectName(QStringLiteral("Edt_Send"));
        Edt_Send->setGeometry(QRect(470, 300, 251, 161));
        Edt_Rev = new QTextEdit(centralWidget);
        Edt_Rev->setObjectName(QStringLiteral("Edt_Rev"));
        Edt_Rev->setGeometry(QRect(10, 30, 431, 431));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 151, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(460, 280, 151, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 742, 30));
        menuOperation_O = new QMenu(menuBar);
        menuOperation_O->setObjectName(QStringLiteral("menuOperation_O"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuOperation_O->menuAction());
        menuOperation_O->addAction(actionScan_port_S);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SerialPort", Q_NULLPTR));
        actionScan_port_S->setText(QApplication::translate("MainWindow", "Scan port (&S)", Q_NULLPTR));
        Btn_OorC->setText(QApplication::translate("MainWindow", "Open Port", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Config Com", Q_NULLPTR));
        baud->setText(QApplication::translate("MainWindow", "Baud:", Q_NULLPTR));
        protName->setText(QApplication::translate("MainWindow", "Port Name:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Reveive area:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Send area:", Q_NULLPTR));
        menuOperation_O->setTitle(QApplication::translate("MainWindow", "Operation(&O)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
