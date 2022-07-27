#pragma once
#ifndef BULLET_H
#define BULLET_H

#include <iostream>
//using namespace std;
#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>


class Bullet
{
private:

	sf::Sprite shape;
	

	sf::Vector2f direction;
	float movementSpeed;

public:
	Bullet();
	Bullet(sf::Texture* texture,float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);
	virtual ~Bullet();

	//Acces to the game position /Accesor
	const sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget* target);
};

#endif // !BULLET_H