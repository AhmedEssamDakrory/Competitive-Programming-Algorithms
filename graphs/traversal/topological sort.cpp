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
stack<int> st; // this stack holds the nodes in the toplogical oreder..
//topological sort...
void top_sort(int u) {
	vis[u] = true;
	for (auto v : gr[u]) {
		if (!vis[v]) top_sort(v);
	}
	st.push(u);
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

	top_sort(1);
	while (!st.empty()) {
		printf("%d ", st.top());
		st.pop();
	}

	
}
