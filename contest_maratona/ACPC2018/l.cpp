#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n, k; cin>>n>>k;
    int r = 0; int aux;
    for(int i = 0; i < n; i++){
        cin>>aux; r |= aux;
    }
    cout<<r<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("looking.in","r",stdin);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}