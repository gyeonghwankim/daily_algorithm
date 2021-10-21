#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> field;
vector<vector<bool>> visited;

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

bool inRange(int& y, int& x) {
	return min(y, x) >= 0 && max(y, x) < n;
}

int getAreaSize(int y, int x) {
	visited[y][x] = true;
	int ret = 1;
	
	for (int i = 0; i < 4; ++i) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (inRange(nextY, nextX) && field[nextY][nextX] == 1 && !visited[nextY][nextX]) {
			ret += getAreaSize(nextY, nextX);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	vector<int> areaSizes;

	cin >> n;
	field.resize(n);
	visited.resize(n);

	for (int y = 0; y < n; ++y) {
		field[y].resize(n);
		visited[y].resize(n);
	}
	
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) 
			cin >> field[y][x];
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (field[i][j] == 1 && !visited[i][j]) {
				int areaSize = getAreaSize(i, j);
				areaSizes.push_back(areaSize);
			}
		}
	}

	sort(areaSizes.begin(), areaSizes.end());

	cout << areaSizes.size() << endl;
	for (int areaSize : areaSizes) cout << areaSize << " ";
}