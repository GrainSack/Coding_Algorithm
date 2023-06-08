#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int INF = 987654321;
int m,b,c,d,e,sum,mp,mf,ms,mv,ret = INF;

struct A{int mp,mf,ms,mv,cost;
}a[16];
map<int, vector<vector<int>>>ret_v;
main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>m;
	cin>>mp>>mf>>ms>>mv;
	for(int i=0; i<m;i++){
		cin>>a[i].mp>>a[i].mf>>a[i].ms>>a[i].mv>>a[i].cost;
	}
	for(int i = 1 ; i<(1<<m);i++){
		b=c=d=e=sum = 0;
		vector<int> v;
		for(int j = 0; j < m;j++){
			if(i & (1<<j)){
				v.push_back(j+1);
				b += a[j].mp;
				c += a[j].mf;
				d += a[j].ms;
				e += a[j].mv;
				sum += a[j].cost;
				//cout<<sum<<'\n';
			}
		}
		if(b>=mp&&c>=mf&&d>=ms&&e>=mv){
			if(ret>= sum){
				ret = sum;
				ret_v[ret].push_back(v);
			}
		}
	}
	
	if(ret == INF){
		cout<<-1<<'\n';
	}
	else{
		sort(ret_v[ret].begin(), ret_v[ret].end());
		cout<<ret<<"\n";
		for(int a : ret_v[ret][0]){
			cout<< a <<" ";
		}
	}
	return 0;
}
