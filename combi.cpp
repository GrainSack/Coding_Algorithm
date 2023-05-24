#include<bits/stdc++.h>
using namespace std;

int n,m, a[54][54];
vector<vector<int>> chiken_list;
vector<pair<int, int>> chiken, house;
int final =987644321;

void combi(int start, vector<int> v){
	if(v.size()==m){
		chiken_list.push_back(v);
		return;
	}
	for(int i= 1 + start; i<chiken.size();i++){
		v.push_back(i);
		combi(i,v);
		v.pop_back();
	}
	return;
}

main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<n;i++){
		for(int j =0;j<n;j++){
			cin>>a[i][j];
			if(a[i][j]==1){
				house.push_back({i,j});
			}
			if(a[i][j]==2){
				chiken.push_back({i,j});
			}
		}
	}
	vector<int> v;
	combi(-1,v);
	for(vector<int> list_ : chiken_list){
		int ret = 0;
		for(pair<int,int> _house : house){
			int _min = 987654321;
			for(int chk : list_){
				int _dist = abs(_house.first-chiken[chk].first) + abs(_house.second - chiken[chk].second);
				_min = min(_dist,_min);
			}
			ret +=_min;
		}
		final = min(ret,final);
	}
	cout<<final<<"\n";
	return 0;
}

