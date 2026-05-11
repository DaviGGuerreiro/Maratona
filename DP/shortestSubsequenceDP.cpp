#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s; cin>>s; int n = (int)s.size();
    string resposta;
    vector<vector<int>> nextp (s.size(), vector<int> (4));
    int a = 1e9, c = 1e9, g = 1e9, t = 1e9;
    for(int i = n - 1; i >= 0;i--){
        if(s[i] == 'A') a = i;
        else if(s[i] == 'C') c = i;
        else if(s[i] == 'G') g = i;
        else if(s[i] == 'T') t = i;
        nextp[i][0] = a - i;
        nextp[i][1] = c - i;
        nextp[i][2] = g - i;
        nextp[i][3] = t - i;
    }
    int novo;
    char letra;
    char x;
    int i = 0;
    while(i < n){
        novo = 0;
        for(int j = 0; j < 4; j ++){
            if(j == 0) letra = 'A';
            else if(j == 1) letra = 'C';
            else if(j == 2) letra = 'G';
            else if(j == 3) letra = 'T';
            if(nextp[i][j] > 1e7){
                i = n;
                resposta.push_back(letra);
                break;
            }
            if(novo < nextp[i][j]){
                novo = nextp[i][j];
                x = letra;
            }
        }
        if(i != n){
            resposta.push_back(x);
            i += novo;
        }
    }

    for(auto it: resposta){
        cout<<it;
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}