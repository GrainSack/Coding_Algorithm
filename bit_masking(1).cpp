#include<bits/stdc++.h>
using namespace std;
const int d = 4;
string a[d] = {"���","����","����","��"};

main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int s = 18; //10010
	int idx = 1;
	int s1 = s & ~(1<<idx); //10000 ���ϴ� idx�� bit ���� using complement(~) operator
	int s2 = s ^ (1<< 0);   //10011 ���ϴ� idx�� bit ������Ű�� using XOR(^) operator
	int s3 = s | (1<< 5);   //110010 (50) ���ϴ� idx�� bit�� �ѱ� using OR(|) operator 
	cout<<s1<<"::"<<s2<<"::"<<(-s & s)<<"::"<<s3<<'\n';
	//������ ��Ʈ idx���ϱ�
	//idx = (-s & s) where as s = 16(10010) idx = 2
	
	//m�� bit ���δ� �ѱ�
	int n = 5;
	cout<<(1<<n)-1<<'\n'; //31[11111(2)]
	
	//m��° bit �� �����ִ��� Ȯ���ϱ�
	if(s&(1<<idx)){
		cout<< "�ش� idx :"<< idx <<"�� �����ֽ��ϴ�"<<'\n';
	}
	 
	return 0;
}


