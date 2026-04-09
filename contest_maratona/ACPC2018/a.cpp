#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

vector<vector<int>> vec;
vector<bool> visitados;
stack<int> pilha;
int n, l, r;
int verde = 0;

void dfs(int x, int distancia){
    visitados[x] = true; int y;
    pilha.push(distancia);
    if(distancia >= l)
    for(auto it : vec[x]){
        if(!visitados[it]){
            dfs(it, distancia + 1);
        }
    }
    return;
}

void solve(){
    cin>>n>>l>>r; verde = 0;
    vec = vector<vector<int>> (n+1);
    visitados = vector<bool> (n+1,false);
    int a, b;
    for(int i = 0; i < n-1; i++){
        cin>>a>>b;
        vec[a].push_back(b); vec[b].push_back(a);
    }
    dfs(1, 0);
    cout<<verde<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    //freopen("awesome.in","r",stdin);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}