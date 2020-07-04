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

class disjoint_sets_union {

private:

	vector<int> par, set_sz;
	int sets_cnt;

public:

	disjoint_sets_union(int n) {
		par.resize(n + 1);
		set_sz.resize(n + 1);
		sets_cnt = n;
		for (int i = 1; i <= n; ++i) par[i] = i, set_sz[i] = 1;
	}

	int find(int u) {
		if (par[u] == u) return u;
		return par[u] = find(par[u]);
	}

	bool unin(int u, int v) {
		int p1 = find(u);
		int p2 = find(v);
		if (p1 == p2) return false;
		par[p1] = p2;
		sets_cnt--;
		set_sz[p2] += set_sz[p1];
		return true;
	}

	bool same_set(int u, int v) {
		return find(u) == find(v);
	}

	int set_size(int u) {
		return set_sz[find(u)];
	}

	int sets_count() {
		return sets_cnt;
	}
};

// sample...
int main() {
	
}