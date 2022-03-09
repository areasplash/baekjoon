#include <iostream>
using namespace std;

const int len_fibonacci = 42;
unsigned int fibonacci[len_fibonacci] = { 0, 1, };

int main() {
	for (int i = 2; i < len_fibonacci; i++) fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];

	int num_testcase;
	cin >> num_testcase;
	unsigned int* result_0 = new unsigned int[num_testcase];
	unsigned int* result_1 = new unsigned int[num_testcase];
	
	for (int i = 0; i < num_testcase; i++) {
		int num;
		cin >> num;
		result_0[i] = (num - 1 < 0) ? 1 : fibonacci[num - 1];
		result_1[i] = (num - 0 < 0) ? 1 : fibonacci[num - 0];
	}

	for (int i = 0; i < num_testcase; i++) {
		cout << result_0[i] << ' ' << result_1[i] << endl;
	}

	delete[] result_0;
	delete[] result_1;
	return 0;
}