#include<bits/stdc++.h>
using namespace std;
int a, b, c, a_in,a_out,b_in,b_out,c_in,c_out, f;
int a_t[100], b_t[100],c_t[100],d_t[100],e_t[100];

main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>a>>b>>c>>a_in>>a_out>>b_in>>b_out>>c_in>>c_out;
	
	for(int i=a_in; i<a_out; i++){
		a_t[i] = 1;
	}
	for(int i=b_in; i<b_out; i++){
		b_t[i] = 1;
	}
	for(int i=c_in; i<c_out; i++){
		c_t[i] = 1;
	}
		
	for(int i=0;i<100; i++){
		d_t[i]=a_t[i]+b_t[i] + c_t[i];
	}
	for(int i = 0 ; i<100; i++){
		if(d_t[i]==1)
		{e_t[i]=d_t[i] * a ;
		}
		if(d_t[i]==2){
			e_t[i] = d_t[i] * b; 
		}
		if(d_t[i]==3){
			e_t[i] =  d_t[i] * c; 
		}
	}
	for(int i=0; i<100; i++){
		f += e_t[i];
		}
	cout<< f ;
	
	return 0;
}
