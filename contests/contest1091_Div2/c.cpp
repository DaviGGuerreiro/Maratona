#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n, m, a, b; cin>>n>>m>>a>>b;
    if(n == 1 && m == 1){cout<<"YES"<<'\n'; return;}
    ll x = gcd(n,a);
    ll y = gcd(m,b);
    ll z = gcd(m,n);
    if(x == 1 && y == 1 && z < 3){
        cout<<"YES"<<'\n';
    }
    else{
        cout<<"NO"<<'\n';
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}