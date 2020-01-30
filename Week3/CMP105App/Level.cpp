#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	circle.setRadius(20);
	circle.setPosition(100, 100);
	circle.setFillColor(sf::Color::Red);
	circle.setOutlineColor(sf::Color::Green);
	circle.setOutlineThickness(3.f);

	circle2.setRadius(20);
	circle2.setPosition(300, 300);
	circle2.setFillColor(sf::Color::Green);
	circle2.setOutlineColor(sf::Color::Red);
	circle2.setOutlineThickness(3.f);

	circle3.setRadius(20);
	circle3.setPosition(300, 300);
	circle3.setFillColor(sf::Color::Red);
	circle3.setOutlineColor(sf::Color::Yellow);
	circle3.setOutlineThickness(3.f);

	speed = 100.0f;
	speed2 = 500.0f;
	speed3 = 300.0f;

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	//circle1
	circle.move(speed * dt, 0);
	const auto pos = circle.getPosition();
	
	if (pos.x >= 1200) {
	    speed *= -1;
	}

	if (pos.x <= 0) {
		speed *= -1;
	}


	//circle2
	if (input->isKeyDown(sf::Keyboard::Right)) {
		circle2.move(speed2 * dt, 0);
	}

	if (input->isKeyDown(sf::Keyboard::Left)) {
		circle2.move(-speed2 * dt, 0);
	}

	if (input->isKeyDown(sf::Keyboard::Down)) {
		circle2.move(0, speed2 * dt);
	}

	if (input->isKeyDown(sf::Keyboard::Up)) {
		circle2.move(0, -speed2 * dt);
	}

	const auto pos2 = circle2.getPosition();
	if (pos2.x >= 1200) {
		circle2.move(-speed2 * dt, 0);
	}

	if (pos2.x <= 0) {
		circle2.move(speed2 * dt, 0);
	}

	if (pos2.y >= 675) {
		circle2.move(0, -speed2 * dt);
	}

	if (pos2.y <= 0) {
		circle2.move(0, speed2 * dt);
	}

	//circle3
	circle3.move(speed3 * dt, speed3 * dt);

	const auto pos3 = circle3.getPosition();

	if (pos3.x >= 1200) {
		speed3 *= -1;
	}

	if (pos3.x <= 0) {
		circle3.move(speed3 * dt, speed3 * dt);
	}

	if (pos3.y >= 675) {
		circle3.move(-speed3 * dt, -speed3 * dt);
	}

	if (pos3.y <= 0) {
		circle3.move(speed3 * dt, speed3 * dt);
	}

	
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(circle);
	window->draw(circle2);
	window->draw(circle3);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}