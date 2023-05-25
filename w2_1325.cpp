#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,mx,visited[10004];
vector<int> adj[10004];


int dfs(int here){
	int ret =1;
	visited[here] = 1;
	for(int there : adj[here]){
		if(visited[there]==1)continue;
		ret+=dfs(there); 
	}
	return ret;
}

main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	int con[n];
	for(int i=0;i<m;i++){
		cin>>a>>b;
		adj[b].push_back(a);
	}
	for(int i =1; i<=n;i++){
		memset(visited,0,sizeof(visited));
		con[i]=dfs(i);
		mx = max(con[i],mx);
	}
		
	for(int i=1;i<=n;i++){
		if(con[i]==mx){
			cout<<i<<" ";	
		}
	}
	return 0;
}
