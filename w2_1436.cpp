#include<bits/stdc++.h>
using namespace std;

int t;

main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	int i = 666;
	for(;;i++){
		if(to_string(i).find("666")!=string::npos) t--;
		if(t==0) break;
	}
	cout<<i<<"\n";

}
