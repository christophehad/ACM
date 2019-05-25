//cce03
//Solution to the Knapsack problem

#include <iostream>
using namespace std;

int DP[1001][1001];

int knapsack(int cap, int * sizes, int * values, int i, int j) {

	if (DP[cap][i] != -1) { return DP[cap][i]; }
	if (cap < sizes[i]) { DP[cap][i] = knapsack(cap, sizes, values, i + 1, j); return DP[cap][i]; }
	if (i > j) { DP[cap][i] = 0; return 0; }
	if (i == j) { DP[cap][i] = values[i]; return values[i]; }

	int m1 = knapsack(cap, sizes, values, i + 1, j);
	int m2 = values[i] + knapsack(cap - sizes[i], sizes, values, i + 1, j);
	int max = (m1 > m2) ? m1 : m2;
	
	DP[cap][i] = max;
	return max;
}

int rknapsack(int cap, int * sizes, int * values, int i, int j) {
	for (int k = 0; k < 1001; k++) {
		for (int l = 0; l < 1001; l++) {
			DP[k][l] = -1;
		}
	}
	return knapsack(cap, sizes, values, i, j);
}

int main() {
	int cap, n;
	cin >> cap >> n;
	int * sizes = new int[n];
	int * val = new int[n];
	for (int i = 0; i < n; i++) {
		int s, v;
		cin >> s >> v;
		sizes[i] = s;
		val[i] = v;
	}
	cout << rknapsack(cap, sizes, val, 0, n - 1);

	return 0;
}