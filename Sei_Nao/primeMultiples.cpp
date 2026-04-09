#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    ll n, k; cin>>n>>k;
    vector<ll> vec (k);
    ll resposta = 0;
    for(int i = 0; i<k; i++){
        cin>>vec[i];
        resposta += n/vec[i];
    }
    int quantidade = 0;
    ll aux;
    ld x;
    bool flg;
    int posicao;
    for(ll mask = 1; mask < (1<<k); mask++){
        quantidade = __builtin_popcount(mask);
        if(quantidade > 1){
            aux = 1; posicao = 0; x = 0.0; flg = false;
            while(mask >= (1<<posicao)){
                if(mask & (1<<posicao)){
                    x += log10(vec[posicao]);
                    if(x > log10(n)){
                        flg = true;
                        break;
                    }
                    aux *= vec[posicao];
                }
                posicao++;
            }

            if(flg) continue;

            if(quantidade%2 == 0){
                resposta -= n/aux;
            }
            else{
                resposta += n/aux;
            }
        }
    }
    cout<<resposta;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}