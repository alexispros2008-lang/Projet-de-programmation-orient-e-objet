#pragma once
#include <vector>
#include "Snowball.h"
class Pattern
{
	private:
		std::vector <Snowball> _pattern;
	public:
		Pattern();
		~Pattern();
		void readPaternFile(std::string paternFileName);
};

