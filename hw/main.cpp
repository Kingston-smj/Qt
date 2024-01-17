#include <QCoreApplication>
#include <iostream>
#include <QTextStream>
#include <QDebug>

using namespace std;

void do_cpp(){
    string name;
    cout << "enter your name ";
    cin >> name;
    cout << "helllo " << name << '\n';
}
void do_qt(){
    QTextStream qin(stdin);
    QTextStream qout(stdout);
    QString name;
    qout << "enter name ";
    qout.flush();
    name = qin.readLine();
    qout << "hello " << name << '\n';
}
void do_both(){
    QTextStream qin(stdin);
    qInfo() << "Enter your name: ";
    QString name = qin.readLine();
    qInfo() << "Hello" << name;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //do_cpp();
    //do_qt();
    do_both();
    return a.exec();
}
