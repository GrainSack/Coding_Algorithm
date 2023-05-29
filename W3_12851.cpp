#include<bits/stdc++.h>
using namespace std;

int a[100004],visited[100004],n,m,cnt;
int max_= 100004;


main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	if(n==m){
		puts("0");puts("1");
		return 0;
	}
	a[n]=1;visited[n]=1;
	queue<int> q;
	q.push(n);

	while(q.size()){
		int now =q.front(); q.pop();
		for(int next : {now-1,now+1,2*now}){
			if(0<=next&&next<=max_){
				if(!visited[next]){
					q.push(next);
					visited[next]= visited[now]+1;
					a[next] += a[now];
				}else if(visited[next] == visited[now]+1){
					a[next] += a[now];
				}
			}
		}
	}
	
	cout<<visited[m]-1<<"\n"<<a[m]<<"\n";
	return 0;
}

