#pragma once
#include "pokemon.h"

class Charizard : public Pokemon
{
protected:
	int _specialAttack;
public:
	Charizard(std::string name);
	~Charizard();
	std::string AttackDmg();
};
