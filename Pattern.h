#pragma once
#include <vector>
#include "Snowball.h"
class Pattern
{
	private:
		std::vector <Snowball> _pattern;
	public:
		Pattern();
		void readPaternFile(std::string paternFileName);
		std::string randomPatternFile();
		std::vector <Snowball> getPattern();
		Snowball patternMovement(int numberOfTheActualBullet);
};

