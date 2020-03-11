#ifndef POINT_H
#define POINT_H

class Point
{
  double x,y;
public:
  Point(double x, double y) : x(x), y(y) {}

  bool operator< (const Point& p)
  {
      return x < p.x;
  }

  double getX() const
  {
      return x;
  }

  void setX(double value)
  {
      x = value;
  }

  double getY() const
  {
      return y;
  }

  void setY(double value)
  {
      y = value;
  }

};

#endif // POINT_H
