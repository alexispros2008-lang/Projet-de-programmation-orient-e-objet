#pragma once
#include "Bullet.h"
#include "math.h"
#include "mesConstantes.h"

class Ice : public Bullet
{
private:
	sf::Rect <float> _iceBounds = _bulletCircle.getGlobalBounds();
public:
	Ice();
	Ice(sf::CircleShape bulletCircle, int bulletSpeed, int radius, float angle, float rotation, float bulletLifeTime);
	~Ice();

	inline sf::CircleShape getIce() const { return _bulletCircle; }
	inline sf::Rect <float> getIceBounds() const { return _iceBounds; }
	inline int getBulletSpeed() const { return _bulletSpeed; }
	inline int getRadius() const { return _bulletCircle.getRadius(); }
	inline float getAngle() const { return _angle; }
	inline float getRotation() const { return _rotation; }

	inline void setAngle(float angle) { _angle = angle; }
};

