#ifndef RECT_HPP
#define RECT_HPP

#include "vec2.hpp"
#include "color.hpp"

class Rect {
  
  public:
                Rect();
                Rect(Rect const& r);
                Rect(Vec2 const& min, Vec2 const& max);

    float       circumference() const;
    
    Vec2        min() const;
    void        min(Vec2 const& pt);
    Vec2        max() const;
    void        max(Vec2 const& pt);

  private:
    Vec2  min_;
    Vec2  max_;
};

#endif
