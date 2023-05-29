#include<bits/stdc++.h>
using namespace std;
int n,m,visited[54][54],ret,max1;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
char a[54][54];

void bfs(int y, int x){
	memset(visited,0,sizeof(visited));
	visited[y][x]=1;
	queue<pair<int,int>> q;
	q.push({y,x});
	while(q.size()){
		tie(y,x)= q.front();q.pop();
		for(int i = 0 ; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i]; 
			if(ny<0||nx<0||ny>=n||nx>=m) continue;
			if(visited[ny][nx])continue;
			if(a[ny][nx]=='W')continue;
			visited[ny][nx] = visited[y][x]+1;
			q.push({ny,nx});
			max1 = max(visited[ny][nx],max1);
		}
	}
	return;
}
main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i = 0; i<n; i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='L')bfs(i,j);
		}
	}
	cout<<max1 -1 <<"\n";
	return 0;
}
