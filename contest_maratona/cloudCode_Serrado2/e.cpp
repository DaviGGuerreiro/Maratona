#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> primos;
vector<bool> prime;

void crivo(){
    prime[0] = prime[1] = false;
    for(ll i = 2; i * i < 1e7; i++){
        if(prime[i]){
            primos.push_back(i);
            for(ll j = i + i; j * j < 1e7; j+=i){
                prime[j] = false;
            }
        }
    }
}

void solve(){
    int n; cin>>n;
    map<ll, ll> mapa;
    ll aux;    
    for(int i = 0; i<n; i++){
        cin>>aux;
        int j = 0;
        while(aux != 1 && j < (int)primos.size()){
            if(aux % primos[j] == 0){
                mapa[primos[j]]++;
                aux /= primos[j];
            }
            else{
                j++;
            }   
        }
        if(aux != 1){
            mapa[aux]++;
        }
    }
    vector<ll> resposta;
    for(auto [k, v] : mapa){
        if(v != 0){
            resposta.push_back(k * v);
        }
    }
    sort(resposta.begin(),resposta.end());
    ll valor = 0;
    for(int i = resposta.size()-1; i>=0; i -= 2){
        valor += resposta[i];
    }
    cout<<valor<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    prime = vector<bool> (1e7 +1, true);
    crivo();
    solve();
    return 0;
}