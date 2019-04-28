#include "rectangle.hpp"
#include "vec2.hpp"
#include "color.hpp"

Rectangle::Rectangle() :
  min_{0.f, 0.f},
  max_{1.f, 1.f}
{}

Rectangle::Rectangle(Rectangle const& r) :
  min_{r.min_},
  max_{r.max_}
{}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max) :
  min_{min},
  max_{max}
{}

Vec2 Rectangle::min() const {
  return min_;
}

void Rectangle::min(Vec2 const& pt) {
  min_ = pt;
}

Vec2 Rectangle::max() const {
  return max_;
}

void Rectangle::max(Vec2 const& pt) {
  max_ = pt;
}
