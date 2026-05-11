#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s; cin>>s;
    bool a = false, c = false, t = false, g = false;
    string resposta;
    for(int i = 0; i< (int)s.size(); i++){
        if(s[i] == 'A') a = true;
        else if(s[i] == 'C') c = true;
        else if(s[i] == 'G') g = true;
        else if(s[i] == 'T') t = true;

        if(a && c && g && t){
            resposta.push_back(s[i]);
            a = false; c = false; g = false; t = false;
        }
    }
    if(!a) resposta.push_back('A');
    else if(!c) resposta.push_back('C');
    else if(!g) resposta.push_back('G');
    else if(!t) resposta.push_back('T');

    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}