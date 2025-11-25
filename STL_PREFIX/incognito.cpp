#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t,n;
    string aux;
    cin>>t;
    while(t--){
        cin>>n;
        map<string,ll> mapa;
        set<string> conjunto;
        while(n--){
            cin>>aux;
            cin>>aux;
            mapa[aux]++;
            if(conjunto.find(aux) == conjunto.end()){
                conjunto.insert(aux);
                mapa[aux]++;
            }
        }
        ll m = 1;
        for(string str : conjunto){
            m = m * mapa[str];
        }
        cout<<m-1<<'\n';
    }
    return 0;
}