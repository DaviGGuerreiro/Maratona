#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    vector<ll> dp (7500, 0); dp[0] = 1;
    vector<int> coins = {1, 5, 10, 25, 50};
    for(auto it : coins){
        for(int i = it; i<7500; i++){
            dp[i] += dp[i-it];
        }
    }
    int n;
    while(cin>>n){
        cout<<dp[n]<<'\n';
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}