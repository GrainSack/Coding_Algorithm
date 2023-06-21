#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
vector<double> v;
double t;
int n;
main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	priority_queue<double> pq;
	for(int i=0; i<n;i++){
		cin>>t;
		if(pq.size() == 7){
			pq.push(t); pq.pop();
		}
		else{
			pq.push(t);
		}
	}
	while(pq.size()){
		v.push_back(pq.top()) ; pq.pop();
	}
	reverse(v.begin(), v.end());
	cout<<fixed;
	cout.precision(3);
	
	for(double i : v){
		cout<< i<<'\n';
	} 
	
	return 0;
}
