#pragma once
#include "SFML/Graphics.hpp"
#include "Ice.h"
#include "Snowball.h"
class Spawner
{
private:
	sf::RectangleShape _spawner;
	sf::FloatRect _spawnerBounds = _spawner.getGlobalBounds();
	sf::Vector2f _speed;
	float _angle; //angle
	float _rotation; //speed of rotation
	float _shootSpeed;
	float _spawnerLifeTime;
	sf::Clock _shootSpeedClock;

	Snowball _typeSnowball;
	std::vector <Snowball> _snowBullets;
public:
	Spawner();
	Spawner(sf::Vector2f position, float angle, float rotation, float shootSpeed, float spawnerLifeTime);

	~Spawner();
	inline sf::RectangleShape getSpawner() const { return _spawner; }
	inline std::vector<Snowball>& getSnowBullets() { return _snowBullets; }
	inline float getLifeTime() const { return _spawnerLifeTime; }

	inline void setTypeBullet(Snowball bullet) { _typeSnowball = bullet; }
	void setSpawner(sf::Vector2f position, float angle, float rotation, float shootSpeed, float spawnerLifeTime);

	void move();
	void turn();
	void summonBullet();
};

