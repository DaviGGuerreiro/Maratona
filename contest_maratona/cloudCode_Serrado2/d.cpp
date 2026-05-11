#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    int q; cin>>q;
    string s; cin>>s;
    string aux; ll maior;
    for(int i = 0; i<q; i++){
        cin>>aux; maior = 0; int tamanho = (int)aux.size();
        for(int i = 0; i < (int)aux.size(); i++){
            if(aux[i] == s[0]){
                tamanho--;
            }
            else{
                break;
            }
        }
        maior = s.size() + tamanho;
        tamanho = s.size();
        for(int i = 0; i < (int)aux.size(); i++){
            if(s[i] == aux[0]){
                tamanho--;
            }
            else{
                break;
            }
        }
        maior = max(maior, (ll)aux.size() + tamanho);
        cout<<maior<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}