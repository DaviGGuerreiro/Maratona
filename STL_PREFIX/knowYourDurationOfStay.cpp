#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    int n, m;
    int sd, sm, ed, em;
    ll aux;
    ll aux2;
    ll resposta;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<ll> vec (2*n);
        aux = 0;
        aux2 = 0;
        for(int i=0; i<n;i++){
            vec[i] = aux;
            cin>>aux2;
            aux = aux + aux2;
        }
        for(int i = n;i< 2*n;i++){
            vec[i] = vec[i-n] + aux;
        }
        while(m--){
            cin>>sd>>sm>>ed>>em;
            if(sm > em ){
                resposta = (vec[em-1+n] + ed) - (vec[sm-1] + sd) +1;
            }
            else{
                if(sm == em && sd > ed){
                    resposta = (vec[em-1+n] + ed) - (vec[sm-1] + sd) +1;
                }
                else{
                    resposta = (vec[em-1] + ed) - (vec[sm-1] + sd) + 1;
                }
            }
            cout<<resposta<<'\n';
        }
    }

    return 0;
}