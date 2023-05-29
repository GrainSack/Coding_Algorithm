#include<bits/stdc++.h>
using namespace std;
int n;
int ret = -987654321;
string s;
vector<char> oper_;
vector<int> num_;

int oper(char a, int b, int c){
	if(a=='+'){
		return b+c;
	}
	if(a == '*'){
		return b*c;
	}
	if(a == '-'){
		return b-c;
	}
}

void go(int here, int num){
	if(here== num_.size() -1){
		ret = max(ret,num);
		return;
	}
	go(here+1,oper(oper_[here],num,num_[here+1]));
	if(here<=num_.size()-3){
		int temp = oper(oper_[here+1],num_[here+1],num_[here+2]);
		go(here+2,oper(oper_[here],num,temp));
	}
	return;
}

main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++){
		if(i%2==0){
			num_.push_back(s[i]-'0');
		}
		else{
			oper_.push_back(s[i]);
		}
	}
	go(0,num_[0]);
	cout<<ret<<"\n";
	return 0;
}
