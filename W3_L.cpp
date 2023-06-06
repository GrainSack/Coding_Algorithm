#include<bits/stdc++.h>
using namespace std;

int ret;
int R,S	,visited[24];
char a[24][24];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

void go(int y, int x, int cnt){
	ret = max(ret, cnt);
	for(int i=0; i<4; i++){
		int ny = y +dy[i];
		int nx = x + dx[i];
		if(ny<0||nx<0||ny>=R||nx>=S)continue;
		int next = int(a[ny][nx]-'A');
		
		if(visited[next] ==0){
			visited[next]= 1;
			go(ny,nx,cnt+1);
			visited[next]=0;
		}
	}
	return;
}

main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>R>>S;
	for(int i = 0 ;i<R;i++){
		for(int j =0; j<S;j++){
			cin>>a[i][j];
		}
	}
	visited[int(a[0][0]-'A')] =1;
	go(0,0,1);
	cout<<ret<<"\n";
	return 0;
}

