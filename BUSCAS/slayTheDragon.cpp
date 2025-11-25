#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll Search(vector<ll> &str,ll soma, ll defesa, ll ataque){
    ll moedas = 0;
    auto query = lower_bound(str.begin(), str.end(), defesa);
    if(query == str.end()){
        query--;
        moedas = defesa - *query;
        if(ataque > soma-*query){
            moedas = moedas + ataque - soma + *query;
        }
    } 
    else{
        ll val1, val2;
        val1 = ataque - soma + *query;
        if(query != str.begin()){
            query--;
            if(ataque - soma + *query >= 0){
                val2 = ataque + defesa - soma;
            }
            else{
                val2 = defesa - *query;
            }
            if(val1 > val2){
                moedas = val2;
            } else{
                moedas = val1;
            }
        }
        else{
            moedas = val1;
        }
    }
    if(moedas<0){
        moedas = 0;
    }
    return moedas;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int i;
    int h;
    cin>>h;
    vector<ll> str (h);
    ll soma = 0;
    ll moedas;
    for(i=0;i<h;i++){
        cin>>str[i];
        soma = soma + str[i];
    }
    sort(str.begin(), str.end());
    int d;
    cin>>d;
    ll defesa, ataque;
    for(i=0;i<d;i++){
        cin>>defesa>>ataque;
        moedas = Search(str, soma, defesa, ataque);
        cout<<moedas<<'\n';
    }
    return 0;
}