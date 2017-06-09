#include "Medicham.h"


Medicham::Medicham(std::string name) :Pikachu(name), Pokemon(name)
{
	_pokeName = "Medicham";
	_health = 60;
	_baseAttack = 60;
	_specialDef = 75;
}

Medicham::~Medicham()
{
}

std::string Medicham::AttackDmg()
{
	std::string output = "Ambushes his enemy with strong kicks!";
	return output;
}