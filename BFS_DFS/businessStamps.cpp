#include<bits/stdc++.h>
using namespace std;

int r = 11;
int n, m, z;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
pair<int,int> fim;
pair<int,int> inicio;

bool bfs(vector<vector<int>>& vec, vector<vector<int>>& vis, vector<int>& carteira){
    queue<pair<int,int>> fila;
    if(carteira[vec[inicio.first][inicio.second]-1] == 0 || carteira[vec[fim.first][fim.second]-1] == 0){
        return false;
    }
    else if(inicio == fim){
        return true;
    }
    vis[inicio.first][inicio.second] = z;
    fila.push(inicio);
    pair<int,int> aux;
    while(!fila.empty()){
        aux = fila.front();
        fila.pop();
        for(int i=0;i<4;i++){
            int y = aux.first + dy[i]; 
            int x = aux.second + dx[i];
            if(x >=1 && x<=m && y>= 1 && y <= n){
                if(vis[y][x] != z && (carteira[vec[y][x]-1] == 1)){
                    fila.push({y,x});
                    vis[y][x] = z;
                    if(y == fim.first && x == fim.second){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    vector<vector<int>> vec (n+1, vector<int> (m+1));
    vector<vector<int>> visitados (n+1, vector<int> (m+1, -1));
    vector<int> carteira (10);
    cin>>inicio.first>>inicio.second;
    cin>>fim.first>>fim.second;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>vec[i][j];
        }
    }
    bool b = false;
    int q;
    for(z=1;z<1024;z++){
        q = 0;
        for(int j = 0;j<10;j++){
            if(z & (1<<j)){
                q++;
                carteira[j] = 1;
            }
            else{
                carteira[j] = 0;
            }
        }
        if(r>q){
            b = bfs(vec, visitados, carteira);
        }
        if(b){
            int resposta = 0;
            for(int i=0;i<10;i++){
                if(carteira[i] == 1){
                    resposta++;
                }
            }
            if(resposta < r){
                r = resposta;
            }
        }
    }

    cout<<r;
    return 0;
}