#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

void solve(){
    ll n, m, c; cin>>n>>m>>c;
    ll a, b, w;
    vector<vector<pair<ll,ll>>> vec (n+1);
    vector<ll> grau (n+1, 0);
    for(int i = 0; i<m; i++){
        cin>>a>>b>>w;
        vec[a].push_back({b,w});
        grau[b]++;
    }
    queue<int>q;
    q.push(1);
    vector<int>ord;
    map<int,ll> preco; preco[1] = 1;
    ll aux;
    while(!q.empty()){
        int u = q.front(); q.pop();
        ord.push_back(u);
        for(auto v: vec[u]){
            grau[v.first]--;
            aux = v.second + preco[u];
            preco[v.first] += aux;
            if(preco[v.first] > c) continue;
            if(grau[v.first] == 0) q.push(v.first);
        }
    }
    int tam = ord.size();
    vector<vector<ll>> dp (tam + 1, vector<ll> (c+1,0));
    dp[0][0] = 1; ll total = 0;
    for(int i = 1; i <= tam; i++){
        for(int j = 0; j <= c; j ++){
            dp[i][j] = dp[i-1][j];
            if(j >= preco[ord[i-1]]){ 
                dp[i][j] = (dp[i][j] + dp[i][j - preco[ord[i-1]]]) % MOD;
                total = (total + dp[i][j-preco[ord[i-1]]]) % MOD;
            }
        }
    }
    cout<<total<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}