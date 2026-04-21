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
		void randomPatternFile();
		sf::CircleShape drawPatern();
		Snowball getAllProjectile();
};

