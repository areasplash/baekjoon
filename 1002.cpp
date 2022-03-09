#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int num_testcase;
	cin >> num_testcase;
	int* result = new int[num_testcase];

	for (int i = 0; i < num_testcase; i++) {
		int pos_x1, pos_y1, pos_r1;
		int pos_x2, pos_y2, pos_r2;
		cin >> pos_x1 >> pos_y1 >> pos_r1 >> pos_x2 >> pos_y2 >> pos_r2;

		int pos_rmax = (pos_r1 > pos_r2) ? pos_r1 : pos_r2;
		int pos_rmin = (pos_r1 < pos_r2) ? pos_r1 : pos_r2;
		int distance = pow(pos_x2 - pos_x1, 2) + pow(pos_y2 - pos_y1, 2);

		if (distance == 0) {
			if (pos_r1 == pos_r2) {
				if (pos_r1 != 0) result[i] = -1;
				else result[i] = 1;
			}
			else result[i] = 0;
		} else {
			if (distance > pow(pos_rmax + pos_rmin, 2)) result[i] = 0;
			else if (distance == pow(pos_rmax + pos_rmin, 2)) result[i] = 1;
			else if (distance == pow(pos_rmax - pos_rmin, 2)) result[i] = 1;
			else if (distance < pow(pos_rmax - pos_rmin, 2)) result[i] = 0;
			else result[i] = 2;
		}
	}

	for (int i = 0; i < num_testcase; i++) {
		cout << result[i] << endl;
	}

	delete[] result;
	return 0;
}