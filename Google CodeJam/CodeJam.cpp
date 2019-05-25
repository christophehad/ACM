//cce03
//Problem Statement: https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/0000000000088231

#include <iostream>
#include <string>
using namespace std;

string compute(string n) {
	string ret = "";
	for (int i = 0; i < n.size(); i++) {
		if (n[i] == '4') {
			ret = ret + "1";
		}
		else {
			if (!ret.empty()) {
				ret = ret + "0";
			}
		}
	}
	return ret;
}

string compute2(string n) {
	string ret = n;
	for (int i = 0; i < n.size(); i++) {
		if (ret[i] == '4') {
			ret[i] = '3';
		}
	}
	return ret;
}

int main() {
	int N; cin >> N;
	int counter = 1;
	for (int i = 0; i < N; i++) {
		string n; cin >> n;
		string k = compute(n);
		string n2 = compute2(n);
		cout << "Case #" << counter << ": ";
		cout << n2 << " " << k << endl;
		
		counter++;
	}

}


