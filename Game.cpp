#include "Game.h"
bool window1 = true;
bool window2 = false;

//Private functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Meteor Krash", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Textures/bullet.png");
}


void Game::initGUI()
{
	//Load font
	if (!this->font.loadFromFile("Fonts/PixelLettersFull.ttf"))
		std::cout << "ERROR::GAME::Failed to load font Pixel Letter" << "\n";


	if (!this->textFont.loadFromFile("Fonts/SuperMario.ttf"))
		std::cout << "ERROR::GAME::Failed to load font GROBOLD" << "\n";


	//Innit point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(30);
	this->pointText.setFillColor(sf::Color::White);
	//this->pointText.setPosition(700.f, 25.f);
	this->pointText.setPosition(660.f, 45.f);
	//this->pointText.setString("test");

	//Inti Level 1
	this->level1Text.setFont(this->font);
	this->level1Text.setCharacterSize(40);
	this->level1Text.setFillColor(sf::Color::White);
	this->level1Text.setString("Level 1");
	//this->level1Text.setPosition(660.f, 40.f);
	this->level1Text.setPosition(660.f, 10.f);


	//Init Level 2 
	this->level2Text.setFont(this->font);
	this->level2Text.setCharacterSize(40);
	this->level2Text.setFillColor(sf::Color::White);
	this->level2Text.setString("Level 2");
	//this->level2Text.setPosition(660.f, 40.f);
	this->level2Text.setPosition(660.f, 10.f);
	//this->level2Text.setPosition(this->window->getSize().x / 2.f - this->victoryText.getGlobalBounds().width / 2.f, 0.f);

	//Init victory
	this->victoryText.setFont(this->textFont);
	this->victoryText.setCharacterSize(21);
	this->victoryText.setFillColor(sf::Color::Yellow);
	this->victoryText.setString("Congratulations you've completed the game!! \n\n \t\t   Press esc to exit the game");
	//Victory text middle position
	this->victoryText.setPosition(
		this->window->getSize().x / 2.f - this->victoryText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->victoryText.getGlobalBounds().height / 2.f);

	//Init game over
	this->gameOverText.setFont(this->textFont);
	this->gameOverText.setCharacterSize(30);
	this->gameOverText.setFillColor(sf::Color::White);
	this->gameOverText.setString("\t\tGame Over!! \n\n Press esc to exit the game");
	//Game over text middle position
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f);

	//Initalize player GUI
	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

}

void Game::initSound()
{
	//background sound
	if (!this->music.loadFromFile("Sounds/song.wav"))
	{
		std::cout << "Resource 'bgsound.ogg' is missing!" << std::endl;
	}
	this->sound1.setBuffer(music);
	this->sound1.play();
	this->sound1.setVolume(25.f);

	//shooting sound
	if (!this->shooting.loadFromFile("Sounds/shoot.wav"))
	{
		std::cout << "ERROR::GAME::COULD NOT LOAD SHOOTING SOUND " << "\n";
	}
	this->sound2.setBuffer(shooting);

	//winning sound
	if (!this->win.loadFromFile("Sounds/victory.wav"))
	{
		std::cout << "ERROR::GAME::COULD NOT LOAD WINNING SOUND " << "\n";
	}
	this->sound3.setBuffer(win);
}

void Game::initWorld()
{
	//Background
	if (!this->worldBackgroundTex.loadFromFile("Textures/background4.jpg"))
	{
		std::cout << "ERROR::GAME::COULD NOT LOAD BACKGROUND TEXTURE " << "\n";
	}
	this->worldBackground.setTexture(this->worldBackgroundTex);

	//Winning background
	if (!this->winBackgroundTex.loadFromFile("Textures/gameWin.png"))
	{
		std::cout << "ERROR::GAME::COULD NOT LOAD WIN BACKGROUND TEXTURE " << "\n";
	}
	this->winBackground.setTexture(this->winBackgroundTex);


}

void Game::initSystems()
{
	this->points = 0;
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}

//Con/Des
Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initSound();
	this->initWorld();
	this->initSystems();

	this->initPlayer();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
	delete this->player;

	//Delete textures
	for (auto& i : this->textures)
	{
		delete i.second;
	}

	//Delete Bullets
	for (auto* i : this->bullets)
	{
		delete i;
	}

	//Delete enemies
	for (auto* i : this->enemies)
	{
		delete i;
	}
}

