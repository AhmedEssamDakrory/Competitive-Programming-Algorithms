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

ll arr[N];
ll ST[N][int(log2(N)+1)]; //sparse table...
int n; //size of array..

// complexity O(nlogn)*complexity(function)....
void buildSparse(){
	for(int i = 0; i < n; ++i) ST[i][0] = arr[i];
	for(int j = 1 ; (1<<j) <= n ; ++j){
		for(int i = 0; i < n; ++i)
			// here is your function.....
			ST[i][j] = min(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
	}
}

//complexity O(1)....
ll query(int i, int j){
	int k = log2(j-i+1);
	//here is your function
	return min(ST[i][k], ST[j-(1<<k)+1][k]);
}

//sample
int main(){
	cin>>n;
	for(int i = 0 ; i < n ; ++i) cin>>arr[i];
	buildSparse();
	int q; //number of queries..
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<query(l,r)<<endl;
	}
}
