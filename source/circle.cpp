#include "circle.hpp"
#include "vec2.hpp"
#include "color.hpp"

Circle::Circle() :
  center_{0.f, 0.f},
  radius_{1.f}
{}

Circle::Circle(Circle const& c) :
  center_{c.center_},
  radius_{c.radius_}
{}

Circle::Circle(Vec2 const& center, float radius) :
  center_{center},
  radius_{radius}
{}

Vec2 Circle::center() const {
  return center_;
}

void Circle::center(Vec2 const& center) {
  center_ = center;
}

float Circle::radius() const {
  return radius_;
}

void Circle::radius(float radius) {
  radius_ = radius;
}
  