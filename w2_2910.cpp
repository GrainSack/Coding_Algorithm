#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,int>> v;
map<int,int> mp, mp_first;
int n,c,a[1004];

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first){
		return mp_first[a.second]<mp_first[b.second];
	}
	return a.first>b.first;
}
main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>c;
	for(int i=0;i<n;i++){
		cin>>a[i];mp[a[i]]++;
		if(mp_first[a[i]]==0)mp_first[a[i]]=i+1;
	}
	for(auto it : mp){
		v.push_back({it.second, it.first});
	}
	sort(v.begin(),v.end(),cmp);
	for(auto i : v){
		for(int j =0;j<i.first;j++){
			cout<<i.second<<" ";
		
		}
	}
	return 0;
	
}
