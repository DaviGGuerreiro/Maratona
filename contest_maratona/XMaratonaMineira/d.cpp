#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    vector<int> vec (n);
    ll soma = 0;
    int pos = 0;
    for(int i = 0; i<n-1; i++){
        cin>>vec[i];
        soma += vec[i];
    }
    pos = soma % n;
    vector<int> resposta (n, -1);
    int limite = min(20, n);
    for(int i = 0; i<= limite; i ++){
        if(resposta[(pos + i) % n] == -1) resposta[(pos + i) % n] = i;
    }
    for(auto it : resposta){
        cout<<it<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}