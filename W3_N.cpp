#include<bits/stdc++.h>
using namespace std;
int n, a[1030];
vector<int> ret[14];


void go(int s, int e, int level){
	if(s > e){
		return;
	}
	if(s == e){
		ret[level].push_back(a[s]);
		return;
	}
	int mid = (s + e)/2;
	ret[level].push_back(a[mid]);
	go(s,mid-1,level + 1);
	go(mid + 1, e, level+1);
	return;
}

main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	int node_num = (int)pow(2,n)-1;
	
	for(int i=0; i <node_num; i++){
		cin>>a[i];
	}
	go(0, node_num , 1);
	
	for(int i = 1; i <= n; i++){
		for(int j : ret[i]){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
