#pragma once

struct Master {
  int width, height; // pixels
  float gravity; // pixels per second squared
  int frame_rate; // frames per second
  int iteration_rate; // iterations per second
  int n = 0; // number of circles
  float max_radius;
  float min_radius;
  float max_starting_speed;
  float restitution = 0.9; // 0 to 1 (0 = no bounce, 1 = perfect bounce)
  float friction = 0.8; // 0 to 1 (0 = no friction, 1 = perfect friction)
};
