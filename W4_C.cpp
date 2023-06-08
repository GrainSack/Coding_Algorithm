#include<bits/stdc++.h>
using namespace std;
int n,v[14],comp[14],a[14],m,temp;
vector<int> adj[14];
const int INF = 987654321;
int ret = INF;

pair<int,int> dfs(int here, int value){
	v[here] =1;
	pair<int,int> ret = {1, a[here]};
	for(int there : adj[here]){
		if(comp[there]!=value) continue;
		if(v[there])continue;
		pair<int,int> _temp = dfs(there, value);
		ret.first += _temp.first;
		ret.second += _temp.second;
	}
	return ret;
} 


main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>> n;
	for(int i = 1; i<=n;i++){
		cin>>a[i];
	}
	for(int i=1; i<=n;i++){
		cin>>m;
		for(int j = 0; j<m;j++){
			cin>>temp;
			adj[i].push_back(temp);
			adj[temp].push_back(i);
		}
	}
	for(int i=1;i<=(1<<n)-1;i++){
		fill(comp,comp+14, 0);
		fill(v, v+14, 0);
		int idx = -1, idx2 = -1;
		for(int j = 0; j < n;j++){
			if(i & (1<<j)){
				comp[j+1]=1; idx = j+1;
			}
			else{
				idx2 = j+1;
			}
		}
		pair<int,int>  comp1 = dfs(idx,1);
		pair<int,int> comp2 = dfs(idx2,0);
		if(comp1.first + comp2.first ==n){
			ret = min(ret,abs(comp1.second - comp2.second));
		}
	}
	cout<<(ret == INF ?-1 : ret)<<'\n';
	//만약 ret == INF 이면 -1 반환 아니먄 ret반환 
	return 0;
}
