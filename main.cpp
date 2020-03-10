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

//![0]
    QStringList dataList;
    dataList.append("Item 14");
    dataList.append("Item 2");
    dataList.append("Item 3");
    dataList.append("Item 4");

    QQuickView view;
    Handler handler(&view);
    QQmlContext *ctxt = view.rootContext();
    ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));
//![0]
    ctxt->setContextProperty("handler", &handler);
    view.setSource(QUrl("qrc:main.qml"));
    view.show();

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
    Handler handler(root);
    engine.rootContext()->setContextProperty("handler", &handler);


     engine.rootContext()->setContextProperty("myModel", QVariant::fromValue(dataList));
     if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
*/
