#include "Arena.h"

Arena::Arena(Fighter* player, Fighter* enemy) :
	player(player), enemy(enemy) {}

Arena::~Arena() {}

void Arena::startBattle() {

	while (isRunning) {
		playerTurn();
		isRunning = checkWinCondition();
		if (!isRunning)
			break;
		enemyTurn();
		isRunning = checkWinCondition();
	}
}

void Arena::playerTurn() {
	cout << "--------------------------------------" << endl;
	cout << "|Your Health: " << player->getHealth() << " | " << "Enemy Health: " << enemy->getHealth() << "|" << endl;
	cout << "--------------------------------------" << endl;
	cout << "\n\n" << "Choose action:\n" << "1. Attack\n2. Deffend\n3. Heal\n";
	string choice;
	cout << "> ";
	cin >> choice;
	bool isNotValid = true;
	while (isNotValid) {
		if (choice == "1" || choice == "2" || choice == "3") {
			isNotValid = false;
			break;
		}
		else {
			cout << "Invalid input" << endl;
			cout << "> ";
			cin >> choice;
		}
	}

	if (choice == "1") {
		cout << "You hit the enemy for " << player->attack(enemy) << " damage!" << endl;
	}
	else if (choice == "2") {
		player->defend();
		cout << "You take a defensive stance!" << endl;
	}
	else if (choice == "3") {
		player->heal();
	}
	else {
		cout << "Invalid input" << endl;
	}

}

void Arena::enemyTurn() {
	int choice = rand() % 3;

	if (choice == 0) {
		cout << "Enemy hit you for " << enemy->attack(player) << " damage!" << endl;
	}
	else if (choice == 1) {
		enemy->defend();
		cout << "Enemy takes a defensive stance!" << endl;
	}
	else if (choice == 2){
		enemy->heal();
	}
}

bool Arena::checkWinCondition() {
	if (!player->isAlive())
	{
		cout << "Enemy Wins!" << endl;
		return false;
	}
	else if (!enemy->isAlive()) {
		cout << "Congratulations! You Win!" << endl;
		return false;
	}
	return true;
}