#include<bits/stdc++.h>
using namespace std;
bool check;
string s;
string ret;
main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>s;
	for(int i=0; i< s.size();i++){
		ret += s[i];
		if(!s.size()){
			cout<<"NO";
			break;
		}
		if(ret.size()>=2 && (ret.substr(ret.size()-2,2) == "pi" ||ret.substr(ret.size()-2,2) == "ka")){
			ret.pop_back();
			ret.pop_back();
		}
		if(ret.size()>=3 && (ret.substr(ret.size()-3,3) == "chu")){
			ret.pop_back();
			ret.pop_back();
			ret.pop_back();
		}
//		else if(ret.size() >=4){
//			check =1;
//			break;
//		}
	}
	cout<<ret<<'\n';
	if(ret.size()){
		check = 1;
	}
	
	if(check){
		cout<<"NO";
	}
	else{
		cout<<"YES";
	}
	return 0;
}
