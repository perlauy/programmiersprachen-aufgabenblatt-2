#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"

class Circle {
  
  public:
                   Circle();
                   Circle(Circle const& c);
                   Circle(Vec2 const& center, float radius);

    Vec2           center() const;
    void           center(Vec2 const& center);
    float          radius() const;
    void           radius(float r);

  private:
    Vec2  center_;
    float radius_;
};

#endif
