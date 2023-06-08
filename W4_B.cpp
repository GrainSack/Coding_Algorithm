#include<bits/stdc++.h>
using namespace std;
int m, a[24];
string s;
const int INF = 987654321;
int ret = INF;

void go(int here){
	if(here == m+1){
		int sum =0;
		for(int i =1; i<=(1<<(m-1));i *=2){
			int cnt =0 ;
			for(int j =1; j<=m;j++){
				if(a[j]&i)cnt++;
			}
			sum += min(cnt, m-cnt);
		}
		ret = min(ret,sum);
		return;
	}
	a[here] = ~a[here];
	go(here+1);
	a[here] = ~a[here];
	go(here+1);
}

main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>m;
	for(int i=1; i<=m;i++){
		cin>>s;
		int value = 1;
		for(int j =0; j< s.size();j++){
			if(s[j]=='T'){
				a[i] |= value;
			}
			value *=2;
		}
	}
	go(1);
	cout<<ret<<'\n';
	return 0;
}
