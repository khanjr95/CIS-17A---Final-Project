#include "Pikachu.h"



Pikachu::Pikachu(std::string name) : Pokemon(name)
{
	_pokeName = "Pikachu";
	_health = 35;
	_baseAttack = 55;
}


Pikachu::~Pikachu()
{
}

std::string Pikachu::AttackDmg()
{
	std::string output = "Strikes down oppenent with Thunder.";
	return output;
}