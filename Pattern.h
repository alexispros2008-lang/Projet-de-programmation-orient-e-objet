#pragma once
#include <vector>
#include "Snowball.h"
#include "Spawner.h"
class Pattern
{
	private:
		std::vector <Snowball> _pattern;
		float _patternLifeTime;

		std::vector <Spawner> _spawners;
	public:
		Pattern();

		void createPattern(int actualDifficulty);
		void resetPattern();
		void readPaternFile(std::string paternFileName);

		void deleteOneSnowball(int snowballVectorPlace);

		std::string randomPatternFile(int actualDifficulty);

		inline std::vector <Snowball>& getPattern() { return _pattern; }
		inline std::vector <Spawner>& getSpawners() { return _spawners; }
		float getPatternLifeTime() const { return _patternLifeTime; }

		void patternMovement(int numberOfTheActualBullet);
};

