#include "handler.h"


const QStringList& Handler::getStringPoints() const
{
    return stringPoints;
}

void Handler::deletePoint(const QString& text)
{
    stringPoints.removeOne(text);
    //double x, y;
    auto chs = text.split(' ');
    points.erase(points.find(Point(chs[0].toDouble(), chs[1].toDouble())));
    ctxt->setContextProperty("myModel", QVariant::fromValue(stringPoints));
}

Handler::Handler(QObject *parent, QQmlContext *ctxt) : QObject(parent), ctxt(ctxt),
    points(std::function<bool (const Point&, const Point&)>(
               [](const Point& p1, const Point& p2) { return p1.getX() < p2.getX(); }))
{}

void Handler::calcButtonClick()
{
    if(func.splainsCount() == 0)
        return;
    QObject* res = this->parent()->findChild<QObject*>("res");
    QObject* x = this->parent()->findChild<QObject*>("x");
    res->setProperty("text", func(x->property("text").toDouble()));

}

void Handler::addButtonClick()
{
    QObject* x = this->parent()->findChild<QObject*>("xf");
    QObject* y = this->parent()->findChild<QObject*>("yf");
    auto xv = x->property("text").toString(), yv = y->property("text").toString();//.toDouble();
    points.emplace(Point(xv.toDouble(), yv.toDouble()));
    stringPoints.append(xv + " " + yv);
    ctxt->setContextProperty("myModel", QVariant::fromValue(stringPoints));

}

void Handler::solveButtonClick()
{
    func = interpolate(points.begin(), points.end());
    QObject* res = this->parent()->findChild<QObject*>("resFunc");
    auto string = func.toString();
    res->setProperty("text", QString::fromStdString(string));
}
