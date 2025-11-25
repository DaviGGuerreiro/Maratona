#include<bits/stdc++.h>
using namespace std;
bool contem(pair<int,int>& a, pair<int,int>& b){
    bool b1 = (a.first > b.first && a.first < b.second);
    bool b2 = (a.second > b.first && a.second < b.second);
    bool b3 = (a.first == b.first || a.first == b.second || a.second == b.first || a.second == b.second);
    if(b3){
        return true;
    }
    else if(b1 == b2){
        return true;
    }
    else{
        return false;
    }
}

bool dfs(int inicio,vector<vector<int>>& g, vector<int>& visitados, int cor){
    visitados[inicio] = cor;
    for(auto x : g[inicio]){
        if(visitados[x] == -1){
            if(cor == 0){
                if(!dfs(x,g,visitados,1)){
                    return false;
                }
            }
            else{
                if(!dfs(x,g,visitados,0)){
                    return false;
                }
            }
        }
        else if(visitados[x] == cor){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, m;
    cin>>n>>m;
    int a,b;
    vector<pair<int,int>> vec;
    vector<vector<int>> v (m+1);
    vector<int> visitados (m+1, -1);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(a>b){swap(a,b);}
        vec.push_back({a,b});
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i != j){
                if(!contem(vec[i],vec[j])){
                    v[i+1].push_back(j+1);
                    v[j+1].push_back(i+1);
                }
            }
        }
    }
    bool flg = true;
    for(int i=1;i<=m;i++){
        if(visitados[i] == -1){
            flg = dfs(i , v, visitados, 0);
        }
        if(!flg){
            break;
        }
    }
    if(flg){
        for(int i=1;i<=m;i++){
            if(visitados[i] == 0){
                cout<<'i';
            }
            else{
                cout<<'o';
            }
        }
    }
    else{
        cout<<"Impossible";
    }

    return 0;
}