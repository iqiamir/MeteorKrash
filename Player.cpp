#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 2.5f;

	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;

	this->hpMax = 100;
	this->hp = this->hpMax;

}

void Player::initTexture()
{
	//Load a texture from file
	if (!this->pTexture.loadFromFile("Textures/spacecraft1.png"))
	{
		std::cout << "ERROR :: PLAYER :: INNITTEXTURE :: Could not load texture file." << std::endl;
	}
}

void Player::initSprite()
{
	//set sprite position
	this->pSprite.setPosition(357.f, 450.f);

	//set texture to sprite
	this->pSprite.setTexture(this->pTexture);

	//Resize sprite
	this->pSprite.scale(0.18f, 0.22f);
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

//Create bullet sprite at the player
const sf::Vector2f& Player::getPos() const
{
	return this->pSprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->pSprite.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->pSprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->pSprite.setPosition(x, y);
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

void Player::move(const float dirX, const float dirY)
{
	this->pSprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}

	return false;
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.5f;
}

//Functions
void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->pSprite);
}
