//بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
#include<unordered_map>
#define F first
#define S second
#define pb push_back
#define mkp make_pair
#define sz(s) (int)s.size()
using namespace std;
typedef long long ll;
const int inf = (int) 1e9;
const int N = (int) 2e5+2;

ll arr[N], BIT[N];
int n;

// updates index idx with value val in O(logn)....
void update(int idx, ll val) {
	for (idx ; idx <= n; idx += (idx&-idx)) {
		BIT[idx] += val;
	}
}

// get the sum from 1 to idx in O(logn)
ll query(int idx) {
	ll ret = 0;
	for (idx ; idx > 0; idx -= (idx&-idx)) {
		ret += BIT[idx];
	}
	return ret;
}

// sample...
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		update(i, arr[i]);
	}
	cout << query(3) << endl;
	
}