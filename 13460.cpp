#include <iostream>
using namespace std;

struct pos {
	int x, y;
	char** n;
};

pos board;
pos pos_rose;
pos pos_blue;
pos pos_exit;
int num_history = 11;

void simulation(pos rose, pos blue, int direction, int history) {
	history++;
	if (history > num_history) return;
	bool rose_movement = false;
	bool blue_movement = false;
	bool rose_pass_exit = false;
	bool blue_pass_exit = false;
	while (true) switch(direction) {
	case 1:
		rose_movement = (board.n[rose.x + 1][rose.y] == '#' || ((!rose_pass_exit && !blue_pass_exit) && rose.x + 1 == blue.x && rose.y == blue.y)) ? false : true;
		blue_movement = (board.n[blue.x + 1][blue.y] == '#' || ((!rose_pass_exit && !blue_pass_exit) && blue.x + 1 == rose.x && blue.y == rose.y)) ? false : true;
		if (rose_movement) rose.x++;
		if (blue_movement) blue.x++;
		if (rose.x == pos_exit.x && rose.y == pos_exit.y) rose_pass_exit = true;
		if (blue.x == pos_exit.x && blue.y == pos_exit.y) blue_pass_exit = true;
		if (!rose_movement && !blue_movement) {
			if (blue_pass_exit) return;
			if (rose_pass_exit) {
				if (history < num_history) num_history = history;
				return;
			}
			else if (rose_pass_exit && blue_pass_exit) return;
			simulation(rose, blue, 2, history);
			simulation(rose, blue, 3, history);
			simulation(rose, blue, 4, history);
			return;
		} break;
	case 2:
		rose_movement = (board.n[rose.x - 1][rose.y] == '#' || ((!rose_pass_exit && !blue_pass_exit) && rose.x - 1 == blue.x && rose.y == blue.y)) ? false : true;
		blue_movement = (board.n[blue.x - 1][blue.y] == '#' || ((!rose_pass_exit && !blue_pass_exit) && blue.x - 1 == rose.x && blue.y == rose.y)) ? false : true;
		if (rose_movement) rose.x--;
		if (blue_movement) blue.x--;
		if (rose.x == pos_exit.x && rose.y == pos_exit.y) rose_pass_exit = true;
		if (blue.x == pos_exit.x && blue.y == pos_exit.y) blue_pass_exit = true;
		if (!rose_movement && !blue_movement) {
			if (blue_pass_exit) return;
			if (rose_pass_exit) {
				if (history < num_history) num_history = history;
			return;
		}
			else if (rose_pass_exit && blue_pass_exit) return;
			simulation(rose, blue, 1, history);
			simulation(rose, blue, 3, history);
			simulation(rose, blue, 4, history);
			return;
		} break;
	case 3:
		rose_movement = (board.n[rose.x][rose.y + 1] == '#' || ((!rose_pass_exit && !blue_pass_exit) && rose.x == blue.x && rose.y + 1 == blue.y)) ? false : true;
		blue_movement = (board.n[blue.x][blue.y + 1] == '#' || ((!rose_pass_exit && !blue_pass_exit) && blue.x == rose.x && blue.y + 1 == rose.y)) ? false : true;
		if (rose_movement) rose.y++;
		if (blue_movement) blue.y++;
		if (rose.x == pos_exit.x && rose.y == pos_exit.y) rose_pass_exit = true;
		if (blue.x == pos_exit.x && blue.y == pos_exit.y) blue_pass_exit = true;
		if (!rose_movement && !blue_movement) {
			if (blue_pass_exit) return;
			if (rose_pass_exit) {
				if (history < num_history) num_history = history;
			return;
		}
			else if (rose_pass_exit && blue_pass_exit) return;
			simulation(rose, blue, 1, history);
			simulation(rose, blue, 2, history);
			simulation(rose, blue, 4, history);
			return;
		} break;
	case 4:
		rose_movement = (board.n[rose.x][rose.y - 1] == '#' || ((!rose_pass_exit && !blue_pass_exit) && rose.x == blue.x && rose.y - 1 == blue.y)) ? false : true;
		blue_movement = (board.n[blue.x][blue.y - 1] == '#' || ((!rose_pass_exit && !blue_pass_exit) && blue.x == rose.x && blue.y - 1 == rose.y)) ? false : true;
		if (rose_movement) rose.y--;
		if (blue_movement) blue.y--;
		if (rose.x == pos_exit.x && rose.y == pos_exit.y) rose_pass_exit = true;
		if (blue.x == pos_exit.x && blue.y == pos_exit.y) blue_pass_exit = true;
		if (!rose_movement && !blue_movement) {
			if (blue_pass_exit) return;
			if (rose_pass_exit) {
				if (history < num_history) num_history = history;
			return;
		}
			else if (rose_pass_exit && blue_pass_exit) return;
			simulation(rose, blue, 1, history);
			simulation(rose, blue, 2, history);
			simulation(rose, blue, 3, history);
			return;
		} break;
	}
}

int main() {
	cin >> board.x >> board.y;
	board.n = new char*[board.x];
	for (int x = 0; x < board.x; x++) board.n[x] = new char[board.y];
	for (int x = 0; x < board.x; x++) for (int y = 0; y < board.y; y++) {
		cin >> board.n[x][y];
		if (board.n[x][y] == 'R') board.n[x][y] = '.', pos_rose.x = x, pos_rose.y = y;
		if (board.n[x][y] == 'B') board.n[x][y] = '.', pos_blue.x = x, pos_blue.y = y;
		if (board.n[x][y] == 'O') board.n[x][y] = '.', pos_exit.x = x, pos_exit.y = y;
	}
	simulation(pos_rose, pos_blue, 1, 0);
	simulation(pos_rose, pos_blue, 2, 0);
	simulation(pos_rose, pos_blue, 3, 0);
	simulation(pos_rose, pos_blue, 4, 0);

	num_history = num_history == 11 ? -1 : num_history;
	cout << num_history << endl;

	for (int x = 0; x < board.x; x++) delete[] board.n[x];
	delete[] board.n;
	return 0;
}