#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStringList>
#include "handler.h"
#include <QQuickView>
#include <QApplication>
#include <QGuiApplication>
#include <QStringList>

#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    QQmlApplicationEngine view;
    view.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QQmlContext *ctxt = view.rootContext();
    Handler handler(view.rootObjects()[0], ctxt);
    ctxt->setContextProperty("myModel", QVariant::fromValue(handler.getStringPoints()));

    ctxt->setContextProperty("handler", &handler);

    return app.exec();
}
