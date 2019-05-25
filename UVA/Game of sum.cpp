//cce03
//Problem Statement: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=1832

#include <iostream>
using namespace std;

int DP[101][101][2];

// first version using bool
//int game(int * a, int i, int j, bool turn) {
//	if (DP[i][j][turn] != -1) { return DP[i][j][turn]; }
//	if (i > j) { DP[i][j][turn] = 0; return 0; }
//
//	int ret = (2*turn-1)*a[i]+game(a,i+1,j,!turn);
//	int sum = a[i];
//	for (int k = i + 1; k <= j; k++) {
//		sum += a[k];
//		int trysum = (2 * turn - 1)*sum + game(a, k + 1, j, !turn);
//		if (turn) {
//			if (trysum > ret) { ret = trysum; }
//		}
//		else {
//			if (trysum < ret) { ret = trysum; }
//		}
//		
//	}
//	sum = 0;
//	for (int k = j; k >= i; k--) {
//		sum += a[k];
//		int trysum = (2 * turn - 1)*sum + game(a, i, k-1, !turn);
//		if (turn) {
//			if (trysum > ret) { ret = trysum; }
//		}
//		else {
//			if (trysum < ret) { ret = trysum; }
//		}
//	}
//	DP[i][j][turn] = ret;
//	return ret;
//}

//second version without using the bool (kept it for a quick edit of the code)
int game(int * a, int i, int j, bool turn) {
	if (DP[i][j][0] != -1) { return DP[i][j][0]; }
	if (i > j) { DP[i][j][0] = 0; return 0; }

	int ret = a[i] - game(a, i + 1, j, 0);
	int sum = a[i];
	for (int k = i + 1; k <= j; k++) {
		sum += a[k];
		int trysum = sum - game(a, k + 1, j, 0);
		if (trysum > ret) { ret = trysum; }
		
	}
	sum = 0;
	for (int k = j; k >= i; k--) {
		sum += a[k];
		int trysum = sum - game(a, i, k - 1, 0);
		if (trysum > ret) { ret = trysum; }
	
	}
	DP[i][j][0] = ret;
	return ret;
}


int gamer(int *a, int N) {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			DP[i][j][0] = -1;
			DP[i][j][1] = -1;
		}
	}
	return game(a, 0, N - 1, 1);
}

int main() {
	int N;
	cin >> N;
	while (N != 0) {
		int *a = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		cout << gamer(a, N) << endl;
		cin >> N;
	}

	return 0;
}