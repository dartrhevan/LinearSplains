#ifndef POINTLIST_H
#define POINTLIST_H

#include <QAbstractListModel>
#include <QObject>
#include <vector>
#include "point.h"
/*
class PointList : public QAbstractListModel {
public:
    // Собственно метод для доступа к элементу
    //Q_INVOKABLE Employee* getPoint( int index );

    // Обязательная реализация QAbstractListModel:
    int rowCount( const QModelIndex& parent ) const override {
        return points.size();
    }

    // Этот метод не реализован, т.к. у нас нет ролей.
    QVariant data( const QModelIndex& index, int role ) const override {
        return QVariant();
    }

    // И где-то тут должны быть методы для добавления и удаления элементов
    // в модель и внутренний QList, а также все необходимые вызовы
    // beginInsertRows(), endInsertRows() и им подобные.
    // Тут все стандартно, как в документации, никакой магии.

private:

    std::vector<Point> points;//<Employee*> personal;
}*/
#endif // POINTLIST_H
