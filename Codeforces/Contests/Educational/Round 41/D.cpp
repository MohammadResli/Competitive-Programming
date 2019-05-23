//https://codeforces.com/contest/961/submission/53439111
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define pb push_back
struct pt {
	ll x,y;
	pt operator +( pt a){ return {x+a.x,y+a.y};}
	pt operator -( pt a){ return {x-a.x,y-a.y};}
};
ll dot (pt a, pt b){
	return (a.x*b.y - a.y*b.x);
}
bool col(pt a, pt b ,pt c){
	return (dot(c-a,c-b)==0);
}
pt p[100005];
bool vis[100005];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; 
	cin>>n; 
	int x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		p[i] = {x,y};
	}
	if(n<=4){
		cout<<"YES\n";
		return 0;
	}
	vector<pt>v;
	v.pb(p[0]);
	v.pb(p[1]);
	vis[0] = vis[1] = true;
	set<pair<int,int> > st;
	for(int i=2;i<n;i++){
		if(v.size()==4)break;
		int z = v.size();
		bool go = false;
		for(int j=0;j<z;j++){
			for(int k=j+1;k<z;k++){
				pair<int,int> trt = {j,k};
				if(col(v[j],v[k],p[i])){
					go = true;
					if(st.size()==2 and !st.count(trt))go = false;
					else st.insert(trt);
				}
			}
		}
		if(go)continue;
		vis[i] = true;
		v.pb(p[i]);
	}
	if(v.size()<4){
		cout<<"YES\n";
		return 0;
	}
	bool can = false;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(j<=i)continue;
			for(int ii=0;ii<4;ii++){
				if(ii==i or ii==j)continue;
				for(int jj=0;jj<4;jj++){
					if(jj==i or jj==j or jj<=ii)continue;
					bool tmp = true;
					for(int k=0;k<n;k++){
						if(vis[k])continue;
						if(!col(v[i],v[j],p[k]) and !col(v[ii],v[jj],p[k])){
							tmp = false;
							break;
						}
					}
					if(tmp)can = true;
				}
			}
		}
	}
	if(can)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
