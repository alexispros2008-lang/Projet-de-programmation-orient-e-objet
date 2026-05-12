#include "Pattern.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Snowball.h"
#include "mesConstantes.h"
#include <string>

Pattern::Pattern()
{
	_patternLifeTime = 0.0f;
}

void Pattern::createPattern(int actualDifficulty)
{
	std::string randomNumberStringVersion = randomPatternFile(actualDifficulty);
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

	for (int i = 0; i < _spawners.size(); i++)
	{
		for (int j = 0; j < _spawners.at(i).getSnowBullets().size(); j++)
		{
			if (_spawners.at(i).getSnowBullets().at(j).getSnowballCircle().getPosition().x < 0 - _spawners.at(i).getSnowBullets().at(j).getSnowballCircle().getRadius() * 2 - 100
				|| _spawners.at(i).getSnowBullets().at(j).getSnowballCircle().getPosition().x > WINDOW_WIDTH + _spawners.at(i).getSnowBullets().at(j).getSnowballCircle().getRadius() * 2 + 100
				|| _spawners.at(i).getSnowBullets().at(j).getSnowballCircle().getPosition().y < 0 - _spawners.at(i).getSnowBullets().at(j).getSnowballCircle().getRadius() * 2 - 100
				|| _spawners.at(i).getSnowBullets().at(j).getSnowballCircle().getPosition().y > WINDOW_HEIGHT + _spawners.at(i).getSnowBullets().at(j).getSnowballCircle().getRadius() * 2 + 100)
			{
				_spawners.at(i).getSnowBullets().erase(_spawners.at(i).getSnowBullets().begin() + j);
			}
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
		std::string comment;

		std::getline(paternFile, comment); // Chaque fichier a une commentaire au 1er ligne
	
		paternFile >> bulletType;

		sf::Vector2 <float> position(0, 0);
		int speed = 0;
		float angle = 0.0f;
		float lifeTime = 0.0f;
		int radius = 0;
		Snowball tempSnowball;

		if (bulletType <= 3)
		{
			paternFile >> position.x >> position.y >> speed >> angle >> radius >> lifeTime;

			sf::CircleShape tempBullet;
			tempBullet.setPosition({ position.x, position.y });
			tempSnowball.setSnowball(tempBullet, speed * 2.5, radius, angle, 0);
			
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

			_patternLifeTime = lifeTime;
			_pattern.push_back(tempSnowball);
		}
		else
		{
			float rotation = 0;
			sf::Vector2f moveSpeed;

			paternFile >> position.x >> position.y >> moveSpeed.x >> moveSpeed.y >> angle >> rotation >> speed >> lifeTime;
			Spawner tempSpawner(position, moveSpeed, angle, rotation, speed, lifeTime);

			paternFile >> bulletType >> speed >> angle >> rotation >> radius;
			sf::CircleShape tempBullet;

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

			tempBullet.setPosition({ position.x, position.y });
			tempSnowball.setSnowball(tempBullet, speed * 2.5, radius, angle, rotation);

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

std::string Pattern::randomPatternFile(int actualDifficulty)
{
	int randomNumberIntVersion = 0;
	if (actualDifficulty == NORMAL_MODE)
	{
		randomNumberIntVersion = rand() % 14 + 1;
	}
	else if (actualDifficulty == HARD_MODE)
	{
		randomNumberIntVersion = rand() % 27 + 1;
	}
	else if (actualDifficulty == EASY_MODE)
	{
		randomNumberIntVersion = rand() % 10 + 1;
	}
	else if (actualDifficulty == DEBUG_MODE)
	{
		randomNumberIntVersion = 27;
	}
	else if (actualDifficulty == CHAOS_MODE)
	{
		randomNumberIntVersion = rand() % 27 + 1;
	}
	else if (actualDifficulty == SUPER_HARD_MODE)
	{
		randomNumberIntVersion = rand() % 27 + 1;
	}
	std::string randomNumberStringVersion = std::to_string(randomNumberIntVersion);
	return randomNumberStringVersion;
}

void Pattern::patternMovement(int numberOfTheActualBullet)
{
	_pattern[numberOfTheActualBullet].bulletMovement();
}
