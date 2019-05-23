//https://codeforces.com/contest/961/submission/36954425
#include<bits/stdc++.h>
using namespace std;

long long n,k;
long long a[100005];
long long b[100005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long cnt = 0;
    for(int i=0;i<n;i++){
        cin>>b[i];
        cnt+=b[i]*a[i];
    }
    long long curr = 0;
    for(int i=0;i<k;i++){
        curr+=(1-b[i])*a[i];
    }
    long long ans = cnt+curr;
    for(int i=0;i+k<n;i++){
        curr-=(1-b[i])*a[i];
        curr+=(1-b[i+k])*a[i+k];
        ans=max(ans,cnt+curr);
    }
    cout<<ans;
    return 0;
}
