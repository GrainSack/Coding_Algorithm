#include<bits/stdc++.h>
using namespace std;
int m,n,a[54][54],v[54][54];
const int dy[]={0,-1,0,1};
const int dx[] = {-1,0,1,0};
const int INF = -987654321;
int ret = INF,ret2 = INF;
int	cnt,cnt2,cnt3;

void go(int y, int x){
	v[y][x]=1;
	for(int i=0;i<4;i++){
		if(a[y][x]&(1<<i))continue;
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny<0||nx<0||ny>=n||nx>=m||v[ny][nx])continue;
		else{
		v[ny][nx] = 1;
		cnt++;
		cnt3++;
		go(ny,nx);
		}
	}
	return;
}


main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>m>>n;
	for(int i=0; i<n;i++){
		for(int j=0; j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!v[i][j]){
			cnt =1;
			go(i,j);
			ret = max(cnt,ret);
			cnt2++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<4;k++){
				if(a[i][j]&(1<<k)){
					fill(&v[0][0],&v[54-1][54] , 0);
					a[i][j] -= (1<<k);
					cnt3=1;
					go(i,j);
					a[i][j] += (1<<k);
					ret2 = max(ret2,cnt3);
				}
			}
		}
	}
	
	
	cout<<cnt2<<'\n'<<ret<<'\n'<<ret2<<'\n';
	return 0;
}
