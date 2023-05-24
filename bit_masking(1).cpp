#include<bits/stdc++.h>
using namespace std;
const int d = 4;
string a[d] = {"사과","딸기","포도","배"};

main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int s = 18; //10010
	int idx = 1;
	int s1 = s & ~(1<<idx); //10000 원하는 idx의 bit 끄기 using complement(~) operator
	int s2 = s ^ (1<< 0);   //10011 원하는 idx의 bit 반전시키기 using XOR(^) operator
	int s3 = s | (1<< 5);   //110010 (50) 원하는 idx의 bit를 켜기 using OR(|) operator 
	cout<<s1<<"::"<<s2<<"::"<<(-s & s)<<"::"<<s3<<'\n';
	//최하위 비트 idx구하기
	//idx = (-s & s) where as s = 16(10010) idx = 2
	
	//m개 bit 전부다 켜기
	int n = 5;
	cout<<(1<<n)-1<<'\n'; //31[11111(2)]
	
	//m번째 bit 가 켜져있는지 확인하기
	if(s&(1<<idx)){
		cout<< "해당 idx :"<< idx <<"가 켜져있습니다"<<'\n';
	}
	 
	return 0;
}


