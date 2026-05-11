#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
int n, m, c;
vector<ll> precos;
vector<vector<ll>> dp;

ll resposta(int i, int j){
    if(i == n + 1 || j == 0) return 0;
    dp[i][j] = resposta(i + 1, j);
    if(precos[i] <= j)dp[i][j] = (dp[i][j] + resposta(i, j - precos[i]) + 1) % MOD;
    return dp[i][j];
}

void solve(){
    cin>>n>>m>>c;
    precos = vector<ll> (n+1, 0); precos[1] = 1;
    dp = vector<vector<ll>> (n+1, vector<ll> (c+1, 0));
    vector<vector<pair<ll,ll>>> vec (n+1);
    vector<int> grau (n+1, 0);
    int a, b, d;
    for(int i = 0; i<m; i++){
        cin>>a>>b>>d;
        vec[a].push_back({b,d});
        grau[b]++;
    }
    queue<int> edges; edges.push(1);
    int aux;
    while(!edges.empty()){
        aux = edges.front();
        edges.pop();
        for(auto it : vec[aux]){
            precos[it.first] += precos[aux] + it.second;
            if(precos[it.first] > c) precos[it.first] = c+1;
            grau[it.first]--;
            if(grau[it.first] == 0) edges.push(it.first);
        }
    }
    cout<<resposta(1,c)<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}