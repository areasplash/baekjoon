#include <iostream>
using namespace std;

int num_testroom;
int *num_testtaker;

int supervisor_allocation;
int sub_supervisor_allocation;

long long result;

int main() {
	cin >> num_testroom;
	num_testtaker = new int[num_testroom];
	for (int i = 0; i < num_testroom; i++) cin >> num_testtaker[i];
	cin >> supervisor_allocation >> sub_supervisor_allocation;

	result = 0;
	for (int i = 0; i < num_testroom; i++) {
		num_testtaker[i] -= supervisor_allocation;
		int value_division = (num_testtaker[i] > 0) ? num_testtaker[i] / sub_supervisor_allocation : 0;
		int value_rest = num_testtaker[i] % sub_supervisor_allocation;
		result += 1 + value_division + (value_rest > 0);
	}

	cout << result << endl;
	delete[] num_testtaker;
	return 0;
}