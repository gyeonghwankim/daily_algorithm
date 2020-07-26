#include <iostream>
#define endl '\n'

using namespace std;

int n;

int powerOfTwo(int n){
	int ret = 1;
	while(n--) ret *= 2;
	return ret;
}

void hanoi(int cnt, int src, int dst, int aux){
	if(cnt == 1){
		cout << src << " " << dst << endl;
		return;
	}
	hanoi(cnt - 1, src, aux, dst);
	cout << src << " " << dst << endl;
	hanoi(cnt - 1, aux, dst, src);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	cout <<  powerOfTwo(n) - 1 << endl;
	hanoi(n, 1, 3, 2);
}