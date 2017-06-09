#include "Charizard.h"



Charizard::Charizard(std::string name) :Charizard(name)
{
	_pokeName = "Charizard";
	_health = 78;
	_specialAttack= 109;
}


Charizard::~Charizard()
{
}

std::string Charizard::AttackDmg()
{
	std::string output = "Lets out a huge fire breath in all directions!";
	return output;
}
