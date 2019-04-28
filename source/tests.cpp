#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rect.hpp"

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

TEST_CASE (" vec2_initializierung ", "[vec2_initializierung]")
{
  Vec2 vector_with_parameters{2.f, 5.5f};
  Vec2 vector_with_no_parameters;

  REQUIRE(vector_with_parameters.x == Approx(2.f));
  REQUIRE(vector_with_parameters.y == Approx(5.5f));
  REQUIRE(vector_with_no_parameters.x == 0.0f);
  REQUIRE(vector_with_no_parameters.y == 0.0f);  
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
  REQUIRE(vector_1.x == 0.0f);
  REQUIRE(vector_1.y == 0.0f);

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
  REQUIRE(vector_1_by_0.x == 0.0f);
  REQUIRE(vector_1_by_0.y == 0.0f);

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

TEST_CASE (" matrix_operations ", "[matrix_operations]")
{
  Mat2 matrix_1{2.f, 1.5f, -1.f, 2.f};  
  Vec2 vector{2.f, -3.f};
  Mat2 matrix_default;

  Vec2 multiply_result_1 = matrix_1 * vector;
  REQUIRE(multiply_result_1.x == Approx(-.5f));
  REQUIRE(multiply_result_1.y == Approx(-8.f));

  Vec2 multiply_result_2 = vector * matrix_1;
  REQUIRE(multiply_result_2.x == Approx(-.5f));
  REQUIRE(multiply_result_2.y == Approx(-8.f));

  Mat2 inversed_matrix = inverse(matrix_1);
  REQUIRE(inversed_matrix.e_00 == Approx(0.363636f));
  REQUIRE(inversed_matrix.e_01 == Approx(-0.272727f));
  REQUIRE(inversed_matrix.e_10 == Approx(0.181818f));
  REQUIRE(inversed_matrix.e_11 == Approx(0.363636f));

  Mat2 transposed_matrix = transpose(matrix_1);
  REQUIRE(transposed_matrix.e_00 == Approx(2.f));
  REQUIRE(transposed_matrix.e_01 == Approx(-1.f));
  REQUIRE(transposed_matrix.e_10 == Approx(1.5f));
  REQUIRE(transposed_matrix.e_11 == Approx(2.f));

  Mat2 rotation_matrix = make_rotation_mat2(0.26179938f); //15 in radians
  REQUIRE(rotation_matrix.e_00 == Approx(0.9659258f));
  REQUIRE(rotation_matrix.e_01 == Approx(-.2588190f));
  REQUIRE(rotation_matrix.e_10 == Approx(0.2588190f));
  REQUIRE(rotation_matrix.e_11 == Approx(0.9659258f));
}

TEST_CASE (" color ", "[color]")
{
  Color color_1{0.2f, 0.15f, 0.f};
  Color color_default;
  Color color_2{-1.f, 3.3f, 0.f};

  REQUIRE(color_1.r == Approx(0.2f));
  REQUIRE(color_1.g == Approx(0.15f));
  REQUIRE(color_1.b == Approx(0.f));

  REQUIRE(color_default.r == Approx(0.5f));
  REQUIRE(color_default.g == Approx(0.5f));
  REQUIRE(color_default.b == Approx(0.5f));

 // REQUIRE(color_2.r == Approx(0.f));
 // REQUIRE(color_2.g == Approx(1.f));
 // REQUIRE(color_2.b == Approx(0.f));
}

TEST_CASE (" circumferences ", "[circumferences]")
{
  Circle circle_default;
  REQUIRE(circle_default.circumference() == Approx(6.283185f));

  Circle circle{Vec2{-2.f, 1.f}, 4.f, Color{0.f,0.f,1.f}};
  REQUIRE(circle.circumference() == Approx(25.13274f));

  Rect rectangle_default;
  REQUIRE(rectangle_default.circumference() == Approx(4.f));

  Rect rectangle{Vec2{-1.f,2.f}, Vec2{2.f, 4.f}, Color{1.f,0.f,0.f}};
  REQUIRE(rectangle.circumference() == Approx(10.f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
