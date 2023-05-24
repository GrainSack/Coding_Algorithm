#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main(){
	while(scanf("%d",&n)!=EOF){
		int cnt=1, ret=1;
		while(true){
			if(ret%n==0){
				printf("%d\n",cnt);
				break;
			}
			else{
				ret = ret*10 +1;
				ret %=n;
				cnt++;
			}
		}
	}
	return 0;
}
