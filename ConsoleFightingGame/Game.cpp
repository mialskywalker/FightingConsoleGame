#include "Arena.h"

int main() {
	Fighter player("Player", 100, 50);
	Fighter enemy("Enemy", 100, 10);
	Arena arena(&player, &enemy);

	arena.startBattle();

	return 0;
}