#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

class Player {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f acc = sf::Vector2f(0.f, 0.f);
	sf::Vector2f speed = sf::Vector2f(0.f, 0.f);
	sf::Vector2f pos = sf::Vector2f(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT - 250.f);
public:
	Player() {
		texture.loadFromFile(
			IMAGES_FOLDER + 
			PLAYER_IMAGES_FOLDER + 
			PLAYER_IMAGE_FILENAME);
		sprite.setTexture(texture);
	}
	void update() {
		acc = sf::Vector2f(0.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			acc = sf::Vector2f(-PLAYER_ACC_X, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			acc = sf::Vector2f(PLAYER_ACC_X, 0.f);
		}
		acc.x += speed.x * FRICTION;
		speed += acc;
		pos += speed + sf::Vector2f(0.5f * acc.x, 0.5f * acc.y);
		if (pos.x > WINDOW_WIDTH) {
			pos.x = 0;
		}
		if (pos.x < 0) {
			pos.x = WINDOW_WIDTH;
		}

		sprite.setPosition(pos);

	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
};