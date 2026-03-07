#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, k;
    cin>>n>>k;
    vector<ll> pesos (n+1);
    vector<ll> dp (n+1, 1e16);
    for(int i=1;i<=n;i++){
        cin>>pesos[i];
    }
    dp[1] = 0;
    for(int i=2;i<=n;i++){
        for(int j = i-1; j>=1 && i-j<=k; j--){
            if(dp[i] > dp[j] + abs(pesos[i] - pesos[j])){
                dp[i] = dp[j] + abs(pesos[i] - pesos[j]);
            }
        }
    }
    cout<<dp[n];
    return 0;
}