#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
map<pair<int,int>, int> mapa;
void dfs(int begin, vector<vector<int>>& v, vector<int>& visit, bool cor){
    visit[begin] = cor;
    for(auto x : v[begin]){
        if(visit[x] == -1){
            if(mapa[{begin, x}]%2 == 0){
                dfs(x,v,visit, cor);
            }
            else{
                dfs(x,v,visit, !cor);
            }  
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    vector<vector<int>> vec (n+1); 
    vector<int> visit (n+1,-1);
    int a,b,c;
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        if(a!=b){
            vec[a].push_back(b);
            vec[b].push_back(a);
            mapa[{a,b}] = c;
            mapa[{b,a}] = c;
        }
    }
    dfs(1,vec, visit, 0);
    for(int i=1;i<=n;i++){
        cout<<visit[i]<<'\n';
    }
    return 0;
}