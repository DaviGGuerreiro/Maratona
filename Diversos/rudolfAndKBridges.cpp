#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, k, d;
vector<vector<int>> rio;
 
ll calc(int num){
    if(d >= m-2){
        return 2;
    }
    vector<ll> dp (m,0);
    dp[0] = 1;
    deque<int> pilha;
    pilha.push_back(0);
    for(int i=1;i<m;i++){
        if(!pilha.empty() && pilha.front() == i-d-2) pilha.pop_front();
 
        dp[i] = rio[num][i] + 1;
        dp[i] += dp[pilha.front()];
 
        while(!pilha.empty() && dp[pilha.back()] >= dp[i]){
            pilha.pop_back();
        } 
        pilha.push_back(i);
    }
    return dp[m-1];
}
 
void solve(){
    cin>>n>>m>>k>>d;
    rio = vector<vector<int>> (n, vector<int> (m)); 
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>rio[i][j];
        }
    }
    vector<ll> custo (n, 0);
    ll resposta = 1e18, aux = 0;
    for(int i = 0;i<n;i++){
        custo[i] = calc(i);
        aux += custo[i];
        if(i>=k-1){
            if(i >= k) aux -= custo[i-k];
            resposta = min(resposta,aux);
        }
    }
    cout<<resposta<<'\n';
    return;
}
 
 
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}