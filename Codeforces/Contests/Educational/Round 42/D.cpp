#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define fr first
#define sc second
#define pb push_back
map<ll,set<ll> >mp;
vector<pair<ll,ll> >v;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; 
	cin>>n;
	ll x; 
	for(int i=1;i<=n;i++){
		cin>>x; 
		mp[x].insert(i);
	}
	int trt;
	for(auto it:mp){
		x = it.fr;
		while(it.sc.size()>1){
			
			trt = *it.sc.begin();
			it.sc.erase(trt);
			trt = *it.sc.begin();
			it.sc.erase(trt);
			mp[x+x].insert(trt);
		}
		for(auto xx:it.sc){
			v.pb({xx,x});	
		}
	}
	sort(v.begin(),v.end());
	cout<<v.size()<<endl;
	for(auto xx:v)cout<<xx.sc<<" ";
	return 0;
}
