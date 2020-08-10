#include <iostream>
#include <string>
#include <vector>
#define endl '\n'

using namespace std;

int n, sum = 0;
vector<int> trees;

string YES_MSG = "YES", NO_MSG = "NO";

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	trees.resize(n);

	int cntOfOne = 0, cntOfTwo = 0;
	bool flag = false;

	for (int i = 0; i < n; ++i) {
		cin >> trees[i];
		sum += trees[i];
		cntOfTwo += trees[i] / 2;
		cntOfOne += trees[i] % 2;
	}

	if (sum % 3 == 0) {
		int diff = cntOfTwo - cntOfOne;
		if (diff >= 0 && diff % 3 == 0) flag = true;
	}

	string ans = (flag) ? YES_MSG : NO_MSG;
	cout << ans << endl;
}