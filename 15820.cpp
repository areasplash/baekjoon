#include <iostream>
using namespace std;

struct testcases {
	int manyeong;
	int solution;
};

int main() {
	int num_sample_testcase;
	int num_system_testcase;
	int result[2] = { 0, 0 };
	cin >> num_sample_testcase >> num_system_testcase;
	testcases* sample_testcase = new testcases[num_sample_testcase];
	testcases* system_testcase = new testcases[num_system_testcase];
	for (int i = 0; i < num_sample_testcase; i++) {
		cin >> sample_testcase[i].manyeong >> sample_testcase[i].solution;
		result[0] += (sample_testcase[i].manyeong == sample_testcase[i].solution);
	}
	for (int i = 0; i < num_system_testcase; i++) {
		cin >> system_testcase[i].manyeong >> system_testcase[i].solution;
		result[1] += (system_testcase[i].manyeong == system_testcase[i].solution);
	}
	(result[0] == num_sample_testcase) ? (result[1] == num_system_testcase) ?
		cout << "Accepted" << endl : cout << "Why Wrong!!!" << endl : cout << "Wrong Answer" << endl;
	delete[] sample_testcase;
	delete[] system_testcase;
	return 0;
}