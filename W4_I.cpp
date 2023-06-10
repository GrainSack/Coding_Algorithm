#include<bits/stdc++.h>
using namespace std;
int n,m,x;
char s[11];

//int oper(string s, int n, int temp){
//	if(s == "add"){
//		temp |= (1<< n-1 );
//	}
//	return temp;
//	
//	if(s == "check"){
//		if(temp & (1<<n-1)){
//			cout<<"1"<<'\n';
//		}
//		else{
//			cout<<"0"<<'\n';
//		}
//		return temp;
//	}
//	else if(s == "remove"){
//		temp -=(1<<n-1);
//		return temp;
//	}
//	else if(s =="all"){
//		temp = (1<<20)-1;
//	}
//	else if(s=="empty"){
//		temp =0;
//		return temp;
//	}
//	else if(s == "toggle"){
//		if(temp&(1<<n-1)){
//			temp -=(1<<n-1);
//		}
//		else{
//			temp |= (1<<n-1);
//		}
//		return temp;
//	}
//}

main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	scanf(" %d", &m);
	for (int i = 0; i < m; i++){
        scanf(" %s %d", &s, &x);
        if(s[0]=='a'&&s[1]=='d') n|=(1<<x);
        else if(s[0]=='r')n &=~(1<<x);
        else if(s[0]=='c')printf("%d\n", (n&(1<<x))==0? 0 : 1);
        else if(s[0]=='a'&&s[1]=='l')n=(1<<21)-1;
        else if(s[0]=='t')n^=(1<<x);
        else n = 0;
	}
}
