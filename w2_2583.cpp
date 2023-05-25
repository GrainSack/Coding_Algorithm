#include<bits/stdc++.h>
using namespace std;
int a[104][104], visited[104][104], x,y,n,m,k,cnt,b,c,d,e;
vector<int> fin ;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int dfs(int y, int x){
	int fin = 1;
	visited[y][x] =1;
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x +dx[i];
		if(ny<0||nx<0||ny>=n||nx>=m||visited[ny][nx]==1) continue;
		if(a[ny][nx]==1) continue;
		fin +=dfs(ny,nx);
	}
	return fin ;
}

main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>k;
	for(int s=0; s<k;s++){
		cin>>b>>c>>d>>e;
		for(int i=b;i<d;i++){
			for(int j = c;j<e;j++){
				a[j][i]=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j =0;j<m;j++){
			if(a[i][j]==0 &visited[i][j]==0){
				fin.push_back(dfs(i,j));
			}
		}
	}
	sort(fin.begin(),fin.end());
	cout<<fin.size()<<"\n";
	for(int a : fin)cout<<a<<" ";
	return 0;
}
