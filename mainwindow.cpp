#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db.setHostName("localhost");
    db.setDatabaseName("nao");
    db.setUserName("root");
    db.setPassword("");
    db.setPort(3306);
    db.open();
    int reponse;

    if(!db.isOpen())
    {
      QMessageBox msgBox;
      msgBox.setText("Connexion à la base de données impossible !!! \n" + db.lastError().text());
      msgBox.setInformativeText("Voulez vous tenter une nouvelle connexion ? ");
      msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
      msgBox.setDefaultButton(QMessageBox::Cancel);
      msgBox.setIcon(QMessageBox::Critical);


      do
       {
         db.open();
         reponse = msgBox.exec();

       }while(!db.isOpen()&& (reponse !=QMessageBox::Cancel));
    }

    if(!db.isOpen() && reponse == QMessageBox::Cancel) this->close();
    else
    {

      QMessageBox msgBox;
      msgBox.setText("Connectée à la base de données ");
      msgBox.setInformativeText("Connexion à la base de données réussie... \nDataBase : "
                                                         + db.databaseName()
                                                         + "\nServeur : "
                                                         + db.hostName());
      msgBox.setStandardButtons(QMessageBox::Ok);

      msgBox.setIcon(QMessageBox::Information);
      msgBox.exec();
    }

    ui->label_photo->setPixmap(QPixmap(":/NAO.png"));
    ui->label_photo->setScaledContents(true);

    robotIP = ui->lineEdit_IP->text().toStdString().c_str();
    qDebug() << &robotIP;
    battery = new AL::ALBatteryProxy(robotIP,port);
    ui->progressBarBattery->setValue(battery->getBatteryCharge());
    audioDeviceProxy = new AL::ALAudioDeviceProxy(robotIP, port);
    ui->verticalSliderVolume->setValue(audioDeviceProxy->getOutputVolume());

    QSqlQuery query;
    query.exec("SELECT * from seance WHERE question_en_cours = 1;");
    query.next();
    QVariant variant = query.value(1);
    QString intitule = variant.toString();
    qDebug() << "intitule :" << intitule;

    QString nombre = "";
    for(int i = 7; i < intitule.count();i++)
        nombre+= intitule[i];
    qDebug() <<"nombre:" << nombre;
    QString seance = "seance"+nombre;
    query.exec("SELECT * from "+seance+" WHERE 1;");

    query.next();
    variant = query.value(1);
    QString question = variant.toString();
    qDebug() << "Question : " << question ;
    Say(question);

}


MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_clicked()
{
    Say(ui->lineEdit->text());
    QSqlQuery query;
    query.exec("SELECT * from questions WHERE idQuestions = 1;");
    query.next();
    QVariant variant = query.value(1);
    QString question = variant.toString();
    qDebug() << "Question : " << question ;
    Say(question);
}


void MainWindow::on_pushButton_2_clicked()
{
    MoveHead();
}

qi::Future<int> MainWindow::Say(QString str)
{
    qi::Promise<int> promise;
    qi::async(boost::bind(&MainWindow::doSay, this, str, promise));
    return promise.future();
}

void MainWindow::doSay(QString str, qi::Promise<int> promise)
{
    try {

    speech = new AL::ALAnimatedSpeechProxy(robotIP, port);
    speech->say(str.toStdString().c_str());
    promise.setValue(1);
    }  catch (AL::ALError e) {
        promise.setValue(0);
    }
}


qi::Future<int> MainWindow::MoveHead()
{
      qi::Promise<int> promise;
      qi::async(boost::bind(&MainWindow::doMoveHead, this, promise));
      return promise.future();
}

void MainWindow::doMoveHead(qi::Promise<int> promise)
{
    try {
        motion = new AL::ALMotionProxy(robotIP, port);
        const AL::ALValue jointName = "HeadYaw";
        AL::ALValue stiffness = 1.0f;
            // Time (in seconds) to reach the target.
        AL::ALValue time = 1.0f;
            //Call the stiffness interpolation method.
        motion->stiffnessInterpolation(jointName, stiffness, time);

        // Set the target angle list, in radians.
        AL::ALValue targetAngles = AL::ALValue::array(-1.5f, 1.5f, 0.0f);
            // Set the corresponding time lists, in seconds.
        AL::ALValue targetTimes = AL::ALValue::array(3.0f, 6.0f, 9.0f);
            // Specify that the desired angles are absolute.
        bool isAbsolute = true;
        motion->angleInterpolation(jointName, targetAngles, targetTimes, isAbsolute);

        // Remove the stiffness on the head.
         stiffness = 0.0f;
         time = 1.0f;
        motion->stiffnessInterpolation(jointName, stiffness, time);
        promise.setValue(1);
    }
    catch (AL::ALError e) {
        promise.setValue(0);
    }
}


void MainWindow::on_verticalSliderVolume_valueChanged(int value)
{
    audioDeviceProxy = new AL::ALAudioDeviceProxy(robotIP, port);
    audioDeviceProxy->setOutputVolume(value);
}

void MainWindow::on_pushButton_StandUp_clicked()
{
    StandUp();
}

qi::Future<int> MainWindow::StandUp()
{
    qi::Promise<int> promise;
    qi::async(boost::bind(&MainWindow::doStandUp, this, promise));
    return promise.future();

}

void MainWindow::doStandUp(qi::Promise<int> promise)
{
    try {

        posture = new AL::ALRobotPostureProxy(robotIP, port);
        posture->goToPosture("Stand",1.0);
        promise.setValue(1);
    }  catch (AL::ALError e) {
        promise.setValue(0);
    }
}

void MainWindow::on_pushButton_SitDown_clicked()
{
    SitDown();
}

qi::Future<int> MainWindow::SitDown()
{
    qi::Promise<int> promise;
    qi::async(boost::bind(&MainWindow::doSitDown, this, promise));
    return promise.future();
}

void MainWindow::doSitDown(qi::Promise<int> promise)
{
    try {

        posture = new AL::ALRobotPostureProxy(robotIP, port);
        posture->goToPosture("Sit",1.0);
        promise.setValue(1);
    }  catch (AL::ALError e) {
        promise.setValue(0);
    }
}




