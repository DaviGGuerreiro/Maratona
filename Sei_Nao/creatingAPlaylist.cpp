#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    vector<ll> dp (n,0); 
    vector<ll> vec (n);
    for(int i = 0;i<n;i++){
        cin>>vec[i];
    }
    if(vec[0] > 0) dp[0] = vec[0];
    for(int i = 1;i<n;i++){
        if(i < k){
            dp[i] = max(dp[i-1], vec[i]);
        }
        else{
            dp[i] = max(dp[i-1], dp[i-k] + vec[i]);
        }
    }
    cout<<dp[n-1]<<'\n';

    return 0;
}