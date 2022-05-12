#include "game.h"

Game::Game() : 
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Jumper")
{
	//в самом низу экрана шириной на весь экран
	Platform* p1 = new Platform(0, WINDOW_HEIGHT - 55.f, 
								WINDOW_WIDTH, 55.f);
	platform_sprites.push_back(p1);
	//выше 1-ой и на 1/2 экрана шириной
	Platform* p2 = new Platform(WINDOW_WIDTH/4, 
		WINDOW_HEIGHT*3/4 , WINDOW_WIDTH/2, 55.f);
	platform_sprites.push_back(p2);
	window.setVerticalSyncEnabled(true);
}
void Game::play() {
	while (window.isOpen()) {
		check_events();
		update();
		check_collisions();
		draw();
	}
}
void Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		// Пользователь нажал на «крестик» и хочет закрыть окно?
		if (event.type == sf::Event::Closed)
			// тогда закрываем его
			window.close();
	}
}
void Game::update() {
	player.update();
	for (auto iter = platform_sprites.begin();
		iter != platform_sprites.end(); iter++) {
		(*iter)->update();
	}
}
void Game::draw() {
	window.clear();
	player.draw(window);
	for (auto iter = platform_sprites.begin();
		iter != platform_sprites.end(); iter++) {
		(*iter)->draw(window);
	}
	window.display();
}
void Game::check_collisions() {
	for (auto iter = platform_sprites.begin();
		iter != platform_sprites.end(); iter++) {
		if (player.getHitBox().intersects((*iter)->getHitBox())) {
			if (player.getSpeed().y >= 0) {
				player.setIsJumping(false);
				player.resetSpeed();
				sf::Vector2f platform_pos = (*iter)->getPosition();
				sf::Vector2f player_new_pos =
					sf::Vector2f(player.getPosition().x,
						platform_pos.y - player.getHitBox().height);
				player.setPosition(player_new_pos);
			}
			
		}
	}
}

