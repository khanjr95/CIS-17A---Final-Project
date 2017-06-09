#pragma once
#include "Pikachu.h"

class Medicham : public Pikachu
{
protected:
	int _specialDef;
public:
	Medicham(std::string name);
	~Medicham();
	std::string AttackDmg();
};