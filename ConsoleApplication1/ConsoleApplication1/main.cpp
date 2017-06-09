//Wanted to make  a program Pokemon based inventory
//couldnt figure out how to get the specific pokemon to derived into class
//got insperation for another student to use project 3 to make it work.


#include <iostream>
#include <stack>
#include "pokemon.h"
#include "Pikachu.h"
#include "Medicham.h"
#include "Charizard.h"

using namespace std;

void DisplayMenu(shared_ptr<Pokemon> currentpoke, shared_ptr<Pokemon> parent);
void AddPokeMenu(shared_ptr<Pokemon> currentpoke);
shared_ptr<Pokemon> PickPokemon(shared_ptr<Pokemon> currentPoke);
void displayStats(shared_ptr<Pokemon> currentPoke);


int main()
{
	stack <shared_ptr<Pokemon>> parentPokeStack;
	auto currentPoke = make_shared<Pokemon>();
	auto parentPokemon = make_shared<Pokemon>();
	parentPokemon = nullptr;

	int choice = 0;
	while (choice != -1)
	{
		DisplayMenu(currentPoke, parentPokemon);
		cin >> choice;
		switch (choice)
		{
		case 1: system("cls");
		{
			cout << "Pokemon that you have caught" << currentPoke->getPokeName() << currentPoke->listmypoke() << endl;
			system("pause");
			break;
		}
		case 2:
		{
			AddPokeMenu(currentPoke);
			break;
		}
		case 3:
		{
			auto newCurrent = make_shared<Pokemon>();
			newCurrent = nullptr;
			try
			{
				newCurrent = PickPokemon(currentPoke);
				if (newCurrent == nullptr)
				{
					throw "You have not caught that pokemon yet.";
				}
			}
			catch (char* errorMessage)
			{
				system("pause");
				while (newCurrent == nullptr)
				{
					system("cls");
					cout << "Error has occured" << endl;
					cout << errorMessage << endl;
					cout << "Enter a Pokemon that you have caught" << endl;
					system("pause");

					system("cls");
					newCurrent = PickPokemon(currentPoke);
				}
			}

			parentPokeStack.push(currentPoke);
			parentPokemon = currentPoke;
			currentPoke = newCurrent;
			break;
		}
		case 4:
		{
			displayStats(currentPoke);
			break;
		}
		
		case 5:
		{
			cout << currentPoke->getPokeName() << " " << currentPoke->AttackDmg() << endl;
			system("pause");
			break;
		}
		
		case 6:
		{
			if (parentPokemon != nullptr)
			{
				currentPoke = parentPokeStack.top();
				parentPokeStack.pop();

				if (parentPokeStack.empty() == false)
				{
					parentPokemon = parentPokeStack.top();
				}
				else
				{
					parentPokemon = nullptr;
				}
			}
			break;
		}
		default:
		{
			cout << "Invalid choice!";
			break;
		}
		}
	}
	system("pause");
	return 0;
}

void DisplayMenu(shared_ptr<Pokemon> currentPoke, shared_ptr<Pokemon> parent)
{
	system("cls");
	cout << "Your Pokemon Inventory" << endl;
	cout << "Now looking at " << currentPoke->getPokeName() << " the " << currentPoke->getPokemon() << endl;
	cout << "-------------------------------------------" << endl;
	cout << "1) List Current Pokemon" << endl;
	cout << "2) Add Pokemon" << endl;
	cout << "3) Search for a Pokemon" << endl;
	cout << "4) Look for Pokemon by stats" << endl;
	cout << "5) Get Pokemon to Demonstrate Attack" << endl;
	
	if (parent != nullptr) {
		cout << "6) Return to [" << parent->getPokeName() << "]";
	}

}

shared_ptr<Pokemon> PickPokemon(shared_ptr<Pokemon> currentPoke)
{
	cout << "Pokemon Name: ";
	string name;
	cin >> name;
	cin.ignore();

	auto pokem = currentPoke->findPokemon(name);
	return pokem;
}

void AddPokeMenu(shared_ptr<Pokemon> currentpoke)
{
	system("cls");

	cout << "Enter name of pokemon you caught ";
	string name;
	cin >> name;
	cin.ignore();

	system("cls");

	cout << "What type of Pokemon would you like to add?" << endl;
	cout << "1) Unknown" << endl;
	cout << "2) Pikachu" << endl;
	cout << "3) Medicham" << endl;
	cout << "4) Charizard" << endl;

	int choice = -1;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		auto newPoke = make_shared<Pokemon>(name);
		currentpoke->addPoke(newPoke);
		break;
	}
	case 2:
	{
		auto newPoke = make_shared<Pikachu>(name);
		currentpoke->addPoke(newPoke);
		break;
	}
	case 3:
	{
		auto newPoke = make_shared<Medicham>(name);
		currentpoke->addPoke(newPoke);
		break;
	}
	case 4:
	{
		auto newPoke = make_shared<Charizard>(name);
		currentpoke->addPoke(newPoke);
		break;
	}//cant get code to add Charizard Class pokemon
	default:
	{
		cout << "Invalid choice!";
		break;
	}
	}
	system("pause");
}

void displayStats(shared_ptr<Pokemon> currentPoke)
{
	system("cls");
	cout << "These are " << currentPoke->getPokeName() << "'s Stats:" << endl;
	cout << currentPoke->displayStats(currentPoke) << endl;
	system("pause");
}
