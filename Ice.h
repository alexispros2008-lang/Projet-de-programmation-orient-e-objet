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
	inline float getAngle() const { return _angle; }

	inline void setAngle(float angle) { _angle = angle; }

	void bulletMovement() override;
};

