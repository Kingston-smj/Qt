#include "inventory.h"

inventory::inventory(QObject *parent)
    : QObject{parent}
{
    load();
}

void inventory::add(QString name, int qty)
{
    if(m_items.contains(name)){
        m_items[name] += qty;
    }
    esle{
        m_items.insert(name,qty);
    }
}

void inventory::remove(QString name, int qty)
{
    if(m_items.contains(name)){
        m_items[name] -= qty;
        if(m_items.value(name)< 0)m_items.remove(name);
        qInfo() << "Item removed";
    }
    esle{
        qWarning() << "Item doesn't exist";
    }
}

void inventory::list()
{
    qInfo() << "Items: " << m_items.size();
    foreach (QString key, m_items.keys()) {
        qInfo() << key << " - " << m_items.value(key);
    }
}

void inventory::save()
{
    QFile file("inventory.txt");
    if(!file.open(QIODevice::WriteOnly)){
        qCritical() << "could not save file: " << file.errorString();
        return;
    }
    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_6);

    int len = m_items.size();
    stream << len;

    qInfo() << "Number of items to save: " << len;
    foreach (QString key, m_items.keys()) {
        qInfo() << "Saving: " << key;
        stream << key;
        stream << m_items.value(key);
    }
    file.close();
    qInfo() << "File saved";
}

void inventory::load()
{
    Qile file("inventory.txt");
    if(!file.exists()){
        qWarning() << "File doesn't exist ";
        return;
    }
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "could not save file: " << file.errorString();
        return;
    }
    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_6);

    int len = m_items.size();
    stream << len;

    qInfo() << "Number of items to save: " << len;
    foreach (QString key, m_items.keys()) {
        qInfo() << "Saving: " << key;
        stream << key;
        stream << m_items.value(key);
    }
    file.close();
    qInfo() << "FIle saved";
}
