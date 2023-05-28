#ifndef SPEECHRECOGNITION_H
#define SPEECHRECOGNITION_H

#include <QObject>
#include <alcommon/almodule.h>
#include <boost/shared_ptr.hpp>
#include <alcommon/alproxy.h>
#include <alcommon/albroker.h>
#include <alvalue/alvalue.h>
#include <alproxies/almemoryproxy.h>
#include <alcommon/albrokermanager.h>
#include <alcommon/altoolsmain.h>
#include <alcommon/api.h>
#include <signal.h>
#include <QDebug>

namespace AL
{
  class ALBroker;
}

class SpeechRecognition : public QObject, public AL::ALModule
{
    Q_OBJECT
public:
    explicit SpeechRecognition(boost::shared_ptr<AL::ALBroker> broker, const std::string& name, QObject *parent = nullptr);

    void startRecognition();

    void stopRecognition();

    void onSpeechRecognized(const std::string& name,
                            const AL::ALValue& val,
                            const std::string& myName);

signals:

        void onWordDetected();

private :

    boost::shared_ptr<AL::ALMemoryProxy> fMemory;
    boost::shared_ptr<AL::ALProxy> fSpeechRecognition;
    boost::shared_ptr<AL::ALProxy> fTextToSpeech;
    qi::AnyObject subscriber;

};

#endif // SPEECHRECOGNITION_H
