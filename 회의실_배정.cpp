#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t,a,b,cnt;
vector<pair<int,int>> v;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}


main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>t;
	for(int i=0; i<t; i++){
		cin>>a>>b;
		v.push_back({b,a});
	}
	sort(v.begin(), v.end());
	
	b = v[0].first;
	a = v[0].second;
	
	for(int i=1; i<v.size(); i++){
		if(v[i].second <b) continue;
		b = v[i].first; cnt++;	
	}
	cout<< cnt +1<< '\n';
	
	return 0;
}
