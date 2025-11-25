#include<bits/stdc++.h>
using namespace std;
int n,m,bom;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool valid(pair<int,int> p, vector<vector<char>>& v){
    if(p.first >= 0 && p.first < m && p.second >= 0 && p.second < n){
        for(int i=0;i<4;i++){
            int ax = p.first + dx[i]; int ay = p.second + dy[i];
            if(ax >= 0 && ax < m && ay >= 0 && ay < n && v[ay][ax] == 'B'){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

int bfs(pair<int,int> comeco, vector<vector<char>>& v, vector<vector<bool>>& vis){
    vis[n-1][m-1] = true;
    queue<pair<int,int>> fila;
    fila.push(comeco);
    pair<int, int> coord;
    int comp = 0;
    if(v[n-1][m-1] == 'B'){
        return -1;
    }
    else if(v[n-1][m-1] == '#'){
        return 0;
    }
    else if(v[n-1][m-1] == 'G'){
        comp++;
    }

    if(!valid({m-1,n-1},v)){
        return comp;
    }
    
    while(!fila.empty()){
        coord = fila.front();
        fila.pop();
        for(int i = 0; i < 4; i++){
            int ax = coord.second + dx[i];
            int ay = coord.first + dy[i];
            if(valid({ax,ay}, v) && !vis[ay][ax] && v[ay][ax] != '#'){
                if(v[ay][ax] == 'G'){
                    fila.push({ay,ax});
                    vis[ay][ax] = true;
                    comp++;
                }
                else if(v[ay][ax] == '.'){
                    fila.push({ay,ax});
                    vis[ay][ax] = true;
                }
            }

        }
    }
    return comp;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<char>> vec (n, vector<char> (m));
        vector<vector<bool>> vis (n, vector<bool> (m,false));
        bom = 0;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>vec[i][j];
                if(vec[i][j] == 'G'){ bom++; }
            }
        }
        if(bfs({n-1,m-1},vec,vis) != bom){
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
        }
    }

    return 0;
}