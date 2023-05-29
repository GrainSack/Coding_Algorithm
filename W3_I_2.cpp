#include<bits/stdc++.h>
using namespace std;
const int Max = 500000;
int ok, m, n, visited[2][Max+4], turn =1;
main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>m>>n;
	if(m==n){
		cout<<0<<"\n";return 0;
	}
	queue<int> q;
	q.push(m);
	visited[0][m]=1;
	while(q.size()){
		n += turn;
		if(m==n){
			ok = true;break;
		}
		if(visited[turn%2][n]){
			ok = true; break;
		}
		if(n>Max)break;
		int qsize = q.size();
		for(int i =0; i<qsize;i++){
			int now = q.front();q.pop();
			for(int next : {now+1,now-1,2*now}){
				if(next<0||next>Max||visited[turn%2][next])continue;
				visited[turn%2][next] = visited[(turn+1)%2][now]+1;
				if(next ==n){
					ok = true; break;
				}
				q.push(next);
			}
			if(ok)break;
		}
		if(ok)break;
		turn++;
	}
	if(ok){
		cout<< turn<<"\n";
	}
	else{
		cout<<-1<<"\n";
	}
	return 0;
}
