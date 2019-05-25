#include <iostream>
#include <vector>
using namespace std;


void towers(int n, int & i, int k, int from, int mid, int to) {
	if (i > k) {
		return;
	}
	if (n == 1) {
		i++;
		if (i == k) {
			cout << "Move from tower " << from << " to tower " << to << endl;
		}
		return;
	}
	towers(n - 1,i,k, from, to, mid);
	i++;
	if (i == k) {
		cout << "Move from tower " << from << " to tower " << to << endl;
	}
	towers(n - 1,i,k, mid, from, to);
}

int counttowers(int n) {
	if (n == 0) { return 0; }
	if (n == 1) { return 1; }
	int a = 0;
	for (int i = 0; i <= n - 1; i++) {
		a = a + counttowers(i) + counttowers(n - 1 - i);
	}
	return a;
}

int DP[1000][1000];

int count(int n1, int n2) {
	if (DP[n1][n2] != -1) { return DP[n1][n2]; }

	if (n1 == 0 && n2 > 0) { DP[0][n2] = 1; return 1; }

	if (n1 == 0) { DP[0][0] = 0; return 0; }

	if (n2 > 0) { DP[n1][n2] = count(n1 - 1, n2 + 1) + count(n1, n2 - 1); return DP[n1][n2]; }
	
	DP[n1][0] = count(n1 - 1, 1); return DP[n1][0];

}

int countWays(int n) {
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			DP[i][j] = -1;
		}
	}
	return count(n, 0);
}

//Program to Show ith message: get total number of steps, and check if i < n/2 or not...