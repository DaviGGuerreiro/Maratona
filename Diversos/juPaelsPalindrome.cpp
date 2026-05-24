#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string s; int n;

void solve(){
    cin>>n; cin>>s;
    vector<int> dp (1<<26,1e9);
    int mask = 0; int maximo = 1; dp[0] = 0;
    for(int i = 0; i<n; i++){
        mask ^= (1<<(s[i] - 'a'));
        if(dp[mask] == 1e9) dp[mask] = i+1;
        else maximo = max(maximo, i + 1 - dp[mask]);
        for(int j = 0; j<26; j++){ 
            if(dp[mask^(1<<j)] != 1e9) maximo = max(maximo, i + 1 - dp[mask^(1<<j)]); //1 diferente
        }
    }
    cout<<maximo<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}