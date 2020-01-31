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

ll floyd[N][N]; // this 2D array holds the distance between any two pairs in the graph.... 
int to[N][N]; //holds the next of any node to know the path if wanted...

void init() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			floyd[i][j] = (i == j ? 0 : inf);
			to[i][j] = j;
		}
	}
}

void warshal(int n) {

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				if (floyd[i][j] > floyd[i][k] + floyd[k][j]) {
					floyd[i][j] = floyd[i][k] + floyd[k][j];
					to[i][j] = to[i][k];
				}
			}
}

// printing path...
void print_path(int u , int v) {
	printf("%d ", u);
	if (u == v) {
		return;
	}
	print_path(to[u][v], v);
}
//sample....
int main() {
	
	int n,m,u,v; cin >> n >> m >> u >> v;
	init(); //initialize;
	for (int i = 0; i < m; ++i) {
		int u,v; ll w; cin >> u >> v >> w;
		floyd[u][v] = w;
	}

	warshal(n);
	print_path(u,v);
}
