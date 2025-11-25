#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    int i;
    ll aux;
    ll soma = 0;

    map<int, ll> mapa;
    vector<int> vec (n);
    for(i=0;i<n;i++){
        cin>>vec[i];
    }
    for(i=0;i<n;i++){
        cin>>aux;
        soma = soma + aux;
        mapa[vec[i]] = soma;
    }
    int q;
    cin>>q;
    int l, r;
    ll resposta;
    while(q--){
        cin>>l>>r;
        auto it = lower_bound(vec.begin(), vec.end(), l);
        auto et = upper_bound(vec.begin(), vec.end(), r);
        if(it == vec.begin()){
            if(et == vec.begin()){
                resposta = 0;
            }
            else{
                --et;
                resposta = mapa[*et];
            }
        }
        else{
            --et;
            --it;
            resposta = mapa[*et] - mapa[*it];
        }
        cout<<resposta<<'\n';
    }

    return 0;
}