#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define INF 987654321

using namespace std;

enum color { W = 0, B };

int n, m;
string line;
vector<vector<int> > field;

bool inRange(int y, int x) {
  return y + 7 < n && x + 7 < m;
}

int getCnt(int y, int x) {
  int stdRet = 0, oppRet = 0;
  int posVal = y + x;
  int stdColor = field[y][x];
  int oppColor = 1 - stdColor;
  
  for (int i = y; i < y + 8; ++i) {
    for (int j = x; j < x + 8; ++j) {
      int curColor = field[i][j];
      int temp;
      if ((i + j - posVal) % 2 == 0) temp = (curColor != stdColor) ? 1 : 0;
      else temp = (curColor != oppColor) ? 1 : 0;
      stdRet += temp;
      oppRet += 1 - temp;
    }
  }
  return min(stdRet, oppRet);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;

  field.resize(n);
  int answer = INF;

  for (int i = 0; i < n; ++i) {
    cin >> line;
    for (int idx = 0; idx < m; ++idx) {
      if (line[idx] == 'W') field[i].emplace_back(W);
      else field[i].emplace_back(B);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (inRange(i, j)) answer = min(answer, getCnt(i, j));
    }
  }
  cout << answer << endl;
}