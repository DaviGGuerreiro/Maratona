#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<char>> vec;
vector<vector<int>> dist;
queue<pair<int,int>> fila;
vector<double> v;
int quantidade = 0;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,-1,1};

void bfs(){
    while(!fila.empty()){
        auto aux = fila.front();
        fila.pop();
        for(int i=0;i<4;i++){
            int x = aux.second + dx[i];
            int y = aux.first + dy[i];
            if(x>=0 && x<n && y>=0 && y<n && vec[y][x] == '.' && dist[y][x] == 0){
                fila.push({y,x});
                dist[y][x] = dist[aux.first][aux.second] + 1;
                v[dist[y][x]]++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cout<<fixed<<setprecision(8);
    int q;
    cin>>n>>q;
    vec = vector<vector<char>> (n, vector<char> (n));
    dist = vector<vector<int>> (n, vector<int> (n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];
            if(vec[i][j] == '.'){
                quantidade++;
            }
            else if(vec[i][j] == 'E'){
                fila.push({i,j});
                dist[i][j] = 1;
            }
        }
    }
    v = vector<double> ((n*n)+1);
    bfs();
    for(int i=1;i<=n*n;i++){
        v[i] = v[i] + v[i-1];
    }
    int x;
    double y;
    for(int i=0;i<q;i++){
        cin>>x;
        y = v[x]/quantidade;
        cout<<y<<'\n';
    }
    return 0;
}