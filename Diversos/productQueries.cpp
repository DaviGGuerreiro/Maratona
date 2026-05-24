#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        int aux;
        vector<int> dp (n+1, 1e9);
        for(int i=0;i<n;i++){
            cin>>aux;
            dp[aux] = 1;
        }
        for(int i=1;i<=n;i++){
            int d = 2;
            while(d <= sqrt(i)){
                if(i % d == 0){
                    dp[i] = min(dp[i], dp[i/d] + dp[d]);
                }
                d++;
            }
            if(dp[i] == 1e9){
                cout<<"-1"<<' ';
            }
            else{
                cout<<dp[i]<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}