#include <iostream>
#include <vector>
#include <string>
#define endl '\n'

using namespace std;

int testCase, n;
int dx[3] = { -1, 0, 1 };

bool inRange(int& x) {
	return x >= 0 && x < n;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> testCase;

	while (testCase--) {
		string cnt, block;

		cin >> n;
		cin.ignore();

		getline(cin, cnt);
		getline(cin, block);
	
		for (int i = 0; i < n; ++i) {
			vector<int> blockIdx;
			int curMine = 0;

			for (int j = 0; j < 3; ++j) {
				int nextX = i + dx[j];

				if (inRange(nextX)) {
					char curVal = block[nextX];
					if (curVal == '*') curMine += 1;
					else blockIdx.push_back(nextX);
				}
			}

			int diff = cnt[i] - curMine - 48;
			for (int j = 0; j < diff; ++j)
				block[blockIdx[blockIdx.size() - j - 1]] = '*';
		}
		int ans = 0;
		for (int i = 0; i < block.size(); ++i) {
			if (block[i] == '*') ans += 1;
		}
		cout << ans << endl;
	}
}