#include <iostream> 
#include <vector>
#define endl '\n'

typedef long long ll;

using namespace std;

int n, m;
vector<int> cost;

bool decision(ll timeLimit){
	ll count = 0;
	for(ll i = 0; i < cost.size(); ++i){
		count += timeLimit / cost[i];
		if(count >= m) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	cost.resize(n);
	
	for(int i = 0; i < n; ++i) cin >> cost[i];	
		
	ll lo = 0, hi = 1e18 + 1;
	while(lo < hi){
		ll mid = lo + (hi - lo) / 2;
		if(decision(mid)) hi = mid;
		else lo = mid + 1;
	}
	cout << hi << endl;
}
