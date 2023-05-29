#include<bits/stdc++.h>
using namespace std;
int y,x,sy,sx;
int m,n,person[1004][1004],fire_chk[1004][1004],ret;
char a[1004][1004];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
const int INF=987654321;
main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>m>>n;
	fill(&fire_chk[0][0], &fire_chk[0][0] + 1004 * 1004, INF);
	queue<pair<int,int>> q;
	for(int i =0 ; i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			if(a[i][j]=='F'){
				fire_chk[i][j]=1;q.push({i,j});
			}
			if(a[i][j]=='J'){
				sy=i;
				sx = j;
			}
		}
	}
	while(q.size()){
		tie(y,x) = q.front();q.pop();
		for(int i=0;i<4;i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny<0||nx<0||ny>=m||nx>=n||a[ny][nx]=='#'||fire_chk[ny][nx]!=INF)continue;
			fire_chk[ny][nx] = fire_chk[y][x]+1;
			q.push({ny,nx});
		}
	}
	
	person[sy][sx] = 1;
	q.push({sy,sx});
	while(q.size()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if(y==0||x==0||y==m-1||x==n-1){
			ret = person[y][x];
			break;
		}
		for(int i=0; i<4; i++){
			int ny = y +dy[i];
			int nx = x + dx[i];
			if(ny<0||nx<0||ny>=m||nx>=n||a[ny][nx]=='#'||person[ny][nx]!=0)continue;
			if(fire_chk[ny][nx]<=person[y][x]+1)continue;
			person[ny][nx] = person[y][x] +1;
			q.push({ny,nx}); 
		}
	}
	
	if(ret!=0){
		cout<<ret<<"\n";
	}
	else{
		cout<<"IMPOSSIBLE"<<"\n";
	}
	return 0;
}

