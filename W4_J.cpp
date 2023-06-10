#include<bits/stdc++.h>
using namespace std;
int m,n,a[6][6];
const int INF = -987654321;
int ret = INF;

//가로세로 따로 처리 

main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++){
		for(int j=0; j<m;j++){
			scanf("%1d" ,&a[i][j]);
		}
	}
	
	for(int size = 0;size<(1<<m * n);size++){
		int sum =0;
		
		for(int i=0;i<n;i++){
			int cur = 0;
			for(int j = 0;j<m;j++){
				int k = i * m +j;
				if((size&(1<<k))==0){
					cur = cur * 10 + a[i][j];
				}
				else{
					sum +=cur;
					cur=0;
				}
			}
			sum += cur;
		}
		for(int j=0;j<m;j++){
			int cur = 0; 
			for(int i=0;i<n;i++){
				int k = i*m+ j;
				if((size&(1<<k))!=0){	
					cur = cur*10 + a[i][j];
				}
				else{
					sum+= cur;
					cur =0;
				}
			}
			sum += cur;
		}
		ret = max(sum,ret);
	}
	cout<<ret<<'\n';
	return 0;
}
