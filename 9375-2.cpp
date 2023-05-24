#include<bits/stdc++.h>
using namespace std;

int t,n;
string a,b;

main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--){
		map<string,int> _map;
		cin>>n;
		long long ret = 1;
		for(int i =0 ; i<n;i++){
			cin>>a>>b;
			_map[b]++;
		}
		for(auto c :_map){
			ret*=((long long)c.second + 1);
		}
		ret--;
		cout<<ret<<'\n';
	}
	return 0;
}
