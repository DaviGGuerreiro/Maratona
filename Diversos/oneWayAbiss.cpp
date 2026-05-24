#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m; cin>>n>>m;
    vector<ll> vec (n+1,0);
    int a, b, c;
    ll aux;
    for(int i = 0; i<m; i++){
        cin>>a>>b>>c;
        aux = vec[a];
        vec[a] = vec[b] + c;
        vec[b] = aux + c;
    }
    ll maximo = 0;
    for(int i = 1; i<=n;i++){
        maximo = max(maximo, vec[i]);
    }
    cout<<maximo<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--){
       solve(); 
    }
    return 0;
}