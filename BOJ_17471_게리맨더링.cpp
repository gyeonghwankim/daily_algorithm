#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#define INF 987654321
#define endl '\n'

using namespace std;

int n, m, dst;
vector<int> population, totalSection;
vector<vector<int> > adjList;


int ans = INF;

int checkTheConnection(vector<int>& sections) {
	vector<bool> checked(n, false);
	queue<int> q;
	int ret = 0;

	for (int i = 0; i < sections.size(); ++i)
		checked[sections[i]] = true;

	q.push(sections[0]);
	checked[sections[0]] = false;

	while (!q.empty()) {
		int qf = q.front(); q.pop();

		for (int i = 0; i < adjList[qf].size(); ++i) {
			int currentSection = adjList[qf][i];
			if (checked[currentSection]) {
				checked[currentSection] = false;
				q.push(currentSection);
			}
		}
	}
	for (int i = 0; i < checked.size(); ++i)
		if (checked[i]) return -1;

	for (int i = 0; i < sections.size(); ++i)
		ret += population[sections[i]];

	return ret;
}

void pick(vector<int>& picked, int toPick) {
	if (toPick == 0) {
		vector<int> notPicked(n);
		auto it = set_difference(totalSection.begin(), totalSection.end(), picked.begin(), picked.end(), notPicked.begin());
		notPicked.erase(it, notPicked.end());

		int pickedPop = checkTheConnection(picked), notPickedPop = checkTheConnection(notPicked);
		if (pickedPop != -1 && notPickedPop != -1)
			ans = min(ans, abs(pickedPop - notPickedPop));
	}

	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(picked, toPick - 1);
		picked.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	population.resize(n); adjList.resize(n);
	for (int i = 0; i < n; ++i) cin >> population[i];
	for (int i = 0; i < n; ++i) {
		totalSection.push_back(i);

		cin >> m;
		for (int j = 0; j < m; ++j) {
			cin >> dst;
			adjList[i].push_back(dst - 1);
		}
	}
	vector<int> v;
	for (int i = 1; i <= n / 2; ++i) {
		pick(v, i);
	}
	ans = (ans == INF) ? -1 : ans;
	cout << ans << endl;
}