#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "vec2.hpp"
#include "color.hpp"

class Rectangle {
  
  public:
                Rectangle();
                Rectangle(Rectangle const& r);
                Rectangle(Vec2 const& min, Vec2 const& max);

    Vec2        min() const;
    void        min(Vec2 const& pt);
    Vec2        max() const;
    void        max(Vec2 const& pt);

  private:
    Vec2  min_;
    Vec2  max_;
};

#endif
