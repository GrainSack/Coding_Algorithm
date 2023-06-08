#include<bits/stdc++.h>
using namespace std;
const int INF = -987654321;
int a = (1<<26);
int m,n;
char al[24][24];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int cnt =1;
int ret = INF;
void go(int y, int x,int level){
	//cout<<y<<"::"<<x<<'\n';
	ret = max(ret,level);
	for(int i =0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny<0||nx<0||ny>=m||nx>=n)continue;
		if(a&(1<<(al[ny][nx]-'A')))continue;
		a|= (1<<(al[ny][nx]-'A'));
		go(ny,nx,level+1);
		a -= (1<<(al[ny][nx]-'A'));
	}
	return;
}

main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>m>>n;
	for(int i=0; i<m;i++){
		for(int j = 0; j<n;j++){
			cin>>al[i][j];
		}
	}
	a|=(1<<(al[0][0]-'A'));
	go(0,0,1);
	
	cout<<ret <<'\n';
	return 0;
}
