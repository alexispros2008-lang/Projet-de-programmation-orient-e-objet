#include "Pattern.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Snowball.h"
#include "mesConstantes.h"

Pattern::Pattern()
{
}

void Pattern::createPattern()
{
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
		if (_pattern.size() >= 20) {
			_pattern.clear();
		}
	}
}

void Pattern::readPaternFile(std::string paternFileName)
{
	std::ifstream paternFile;
	paternFile.open(paternFileName);

	if (!paternFile) {
		exit(1);
	}

	sf::Vector2 <float> positionBullet(0, 0);
	int bulletSpeed = 0;
	int direction = 0;
	int radius = 0;
	int bulletType = 0;
	float angle = 0.0f;

	while (paternFile >> bulletType >> positionBullet.x >> positionBullet.y >> bulletSpeed >> direction >> radius) {
		if (direction == 0) {
			angle = 180.f;
		}
		else if (direction == 1) {
			angle = 90.f;
		}
		else if (direction == 2) {
			angle = 270.f;
		}
		else if (direction == 3) {
			angle = 0.f;
		}
		else if (direction == 4) {
			angle = 45.f;
		}
		else if (direction == 5) {
			angle = 335.f;
		}
		else if (direction == 6) {
			angle = 180.f;
		}
		else if (direction == 7) {
			angle = 180.f;
		}
		else {
			angle = 0.f;
		}
		sf::CircleShape tempBullet;
		tempBullet.setPosition({ positionBullet.x, positionBullet.y });
		Snowball tempSnowball(tempBullet, bulletSpeed, angle, radius, 0);
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
}

std::string Pattern::randomPatternFile()
{
	int randomNumberIntVersion =  rand() % 16 + 1;
	std::string randomNumberStringVersion = std::to_string(randomNumberIntVersion);
	return randomNumberStringVersion;
}

std::vector<Snowball>& Pattern::getPattern()
{
	return _pattern;
}

void Pattern::patternMovement(int numberOfTheActualBullet)
{
	_pattern[numberOfTheActualBullet].bulletMovement();
}
