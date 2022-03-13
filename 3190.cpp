#include <iostream>
using namespace std;

struct rule {
	int time;
	int direction;
};

struct player {
	int length;
	int *x;
	int *y;
	int direction;
	int playtime;
};

int num_block;
int** block;
int num_rule;
rule* rules;

int result;
player snake;



int main() {
	cin >> num_block;
	num_block += 2;
	block = new int* [num_block];
	for (int x = 0; x < num_block; x++) block[x] = new int[num_block];
	for (int x = 1; x < num_block - 1; x++) for (int y = 1; y < num_block - 1; y++) block[x][y] = 0;
	for (int i = 0; i < num_block; i++) block[i][num_block - 1] = 1, block[num_block - 1][i] = 1,
										block[i][0] = 1, block[0][i] = 1;
	int num_apple, apple_x, apple_y;
	cin >> num_apple;
	for (int i = 0; i < num_apple; i++) cin >> apple_x >> apple_y, block[apple_x][apple_y] = 3;

	cin >> num_rule;
	rules = new rule [num_rule];
	snake.direction = 3;
	for (int i = 0; i < num_rule; i++) {
		char dummy;
		cin >> rules[i].time >> dummy;
		switch (snake.direction) {
		case 1: rules[i].direction = (dummy == 'L') ? 3 : 4; break;
		case 2: rules[i].direction = (dummy == 'L') ? 4 : 3; break;
		case 3: rules[i].direction = (dummy == 'L') ? 2 : 1; break;
		case 4: rules[i].direction = (dummy == 'L') ? 1 : 2; break;
		}
		snake.direction = rules[i].direction;
	}

	result = 0;

	snake.length = 1;
	snake.x = new int[snake.length];
	snake.y = new int[snake.length];
	snake.x[0] = 1;
	snake.y[0] = 1;
	snake.direction = 3;
	snake.playtime = 0;
	block[snake.x[0]][snake.y[0]] = 2;

	while (!result) {
		snake.playtime++;

		int* x = new int[snake.length + 1];
		int* y = new int[snake.length + 1];
		for (int i = 0; i < snake.length; i++) x[i + 1] = snake.x[i], y[i + 1] = snake.y[i];

		switch (snake.direction) {
		case 1: x[0] = snake.x[0] + 1, y[0] = snake.y[0]; break;
		case 2: x[0] = snake.x[0] - 1, y[0] = snake.y[0]; break;
		case 3: x[0] = snake.x[0], y[0] = snake.y[0] + 1; break;
		case 4: x[0] = snake.x[0], y[0] = snake.y[0] - 1; break;
		}

		switch (block[x[0]][y[0]]) {
		case 0:
			block[x[0]][y[0]] = 2;
			block[snake.x[snake.length - 1]][snake.y[snake.length - 1]] = 0;
			for (int i = 0; i < snake.length; i++) snake.x[i] = x[i], snake.y[i] = y[i];
			break;
		case 1:
			result = snake.playtime;
			break;
		case 2:
			result = snake.playtime;
			break;
		case 3:
			block[x[0]][y[0]] = 2;
			delete[] snake.x;
			delete[] snake.y;
			snake.length++;
			snake.x = new int[snake.length];
			snake.y = new int[snake.length];
			for (int i = 0; i < snake.length; i++) snake.x[i] = x[i], snake.y[i] = y[i];
			break;
		}
		
		for (int i = 0; i < num_rule; i++) if (snake.playtime == rules[i].time) snake.direction = rules[i].direction;
		delete[] x;
		delete[] y;

		//for (int x = 0; x < num_block; x++) for (int y = 0; y < num_block; y++)
		//	(y == num_block - 1) ? cout << block[x][y] << endl : cout << block[x][y] << ' ';
		//cout << endl;
	}

	cout << result << endl;

	for (int x = 0; x < num_block; x++) delete[] block[x];
	delete[] block;
	delete[] rules;
	delete[] snake.x;
	delete[] snake.y;
	return 0;
}

/*
block 0 : Air
block 1 : Block
block 2 : Snake
block 3 : Apple

direction 1 : x + : Down
direction 2 : x - : Up
direction 3 : y + : Right
direction 4 : y - : Left
*/