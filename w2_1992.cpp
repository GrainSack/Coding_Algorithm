#include<bits/stdc++.h>
using namespace std;
int n;
char a[104][104];

string quad(int y, int x, int size){
	if(size == 1){
		return string(1,a[y][x]);
	}
	char b=a[y][x];
	string ret = "";
	for(int i =y;i<y + size;i++){
		for(int j=x;j<x + size;j++){
			if(b!=a[i][j]){
				ret +='(';
				ret +=quad(y,  x, size/2);
				ret += quad(y, x + size/2, size/2);
				ret += quad (y+ size/2, x, size/2);
				ret+= quad(y+size/2, x+ size/2, size/2);
				ret +=')';
				return ret;
			}
			
		}
	}
	return string(1,a[y][x]);
}

main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	cout<<quad(0,0,n)<<"\n";
	return 0;
}
