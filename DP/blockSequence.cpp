#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> dp (n,0); dp[n-1] = 1;
        vector<int> vec (n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        for(int i=n-2;i>=0;i--){
            dp[i] = 1 + dp[i+1];
            if(vec[i] + 1 + i <= n-1){
                dp[i] = min(dp[i + vec[i] + 1], dp[i]);
            }
            else if(vec[i] + 1 + i == n){
                dp[i] = 0;
            }
        }
        cout<<dp[0]<<'\n';
    }
    return 0;
}