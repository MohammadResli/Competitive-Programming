//https://codeforces.com/contest/961/submission/36952405
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m,x;
ll v[10001];

int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>x;
		v[x]++;
	}
	sort(v+1,v+n+1);
	cout<<v[1]<<endl;
}
