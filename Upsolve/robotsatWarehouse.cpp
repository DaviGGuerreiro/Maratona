#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<char>> vec(n, vector<char> (m));
    vector<vector<bool>> visitados(n, vector<bool> (m,false));
    int numero = 0;
    pair<int,int> comeco = {-1,-1};
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>vec[i][j];
            if(vec[i][j] == '.'){numero++; if(comeco == make_pair(-1,-1)) comeco = {i,j};}
            
        }
    }
    queue<pair<int,int>> fila; fila.push(comeco);
    visitados[comeco.first][comeco.second] = true;
    pair<int,int> aux; int k = 1;
    while(!fila.empty()){
        aux = fila.front();
        fila.pop();
        for(int i = 0; i<4; i++){
            int x = aux.second + dx[i];
            int y = aux.first + dy[i];
            if(x >= 0 && y >= 0 && x < m && y < n && vec[y][x] != '#' && !visitados[y][x]){
                fila.push({y,x});
                visitados[y][x] = true;
                if(vec[y][x] == '.') k++;
            }
        }
    }
    if(k != numero){
        cout<<"Impossible"<<'\n';
        return;
    }
    visitados = vector<vector<bool>> (n, vector<bool> (m,false));
    fila.push(comeco);
    stack<pair<int,int>> interrogas;
    visitados[comeco.first][comeco.second] = true;
    while(!fila.empty()){
        aux = fila.front();
        fila.pop();
        for(int i = 0; i<4; i++){
            int x = aux.second + dx[i];
            int y = aux.first + dy[i];
            if(x >= 0 && y >= 0 && x < m && y < n && vec[y][x] != '#' && !visitados[y][x]){
                if(vec[y][x] != '?') fila.push({y,x});
                else interrogas.push({y,x});
                visitados[y][x] = true;
            }
        }
        if(fila.empty()){
            if(!interrogas.empty()){
                bool tf = true;
                aux = interrogas.top();
                interrogas.pop();
                for(int i = 0; i<4; i++){
                    int x = aux.second + dx[i];
                    int y = aux.first + dy[i];
                    if(x >= 0 && y >= 0 && x < m && y < n && vec[y][x] != '#' && !visitados[y][x]){
                        fila.push(aux); tf = false;
                        vec[aux.first][aux.second] = '.';
                        break;
                    }
                }
                if(tf){
                    cout<<"Ambiguous"<<'\n';
                    return;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j<m ;j++){
            if(vec[i][j] == '?') cout<<'#';
            else cout<<vec[i][j];
        }
        cout<<'\n';
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}