#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QString>
#include <QMessageLogContext>


class Logger {
private:
    static Logger *me;
    Logger();
public:
    static Logger * getInstance();
    void doLog( QtMsgType type,  const QString msg);
    ~Logger();
};

void logHandler (QtMsgType type, const QMessageLogContext &,
                 const QString &msg);


#endif // LOGGER_H



