#include <iostream>
using namespace std;

int num_block;
int** block;
int result = 0;



void simulation(int** pre_block, int direction, int history) {
	int** new_block = new int* [num_block];
	for (int x = 0; x < num_block; x++) new_block[x] = new int[num_block];
	for (int x = 0; x < num_block; x++) for (int y = 0; y < num_block; y++) new_block[x][y] = pre_block[x][y];
	
	int min = 0, max = num_block - 1;
	switch (direction) {
	case 1:
		for (int y = min; y <= max; y++) {
			int x = max;
			int point_overlap = max + 1;
			int point_space = -1;
			while (x >= min) {
				if (new_block[x][y] == 0) {
					if (point_space == -1) point_space = x;
				} else if (new_block[x][y] != 0) {
					if (point_space != -1) {
						new_block[point_space][y] = new_block[x][y], new_block[x][y] = 0;
						x = point_space + 1, point_space = -1;
					} else if (point_overlap > x && x + 1 <= max && new_block[x][y] == new_block[x + 1][y]) {
						new_block[x + 1][y] *= 2, new_block[x][y] = 0;
						x += 1, point_overlap = x - 1;
					}
				} x--;
			}
		} break;
	case 2:
		for (int y = max; y >= min; y--) {
			int x = min;
			int point_overlap = min - 1;
			int point_space = -1;
			while (x <= max) {
				if (new_block[x][y] == 0) {
					if (point_space == -1) point_space = x;
				} else if (new_block[x][y] != 0) {
					if (point_space != -1) {
						new_block[point_space][y] = new_block[x][y], new_block[x][y] = 0;
						x = point_space - 1, point_space = -1;
					} else if (point_overlap < x && x - 1 >= min && new_block[x][y] == new_block[x - 1][y]) {
						new_block[x - 1][y] *= 2, new_block[x][y] = 0;
						x -= 1, point_overlap = x + 1;
					}
				} x++;
			}
		} break;
	case 3:
		for (int x = min; x <= max; x++) {
			int y = max;
			int point_overlap = max + 1;
			int point_space = -1;
			while (y >= min) {
				if (new_block[x][y] == 0) {
					if (point_space == -1) point_space = y;
				} else if (new_block[x][y] != 0) {
					if (point_space != -1) {
						new_block[x][point_space] = new_block[x][y], new_block[x][y] = 0;
						y = point_space + 1, point_space = -1;
					} else if (point_overlap > y && y + 1 <= max && new_block[x][y] == new_block[x][y + 1]) {
						new_block[x][y + 1] *= 2, new_block[x][y] = 0;
						y += 1, point_overlap = y - 1;
					}
				} y--;
			}
		} break;
	case 4:
		for (int x = max; x >= min; x--) {
			int y = min;
			int point_overlap = min - 1;
			int point_space = -1;
			while (y <= max) {
				if (new_block[x][y] == 0) {
					if (point_space == -1) point_space = y;
				} else if (new_block[x][y] != 0) {
					if (point_space != -1) {
						new_block[x][point_space] = new_block[x][y], new_block[x][y] = 0;
						y = point_space - 1, point_space = -1;
					} else if (point_overlap < y && y - 1 >= min && new_block[x][y] == new_block[x][y - 1]) {
						new_block[x][y - 1] *= 2, new_block[x][y] = 0;
						y -= 1, point_overlap = y + 1;
					}
				} y++;
			}
		} break;
	}
	if (history < 5) {
		simulation(new_block, 1, history + 1);
		simulation(new_block, 2, history + 1);
		simulation(new_block, 3, history + 1);
		simulation(new_block, 4, history + 1);
	} else for (int x = 0; x < num_block; x++) for (int y = 0; y < num_block; y++)
		if (new_block[x][y] > result) result = new_block[x][y];

	for (int x = 0; x < num_block; x++) delete[] new_block[x];
	delete[] new_block;
}



int main() {
	cin >> num_block;
	block = new int*[num_block];
	for (int x = 0; x < num_block; x++) block[x] = new int[num_block];
	for (int x = 0; x < num_block; x++)	for (int y = 0; y < num_block; y++) cin >> block[x][y];
	
	simulation(block, 1, 1);
	simulation(block, 2, 1);
	simulation(block, 3, 1);
	simulation(block, 4, 1);
	cout << result << endl;

	for (int x = 0; x < num_block; x++) delete[] block[x];
	delete[] block;
	return 0;
}