#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
#define endl '\n'

using namespace std;

int n, m;
int diff = INF;
vector<int> cards;

void pick(int n, vector<int>& picked, int toPick) {
	if (toPick == 0) {
		int total = 0;
		for (int n : picked) total += cards[n];
		if (total <= m) diff = min(diff, m - total);
		return;
	}
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	int input;
	for (int i = 0; i < n; ++i) {
		cin >> input;
		cards.push_back(input);
	}
	vector<int> v;
	pick(n, v, 3);
	cout << m - diff << endl;
	return 0;
}