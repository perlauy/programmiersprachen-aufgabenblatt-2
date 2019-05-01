#define _USE_MATH_DEFINES

#include "circle.hpp"
#include "rect.hpp"
#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(600,600)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    // Draw base of clock
//    Rect bg{{100.f, 100.f}, {500.f,500.f}, {0.2f,0.6f,0.85f}};
//    bg.draw(win, 400.f);

    Circle base{{300.f, 300.f}, 150.f, {1.f,1.f,1.f}, {0.f,1.f,1.0f}};
    base.draw(win, 36, 290.f, false);
    Circle center{{300.f, 300.f}, 80.f, {1.f,1.f,1.f}, {0.f,1.f,1.0f}};
    center.draw(win, 36, 40.f, false);

    win.draw_line(300.0f, 80.f, 
                  300.0f, 95.f,
                  0.0f,0.3f,0.4f,
                  6.0);
    
    auto t = win.get_time();


    float x1 = 300.f - 200.f * std::sin(std::floor(-t) * M_PI / 30);
    float y1 = 300.f - 200.f * std::cos(std::floor(t) * M_PI / 30);

    float x2 = 300.f - 160.f * std::sin(-t / 60 * M_PI / 30);
    float y2 = 300.f - 160.f * std::cos(t / 60 * M_PI / 30);

    float x3 = 300.f - 120.f * std::sin(-t / 3600 * M_PI / 15);
    float y3 = 300.f - 120.f * std::cos(t / 3600 * M_PI / 15);


    // SECONDS
    win.draw_line(x1, y1,
                  300.0f, 300.0f,
                  0.f, 0.f, 0.f,
                  2.0f);
    // MINUTES
    win.draw_line(x2, y2,
                  300.0f, 300.0f,
                  0.2f, 0.2f, 0.2f,
                  4.0f);
    // HOURS
    win.draw_line(x3, y3,
                  300.0f, 300.0f,
                  0.4f, 0.4f, 0.4f,
                  7.0f);

    win.update();
  }

  return 0;
}
