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
const int N = (int) 2e5 + 10;

bool vis[N]; // array to mark visited nodes
vector<vector<int>> gr; //your graph
vector<int> srcs; // vector holds all sourses you want to start from
//multi source BFS
void bfs() {

	queue<int> q;
	for (auto u : srcs) q.push(u) , vis[u] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : gr[u]) {
			if (!vis[v]) {
				vis[v] = true; // mark as visited once pushed in the queue
				q.push(v);
			}
		}
		printf("%d ", u); // printing nodes in breadth oreder ( put your logic here )
	}
}

//sample....
int main() {
	int n , m; cin >> n >> m;
	gr.resize(n + 1);

	for (int i = 0; i < m; ++i) {
		int u,v;
		cin >> u >> v;
		gr[u].pb(v);
	}

	srcs.pb(1);
	bfs();
}
