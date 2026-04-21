#include "Pattern.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Snowball.h"

Pattern::Pattern()
{
	randomPatternFile();
}

void Pattern::readPaternFile(std::string paternFileName)
{

	std::ifstream paternFile;
	paternFile.open(paternFileName);

	if (!paternFile) {
		exit(1);
	}

	sf::Vector2 <float> positionBullet;
	positionBullet.x = 0;
	positionBullet.y = 0;
	int bulletSpeed = 0;
	int damageAmount = 0;
	int direction = 0;
	int radius = 0;
	int bulletType = 0;
	Direction tempDirectionPush = NOTHING;

	while (paternFile >> bulletType >> positionBullet.x >> positionBullet.y >> bulletSpeed >> damageAmount >> direction >> radius) {
		if (direction == 0) {
			tempDirectionPush = LEFT;
		}
		else if (direction == 1) {
			tempDirectionPush = UP;
		}
		else if (direction == 2) {
			tempDirectionPush = DOWN;
		}
		else if (direction == 3) {
			tempDirectionPush = RIGHT;
		}
		else if (direction == 4) {
			tempDirectionPush = RIGHT_UP;
		}
		else if (direction == 5) {
			tempDirectionPush = RIGHT_DOWN;
		}
		else if (direction == 6) {
			tempDirectionPush = LEFT_UP;
		}
		else if (direction == 7) {
			tempDirectionPush = LEFT_DOWN;
		}
		else {
			tempDirectionPush = NOTHING;
		}
		if (bulletType == 0) {
			Snowball tempSnowball(positionBullet, bulletSpeed, damageAmount, tempDirectionPush, radius);
			_pattern.push_back(tempSnowball);
		}
		else {

		}
	}
	paternFile.close();
}

void Pattern::randomPatternFile()
{
	int number = 1;
	std::string s = std::to_string(number);
	readPaternFile("pattern/pattern" + s + ".txt");
}

sf::CircleShape Pattern::drawPatern()
{
	for (int i = 0; i < _pattern.size(); i++) {
		return _pattern[i].getCircle();
	}
}

Snowball Pattern::getAllProjectile()
{
	for (int i = 0; i < _pattern.size(); i++) {
		return _pattern[i];
	}
}

std::vector<Snowball> Pattern::getPattern()
{
	return _pattern;
}
