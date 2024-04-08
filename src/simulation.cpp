#include "simulation.hpp"

void render_circles(sf::RenderWindow &window, vector<Circle> &circles, Master master) {
  for (Circle &circle : circles) {
    sf::CircleShape shape(circle.r);
    shape.setPosition(circle.x, circle.y);
    shape.setFillColor(sf::Color::White);
    window.draw(shape);
  }
}

void render_text(sf::RenderWindow &window, string text, int x, int y, int size, sf::Color color) {
  sf::Font font;
  font.loadFromFile(FONT_PATH);
  sf::Text sf_text;
  sf_text.setFont(font);
  sf_text.setString(text);
  sf_text.setCharacterSize(size);
  sf_text.setFillColor(color);
  sf_text.setPosition(x, y);
  window.draw(sf_text);
}
