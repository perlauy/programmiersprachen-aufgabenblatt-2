#include "rect.hpp"
#include "vec2.hpp"
#include "color.hpp"

#include <cmath>

Rect::Rect() :
  min_{0.f, 0.f},
  max_{1.f, 1.f}
{};

Rect::Rect(Rect const& r) :
  min_{r.min_},
  max_{r.max_}
{};

Rect::Rect(Vec2 const& min, Vec2 const& max) :
  min_{min},
  max_{max}
{}

Vec2 Rect::min() const {
  return min_;
}

void Rect::min(Vec2 const& pt) {
  min_ = pt;
}

Vec2 Rect::max() const {
  return max_;
}

void Rect::max(Vec2 const& pt) {
  max_ = pt;
}

float Rect::circumference() const {
  return 2 * (abs(max_.x - min_.x) + abs(max_.y - min_.y));
}
