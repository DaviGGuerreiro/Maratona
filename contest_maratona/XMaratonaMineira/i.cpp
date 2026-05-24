#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main(){

    int K,P;
    cin>>K>>P;
    
    vector<int> dp(K+1,0);


    dp[0]=0;
    dp[1]=0;
    dp[2]=8;
    dp[3]=24;

    for(int i=4;i<=K;i++){

        dp[i]=(((8*dp[i-2])%P) + ((8*dp[i-3])%P) +2*P)%P;

    }

    cout<<dp[K];


}