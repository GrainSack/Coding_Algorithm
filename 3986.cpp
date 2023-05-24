#include<bits/stdc++.h>
using namespace std;
int m,cnt;
string s;

main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>s;
		stack<char> stk;
		for(char a:s){
			if(stk.size() && stk.top()==a)
				stk.pop();
			else stk.push(a);
		}
		if(stk.size() == 0)cnt++;
	}
	cout<<cnt<<'\n';
	return 0;
}
