#include<bits/stdc++.h>
using namespace std;
string s,str,start, fin;
int m;

main(){
	cin>>m;
	cin>>s;
	int pos = s.find('*');
	start = s.substr(0,pos);
	fin = s.substr(pos+1);
	
	for(int i= 0; i<m ;i++){
		cin>>str;
		if(start.size() + fin.size() > str.size()){
			cout<<"NE\n";
		}
		else{
			if(str.substr(0,start.size())==start && str.substr(str.size()-fin.size())==fin)
				cout<< "DA\n";
			else
				cout<< "NE\n";
		}
	}
	return 0;
}
