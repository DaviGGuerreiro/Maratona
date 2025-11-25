#include<bits/stdc++.h>
using namespace std;
queue<int> fila;
bool d;
bool dfs(int v,vector<vector<int>>& vec, vector<int>& vis, int ant, int indice){ 
    vis[v] = true;
    for(int x : vec[v]){
        if(!vis[x]){
            if(dfs(x,vec,vis,v, indice+1)){
                if(d){
                    if(v == fila.front()){
                        d = false;
                    }
                    fila.push(v);
                }
                return true;
            }
        }
        else{
            if(x != ant){
                fila.push(x);
                fila.push(v);
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, m, l, r;
    d = true;
    cin>>n>>m;
    vector<vector<int>> vec (n+1);
    vector<int> vis (n+1, false);
    for(int i=0;i<m;i++){
        cin>>l>>r;
        if(l != r){
            vec[l].push_back(r);
            vec[r].push_back(l); 
        }
    }
    for(int i=1;i<=n;i++){
        sort(vec[i].begin(),vec[i].end());
        vec[i].erase(unique(vec[i].begin(),vec[i].end()), vec[i].end());
    }
    bool b = false;
    for(int i = 1; i<=n;i++){
        if(!vis[i]){
            int ant = 0;
            b = dfs(i,vec,vis,ant, 1);
        }
        if(b){
            break;
        }
    }
    if(!b){
        cout<<"IMPOSSIBLE";
    }
    else{
        int tamanho = fila.size();
        cout<<tamanho<<'\n';
        while(tamanho--){
            cout<<fila.front()<<" ";
            fila.pop();
        }
    }

    return 0;
}