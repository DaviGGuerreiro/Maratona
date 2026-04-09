#include<bits/stdc++.h>
using namespace std;    

const int MAX_VAL = 1e6 + 1;
bool LOCAL[MAX_VAL];
bool GLOBAL[MAX_VAL];

void solve(){
    int n; cin>>n; int l;
    vector<vector<int>> vec (n);
    for(int i = 0; i<n ; i++){
        cin>>l;
        vector<int> temp (l);
        for(int j = l-1; j>=0; j--){
            cin>>temp[j];
        }
        for(int j = 0; j < l ; j++){
            if(!LOCAL[temp[j]]){vec[i].push_back(temp[j]); LOCAL[temp[j]] = true;}
        }
        for(auto it : vec[i]) LOCAL[it] = false;
    }

    queue<int> resposta;
    vector<bool> ativo (n, true);
    for(int i = 0; i<n; i++){
        vector<int> atual;
        bool achou = false;
        for(int j = 0; j<n; j++){
            if(!ativo[j]) continue;
            vector<int> teste;
            for(auto it : vec[j]){
                if(!GLOBAL[it]){
                    teste.push_back(it);
                }
            }
            if(!teste.empty()){
                if(!achou || atual > teste){
                    swap(atual,teste);
                    achou = true;
                }
            }
            else ativo[j] = false;
        }
        if(atual.empty()) break;
        for(auto it : atual){
            GLOBAL[it] = true;
            resposta.push(it);
        }
    }
    int x;
    while(!resposta.empty()){
        x = resposta.front();
        cout<<x<<' '; resposta.pop();
        GLOBAL[x] = false;
    }
    cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}   