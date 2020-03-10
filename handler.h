#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QtGui>
#include <vector>
#include "point.h"
#include <QListView>

#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

class Handler : public QObject
{
    Q_OBJECT
    std::vector<Point> pointList;
    QObject *viewer;
    QQmlContext *ctxt;
    QStringList stringPoints = {"dsfg", "dsfdgf"};


public:
    explicit Handler(QObject *parent = nullptr, QQmlContext *ctxt = nullptr);

    const QStringList& getStringPoints() const;

signals:

public slots:
    void calcButtonClick();
    void addButtonClick();
};

#endif // HANDLER_H
