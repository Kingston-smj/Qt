#include <QCoreApplication>

#include "test.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test test;

    //connect signal and slot
    QObject::connect(&test,&test::close,&a,&QCoreApplication::quit,Qt::QueuedConnection);

    test.dostuff();
    int value = a.exec();
    qInfo() << "Exit value"<< value;

    return value;
}
