#include<bits/stdc++.h>
using namespace std;

string str, str_r;
int tof;

main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >>str;
	str_r = str;
	reverse(str.begin(),str.end());
	
	if(str_r == str)
		cout<< 1;
	else
		cout<< 0;
		
	return 0;
}
