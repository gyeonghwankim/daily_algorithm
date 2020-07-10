#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int testCase, m, n;
	cin >> testCase;
	while (testCase--) {
		vector<vector<int> > field;
		int ans = 0;

		cin >> m >> n;
		field.resize(m);

		for (int i = 0; i < m; ++i) {
			field[i].resize(n);
			for (int j = 0; j < n; ++j) cin >> field[i][j];
		}

		for (int j = 0; j < n; ++j) {
			int zeroCnt = 0;
			for (int i = m - 1; i >= 0; --i) {
				if (field[i][j] == 0) zeroCnt += 1;
				else ans += zeroCnt;
			}
		}
		cout << ans << endl;
	}
}