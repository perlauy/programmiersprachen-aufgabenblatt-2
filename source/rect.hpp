#ifndef RECT_HPP
#define RECT_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rect {
  
  public:
                Rect();
                Rect(Rect const& r);
                Rect(Vec2 const& min, Vec2 const& max, Color const& color);

    float       circumference() const;
    void        draw(Window const& window) const;

    Vec2        min() const;
    void        min(Vec2 const& pt);
    Vec2        max() const;
    void        max(Vec2 const& pt);
    Color       color() const;
    void        color(Color const& color);

  private:
    Vec2  min_;
    Vec2  max_;
    Color color_;
};

#endif
