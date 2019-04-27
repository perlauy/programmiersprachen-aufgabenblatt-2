#include "vec2.hpp"
#include "mat2.hpp"

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

TEST_CASE (" vec2_initializierung ", "[vec2_initializierung]")
{
  Vec2 vector_with_parameters{2.f, 5.5f};
  Vec2 vector_with_no_parameters;

  REQUIRE(vector_with_parameters.x == Approx(2.f));
  REQUIRE(vector_with_parameters.y == Approx(5.5f));
  REQUIRE(vector_with_no_parameters.x == Approx(0.f));
  REQUIRE(vector_with_no_parameters.y == Approx(0.f));  
}

TEST_CASE (" vec2_addition ", "[vec2_addition]")
{
  Vec2 vector_1{2.f, 1.5f};
  Vec2 vector_2{3.1f, 5.5f};
  Vec2 vector_3{-1.2f, -5.f};
  Vec2 vector_0;

  vector_1 += vector_0;
  REQUIRE(vector_1.x == Approx(2.f));
  REQUIRE(vector_1.y == Approx(1.5f));

  vector_1 += vector_2;
  REQUIRE(vector_1.x == Approx(5.1f));
  REQUIRE(vector_1.y == Approx(7.f));

  vector_1 += vector_3;
  REQUIRE(vector_1.x == Approx(3.9f));
  REQUIRE(vector_1.y == Approx(2.f));
}

TEST_CASE (" vec2_substraction ", "[vec2_substraction]")
{
  Vec2 vector_1{2.f, 1.5f};
  Vec2 vector_2{3.1f, 5.5f};
  Vec2 vector_3{-1.2f, -5.f};
  Vec2 vector_0;

  vector_1 -= vector_0;
  REQUIRE(vector_1.x == Approx(2.f));
  REQUIRE(vector_1.y == Approx(1.5f));

  vector_1 -= vector_2;
  REQUIRE(vector_1.x == Approx(-1.1f));
  REQUIRE(vector_1.y == Approx(-4.f));

  vector_1 -= vector_3;
  REQUIRE(vector_1.x == Approx(0.1f));
  REQUIRE(vector_1.y == Approx(1.f));
}

TEST_CASE (" vec2_scale ", "[vec2_scale]")
{
  Vec2 vector_1{2.f, 1.5f};
  Vec2 vector_0;

  vector_1 *= 1;
  REQUIRE(vector_1.x == Approx(2.f));
  REQUIRE(vector_1.y == Approx(1.5f));

  vector_1 *= -2;
  REQUIRE(vector_1.x == Approx(-4.f));
  REQUIRE(vector_1.y == Approx(-3.f));

  vector_1 /= 2;
  REQUIRE(vector_1.x == Approx(-2.f));
  REQUIRE(vector_1.y == Approx(-1.5f));

  vector_1 /= 1;
  REQUIRE(vector_1.x == Approx(-2.f));
  REQUIRE(vector_1.y == Approx(-1.5f));

  vector_1 *= 0;
  REQUIRE(vector_1.x == Approx(0.f));
  REQUIRE(vector_1.y == Approx(0.f));

//  vector_1 /= 0; //catch?
//  REQUIRE(vector_1.x == Approx(3.9f));
//  REQUIRE(vector_1.y == Approx(2.f));
}

TEST_CASE (" vec2_operations ", "[vec2_operations]")
{
  Vec2 vector_1{2.f, 1.5f};
  Vec2 vector_2{3.1f, 5.5f};
  Vec2 vector_3{-1.2f, -5.f};
  Vec2 vector_0;

  Vec2 vector_1_plus_0 = vector_1 + vector_0;
  REQUIRE(vector_1_plus_0.x == Approx(2.f));
  REQUIRE(vector_1_plus_0.y == Approx(1.5f));

  Vec2 vector_1_plus_2 = vector_1 + vector_2;
  REQUIRE(vector_1_plus_2.x == Approx(5.1f));
  REQUIRE(vector_1_plus_2.y == Approx(7.f));

  Vec2 vector_1_plus_3 = vector_1 + vector_3;
  REQUIRE(vector_1_plus_3.x == Approx(0.8f));
  REQUIRE(vector_1_plus_3.y == Approx(-3.5f));

  Vec2 vector_1_minus_0 = vector_1 - vector_0;
  REQUIRE(vector_1_minus_0.x == Approx(2.f));
  REQUIRE(vector_1_minus_0.y == Approx(1.5f));

  Vec2 vector_1_minus_2 = vector_1 - vector_2;
  REQUIRE(vector_1_minus_2.x == Approx(-1.1f));
  REQUIRE(vector_1_minus_2.y == Approx(-4.f));

  Vec2 vector_1_minus_3 = vector_1 - vector_3;
  REQUIRE(vector_1_minus_3.x == Approx(3.2f));
  REQUIRE(vector_1_minus_3.y == Approx(6.5f));

  Vec2 vector_1_by_1 = vector_1 * 1;
  REQUIRE(vector_1.x == Approx(2.f));
  REQUIRE(vector_1.y == Approx(1.5f));

  Vec2 vector_1_by_minus_2 = vector_1 * -2;
  REQUIRE(vector_1_by_minus_2.x == Approx(-4.f));
  REQUIRE(vector_1_by_minus_2.y == Approx(-3.f));

  Vec2 minus_2_by_vector_1 = -2 * vector_1;
  REQUIRE(minus_2_by_vector_1.x == Approx(-4.f));
  REQUIRE(minus_2_by_vector_1.y == Approx(-3.f));

  Vec2 vector_1_by_0 = vector_1 * 0;
  REQUIRE(vector_1_by_0.x == Approx(0.f));
  REQUIRE(vector_1_by_0.y == Approx(0.f));

  Vec2 vector_1_divided_2 = vector_1 / 2;
  REQUIRE(vector_1_divided_2.x == Approx(1.f));
  REQUIRE(vector_1_divided_2.y == Approx(0.75f));
}


TEST_CASE (" matrix ", "[matrix]")
{
  Mat2 matrix_1{2.f, 1.5f, 1.f, 2.f};
  Mat2 matrix_2{3.f, -5.f, -1.5f, 0.f};
  Mat2 matrix_default;

  Mat2 matrix_1_by_2 = matrix_1 * matrix_2;
  REQUIRE(matrix_1_by_2.e_00 == Approx(3.75f));
  REQUIRE(matrix_1_by_2.e_01 == Approx(-10.f));
  REQUIRE(matrix_1_by_2.e_10 == Approx(0.f));
  REQUIRE(matrix_1_by_2.e_11 == Approx(-5.f));

  Mat2 matrix_1_by_default = matrix_1 * matrix_default;
  REQUIRE(matrix_1_by_default.e_00 == Approx(2.f));
  REQUIRE(matrix_1_by_default.e_01 == Approx(1.5f));
  REQUIRE(matrix_1_by_default.e_10 == Approx(1.f));
  REQUIRE(matrix_1_by_default.e_11 == Approx(2.f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
