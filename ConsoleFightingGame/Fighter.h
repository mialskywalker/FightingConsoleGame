#ifndef __FIGHTER__
#define __FIGHTER__

#include <iostream>

using namespace std;

class Fighter {
	string name;
	int health;
	int attackPower;
	bool reduced = false;

public:
	Fighter(string name, int health, int attackPower);
	~Fighter();
	Fighter(const Fighter&) = delete;
	Fighter& operator=(const Fighter&) = delete;
	Fighter(Fighter&&) = default;
	Fighter& operator=(Fighter&&) = default;

	// functions

	// getters
	const string& getName() const;
	int getHealth() const;
	int getAttackPower() const;

	
	// methods
	int attack(Fighter* enemy);

	void defend();

	void heal();

	bool isAlive() const;

	void takeDamage(int damage);

	int getDamage();
};

#endif