#include<bits/stdc++.h>
using namespace std;

const int v = 10;
int cnt[v];
vector<int> adj[v];

void go(int idx){
	cout<<idx<<'\n';
	cnt[idx] = 1;
	for(int there : adj[idx]){
		if(cnt[there]) continue;
		go(there);
	}
}

int main(){
	adj[1].push_back(2);
	adj[2].push_back(1);
	adj[1].push_back(3);
	adj[3].push_back(1);
	adj[3].push_back(4);
	adj[4].push_back(3);
	
	for(int i=0;i< v ;i++){
		if(adj[i].size()&&cnt[i]==0) go(i);
		
	}
}
