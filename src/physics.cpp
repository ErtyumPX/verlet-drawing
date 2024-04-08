#include "physics.hpp"
#include <iostream>
#include <ctime>
#include <random>

void instantiate_circle(vector<Circle> &circles, Master master, float x, float y, float r, float vx, float vy) {
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  cout << "r: " << r << endl;
  cout << "vx: " << vx << endl;
  cout << "vy: " << vy << endl;
  Circle circle = Circle();
  circle.x = x;
  circle.y = y;
  circle.r = r;
  circle.vx = vx;
  circle.vy = vy;
  circles.push_back(circle);
}

void instantiate_random_circles(vector<Circle> &circles, Master master, int count) {
  for (int i = 0; i < count; i++) {
    float x, y, r, vx, vy;
    srand(rand() + time(0));
    x = rand() % master.width;
    y = rand() % master.height;
    r = master.min_radius + rand() % (int)(master.max_radius - master.min_radius);
    if (master.max_starting_speed == 0) {
      vx = 0;
      vy = 0;
    }
    else {
      vx = rand() % (int)(master.max_starting_speed * 2) - master.max_starting_speed;
      vy = rand() % (int)(master.max_starting_speed * 2) - master.max_starting_speed;
    }
    instantiate_circle(circles, master, x, y, r, vx, vy);
  }
}

void move_circles(vector<Circle> &circles, Master master, float dt) {
  cout << "circle vx " << circles[0].vx << endl;
  cout << "circle vy " << circles[0].vy << endl;
  for (Circle &circle : circles) {
    // Gravity
    circle.vy += master.gravity * dt;
    // Movement
    circle.x += circle.vx * dt;
    circle.y += circle.vy * dt;
    handle_wall_collisions(circle, master);
    // Friction
    circle.vx *= master.friction;
    circle.vy *= master.friction;
    
    if (abs(circle.vx) < master.gravity * dt * master.friction) circle.vx = 0;
    if (abs(circle.vy) < master.gravity * dt * master.friction) circle.vy = 0;
  }
}

void handle_wall_collisions(Circle &circle, Master master) {
  if (circle.x - circle.r < 0) {
    circle.x = circle.r;
    circle.vx = -circle.vx;
  }
  if (circle.x + circle.r> master.width) {
    circle.x = master.width - circle.r;
    circle.vx = -circle.vx;
  }
  if (circle.y - circle.r < 0) {
    circle.y = circle.r;
    circle.vy = -circle.vy;
  }
  if (circle.y + circle.r > master.height) {
    circle.y = master.height - circle.r;
    circle.vy = -circle.vy;
  }
}

void handle_collisions(vector<Circle> &circles, Master master, float dt) {
  for (size_t i = 0; i < circles.size(); i++) {
    for (size_t j = i + 1; j < circles.size(); j++) {
      Circle &circle1 = circles[i];
      Circle &circle2 = circles[j];
      float dx = circle2.x - circle1.x;
      float dy = circle2.y - circle1.y;
      float d = sqrt(dx * dx + dy * dy);
      if (d == 0) d = 0.001;
      if (d < circle1.r + circle2.r) {
        float nx = dx / d;
        float ny = dy / d;
        float tx = -ny;
        float ty = nx;
        float dpTan1 = circle1.vx * tx + circle1.vy * ty;
        float dpTan2 = circle2.vx * tx + circle2.vy * ty;
        float dpNorm1 = circle1.vx * nx + circle1.vy * ny;
        float dpNorm2 = circle2.vx * nx + circle2.vy * ny;
        float m1 = (dpNorm1 * (circle1.r - circle2.r) + 2 * circle2.r * dpNorm2) / (circle1.r + circle2.r);
        float m2 = (dpNorm2 * (circle2.r - circle1.r) + 2 * circle1.r * dpNorm1) / (circle1.r + circle2.r);
        circle1.vx = (tx * dpTan1 + nx * m1) * master.restitution;
        circle1.vy = (ty * dpTan1 + ny * m1) * master.restitution;
        circle2.vx = (tx * dpTan2 + nx * m2) * master.restitution;
        circle2.vy = (ty * dpTan2 + ny * m2) * master.restitution;
        float overlap = 0.5 * (circle1.r + circle2.r - d + 1);
        circle1.x -= overlap * nx;
        circle1.y -= overlap * ny;
        circle2.x += overlap * nx;
        circle2.y += overlap * ny;
      }
    }
  }
}
