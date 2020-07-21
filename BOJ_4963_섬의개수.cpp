#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

typedef struct pos {
    int y, x;
}Pos;

int w, h;
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool inRange(int _y, int _x) {
    return min(_y, _x) >= 0 && _y < h && _x < w;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> w >> h) {
        if (w == 0 && h == 0) break;

        int cnt = 0;

        vector<vector<int> > field;
        vector<vector<bool> > visited;

        field.resize(h); visited.resize(h);

        for (int i = 0; i < h; ++i) {
            field[i].resize(w);
            visited[i].resize(w, false);
        }

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j)
                cin >> field[i][j];
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!visited[i][j] && field[i][j] == 1) {
                    queue<Pos> q;
                    q.push({ i, j });
                    visited[i][j] = true;
                    while (!q.empty()) {
                        Pos qf = q.front(); q.pop();
                        for (int k = 0; k < 8; ++k) {
                            int nextY = qf.y + dy[k], nextX = qf.x + dx[k];
                            if (inRange(nextY, nextX) && field[nextY][nextX] == 1 && !visited[nextY][nextX]) {
                                q.push({ nextY, nextX });
                                visited[nextY][nextX] = true;
                            }
                        }
                    }
                    cnt += 1;
                }
            }
        }
        cout << cnt << endl;
    }

}