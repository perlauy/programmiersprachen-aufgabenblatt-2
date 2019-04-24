#include "vec2.hpp"

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


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
