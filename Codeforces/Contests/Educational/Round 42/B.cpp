#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
int main(){
	int n,a,b; 
	cin>>n>>a>>b; 
	string s; 
	cin>>s; 
	int ans = 0;
	int lst = -1;
	for(int i=0;i<n;i++){
		if(s[i]=='*'){
			lst = -1;
			continue;
		}
		if(lst==-1){
			if(a>b)lst = 2;
			else lst = 1;
		}
		if(lst==1 and b>0){
			b--;
			ans++;
			lst = 2;
			continue;
		}
		if(lst==2 and a>0){
			a--;
			ans++;
			lst = 1;
			continue;
		}
		lst = -1;
	}
	cout<<ans<<endl;
	return 0;
}
