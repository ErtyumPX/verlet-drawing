#pragma once

#include "circle.hpp"
#include "physics.hpp"
#include "master.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

#define FONT_PATH "assets/fonts/mono_regular.ttf"

void render_circles(sf::RenderWindow &window, vector<Circle> &circles, Master master);

void render_text(sf::RenderWindow &window, string text, int x, int y, int size, sf::Color color);
