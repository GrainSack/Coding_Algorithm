#include<bits/stdc++.h>
using namespace std;

int n,l,r,a[54][54],visited[54][54],sum,cnt;
vector<pair<int,int>> v;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

void dfs(int y, int x, vector<pair<int,int>> &v){
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny<0||nx<0||ny>=n||nx>=n||visited[ny][nx])continue;
		if(abs(a[y][x] - a[ny][nx])>=l&&abs(a[y][x] - a[ny][nx])<=r){
			v.push_back({ny,nx});
			visited[ny][nx]=1;
			sum += a[ny][nx];
			dfs(ny,nx,v);	
		}
	}
}
	
main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>l>>r;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	while (true){
		bool flag =0;
		memset(visited,0,sizeof(visited));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(!visited[i][j]){
					v.clear();
					sum = a[i][j];
					v.push_back({i,j});
					visited[i][j]=1;
					dfs(i,j,v);
					if(v.size()==1)continue;
					for(pair<int,int> p : v){
						a[p.first][p.second] = sum/v.size();
						flag =1;
					}
				}
			}
		}
		if(!flag)break;
		cnt++;
	}
	cout<<cnt<<"\n";
	return 0;
}
