#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> pesos (m+1);
    vector<vector<ll>> ganho (m+1);
    int a, b, c;
    for(int i =0; i<n; i++){
        cin>>a>>b>>c;
        pesos[b].push_back(a);
        ganho[b].push_back(c);
    }
    vector<int> sapatos (m+1);
    for(int i =1; i<=m; i++){
        cin>>a>>b;
        sapatos[i] = min(a,b) * 2;
    }
    ll soma = 0;
    for(int i = 1; i <= m; i++){
        vector<ll> knapsack (sapatos[i] + 1, 0);
        for(int j = 0; j < (int)pesos[i].size(); j++){
            for(ll k = sapatos[i] - pesos[i][j]; k >= 0; k--){
                knapsack[k + pesos[i][j]] = max(knapsack[k + pesos[i][j]], knapsack[k] + ganho[i][j]);
            }
        }
        soma += knapsack[sapatos[i]];
    }
    cout<<soma<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}