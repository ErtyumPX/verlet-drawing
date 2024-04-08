#include "simulation.hpp"
#include "physics.hpp"

#include <iostream>
#include <string>

using namespace std;

#define FONT_PATH "assets/fonts/mono_regular.ttf" 

// Simple arg parser for the image path
string parse_args(int argc, char const *argv[]){
  if (argc < 2) {
    cout << "Usage: " << argv[0] << " <path>" << endl;
    exit(1);
  }
  return argv[1];
}


int main(int argc, char const *argv[]){
  string image_path = parse_args(argc, argv);

  // Simulation Configs
  Master master = Master();
  master.frame_rate = 60;
  master.iteration_rate = 60;
  master.width = 800;
  master.height = 600;
  master.gravity = 300;
  master.min_radius = 20;
  master.max_radius = 21;
  master.max_starting_speed = 300;
  master.friction = 0.9999;
  master.restitution = 0.8;
  
  // Create circles
  vector<Circle> circles;
  instantiate_random_circles(circles, master, 100);

  // Create window
  sf::RenderWindow window(sf::VideoMode(master.width, master.height), "Circle Collision Simulation", sf::Style::Titlebar);

  // Main loop
  double dt;
  double total_time = 0;
  sf::Clock clock;
  while (window.isOpen()) {
    // Time management
    dt = clock.restart().asSeconds();
    total_time += dt;

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // Physics
    handle_collisions(circles, master, dt);
    move_circles(circles, master, dt);


    // Rendering
    window.clear(sf::Color::Black);
    render_circles(window, circles, master);
    window.display();
  }

  return 0;
}
