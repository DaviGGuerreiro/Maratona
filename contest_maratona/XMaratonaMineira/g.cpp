#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FORi(n) for(int i=0;i<n;i++)
#define FORj(n) for(int j=0;j<n;j++)
#define all(a) (a).begin(),(a).end()
#define printn(v,n) for(int i=0;i<n;i++) cout << v[i] << (i == n-1 ? "\n" : " ")

void solve() {
    int n; cin>>n;

    int ans = 2;
    FORi(n) {
        int a,b; cin>>a>>b;

        if(a == ans) { ans = b; }
        else if(b == ans) { ans = a; }
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    solve();
}