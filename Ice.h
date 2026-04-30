#pragma once
#include "Bullet.h"
class Ice : public Bullet
{
private:
	sf::CircleShape _iceCircle;
	sf::Rect <float> _iceBounds = _iceCircle.getGlobalBounds();
	float _angle;
	float _rotation; //speed of rotation

public:
	Ice();
	Ice(sf::Vector2 <float> positionBullet, int bulletSpeed, int radius, float angle, float rotation);
	~Ice();

	inline sf::CircleShape getIce() const { return _iceCircle; }
	inline sf::Rect <float> getIceBounds() const { return _iceBounds; }
	inline int getBulletSpeed() const { return _bulletSpeed; }
	inline int getRadius() const { return _iceCircle.getRadius(); }
	inline float getAngle() const { return _angle; }
	inline float getRotation() const { return _rotation; }

	inline void setAngle(float angle) { _angle = angle; }

	void bulletMovement() override;
};

