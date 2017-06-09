#include "pokemon.h"
using namespace std;

Pokemon::Pokemon(std::string name) : _name(name)
{
	_pokeName = "Unknown";
	_health = 100;
}

Pokemon::Pokemon()
{
}

Pokemon::~Pokemon()
{
}

std::string Pokemon::getPokeName()
{
	return _name;
}

std::string Pokemon::getPokemon()
{
	return _pokeName;
}

std::string Pokemon::listmypoke()
{
	std::string output = "\n";
	for (auto Pokem : _myPoke) {
		output += Pokem ->getPokeName();
		output += " the " + Pokem->getPokemon() + "\n";
	}
	return output;
}

void Pokemon::addPoke(std::shared_ptr<Pokemon> newPoke)
{
	_myPoke.push_back(newPoke);
}

std::shared_ptr<Pokemon> Pokemon::findPokemon(std::string name)
{
	for (auto Pokem : _myPoke)
	{
		if (Pokem->getPokeName() == name) {
			return Pokem;
		}
	}
	return nullptr;
}

std::string Pokemon::displayStats(std::shared_ptr<Pokemon> currentPoke)
{
	std::string output;
	int Health = 0;
	int specialAttack = 0;
	int baseAttack = 0;
	int specialDef = 0;

	if (currentPoke->_pokeName == "Unknown")
	{
		Health = 100, specialAttack = 0, baseAttack = 0, specialDef = 0;
	}
	else if (currentPoke->_pokeName == "Pikachu")
	{
		Health = 35, specialAttack = 0, baseAttack = 55, specialDef = 0;
	}
	else if (currentPoke->_pokeName == "Medicham")
	{
		Health = 60, specialAttack = 0, baseAttack = 60, specialDef = 75;
	}
	else if (currentPoke->_pokeName == "Charizard")
	{
		Health = 78, specialAttack = 109, baseAttack = 0, specialDef = 0;
	}

	output += currentPoke->_name + "'s Health: " + to_string(Health) + "\n";
	output += currentPoke->_name + "'s Special Attack: " + to_string(specialAttack) + "\n";
	output += currentPoke->_name + "'s Base Attack: " + to_string(baseAttack) + "\n";
	output += currentPoke->_name + "'s Special Defense: " + to_string(specialDef) + "\n";
	

	return output;
}

int Pokemon::PokeInvNum(std::string pokeName)
{
	int pokeNum = 0;
	for (auto Pokem : _myPoke)
	{
		if (Pokem->_pokeName == pokeName)
		{
			pokeNum += 1;
		}
		int pokeCount = Pokem->PokeInvNum(pokeName);
		pokeNum += pokeCount;
	}
	return pokeNum;
}

std::string Pokemon::AttackDmg()
{
	string output = "Attacks with Mind Attacks.";
	return output;
}
