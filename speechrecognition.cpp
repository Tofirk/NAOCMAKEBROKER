#include "speechrecognition.h"


SpeechRecognition::SpeechRecognition(boost::shared_ptr<AL::ALBroker> broker, const std::string& name, QObject *parent):
    AL::ALModule(broker, name), QObject(parent)
{
    /// Class functions that need to be bound to be called in Python or by remote processes.
    functionName("startRecognition",
                 getName(),
                 "This function will launch the ASR engine.");
    BIND_METHOD(SpeechRecognition::startRecognition);

    functionName("stopRecognition",
                 getName(),
                 "This function will stop the ASR engine.");
    BIND_METHOD(SpeechRecognition::stopRecognition);

    functionName("onSpeechRecognized",
                 getName(),
                 "Called by ALMemory when a word is recognized.");
    BIND_METHOD(SpeechRecognition::onSpeechRecognized);

    /// Specify a command to which the robot will react.

    qDebug() << getName().c_str() << " a été créé !";
}

void SpeechRecognition::startRecognition()
{
    qDebug() << "startRecognition is running......!";
    /// Setting up a proxy to ALTextToSpeech
     fTextToSpeech = getParentBroker()->getProxy("ALTextToSpeech");
     /// Setting the language to "English"
     fTextToSpeech->callVoid("setLanguage",std::string("French"));

  /// Setting up a proxy to ALMemory
  fMemory = getParentBroker()->getMemoryProxy();
    qDebug() << "fMemory = getParentBroker()->getMemoryProxy()";
  /// Setting up a proxy to ALSpeechRecognition
  fSpeechRecognition = getParentBroker()->getProxy("ALSpeechRecognition");
  qDebug() << "fSpeechRecognition = getParentBroker()->getProxy(\"ALSpeechRecognition\")";
  /// Setting the working language of speech recognition engine
  fSpeechRecognition->callVoid("setLanguage",std::string("French"));
    qDebug() << " fSpeechRecognition->callVoid(\"setLanguage\",std::string(\"French\"))";

  /// Setting the word list that should be recognized
  std::vector<std::string> wordlist;
  fSpeechRecognition->callVoid("pause",true);
  wordlist.push_back("Coucou");
  wordlist.push_back("Nao");
  wordlist.push_back("Salut");
  fSpeechRecognition->callVoid("setWordListAsVocabulary", wordlist);



  fTextToSpeech->callVoid("say",std::string("Reconnaissance vocale activée"));
   /// Launching the speech recognition engine by subscribing to a ALMemory key
   /// that is fed by ALSpeechRecognition. Note that a callback function is specified.

  fSpeechRecognition->callVoid("pause",false);
  fMemory->subscribeToEvent("WordRecognized",getName(),"onSpeechRecognized");
  subscriber = fMemory->subscriber("WordRecognized");



  qDebug() << "Pause is now Off and Recognition is ready";


}

void SpeechRecognition::stopRecognition()
{
  /// Stopping the speech recognition engine by unsubscribing to the ALMemory key
  fMemory->unsubscribeToEvent("WordRecognized",getName());
}


/// This function is called by ALMemory every time the value of
/// the key "WordRecognized" is modified by the speech recognition engine.
void SpeechRecognition::onSpeechRecognized(const std::string& name,
                                             const AL::ALValue& val,
                                             const std::string& myName)
{
    emit onWordDetected();
    fTextToSpeech->callVoid("say",std::string("Ok, Hello There!"));
  /// Parse the list of words that has been recognized by ALSpeechRecognition
  for(unsigned int i = 0; i < val.getSize()/2 ; ++i)
  {
    qDebug() << "word recognized: " << val[i*2].toString().c_str()
              << " with confidence: " << (float)val[i*2+1] ;
    /// If our "command" has been recognized, start a speech synthesis reaction
        if((std::string)val[i*2] == "Coucou" && (float)val[i*2+1] > 0.15)
        {
          fTextToSpeech->callVoid("say",std::string("Ok, Salut tout le monde !"));
        }
      }

}
