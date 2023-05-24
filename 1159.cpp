#include<bits/stdc++.h>
using namespace std;

int cnt[26], a,b;
string str, s;

main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>> a;
	string m;
	for(int i=0; i<a; i++){ 
		cin >>m;
		cnt[m[0]-'a']++;
	}
	for(int i =0;i< 26 ;i++){
		if(cnt[i] >= 5)
			s += (i + 'a');
	}
	if(s.size())cout<< s <<"\n";
	else cout<<"PREDAJA"<<"\n";
	return 0;
}
