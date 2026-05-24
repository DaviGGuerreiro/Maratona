#include<bits/stdc++.h>
using namespace std;

int n, k;
int resposta = 0;

void solve(){
    string s, aux;
    cin>>s>>aux;
    if(aux[0] == aux[1]){
        int r = 0;
        for(int i=0;i<n;i++){
            if(s[i] == aux[0]) r++;
        }
        resposta = min(n,r+k); resposta = resposta * (resposta-1); resposta = resposta/2;
        cout<<resposta;
        return;
    }
    vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (k+1, vector<int> (n+1, -1e9))); // dp[i][j][l] utiliza i primeiros caracteres, com j possiveis mudanças e l caracterse aux[0]
    dp[0][0][0] = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j <= k; j++){
            for(int l = 0; l<n; l++){
                if(dp[i][j][l] != -1e9){
                    int e0 = (s[i] == aux[0]);
                    int e1 = (s[i] == aux[1]);
                    dp[i+1][j][l + e0] = max(dp[i+1][j][l + e0], dp[i][j][l] + (e1 ? l : 0));
                }
                if(j < k){
                    dp[i+1][j+1][l+1] = max(dp[i+1][j+1][l+1], dp[i][j][l]);
                    dp[i+1][j+1][l] = max(dp[i+1][j+1][l], dp[i][j][l] + l);
                }
            }
        }
    }
    for(int i = 0; i<=k; i++){
        for(int j=0; j<=n; j++){
            resposta = max(resposta, dp[n][i][j]);
        }
    }
    cout<<resposta;
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    solve();
    return 0;
}