#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QtGui>
#include <vector>
#include "point.h"
#include <QListView>


class Handler : public QObject
{
    Q_OBJECT
    std::vector<Point> pointList;
    QObject *viewer;
public:
    explicit Handler(QObject *parent = nullptr);

     QStringList strings = {"dsfg", "dsfdgf"};
signals:

public slots:
    void calcButtonClick();
    void addButtonClick();
};

#endif // HANDLER_H
