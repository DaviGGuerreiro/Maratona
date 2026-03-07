#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
const int modulo = 1e9 + 7;
vector<vector<int>> caminhos;
vector<vector<int>> dp;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    caminhos = vector<vector<int>> (n, vector<int> (n,0));
    dp = vector<vector<int>> (1<<n, vector<int> (n,0));
    int a ,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        caminhos[a-1][b-1]++;
    }
    dp[1][0] = 1;
    ll aux;
    for(int i = 1; i<(1<<n);i++){
        for(int j = 0 ; j<n; j++){
            if(dp[i][j]==0) continue;
            for(int v = 1; v<n; v++){
                if(caminhos[j][v] > 0 && !(i & (1<<v))){
                    int prox = i | (1<<v);
                    if(v == n-1 && prox != ((1<<n)-1)){
                        continue;
                    }
                    aux = (1LL * dp[i][j] * caminhos[j][v])%modulo;   
                    dp[prox][v] = (dp[prox][v] + aux)%modulo;
                }
            }
        }
    }
    cout<<dp[(1<<n)-1][n-1];
    return 0;
}