//cce03
//Problem Statement: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=284

#include <iostream>
#include <string>
using namespace std;

int DP[12][12];
int choices[12][12];

int minmulr(int* a, int i, int j) {
	if (DP[i][j] != -1) { return DP[i][j]; }
	if (j == i + 1) { DP[i][j] = 0; choices[i][j] = 0; return 0; }
	if (j== i+2) { DP[i][j] = a[i] * a[i+1] * a[j]; choices[i][j] = 12; return DP[i][j]; }
	int min = 2147483647;
	for (int k = i + 1; k < j; k++) {
		int m = minmulr(a, i, k) + minmulr(a, k, j) + a[i] * a[k] * a[j]; //try to partition our multiplication in any index and get the minimum
		if (m < min) { min = m; choices[i][j] = k; }
	}
	DP[i][j] = min;
	return min;
}

int counter = 1;

int minmul(int *a, int N) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			DP[i][j] = -1;
			choices[i][j] = -1;
		}
	}
	counter = 1;
	return minmulr(a, 0, N - 1);
}


string printstr(int start, int end) {
	if (choices[start][end] == -1) { return ""; }
	if (choices[start][end] == 0) { return "A" + to_string(counter++); }
	if (choices[start][end] == 12) { 
		string A = "A" + to_string(counter++);
		string B = "A" + to_string(counter++);
		return "("+A+" x "+B+")"; 
	}
	string A = printstr(start, choices[start][end]);
	string B = printstr(choices[start][end], end);
	return "(" + A + " x " + B + ")";
}

int main() {
	int N;
	int globalc = 1;
	cin >> N;
	while (N != 0) {
		int * a = new int[N+1];
		int m, n;
		cin >> m >> n;
		a[0] = m;
		a[1] = n;
		for (int i = 2; i < N+1; i++) {
			int m, n;
			cin >> m >> n;
			a[i] = n;
		}
		minmul(a, N+1);
		cout << "Case "<<globalc<< ": " << printstr(0, N)<<endl;
		globalc++;
		cin >> N;
	}


	return 0;
}