#include<bits/stdc++.h>
using namespace std;

int visited[304][304],n,m,y_1,x_1,y_2,x_2,cnt;
char a[304][304];
int y,x;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
queue<pair<int,int>> q;

main(){
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &y_1, &x_1, &y_2, &x_2);
    y_1--, x_1--, y_2--, x_2--; 
    for(int i = 0; i < n; i++){
        scanf("%s", a[i]); 
    }
    q.push({y_1,x_1});
	visited[y_1][x_1]=1;
	while(a[y_2][x_2] != '0'){
		cnt++;
		queue<pair<int,int>> p;
		while(q.size()){
			tie(y,x) = q.front();q.pop();
			for(int i=0;i<4;i++){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny<0||nx<0||ny>=n||nx>=m||visited[ny][nx])continue;
				visited[ny][nx] = cnt;
				if(a[ny][nx]!='0'){
					a[ny][nx] = '0';
					p.push({ny,nx});
				}
				else{
					q.push({ny,nx});
				}
			}
		}
		q = p;
	}
	printf("%d\n",visited[y_2][x_2]);
}
