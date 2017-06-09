#pragma once
#include <string>
#include <memory>
#include <vector>

class Pokemon		
{
private:
	std::string _name;
	std::vector <std::shared_ptr<Pokemon>> _myPoke;

protected:
	int _health;
	std::string _pokeName;

public:
	Pokemon(std::string name);
	Pokemon();
	~Pokemon();

	std::string getPokeName();
	std::string getPokemon();
	std::string listmypoke();
	void addPoke(std::shared_ptr<Pokemon> newPoke);
	std::shared_ptr<Pokemon> findPokemon(std::string name);
	std::string displayStats(std::shared_ptr<Pokemon>currentPoke);
	int PokeInvNum(std::string pokeName);
	virtual std::string AttackDmg();
	

};