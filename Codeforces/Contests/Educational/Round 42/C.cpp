#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
string l2s(ll x){
	string ret = "";
	while(x){
		char c = '0' + x%10;
		ret = c+ret;
		x/=10;
	}
	return ret;
}
string s;
int in(ll x){
	string ss = l2s(x);
	int j = 0;
	int zs = s.size();
	int zss = ss.size();
	for(int i=0;i<zs;i++){
		if(j==zss)break;
		if(s[i]==ss[j])j++;
	}
	if(j==zss)return zs-zss;
	else return -1;
}
int main(){
	cin>>s; 
	ll ans = 1e9;
	for(ll i=1;i<=1e5;i++){
		ll trt = in(i*i);
		if(trt>=0){
			ans = min(ans,trt);
		}
	}
	if(ans>1e8)ans = -1;
	cout<<ans<<endl;
	return 0;
}
