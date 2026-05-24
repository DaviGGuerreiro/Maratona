#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> grid;
const int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

void bfs(){
    queue<pair<int,int>> fila; fila.push({1,1});;
    while(!fila.empty()){
        auto aux = fila.front(); fila.pop();
        for(int i = 0; i < 8; i++){
            int y = aux.first + dy[i];
            int x = aux.second + dx[i];
            if(y == 1 && x == 1) continue;
            if(x >= 1 && y >=1 && x<=n && y<=n && grid[y][x] == 0){
                grid[y][x] = grid[aux.first][aux.second] + 1;
                fila.push({y,x});
            }
        }
    }
}

void solve(){
    cin>>n;
    grid = vector<vector<int>> (n+1, vector<int> (n+1,0));
    bfs();
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cout<<grid[i][j]<<' ';
        }
        cout<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}