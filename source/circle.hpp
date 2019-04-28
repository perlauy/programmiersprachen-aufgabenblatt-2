#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"

class Circle {
  
  public:
                   Circle();
                   Circle(Circle const& c);
                   Circle(Vec2 const& center, float radius, Color const& color);
  
    double         circumference() const;
    
    Vec2           center() const;
    void           center(Vec2 const& center);
    float          radius() const;
    void           radius(float radius);
    Color          color() const;
    void           color(Color const& color);

  private:
    Vec2  center_;
    float radius_;
    Color color_;
};

#endif
