#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s; cin>>s; int n = (int)s.size();
    string t; cin>>t;
    vector<int> peso (n);
    for(int i = 0; i < n; i++){
        cin>>peso[i];
    }
    ll resposta = 0;
    int periodo_s;
    string teste = s + s;
    for(int i = 1; i*i <= (int)teste.size(); i++){
        if(teste.size() % (i) == 0){
            int j = 0;
            bool b = true;
            while(j < (int)teste.size()){
                
            }
            if(b){
                periodo_s = i;
                break;
            }
        }
    }
    

}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}