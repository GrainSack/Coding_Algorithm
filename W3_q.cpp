#include<bits/stdc++.h>
using namespace std;
int m,n,t,visited[8][8],cnt;
char a[8][8];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

bool check(int y, int x){
	if(y==0&&x==n-1){
		return true;
	}
	return false;
}

void go(int y, int x, int level,int t){
	if(level>t)return;
	if(check(y,x) && level ==t){
		cnt++;
		return;
	}	
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny<0||nx<0||ny>=m||nx>=n||visited[ny][nx]||a[ny][nx] =='T')continue;
		visited[ny][nx]=1;
		go(ny, nx , level + 1, t);
		visited[ny][nx]=0;
	}
	return;
}


main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>m>>n>>t;
	for(int i=0; i<m;i++){
		for(int j=0; j <n;j++){
			cin>>a[i][j];
		}
	}
	visited[m-1][0] = 1;
	go(m-1,0,1,t);
	
	cout<<cnt<<'\n';
	return 0;
}
