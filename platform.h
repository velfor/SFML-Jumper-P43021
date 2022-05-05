#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

class Platform {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f pos;
	float width;
	float height;
public:
	Platform(float x, float y, float width, float height) {
		texture.loadFromFile(
			IMAGES_FOLDER +
			PLATFORM_IMAGES_FOLDER +
			PLATFORM_IMAGE_FILENAME);
		sprite.setTexture(texture);
		sf::FloatRect g_bounds = sprite.getGlobalBounds();
		sprite.setScale(width/g_bounds.width, height/g_bounds.height);
		sprite.setPosition(x, y);
	}
	void update() {}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
};