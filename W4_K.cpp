#include<bits/stdc++.h>
using namespace std;
int t,n,m,a,b,cnt,visited[1004];
vector<int> adj[1004];

void dfs(int here){
	visited[here]=1;
	for(int there : adj[here]){
		if(!visited[there])dfs(there);
	}
return;	
}


main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	scanf("%d\n",&t);
	while(t--){
		for(int i=0;i< 1004; i++)adj[i].clear();
		fill(visited, visited + 1004, 0);
		cnt =0;
		scanf("%d %d", &n, &m);
		for(int i=0;i<m;i++){
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(int i =1; i<=n;i++){
			if(!visited[i]){
				dfs(i);
				cnt++;
			}
		}
		if(m==n-1 && cnt==1){
			printf("tree\n");
		}
		else{
			printf("graph\n");
		}
	}
}
