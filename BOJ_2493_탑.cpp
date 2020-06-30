#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int n;
vector<int> heightOfTower, indexOfReception;

int getIndex(int value, int curIndex){
	if(curIndex == -1) return -1;
	int nextIndex = indexOfReception[curIndex];
	if(heightOfTower[nextIndex] >= value) return nextIndex;
	return getIndex(value, nextIndex);
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	heightOfTower.resize(n);
	
	cin >> heightOfTower[0];
	int maxVal = heightOfTower[0];
	indexOfReception.push_back(-1);
	
	
	for(int i = 1; i < n; ++i){
		cin >> heightOfTower[i];
		if(heightOfTower[i] < heightOfTower[i-1]) indexOfReception.push_back(i-1);
		else{
			if(heightOfTower[i] > maxVal) indexOfReception.push_back(-1);
			else indexOfReception.push_back(getIndex(heightOfTower[i], i-1));
		}
		maxVal = maxVal < heightOfTower[i] ? heightOfTower[i] : maxVal;
	}
	
	for(int i = 0; i < n; ++i) cout << indexOfReception[i] + 1 << " ";
}
