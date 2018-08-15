#include "view/mainwindow.h"
#include <QApplication>

#include "utils/logger.h"

int main(int argc, char *argv[]) {
    qInstallMessageHandler(logHandler);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
