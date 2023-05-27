#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int s,t;

main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>s;
		int cnt_2, cnt_5 = 0;
		for(int j=2;j<=s;j*=2){
			cnt_2+=s/j;
		}
		for(int j=5;j<=s;j*=5){
			cnt_5+=s/j;
		}
		cout<<min(cnt_5,cnt_2)<<"\n";
	}
	return 0;
}
