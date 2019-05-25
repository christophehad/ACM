//cce03
//Problem Statement: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=1346

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int DP[1001][1001];
int choices[1001][1001];


// Solving the knapsack problem for practice
//int knapsack(int cap, int * sizes, int * values, int i, int j) {
//
//	if (DP[cap][i] != -1) { return DP[cap][i]; }
//	if (cap < sizes[i]) { DP[cap][i] = knapsack(cap, sizes, values, i + 1, j); return DP[cap][i]; }
//	if (i > j) { DP[cap][i] = 0; return 0; }
//	if (i == j) { DP[cap][i] = values[i]; return values[i]; }
//
//	int m1 = knapsack(cap, sizes, values, i + 1, j);
//	int m2 = values[i] + knapsack(cap - sizes[i], sizes, values, i + 1, j);
//	int max = (m1 > m2) ? m1 : m2;
//
//	DP[cap][i] = max;
//	return max;
//}

//int rknapsack(int cap, int * sizes, int * values, int i, int j) {
//	for (int k = 0; k < 1001; k++) {
//		for (int l = 0; l < 1001; l++) {
//			DP[k][l] = -1;
//		}
//	}
//	return knapsack(cap, sizes, values, i, j);
//}

//string common(string str1,string str2, int i1, int j1, int i2, int j2) {
//	
//	if (DP[i1][i2] != "-1") { return DP[i1][i2]; }
//
//	if (str1[i1] == str2[i2]) {
//		if (i1 == j1 || i2 == j2) {
//			DP[i1][i2] = str1[i1];
//		}
//		else {
//			DP[i1][i2] = string(1, str1[i1]).append(common(str1, str2, i1 + 1, j1, i2 + 1, j2));
//		}
//		return DP[i1][i2];
//	}
//	
//	string c1 = (i1==j1) ? "" : "" + common(str1, str2, i1 + 1, j1, i2, j2);
//	string c2 = (i2==j2) ? "" : "" + common(str1, str2, i1, j1, i2+1, j2);
//
//	DP[i1][i2] = (c1.size() > c2.size()) ? c1 : c2;
//	return DP[i1][i2];
//}

//string rcommon(string str1, string str2, int i1, int j1, int i2, int j2) {
//	for (int i = 0; i < 1001; i++) {
//		for (int j = 0; j < 1001; j++) {
//			DP[i][j] = "-1";
//		}
//	}
//	return common(str1, str2, i1, j1, i2, j2);
//}

int common(string str1, string str2, int i1, int i2) {

	if (DP[i1][i2] != -1) { return DP[i1][i2]; }

	if (i1 == str1.length() || i2 == str2.length()) {
		DP[i1][i2] = 0; return 0;
	}

	if (str1[i1] == str2[i2]) {
		DP[i1][i2] = 1 + common(str1, str2, i1 + 1, i2 + 1);
		choices[i1][i2] = 0;
		return DP[i1][i2];
	}

	int c1 = common(str1, str2, i1 + 1, i2);
	int c2 = common(str1, str2, i1, i2 + 1);

	if (c1 > c2) {
		DP[i1][i2] = c1;
		choices[i1][i2] = 1;
	}
	else {
		DP[i1][i2] = c2;
		choices[i1][i2] = 2;
	}

	return DP[i1][i2];
}

int rcommon(string str1, string str2) {
	for (int i = 0; i < str1.length()+1; i++) {
		for (int j = 0; j < str2.length()+1; j++) {
			DP[i][j] = -1;
		}
	}
	for (int i = 0; i < str1.length() + 1; i++) {
		for (int j = 0; j < str2.length() + 1; j++) {
			choices[i][j] = -1;
		}
	}
	int ret = common(str1, str2, 0, 0);
	string str = "";
	int i = 0;
	int j = 0;
	while ((i < str1.length() + 1) && (j < str2.length() + 1)) {

		switch (choices[i][j])
		{
		default: goto exitloop;
		case -1: goto exitloop;
		case 0: str = str + str1[i]; i++; j++; break;
		case 1: i++; break;
		case 2: j++; break;
		}
	}
exitloop:;
	return ret;
}


int main() {
	string str1 = "a";
	string str2 = "b";
	int arr[500];
	int ar = 0;
	getline(cin, str1);
	while (!str1.empty()) {
		string a;
		getline(cin, a);
		str2 = a;
		if (str2.empty()) { break; }
		arr[ar] = rcommon(str1, str2);
		ar++;
		string b;
		getline(cin, b);
		str1 = b;
	}
	for (int i = 0; i <ar; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}