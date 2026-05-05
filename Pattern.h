#pragma once
#include <vector>
#include "Snowball.h"
#include "Spawner.h"
class Pattern
{
	private:
		std::vector <Snowball> _pattern;
		float _patternLifeTime;

	public:
		Pattern();

		void createPattern();
		void resetPattern();
		void readPaternFile(std::string paternFileName);

		void deleteOneSnowball(int snowballVectorPlace);

		std::string randomPatternFile();

		std::vector <Snowball>& getPattern();
		float getPatternLifeTime() const { return _patternLifeTime; }

		void patternMovement(int numberOfTheActualBullet);
};

