#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define br '\n'

ll total = 0;
ll resposta = 5;
vector<vector<bool>> visitados;
vector<vector<int>> frente;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int r, c; 

void dfs(int a, int b){
    visitados[a][b] = true;
    for(int i = 0; i<4; i++){
        int x = dx[i] + b;
        int y = dy[i] + a;
        if(x >= 0 && y >= 0 && x < c && y < r && frente[y][x] == frente[a][b] && !visitados[y][x]){
            dfs(y, x);
        }
    }
    return;
}

void solve(){
    cin>>r>>c;
    frente = vector<vector<int>> (r, vector<int> (c));
    visitados = vector<vector<bool>> (r, vector<bool> (c,false));
    vector<vector<int>> esquerda (c, vector<int> (r));
    vector<vector<int>> direita (c, vector<int> (r));
    vector<vector<int>> verso (r, vector<int> (c));
    int quantidade;
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cin>>frente[i][j];
            verso[r-i-1][c-j-1] = frente[i][j];
            esquerda[j][r-1-i] = frente[i][j];
            direita[c-1-j][i] = frente[i][j];
        }
    }
    for(int i = 1; i<r; i++){
        for(int j = 0; j<c; j++){
            if(j == 0 && frente[i][j] > frente[i-1][j]) resposta++;
            else if(j != 0 && frente[i][j] > frente[i-1][j] && (frente[i][j-1] <= frente[i-1][j] || frente[i-1][j-1] >= frente[i][j-1] || frente[i-1][j-1] >= frente[i][j])){
                resposta++;
            }
        }
    }
    for(int i = 1; i<c; i++){
        for(int j = 0; j<r; j++){
            if(j == 0 && esquerda[i][j] > esquerda[i-1][j]) resposta++;
            else if(j != 0 && esquerda[i][j] > esquerda[i-1][j] && (esquerda[i][j-1] <= esquerda[i-1][j] || esquerda[i-1][j-1] >= esquerda[i][j-1] || esquerda[i-1][j-1] >= esquerda[i][j])){
                resposta++;
            }
        }
    }
    for(int i = 1; i<c; i++){
        for(int j = 0; j<r; j++){
            if(j == 0 && direita[i][j] > direita[i-1][j]) resposta++;
            else if(j != 0 && direita[i][j] > direita[i-1][j] && (direita[i][j-1] <= direita[i-1][j] || direita[i-1][j-1] >= direita[i][j-1] || direita[i-1][j-1] >= direita[i][j])){
                resposta++;
            }
        }
    }
    for(int i = 1; i<r; i++){
        for(int j = 0; j<c; j++){
            if(j == 0 && verso[i][j] > verso[i-1][j]) resposta++;
            else if(j != 0 && verso[i][j] > verso[i-1][j] && (verso[i][j-1] <= verso[i-1][j] || verso[i-1][j-1] >= verso[i][j-1] || verso[i-1][j-1] >= verso[i][j])){
                resposta++;
            }
        }
    }
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            if(!visitados[i][j]){
                resposta++;
                dfs(i, j);
            }
        }
    }
   cout<<resposta<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}