#include<bits/stdc++.h>
using namespace std;
string str,ret;
int t,cnt;
string x,y;
vector<string> a;


void go(){
	while(true){
		if(ret.size()&&ret.front()=='0'){
			ret.erase(ret.begin());
		}
		else break;
	}
	if(ret.size()==0){
		ret = '0';
	}
	a.push_back(ret);
	ret = "";
	return;
}

bool cmp(string x, string y){
	if(x.size()==y.size()){
		return x < y;
	}
	return x.size() < y.size();
}

main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--){
		cin>>str;
		int j = 0;
		ret = "";
		for(int i=0;i<str.size();i++){
			if(str[i]<65){
				ret+=str[i];
			}
			else if(ret.size())
				{go();}
		}
		if(ret.size()){
			go();
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(string i : a){cout<<i<<"\n";
	}
	return 0;
}
 
