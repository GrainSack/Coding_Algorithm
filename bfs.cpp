#include<bits/stdc++.h>
using namespace std;
int n,m,visited[104][104],a[104][104],x,y,sy,sx;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	cin>>sy>>sx;
	for(int i=0;i<n;i++){
		for(int j =0; j<m;j++){
			cin>>a[i][j];
		}
	}
	queue<pair<int,int>> q;
	visited[sy][sx]=1;
	q.push({sy,sx});

	while(q.size()){
		tie(y,x) = q.front();q.pop();
		for(int i =0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]) continue;
			if(visited[ny][nx])continue;
			visited[ny][nx] = visited[y][x]+1;
			q.push({ny,nx});
		}
	}
	for(int i=0;i<n;i++){
		for(int j =0; j<m;j++){
			if(j == m){
				cout<<"\n";
			}
			else cout<<visited[i][j]<<" ";
			}
	}	
	return 0;
}
