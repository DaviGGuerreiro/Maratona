#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    int quantidade;
    int mask;
    string s;
    vector<int> dp (8, 1e8);
    dp[0] = 0;
    for(int i=0;i<n;i++){
        mask = 0;
        cin>>quantidade>>s;
        for(auto c : s){ 
            if(c == 'A'){
                mask |= 1;
            }
            else if(c == 'B'){
                mask |= 2;
            }
            else{
                mask |= 4;
            }
        }
        for(int j=0; j<(1<<3);j++){
            int x = j | mask;
            dp[x] = min(dp[x],dp[j]+quantidade);
        }
    }
    if(dp[7] == 1e8){
        cout<<"-1";
    }
    else{
        cout<<dp[7];
    }

    return 0;
}