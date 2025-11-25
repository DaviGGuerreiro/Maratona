#include<bits/stdc++.h>
using namespace std;
int n;
int tamanho;
int bfs(int z, vector<vector<int>>& v){
    vector<int> visitados (n+1,-1);
    visitados[0] = 0;
    visitados[z] = 0;
    queue<int> fila;
    fila.push(z);
    int aux;
    while(!fila.empty()){
        aux = fila.front();
        fila.pop();
        for(int x : v[aux]){
            if(visitados[x] == -1){
                fila.push(x);
                visitados[x] = visitados[aux] + 1;
                if(visitados[x] > tamanho){
                    tamanho = visitados[x];
                }
            }
        }
    }
    bool resposta = true;
    for(int b : visitados){
        if(b == -1){
            resposta = false;
            break;
        }
    }
    if(resposta){
        return aux;
    }
    else{
        return -1;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int m;
    cin>>n>>m;
    int a, b;
    vector<vector<int>> vec  (n+1);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    tamanho = 0;
    int m1 = bfs(1,vec);
    if(m1 == -1){
        cout<<"=[";
    }
    else{
        for(int i = 2;i<=n;i++){
            m1 = bfs(i,vec);
        }
        cout<<"=] "<<tamanho;
    }


    return 0;
}