#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n; int g;
vector<pair<int,int>> valor;
vector<int> forca;
ll dp[31][1001];

ll resposta(int i, int j){
    if(i > 0 || j > n) return 0;
    dp[i][j] = resposta(i, j+1);
    if(i - valor[j].first >= 0)dp[i][j] = max(dp[i][j], resposta(i - valor[j].first, j+1) + valor[j].second);
    return dp[i][j];
}

void solve(){
    cin>>n;
    valor = vector<pair<int,int>> (n+1);
    memset(dp, 0, sizeof dp);
    for(int i = 1; i<=n; i++){
        cin>>valor[i].second>>valor[i].first;
    }
    sort(valor.begin(),valor.end());
    ll resultado = 0; ll aux;
    resposta(30,0);
    cout<<dp[30][0];
    cin>>g;
    for(int i = 1; i<=g; i++){
        cin>>aux;
    }
    //cout<<resultado<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}