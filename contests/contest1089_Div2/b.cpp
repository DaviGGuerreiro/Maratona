#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> vec;
vector<bool> marcados;

void solve(){
    cin>>n;
    vec = vector<int> (n+1);
    marcados = vector<bool> (n+1,false);
    int quantidade = 0;
    int maximo = 0;
    for(int i = 1; i<=n; i++){
        cin>>vec[i];
    }
    for(int i = 1; i<=n; i++){
        if(!marcados[i]){
            quantidade++;
            maximo = max(maximo, quantidade);
            marcados[vec[i]] = true;
        }
        else{
            marcados[vec[i]] = true;
        }
    }
    cout<<maximo;
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}