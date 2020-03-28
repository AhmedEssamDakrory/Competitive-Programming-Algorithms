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
const int alpha_size = 255;

struct Node{
	Node* edges[alpha_size];
	int prefix_words_count;
	int end_words_count;
};

class Trie{
	Node* root;
	int nodes_count;
	int distinct_words_count;

	Node* reach(string& s){
			Node* cur = root;
			for(auto c : s){
				if(cur == NULL) return NULL;
				cur = cur->edges[int(c)];
			}
			return cur;
		}

public:
	Trie(){
		root = new Node();
		nodes_count = distinct_words_count = 0;
	}

	void insert(string& s){
		Node* cur = root;
		for(auto c : s){
			cur->prefix_words_count++;
			if(cur->edges[int(c)] == NULL){
				cur->edges[int(c)] = new Node();
				nodes_count++;
			}
			cur = cur->edges[int(c)];
		}
		cur->prefix_words_count++;
		distinct_words_count += (++cur->end_words_count == 1);
	}

	void remove(string& s){
		Node* cur = root;
		for(auto c : s){
			cur->end_words_count--;
			Node* nxt = cur->edges[int(c)];
			if(nxt->prefix_words_count == 1){
				destroy(nxt);
				distinct_words_count--;
				cur->edges[int(c)] = NULL;
				return;
			}
			cur = nxt;
		}
		cur->prefix_words_count--;
		cur->end_words_count--;
	}

	int search(string& s){
		Node* cur = reach(s);
		return ((cur == NULL) ? 0 : cur->end_words_count);
	}

	int prefix_count(string& s){
		Node* cur = reach(s);
		return ((cur == NULL) ? 0 : cur->prefix_words_count);
	}


	void destroy(Node* sub_root){
		if(sub_root == NULL) return;
		for(int i = 0 ; i < alpha_size ; ++i){
			destroy(sub_root->edges[i]);
		}
		nodes_count--;
		delete sub_root;
	}

	void clear(){
		destroy(root);
		root = new Node();
		nodes_count = distinct_words_count = 0;
	}

	~Trie(){
		destroy(root);
	}

};

//sample
int main(){
	Trie t;
	int n; cin>>n;
	for (int i = 0 ; i <n ; ++i){
		string s; cin>>s;
		t.insert(s);
	}
	for(int i = 0 ; i < n ; ++i){
		string s; cin>>s;
		cout<<t.search(s)<<endl;
		cout<<t.prefix_count(s)<<endl;
	}
}
