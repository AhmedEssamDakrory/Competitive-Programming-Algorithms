#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 2;

ll seg[4 * N], lz[4 * N];
int n;

void do_operation(ll val, int id, int l, int r) {
	seg[id] += (r - l)*val; // the sum of segment.
}

void modify_node(ll val, int id, int l, int r) {
	lz[id] += val; // change on the segment.
	do_operation(val, id, l, r);
}

void propagate(int id, int l, int r) {
	int mid = (l + r) / 2;
	modify_node(lz[id], id * 2 + 1, l, mid);
	modify_node(lz[id], id * 2 + 2, mid, r);
	lz[id] = 0;
}

void update(ll val, int s, int e, int id = 0, int l = 0, int r = n) {
	if (s >= r || e <= l) return; // no overlapping
	if (l >= s && r <= e) { // completely overlapped.
		modify_node(val, id, l, r);
		return;
	}
	propagate(id, l, r);
	int mid = (l + r) / 2;
	update(val, s, e, id * 2 + 1, l, mid);
	update(val, s, e, id * 2 + 2, mid, r);
	seg[id] = seg[id * 2 + 1] + seg[id * 2 + 2]; // function
}

ll get_ans(int s, int e, int id = 0, int l = 0, int r = n) {
	if (s >= r || e <= l) return 0; // no overlapping
	if (l >= s && r <= e) { // completely overlapped.
		return seg[id];
	}
	propagate(id, l, r);
	int mid = (l + r) / 2;
	return get_ans(s, e, id * 2 + 1, l, mid) + get_ans(s, e, id * 2 + 2, mid, r);
}

int main()
{
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int t; cin >> t;
		if (t == 1) {
			int l, r; scanf("%d%d", &l, &r);
			int x; scanf("%d", &x);
			update(x, l, r);
		}
		else {
			int l; scanf("%d", &l);
			cout << get_ans(l, l+1) << endl;
		}
	}

}

