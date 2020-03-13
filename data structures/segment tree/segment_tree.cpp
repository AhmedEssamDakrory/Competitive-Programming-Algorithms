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

// safe size of the segment tree is to be four times the size of the array...
ll seg[4 * N], arr[N];
int n; //size of the array....

void update(int pos, ll val, int id = 0, int l = 0, int r = n-1) {
	if (l == r) {
		seg[id] = val;
		return;
	}
	int mid = l + (r - l) / 2;
	if (pos <= mid) update(pos, val, id*2+1, l, mid);
	else update(pos, val, id*2+2, mid+1, r);
	// your equation here....
	seg[id] = seg[id*2+1] + seg[id*2+2];
}

ll query(int s, int e, int id = 0, int l = 0, int r = n-1) {
	
	// no overlapping....
	if (e < l || s > r) {
		return 0;
	}
	// totally overlapping....
	if (s <= l && e >= r) {
		return seg[id];
	}
	// partially overlapping...
	int mid = l + (r - l) / 2;
	// your equation here....
	return query(s, e, id*2+1, l, mid) + query(s, e, id*2+2, mid+1, r);
}

// sample...
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		update(i, arr[i]);
	}

	cout<<query(0, n-1)<<endl;
	update(2, 10);
	cout << query(0, n-1)<<endl;
	cout << query(0, 2);
	
}