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

}

void inventory::load()
{

}
