#pragma once
#include <vector>
#include "Snowball.h"
class Pattern
{
	private:
		std::vector <Snowball> _pattern;
	public:
		Pattern();
		void resetPattern();
		void readPaternFile(std::string paternFileName);
		void deleteOneSnowball(int snowballVectorPlace);
		std::string randomPatternFile();
		std::vector <Snowball> getPattern();
		Snowball patternMovement(int numberOfTheActualBullet);
};

