#ifndef POINT_H
#define POINT_H

class Point
{
  double x,y;
public:
  Point(double x, double y) : x(x), y(y) {}
/*
  bool operator< (const Point& p)
  {
      return x < p.x;
  }
*/
  bool operator== (const Point& p) const
  {
      return x == p.x && y == p.y;
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

  Point(Point&&) noexcept = default;

  Point& operator=(Point&&) noexcept = default;
  Point(const Point&) = default;

  Point& operator=(const Point&) = default;

};
/*
bool operator< (const Point& p, const Point& p2)
{
    return p.getX() < p2.getX();
}
*/
#endif // POINT_H
