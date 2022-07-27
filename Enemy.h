#ifndef ENEMY_H
#define ENEMY_H
#pragma once

#include <SFML/Graphics.hpp>

class Enemy
{
private:
	unsigned pointCount;
	sf::CircleShape shape;
	//sf::Sprite eSprite;
	//sf::Texture eTexture;

	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	//void initTexture();
	//void initSprite();
	void initVariables();
	void initShape();
	//void setEnemyScale(float radius);

public:
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	//Accessors
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;

	//Functions
	void update();
	void render(sf::RenderTarget* target);
};

#endif //!ENEMY_H
