#include "Pattern.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Snowball.h"
#include "mesConstantes.h"

Pattern::Pattern()
{
	_patternLifeTime = 0.0f;
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
		if (_pattern[i].getSnowballCircle().getPosition().x < 0 - _pattern.at(i).getSnowballCircle().getScale().x * 2 - 100
			|| _pattern[i].getSnowballCircle().getPosition().x > WINDOW_WIDTH + _pattern.at(i).getSnowballCircle().getScale().x * 2 + 100
			|| _pattern[i].getSnowballCircle().getPosition().y < 0 - _pattern.at(i).getSnowballCircle().getScale().y * 2 - 100
			|| _pattern[i].getSnowballCircle().getPosition().y > WINDOW_HEIGHT + _pattern.at(i).getSnowballCircle().getScale().y * 2 + 100) 
		{
			deleteOneSnowball(i);
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
	int radius = 0;
	int bulletType = 0;
	float angle = 0.0f;
	float patternLifeTime = 0.0f;

	while (paternFile >> bulletType >> positionBullet.x >> positionBullet.y >> bulletSpeed >> angle >> radius >> patternLifeTime) {

		sf::CircleShape tempBullet;
		tempBullet.setPosition({ positionBullet.x, positionBullet.y });
<<<<<<< Updated upstream
		Snowball tempSnowball(tempBullet, bulletSpeed * 2.5, angle, radius, 0, bulletLifeTime);
=======
		Snowball tempSnowball(tempBullet, 9, angle, radius, 0);
		_patternLifeTime = patternLifeTime;

>>>>>>> Stashed changes
		if (bulletType == 0) 
		{
			tempSnowball.setColorWhite();
		}
		else if (bulletType == 1) 
		{
			tempSnowball.setColorBlue();
		}
		else if (bulletType == 2) 
		{
			tempSnowball.setColorOrange();
		}
		else if (bulletType == 3) 
		{
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
