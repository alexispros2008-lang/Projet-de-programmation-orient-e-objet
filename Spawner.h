#pragma once
#include "SFML/Graphics.hpp"
#include "Ice.h"
class Spawner
{
private:
	sf::RectangleShape _spawner;
	sf::FloatRect _spawnerBounds = _spawner.getGlobalBounds();
	sf::Vector2f _speed;
	float _angle; //angle
	float _rotation; //speed of rotation
	float _shootSpeed;

	Ice _typeIce;
	std::vector <Ice> _iceBullets;
public:
	Spawner();
	Spawner(sf::Vector2f position, float angle, float rotation, float shootSpeed);

	~Spawner();
	inline sf::RectangleShape getSpawner() const { return _spawner; }
	inline std::vector<Ice>& getIceBullets() { return _iceBullets; }

	inline void setTypeIce(Ice typeIce) { _typeIce = typeIce; }
	void setSpawner(sf::Vector2f position, float angle, float rotation, float shootSpeed);

	void move();
	void turn();
	void summonBullet();
};

