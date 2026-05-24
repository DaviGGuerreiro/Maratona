#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, d;
int m1, m2;
vector<vector<int>> vec;
vector<int> a;
vector<int> b;
//variaveis possiveis: passos dados, distancia atual, casa atual de a, casa atual de b,
//onde a dfs entra na historia? dfs na raiz - distancias de toda a arvoreasd
vector<vector<int>> dp;

void solve(){
    
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>d;
    vec = vector<vector<int>> (n+1);
    int aux1, aux2;
    for(int i = 0;i<n-1;i++){
        cin>>aux1>>aux2;
        vec[aux1].push_back(aux2);
        vec[aux2].push_back(aux1);
    }
    cin>>m1;
    a = vector<int> (m1);
    for(int i = 0; i<m1; i++){
        cin>>a[i];
    }
    cin>>m2;
    b = vector<int> (m2);
    for(int i = 0; i<m2; i++){
        cin>>b[i];
    }
    solve();
    return 0;
}