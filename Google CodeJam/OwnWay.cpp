//cce03
//Problem Statement: https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881da

#include <iostream>
#include <string>
using namespace std;

int matrix[1001][1001];

string path(string s, int N) {
	int i = 0;
	int j = 0;
	string str = "";
	for (int m = 0; m < N; m++) {
		for (int n = 0; n < N; n++) {
			matrix[m][n] = 0;
			if (m == N - 1) {
				matrix[N][n] = 2;
			}
			if (n == N - 1) {
				matrix[m][N] = 2;
			}
		}
	}
	int ii = 0; int jj = 0; matrix[0][0] = 1;
	for (int m = 0; m < s.size(); m++) {
		if (s[m] == 'S') {
			ii++;
		}
		else {
			jj++;
		}
		matrix[ii][jj] = 1;
	}


	bool inside = true;
	while (i != N - 1 || j != N - 1) {
		if (inside) {
			inside = false;
			if (matrix[i + 1][j] == 2 || matrix[i][j+1] == 2) {
				matrix[i][j] = 2;
				char c = str[str.size() - 1];
				str.erase(str.end() - 1);
				if (c == 'S') {
					i--;
				}
				else {
					j--;
				}
			}
			else {
				if (matrix[i + 1][j] == 1) {
					str = str + "E";
					j++;
				}
				else {
					str = str + "S";
					i++;
				}
			}
		}
		else {
			if (matrix[i + 1][j] == 2) {
				if (matrix[i][j + 1] == 2) {
					matrix[i][j] = 2;
					char c = str[str.size() - 1];
					str.erase(str.end() - 1);
					if (c == 'S') {
						i--;
					}
					else {
						j--;
					}
				}
				else {
					str = str + "E";
					j++;
				}
			}
			else {
				if (matrix[i][j + 1] == 2) {
					str = str + "S";
					i++;
				}
				else {
					char c = str[str.size() - 1];
					if (c == 'S') {
						str = str + "E";
						j++;
					}
					else {
						str = str + "S";
						i++;
					}


				}


			}


			if (matrix[i][j] == 1) {
				inside = true;
			}
		}


	}
	return str;
}


int main() {
	
	int N; cin >> N;
	int counter = 1;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		string s; cin >> s;

		cout << "Case #" << counter << ": " << path(s, n) << endl;
		
		counter++;
	}

}


