#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
vector<vector<char>> vec;
vector<vector<bool>> vis;
stack<pair<int,int>> pilha;
int total;

void dfs(){
    pair<int,int> aux;
    int k;
    while(!pilha.empty()){
        aux = pilha.top();
        pilha.pop();
        if(!vis[aux.first][aux.second]){
            vis[aux.first][aux.second] = true;
            if(vec[aux.first][aux.second] >= 48 && vec[aux.first][aux.second] <= 57){
                total += vec[aux.first][aux.second] - 48;
            }
            k = 0;
            for(int i = 0; i<4; i++){
                int x = aux.second + dx[i];
                int y = aux.first + dy[i];
                if(x >= 0 && y>=0 && x < m && y < n && vec[y][x] != '#' && !vis[y][x]){
                    pilha.push({y,x});
                    k++;
                    if(vec[y][x] == 'T'){
                        for(int j = 0; j < k; j++){
                            pilha.pop();
                        }
                        break;
                    }
                }
            }
        }
    }
    return;
}


void solve(){
    vec = vector<vector<char>> (n, vector<char> (m));
    vis = vector<vector<bool>> (n, vector<bool> (m,false));
    pair<int,int> inicio;
    total = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
            if(vec[i][j] == 'S') inicio = {i,j};
        }
    }
    pilha.push(inicio);
    dfs();
    cout<<total<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    while(cin>>n>>m){
        solve();
    }
    return 0;
}