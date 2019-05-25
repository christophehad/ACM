//cce03
//Problem Statement: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=944


#include <iostream>
#include <vector>
using namespace std;

int DP[53][53];


int sticks(int* a, int i, int j) {
	if (DP[i][j] != -1) { return DP[i][j]; }
	if (i == j - 1) { DP[i][j] = 0; return 0; }
	int m = 2147483647;	//max int
	for (int k = i + 1; k < j; k++) {
		int b1 = sticks(a, i, k);
		int b2 = sticks(a, k, j);
		int total = b1 + b2 + a[j] - a[i];
		m = (total < m) ? total : m;
	}
	DP[i][j] = m;
	return m;
}

int rsticks(int * a, int i, int j) {
	for (int i = 0; i < 53; i++) {
		for (int j = 0; j < 53; j++) {
				DP[i][j] = -1;
		}
	}
	return sticks(a, i, j);
}

int main() {
	vector <int> v;
	int n;
	cin >> n;
	while (n != 0) {
		int k;
		cin >> k;
		int * a = new int[k + 2];
		a[0] = 0;
		a[k + 1] = n;
		for (int i = 1; i < k+1; i++) {
			int ki;
			cin >> ki;
			a[i] = ki;
		}
		v.push_back(rsticks(a, 0, k + 1));
		cin >> n;
	}
	for (int i = 0; i < v.size(); i++) {
		cout << "The minimum cutting is " << v[i] << "." << endl;

	}
	return 0;
}