//Functions
void Game::run() //might can be use for second level
{
	while (this->window->isOpen())
	{
		while (this->window->isOpen() && window1 == true)
		{
			this->welcomeTex.loadFromFile("Textures/startMenu.png");
			this->welcome.setTexture(this->welcomeTex);

			//this->updatePollevents();
			//if (this->player->getHp() > 0 && this->points < 300)
				//this->update();

			//this->render();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				window1 = false;
				window2 = true;
			}

			this->window->clear();
			this->window->draw(this->welcome);
			this->window->display();
		}
		

		while (this->window->isOpen() && window2 == true)
		{
			this->updatePollevents();
			if (this->player->getHp() > 0 && this->points < 300)
				this->update();

			this->render();
		}
	}
}

void Game::updatePollevents()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Game::updateInput()
{
	//Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		this->sound2.play();
		this->bullets.push_back(
			new Bullet(
				this->textures["BULLET"],
				this->player->getPos().x + this->player->getBounds().width / 2.f,
				this->player->getPos().y,
				0.f,
				-1.f,
				5.f
			)
		);
	}
}

void Game::updateGUI()
{
	std::stringstream ss;

	ss << "Score: " << this->points;

	this->pointText.setString(ss.str());

	//Update player GUI
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));

}

void Game::updateWorld()
{
	//this->sound1.stop();
	//this->window->clear();
	//this->window->draw(this->gameOverText);
	//this->window->draw(this->pointText);
}

void Game::updateCollision()
{
	//Left world collision
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}

	//Right world collision
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}

	//Top world collision
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.f);
	}

	//Bottom world collision
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
	}
}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();

		//Bullet culling (top of the screen)/ removing bullet when it's not visible
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			//Delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);


			//std::cout << this->bullets.size() << "\n";
		}

		++counter;
	}
}

void Game::updateEnemies()
{
	//Spawning 
	//increase time
	this->spawnTimer += 1.0f;
	//spawntimer reach 50.f, it'll reset to zero
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x - 20.f, -100.f));
		this->spawnTimer = 0.f;
	}

	//Update
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();


		if (enemy->getBounds().top > this->window->getSize().y)
		{
			//Delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);

			//std::cout << this->bullets.size() << "\n";
		}
		//Enemy player collision
		else if (enemy->getBounds().intersects(this->player->getBounds()))
		{
			this->player->loseHp(this->enemies.at(counter)->getDamage()); //player hp loss when collide with enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}

		++counter;
	}

}

void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->points += this->enemies[i]->getPoints();

				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);


				enemy_deleted = true;
			}
		}
	}
}

void Game::level1Progress()
{
	if (points >= 20)
	{
		this->spawnTimer += 1.5f;
	}
	else if (points >= 40)
	{
		this->spawnTimer += 2.0f;
	}
	else if (points >= 60)
	{
		this->spawnTimer += 2.5f;
	}
	else if (points >= 80)
	{
		this->spawnTimer += 3.5f;
	}
}

void Game::update()
{
	this->updateInput();

	this->player->update();

	this->updateCollision();

	this->updateBullets();

	this->updateEnemies();

	this->updateCombat();

	this->level1Progress();

	this->updateGUI();

	this->updateWorld();
}



void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}


void Game::render()
{
	this->window->clear();

	//Draw world background
	this->renderWorld();

	//Draw all the stuffs
	this->window->draw(this->level1Text);
	this->player->render(*this->window);

	for (auto* bullet : this->bullets)
	{
		//render bullet to window
		bullet->render(this->window);
	}

	for (auto* enemy : this->enemies)
	{
		//render enemies to window
		enemy->render(this->window);
	}

	this->renderGUI();

	//Level indicator
	if (points >= 100)
	{
		this->level1Text.setScale(0.f, 0.f);
		this->spawnTimer += 5.0f;
		this->window->draw(this->level2Text);
	}

	//Victory screen
	if (points >= 300)
	{
		this->sound1.setVolume(10.f);
		this->window->clear();

		this->window->draw(this->winBackground);
		this->window->draw(this->victoryText);
		this->window->draw(this->pointText);
	}

	//Game over screen
	if (this->player->getHp() <= 0)
	{
		this->sound1.stop();
		this->window->clear();
		this->window->draw(this->gameOverText);
		this->window->draw(this->pointText);
	}

	this->window->display();
}