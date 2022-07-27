#pragma once
#include <map>
#include <string>
#include <sstream>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <assert.h>
#include "SFML/Audio.hpp"

class Game
{
private:
	//Window
	sf::RenderWindow* window;

	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;//Create bunch of bullets


	//GUI
	sf::Font font;
	sf::Font textFont;

	sf::Text pointText;
	sf::Text level1Text;
	sf::Text level2Text;
	sf::Text victoryText;
	sf::Text gameOverText;

	//Sounds
	sf::SoundBuffer music;
	sf::Sound sound1;

	sf::SoundBuffer shooting;
	sf::Sound sound2;

	sf::SoundBuffer win;
	sf::Sound sound3;

	//Menu
	sf::Texture welcomeTex;
	sf::Sprite welcome;

	//World
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;

	sf::Texture winBackgroundTex;
	sf::Sprite winBackground;

	//Systems
	unsigned points;

	//Player
	Player* player;

	//PlayerGUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	//Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies; //Create bunch of enemies


	//private functions
	void initWindow();
	void initTextures();
	void initGUI();
	void initSound();
	void initWorld();
	void initSystems();

	void initPlayer();
	void initEnemies();

public:
	Game();
	virtual ~Game();

	//Functions
	void run();

	void updatePollevents();
	void updateInput();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateBullets();
	void updateEnemies();
	void updateCombat();
	void update();
	void level1Progress();
	void renderGUI();
	void renderWorld();
	void render();
};
