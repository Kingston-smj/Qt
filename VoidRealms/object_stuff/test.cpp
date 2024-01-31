#include "test.h"

test::test(QObject *parent)
    : QObject{parent}
{}

void test::dostuff()
{
    qInfo() << "Doing stuff: ";
    emit close();
}
