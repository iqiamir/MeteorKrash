#include "Enemy.h"
void Enemy::initVariables()
{
	this->pointCount = rand() % 8 + 3; // min 3, max 10
	this->type = 0;
	this->speed = static_cast<float>(this->pointCount / 2);
	this->hpMax = static_cast<int>(this->pointCount);
	this->hp = this->hpMax;
	this->damage = this->pointCount;
	this->points = this->pointCount;

}

void Enemy::initShape()
{
	//randomize enemy shape
	this->shape.setRadius(this->pointCount * 5);
	//randomize enemy hp
	this->shape.setPointCount(this->pointCount);
	//randomize enemy color
	this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
}

Enemy::Enemy(float pos_x, float pos_y)
{
	//this->initSprite();
	this->initVariables();
	this->initShape();

	this->shape.setPosition(pos_x, pos_y);
	//this->eSprite.setPosition(pos_x, pos_y);	
}

Enemy::~Enemy()
{

}

const sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();
	//return this->eSprite.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}


//Functions
void Enemy::update()
{
	//Enemy move to the bottom
	this->shape.move(0.f, this->speed);
	//this->eSprite.move(0.f, this->speed);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	//target->draw(this->eSprite);
}