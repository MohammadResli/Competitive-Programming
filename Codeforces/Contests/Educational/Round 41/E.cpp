//https://codeforces.com/contest/961/submission/36975848
#include <bits/stdc++.h>
using namespace std;

#define MAX 200050

vector<vector<long long> > st;
long long a[MAX];

void merge(long long n, long long left, long long right) {
    long long lptr = 0, rptr = 0, cptr = 0;;
    while (lptr < st[left].size() || rptr < st[right].size()) {
        if (lptr == st[left].size())
            st[n][cptr++] = st[right][rptr++];
        else if (rptr == st[right].size())
            st[n][cptr++] = st[left][lptr++];
        else {
            if (st[left][lptr] < st[right][rptr])
                st[n][cptr++] = st[left][lptr++];
            else
                st[n][cptr++] = st[right][rptr++];
        }
    }
}

void construct(long long n, long long ll, long long rl) {
    if (ll == rl) {
        st[n].push_back(a[ll]);
        return;
    }
    construct(2*n+1, ll, (ll+rl)/2);
    construct(2*n+2, (ll+rl)/2+1, rl);
    st[n].resize(rl-ll+1);
    merge(n, 2*n+1, 2*n+2);
}

long long query(long long n, long long ll, long long rl, long long ql, long long qr, long long k) {
    if (rl < ql || ll > qr) return 0;
    if (ll >= ql && rl <= qr) {
        long long t = st[n].end() - upper_bound(st[n].begin(), st[n].end(), k);
        return t;
    }
    long long left = query(2*n+1, ll, (ll+rl)/2, ql, qr, k);
    long long right = query(2*n+2, (ll+rl)/2+1, rl, ql, qr, k);
    return left + right;
}

long long n;
int main() {
    cin>>n;
    for (long long i = 0; i < n; i++) cin>>a[i];

    st.resize(4*MAX);
    construct(0, 0, n-1);
	
	long long ans = 0;
	for (int i=0;i<n;i++){
		ans += query(0,0,n-1,i+1,a[i]-1,i);
	}
	cout<<ans<<endl;
    
}
