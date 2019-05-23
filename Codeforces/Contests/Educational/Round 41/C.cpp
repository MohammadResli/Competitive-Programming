//https://codeforces.com/contest/961/submission/36960610
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll even[5];
ll odd[5];

void solve(ll idx){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			ll id = i+j;
			ll q; char ch; cin>>ch; q = ch-'0';
			
			if (id&1){
				even[idx] += (q&1);
				odd[idx] += !(q&1);
			}else{
				even[idx] += !(q&1);
				odd[idx] += (q&1);
			}
		}
	}
}

int main(){
	cin>>n;
	solve(1);
	solve(2);
	solve(3);
	solve(4);
	ll ans = 1e16;
	for (int i=1;i<=4;i++){
		for (int j=1;j<=4;j++){
			if (i == j) continue;
			for (int k=1;k<=4;k++){
				if (k == i || k == j) continue;
				for (int l=1;l<=4;l++){
					if (l == i || l == j || l == k) continue;
					ll res = even[i]+even[j]+odd[k]+odd[l];
					ans = min(ans,res);
				}
			}
		}		
	}
	cout<<ans<<endl;
}
