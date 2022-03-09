#include <iostream>
using namespace std;

bool in_planet(int x, int y, int planet_x, int planet_y, int planet_r) {
	int distance = (planet_x - x) * (planet_x - x) + (planet_y - y) * (planet_y - y);
	return (distance < planet_r * planet_r);
}

int main() {
	int num_testcase;
	cin >> num_testcase;
	int* result = new int[num_testcase];

	for (int i = 0; i < num_testcase; i++) {
		result[i] = 0;
		
		int pos_home_x, pos_home_y;
		int pos_goal_x, pos_goal_y;
		cin >> pos_home_x >> pos_home_y >> pos_goal_x >> pos_goal_y;

		int num_planet;
		cin >> num_planet;

		for (int j = 0; j < num_planet; j++) {
			int pos_planet_x, pos_planet_y, pos_planet_r;
			cin >> pos_planet_x >> pos_planet_y >> pos_planet_r;

			bool is_home_in_the_planet = in_planet(pos_home_x, pos_home_y,
				pos_planet_x, pos_planet_y, pos_planet_r);
			bool is_goal_in_the_planet = in_planet(pos_goal_x, pos_goal_y,
				pos_planet_x, pos_planet_y, pos_planet_r);
			if (is_home_in_the_planet && !is_goal_in_the_planet) result[i] += 1;
			if (!is_home_in_the_planet && is_goal_in_the_planet) result[i] += 1;
		}
	}

	for (int i = 0; i < num_testcase; i++) {
		cout << result[i] << endl;
	}

	delete[] result;
	return 0;
}