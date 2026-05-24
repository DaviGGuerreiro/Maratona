#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> vec;
vector<bool> visitados;
int y; int maxima = -1;

void dfs(int x, int dist){
    visitados[x] = true;
    if(dist > maxima){
        maxima = dist;
        y = x;
    }
    for(auto it : vec[x]){
        if(!visitados[it]){
            dfs(it,dist + 1);
        }
    }
}

void solve(){
    int n; cin>>n;
    int a, b;
    vec = vector<vector<int>> (n+1);
    visitados = vector<bool> (n+1, false);
    for(int i = 0; i<n-1;i++){
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(1, 0);
    int x = y;
    y = 0; maxima = -1;
    for(auto it : visitados) it = false;
    dfs(x, 0);
    cout<<maxima<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}