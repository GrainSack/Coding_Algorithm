#include<bits/stdc++.h>
using namespace std;
int n,m;
main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		bool flag = 0;
		int cnt = 0;
		int c[m];
		char str_c = 'c';
		char str;
		for(int j=0;j<m;j++){
			cin>>str;
			c[j]=-1;
			if(str==str_c){
				flag =1;cnt=0;c[j]=0;
			}
			else if(flag==1&&str!=str_c){
				c[j]=++cnt;
			}
		}
		for(int j=0;j<m;j++){
			cout<<c[j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
