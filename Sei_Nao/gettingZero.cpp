#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 32768;

void solve(){
    int n; cin>>n;
    int aux;
    int quantidade;
    int resposta;
    int x;
    for(int i = 0; i<n; i++){
        cin>>aux;
        if(aux == 0){
            cout<<0<<' ';
            continue;
        }
        resposta = 1e9;
        for(int j = 0; j <= 15; j++){
            x = aux + j; quantidade = 0;
            while(x % 2 == 0){
                x /= 2;
                quantidade++;
            }
            resposta = min(resposta, j + (15 - quantidade));
        }
        cout<<resposta<<' ';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}