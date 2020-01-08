#include <bits/stdc++.h>
using namespace std;
#define sz(s) int((s).size())
const int N = (int) 2e5+1;

int lps[N]; //this array to store the length of longest proper suffix which is also a proper prefix for string.....
string p , t; // p is the pattern you wish to find in string t....
vector<int> pos; // this vector to store the positions where the pattern is matched (start position)...

// "Build Longest proper suffix which is also a prefix" array.......
void Build_LPS(){

	int j = -1;
	lps[0] = -1;
	for(int i = 1 ; i< sz(p) ; ++i){
		while(j > -1 && p[j+1] != p[i])
			j = lps[j];
		if(p[j+1] == p[i]) ++j;
		lps[i] = j;
	}
}

// return true if matched and push all positions matched in the pos vector....
bool Match(){

	int i = 0;
	int j = -1;
	while(i < sz(t)){
		if(t[i] == p[j+1]) ++i , ++j;
		else{
			if(j != -1) j = lps[j];
			else ++i;
		}
		if(j == sz(p)-1) j = lps[j],pos .push_back(i-sz(p));
	}

	return sz(pos) > 0;
}


//a sample how to use it....
int main()
{
	cin>>p>>t;
	Build_LPS(); // first Build lps array...
	if(Match()){ // macth....
		puts("YES");
		for(auto x : pos) printf("%d " , x); //printing all positions matched....
	}
	else puts("NO");

}

