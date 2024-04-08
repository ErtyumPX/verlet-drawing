#include "simulation.hpp"

void render_circles(sf::RenderWindow &window, vector<Circle> &circles, Master master) {
  for (size_t i = 0; i < circles.size(); i++) {
    sf::CircleShape shape(circles[i].r);
    int x = circles[i].x - circles[i].r;
    int y = circles[i].y - circles[i].r;
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);
    window.draw(shape);
    // write the index of the circle in the middle
    // render_text(window, to_string(i), circles[i].x, circles[i].y, 10, sf::Color::Black);
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
