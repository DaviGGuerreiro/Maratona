#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n; cin>>n;
    vector<ld> p (n+1);
    ld resposta = 0;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    vector<vector<ld>> dp (n+1, vector<ld> (n+1,0.0));
    dp[0][0] = 1.0;
    // i primeiros, j caras, n-j coroas;
    for(int i = 1; i<=n; i++){
        dp[i][0] = dp[i-1][0] * (1.0 - p[i]);
        for(int j = 1; j<=i; j++){
            dp[i][j] += dp[i-1][j-1] * p[i];
            dp[i][j] += dp[i-1][j] * (1.0 - p[i]);
            if(i == n && j > (n/2)) resposta += dp[i][j];
        }
    }
    cout<<fixed<<setprecision(10)<<resposta;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}