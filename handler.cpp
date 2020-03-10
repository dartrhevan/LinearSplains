#include "handler.h"

const QStringList& Handler::getStringPoints() const
{
    return stringPoints;
}

Handler::Handler(QObject *parent, QQmlContext *ctxt) : QObject(parent), ctxt(ctxt)//, viewer(parent), ctxt(parent->rootContext())
{

}

void Handler::calcButtonClick()
{
    //QListView l;
}

void Handler::addButtonClick()
{
    QObject* x = this->parent()->findChild<QObject*>("xf");
    QObject* y = this->parent()->findChild<QObject*>("yf");
    auto xv = x->property("text").toString();//.toDouble();
    auto p = Point(xv.toDouble(), y->property("text").toDouble());
    pointList.push_back(p);
    stringPoints.append(x->property("text").toString() + " " + y->property("text").toString());
    ctxt->setContextProperty("myModel", QVariant::fromValue(stringPoints));

}
