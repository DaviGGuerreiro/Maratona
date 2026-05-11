#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    int resposta = 0;
    char ultimo = ' ';
    for(int i= 0; i<n ;i++){
        if(s[i] == 'C'){
            resposta++;
            ultimo = 'C';
        }
        else if(s[i] == 'E'){
            if(ultimo == 'E' || ultimo == 'C' || ultimo == ' '){
                resposta++;
                ultimo = 'E';
            }
            else{
                ultimo = 'C';
            }
        }
        else{
            if(ultimo == 'D' || ultimo == 'C' || ultimo == ' '){
                resposta++;
                ultimo = 'D';
            }
            else{
                ultimo = 'C';
            }
        }
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}