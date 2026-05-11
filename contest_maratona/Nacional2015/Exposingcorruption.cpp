#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, l, v;
vector<int> primeiro;
vector<int> segundo;
vector<bool> visitados;
vector<vector<int>> vec;
vector<int> dp;

int q1;
int q2;
int p;

void dfs(int x){
    visitados[x] = true;
    if(x<=n){p += primeiro[x]; q1++;}
    else{p += segundo[x-n]; q2++;}
    for(auto it : vec[x]){
        if(!visitados[it]){
            dfs(it);
        }
    }
}

void solve(){
    cin>>n>>m>>l>>v; int a, b;
    primeiro =  vector<int> (n+1);
    segundo = vector<int> (m+1);
    vec = vector<vector<int>> (n+1+m);
    visitados = vector<bool> (n+1+m,false);
    for(int i = 1; i <= n; i++){
        cin>>primeiro[i];
    }
    for(int i = 1; i <= m; i++){
        cin>>segundo[i];
    }
    for(int i = 0; i<l; i++){
        cin>>a>>b;
        vec[a].push_back(b+n);
        vec[b + n].push_back(a);
    }
    vector<int> valor1;
    vector<int> valor2;
    vector<int> peso;
    for(int i = 1; i<=n+m; i++){
        if(!visitados[i]){
            p = 0; q1 = 0; q2 = 0;
            dfs(i);
            valor1.push_back(q2 - q1);
            valor2.push_back(q1 - q2);
            peso.push_back(p);
        }
    }
    int r1, r2;
    int tamanho = (int)peso.size();
    dp = vector<int> (v + 1,0);
    for(int i = 0; i < tamanho; i++){
        for(int j = v; j >= peso[i]; j--){
            dp[j] = max(dp[j], dp[j - peso[i]] + valor1[i]);
        }
    }
    r1 = dp[v] + n;
    dp = vector<int> (v + 1,0);
    for(int i = 0; i < tamanho; i++){
        for(int j = v; j >= peso[i]; j--){
            dp[j] = max(dp[j], dp[j - peso[i]] + valor2[i]);
        }
    }
    r2 = dp[v] + m;
    cout<<r1<<' '<<r2<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}