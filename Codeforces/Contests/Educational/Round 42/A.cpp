#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
ll a[200005];
int main(){
	int n;
	cin>>n; 
	ll sum = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	ll tmp = 0;
	for(int i=1;i<=n;i++){
		tmp+=a[i];
		if(tmp*2 >=sum){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}
