#include<bits/stdc++.h>
using namespace std;
#define next aaaa
#define prev aaa
vector<int> v;
const int Max=200000;
int visited[Max],m,n,prev[Max],ret,now;
queue<int> q;

main(){
	cin>>n>>m;
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	q.push(n);
	visited[n]=1;
	while(q.size()){
		now = q.front();q.pop();
		if(now==m){
			ret = visited[m];
			break;
		}
		for(int next : {now+1,now-1,now*2}){
			if(next >= Max || next < 0 || visited[next]) continue;  
            visited[next] = visited[now] + 1; 
            prev[next] = now; 
            q.push(next); 
		} 
	}
	for(int i=m;i !=n; i = prev[i]){
		v.push_back(i);
	}
	v.push_back(n);
	reverse(v.begin(),v.end());
	cout<<ret-1<<"\n";
	for(int i : v){
		cout<<i<<" ";
	}
	return 0;
}
