#include "Pattern.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Snowball.h"
#include "mesConstantes.h"

Pattern::Pattern()
{
	_pattern.clear();
	std::string randomNumberStringVersion = randomPatternFile();
	readPaternFile("pattern/pattern" + randomNumberStringVersion + ".txt");
}

void Pattern::resetPattern()
{
	for (int i = 0; i < _pattern.size(); i++)
	{
		if (_pattern[i].getSnowballCircle().getPosition().x < 0 || _pattern[i].getSnowballCircle().getPosition().x > WINDOW_WIDTH || _pattern[i].getSnowballCircle().getPosition().y < 0 || _pattern[i].getSnowballCircle().getPosition().x > WINDOW_HEIGHT) {
			deleteOneSnowball(i);
		}
	}
	std::string randomNumberStringVersion = randomPatternFile();
	readPaternFile("pattern/pattern" + randomNumberStringVersion + ".txt");
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
	int direction = 0;
	int radius = 0;
	int bulletType = 0;
	Direction tempDirectionPush = NOTHING;

	while (paternFile >> bulletType >> positionBullet.x >> positionBullet.y >> bulletSpeed >> direction >> radius) {
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
		Snowball tempSnowball(positionBullet, bulletSpeed, tempDirectionPush, radius);
		if (bulletType == 0) {
			tempSnowball.setColorWhite();
		}
		else if (bulletType == 1) {
			tempSnowball.setColorBlue();
			
		}
		else if (bulletType == 2) {
			tempSnowball.setColorOrange();
		}
		else if (bulletType == 3) {
			tempSnowball.setColorGreen();
		}
		_pattern.push_back(tempSnowball);
	}
	paternFile.close();
}

void Pattern::deleteOneSnowball(int snowballVectorPlace)
{
	_pattern.erase(_pattern.begin() + snowballVectorPlace);
	if (_pattern.empty()) {
		_pattern.clear();
	}
}

std::string Pattern::randomPatternFile()
{
	int randomNumberIntVersion =  rand() % 15 + 1;
	std::string randomNumberStringVersion = std::to_string(randomNumberIntVersion);
	return randomNumberStringVersion;
}

std::vector<Snowball> Pattern::getPattern()
{
	return _pattern;
}

Snowball Pattern::patternMovement(int numberOfTheActualBullet)
{
	_pattern[numberOfTheActualBullet].bulletMovement();
	return _pattern[numberOfTheActualBullet];
}
