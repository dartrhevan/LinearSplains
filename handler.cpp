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
    QObject* res = this->parent()->findChild<QObject*>("res");
    QObject* x = this->parent()->findChild<QObject*>("x");
    res->setProperty("res", func(x->property("text").toDouble()));

}

void Handler::addButtonClick()
{
    QObject* x = this->parent()->findChild<QObject*>("xf");
    QObject* y = this->parent()->findChild<QObject*>("yf");
    auto xv = x->property("text").toString(), yv = y->property("text").toString();//.toDouble();
    pointList.push_back(Point(xv.toDouble(), yv.toDouble()));
    stringPoints.append(xv + " " + yv);
    ctxt->setContextProperty("myModel", QVariant::fromValue(stringPoints));

}

void Handler::solveButtonClick()
{
    std::sort(pointList.begin(), pointList.end());
    func = interpolate(pointList);
    QObject* res = this->parent()->findChild<QObject*>("resFunc");
    auto string = func.toString();
    res->setProperty("text", QString::fromStdString(string));
}
