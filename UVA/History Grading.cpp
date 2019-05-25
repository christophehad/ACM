//cce03
//Problem Statement: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=47

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int DP[25][25];

int grade(int ref[], int ranks[], int tail, int i, int j) {	//try to find the length of the biggest common subsequence between ref and ranks
	if (DP[tail][i] != -1) { return DP[tail][i]; }
	if (i > j && tail == 24) {
		DP[24][i] = 0;
		return 0;
	}

	if (tail == 24) { 	// tail of 24 means our set is empty
		int a = grade(ref, ranks, i, i + 1, j);
		int b = grade(ref, ranks, 24, i + 1, j);
		DP[tail][i] = (a > b) ? a : b;
		return DP[tail][i];
	}
	
	if (i > j) {
		DP[tail][i] = 1;
		return 1;
	}

	int a = grade(ref, ranks, tail, i + 1, j);
	
	if (ref[ranks[tail]] < ref[ranks[i]]) {		// if ranking of event at tail is less than ranking of event at i, then add event i
		int b = 1 + grade(ref, ranks, i, i + 1, j);
		DP[tail][i] = (a > b) ? a : b;
		return DP[tail][i];
	}
	DP[tail][i] = a;
	return a;
}

int grader(int ref[], int check[], int n) {
	int *ranks = new int[n];
	for (int i = 0; i < n; i++) {
		ranks[check[i]] = i;
	}
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			DP[i][j] = -1;
		}
	}

	return grade(ref,ranks,24,0,n-1);
}

int countspaces(string s) {
	int c = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') { c++; }
	}
	return c;
}

int main() {
	string s;
	getline(cin, s);
	while (!s.empty()) {
		stringstream s1(s);
		int n;
		s1 >> n;
		int * ref = new int[n];
		getline(cin, s);
		stringstream needle(s);
		for (int i = 0; i < n; i++) {
			int c;
			needle >> c;
			ref[i] = c - 1; //for indices to start at 0
		}
		int * test = new int[n];
		getline(cin, s);
		while (countspaces(s) == n - 1) {
			stringstream needle2(s);
			for (int i = 0; i < n; i++) {
				int c;
				needle2 >> c;
				test[i] = c - 1; //for indices to start at 0
			}
			cout << grader(ref, test, n) << endl;
			getline(cin, s);
		}
	
		
	}
	
	

	return 0;
}