/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit_IP;
    QLabel *label_3;
    QPushButton *pushButton_StandUp;
    QLabel *label_photo;
    QLineEdit *lineEdit;
    QLabel *label;
    QSlider *verticalSliderVolume;
    QPushButton *pushButton_2;
    QPushButton *pushButton_SitDown;
    QProgressBar *progressBarBattery;
    QPushButton *pushButton;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit_IP = new QLineEdit(centralwidget);
        lineEdit_IP->setObjectName(QString::fromUtf8("lineEdit_IP"));
        lineEdit_IP->setGeometry(QRect(130, 80, 181, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(680, 10, 61, 31));
        pushButton_StandUp = new QPushButton(centralwidget);
        pushButton_StandUp->setObjectName(QString::fromUtf8("pushButton_StandUp"));
        pushButton_StandUp->setGeometry(QRect(470, 50, 75, 23));
        label_photo = new QLabel(centralwidget);
        label_photo->setObjectName(QString::fromUtf8("label_photo"));
        label_photo->setGeometry(QRect(610, 240, 171, 261));
        label_photo->setScaledContents(true);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(160, 220, 421, 20));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 70, 61, 31));
        verticalSliderVolume = new QSlider(centralwidget);
        verticalSliderVolume->setObjectName(QString::fromUtf8("verticalSliderVolume"));
        verticalSliderVolume->setGeometry(QRect(630, 40, 22, 160));
        verticalSliderVolume->setValue(50);
        verticalSliderVolume->setOrientation(Qt::Vertical);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 270, 111, 23));
        pushButton_SitDown = new QPushButton(centralwidget);
        pushButton_SitDown->setObjectName(QString::fromUtf8("pushButton_SitDown"));
        pushButton_SitDown->setGeometry(QRect(470, 90, 75, 23));
        progressBarBattery = new QProgressBar(centralwidget);
        progressBarBattery->setObjectName(QString::fromUtf8("progressBarBattery"));
        progressBarBattery->setGeometry(QRect(680, 40, 31, 161));
        progressBarBattery->setValue(24);
        progressBarBattery->setOrientation(Qt::Vertical);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 220, 75, 23));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(620, 10, 61, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit_IP->setText(QCoreApplication::translate("MainWindow", "192.168.102.198", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Batterie", nullptr));
        pushButton_StandUp->setText(QCoreApplication::translate("MainWindow", "Stand Up", nullptr));
        label_photo->setText(QString());
        lineEdit->setText(QCoreApplication::translate("MainWindow", "Bonjour^start(animations/Stand/Gestures/Hey_1), Je suis connect\303\251 \303\240 votre application QT maintenant !", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Adresse IP : ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Bouger la t\303\252te", nullptr));
        pushButton_SitDown->setText(QCoreApplication::translate("MainWindow", "Sit Down", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Parler", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Volume", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
