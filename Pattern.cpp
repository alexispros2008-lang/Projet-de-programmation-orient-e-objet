#include "Pattern.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Snowball.h"

Pattern::Pattern()
{
	std::string randomNumberStringVersion = randomPatternFile();
	readPaternFile("pattern/pattern" + randomNumberStringVersion + ".txt");
}

void Pattern::resetPattern()
{
	_pattern.clear();
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
		if (bulletType == 0) {
			Snowball tempSnowball(positionBullet, bulletSpeed, tempDirectionPush, radius);
			_pattern.push_back(tempSnowball);
		}
		else {

		}
	}
	paternFile.close();
}

std::string Pattern::randomPatternFile()
{
	int randomNumberIntVersion = rand() % 5 + 1;
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

