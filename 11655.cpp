#include<bits/stdc++.h>
using namespace std;
string s;

main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	getline(cin,s);
	for(int i;i<s.size();i++){
		if(s[i]>=65 && s[i]<=90){
			if(s[i]+13 > 90){
				s[i] = s[i] - 26 + 13;
			}
			else
				s[i] = s[i] + 13;
		}
		else if(s[i]>=97 && s[i] <=122){
			if(s[i]+13 >122){
				s[i] = s[i]-26+13;
			}		
			else
				s[i] = s[i] +13;
		}
	}
	cout<<s<<'\n';
	return 0;
}
