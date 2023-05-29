#include<bits/stdc++.h>
using namespace std;
int n,cnt,result;
int st[3],visited[64][64][64];

int _a[6][3]={
	{9,3,1},{9,1,3},{3,9,1},{3,1,9},{1,3,9},{1,9,3}
};

struct A{
	int a,b,c;
};

queue<A> q;

void bfs(int a, int b, int c){
	visited[a][b][c]=0;
	q.push({a,b,c});
	while(q.size()){
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();
		for(int i=0; i<6;i++){
			int na = max(0,a - _a[i][0]);
			int nb = max(0,b - _a[i][1]);
			int nc = max(0,c - _a[i][2]);
			if(visited[na][nb][nc])continue;
			visited[na][nb][nc] = visited[a][b][c]+1;
			q.push({na,nb,nc});
		}
		if(visited[0][0][0]){
			break;
		}
	}
}

main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>st[i];
	}
	bfs(st[0],st[1],st[2]);
	cout<<visited[0][0][0]<<'\n';
	return 0;
}
