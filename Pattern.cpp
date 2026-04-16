#include "Pattern.h"
#include <iostream>
#include <iomanip>
#include <fstream>

void Pattern::readPaternFile(std::string paternFileName)
{

	std::ifstream paternFile;
	paternFile.open(paternFileName);

	if (!paternFile) {
		exit(1);
	}

	sf::Vector2 <float> positionBullet;
	int bulletSpeed;
	int damageAmount;
	int direction;
	int radius;
	Direction tempDirectionPush;

	/*while (paternFile >> positionBullet.x >> positionBullet.y >> bulletSpeed >> damageAmount >> direction >> radius) {
		if (direction = 4) {

		}
		Snowball tempSnowball(positionBullet, bulletSpeed, damageAmount, direction, radius)
		_pattern.push_back()
	}*/

	//paternFile.close();
}
