//cce03
//Problem Statement: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=1394

#include <iostream>
#include <string>
using namespace std;

int DP[1001][1001];
int choice[1001][1001];


int makepalind(string &str, int i, int j) {
	if (DP[i][j] != -1) { return DP[i][j]; }
	if (i > j) { DP[i][j] = 0; return 0; }
	if (i == j) { choice[i][j] = 3; DP[i][j] = 0; return 0; }

	if (str[i] == str[j]) {
		DP[i][j] = makepalind(str, i + 1, j - 1);
		choice[i][j] = 0;
		return DP[i][j];
	}

	int a = 1 + makepalind(str, i + 1, j);	// to make a palindrome, we either add the char at i to the right of string, or vice versa (char at j to the start of string)
	int b = 1 + makepalind(str, i, j - 1);
	
	if (a < b) {
		DP[i][j] = a;
		choice[i][j] = 1;
		return a;
	}
	else {
		DP[i][j] = b;
		choice[i][j] = 2;
		return b;
	}
}

int palindrome(string &str) {
	for (int i = 0; i < str.size() + 1; i++) {
		for (int j = 0; j < str.size() + 1; j++) {
			DP[i][j] = -1;
			choice[i][j] = -1;
		}
	}
	return makepalind(str, 0, str.size() - 1);
}

void printpal(string &str) {
	string left, right = "";
	int i = 0; int j = str.size() - 1;
	while (choice[i][j] != -1) {
		switch (choice[i][j])
		{
		case 0: left = left + str[i]; right = str[i] + right; i++; j--; break;
		case 1: left = left + str[i]; right = str[i] + right; i++; break;
		case 2: left = left + str[j]; right = str[j] + right; j--; break;
		case 3: left = left + str[i]; choice[i][j] = -1; break;
		default:
			break;
		}
	}
	cout << left + right;
}

int main() {
	while (true) {
		string str;
		cin >> str;
		if (cin.fail()) { break; }
		cout << palindrome(str) << " "; printpal(str); cout << endl;
	}
	return 0;
}