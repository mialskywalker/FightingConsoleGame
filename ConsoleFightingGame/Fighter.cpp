#include "Fighter.h"

Fighter::Fighter(string name, int health, int attackPower) :
	name(name),
	health(health),
	attackPower(attackPower) { 
	if (health > 100) {
		this->health = 100;
	}
}

Fighter::~Fighter() {}

// functions

// getters
const string& Fighter::getName() const { return this->name; }
int Fighter::getHealth() const { return this->health; }
int Fighter::getAttackPower() const { return this->attackPower; }


// methods
int Fighter::attack(Fighter* enemy) {
	int damage = getDamage();
	enemy->takeDamage(damage);
	return damage;
}

void Fighter::defend() {
	reduced = true;
}

void Fighter::heal() {
	if (health < 100) {
		int amount = rand() % 50;
		int oldHP = this->health;
		this->health += amount;
		if (health > 100) {
			this->health = 100;
			cout << getName() << " healed for " << 100 - oldHP << "HP" << endl;
		}
		else
			cout << getName() << " healed for " << amount << "HP" << endl;
	}
	

}

int Fighter::getDamage() {
	int damage = rand() % attackPower;
	return damage;
}

bool Fighter::isAlive() const { return getHealth() > 0; }

void Fighter::takeDamage(int damage) {
	if (reduced) {
		damage -= 10;
		if (damage < 0)
			damage = 0;
	}
	this->health = getHealth() - damage;
	reduced = false;
}
