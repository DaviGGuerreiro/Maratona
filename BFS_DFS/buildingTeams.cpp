#include<bits/stdc++.h>
using namespace std;

stack<int> pilha;
int n, m;

bool dfs(int v, vector<vector<int>>& vec, vector<bool>& visitados, vector<bool>& cor){
    cor[v] = false;
    bool b = true;
    pilha.push(v);
    while(!pilha.empty()){
        int aux = pilha.top();
        visitados[aux] = true;
        pilha.pop();
        for(int x: vec[aux]){
            if(visitados[x] == false){
                pilha.push(x);
                cor[x] = !cor[aux];
            }
            else if(cor[x] == cor[aux]){
                b = false;
                break;
            }
        }
        if(!b){
            break;
        }
    }
    return b;
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int l, r;
    cin>>n>>m;
    vector<vector<int>> vec(n+1);
    vector<bool> visitados (n+1, false);
    vector<bool> cor (n+1);
    for(int i=0;i<m;i++){
        cin>>l>>r;
        vec[l].push_back(r);
        vec[r].push_back(l);
    }
    bool b = true;
    for(int i=1;i<=n;i++){
        if(visitados[i] == false){
            b = dfs(i, vec, visitados, cor);
            if(!b){
                break;
            }
        } 
    }
    if(b){
        for(int i=1;i<=n;i++){
            if(cor[i]){
                cout<<2;
            } else{
                cout<<1;
            }
            cout<<" ";
        }
    } else{
        cout<<"IMPOSSIBLE";
    }

    return 0;
}