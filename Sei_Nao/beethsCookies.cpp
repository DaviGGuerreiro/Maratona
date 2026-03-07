#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    int l = 0, r = 1;
    int entrada = 1;
    stack<pair<int,int>> mult;
    int soma = 0;
    bool b = false;
    for(int i = 0;i<s.size()-1;i++){
        if(s[l] == '(' && s[r] == ')'){
            entrada--;
            b = true;
        }
        else if(s[l] == ')' && s[r] == '('){
            mult.push({soma,entrada});
            entrada++;
            b = false;
        }
        else if(s[l] == ')' && s[r] == ')'){
            soma++;
            if(b){
                soma++;
                b = false;
            }
            entrada--;
            if(mult.top().second == entrada){
                mult.top().first *= soma;
            }
        }
        else{
            entrada++;
        }
        l++;r++;
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}

