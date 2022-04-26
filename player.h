#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

class Player {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Player() {
		texture.loadFromFile(
			IMAGES_FOLDER + 
			PLAYER_IMAGES_FOLDER + 
			PLAYER_IMAGE_FILENAME);
		sprite.setTexture(texture);
	}
	void update() {

	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
};