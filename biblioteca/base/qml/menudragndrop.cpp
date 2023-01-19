#include "menudragndrop.h"

menudragndrop::menudragndrop(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant menudragndrop::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex menudragndrop::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex menudragndrop::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int menudragndrop::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int menudragndrop::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant menudragndrop::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
