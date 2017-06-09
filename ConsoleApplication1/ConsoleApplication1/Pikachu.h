#pragma once
#include "Pokemon.h"

class Pikachu : virtual public Pokemon
{
protected:
	int _baseAttack;
public:
	Pikachu(std::string name);
	~Pikachu();
	std::string AttackDmg();
};
