//بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mkp make_pair
#define sz(s) (int)s.size()
using namespace std;
typedef long long ll;
const ll inf = (ll) 1e18;
const int N = (int) 500;

vector<vector<pair<ll,int>>> gr; // your weighted graph....
ll dis[N]; // the shortest distance to any node from the given source...
int par[N]; // parent of each node to know the path...

void init() {
	for (int i = 0; i < N; ++i) dis[i] = inf , par[i] = i;
}

void dijkstra(int src) {
	init();
	dis[src] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push({ 0 , src });
	while (!pq.empty()) {
		ll w = pq.top().F;
		int u = pq.top().S;
		pq.pop();
		for (auto v : gr[u]) {
			if (dis[v.S] > w+v.F) {
				dis[v.S] = w + v.F;
				par[v.S] = u;
				pq.push({dis[v.S] , v.S});
			}
		}
	}
}

void print_path(int dest) {
	if (par[dest] == dest) return;
	print_path(par[dest]);
	printf("%d ", dest);
}

//sample....
int main() {
	int n, m; cin >> n >> m;
	gr.resize(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v; ll w;
		cin >> u >> v >> w;
		gr[u].pb({ w,v });
	}

	dijkstra(1);
	int dest; cin >> dest;
	print_path(dest);
}
