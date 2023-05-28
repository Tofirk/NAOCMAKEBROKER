#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qi/future.hpp>
#include <alerror/alerror.h>
#include <alproxies/albatteryproxy.h>
#include <alproxies/alaudiodeviceproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <alproxies/alanimatedspeechproxy.h>
#include <alproxies/almotionproxy.h>
#include <QtSql/QtSql>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    qi::Future<int> MoveHead();
    qi::Future<int> StandUp();
    qi::Future<int> SitDown();
    qi::Future<int> Say(QString str);


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_verticalSliderVolume_valueChanged(int value);
    void on_pushButton_StandUp_clicked();
    void on_pushButton_SitDown_clicked();    


private:

    void doMoveHead(qi::Promise<int> promise);
    void doStandUp(qi::Promise<int> promise);
    void doSitDown(qi::Promise<int> promise);
    void doSay(QString str, qi::Promise<int> promise);

    Ui::MainWindow *ui;
    std::string robotIP;
    int port = 9559;
    AL::ALBatteryProxy* battery;
    AL::ALAudioDeviceProxy* audioDeviceProxy;
    AL::ALRobotPostureProxy *posture;
    AL::ALAnimatedSpeechProxy *speech;
    AL::ALMotionProxy *motion;

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    QSqlTableModel *tablemodel = new QSqlTableModel(this, db);

};


#endif // MAINWINDOW_H
