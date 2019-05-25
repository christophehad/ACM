//cce03
//Problem Statement: https://codingcompetitions.withgoogle.com/codejam/round/00000000000516b9/0000000000134c90

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> backup;

//need a combination that wins every opponent

bool isStronger(char first, char second) {
	if (first == 'R' && second == 'S') { return true; }
	if (first == 'S' && second == 'P') { return true; }
	if (first == 'P' && second == 'R') { return true; }
	return false;
}

char getStronger(char c) {
	if (c == 'R') { return 'P'; }
	if (c == 'P') { return 'S'; }
	if (c == 'S') { return 'R'; }
	return c;
}

string getFirst(vector <string> & vs) {
	int size = vs.size();
	bool r, p, s;
	r = p = s = false;
	char strongest = vs[0][0];
	for (int i = 0; i < size; i++) {
		if (vs[i][0] == 'R') { r = true; }
		if (vs[i][0] == 'P') { p = true; }
		if (vs[i][0] == 'S') { s = true; }
	}

	int test = r*p*s;
	if (test != 0) { return "IMPOSSIBLE"; }
	bool twoSet = (r + p + s) == 2;
	for (int i = 1; i < size; i++) {
		if (isStronger(vs[i][0], strongest)) { 
			strongest = vs[i][0]; 
		}
	}

	string ret = "";
	if (!twoSet) {
		ret += getStronger(strongest);
		return ret;
	}
	ret += strongest;
	return ret;
}

void update(vector <string> & vs, string updater) {
	for (int i = 0; i < vs.size(); i++) {
		if (!vs[i].empty()) {
			if (isStronger(updater[0], vs[i][0])) {
				vs[i] = "";
			}
			else {
				if (vs[i].size() == 1) {
					vs[i] = backup[i];
				}
				else {
					vs[i].erase(vs[i].begin());
				}
			}
		}
	}
}

bool isEmpty(vector <string> & vs) {
	for (int i = 0; i < vs.size(); i++) {
		if (!vs[i].empty()) { return false; }
	}
	return true;
}

string getUpdate(vector <string> & vs) {
	int size = vs.size();
	bool r, p, s;
	r = p = s = false;

	for (int i = 0; i < size; i++) {
		if (!vs[i].empty()) {
			if (vs[i][0] == 'R') { r = true; }
			if (vs[i][0] == 'P') { p = true; }
			if (vs[i][0] == 'S') { s = true; }
		}
	}
	char strongest = ' ';
	for (int i = 0; i < size; i++) {
		if (!vs[i].empty()) {
			strongest = vs[i][0];
			break;
		}
	}

	int test = r*p*s;
	if (test != 0) { return "I"; }
	bool twoSet = (r + p + s) == 2;
	for (int i = 1; i < size; i++) {
		if (isStronger(vs[i][0], strongest)) {
			strongest = vs[i][0];
		}
	}

	string ret = "";
	if (!twoSet) {
		ret += getStronger(strongest);
		return ret;
	}
	ret += strongest;
	return ret;
}

string toReturn(vector <string> & vs) {
	string first = getFirst(vs);
	string ret = first;
	if (first == "IMPOSSIBLE") { return first; }
	bool good = true;
	update(vs, first);
	bool exit = isEmpty(vs);
	while (!exit) {

		string updater = getUpdate(vs);
		if (updater == "I") {
			exit = true; good = false;
		}
		else {
			update(vs, updater);
			ret += updater;
			exit = isEmpty(vs);
		}
	}
	

	if (good) {
		return ret;
	}
	return "IMPOSSIBLE";
}

int main() {
	int N; cin >> N;
	int counter = 1;
	for (int i = 0; i < N; i++) {
		int opponents;
		cin >> opponents;
		vector <string> vstring;
		for (int j = 0; j < opponents; j++) {
			string get; cin >> get;
			vstring.push_back(get);
		}
		backup.clear(); backup = vstring;
		cout << "Case #" << counter << ": ";
		cout << toReturn(vstring) << endl;

		counter++;
	}

}


