#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

typedef struct pos{
	int y, x;
}Pos;

int n;
vector<vector<char> > board;

bool isSafe(Pos a){
	return min(a.y, a.x) >= 0 && max(a.y, a.x) < n;
}

int getMaxRowCount(int column){
	int ret = 1, currentCount = 1;
	char currentCandy = board[column][0];
	for(int i = 1; i < n; ++i){
		if(currentCandy == board[column][i]) currentCount += 1;
		else {
			ret = max(ret, currentCount);
			currentCandy = board[column][i];
			currentCount = 1;
		}
	}
	ret = max(ret, currentCount);
	return ret;
}

int getMaxColumnCount(int row){
	int ret = 1, currentCount = 1;
	char currentCandy = board[0][row];
	for(int i = 1; i < n; ++i){
		if(currentCandy == board[i][row]) currentCount += 1;
		else {
			ret = max(ret, currentCount);
			currentCandy = board[i][row];
			currentCount = 1;
		}
	}
	ret = max(ret, currentCount);
	return ret;
}

int getMaxCount(){
	int ret = 1;
	for(int i = 0; i < n; ++i){
		ret = max({ret, getMaxRowCount(i), getMaxColumnCount(i)});
	}
	return ret;
}

void swapElement(Pos a, Pos b){
	int temp = board[a.y][a.x];
	board[a.y][a.x] = board[b.y][b.x];
	board[b.y][b.x] = temp;

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	board.resize(n);

	int ans = 1;

	for(int i = 0; i < n; ++i){
		board[i].resize(n);
		for(int j = 0; j < n; ++j) cin >> board[i][j];
	}

	for(int i = 0; i < n; ++i){
		Pos cur, next;
		for(int j = 0; j < n; ++j){
			cur = {i, j}, next = {i, j+1};
			if(isSafe(next)){
				swapElement(cur, next);
				ans = max(ans, getMaxCount());
				swapElement(cur, next);
			}
			next = {i+1, j};
			if(isSafe(next)){
				swapElement(cur, next);
				ans = max(ans, getMaxCount());
				swapElement(cur, next);
			}
		}
	}
	cout << ans << endl;
}
