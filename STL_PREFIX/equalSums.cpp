#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int k;
    cin>>k;
    int n;
    bool v = false;
    map<int, pair<int,int>> mapa;
    for(int i=1;i<=k;i++){
        cin>>n;
        int aux, soma = 0;
        map<int,int> index;
        set<pair<int, int>> conjunto;
        for(int j=0;j<n;j++){
            cin>>aux;
            soma = soma + aux;
            if(!v && index[aux] == 0){
                index[aux] = 1;
                conjunto.insert({j+1, aux});
            }
        }
        if(!v){
            for(auto [a,b]: conjunto){
                if(mapa.find(soma-b) != mapa.end()){
                    v = true;
                    cout<<"YES"<<'\n';
                    cout<<i<<' '<<a<<'\n';
                    cout<<mapa[soma-b].second<<' '<<mapa[soma-b].first;
                    break;
                }
                else{
                    mapa[soma-b] = {a,i};
                }
            }
        }
    }
    if(v == false){
        cout<<"NO";
    }

    return 0;
}