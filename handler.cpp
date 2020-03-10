#include "handler.h"

Handler::Handler(QObject *parent) : QObject(parent), viewer(parent)
{
    pointList.push_back(Point(0,0));
}

void Handler::calcButtonClick()
{
    //QListView l;

    QObject* x = this->parent()->findChild<QObject*>("x");
    QObject* y = this->parent()->findChild<QObject*>("y");
    pointList.push_back(Point(x->property("text").toDouble(), y->property("text").toDouble()));

}

void Handler::addButtonClick()
{

}
