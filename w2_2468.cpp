#include<bits/stdc++.h>
using namespace std;

int n,x,y,a[104][104];
bool visited[104][104];

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

void dfs(int y, int x, int t){
	visited[y][x] =1;
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x +dx[i];
		if(ny<0||nx<0||ny>=n||nx>=n||a[ny][nx]<=t) continue;
		if(visited[ny][nx]) continue;
		dfs(ny,nx,t);	
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	int ret = 1;
	for(int i =0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int t=1;t<101;t++){
		int cnt =0;
		fill(&visited[0][0],&visited[0][0] + 104*104,0);
		for(int i =0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i][j]>t&&visited[i][j]==0){
					dfs(i,j,t);cnt++;
				}
			}
		}
		ret = max(cnt,ret);
	}
	cout<<ret<<"\n";
	return 0;
}
	

