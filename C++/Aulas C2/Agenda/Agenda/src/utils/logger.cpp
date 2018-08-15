#include "logger.h"

#include <iostream>

#include <QDate>

using namespace std;


Logger *Logger::me = NULL;

Logger::Logger()
{
    // nothing to do
    cout << "Criando inst�ncia. " << endl;
}

Logger * Logger::getInstance() {
    if (!me) {
        me = new Logger();
    }
    return me;
}

void Logger::doLog ( QtMsgType type,  const QString msg ) {
      cout << type << msg.toStdString() << endl;
}

Logger::~Logger() {
    me = 0;
    cout << "Removendo inst�ncia. " << endl;
}


#include <QMessageLogContext>
void logHandler (QtMsgType type, const QMessageLogContext &,
                 const QString &msg) {
    Logger::getInstance()->doLog(type, msg);
}

