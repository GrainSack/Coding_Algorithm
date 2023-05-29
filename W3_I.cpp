#include<bits/stdc++.h>
using namespace std;
const int Max = 500000;
int visited[2][Max+4],m,n,b,ok,turn=1;
queue<int> q;

main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>m>>n;
	if(m==n){
		cout<<0<<"\n";
		return 0;
	}
	visited[0][m]=1;
	q.push(m);
	while(q.size()){
		n += turn;
		if(n>Max)break;
		if(visited[turn%2][b]){
			ok = true; break;
		}
		int qsize = q.size();
		for(int i =0 ; i < qsize;i++){
			int x = q.front();q.pop();
			for(int next : {x+1,x-1,2*x}){
				if(next<0||next>Max||visited[turn%2][next])continue;
				visited[turn%2][next] = visited[(turn+1)%2][x] +1;
				if(next == n){
					ok = true;
					break;
				}
				q.push(next);
			}
			if(ok)break;
		}
		if(ok)break;
		turn++;
	}
	if(ok){
		cout<<turn<<"\n";
	}
	else{
		cout<<-1<<"\n";
	}
	return 0;
}
