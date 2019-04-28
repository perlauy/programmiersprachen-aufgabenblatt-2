#define _USE_MATH_DEFINES

#include "circle.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "window.hpp"

#include <cmath>

Circle::Circle() :
  center_{0.f, 0.f},
  radius_{1.f},
  color_{0.5f,0.5f,0.5f}
{}

Circle::Circle(Circle const& c) :
  center_{c.center_},
  radius_{c.radius_},
  color_{c.color_}
{}

Circle::Circle(Vec2 const& center, float radius, Color const& color) :
  center_{center},
  radius_{radius},
  color_{color}
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

double Circle::circumference() const {
  return 2 * radius_ * M_PI;
}

void Circle::draw(Window const& window, unsigned int facets) const {

  Mat2 rotation_matrix = make_rotation_mat2(2 * M_PI / facets);
  Vec2 start_point{center_.x + radius_, center_.y};
  Vec2 next_point;

  for(unsigned int i = 0; i < facets; i++) {
    next_point = start_point * rotation_matrix;
    
    window.draw_line(start_point.x, start_point.y, next_point.x, next_point.y, color_.r, color_.g, color_.b);
    
    start_point = next_point;
  }

}
