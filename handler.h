#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QtGui>
#include <set>
#include "point.h"
#include <QListView>
#include "interpolate.h"
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include "resultfunction.h"
#include <functional>

class Handler : public QObject
{
    Q_OBJECT
    std::set<Point, std::function<bool (const Point&, const Point&)>> points;
    QObject *viewer;
    QQmlContext *ctxt;
    QStringList stringPoints;
    ResultFunction func;

public:
    explicit Handler(QObject *parent = nullptr, QQmlContext *ctxt = nullptr);
    const QStringList& getStringPoints() const;

signals:

public slots:
    void deletePoint(const QString&);
    void calcButtonClick();
    void addButtonClick();
    void solveButtonClick();
};

#endif // HANDLER_H
