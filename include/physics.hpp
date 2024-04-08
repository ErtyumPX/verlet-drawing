#pragma once

#include "circle.hpp"
#include "master.hpp"
#include <vector>

using namespace std;

void instantiate_circle(vector<Circle> &circles, Master master, float x, float y, float r, float vx, float vy);

void instantiate_random_circles(vector<Circle> &circles, Master master, int count = 1);

void move_circles(vector<Circle> &circles, Master master, float dt);

void handle_wall_collisions(Circle &circle, Master master);

void handle_collisions(vector<Circle> &circles, Master master, float dt);
