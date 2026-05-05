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

	


	while (!paternFile.eof())
	{
		int bulletType = 0;
	
		paternFile >> bulletType;

		sf::Vector2 <float> position(0, 0);
		int speed = 0;
		float angle = 0.0f;
		float lifeTime = 0.0f;
		int radius = 0;

		if (bulletType <= 3)
		{
			paternFile >> position.x >> position.y >> speed >> angle >> radius >> lifeTime;

			sf::CircleShape tempBullet;
			tempBullet.setPosition({ position.x, position.y });
			Snowball tempSnowball(tempBullet, speed * 2.5, angle, radius, 0);
			_patternLifeTime = lifeTime;

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
		else
		{
			float rotation = 0;

			paternFile >> position.x >> position.y >> angle >> rotation >> speed >> lifeTime;
			Spawner tempSpawner(position, angle, rotation, speed, lifeTime);

			paternFile >> speed >> angle >> radius >> lifeTime;
			sf::CircleShape tempBullet;
			tempBullet.setPosition({ position.x, position.y });
			Snowball tempSnowball(tempBullet, speed * 2.5, angle, radius, 0);

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

			tempSpawner.setTypeBullet(tempSnowball);
			_spawners.push_back(tempSpawner);
		}
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
