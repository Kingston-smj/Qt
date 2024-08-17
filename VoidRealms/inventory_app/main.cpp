#include <QCoreApplication>
#include <QTextStream>
#include "inventory.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo() << "Available commands";
    qInfo() << "add <name> <qty>";
    qInfo() << "remove <name> <qty>";
    qInfo() << "save";
    qInfo() << "load";
    qInfo() << "list";
    qInfo() << "quit";

    inventory Inventory;

    QTextStream stream(stdin);

    while (true){
        qInfo () << "enter a command";
        QString line = stream.readLine();
        QStringList list = line.split(" ");
        if(list.size() <= 0) break;

        QString command = list.at(0).toUpper();
        if (command == "QUIT" ){
            a.exit(0);
            break;
        }
        if (command == "LIST"){ Inventory.list();}
        if (command == "LOAD"){ Inventory.load();}
        if (command == "SAVE") {Inventory.save();}

        if(command == "ADD" || command == "REMOVE"){
            if(list.size() < 3){
                qWarning() << "NOt enough info";
                continue;
            }
            QString name = list.at(1);
            bool ok;
            int qty;
            qty = list.at(2).toInt(&ok);
            if (!ok){
                qWarning() << "invalid quatity";
                continue;
            }
            if(command == "ADD") {Inventory.add(name,qty);}
            if (command == "REMOVE") {Inventory.remove(name,qty);}
        }
    }
    Inventory.save();
    qInfo() << "Complete";
    return a.exec();
}
