#include<bits/stdc++.h>
using namespace std;

string str;
int vcnt,icnt;
bool v_include, flag;
bool classify(int idx){
	return(idx=='a'||idx=='e'||idx=='i'||idx=='o'||idx=='u');
}

main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	while(true){
		cin>>str;
		if(str == "end")break;
		vcnt =0;
		icnt= 0;
		v_include=0;
		flag = 0;
		int prev = -1;
		for(int i = 0; i<str.size();i++){
			int idx = str[i];
			if(classify(idx)){
			vcnt++,icnt=0;v_include = 1;}
			else {vcnt=0;icnt++;}
			if(vcnt==3||icnt==3){flag=1;}
			if(i>=1&&(idx==prev) && (idx!='e' && idx!='o')){
				flag=1;}
			prev = idx;	
		}
		if(v_include==0)flag=1;
		if(flag) cout<<'<'<< str<<'>' <<" is not acceptable."<<"\n";
		else cout<<'<'<< str<<'>' <<" is acceptable."<<"\n";
	}
	return 0;
}
