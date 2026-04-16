#pragma once
#include <vector>
#include "Snowball.h"
class Pattern
{
	private:
		std::vector <Snowball> _pattern;
	public:
		Pattern(std::string paternFileName);
		void readPaternFile(std::string paternFileName);
		sf::CircleShape drawPatern();
		Snowball getAllProjectile();
};

