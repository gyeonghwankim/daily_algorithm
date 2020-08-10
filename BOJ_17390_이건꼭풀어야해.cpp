#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

int n, q;

vector<int> partialSum(const vector<int>& a){
	vector<int> ret(a.size());
	ret[0] = a[0];
	for(int i = 1; i < a.size(); ++i){
		ret[i] = ret[i-1] + a[i];
	}
	return ret;
}

int rangeSum(const vector<int>& pSum, int l, int r){
	if(l == 0) return pSum[r];
	return pSum[r] - pSum[l-1];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;

	vector<int> seq;
	int num, l, r;

	for(int i = 0; i < n; ++i){
		cin >> num;
		seq.push_back(num);
	}

	sort(seq.begin(), seq.end());
	vector<int> pSum = partialSum(seq);

	for(int i = 0; i < q; ++i){
		cin >> l >> r;
		cout << rangeSum(pSum, l-1, r-1) << endl;
	}
}