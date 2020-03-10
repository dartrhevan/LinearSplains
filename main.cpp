#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStringList>
#include "handler.h"
#include <QQuickView>

#include <QGuiApplication>
#include <QStringList>

#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

int main(int argc, char ** argv)
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine view;
    view.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QQmlContext *ctxt = view.rootContext();
    Handler handler(view.rootObjects()[0], ctxt);
    ctxt->setContextProperty("myModel", QVariant::fromValue(handler.getStringPoints()));

    ctxt->setContextProperty("handler", &handler);
    //view.setSource(QUrl("qrc:main.qml"));
    //view.show();

    return app.exec();
}
/*
int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject* root = engine.rootObjects()[0];
    Handler myClass(root);
    engine.rootContext()->setContextProperty("_myClass", &myClass);
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
*/
