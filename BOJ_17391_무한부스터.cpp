#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 987654321

using namespace std;

int n, m;
vector<vector<int> > field, dist;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	field.resize(n); dist.resize(n);
	for (int i = 0; i < n; ++i) {
		field[i].resize(m);
		dist[i].resize(m);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> field[i][j];
			int ret = INF;
			for (int k = 0; k <= i - 1; ++k) {
				if (k + field[k][j] >= i) ret = min(ret, dist[k][j] + 1);
			}

			for (int k = 0; k <= j - 1; ++k) {
				if (k + field[i][k] >= j) ret = min(ret, dist[i][k] + 1);
			}

			if (!(i == 0 && j == 0)) dist[i][j] = ret;
		}		
	}
	cout << dist[n - 1][m - 1] << endl;
}