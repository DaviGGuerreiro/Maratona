#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;

void solve(){
    int n, m; cin>>n>>m;
    vector<ll> escalar (n+1); vector<ll> q (m+1);
    vector<ll> resposta (n * m + 1, 0);
    vector<ll> aux = {1};
    for(int i = 0; i<=n; i++){
        cin>>escalar[i];
    }
    for(int i = 0; i<=m; i++){
        cin>>q[i];
    }
    ll mul; ll x;
    resposta[0] = escalar[0];
    for(int i = 1; i<=n; i++){
        mul = escalar[i];
        vector<ll> local(m * i + 1, 0);
        for(int j = 0; j <= (i-1) * m; j ++){
            for(int k = 0; k <= m; k ++){
                x = (aux[j] % MOD * q[k] % MOD) % MOD;
                local[j + k] = (local[j + k] + x) % MOD;
            }
        }
        swap(aux,local);
        for(int j = 0; j < m * i + 1; j++){
            x = (aux[j] % MOD * mul % MOD) % MOD;
            resposta[j] = (resposta[j] + x) % MOD;
        }
    }
    for(auto it : resposta){
        cout<<it<<' ';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}