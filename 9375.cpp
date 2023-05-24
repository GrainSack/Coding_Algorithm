#include<bits/stdc++.h>
using namespace std;
int n,m;
string a,b;

main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	while(n--){
		map<string, int> _map;
		cin>>m;
		for(int i = 0; i<m ; i++){
			cin>>a>>b;
			_map[b]++;
		}
		long long ret = 1;
		for(auto c : _map){
			ret *=((long long)c.second+1);
		}
		ret --;
		cout<<ret<<'\n';
	}
	return 0;
}
