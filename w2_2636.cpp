#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,cnt2,visited[104][104],a[104][104];

const int dy[]= {-1,0,1,0};
const int dx[] = {0,1,0,-1};
vector<pair<int,int>> v;

void dfs(int y ,int x){
	visited[y][x]=1;
	if(a[y][x]==1){
		v.push_back({y,x});
		return;
	}
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny<0||nx<0||ny>=n||nx>=n||visited[ny][nx]==1)continue;
		dfs(ny,nx);
	}
	return;
}


main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	while(true){
		cnt++;
		fill(&visited[0][0],&visited[0][0]+104*104,0);
		v.clear();
		dfs(0,0);
		cnt2=0;
		for(pair<int,int> b : v){
			cnt2++;
			a[b.first][b.second]=0;
		}
		bool flag= 0;
		for(int i=0; i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]!=0)flag=1;
			}
		}
		if(!flag)break;
	}
	cout<<cnt<<"\n"<<cnt2;
	return 0;
}
