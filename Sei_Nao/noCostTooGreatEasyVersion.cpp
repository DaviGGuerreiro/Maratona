#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> primos (2e5 +3);
vector<bool> visitados (2e5 + 3, false);

void sieve(){
    for(int i = 2; i<=2e5+2; i++){
        if(visitados[i]) continue;
        visitados[i] = true;
        for(int j = i; j<=2e5+2; j+=i){
            visitados[j] = true;
            primos[j].push_back(i);
        }
    }
    return;
}

void solve(){
    int n, aux; cin>>n;
    int pares = 0;
    vector<int> vec (n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
        if(vec[i]%2 == 0) pares++;
    }
    for(int i=0;i<n;i++) cin>>aux;
    if(pares >= 2){ cout<<0<<'\n'; return;}
    set<int> conjunto;
    set<int> conjuntoPlus;
    for(int i = 0; i<n; i++){
        for(auto it : primos[vec[i]]){
            if(conjunto.find(it) != conjunto.end()){
                cout<<0<<'\n'; return;
            }
            else{
                conjunto.insert(it);
            }
        }
        for(auto it : primos[vec[i]+1]){
            conjuntoPlus.insert(it);
        }
    }
    for(auto it : conjuntoPlus){
        if(conjunto.find(it) != conjunto.end()){
            cout<<1<<'\n'; return;
        }
    }
    cout<<2<<'\n'; return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    sieve();
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}