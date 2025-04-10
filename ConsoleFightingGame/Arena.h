#ifndef __ARENA__
#define __ARENA__

#include "Fighter.h"

class Arena {
	Fighter* player;
	Fighter*  enemy;
	bool isRunning = true;


public:
	Arena(Fighter* player,Fighter* enemy);
	~Arena();
	Arena(const Arena&) = delete;
	Arena& operator=(const Arena&) = delete;
	Arena(Arena&&) = default;
	Arena& operator=(Arena&&) = default;

	void startBattle();

	void playerTurn();

	void enemyTurn();

	bool checkWinCondition();
};


#endif
