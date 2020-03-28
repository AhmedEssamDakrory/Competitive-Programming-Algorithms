#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int>ii;
typedef long long ll;
#define sz(s) int((s).size())
#define mkp make_pair
#define debug(x) cout<<(#x)<<": \""<<x<<"\""<<endl;
#define sc(x) scanf("%d", &(x))
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pb push_back
const ll inf = (ll) 1e18;
ll MOD = (ll)  998244353;
const int N = (int) 1e5+1;

/*
 * (P) holds the 2^j th ancestor of node i
 * (dep) holds the distance for each node from the root (default root 1)
 * (n) number of nodes
 * (tr) the adjacency list of the tree
 * (level) holds the level for each node
 * (par) holds the parent of each node (parent of the root is -1)
 */
int par[N], P[N][int(log2(N)+1)], level[N], dep[N], n;
vector<vector<int>> tr;

// O(n)
void dfs(int u = 1, int p = -1, int d = 0){
	par[u] = p;
	dep[u] = d;
	level[u] = d+1;
	for(auto v : tr[u]){
		if(v != p){
			dfs(v, u, d+1);
		}
	}
}

// O(nlog(n)
void preprocess(){
	for(int i = 1 ; i <= n ; ++i)
		for(int j = 0 ; (1<<j) < n ; ++j)
			P[i][j] = -1;
	for(int i = 1 ; i <= n ; ++i)
		P[i][0] = par[i];
	for(int j = 1 ; (j<<1) < n ; ++j){
		for(int i = 1 ; i <= n ; ++i){
			if(P[i][j-1] != -1) P[i][j] = P[P[i][j-1]][j-1];
		}
	}
}

// O(log(n))
int LCA(int u, int v){
	if(level[u] < level[v]) swap(u,v);
	int dist = level[u]-level[v];
	//raising u to the same level of v
	while(dist > 0){
		int raise_by = log2(dist);
		u = P[u][raise_by];
		dist -= (1<<raise_by);
	}
	if(u == v) return u;
	for(int j = log2(n); j >= 0 ; --j){
		if( (P[u][j] != P[v][j]) && P[u][j] != -1 ){
			u = P[u][j];
			v = P[v][j];
		}
	}
	return par[u];
}

// O(nlogn)
void buildLCA(){
	dfs();
	preprocess();
}

//o(logn)
int getDist(int u, int v){
	return dep[u]+dep[v]-2*dep[LCA(u,v)];
}


//sample...
int main(){
	cin>>n;
	tr.resize(n+1);
	for(int i = 0 ; i < n-1 ; ++i){
		int u,v; cin>>u>>v;
		tr[u].pb(v);
		tr[v].pb(u);
	}
	buildLCA();
	int q;
	cin>>q;
	while(q--){
		int u, v; cin>>u>>v;
		cout<<getDist(u,v)<<endl;
	}
}
