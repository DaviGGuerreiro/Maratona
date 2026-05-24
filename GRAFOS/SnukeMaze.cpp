#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int h, w; 
vector<vector<char>> vec;
vector<vector<bool>> visitados;
map<char, int> mapa;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
bool dfs(pair<int,int> pai){
    visitados[pai.first][pai.second] = true;
    for(int i = 0; i<4; i++){
        int x = dx[i] + pai.second;
        int y = dy[i] + pai.first;
        if(x >=0 && y>=0 && x < w && y < h && !visitados[y][x] &&(((mapa[vec[pai.first][pai.second]] % 5) + 1) == mapa[vec[y][x]])){
            if(y == h-1 && x == w-1) return true;
            if(dfs({y,x})) return true;
        }
    }
    return false;
}

void solve(){
    cin>>h>>w;
    vec = vector<vector<char>> (h, vector<char> (w));
    visitados = vector<vector<bool>> (h, vector<bool> (w,false));
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            cin>>vec[i][j];
        }
    }
    mapa['s'] = 1;
    mapa['n'] = 2;
    mapa['u'] = 3;
    mapa['k'] = 4;
    mapa['e'] = 5;
    if(vec[0][0] == 's'){
        bool resposta = dfs({0,0});
        if(resposta) cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }
    else{
        cout<<"No"<<'\n';
        return;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}