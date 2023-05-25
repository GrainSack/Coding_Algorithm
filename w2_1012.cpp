#include<bits/stdc++.h>
using namespace std;
int m,n,t,k,y,x,a[54][54];
bool visited[54][54];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void DFS(int y ,int x){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	visited[y][x] = 1;
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny<0||nx<0||ny>=m||nx>=n)continue;
		if(a[ny][nx]==1 && !visited[ny][nx]){
		DFS(ny,nx);
		}
	}
	return;
}
main(){
	cin>>t;
	while(t--){
		int cnt = 0;
		fill(&a[0][0], &a[0][0] +54*54,0);
		fill(&visited[0][0],&visited[0][0] + 54*54,0);
		cin>>m>>n>>k;
		for(int i=0;i<k;i++){
			cin>>y>>x;
			a[y][x] = 1;
		}

		for(int i=0 ; i<m;i++){
			for(int j=0;j<n;j++){
				if(a[i][j]==1 && visited[i][j]==0){
					DFS(i,j);cnt++;
				}
			}
		}
	cout<<cnt<<"\n";
	}
	return 0;
}

