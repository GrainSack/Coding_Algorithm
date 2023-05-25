#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int d,t,temp,psum[100001], ret= -10000004;

main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>> d>>t;
	for(int i=1; i<=d;i++){
		cin>>temp; psum[i] =psum[i-1] + temp;
	}
	for(int i = t;i<=d;i++){
		ret = max(ret,psum[i]-psum[i-t]);
	}
	cout<< ret <<"\n";
	return 0;
}
