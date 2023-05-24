#include<bits/stdc++.h>
using namespace std;
const int d = 4;
main(){
	string a[d] = {"사과","딸기","포도","배"};
	
	for(int i=0; i < (1<<d) ;i++){
		string ret = "";
		cout<<i<<":";
		for(int j=0; j < d ; j++){
			if(i & (1<<j)){
				ret +=(a[j] + " ");
			}
		}
		cout<<'\n';
		cout<<ret<<'\n';
	}
	 
	return 0;
}
