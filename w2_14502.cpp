#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> viruslist,walllist;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n,m,visited[10][10],a[10][10],ret;

void dfs(int y, int x){
	for(int i=0;i<4;i++){
		int ny = y +dy[i];
		int nx = x + dx[i];
		if(ny<0||nx<0||ny>=n||nx>=m||visited[ny][nx]==1||a[ny][nx]==1) continue;
		visited[ny][nx]=1;
		dfs(ny,nx);
	}
	return;
}


int solve(){
	fill(&visited[0][0],&visited[0][0]+10*10,0);
	for(pair<int,int> b : viruslist){
		visited[b.first][b.second]=1;
		dfs(b.first,b.second);
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(visited[i][j]==0&&a[i][j]==0)cnt++;
		}
	}
	return cnt;
}
main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0; j<m;j++){
			cin>>a[i][j];
			if(a[i][j]==2)viruslist.push_back({i,j});
			if(a[i][j]==0)walllist.push_back({i,j});
		}
	}
	for(int i=0;i<walllist.size();i++){
		for(int j=0;j<i;j++){
			for(int k =0;k<j;k++){
				a[walllist[i].first][walllist[i].second]=1;
				a[walllist[j].first][walllist[j].second]=1;
				a[walllist[k].first][walllist[k].second]=1;
				ret = max(ret,solve());
				a[walllist[i].first][walllist[i].second]=0;
				a[walllist[j].first][walllist[j].second]=0;
				a[walllist[k].first][walllist[k].second]=0;
			}
		}
	}
	cout<<ret<<"\n";
	return 0;
}
