#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

void solve(){
    ll n; cin>>n;
    vector<ll> dp (n+1);
    dp[0] = 1; dp[1] = 1;
    ll sum = 1;
    for(int i = 2; i<=n; i++){
        if(i%2 == 1) sum = ((sum % MOD - dp[(i-1)/2] % MOD) + MOD) % MOD;
        dp[i] = sum % MOD;
        sum += dp[i] % MOD;
    }
    cout<<dp[n];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}