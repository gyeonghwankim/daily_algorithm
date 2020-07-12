#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

typedef struct robot {
	robot(int _id, int _y, int _x) : id(_id), y(_y), x(_x) {}
	int id, y, x;
}Robot;

enum direction { E = 0, S, W, N };

char rd, cmd;
int y, x, n, m, ry, rx, rID, cnt;
vector<vector<int> > field; // y,x 위치에 존재하는 Robot의 방향
vector<Robot> Robots; // id 값을 가지는 Robot의 위치

// 동 남 서 북
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

bool inRange(int _y, int _x) {
	return min(_y, _x) >= 0 && _y < y && _x < x;
}

bool isItSafe(int _y, int _x) {
	return field[_y][_x] == -1;
}

void rotate(int _id, int _direction) {
	Robot cur = Robots[_id];
	if (_direction == 'R') field[cur.y][cur.x] = (field[cur.y][cur.x] + 1) % 4;
	if (_direction == 'L') field[cur.y][cur.x] = (field[cur.y][cur.x] + 3) % 4;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> x >> y;
	field.resize(y);
	for (int i = 0; i < y; ++i) field[i].resize(x, -1);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> rx >> ry >> rd;
		Robots.emplace_back(i, ry - 1, rx - 1);

		int nRd;
		if (rd == 'E') nRd = E;
		else if (rd == 'W') nRd = W;
		else if (rd == 'N') nRd = N;
		else if (rd == 'S') nRd = S;

		field[ry - 1][rx - 1] = nRd;
	}

	for (int i = 0; i < m; ++i) {
		cin >> rID >> cmd >> cnt;
		if (cmd != 'F') {
			for (int j = 0; j < cnt % 4; ++j) rotate(rID - 1, cmd);
		}
		else {
			for (int j = 0; j < cnt; ++j) {
				Robot cur = Robots[rID - 1];
				int curDirection = field[cur.y][cur.x];
				int nextY = cur.y + dy[curDirection], nextX = cur.x + dx[curDirection];
				if (inRange(nextY, nextX)) {
					if (isItSafe(nextY, nextX)) {
						field[cur.y][cur.x] = -1;
						Robots[rID - 1].y = nextY, Robots[rID - 1].x = nextX;
						field[nextY][nextX] = curDirection;
					}
					else {
						int opponentID = -1;
						for (int k = 0; k < Robots.size(); ++k) {
							if (Robots[k].y == nextY && Robots[k].x == nextX) {
								opponentID = k + 1;
								break;
							}
						}
						cout << "Robot " << rID << " crashes into robot " << opponentID << endl;
						return 0;
					}
				}
				else {
					cout << "Robot " << rID << " crashes into the wall" << endl;
					return 0;
				}

			}

		}
	}
	cout << "OK" << endl;
}