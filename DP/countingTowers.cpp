#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int m = 1e9 + 7;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n;
    cin>>t;
    vector<ll> dp (1e6,0);
    dp[0] = 2;
    ll r = 1;
    ll l = 1;
    ll aux;
    for(int i=1;i<1e6;i++){
        aux = r;
        r = (4*r + l)%m;
        l = (aux + 2*l)%m;
        dp[i] = (r + l)%m;
    }
    while(t--){
        cin>>n;
        cout<<dp[n-1]<<'\n';
    }
    return 0;
}