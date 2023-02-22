#include<iostream>
using namespace std;
int MonsterGen();
void Biome();
char BTYPE = 'M';
int SpawnmodifierC = 0;
int SpawnmodifierS = 0;
int life = 100;
// monster list
int main() {
	int life = 100;
	Biome();
	
	if (BTYPE == 'S') {
		SpawnmodifierC = 0;
		SpawnmodifierS = 30;
		cout << "SWAMP" << endl;
	}
	else if (BTYPE == 'C'){
		SpawnmodifierC = 30;
		SpawnmodifierS = 0;
		cout << "CAVE" << endl;
	}
	else{
		cout << "no biome" << endl;
	}
	string input; //does nothing, just used to pause loop
	while (life >= 0) { //gameloop
		life -= MonsterGen();
		cout << "You currently have " << life << " hp left." << endl;
		cout << "press any key for next turn." << endl;
		cin >> input;
	}
	cout << "You Died. Game Over." << endl;
}
void Biome() {
	int num2 = rand() % 100; // 0 - 99
	if (num2 < 9) {
		BTYPE = 'C';
		//Cave with zombies and spiders
		cout << "CAVE" << endl;
	}
	else if (num2 < 99) {
		BTYPE = 'S';
		// swamp with skeletons and witches
		cout << "SWAMP" << endl;
	}
	else {
		cout << "no biome" << endl;
	}
}
// function definition
int MonsterGen() {
	cout << BTYPE << endl;
	int num = rand() % 100; // 0 - 99
	if (num < 30 + SpawnmodifierC) {
		cout << "A zombie appears!" << endl;
		return 10; //represents the damage

	}
	// skeleton has spawn chance of 20 (spawnchance - spawnchance of previous monster)
	else if (num < 55 + SpawnmodifierS) {
		cout << "a skeleton attacks!" << endl;
		return 15;
	}
	else if (num < 75 + SpawnmodifierC) {
		cout << "A spider jumps at you!" << endl;
		return 5;
	}
	else if (num < 80 + SpawnmodifierS) {
		cout << "a witch readies its potions" << endl;
		return 25;
	}
	else {
		cout << "No enemies appear. You bandage your wounds" << endl;
		life += 20;
		return 0;
	}

}