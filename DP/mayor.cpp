#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve(){
    int n;
    cin>>n;
    if(n == 1){
        cout<<0<<'\n';
        return;
    }
    vector<vector<int>> vec(n, vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];
        }
    }
    vector<vector<ll>> dp (1<<n, vector<ll> (n));
    for(int i = 0;i< 1<<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = 2e9;
        }
    }
    dp[1][0] = 0;
    for(int mask = 1; mask < (1<<n); mask++){
        for(int i=0;i<n; i++) if(mask & (1<<i)){
            for(int j = 0; j<n; j++) if(!(mask & (1<<j))){
                dp[mask ^(1<<j)][j] = min(dp[mask ^ (1<<j)][j], dp[mask][i] + vec[i][j]);
            }
        }
    }
    ll best = 2e9;
    for(int i = 1;i<n;i++){
        best = min(best, dp[(1<<n)-1][i] + vec[i][0]);
    }
    cout<<best<<'\n';
}
 
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}